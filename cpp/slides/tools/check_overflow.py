import sys, os, subprocess, json, re
html_path = os.path.abspath(sys.argv[1])
html = open(html_path, encoding='utf-8').read()
script = r'''
<script>
window.addEventListener('load', function () {
  setTimeout(function () {
    var out = [];
    var secs = document.querySelectorAll('.reveal .slides > section');
    for (var i = 0; i < secs.length; i++) {
      Reveal.slide(i, 0, 0);
      var s = secs[i];
      var pre = s.querySelector('pre');
      var preOver = 0;
      if (pre) preOver = Math.max(0, pre.scrollWidth - pre.clientWidth);
      out.push({n: i + 1, h: s.scrollHeight, w: s.scrollWidth, pre: preOver});
    }
    var el = document.createElement('pre');
    el.id = '__measure';
    el.textContent = JSON.stringify(out);
    document.body.appendChild(el);
  }, 2500);
});
</script>
'''
tmp = html_path.replace('.html', '__sw.html')
open(tmp, 'w', encoding='utf-8').write(html.replace('</body>', script + '</body>'))
chrome = '/Applications/Google Chrome.app/Contents/MacOS/Google Chrome'
cmd = [chrome, '--headless=new', '--disable-gpu', '--hide-scrollbars',
       '--window-size=1280,807', '--virtual-time-budget=15000', '--dump-dom',
       'file://' + tmp]
r = subprocess.run(cmd, capture_output=True, text=True, timeout=120)
m = re.search(r'<pre id="__measure">(.*?)</pre>', r.stdout, re.S)
if not m:
    print('MEASURE FAILED'); print(r.stdout[:1000]); sys.exit(1)
data = json.loads(m.group(1))
bad = [x for x in data if x['h'] > 720 or x['pre'] > 2]
print('total', len(data), 'overflow', len(bad))
for x in data:
    flag = 'OVER' if x['h'] > 720 else ('PRE' if x['pre'] > 2 else 'ok')
    if flag != 'ok':
        print('slide %2d  h=%4d  w=%4d  preOver=%3d  %s' % (x['n'], x['h'], x['w'], x['pre'], flag))
os.remove(tmp)
