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

- 常见错误与课堂编码

- 分治与快速排序 (弹性)

- 课堂小测

---
<!-- slide data-notes="" -->

##### 递归是什么

---

==递归==: 函数直接或间接地==自己调用自己==——有些问题的定义本身就是递归的: 阶乘、汉诺塔、目录遍历……

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
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

<div style="flex:1;font-size:1.0em;line-height:1.6;">

- ==两个要素==: ==基准情形== (最简单、直接给答案) + ==递归情形== (把问题==缩小==后再调用自己)

- ==信任递归==: 写第 n 层时只关心两层——假设 n-1 层的答案是对的, 用它构造 n 的答案, ==不要在脑中展开所有层==

- ==递归三问==: 最小问题是什么? 怎么缩小? 怎么用缩小后的答案构造当前答案?

</div>

</div>

---

<!-- slide data-notes="" -->

##### 递归执行过程

---

fact(3) 的跟踪——==递推==下去, 再==回归==上来:

<div style="text-align:center;margin:2px 0;">
<svg viewBox='0 0 400 200' style='max-width:100%;height:180px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='fact-down' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker><marker id='fact-up' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><g font-weight='700'><rect x='48' y='8' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='25' font-size='14' fill='#073642' text-anchor='middle'>fact(3)</text><text x='123' y='39' font-size='10' fill='#586e75' text-anchor='middle'>n = 3 → 3 × fact(2)</text><rect x='48' y='76' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='123' y='93' font-size='14' fill='#073642' text-anchor='middle'>fact(2)</text><text x='123' y='107' font-size='10' fill='#586e75' text-anchor='middle'>n = 2 → 2 × fact(1)</text><rect x='48' y='144' width='150' height='38' rx='8' fill='#fdf6e3' stroke='#859900' stroke-width='3'/><text x='123' y='161' font-size='14' fill='#073642' text-anchor='middle'>fact(1)</text><text x='123' y='175' font-size='10' fill='#586e75' text-anchor='middle'>n = 1，命中基准 → return 1</text></g><path d='M123 46 V72' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><path d='M123 114 V140' stroke='#268bd2' stroke-width='2.5' fill='none' marker-end='url(#fact-down)'/><text x='133' y='63' font-size='9' fill='#268bd2'>递推（压栈）</text><text x='133' y='131' font-size='9' fill='#268bd2'>递推（压栈）</text><path d='M300 184 V20' stroke='#859900' stroke-width='2.5' fill='none' marker-end='url(#fact-up)'/><text x='310' y='12' font-size='9' fill='#859900' font-weight='700'>回归（弹栈）</text><text x='310' y='38' font-size='9' fill='#859900'>返回 3 × 2 = 6</text><text x='310' y='106' font-size='9' fill='#859900'>返回 2 × 1 = 2</text><text x='310' y='176' font-size='9' fill='#859900'>返回 1</text><text x='48' y='196' font-size='9' fill='#586e75'>蓝色：递推（压栈）　绿色：回归（弹栈）</text></g></svg>
</div>

- 每一层调用压一张==便签== (昨天的栈), 回归时逐层弹栈==结算==——递归就是便签一层层叠高、再一层层揭掉

- 每层调用有==自己的一套局部变量和参数==, 各层互不干扰 (下一页: 生命期)

- 递归深度 = 压栈层数; 递归过深 → ==栈溢出==

动画: [function-and-stack.html](function-and-stack.html) —— 阶乘递归的层层压栈与返回

<a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (逐行看栈帧)</a>

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
<svg viewBox='0 0 400 200' style='max-width:100%;height:230px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='scope-red' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#dc322f'/></marker><marker id='scope-green' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#859900'/></marker></defs><rect x='14' y='14' width='372' height='172' rx='10' fill='#fdf6e3' stroke='#93a1a1' stroke-width='2' stroke-dasharray='6 4'/><text x='28' y='34' font-size='10' fill='#586e75' font-weight='700'>文件作用域（整个 .c 文件）</text><rect x='28' y='44' width='150' height='32' rx='6' fill='#eee8d5' stroke='#b58900' stroke-width='2'/><text x='103' y='65' font-size='11' fill='#073642' text-anchor='middle' font-weight='700'>int x = 0;（全局）</text><rect x='50' y='88' width='300' height='86' rx='8' fill='#dceaf5' stroke='#268bd2' stroke-width='2.5'/><text x='205' y='108' font-size='9.5' fill='#268bd2' text-anchor='middle' font-weight='700'>f 的函数体（块作用域）</text><rect x='65' y='116' width='150' height='32' rx='6' fill='#fdf6e3' stroke='#dc322f' stroke-width='2.5'/><text x='140' y='137' font-size='11' fill='#073642' text-anchor='middle' font-weight='700'>int x = 1;（局部）</text><rect x='240' y='116' width='95' height='32' rx='6' fill='#fdf6e3' stroke='#859900' stroke-width='2'/><text x='287' y='137' font-size='11' fill='#073642' text-anchor='middle' font-weight='700'>printf → 1</text><path d='M100 116 V80' stroke='#dc322f' stroke-width='2' stroke-dasharray='5 3' fill='none' marker-end='url(#scope-red)'/><text x='108' y='100' font-size='9' fill='#dc322f'>遮蔽全局 x</text><path d='M215 132 H236' stroke='#859900' stroke-width='2' fill='none' marker-end='url(#scope-green)'/><text x='28' y='198' font-size='9.5' fill='#586e75'>全局变量整个文件可见；局部变量出了函数就不可见</text></g></svg>
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

---


<!-- slide data-notes="" -->


##### 演示: 局部变量的"垃圾值"

---

<div style="font-size:0.8em;">

```C
void f(void) {
    int i;                    /* 没有初始化 */
    printf("i = %d\n", i);
}
int main(void) { f(); return 0; }
```

</div>

一次运行的结果 (每次可能不同!): 

```
i = 32764
```

- 动态局部变量诞生时==不会自动清零==——里面是内存里残留的"垃圾值"

- 每次运行、每台机器都可能不同; 调试器里恰好是 `0` 只是假象

- 教训: ==局部变量必须初始化后再使用==; 编译加 `-Wall` 有时能提示 "used uninitialized"

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
    printf("%c -> %c\n", A, C);
  }
  else {
    Hanoi(n - 1, A, C, B);
    printf("%c -> %c\n", A, C);
    Hanoi(n - 1, B, A, C);
  }
}
```

</div>

<div style="flex:1;">

3 根柱 A、B、C, 把 n 个盘子从 A 移到 C (大盘不能压小盘, 可借 B):

- n=1: 直接 A → C

- n>1: 先把上面 n-1 个 A → B (借 C), 再把最大盘 A → C, 最后 n-1 个 B → C (借 A)

64 个盘子需 2^64 - 1 步——"把问题交给递归"的威力

</div>

</div>

<!-- slide data-notes="" -->


##### 常见错误

---

- ==缺少基准情形==: 递归永不终止 (如忘了 n==0 的判断)

- ==问题没有缩小==: 每次调用与上次规模相同 (如 f(n) 里调用 f(n))

<span class="blue">:fa-lightbulb-o:</span> 写递归的两步检查: ① 基准情形对吗? ② 每次调用规模在变小吗?

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


