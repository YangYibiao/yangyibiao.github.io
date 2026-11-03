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

- 作用域与生命期

- 经典案例: Fibonacci、最大公约数、汉诺塔 (弹性)

- 常见错误与课堂编码 (基础 + 三个经典案例)

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
long f(long n)
{
  if (n == 0 || n == 1) {  /* 基准情形: 直接给答案 */
    return 1;
  }
  return n * f(n - 1);     /* 递归情形: 缩小后再调用 */
}
```

```C
/* 求幂: x^n = x × x^(n-1), 可以精简成一行 */
int power(int x, int n) {
    return n == 0 ? 1 : x * power(x, n - 1);
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.5;">

- ==两个要素==: ==基准情形== (最简单、直接给答案) + ==递归情形== (把问题==缩小==后再调用自己)

- ==信任递归==: 假设 n-1 层的答案是对的, 用它构造 n 的答案——==不要在脑中展开所有层==

- ==递归三问==: 最小问题? 怎么缩小? 怎么构造当前答案?

- ==为什么能自己调用自己==? 函数名只是代码的==入口==——每次调用都开一张==新便签==、配一套新参数, 互不干扰

<span style="font-size:0.85em;">==递归 = 归纳法的计算版本==: 基准情形 = 奠基, 递归情形 = 归纳步骤, 信任递归 = 归纳假设</span>

</div>

</div>

---

<!-- slide data-notes="" -->

##### 递归执行过程

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;text-align:center;">

<svg viewBox='0 0 400 200' style='max-width:100%;height:320px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='fact-down' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker><marker id='fact-up' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><g font-weight='700'><rect x='48' y='8' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='25' font-size='15.4' fill='#073642' text-anchor='middle'>fact(3)</text><text x='123' y='39' font-size='11.0' fill='#586e75' text-anchor='middle'>n = 3 → 3 × fact(2)</text><rect x='48' y='76' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='93' font-size='15.4' fill='#073642' text-anchor='middle'>fact(2)</text><text x='123' y='107' font-size='11.0' fill='#586e75' text-anchor='middle'>n = 2 → 2 × fact(1)</text><rect x='48' y='144' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#859900' stroke-width='3'/><text x='123' y='161' font-size='15.4' fill='#073642' text-anchor='middle'>fact(1)</text><text x='123' y='175' font-size='11.0' fill='#586e75' text-anchor='middle'>n = 1，命中基准 → return 1</text></g><path d='M123 46 V72' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><path d='M123 114 V140' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><text x='133' y='63' font-size='9.9' fill='#268bd2'>递推（压栈）</text><text x='133' y='131' font-size='9.9' fill='#268bd2'>递推（压栈）</text><path d='M300 184 V20' stroke='#859900' stroke-width='2.5' fill='none' marker-end='url(#fact-up)'/><text x='310' y='12' font-size='9.9' fill='#859900' font-weight='700'>回归（弹栈）</text><text x='310' y='38' font-size='9.9' fill='#859900'>返回 3 × 2 = 6</text><text x='310' y='106' font-size='9.9' fill='#859900'>返回 2 × 1 = 2</text><text x='310' y='176' font-size='9.9' fill='#859900'>返回 1</text><text x='48' y='196' font-size='9.9' fill='#586e75'>蓝色：递推（压栈）　绿色：回归（弹栈）</text></g></svg>

</div>

<div style="flex:1;font-size:0.95em;line-height:1.6;">

fact(3) 的跟踪——==递推==下去, 再==回归==上来:

- 每一层调用压一张==便签== (昨天的栈), 回归时逐层弹栈==结算==——递归就是便签一层层叠高、再一层层揭掉

- 每层调用有==自己的一套局部变量和参数==, 各层互不干扰 (下一页: 生命期)

- 递归深度 = 压栈层数; 递归过深 → ==栈溢出==

</div>

</div>

---

<!-- slide data-notes="" -->##### 递归演示: 层层压栈与返回

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.85em;">

```C
#include <stdio.h>

long fact(int n)
{
  if (n == 0 || n == 1) {
    return 1;
  }
  return n * fact(n - 1);
}

int main(void)
{
  printf("%ld\n", fact(5));
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.95em;line-height:1.6;">

- 🎬 ==动画==: 打开调用栈动画, 看阶乘递归的层层压栈与返回

- 🌐 ==Python Tutor==: 把左栏代码粘进去, 逐行看栈帧——每调用一次 fact, 栈上多一张便签; 返回时逐层揭掉

<a href="../8-functions/function-and-stack.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🎬 打开调用栈动画 (function-and-stack.html)</a> <a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (逐行看栈帧)</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 标识符的作用域

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.7em;">

```C
int x = 0;            /* 文件作用域 */
void f(void)
{
  int x = 1;        /* 块作用域, 屏蔽全局 x */
  printf("%d", x);  /* 打印 1 */
}
```

<div style="text-align:center;margin:2px 0;">
<svg viewBox='0 0 400 200' style='max-width:100%;height:230px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='scope-red' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#dc322f'/></marker><marker id='scope-green' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><rect x='14' y='14' width='372' height='172' rx='10' fill='#fdf6e3' stroke='#93a1a1' stroke-width='2' stroke-dasharray='6 4'/><text x='28' y='34' font-size='14.0' fill='#586e75' font-weight='700'>文件作用域（整个 .c 文件）</text><rect x='28' y='44' width='150' height='32' rx='6' fill='#eee8d5' stroke='#b58900' stroke-width='2'/><text x='103' y='65' font-size='15.4' fill='#073642' text-anchor='middle' font-weight='700'>int x = 0;（全局）</text><rect x='50' y='88' width='300' height='86' rx='8' fill='#dceaf5' stroke='#268bd2' stroke-width='2.5'/><text x='205' y='108' font-size='13.3' fill='#268bd2' text-anchor='middle' font-weight='700'>f 的函数体（块作用域）</text><rect x='65' y='116' width='150' height='32' rx='6' fill='#fdf6e3' stroke='#dc322f' stroke-width='2.5'/><text x='140' y='137' font-size='15.4' fill='#073642' text-anchor='middle' font-weight='700'>int x = 1;（局部）</text><rect x='240' y='116' width='95' height='32' rx='6' fill='#fdf6e3' stroke='#859900' stroke-width='2'/><text x='287' y='137' font-size='15.4' fill='#073642' text-anchor='middle' font-weight='700'>printf → 1</text><path d='M100 116 V80' stroke='#dc322f' stroke-width='2' stroke-dasharray='5 3' fill='none' marker-end='url(#scope-red)'/><text x='108' y='100' font-size='12.6' fill='#dc322f'>遮蔽全局 x</text><path d='M215 132 H236' stroke='#859900' stroke-width='2' fill='none' marker-end='url(#scope-green)'/><text x='28' y='198' font-size='13.3' fill='#586e75'>全局变量整个文件可见；局部变量出了函数就不可见</text></g></svg>
</div>

</div>

<div style="flex:1;">

==作用域==: 标识符可以被使用的那段代码范围

- ==块作用域==: 函数体内 {} 覆盖的范围——局部变量、形式参数

- ==文件作用域==: 从定义位置到文件末尾——全局变量

- 内层屏蔽外层: 内层同名变量会==遮蔽==外层的

==局部变量==: 定义在函数内, 出了函数就不可见

- ==全局变量==: 定义在函数外, 整个文件可见; 少用为妙 (谁都可能改它)

</div>

</div>

<!-- slide data-notes="" -->


##### 变量的生命期

---

- ==动态变量==(默认): 函数被调用时诞生, 函数返回时消亡

- ==静态变量==(static): 与程序同生共死, 函数返回后==保留原值==

```C
void f(void)
{
  static int count = 0;  /* 只初始化一次 */
  count++;
  printf("第 %d 次调用\n", count);
}
```

- static 局部变量 = 带记忆的局部变量 (下次调用接着用上次的值)

- ==与递归的关系==: 递归的每一层调用都是一次独立的函数调用——各层的参数和局部变量==随层生、随层亡==, 互不干扰 (上一页"每层一套自己变量"的底层原因就在这里)

---


<!-- slide data-notes="" -->


##### 演示: 局部变量的"垃圾值"

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.85em;">

```C
void f(void) {
    int i;                    /* 没有初始化 */
    printf("i = %d\n", i);
}
int main(void) { f(); return 0; }
```

一次运行的结果 (每次可能不同!):

```
i = 32764
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 动态局部变量诞生时==不会自动清零==——里面是内存里残留的"垃圾值"

- 每次运行、每台机器都可能不同; 调试器里恰好是 `0` 只是假象

- 教训: ==局部变量必须初始化后再使用==; 编译加 `-Wall` 有时能提示 "used uninitialized"

- 递归函数里的局部变量也不例外——忘初始化的话, ==每一层==读到的都是垃圾值

</div>

</div>

---


<!-- slide data-notes="" -->


##### Fibonacci 数列

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
#include <stdio.h>
long fib(long n)
{
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n - 1) + fib(n - 2);
}
int main(void)
{
  int n;
  scanf("%d", &n);
  printf("fib(%d) = %ld\n", n, fib(n));
  return 0;
}
```

</div>

<div style="flex:1;">

F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)

f(5) 会把 f(3)、f(2) 各算多遍——重复计算是朴素递归的代价

</div>

</div>

<!-- slide data-notes="" -->


##### 递归求最大公约数

---

辗转相除法用递归表达: gcd(a, b) = gcd(b, a % b)

```C
int gcd(int a, int b)
{
  if (b == 0) {             /* 基准情形 */
    return a;
  }
  return gcd(b, a % b);     /* 递归情形 */
}
```

- 循环版比较: while (b != 0) { int r = a % b; a = b; b = r; }——递归版更接近数学定义 (注意: 循环条件里不要写赋值)

---


<!-- slide data-notes="" -->


##### Hanoi 塔

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
void Hanoi(int n, char A, char B, char C)
{
  if (n == 1) {
    printf("%c -> %c\n", A, C);      /* 基准: 只剩一个盘 */
  }
  else {
    Hanoi(n - 1, A, C, B);            /* 上面 n-1 个: A -> B (借 C) */
    printf("%c -> %c\n", A, C);      /* 最大盘: A -> C */
    Hanoi(n - 1, B, A, C);            /* 上面 n-1 个: B -> C (借 A) */
  }
}
```

```C
int main(void)
{
  Hanoi(3, 'A', 'B', 'C');     /* 3 个盘的完整移法 */
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.85em;line-height:1.5;">

3 根柱 A、B、C, 把 n 个盘子从 A 移到 C (大盘不能压小盘, 可借 B):

- n=1: 直接 A → C

- n>1: 先把上面 n-1 个 A → B (借 C), 再把最大盘 A → C, 最后 n-1 个 B → C (借 A)

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/hanoi.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 hanoi.c (直接编译运行)</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### Hanoi 塔 · 调用过程与运行结果

---

<div style="font-size:0.8em;">

```text
Hanoi(3, A, B, C)
 ├─ Hanoi(2, A, C, B)        ← 先把上面 2 个 A→B
 │    ├─ Hanoi(1, A, B, C) → A→C
 │    ├─ A→B
 │    └─ Hanoi(1, C, A, B) → C→B
 ├─ A→C                      ← 最大盘就位
 └─ Hanoi(2, B, A, C)        ← 再把上面 2 个 B→C
      ├─ Hanoi(1, B, C, A) → B→A
      ├─ B→C
      └─ Hanoi(1, A, B, C) → A→C
```

</div>

运行输出 (共 7 步): <span style="font-size:0.75em;font-family:Menlo,monospace;">A→C &nbsp; A→B &nbsp; C→B &nbsp; A→C &nbsp; B→A &nbsp; B→C &nbsp; A→C</span>

<a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (粘代码, 逐层看调用栈)</a>

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
<g id="h3"><rect x="-40" y="-11" width="80" height="22" rx="5" fill="#268bd2"/></g>
<g id="h2"><rect x="-30" y="-11" width="60" height="22" rx="5" fill="#b58900"/></g>
<g id="h1"><rect x="-20" y="-11" width="40" height="22" rx="5" fill="#dc322f"/></g>
</svg>
</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

<div id="hanoiMsg" style="font-weight:700;min-height:1.6em;">初始状态: 3 个盘都在 A</div>

<div id="hanoiStep" style="color:#586e75;margin-bottom:8px;">0 / 7</div>

<button onclick="hanoiNext()" style="display:block;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#268bd2;color:#fff;border:none;border-radius:8px;cursor:pointer;">▶ 下一步</button>

<button onclick="hanoiAuto()" style="display:block;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#859900;color:#fff;border:none;border-radius:8px;cursor:pointer;">▶▶ 自动播放 (7 步)</button>

<button onclick="hanoiReset()" style="display:block;margin:6px 0;padding:8px 18px;font-size:0.9em;background:#b58900;color:#fff;border:none;border-radius:8px;cursor:pointer;">⟲ 重来</button>

- 按 "下一步" 逐盘观察: 大盘==永远不压小盘==, 每步对应上一页调用树上的一次移动

- 第 4 步恰好是==最大盘就位==——和调用树对照着看

</div>

</div>

<script src="code/hanoi-anim.js"></script>

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
long fact(int n)
{
  return n * fact(n - 1);
}

int main(void)
{
  printf("%ld\n", fact(5));
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

- 即使有基准情形, ==极大的递归==也会爆: 递归深度以"层"计, 大输入要留意 (如对 10 万元素的链表递归打印)

- 应对: 递归三问缺一不可; 有些递归能改写成==循环==——循环不占栈, 深了也不怕 (这是"尾递归优化"的朴素版理解)

</div>

</div>

---

<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

1. 递归求和: sum(n) = 1 + 2 + … + n

2. 递归求幂: power(x, n) = x 的 n 次方

3. 递归打印整数: 输入 1234, 按位逐个打印 (样例: `1234 → 1 2 3 4`)

<span class="blue">:fa-lightbulb-o:</span> 提示: 先想清楚==递推关系==和==递归出口==, 再动手写

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>

---

<!-- slide data-notes="" -->##### 课堂案例 1: 递归求最大值

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 实现 `int max_rec(int a[], int n)`——最大值 = `a[n-1]` 与 "前 n-1 个的最大值" 里较大的那个 (与第 6 周"先假设再修正"同源)

样例: `a = {3, 9, 1, 7, 5}` → 输出 `9`

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/max-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 max-rec.c (只写函数体)</a>

---

<!-- slide data-notes="" -->##### 课堂案例 1: 递归求最大值 · 参考实现

---

<div style="font-size:0.85em;">

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

</div>

- 递归情形里==先信任== `max_rec(a, n-1)` 是对的, 再拿 `a[n-1]` 和它比——这就是"信任递归"

---

<!-- slide data-notes="" -->##### 课堂案例 2: 判断回文

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 实现 `int is_pal(char s[], int l, int r)`——两端字符相等, 且中间那一段也是回文 (回文用循环双指针更自然; 这题的价值是练习"把递归定义==直接翻译==成代码")

样例: `"level"` → 1, `"hello"` → 0

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/pal-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 pal-rec.c (只写函数体)</a>

---

<!-- slide data-notes="" -->##### 课堂案例 2: 判断回文 · 参考实现

---

<div style="font-size:0.85em;">

```C
int is_pal(char s[], int l, int r)
{
  if (l >= r) {                    /* 基准: 0 或 1 个字符 */
    return 1;
  }
  return s[l] == s[r] && is_pal(s, l + 1, r - 1);
}
```

</div>

- ==定义即代码==: 把"首尾相等且中间是回文"逐字翻译出来, 就是函数体

---

<!-- slide data-notes="" -->##### 课堂案例 3: 二分查找

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 实现 `int bin_search(int a[], int low, int high, int key)`——每次砍一半, 与分治同构 (有序数组是第 7 周的老朋友)

样例: 在 `{2, 5, 8, 12, 19}` 中找 8 → 下标 2; 找 7 → -1

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/bin-rec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 bin-rec.c (只写函数体)</a>

---

<!-- slide data-notes="" -->##### 课堂案例 3: 二分查找 · 参考实现

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

- 每次调用区间==必然缩小==——这保证递归一定终止; 下一页分治法正是这个思想的放大版

---

<!-- slide data-notes="" -->##### 课堂案例 4: 组合数

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 实现 `long comb(int m, int n)`——C(m,n) = C(m-1,n-1) + C(m-1,n); 对比 8-2 用 factorial 算组合数: 递归定义有时比公式==更直接==

样例: `comb(5, 2)` → 10

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c (只写函数体)</a>

---

<!-- slide data-notes="" -->##### 课堂案例 4: 组合数 · 参考实现

---

<div style="font-size:0.85em;">

```C
long comb(int m, int n)
{
  if (n == 0 || n == m) {          /* 基准情形 */
    return 1;
  }
  return comb(m - 1, n - 1) + comb(m - 1, n);
}
```

</div>

- 同一行里两个递归调用——先展开一层看: "选中第 m 个"与"不选第 m 个"两类, 加起来

---

<!-- slide data-notes="" -->##### 课堂案例 5: 爬楼梯

---

<div style="font-size:0.9em;line-height:1.6;">

==任务==: 实现 `int climb(int n)`——每次走 1 或 2 级, 最后一步从 n-1 或 n-2 上来 (Fibonacci 的亲戚)

样例: `climb(4)` → 5

</div>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/9-functions/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c (只写函数体)</a>

---

<!-- slide data-notes="" -->##### 课堂案例 5: 爬楼梯 · 参考实现

---

<div style="font-size:0.85em;">

```C
int climb(int n)
{
  if (n <= 1) {                    /* 基准情形 */
    return 1;
  }
  return climb(n - 1) + climb(n - 2);
}
```

</div>

- 生活问题→递归定义: 走到第 n 级的方法数 = 走到 n-1 的方法数 + 走到 n-2 的方法数

---


<!-- slide data-notes="" -->

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
<svg viewBox='0 0 400 210' style='max-width:100%;height:380px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='qk-blue' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker><marker id='qk-green' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><g font-size='9' fill='#586e75' text-anchor='end' font-weight='700'><text x='90' y='49'>原数组</text><text x='90' y='111'>划分后</text><text x='90' y='173'>最终</text></g><g font-size='11' text-anchor='middle' font-weight='700'><rect x='98' y='30' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='115' y='50' fill='#fdf6e3'>5</text><rect x='132' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='149' y='50' fill='#073642'>2</text><rect x='166' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='183' y='50' fill='#073642'>9</text><rect x='200' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='217' y='50' fill='#073642'>1</text><rect x='234' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='251' y='50' fill='#073642'>8</text><rect x='268' y='30' width='34' height='30' fill='#fdf6e3' stroke='#93a1a1'/><text x='285' y='50' fill='#073642'>3</text></g><path d='M200 60 V88' stroke='#268bd2' stroke-width='2' fill='none' marker-end='url(#qk-blue)'/><text x='208' y='76' font-size='9' fill='#268bd2'>① 划分</text><g font-weight='700'><rect x='98' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='115' y='112' font-size='11' fill='#073642' text-anchor='middle'>2</text><rect x='132' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='149' y='112' font-size='11' fill='#073642' text-anchor='middle'>1</text><rect x='166' y='92' width='34' height='30' fill='#dceaf5' stroke='#268bd2'/><text x='183' y='112' font-size='11' fill='#073642' text-anchor='middle'>3</text><rect x='200' y='92' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='217' y='112' font-size='11' fill='#fdf6e3' text-anchor='middle'>5</text><rect x='234' y='92' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='251' y='112' font-size='11' fill='#073642' text-anchor='middle'>9</text><rect x='268' y='92' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='285' y='112' font-size='11' fill='#073642' text-anchor='middle'>8</text></g><g fill='none' stroke-width='1.5'><path d='M98 90 V86 H200 V90' stroke='#268bd2'/><path d='M200 90 V86 H302 V90' stroke='#859900'/></g><text x='149' y='82' font-size='8.5' fill='#268bd2' text-anchor='middle'>左段（&lt;5）</text><text x='268' y='82' font-size='8.5' fill='#859900' text-anchor='middle'>右段（&gt;5）</text><path d='M200 122 V150' stroke='#859900' stroke-width='2' fill='none' marker-end='url(#qk-green)'/><text x='208' y='140' font-size='9' fill='#859900'>② 各自递归</text><g font-size='11' text-anchor='middle' font-weight='700'><rect x='98' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='115' y='174' fill='#073642'>1</text><rect x='132' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='149' y='174' fill='#073642'>2</text><rect x='166' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='183' y='174' fill='#073642'>3</text><rect x='200' y='154' width='34' height='30' fill='#b58900' stroke='#b58900'/><text x='217' y='174' fill='#fdf6e3'>5</text><rect x='234' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='251' y='174' fill='#073642'>8</text><rect x='268' y='154' width='34' height='30' fill='#fdf6e3' stroke='#859900'/><text x='285' y='174' fill='#073642'>9</text></g><text x='312' y='49' font-size='9' fill='#b58900' font-weight='700'>基准 = 5</text><text x='312' y='106' font-size='9' fill='#586e75'>5 已就位</text><text x='312' y='120' font-size='9' fill='#859900'>左右各自递归</text><text x='312' y='173' font-size='9' fill='#859900' font-weight='700'>无需合并</text><text x='98' y='202' font-size='9.5' fill='#586e75'>基准位置一次到位 → 左右两段递归即可，不需要合并</text></g></svg>
</div>

- ==① 划分==: 选基准 5, 小的放左、大的放右——5 的位置就此==一次到位==

- ==② 治==: 左段 [2, 1, 3] 和右段 [9, 8] 各自递归——同样先划分、再递归

- ==③ 合==: ==什么都不用做==——每次划分都把基准放到最终位置, 递归结束时整个数组就有序了

- 对比: "分成两半各自排好再合并"是另一种思路 (归并排序), 课下了解

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

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

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


