import glob,re,os,subprocess,tempfile
blocks=[]
for f in sorted(glob.glob('*/*.md')):
    s=open(f,encoding='utf-8').read()
    slides=re.split(r'<!-- slide(?: vertical=true)?(?: data-notes="")? -->',s)[1:]
    for si,b in enumerate(slides,1):
        for m in re.finditer(r'```(?:cpp|c|C)(?:\{[^}]*\})?\n(.*?)```', b, re.S):
            code=m.group(1)
            if '#include' in code and re.search(r'\bint\s+main\s*\(',code):
                blocks.append((f,si,m.group(0).split('\n',1)[0],code))
print('candidate full programs:',len(blocks))
ok=0; fail=[]
tmp=tempfile.mkdtemp(prefix='cppcheck_')
for n,(f,si,lang,code) in enumerate(blocks):
    ext='.c' if lang.startswith('```c') and not lang.startswith('```cpp') else '.cpp'
    path=os.path.join(tmp,'t%d%s'%(n,ext))
    open(path,'w',encoding='utf-8').write(code)
    if ext=='.c':
        cmd=['gcc','-std=c11','-fsyntax-only','-Wall',path]
    else:
        cmd=['g++','-std=c++20','-fsyntax-only','-Wall','-Wextra',path]
    r=subprocess.run(cmd,capture_output=True,text=True)
    if r.returncode==0:
        ok+=1
    else:
        fail.append((f,si,lang,r.stderr.strip().split('\n')[:6]))
print('ok:',ok,'fail:',len(fail))
for f,si,lang,err in fail:
    print('\n---',f,'slide',si,lang)
    for line in err: print('  ',line)
