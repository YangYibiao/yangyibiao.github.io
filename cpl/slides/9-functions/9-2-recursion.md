---
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../../css/theme/solarized.css"
@import "../../css/logo.css"
@import "../../css/font.css"
@import "../../css/color.css"
@import "../../css/margin.css"
@import "../../css/table.css"
@import "../../css/main.css"
@import "../../plugin/zoom/zoom.js"
@import "../../plugin/customcontrols/plugin.js"
@import "../../plugin/customcontrols/style.css"
@import "../../plugin/chalkboard/plugin.js"
@import "../../plugin/chalkboard/style.css"
@import "../../plugin/menu/menu.js"
@import "../../js/anychart/anychart-core.min.js"
@import "../../js/anychart/anychart-venn.min.js"
@import "../../js/anychart/pastel.min.js"
@import "../../js/anychart/venn-ml.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 函数 (III) · 递归

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

---

<!-- slide data-notes="" -->##### 提纲

---

- 递归是什么 (两个要素、信任递归)

- 递归执行过程 (层层递推与回归)

- 经典案例: Fibonacci (弹性)、汉诺塔

- 常见错误与课堂编码 (基础 3 题 + 案例 5 题)

- 分治与快速排序 (弹性)

- 课堂小测

---
<!-- slide data-notes="" -->

##### 递归是什么

---

==递归==: 函数直接或间接地==自己调用自己==——有些问题的定义本身就是递归的: 阶乘、汉诺塔、目录遍历……

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
/* 阶乘: n! = n × (n-1)! */
long long f(long long n)
{
  if (n == 0) {            /* 基准: 0! = 1, 唯一的奠基 */
    return 1;
  }
  return n * f(n - 1);     /* 递归: 1! 由 0! 归纳出来 */
}
```

```C
/* 求幂: x^n = x × x^(n-1), 可以精简成一行 */
int power(int x, int n) {
    return n == 0 ? 1 : x * power(x, n - 1);
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.42;">

- ==两个要素==: ==基准情形== (最简单, 直接给答案) + ==递归情形== (==缩小==后再调用自己)

- ==信任递归==: 假设 n-1 层的答案是对的, 用它构造 n 的答案——==不要在脑中展开所有层==

- ==递归三问==: 最小问题? 怎么缩小? 怎么构造当前答案?

- ==为什么能自己调用自己==? 函数名只是代码的==入口==——每次调用都开一张==新便签==、配一套新参数, 互不干扰

<span style="font-size:0.85em;">==递归 = 归纳法的计算版本==: 基准 = 奠基, 递归 = 归纳, 信任 = 归纳假设</span>

</div>

</div>

---

<!-- slide data-notes="" -->
##### 递归执行过程: 压栈与返回

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;text-align:center;">

<svg viewBox='0 0 400 292' style='max-width:100%;height:440px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='fact-down' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker><marker id='fact-up' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><g font-weight='700'><rect x='48' y='4' width='150' height='44' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='26' font-size='13' fill='#073642' text-anchor='middle'>fact(3)</text><text x='123' y='42' font-size='9' fill='#586e75' text-anchor='middle'>n = 3 → 3 × fact(2)</text><rect x='48' y='76' width='150' height='44' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='98' font-size='13' fill='#073642' text-anchor='middle'>fact(2)</text><text x='123' y='114' font-size='9' fill='#586e75' text-anchor='middle'>n = 2 → 2 × fact(1)</text><rect x='48' y='148' width='150' height='44' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='170' font-size='13' fill='#073642' text-anchor='middle'>fact(1)</text><text x='123' y='186' font-size='9' fill='#586e75' text-anchor='middle'>n = 1 → 1 × fact(0)</text><rect x='48' y='220' width='150' height='44' rx='8' fill='#fdf6e3' stroke='#859900' stroke-width='3'/><text x='123' y='242' font-size='13' fill='#073642' text-anchor='middle'>fact(0)</text><text x='123' y='258' font-size='9' fill='#586e75' text-anchor='middle'>n = 0，命中基准 → return 1</text></g><path d='M123 48 V72' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><path d='M123 120 V144' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><path d='M123 192 V216' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><text x='133' y='64' font-size='8' fill='#268bd2'>递推</text><text x='133' y='136' font-size='8' fill='#268bd2'>递推</text><text x='133' y='208' font-size='8' fill='#268bd2'>递推</text><path d='M300 262 V16' stroke='#859900' stroke-width='2.5' fill='none' marker-end='url(#fact-up)'/><text x='310' y='16' font-size='8.5' fill='#859900' font-weight='700'>回归（弹栈）</text><text x='310' y='42' font-size='8.5' fill='#859900'>返回 3 × 2 = 6</text><text x='310' y='114' font-size='8.5' fill='#859900'>返回 2 × 1 = 2</text><text x='310' y='186' font-size='8.5' fill='#859900'>返回 1 × 1 = 1</text><text x='310' y='258' font-size='8.5' fill='#859900'>返回 1</text><text x='48' y='284' font-size='8' fill='#586e75'>蓝色：递推（压栈）　绿色：回归（弹栈）</text></g></svg>

</div>

<div style="flex:1;font-size:0.9em;line-height:1.52;padding-right:16px;">

fact(3) 的跟踪——==递推==下去, 再==回归==上来:

- 每一层调用压一张==便签== (昨天的栈), 回归时逐层弹栈==结算==——递归就是便签一层层叠高、再一层层揭掉

- 每层调用有==自己的一套局部变量和参数==, 各层互不干扰 (作用域与生命期见上一讲)

- 递归深度 = 压栈层数; 递归过深 → ==栈溢出==

<div style="margin-top:10px;font-size:0.86em;line-height:1.4;">
<p style="margin:0.2rem 0;">🎬 ==动画==: 打开调用栈动画, 看阶乘递归的层层压栈与返回</p>
<p style="margin:0.2rem 0;">🌐 ==Python Tutor==: 把课程中的阶乘代码粘进去, 逐行看栈帧——每调用一次 fact, 栈上多一张便签; 返回时逐层揭掉</p>
</div>

</div>

</div>

<div style="margin:6px 2rem 0;font-size:0.75em;">
<a href="../8-functions/function-and-stack.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🎬 打开调用栈动画 (function-and-stack.html)</a> <a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (逐行看栈帧)</a>
</div>

---

<!-- slide data-notes="" -->


##### Fibonacci 数列

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
#include <stdio.h>
long long fib(long long n)
{
  if (n == 0) {              /* 奠基之一: F(0) = 0 */
    return 0;
  }
  if (n == 1) {              /* 奠基之二: F(1) = 1 */
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}
int main(void)
{
  printf("fib(10) = %lld\n", fib(10));
  return 0;
}
```

<div style="font-size:0.85em;color:#586e75;">

样例输出: `fib(10) = 55`

</div>

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- ==两个奠基==: 递推式需要==前两项==, 所以基准情形有两个、返回不同值 (对比阶乘: 只靠 0! 一个奠基就够)

- F(n) = F(n-1) + F(n-2): 一次调用==分成两个分支==——递归展开成一棵二叉树, 深度 n、最多 2ⁿ 个结点

- ==重复计算==: fib(5) 会把 fib(3) 算 2 遍、fib(2) 算 3 遍——朴素递归的代价; 优化办法 (记忆化/动态规划) 课下可以了解

</div>

</div>

---


<!-- slide data-notes="" -->##### Hanoi 塔 · 任务与规则

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;">

<div style="font-size:0.86em;line-height:1.43;">

==传说==: 印度教寺庙里有 3 根柱子、64 个金盘, 僧侣昼夜不停地移动; 传说 64 个盘移完之日就是世界末日——放心, 一共要 2⁶⁴ − 1 步, 约 5849 亿年

</div>

<div style="display:flex;gap:14px;justify-content:center;margin-top:10px;">

<div style="text-align:center;">
<div style="font-size:0.8em;color:#586e75;">初始 (n = 3)</div>
<svg viewBox="0 0 150 130" style="max-width:100%;height:180px;">
<rect x="5" y="112" width="140" height="5" rx="2" fill="#93a1a1"/>
<rect x="23" y="30" width="4" height="82" fill="#586e75"/>
<rect x="73" y="30" width="4" height="82" fill="#586e75"/>
<rect x="123" y="30" width="4" height="82" fill="#586e75"/>
<text x="25" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">A</text>
<text x="75" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">B</text>
<text x="125" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">C</text>
<rect x="5" y="96" width="40" height="13" rx="4" fill="#268bd2"/>
<text x="25" y="106" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">3</text>
<rect x="13" y="83" width="24" height="13" rx="4" fill="#b58900"/>
<text x="25" y="93" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">2</text>
<rect x="19" y="70" width="12" height="13" rx="3" fill="#dc322f"/>
<text x="25" y="80" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">1</text>
</svg>
</div>

<div style="text-align:center;">
<div style="font-size:0.8em;color:#586e75;">目标</div>
<svg viewBox="0 0 150 130" style="max-width:100%;height:180px;">
<rect x="5" y="112" width="140" height="5" rx="2" fill="#93a1a1"/>
<rect x="23" y="30" width="4" height="82" fill="#586e75"/>
<rect x="73" y="30" width="4" height="82" fill="#586e75"/>
<rect x="123" y="30" width="4" height="82" fill="#586e75"/>
<text x="25" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">A</text>
<text x="75" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">B</text>
<text x="125" y="126" font-size="12" fill="#268bd2" text-anchor="middle" font-weight="700">C</text>
<rect x="105" y="96" width="40" height="13" rx="4" fill="#268bd2"/>
<text x="125" y="106" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">3</text>
<rect x="113" y="83" width="24" height="13" rx="4" fill="#b58900"/>
<text x="125" y="93" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">2</text>
<rect x="119" y="70" width="12" height="13" rx="3" fill="#dc322f"/>
<text x="125" y="80" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">1</text>
</svg>
</div>

</div>

</div>

<div style="flex:1;font-size:0.86em;line-height:1.43;">

==盘子编号==: 最小的叫 ==盘 1== (叠在最上面), ==往下==依次是 ==盘 2、盘 3……==, 最大的叫 ==盘 n== (最下面; 后面代码输出的就是这些编号)

==目标==: 把 n 个盘子从 A 柱==全部移到 C 柱==, 结束时仍然==上小下大== (和初始状态一样)

==规则==:

- 每次只能移动==一个盘子== (某根柱最上面的)

- 大盘==不能压在小盘==上

- 可以借 B 柱==暂存==

==任务==: 给定任意 n, 设计算法输出==全部移动步骤== (每一步: 哪个盘、从哪柱到哪柱)

→ ==下一页==: 先看 3 个盘实际怎么挪

</div>

</div>

---

<!-- slide data-notes="" -->##### Hanoi 塔 · 盘子动画

---

<div style="display:flex;align-items:center;gap:20px;">

<div style="flex:1.2;text-align:center;">
<svg viewBox="0 0 600 300" style="max-width:100%;height:300px;display:block;margin:0 auto;">
<rect x="60" y="270" width="480" height="8" rx="4" fill="#93a1a1"/>
<rect x="147" y="100" width="6" height="170" fill="#586e75"/>
<rect x="297" y="100" width="6" height="170" fill="#586e75"/>
<rect x="447" y="100" width="6" height="170" fill="#586e75"/>
<text x="150" y="292" font-size="18" fill="#268bd2" text-anchor="middle" font-weight="700">A</text>
<text x="300" y="292" font-size="18" fill="#268bd2" text-anchor="middle" font-weight="700">B</text>
<text x="450" y="292" font-size="18" fill="#268bd2" text-anchor="middle" font-weight="700">C</text>
<g id="h3"><rect x="-40" y="-11" width="80" height="22" rx="5" fill="#268bd2"/><text x="0" y="4" font-size="12" fill="#fff" text-anchor="middle" font-weight="700">3</text></g>
<g id="h2"><rect x="-30" y="-11" width="60" height="22" rx="5" fill="#b58900"/><text x="0" y="4" font-size="12" fill="#fff" text-anchor="middle" font-weight="700">2</text></g>
<g id="h1"><rect x="-20" y="-11" width="40" height="22" rx="5" fill="#dc322f"/><text x="0" y="4" font-size="12" fill="#fff" text-anchor="middle" font-weight="700">1</text></g>
</svg>
</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;position:relative;z-index:10;pointer-events:auto;">

<div id="hanoiMsg" style="font-weight:700;min-height:1.6em;">初始状态: 3 个盘都在 A</div>

<div id="hanoiStep" style="color:#586e75;margin-bottom:8px;">0 / 7</div>

<button onclick="hanoiNext()" style="display:block;pointer-events:auto!important;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#268bd2;color:#fff;border:none;border-radius:8px;cursor:pointer;">▶ 下一步</button>

<button onclick="hanoiAuto()" style="display:block;pointer-events:auto!important;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#859900;color:#fff;border:none;border-radius:8px;cursor:pointer;">▶▶ 自动播放 (7 步)</button>

<button onclick="hanoiReset()" style="display:block;pointer-events:auto!important;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#b58900;color:#fff;border:none;border-radius:8px;cursor:pointer;">⟲ 重来</button>

- 按 "下一步" 逐盘观察: 大盘==永远不压小盘== (规则见上一页), 3 个盘恰好要 ==7 步==

- 第 4 步恰好是==最大盘就位==——后面讲递归分解时对照着看

</div>

</div>

<script src="code/hanoi-anim.js"></script>

---

<!-- slide data-notes="" -->##### Hanoi 塔

---

<style>#hanoi-code pre{padding:0.35em 0.6em!important;margin:0.2rem 0!important}#hanoi-code pre code{font-size:17px!important;line-height:1.2!important;padding:0!important;max-height:none!important}</style>

<div style="display:flex;align-items:flex-start;gap:24px;">

<div id="hanoi-code" style="flex:1;font-size:0.6em;">

```C
/* hanoi.c: A = 起始柱, B = 辅助柱, C = 目标柱;
   n = 本次要移的盘数 (最大盘编号) */
#include <stdio.h>

void Hanoi(int n, char A, char B, char C)
{
  if (n == 1) {
    /* 基准: 只剩一个盘 */
    printf("盘 %d: %c -> %c\n", n, A, C);
  } else {
    /* 上面 n-1 个: A -> B (借 C) */
    Hanoi(n - 1, A, C, B);
    /* 最大盘: A -> C */
    printf("盘 %d: %c -> %c\n", n, A, C);
    /* 上面 n-1 个: B -> C (借 A) */
    Hanoi(n - 1, B, A, C);
  }
}

int main(void)
{
  /* 3 个盘的完整移法 */
  Hanoi(3, 'A', 'B', 'C');
  return 0;
}
```

</div>

<div style="flex:1.5;font-size:0.76em;line-height:1.32;">

<div style="text-align:center;margin-bottom:2px;">
<svg viewBox="0 0 320 150" style="max-width:100%;height:140px;display:block;margin:0 auto;">
<defs>
<marker id="ah-red" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto" markerUnits="strokeWidth"><path d="M0,0 L6,3 L0,6 z" fill="#dc322f"/></marker>
<marker id="ah-blue" markerWidth="6" markerHeight="6" refX="5" refY="3" orient="auto" markerUnits="strokeWidth"><path d="M0,0 L6,3 L0,6 z" fill="#268bd2"/></marker>
</defs>
<rect x="6" y="118" width="308" height="5" rx="2" fill="#93a1a1"/>
<path d="M 85 109 Q 160 112 235 109" fill="none" stroke="#268bd2" stroke-width="1.5" marker-end="url(#ah-blue)"/>
<rect x="53" y="32" width="4" height="86" fill="#586e75"/>
<rect x="158" y="32" width="4" height="86" fill="#586e75"/>
<rect x="263" y="32" width="4" height="86" fill="#586e75"/>
<rect x="27" y="103" width="56" height="13" rx="4" fill="#268bd2"/>
<text x="55" y="113" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">n</text>
<rect x="34" y="92" width="42" height="11" rx="4" fill="#b58900"/>
<rect x="40" y="81" width="30" height="11" rx="4" fill="#dc322f"/>
<rect x="46" y="70" width="18" height="11" rx="4" fill="#859900"/>
<rect x="139" y="92" width="42" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<rect x="145" y="81" width="30" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<rect x="151" y="70" width="18" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<rect x="237" y="103" width="56" height="13" rx="4" fill="#268bd2"/>
<text x="265" y="113" font-size="9" fill="#fff" text-anchor="middle" font-weight="700">n</text>
<rect x="244" y="92" width="42" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<rect x="250" y="81" width="30" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<rect x="256" y="70" width="18" height="11" rx="4" fill="none" stroke="#586e75" stroke-width="1.2" stroke-dasharray="3 3"/>
<path d="M 66 72 Q 110 54 149 72" fill="none" stroke="#dc322f" stroke-width="1.5" stroke-dasharray="4 3" marker-end="url(#ah-red)"/>
<path d="M 175 73 Q 214 52 250 73" fill="none" stroke="#dc322f" stroke-width="1.5" stroke-dasharray="4 3" marker-end="url(#ah-red)"/>
<text x="100" y="76" font-size="9" fill="#586e75">n-1 个</text>
<text x="108" y="56" font-size="10" fill="#dc322f" font-weight="700">①</text>
<text x="93" y="97" font-size="10" fill="#268bd2" font-weight="700">②</text>
<text x="212" y="48" font-size="10" fill="#dc322f" font-weight="700">③</text>
<text x="55" y="133" font-size="11" fill="#268bd2" text-anchor="middle" font-weight="700">A</text>
<text x="160" y="133" font-size="11" fill="#268bd2" text-anchor="middle" font-weight="700">B</text>
<text x="265" y="133" font-size="11" fill="#268bd2" text-anchor="middle" font-weight="700">C</text>
</svg>
</div>

<div style="text-align:center;margin-top:4px;font-size:0.8em;">
<span style="color:#dc322f;font-weight:700;">①</span> n-1 个: A → B (虚线) &nbsp;&nbsp; <span style="color:#268bd2;font-weight:700;">②</span> 盘 n: A → C (实线) &nbsp;&nbsp; <span style="color:#dc322f;font-weight:700;">③</span> n-1 个: B → C (虚线)
</div>

==刚才的动画== (3 个盘、7 步) 正是来自下面的==分解== (A 起始、B 辅助、C 目标):

- ① 先把上面 ==n-1 个== A → B (借 C)——同类问题小 1

- ② 把==最大盘 n== 直接 A → C——一步完成

- ③ 再把那 ==n-1 个== B → C (借 A)

<span style="font-size:0.85em;">①③ 交给递归; n = 1 直接 A → C (基准情形)</span>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/hanoi.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 打开 hanoi.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### Hanoi 塔 · 调用过程与运行结果

---

==动画里的 7 步==, 正是下面这棵调用树逐层产生的:

<div style="font-size:0.8em;">

```text
Hanoi(3, A, B, C)
 ├─ Hanoi(2, A, C, B)        ← 先把上面 2 个 A→B
 │    ├─ Hanoi(1, A, B, C) → 盘1: A→C
 │    ├─ 盘2: A→B
 │    └─ Hanoi(1, C, A, B) → 盘1: C→B
 ├─ 盘3: A→C                 ← 最大盘就位
 └─ Hanoi(2, B, A, C)        ← 再把上面 2 个 B→C
      ├─ Hanoi(1, B, C, A) → 盘1: B→A
      ├─ 盘2: B→C
      └─ Hanoi(1, A, B, C) → 盘1: A→C
```

</div>

运行输出 (共 7 步): <span style="font-size:0.75em;font-family:Menlo,monospace;">盘1: A→C &nbsp; 盘2: A→B &nbsp; 盘1: C→B &nbsp; 盘3: A→C &nbsp; 盘1: B→A &nbsp; 盘2: B→C &nbsp; 盘1: A→C</span>

<a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (粘代码, 逐层看调用栈)</a>

---

<!-- slide data-notes="" -->


##### 常见错误

---

- ==缺少基准情形==: 递归永不终止 (如忘了 n==0 的判断)

- ==问题没有缩小==: 每次调用与上次规模相同 (如 f(n) 里调用 f(n))

<span class="blue">:fa-lightbulb-o:</span> 写递归的两步检查: ① 基准情形对吗? ② 每次调用规模在变小吗?

→ ==下一页==: 现场演示"没有基准情形"的下场——调用栈爆掉

---


<!-- slide data-notes="" -->##### 演示: 没有基准情形的栈溢出

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.85em;">

```C
/* 不规范: 少了基准情形 */
long long fact(int n)
{
  return n * fact(n - 1);
}

int main(void)
{
  printf("%lld\n", fact(5));
  return 0;
}
```

<div style="font-size:0.8em;color:#dc322f;">

运行结果: 一阵呼啸之后——

Segmentation fault (core dumped)

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/stack-overflow.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 stack-overflow.c (直接编译运行, 看它崩溃)</a>

</div>

<div style="flex:1;font-size:0.95em;line-height:1.6;">

- 每一层调用压一张便签; 没有基准情形, 便签就==无限叠高==——谁也不返回, 谁也腾不出空间

- 栈的空间是==有限==的 (默认几 MB): 用尽即 ==栈溢出== (stack overflow), 程序直接崩溃

- 即使有基准情形, ==极大的递归==也会爆: 递归深度以"层"计, 大输入要留意 (如对 10 万个元素的数组递归求最大值)

- 应对: 递归三问缺一不可; 有些递归能改写成==循环==——循环不占栈, 深了也不怕 (这是"尾递归优化"的朴素版理解)

</div>

</div>

---

<!-- slide data-notes="" -->

##### 课堂编码: 基础三题

---

<style>.mcols{display:flex;align-items:flex-start;gap:18px;margin:0 1.2rem;}.mcols>div{flex:1;min-width:0;}.mcols>div:last-child{padding-right:14px;}.mcols p{margin:0.28rem 0;text-align:left;}.mcols ul{margin:0.1rem 0;padding-left:0.9rem;}.mcols ul>li{margin:0.12rem 0.8rem 0.12rem 0;}.mcols ul>li>p{margin:0.08rem 0;}.mcols .ct{font-weight:700;color:#268bd2;margin-bottom:4px;}.mcols pre{font-size:15px!important;line-height:1.22!important;padding:0.3em 0.2em!important;margin:0.15rem 0!important;max-height:none!important;}.mcols pre code{font-size:15px!important;line-height:1.22!important;padding:0!important;max-height:none!important;}.mcols.two pre,.mcols.two pre code{font-size:16px!important;}</style>

<div class="mcols">

<div style="font-size:0.62em;line-height:1.55;padding-right:16px;border-right:1px solid #eee8d5;">

<div class="ct">课堂编码 1: 递归求幂</div>

==任务==: 实现 `int power(int x, int n)`——计算 x 的 n 次方 (开篇"递归是什么"一页提过的例子, 这里把它写完整)

样例: `power(5, 3)` → 125; `power(2, 10)` → 1024

==先想参数==: 哪些量随递归变化、哪些全程不变?

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/power-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 power-rec.c (只写函数体)</a>

</div>

<div style="font-size:0.62em;line-height:1.55;padding-right:16px;border-right:1px solid #eee8d5;">

<div class="ct">课堂编码 2: 递归求和</div>

==任务==: 实现 `int sum(int n)`——计算 1 + 2 + … + n

样例: `sum(10)` → 55; `sum(100)` → 5050

<span class="blue">:fa-lightbulb-o:</span> 提示: 先想清楚==递推关系==和==递归出口==, 再动手写

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/sum-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 sum-rec.c (只写函数体)</a>

</div>

<div style="font-size:0.62em;line-height:1.55;">

<div class="ct">课堂编码 3: 递归打印整数</div>

==任务==: 实现 `void print(int n)`——输入 1234, 按位逐个打印

样例: `1234` → `1 2 3 4`

<span class="blue">:fa-lightbulb-o:</span> 提示: 先递归打印前面几位, 回来再打印末位——==顺序是本题关键==

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/print-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 print-rec.c (只写函数体)</a>

</div>

</div>
<!-- slide data-notes="" -->

##### 课堂编码 · 参考实现

---

<div class="mcols">

<div style="font-size:0.58em;line-height:1.5;padding-right:12px;border-right:1px solid #eee8d5;">

<div class="ct">参考实现 1: 递归求幂</div>

```C
int power(int x, int n)
{
  /* 基准 x^0=1; 递归 x × x^(n-1) */
  return n == 0 ? 1 : x * power(x, n - 1);
}
```

- ==参数即状态==: 底数 x 全程不变, 指数 n 逐层减 1——两个量都要进参数, 缺一不可
- ==基准情形==: n == 0 → 1; 递归情形把问题缩小成 x^(n-1)

</div>

<div style="font-size:0.58em;line-height:1.5;padding-right:12px;border-right:1px solid #eee8d5;">

<div class="ct">参考实现 2: 递归求和</div>

```C
int sum(int n)
{
  /* 基准 0; 递归 n + sum(n-1) */
  return n == 0 ? 0 : n + sum(n - 1);
}
```

- ==参数即状态==: 只带 n——"加到几为止"就是子问题的全部状态
- ==基准情形==: n == 0 → 0; 递归情形: sum(n) = n + sum(n-1)

</div>

<div style="font-size:0.58em;line-height:1.5;">

<div class="ct">参考实现 3: 递归打印整数</div>

```C
void print(int n)
{
  if (n / 10 == 0) {
    /* 基准: 一位数直接打印 */
    printf("%d", n);
  } else {
    /* 先递归打印前面几位 */
    print(n / 10);
    /* 回来再打印末位 —— 顺序是本题关键 */
    printf(" %d", n % 10);
  }
}
```

- ==参数即状态==: 只带 n; ==顺序是本题关键==——先递归打印 n/10, 回来再打印末位 n%10, 得到正序
- ==基准情形==: 一位数 (n / 10 == 0) 直接打印

</div>

</div>
<!-- slide data-notes="" -->

##### 课堂案例: 递归求最大值与判断回文

---

<div class="mcols two">

<div style="font-size:0.64em;line-height:1.55;padding-right:16px;border-right:1px solid #eee8d5;">

<div class="ct">课堂案例 1: 递归求最大值</div>

==任务==: 实现 `int max_rec(int a[], int n)`——最大值 = `a[n-1]` 与 "前 n-1 个的最大值" 里较大的那个 (与之前"先假设再修正"同源)

样例: `a = {3, 9, 1, 7, 5}` → 输出 `9`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/max-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 max-rec.c (只写函数体)</a>

</div>

<div style="font-size:0.64em;line-height:1.55;">

<div class="ct">课堂案例 2: 判断回文</div>

==任务==: 判断字符串是否回文——两端字符相等, 且中间那一段也是回文 (回文用循环双指针更自然; 这题的价值是练习"把递归定义==直接翻译==成代码")

==先想参数==: `int is_pal( ??? )`——子问题是"首尾去掉后剩下的中间一段", 要==几个参数==才能刻画它? 需要复制一个新字符串吗? 想清楚再打开 VS Code 对照

样例: `"level"` → 1, `"hello"` → 0

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/pal-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 pal-rec.c (自己设计签名 + 函数体 + main 调用)</a>

</div>

</div>
<!-- slide data-notes="" -->

##### 课堂案例: 递归求最大值与判断回文 · 参考实现

---

<div class="mcols two">

<div style="font-size:0.58em;line-height:1.5;padding-right:12px;border-right:1px solid #eee8d5;">

<div class="ct">案例 1: 递归求最大值</div>

```C
int max_rec(int a[], int n)
{
  int rest;
  if (n == 1) {                    /* 基准情形 */
    return a[0];
  }
  rest = max_rec(a, n - 1);        /* 递归: 前 n-1 个的最大值 */
  return a[n - 1] > rest ? a[n - 1] : rest;
}
```

- 递归情形里==先信任== `max_rec(a, n-1)` 是对的, 再拿 `a[n-1]` 和它比——这就是"信任递归"

</div>

<div style="font-size:0.58em;line-height:1.5;">

<div class="ct">案例 2: 判断回文</div>

```C
int is_pal(char s[], int l, int r)
{
  if (l >= r) {                    /* 基准: 0 或 1 个字符 */
    return 1;
  }
  return s[l] == s[r] && is_pal(s, l + 1, r - 1);
}
```

- ==参数即状态==: l、r 刻画当前子串——不复制字符串, 只移动两个下标
- ==定义即代码==: 把"首尾相等且中间是回文"逐字翻译出来, 就是函数体

</div>

</div>
<!-- slide data-notes="" -->##### 课堂案例: 二分查找

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 在升序数组 a 的某个区间里查找 key——每次砍一半, 与分治同构; 找到返回下标, 找不到返回 -1

==先想参数==: `int bin_search( ??? )`——==子问题是什么==? 哪几个量==随递归变化==、哪几个==全程不变==? 想清楚再打开 VS Code 对照骨架里的签名

样例: 在 `{2, 5, 8, 12, 19}` 中找 8 → 下标 2; 找 7 → -1

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/bin-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 bin-rec.c (自己设计签名 + 函数体 + main 调用)</a>

---

<!-- slide data-notes="" -->##### 课堂案例: 二分查找 · 参考实现

---

<div style="font-size:0.85em;">

```C
int bin_search(int a[], int low, int high, int key)
{
  int mid;
  if (low > high) {                /* 基准: 没找到 */
    return -1;
  }
  mid = (low + high) / 2;
  if (a[mid] == key) {
    return mid;
  }
  if (a[mid] > key) {
    return bin_search(a, low, mid - 1, key);
  }
  return bin_search(a, mid + 1, high, key);
}
```

</div>

- ==参数即状态==: 递归函数的参数要能完整描述"当前子问题"——low、high 刻画查找区间, key 与 a 全程不变

- 每次调用区间==必然缩小==——这保证递归一定终止; 下一页分治法正是这个思想的放大版

---

<!-- slide data-notes="" -->

##### 课堂案例: 组合数与爬楼梯

---

<div class="mcols two">

<div style="font-size:0.64em;line-height:1.55;padding-right:16px;border-right:1px solid #eee8d5;">

<div class="ct">课堂案例 4: 组合数</div>

==任务==: C(m,n) = 从 m 个元素中选出 n 个的==方案数==。实现 `long comb(int m, int n)`——按"选/不选第 m 个元素"分成两类: C(m,n) = C(m-1,n-1) + C(m-1,n); 对比 8-2 用 factorial 的公式算法: 递归定义有时比公式==更直接==

样例: `comb(5, 2)` → 10

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/comb-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 comb-rec.c (只写函数体)</a>

</div>

<div style="font-size:0.64em;line-height:1.55;">

<div class="ct">课堂案例 5: 爬楼梯</div>

==任务==: 有 n 级台阶, 每次可以走 ==1 或 2 级==——从第 0 级走到第 n 级共有==多少种走法==? 实现 `int climb(int n)`

样例: `climb(4)` → 5 (走法: 1111、112、121、211、22)

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/climb-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 climb-rec.c (只写函数体)</a>

</div>

</div>
<!-- slide data-notes="" -->

##### 课堂案例: 组合数与爬楼梯 · 参考实现

---

<div class="mcols two">

<div style="font-size:0.58em;line-height:1.5;padding-right:12px;border-right:1px solid #eee8d5;">

<div class="ct">案例 4: 组合数</div>

```C
long comb(int m, int n)
{
  if (n == 0 || n == m) {          /* 基准情形 */
    return 1;
  }
  return comb(m - 1, n - 1) + comb(m - 1, n);
}
```

- 同一行里两个递归调用——先展开一层看: "选中第 m 个"与"不选第 m 个"两类, 加起来

</div>

<div style="font-size:0.58em;line-height:1.5;">

<div class="ct">案例 5: 爬楼梯</div>

```C
int climb(int n)
{
  if (n <= 1) {                    /* 基准情形 */
    return 1;
  }
  return climb(n - 1) + climb(n - 2);
}
```

- 生活问题→递归定义: 走到第 n 级的方法数 = 走到 n-1 的方法数 + 走到 n-2 的方法数

</div>

</div>
<!-- slide data-notes="" -->


##### 分治法

---

==分治法== (divide and conquer): 把大问题拆成几个==同类的小问题==, 分别解决, 再合并结果



- 三步: ==分== (拆) → ==治== (解决小问题) → ==合== (拼起来)

- 生活例子: 整理一摞试卷——先按分数段分堆, 每堆再各自整理

- 排序中的分治 (快速排序): 选一个==基准==, 把数组划分成"小的在左、大的在右"两段, 再对两段各自递归——==不需要合并== (划分完位置就对了); 过程见==下一页==

- ("分成两半各自排好再合并"是另一种排序——归并排序, 课下可以了解)

<span class="blue">:fa-lightbulb-o:</span> 递归常常是分治法的==自然结果==——快速排序正是如此




<!-- slide data-notes="" -->##### 分治图示: 快速排序

---

<div style="text-align:center;margin:2px 0;">
<svg viewBox='0 0 400 210' style='max-width:100%;height:310px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='qk-blue' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker><marker id='qk-green' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><g font-size='9' fill='#586e75' text-anchor='end' font-weight='700'><text x='90' y='49'>原数组</text><text x='90' y='111'>划分后</text><text x='90' y='173'>最终</text></g><g font-size='11' text-anchor='middle' font-weight='700'><rect x='98' y='30' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='115' y='50' fill='#fdf6e3'>5</text><rect x='132' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='149' y='50' fill='#073642'>2</text><rect x='166' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='183' y='50' fill='#073642'>9</text><rect x='200' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='217' y='50' fill='#073642'>1</text><rect x='234' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='251' y='50' fill='#073642'>8</text><rect x='268' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='285' y='50' fill='#073642'>3</text></g><path d='M200 60 V88' stroke='#268bd2' stroke-width='2' fill='none' marker-end='url(#qk-blue)'/><text x='208' y='76' font-size='9' fill='#268bd2'>① 划分</text><g font-weight='700'><rect x='98' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='115' y='112' font-size='11' fill='#073642' text-anchor='middle'>2</text><rect x='132' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='149' y='112' font-size='11' fill='#073642' text-anchor='middle'>1</text><rect x='166' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='183' y='112' font-size='11' fill='#073642' text-anchor='middle'>3</text><rect x='200' y='92' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='217' y='112' font-size='11' fill='#fdf6e3' text-anchor='middle'>5</text><rect x='234' y='92' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='251' y='112' font-size='11' fill='#073642' text-anchor='middle'>9</text><rect x='268' y='92' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='285' y='112' font-size='11' fill='#073642' text-anchor='middle'>8</text></g><g fill='none' stroke-width='1.5'><path d='M98 90 V86 H200 V90' stroke='#268bd2'/><path d='M200 90 V86 H302 V90' stroke='#859900'/></g><text x='149' y='82' font-size='8.5' fill='#268bd2' text-anchor='middle'>左段（&lt;5）</text><text x='268' y='82' font-size='8.5' fill='#859900' text-anchor='middle'>右段（&gt;5）</text><path d='M200 122 V150' stroke='#859900' stroke-width='2' fill='none' marker-end='url(#qk-green)'/><text x='208' y='140' font-size='9' fill='#859900'>② 各自递归</text><g font-size='11' text-anchor='middle' font-weight='700'><rect x='98' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='115' y='174' fill='#073642'>1</text><rect x='132' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='149' y='174' fill='#073642'>2</text><rect x='166' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='183' y='174' fill='#073642'>3</text><rect x='200' y='154' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='217' y='174' fill='#fdf6e3'>5</text><rect x='234' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='251' y='174' fill='#073642'>8</text><rect x='268' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='285' y='174' fill='#073642'>9</text></g><text x='312' y='49' font-size='9' fill='#b58900' font-weight='700'>基准 = 5</text><text x='312' y='106' font-size='9' fill='#586e75'>5 已就位</text><text x='312' y='120' font-size='9' fill='#859900'>左右各自递归</text><text x='312' y='173' font-size='9' fill='#859900' font-weight='700'>无需合并</text><text x='98' y='202' font-size='9.5' fill='#586e75'>基准位置一次到位 → 左右两段递归即可，不需要合并</text></g></svg>
</div>

- ==① 划分==: 选基准 5, 小的放左、大的放右——5 的位置就此==一次到位==

- ==② 治==: 左段 [2, 1, 3] 和右段 [9, 8] 各自递归——同样先划分、再递归

- ==③ 合==: ==什么都不用做==——每次划分都把基准放到最终位置, 递归结束时整个数组就有序了

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/qsort-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 自己动手: 打开 qsort-rec.c (框架只有 main)——对照图示写 quicksort 和 split</a>

<!-- slide data-notes="" -->


##### 递归排序: 快速排序

---

用==递归==做排序: 选一个基准, 小的放左、大的放右, 再对左右递归

```C{.line-numbers}
void quicksort(int a[], int low, int high)
{
  int middle;

  if (low >= high) {          /* 基准情形: 只剩 0 或 1 个元素 */
    return;
  }
  middle = split(a, low, high);       /* 划分: 小的在左, 大的在右 */
  quicksort(a, low, middle - 1);      /* 递归排左半 */
  quicksort(a, middle + 1, high);     /* 递归排右半 */
}
```

- 平均 O(n log n), 比之前三种排序的 O(n^2) 快得多

- `split` 是划分函数, 下一页展开


<!-- slide data-notes="" -->


##### 快速排序: 划分函数 split

---

<style>#split-code pre{padding:0.35em 0.6em!important;margin:0.2rem 0!important}#split-code pre code{font-size:17px!important;line-height:1.2!important;padding:0!important;max-height:none!important}</style>

<div style="display:flex;align-items:flex-start;gap:24px;">

<div id="split-code" style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
int split(int a[], int low, int high)
{
  int part_element = a[low];

  for (;;) {
    while (low < high && part_element <= a[high]) {
      high--;
    }
    if (low >= high) {
      break;
    }
    a[low++] = a[high];

    while (low < high && a[low] <= part_element) {
      low++;
    }
    if (low >= high) {
      break;
    }
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}
```

</div>

<div style="flex:1;">

==split==: 以 `a[low]` 为基准, 把小元素换到左边、大的换到右边, 返回基准的最终下标

完整可运行程序: [code/qsort-split.c](code/qsort-split.c) (无指针版, 全部用数组下标)

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 概念: 递归函数必须具备哪两个要素？

2. 概念: f(5) 计算 5! 的过程中，栈上最多同时压了几层调用？

3. 代码阅读: fib(5) 中 fib(2) 被计算了几次？这说明了什么？

4. 纠错: 递归函数忘了写基准情形会怎样？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


