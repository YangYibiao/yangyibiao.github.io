import os
import math
import subprocess

covdir = '/root/llvm-project/build'
clangdir = covdir + '/bin/clang '
collectdir = '/root/llvm/cov/'
testdir = '/root/llvm/test/llvmbugs/'
llvmbugsFile = '/root/llvm/llvmbugs_summary.txt'

crash_bugId_lst = []
resultdict = {}

timeout = 10


def getBugInfo(llvmbug):
    items = llvmbug.strip().split(',')
    bugId, sha, passOptLevel, failOptLevel, buggyFiles = items[0], items[1], items[2].replace('+', ' '), items[3].replace('+', ' '), items[4].split('+')
    return bugId, sha, passOptLevel, failOptLevel, buggyFiles


def getConfResult(bugId, conf, timeout=timeout):
    cwd = os.path.join(testdir, bugId)
    cplcmd = clangdir + conf + ' fail.c'
    cplcmd = 'timeout --signal=SIGKILL ' + str(timeout) + ' ' + cplcmd
    try:
        cplout = subprocess.run(cplcmd, shell=True, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout+1)
        if bugId in crash_bugId_lst:
            return str(cplout.returncode)
        else:
            if cplout.returncode != 0:
                return str(cplout.returncode) + ':' + cplout.stdout.decode().strip() + ':' + cplout.stderr.decode().strip()

            execmd = 'timeout --signal=SIGKILL ' + str(timeout) + ' ./a.out'
            try:
                exeout = subprocess.run(execmd, shell=True, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout+1)
                return str(exeout.returncode) + ':' + exeout.stdout.decode().strip() + ':' + exeout.stderr.decode().strip()
            except subprocess.TimeoutExpired:
                return 'EXETimeoutExpired'
    except subprocess.TimeoutExpired:
        return 'CPLTimeoutExpired'
    

def getOptBisectLimit(bugId, failOptLevel, passOptLevel):
    print('\033[1;35m bugId = %s, failOptLevel = %s, passOptLevel = %s\033[0m' % (bugId, failOptLevel, passOptLevel))
    os.chdir(testdir + bugId)
    # get right result
    passResult = getConfResult(bugId, passOptLevel)

    print('\033[1;35m get Opt-Bisect-Limit..\033[0m')
    failLimitList, passLimitList = [], []
    os.system(clangdir + failOptLevel + ' -mllvm -opt-bisect-limit=-1 fail.c > failLimit.txt 2>&1')
    with open('failLimit.txt', 'r') as f:
        maxfailLimit = len(f.readlines())
    failLimit = maxfailLimit
    passLimit = 0
    while True:
        print('\033[1;35m passLimit = %d, failLimit = %d\033[0m' % (passLimit, failLimit))
        if failLimit - passLimit == 1:
            break
        tmpLimit = (failLimit + passLimit) / 2
        tmpConf = failOptLevel + ' -mllvm -opt-bisect-limit=' + str(tmpLimit)
        # check result
        tmpResult = getConfResult(bugId, tmpConf)
        if tmpResult == passResult:  # pass
            passLimit = tmpLimit
        else:  # fail
            failLimit = tmpLimit
    passLimitList.append(passLimit)
    failLimitList.append(failLimit)

    for i in range(2):
        if failLimit + i + 1 > maxfailLimit:
            break
        else:
            failLimitList.append(failLimit + i + 1)

    for i in range(2):
        if passLimit - i - 1 < 0:
            break
        else:
            passLimitList.append(passLimit - i - 1)

    print('\033[1;35m failLimitList = %s, passLimitList = %s\033[0m' % (str(failLimitList), str(passLimitList)))
    return failLimitList, passLimitList


def collect(bugId, option, failorpass):
    os.chdir(testdir + bugId)
    # delete all .gcda files
    os.system('find ' + covdir + ' -name \"*.gcda\" | xargs rm -f')
    # compile test program
    os.system(clangdir + option + ' fail.c > /dev/null 2>&1')

    if os.path.exists('gcdalist'):
        os.system('rm gcdalist')
    os.system('find ' + covdir + ' -name \"*.gcda\" > gcdalist')
    f = open('gcdalist')
    lines = f.readlines()
    f.close()

    if os.path.exists(collectdir + bugId + '/' + failorpass):
        os.system('rm -rf ' + collectdir + bugId + '/' + failorpass)
    os.system('mkdir ' + collectdir + bugId + '/' + failorpass)
    stmtfile = open(collectdir + bugId + '/' + failorpass + '/stmt_info.txt', 'w')

    for i in range(len(lines)):
        gcdafile = lines[i].strip()
        if '/clang/test/' in gcdafile:
            continue
        os.system('rm *.gcov > /dev/null 2>&1')
        if os.path.exists('gcovfile'):
            os.system('rm gcovfile')
        os.system('gcov ' + gcdafile + ' > gcovfile')

        if not os.path.exists('./' + gcdafile.strip().split('/')[-1].split('.gcda')[0] + '.gcov'):
            continue
        f = open(gcdafile.strip().split('/')[-1].split('.gcda')[0] + '.gcov')
        stmtlines = f.readlines()
        f.close()

        # stmt_info
        tmp = []
        for j in range(len(stmtlines)):
            if ':' in stmtlines[j].strip():
                covcnt = stmtlines[j].strip().split(':')[0].strip()
                linenum = stmtlines[j].strip().split(':')[1].strip()
                if covcnt != '-' and covcnt != '#####':
                    tmp.append(linenum)
        if len(tmp) == 0:
            continue

        tmpfilename = gcdafile.split(covdir + '/')[-1].split('.gcda')[0]
        if 'CMakeFiles' in tmpfilename:
            tmpfilename = tmpfilename.split('/CMakeFiles/')[0] + tmpfilename.split('.dir')[1]
        failcovline = tmpfilename + '$' + ','.join(tmp) + '\n'
        stmtfile.write(failcovline)

    stmtfile.close()


def getStmtInfo(covFile):
    stmtInfoSet = set()
    with open(covFile, 'r') as f:
        for line in f:
            filename, stmts = line.strip().split('$')
            for stmt in stmts.split(','):
                stmtInfoSet.add(filename + ',' + stmt)
    return stmtInfoSet


def rank(failStmtInfoDir, passStmtInfoDir):
    failstmt = {}  # the stmt cov information of failing test program
    passstmt = {}
    nfstmt = {}
    npstmt = {}

    failstmtset = set()  # all failstmt
    passstmtset = set()  # all passstmt

    # efs
    # the statements that the falling test program executed
    for failStmtInfo in failStmtInfoDir:
        tmpfailstmtset = getStmtInfo(failStmtInfo)
        failstmtset.update(tmpfailstmtset)
        for stmt in tmpfailstmtset:
            failstmt[stmt] = failstmt.get(stmt, 0) + 1

    # init nfstmt and passstmt
    for stmt in failstmtset:
        nfstmt[stmt] = 0
        passstmt[stmt] = 0
        npstmt[stmt] = 0

    # nfs
    for failStmtInfo in failStmtInfoDir:
        nfset = failstmtset - getStmtInfo(failStmtInfo)
        for nf in nfset:
            nfstmt[nf] += 1

    # eps and nps
    for passStmtInfo in passStmtInfoDir:
        tmppassstmtset = getStmtInfo(passStmtInfo)
        passstmtset.update(failstmtset - tmppassstmtset)
        for stmt in tmppassstmtset:
            if stmt in failstmtset:
                passstmt[stmt] += 1
        npset = failstmtset - tmppassstmtset
        for np in npset:
            npstmt[np] += 1

    # compute statement score based on SBFL
    score = {}  # the buggy value of each statement and its line number in each file
    filescore = {}  # the buggy value of each file, and we can get the corresponding statement values
    for key in failstmt:
        score[key] = failstmt[key] / math.sqrt((failstmt[key] + nfstmt[key]) * (failstmt[key] + passstmt[key]))
        filename = key.rsplit(',', 1)[0]
        filescore.setdefault(filename, []).append(score[key])

    # compute the buggy values of each file based on average aggregation
    fileaggstmtscore = {key: sum(values) / len(values) for key, values in filescore.items()}
    scorelist = sorted(fileaggstmtscore.items(), key=lambda d: d[1], reverse=True)

    return scorelist


def topk(resultlist, k):
    cnt = sum(1 for llvm in resultlist if min(llvm) <= k)
    return cnt


def metrics(resultlist):
    result = {}
    result['Top-1'] = topk(resultlist, 1)
    result['Top-5'] = topk(resultlist, 5)
    result['Top-10'] = topk(resultlist, 10)
    result['Top-20'] = topk(resultlist, 20)

    sumouter = sum(min(llvm) for llvm in resultlist)
    result['MFR'] = round(sumouter / len(resultlist), 2)

    sumouter = sum(sum(llvm) / len(llvm) for llvm in resultlist)
    result['MAR'] = round(sumouter / len(resultlist), 2)

    return result


if __name__ == '__main__':
    if not os.path.exists(collectdir):
        os.system('mkdir ' + collectdir)

    with open(llvmbugsFile, 'r') as f:
        llvmbugs = f.readlines()

    for llvmbug in llvmbugs:
        bugId, sha, passOptLevel, failOptLevel, buggyFiles = getBugInfo(llvmbug)
        # collect covinfo
        if os.path.exists(collectdir + bugId):
            os.system('rm -rf ' + collectdir + bugId)
        os.system('mkdir ' + collectdir + bugId)
        (failLimitList, passLimitList) = getOptBisectLimit(bugId, failOptLevel, passOptLevel)
        print('\033[1;35m collect..\033[0m')
        failStmtInfoDir = []
        for i in range(len(failLimitList)):
            failOption = failOptLevel + ' -mllvm -opt-bisect-limit=' + str(failLimitList[i])
            print('\033[1;35m collect covinfo of %s ..\033[0m' % failOption)
            collect(bugId, failOption, 'fail' + str(i))
            failStmtInfoDir.append(collectdir + bugId + '/fail' + str(i) + '/stmt_info.txt')
        passStmtInfoDir = []
        for i in range(len(passLimitList)):
            passOption = failOptLevel + ' -mllvm -opt-bisect-limit=' + str(passLimitList[i])
            print('\033[1;35m collect covinfo of %s ..\033[0m' % passOption)
            collect(bugId, passOption, 'pass' + str(i))
            passStmtInfoDir.append(collectdir + bugId + '/pass' + str(i) + '/stmt_info.txt')

        # rank file by score
        print('\033[1;35m ranking files..\033[0m')
        scorelist = rank(failStmtInfoDir, passStmtInfoDir)

        tmpresultlist = []
        for buggyfile in buggyFiles:
            pre_index = 0
            pre_score = 0.0
            cnt = 0
            for line in scorelist:
                cnt += 1
                current_score = line[1]
                if current_score == pre_score:
                    current_index = pre_index
                else:
                    current_index = cnt
                pre_index = current_index
                pre_score = current_score
                if buggyfile in line[0]:
                    tmpresultlist.append(current_index)
                    break
        resultdict[bugId] = tmpresultlist

    # rank result
    print('\033[1;35m===================================================\033[0m')
    for key in sorted(resultdict):
        print('%s,%s' % (key, resultdict[key]))
    print('\033[1;35m===================================================\033[0m')

    # metric
    print('\033[1;35m[metric]:\033[0m')
    result = metrics(resultdict.values())
    for key in ['Top-1', 'Top-5', 'Top-10', 'Top-20', 'MFR', 'MAR']:
        print(key + ': ' + str(result[key]))
