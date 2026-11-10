# -*- coding: utf-8 -*-
"""从 md 源重新生成课件的 html (保留原 html 的 head/tail 与 16:9 设置).

用法:
    python3 genhtml.py <md文件名(不含.md)> [课件所在目录]

例:
    python3 genhtml.py 0-1-programming-and-c 0-intro
    python3 genhtml.py 8-2-sorting 2-if-for-array

功能: 支持标题页/普通页/结束页、代码块语法高亮、markdown 表格、
列表(含嵌套)、图片与原始 HTML 透传、行内 `code`/==高亮==/:fa-图标:/链接。
生成后会做结构自检 (列表配对、重复标题、残留 markdown)。

注意: md 里每个 slide 用 <!-- slide data-notes="" --> 或 <!-- slide --> 分隔, 不能有遗漏。
"""
import os, re, sys

if len(sys.argv) < 2:
    print(__doc__)
    sys.exit(1)
name = sys.argv[1]
here = os.path.dirname(os.path.abspath(__file__))
BASE = (os.path.join(here, sys.argv[2]) if len(sys.argv) > 2 else here)
if not BASE.endswith('/'):
    BASE += '/'
md = open(BASE + name + '.md', encoding='utf-8').read()
html_path = BASE + name + '.html'
try:
    html = open(html_path, encoding='utf-8').read()
except FileNotFoundError:
    # 新课件: 借用同目录任一已有课件做模板 (只取 head/tail)
    # 只选包含 Reveal.initialize 的课件, 避免误用浏览器保存的普通页面
    import glob
    tmpl = next((f for f in sorted(glob.glob(BASE + '*.html'))
                 if not f.endswith(name + '.html')
                 and 'Reveal.initialize' in open(f, encoding='utf-8', errors='replace').read()), None)
    if tmpl is None:
        print('no template html in', BASE, '- create one deck first')
        sys.exit(1)
    print('new deck: using template', os.path.basename(tmpl))
    html = open(tmpl, encoding='utf-8').read()
MARK_RE = r'<!-- slide(?: vertical=true)?(?: data-notes="")? -->'
blocks = re.split(MARK_RE, md)[1:]

if '"width":1280' not in html:
    html = html.replace('Reveal.initialize({', 'Reveal.initialize({"width":1280,"height":720,', 1)
first = html.find('<section data-notes')
last = html.rfind('</section>') + len('</section>')
head_html, tail_html = html[:first], html[last:]
head_html = re.sub(r'<title>[^<]*</title>', '<title>' + name + '</title>', head_html)
# 注入 KaTeX 运行时 (数学公式 \(...\) 与 \[...\] 在浏览器端渲染)
# JS 版本与 head 中已有的 katex.min.css 保持一致, 避免 CSS/JS 错配
head_html = re.sub(r'<script defer src="https://cdn\.jsdelivr\.net/npm/katex@[\d.]+/dist/katex\.min\.js"></script>.*?</head>',
                   '</head>', head_html, flags=re.S)  # 先移除旧版注入块 (若有), 否则会被旧版本覆盖
m = re.search(r'katex@([\d.]+)/dist/katex\.min\.css', head_html)
katex_ver = m.group(1) if m else '0.16.47'
KATEX = """<script defer src="https://cdn.jsdelivr.net/npm/katex@VER/dist/katex.min.js"></script>
<script defer src="https://cdn.jsdelivr.net/npm/katex@VER/dist/contrib/auto-render.min.js"></script>
<script>
document.addEventListener("DOMContentLoaded", function () {
  if (window.renderMathInElement) {
    renderMathInElement(document.body, {
      delimiters: [
        {left: "\\\\[", right: "\\\\]", display: true},
        {left: "\\\\(", right: "\\\\)", display: false}
      ],
      throwOnError: false
    });
  }
});
</script>
</head>""".replace('VER', katex_ver)
head_html = head_html.replace('</head>', KATEX, 1)
# 代码块不显示滚动条: 单行代码出现上下滚动条很刺眼, 且各页代码均已按宽度/字号适配
head_html = head_html.replace('</head>', '<style>pre[class*=language-]{overflow:hidden!important;scrollbar-width:none}pre[class*=language-]::-webkit-scrollbar{display:none}</style></head>', 1)
# 注入 Mermaid 运行时 (```mermaid 代码块在浏览器端渲染, 数据挖掘课件使用)
head_html = re.sub(r'<script defer src="https://cdn\.jsdelivr\.net/npm/mermaid@[\d.]+/dist/mermaid\.min\.js"></script>.*?</head>',
                   '</head>', head_html, flags=re.S)  # 先移除旧版注入块 (若有), 避免重复注入
MERMAID = """<script defer src="https://cdn.jsdelivr.net/npm/mermaid@11.4.1/dist/mermaid.min.js"></script>
<script defer>
document.addEventListener("DOMContentLoaded", function () {
  if (window.mermaid) {
    // 懒渲染: 只渲染"当前可见页"的图, 翻页时再渲染新页的图。
    // 一次性渲染所有图时, 隐藏页里的图会在零尺寸状态下被测量, 导致节点框极小、标签折成竖排。
    mermaid.initialize({ startOnLoad: false, theme: 'dark', fontFamily: 'LXGWWenKai, "Noto Sans SC", sans-serif', flowchart: { htmlLabels: false, useMaxWidth: true } });
    function renderSlide(slide) {
      if (!slide) return;
      var els = slide.querySelectorAll('.mermaid');
      for (var i = 0; i < els.length; i++) {
        var el = els[i];
        if (el.getAttribute('data-processed')) continue;
        try { mermaid.run({ nodes: [el] }); } catch (e) {}
      }
    }
    function currentSlide() {
      return document.querySelector('.reveal .slides section.present') ||
             document.querySelector('.reveal .slides section');
    }
    function renderWhenReady() {
      renderSlide(currentSlide());
      if (window.Reveal && Reveal.on) {
        // 过渡结束后渲染 (slidechanged 在过渡开始时触发, 此时页面在旋转缩放, 测量宽度会失真);
        // 900ms 定时器兜底 transition:none 等不触发 slidetransitionend 的情况
        Reveal.on('slidechanged', function (e) {
          setTimeout(function () { renderSlide(e.currentSlide); }, 900);
        });
        Reveal.on('slidetransitionend', function (e) { renderSlide(e.currentSlide); });
      }
    }
    if (document.fonts && document.fonts.ready) {
      document.fonts.ready.then(renderWhenReady);
    } else {
      renderWhenReady();
    }
  }
});
</script>
</head>"""
head_html = head_html.replace('</head>', MERMAID, 1)
# 内联 md 头部 @import 的本地 CSS (生成的 html 是自包含的, 浏览器不会处理 md 里的 @import)
# 含 url(...) 的文件 (字体/背景图等相对路径) 跳过, 避免内联后资源路径失效
# 先移除上一轮已内联的块, 再按当前文件重新内联, 保证每次生成结果确定
head_html = re.sub(r'<style>\s*/\* inlined: [^*]*\*/.*?</style>', '', head_html, flags=re.S)
inlined_css = []
for m in re.finditer(r'^@import\s+"([^"]+\.css)"\s*$', md, re.M):
    css_path = os.path.normpath(os.path.join(BASE, m.group(1)))
    if os.path.exists(css_path):
        content = open(css_path, encoding='utf-8').read()
        if 'url(' not in content:
            inlined_css.append('/* inlined: ' + m.group(1) + ' */\n' + content)
if inlined_css:
    head_html = head_html.replace('</head>', '<style>' + '\n'.join(inlined_css) + '</style></head>', 1)

FA = {'fa-lightbulb-o': 'fa fa-lightbulb-o', 'fa-weixin': 'fa fa-weixin', 'fa-camera': 'fa fa-camera',
      'fa-language': 'fa fa-language', 'fa-car': 'fa fa-car', 'fa-microphone': 'fa fa-microphone',
      'fa-comments': 'fa fa-comments'}
KEYWORDS = {'int': 'keyword-int', 'void': 'keyword-void', 'return': 'keyword-return', 'if': 'keyword-if',
            'else': 'keyword-else', 'while': 'keyword-while', 'char': 'keyword-char', 'float': 'keyword-float',
            'double': 'keyword-double', 'long': 'keyword-long', 'short': 'keyword-short', 'for': 'keyword-for',
            'do': 'keyword-do', 'const': 'keyword-const', 'static': 'keyword-static', 'struct': 'keyword-struct',
            'break': 'keyword-break', 'continue': 'keyword-continue', 'switch': 'keyword-switch',
            'case': 'keyword-case', 'default': 'keyword-default', 'sizeof': 'keyword-sizeof',
            'typedef': 'keyword-typedef', 'unsigned': 'keyword-unsigned', 'signed': 'keyword-signed'}

def esc(s): return s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')

def raw_inline(line):
    """原始 HTML 行: 先暂存行内代码, 其余文本转换图标/强调/数学并转义裸 &"""
    codes = []
    def stash(m):
        codes.append(m.group(1)); return '\x00%d\x00' % (len(codes) - 1)
    line = re.sub(r'`([^`\n]+)`', stash, line)
    line = re.sub(r'``([^`\n]+)``', r'`\1`', line)  # 双反引号 -> 单反引号
    line = re.sub(r':(fa-[a-z0-9-]+):',
                  lambda m: '<i class="fa ' + m.group(1) + '" aria-hidden="true"></i>', line)
    line = re.sub(r'==([^=<>{}]+(?:=[^=<>{}]+)*)==', r'<mark>\1</mark>', line)
    line = re.sub(r'\$\$([^$\n]{1,200})\$\$', lambda m: '\\[' + m.group(1) + '\\]', line)
    line = re.sub(r'\$([^$\n]{1,80})\$', lambda m: m.group(0) if re.search(r'\d,\d{3}', m.group(1)) else '\\(' + m.group(1) + '\\)', line)
    line = re.sub(r'&(?!(?:[a-zA-Z]+|#\d+|#x[0-9a-fA-F]+);)', '&amp;', line)
    line = re.sub(r'\x00(\d+)\x00', lambda m: '<code>' + esc(codes[int(m.group(1))]) + '</code>', line)
    return line


def highlight_c(code):
    out, i, n = [], 0, len(code)
    while i < n:
        c = code[i]
        if c == '/' and i + 1 < n and code[i+1] == '/':
            j = code.find('\n', i)
            if j == -1: j = n
            out.append('<span class="token comment">' + esc(code[i:j]) + '</span>'); i = j; continue
        if c == '/' and i + 1 < n and code[i+1] == '*':
            j = code.find('*/', i + 2)
            if j == -1: j = n - 2
            j += 2
            out.append('<span class="token comment">' + esc(code[i:j]) + '</span>'); i = j; continue
        if c == '#':
            j = code.find('\n', i)
            if j == -1: j = n
            line = code[i:j]
            m = re.match(r'#\s*(include|define|ifdef|ifndef|endif|if|elif|else|undef)\b', line)
            out.append('<span class="token macro property"><span class="token directive-hash">#</span>')
            if m:
                out.append('<span class="token directive keyword">' + m.group(1) + '</span>')
                rest = line[m.end():]
                m2 = re.match(r'\s*(<[^>]+>|\S+)', rest)
                if m2:
                    if m2.group(1).startswith('<'):
                        out.append(' <span class="token string">' + esc(m2.group(1)) + '</span>')
                    else:
                        out.append(' ' + esc(m2.group(1)))
                    rest = rest[m2.end():]
                out.append(esc(rest))
            else:
                out.append(esc(line[1:]))
            out.append('</span>'); i = j; continue
        if c == '"':
            j = i + 1
            while j < n:
                if code[j] == '\\': j += 2; continue
                if code[j] == '"': break
                j += 1
            j = min(j + 1, n)
            out.append('<span class="token string">' + esc(code[i:j]) + '</span>'); i = j; continue
        if c == "'":
            j = i + 1
            while j < n:
                if code[j] == '\\': j += 2; continue
                if code[j] == "'": break
                j += 1
            j = min(j + 1, n)
            out.append('<span class="token string">' + esc(code[i:j]) + '</span>'); i = j; continue
        m = re.match(r'[A-Za-z_][A-Za-z0-9_]*', code[i:])
        if m:
            word = m.group(0)
            if word in KEYWORDS:
                out.append(f'<span class="token keyword {KEYWORDS[word]}">{word}</span>')
            else:
                j = i + len(word)
                while j < n and code[j].isspace(): j += 1
                if j < n and code[j] == '(':
                    out.append(f'<span class="token function">{word}</span>')
                else:
                    out.append(esc(word))
            i += len(word); continue
        m = re.match(r'\d+(\.\d+)?([eE][+-]?\d+)?', code[i:])
        if m:
            out.append('<span class="token number">' + esc(m.group(0)) + '</span>')
            i += len(m.group(0)); continue
        m = re.match(r'(==|!=|<=|>=|&&|\|\||\+\+|--|->|<<|>>|\+=|-=|\*=|/=|%=)', code[i:])
        if m:
            out.append('<span class="token operator">' + esc(m.group(0)) + '</span>')
            i += len(m.group(0)); continue
        if c in '(){}[];,.':
            out.append('<span class="token punctuation">' + c + '</span>'); i += 1; continue
        if c in '+-*/%=<>!&|?:':
            out.append('<span class="token operator">' + c + '</span>'); i += 1; continue
        out.append(esc(c)); i += 1
    return ''.join(out)


def inline(text):
    parts = re.split(r'(</?[A-Za-z][A-Za-z0-9]*(?:\s[^<>]*)?/?>)', text)
    out = []
    for p in parts:
        if p.startswith('<'):
            out.append(p); continue
        p = re.sub(r'``([^`\n]+)``', r'`\1`', p)   # 双反引号 -> 单反引号
        # 先保护行内代码, 避免把代码里的 $ 当数学
        codes = []
        def stash(m):
            codes.append(m.group(1)); return '\x00%d\x00' % (len(codes) - 1)
        p = re.sub(r'`([^`]+)`', stash, p)
        # LaTeX 数学: $$..$$ -> \\[..\\], $..$ -> \\(..\\) (排除含逗号的金额写法)
        p = re.sub(r'\$\$([^$\n]{1,200})\$\$', lambda m: '\\[' + m.group(1) + '\\]', p)
        p = re.sub(r'\$([^$\n]{1,80})\$', lambda m: m.group(0) if re.search(r'\d,\d{3}', m.group(1)) else '\\(' + m.group(1) + '\\)', p)
        # 高亮/图标/加粗/链接在还原行内代码==之前==处理: 占位符 \x00N\x00 保护代码内容,
        # 代码里的 == (比较运算符) 不会被误当高亮标记吞掉
        p = re.sub(r':(fa-[a-z0-9-]+):', lambda m: '<span class="blue"><i class="' + FA.get(m.group(1), 'fa ' + m.group(1)) + '" aria-hidden="true"></i></span>', p)
        p = re.sub(r'==([^=]+(?:=[^=]+)*)==', r'<mark>\1</mark>', p)
        p = re.sub(r'\*\*([^*]+)\*\*', r'<strong>\1</strong>', p)
        p = re.sub(r'\[([^\]]+)\]\(([^)]+)\)', r'<a href="\2">\1</a>', p)
        # 还原行内代码
        p = re.sub(r'\x00(\d+)\x00', lambda m: '<code>' + esc(codes[int(m.group(1))]) + '</code>', p)
        out.append(p)
    return ''.join(out)

def is_raw(s): return s.strip().startswith('<')
def is_bullet(s): return re.match(r'^[-*] ', s.strip())
def is_ol(s): return re.match(r'^\d+\. ', s.strip())
def is_fence(s): return s.strip().startswith('```')
def is_hr(s): return s.strip() == '---'
def is_table(s): return s.strip().startswith('|')
def is_sep_row(cells): return all(re.match(r'^:?-{2,}:?$', c.strip()) for c in cells if c.strip() != '') and any(c.strip() for c in cells)

def split_table_row(line):
    """按 | 切表格行, 但跳过反引号内的 | (如位运算符 `12 | 10`)"""
    s = line.strip().strip('|')
    cells, cur, in_code = [], [], False
    for ch in s:
        if ch == '`':
            in_code = not in_code
            cur.append(ch)
        elif ch == '|' and not in_code:
            cells.append(''.join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    cells.append(''.join(cur).strip())
    return cells

def parse_table(lines, i):
    rows = []
    while i < len(lines) and lines[i].strip() and is_table(lines[i]):
        cells = split_table_row(lines[i])
        rows.append(cells)
        i += 1
    header = None
    body = []
    if rows and len(rows) > 1 and is_sep_row(rows[1]):
        header = rows[0]
        body = rows[2:]
    else:
        body = rows
    html = ['<table>']
    if header:
        html.append('<thead>\n<tr>\n' + '\n'.join('<th>' + inline(c) + '</th>' for c in header) + '\n</tr>\n</thead>')
    html.append('<tbody>')
    for r in body:
        html.append('<tr>\n' + '\n'.join('<td>' + inline(c) + '</td>' for c in r) + '\n</tr>')
    html.append('</tbody>\n</table>')
    return '\n'.join(html), i

def parse_content(lines):
    out, i = [], 0
    while i < len(lines):
        ln = lines[i]
        if not ln.strip():
            i += 1; continue
        if is_fence(ln):
            info = ln.strip()[3:].strip()
            pre_open = ('<pre data-role="codeBlock" data-info="C{.line-numbers}" class="language-c C line-numbers"><code>'
                        if '{.line-numbers}' in info else
                        '<pre data-role="codeBlock" data-info="C" class="language-c C"><code>')
            code_lines = []
            i += 1
            while i < len(lines) and not is_fence(lines[i]):
                code_lines.append(lines[i]); i += 1
            i += 1
            if info == 'mermaid':
                # Mermaid 图: 保留原文交给浏览器端 mermaid.js 渲染, 不做 C 高亮
                out.append('<pre class="mermaid" style="background:transparent;box-shadow:none;">'
                           + esc('\n'.join(code_lines)) + '</pre>')
            else:
                out.append(pre_open + highlight_c('\n'.join(code_lines)) + '</code></pre>')
            continue
        if is_table(ln) and not is_raw(ln):
            tbl, i = parse_table(lines, i)
            out.append(tbl); continue
        if is_raw(ln):
            # <script> 块原样保留 (脚本内容不能做 HTML 转义, 否则 && 会变成 &amp;&amp;)
            if ln.strip().startswith('<script'):
                if '</script>' in ln:      # 单行脚本: 直接原样输出
                    out.append(ln); i += 1; continue
                raw = [ln]; i += 1
                while i < len(lines):
                    raw.append(lines[i])
                    if '</script>' in lines[i]:
                        i += 1; break
                    i += 1
                out.append('\n'.join(raw)); continue
            raw = [raw_inline(ln)]
            i += 1
            while (i < len(lines) and lines[i].strip() and is_raw(lines[i])
                   and not lines[i].strip().startswith('<script')):
                raw.append(raw_inline(lines[i])); i += 1
            joined = '\n'.join(raw)
            if ln.strip().startswith('<span'):
                out.append('<p>' + joined + '</p>')
            else:
                out.append(joined)
            continue
        if is_bullet(ln) and not re.match(r'^  [-*] ', ln):
            items = []
            while i < len(lines):
                if not lines[i].strip():
                    k = i
                    while k < len(lines) and not lines[k].strip():
                        k += 1
                    if k < len(lines) and is_bullet(lines[k]) and not re.match(r'^  [-*] ', lines[k]):
                        i = k; continue
                    break
                if not (is_bullet(lines[i]) and not re.match(r'^  [-*] ', lines[i])):
                    break
                item_text = lines[i].strip()[2:].strip()
                i += 1
                while i < len(lines) and lines[i].strip() and not re.match(r'^[-*] ', lines[i].strip()) and not is_ol(lines[i]) and not is_fence(lines[i]) and not is_raw(lines[i]) and not is_hr(lines[i]) and not is_table(lines[i]):
                    item_text += ' ' + lines[i].strip(); i += 1
                nested = ''
                if i < len(lines) and re.match(r'^  [-*] ', lines[i]):
                    nested_items = []
                    while i < len(lines) and re.match(r'^  [-*] ', lines[i]):
                        sub_text = lines[i].strip()[2:].strip()
                        i += 1
                        while i < len(lines) and lines[i].strip() and not re.match(r'^[-*] ', lines[i].strip()) and not is_ol(lines[i]) and not is_fence(lines[i]) and not is_raw(lines[i]) and not is_hr(lines[i]):
                            sub_text += ' ' + lines[i].strip(); i += 1
                        nested_items.append('<li>\n<p>' + inline(sub_text) + '</p>\n</li>')
                    nested = '<ul>\n' + '\n'.join(nested_items) + '\n</ul>'
                items.append('<li>\n<p>' + inline(item_text) + '</p>\n' + nested + '\n</li>')
            out.append('<ul>\n' + '\n'.join(items) + '\n</ul>'); continue
        if is_ol(ln):
            items = []
            while i < len(lines):
                if not lines[i].strip():
                    k = i
                    while k < len(lines) and not lines[k].strip():
                        k += 1
                    if k < len(lines) and is_ol(lines[k]):
                        i = k; continue
                    break
                if not is_ol(lines[i]):
                    break
                item_text = re.sub(r'^\d+\. ', '', lines[i].strip()).strip()
                i += 1
                while i < len(lines) and lines[i].strip() and not is_ol(lines[i]) and not is_fence(lines[i]) and not is_raw(lines[i]) and not is_hr(lines[i]) and not re.match(r'^ {2,}[-*] ', lines[i]):
                    item_text += ' ' + lines[i].strip(); i += 1
                nested = ''
                if i < len(lines) and re.match(r'^ {2,}[-*] ', lines[i]):
                    nested_items = []
                    while i < len(lines) and re.match(r'^ {2,}[-*] ', lines[i]):
                        sub_text = lines[i].strip()[2:].strip()
                        i += 1
                        while i < len(lines) and lines[i].strip() and not re.match(r'^[-*] ', lines[i].strip()) and not is_ol(lines[i]) and not is_fence(lines[i]) and not is_raw(lines[i]) and not is_hr(lines[i]):
                            sub_text += ' ' + lines[i].strip(); i += 1
                        nested_items.append('<li>' + inline(sub_text) + '</li>')
                    nested = '<ul>\n' + '\n'.join(nested_items) + '\n</ul>'
                items.append('<li>' + inline(item_text) + '\n' + nested + '</li>')
            out.append('<ol>\n' + '\n'.join(items) + '\n</ol>'); continue
        if is_hr(ln):
            out.append('<hr>'); i += 1; continue
        if re.match(r'^> ', ln.strip()):
            # 引用块: 连续的 > 行合并为一个 blockquote, 每行一个段落
            quote = []
            while i < len(lines) and re.match(r'^> ', lines[i].strip()):
                quote.append(re.sub(r'^>\s?', '', lines[i].strip())); i += 1
            out.append('<blockquote>\n' + '\n'.join('<p>' + inline(q) + '</p>' for q in quote) + '\n</blockquote>')
            continue
        para = [ln]
        i += 1
        while i < len(lines) and lines[i].strip() and not is_fence(lines[i]) and not is_bullet(lines[i]) and not is_ol(lines[i]) and not is_raw(lines[i]) and not is_hr(lines[i]) and not is_table(lines[i]) and not re.match(r'^> ', lines[i].strip()):
            para.append(lines[i]); i += 1
        # 行尾两个空格或显式 <br> 视为硬换行
        joined = []
        for p in para:
            hard = re.search(r' {2,}$', p) or p.rstrip().endswith('<br>')
            joined.append(p.strip() + ('<br>' if hard else ''))
        out.append('<p>' + inline(' '.join(joined)) + '</p>')
    return '\n'.join(out)

def build_section(block, idx):
    lines = block.split('\n')
    while lines and not lines[0].strip():
        lines.pop(0)
    while lines and (not lines[-1].strip() or is_hr(lines[-1])):
        lines.pop()
    if not lines:
        return None
    first_line = lines[0].strip()
    if first_line.startswith('<div class="bottom20">'):
        content = []
        for ln in lines:
            s = ln.strip()
            if s.startswith('<'):
                content.append(ln); continue
            m = re.match(r'^# (.*)$', s)
            if m:
                content.append('<h1 id="智能程序设计c语言">' + inline(m.group(1)) + ' </h1>'); continue
            m = re.match(r'^## (.*)$', s)
            if m:
                t = m.group(1).strip()
                hid = re.sub(r'[^\w一-鿿]', '', t.lower())
                content.append(f'<h2 id="{hid}">{inline(t)} </h2>'); continue
            m = re.match(r'^### (.*)$', s)
            if m:
                t = m.group(1).strip()
                hid = re.sub(r'[^\w一-鿿]', '', t.lower())
                content.append(f'<h3 id="{hid}">{inline(t)} </h3>'); continue
            m = re.match(r'^#### (.*)$', s)
            if m:
                t = m.group(1).strip()
                hid = re.sub(r'[^\w一-鿿]', '', t.lower())
                content.append(f'<h4 id="{hid}">{inline(t)} </h4>'); continue
            if s:
                content.append('<p>' + inline(s) + '</p>')
        inner = '\n'.join(content)
        return f'<section data-notes="" lineno="32" class="slide " data-source-line="32" data-h="{idx}" data-v="0">{inner}\n</section>'
    m = re.match(r'^##### (.*)$', first_line)
    if m:
        title = m.group(1).strip()
        hid = re.sub(r'[^\w一-鿿]', '-', title.lower()).strip('-')
        body = lines[1:]
        while body and (not body[0].strip() or is_hr(body[0])):
            body.pop(0)
        inner = parse_content(body)
        return (f'<section data-notes="" lineno="{idx*14+52}" class="slide " data-source-line="{idx*14+52}" '
                f'data-h="{idx}" data-v="0"><h5 id="{hid}">{inline(title)} </h5>\n<hr>\n{inner}\n<hr>\n</section>')
    body = [l for l in lines if l.strip() and l.strip() != '#####']
    # split headings (h1/h2/h3) out, feed the rest to parse_content
    # 代码围栏内的 # 行 (如 Python 注释) 不是标题, 跳过
    content = []
    buf = []
    i2 = 0
    in_fence = False
    def flush():
        if buf:
            content.append(parse_content(list(buf)))
            buf.clear()
    while i2 < len(body):
        s = body[i2].strip()
        if is_fence(s):
            in_fence = not in_fence
            buf.append(body[i2]); i2 += 1; continue
        if not in_fence:
            m = re.match(r'^# (.*)$', s)
            if m:
                flush(); content.append('<h1 id="周三见">' + inline(m.group(1)) + ' </h1>'); i2 += 1; continue
            m = re.match(r'^## (.*)$', s)
            if m:
                flush()
                t = m.group(1).strip()
                hid = re.sub(r'[^\w一-鿿]', '', t.lower())
                content.append(f'<h2 id="{hid}">{t} </h2>'); i2 += 1; continue
            m = re.match(r'^### (.*)$', s)
            if m:
                flush()
                t = m.group(1).strip()
                hid = re.sub(r'[^\w一-鿿]', '', t.lower())
                content.append(f'<h3 id="{hid}">{t} </h3>'); i2 += 1; continue
        buf.append(body[i2]); i2 += 1
    flush()
    inner = '\n'.join(c for c in content if c)
    return f'<section data-notes="" lineno="999" class="slide " data-source-line="999" data-h="{idx}" data-v="0">{inner}\n</section>'

sections = [s for s in (build_section(b, i) for i, b in enumerate(blocks)) if s]
body_out = ''.join(sections)

# ---- 密码门: md 头部 front matter 里写 password: xxx 时, 页面先显示密码遮罩 ----
import hashlib as _hashlib
_pwd = None
_fm = re.match(r'---\s*\n(.*?)\n---', md, re.S)
if _fm:
    _m = re.search(r'^password:\s*["\']?([^"\'\n]+)["\']?\s*$', _fm.group(1), re.M)
    if _m:
        _pwd = _m.group(1).strip()
# 先移除已有的密码门 (未设置密码时也要清除, 否则重新生成会残留旧遮罩)
tail_html = re.sub(r'<div id="cpl-gate".*?\n\}\)\(\);\n</script>\n?', '', tail_html, flags=re.S)

if _pwd:
    _GATE = """<div id="cpl-gate" style="position:fixed;inset:0;z-index:2147483647;background:#fdf6e3;display:flex;align-items:center;justify-content:center;flex-direction:column;font-family:-apple-system,'PingFang SC',sans-serif;">
<h2 style="color:#073642;margin:0 0 18px;font-size:26px;">🔒 本课件尚未发布</h2>
<input id="cpl-pwd" type="password" placeholder="请输入密码" autocomplete="off" style="width:260px;padding:10px 14px;font-size:16px;border:2px solid #93a1a1;border-radius:8px;outline:none;background:#fff;"/>
<button id="cpl-go" style="margin-top:14px;padding:9px 26px;font-size:16px;background:#268bd2;color:#fff;border:none;border-radius:8px;cursor:pointer;">进入课件</button>
<div id="cpl-err" style="margin-top:12px;color:#dc322f;font-size:14px;display:none;">密码不正确，请重试</div>
</div>
<script>
(function(){
  var KEY = 'cpl_unlock_""" + name + """';
  var HASH = '""" + _hashlib.sha256(_pwd.encode('utf-8')).hexdigest() + """';
  var g = document.getElementById('cpl-gate');
  if (!g) return;
  if (sessionStorage.getItem(KEY) === '1') { g.remove(); return; }
  function sha256(ascii) {
    function rightRotate(v, a) { return (v >>> a) | (v << (32 - a)); }
    var maxWord = Math.pow(2, 32), i, j, result = '';
    var words = [], len = ascii.length * 8;
    var hash = sha256.h = sha256.h || [], k = sha256.k = sha256.k || [], pc = k.length;
    var comp = {};
    for (var c = 2; pc < 64; c++) {
      if (!comp[c]) {
        for (i = 0; i < 313; i += c) comp[i] = c;
        hash[pc] = (Math.pow(c, .5) * maxWord) | 0;
        k[pc++] = (Math.pow(c, 1 / 3) * maxWord) | 0;
      }
    }
    ascii += '\\x80';
    while (ascii.length % 64 - 56) ascii += '\\x00';
    for (i = 0; i < ascii.length; i++) {
      j = ascii.charCodeAt(i);
      if (j >> 8) return '';
      words[i >> 2] |= j << ((3 - i) % 4) * 8;
    }
    words[words.length] = ((len / maxWord) | 0);
    words[words.length] = (len);
    for (j = 0; j < words.length;) {
      var w = words.slice(j, j += 16), oldHash = hash;
      hash = hash.slice(0, 8);
      for (i = 0; i < 64; i++) {
        var w15 = w[i - 15], w2 = w[i - 2];
        var a = hash[0], e = hash[4];
        var temp1 = hash[7] + (rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25))
          + ((e & hash[5]) ^ ((~e) & hash[6])) + k[i]
          + (w[i] = (i < 16) ? w[i] : (w[i - 16]
            + (rightRotate(w15, 7) ^ rightRotate(w15, 18) ^ (w15 >>> 3))
            + w[i - 7] + (rightRotate(w2, 17) ^ rightRotate(w2, 19) ^ (w2 >>> 10))) | 0);
        var temp2 = (rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22))
          + ((a & hash[1]) ^ (a & hash[2]) ^ (hash[1] & hash[2]));
        hash = [(temp1 + temp2) | 0].concat(hash);
        hash[4] = (hash[4] + temp1) | 0;
      }
      for (i = 0; i < 8; i++) hash[i] = (hash[i] + oldHash[i]) | 0;
    }
    for (i = 0; i < 8; i++) {
      for (j = 3; j + 1; j--) {
        var b = (hash[i] >> (j * 8)) & 255;
        result += ((b < 16) ? 0 : '') + b.toString(16);
      }
    }
    return result;
  }
  function tryUnlock() {
    if (sha256(document.getElementById('cpl-pwd').value) === HASH) {
      sessionStorage.setItem(KEY, '1');
      g.remove();
    } else {
      var e = document.getElementById('cpl-err');
      e.style.display = 'block';
      document.getElementById('cpl-pwd').value = '';
    }
  }
  document.getElementById('cpl-go').onclick = tryUnlock;
  document.getElementById('cpl-pwd').addEventListener('keydown', function (ev) {
    if (ev.key === 'Enter') tryUnlock();
  });
  document.getElementById('cpl-pwd').focus();
})();
</script>
"""
    tail_html = tail_html.replace('</body>', _GATE + '</body>', 1)

open(BASE + name + '.html', 'w', encoding='utf-8').write(head_html + body_out + tail_html)
print(f'{name}: md {len(blocks)} blocks -> html {len(sections)} sections')

secs = re.findall(r'<section data-notes="".*?</section>', body_out, re.S)
issues = []
for i, s in enumerate(secs):
    if s.count('<ul>') != s.count('</ul>') or s.count('<ol>') != s.count('</ol>') or s.count('<li>') != s.count('</li>'):
        issues.append((i, 'list imbalance'))
    if s.count('<h5') > 1:
        issues.append((i, 'dup h5'))
    if '<p>|' in s or '<p>#' in s:
        issues.append((i, 'stray markdown'))
print('issues:', issues if issues else 'NONE')
