---
password: "cpl2026"
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../css/theme/solarized.css"
@import "../css/logo.css"
@import "../css/font.css"
@import "../css/color.css"
@import "../css/margin.css"
@import "../css/table.css"
@import "../css/main.css"
@import "../plugin/zoom/zoom.js"
@import "../plugin/customcontrols/plugin.js"
@import "../plugin/customcontrols/style.css"
@import "../plugin/chalkboard/plugin.js"
@import "../plugin/chalkboard/style.css"
@import "../plugin/menu/menu.js"
@import "../js/anychart/anychart-core.min.js"
@import "../js/anychart/anychart-venn.min.js"
@import "../js/anychart/pastel.min.js"
@import "../js/anychart/venn-ml.js"
@import "https://cdn.bootcdn.net/ajax/libs/jquery/3.5.0/jquery.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 指针基础 (下): 传址调用

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 反例: 传值 swap 为什么改不了实参

- 传址调用: 把地址传进函数

- scanf 与传址

- 多结果: max_min 与平均值

- const 与指针返回值

- 课堂任务与小测

---


<!-- slide data-notes="" -->##### 先看一个反例: swap 为什么没交换?

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.78em;">

<div class="col-label">代码</div>

```C
void swap_by_value(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main(void)
{
  int x = 1, y = 2;
  swap_by_value(x, y);
  printf("x=%d, y=%d\n", x, y);  /* 1 2 */
  return 0;
}
```

<div style="margin-top:10px;padding:8px 14px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;font-size:0.92em;">
运行结果: <code>x=1, y=2</code>——没有交换.
</div>

</div>

<div style="flex:1.05;">

<svg viewBox="0 0 460 250" style="max-width:620px;width:100%;height:auto;display:block;margin:0 auto;" role="img" aria-label="传值调用: 函数拿到的是 x 和 y 的副本">
  <defs>
    <marker id="copyArrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="6" markerHeight="6" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#93a1a1"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="230" y="20" font-size="15" fill="#586e75" text-anchor="middle">传值: 函数拿到的是副本</text>

    <rect x="60" y="40" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="72" y="58" font-size="14" fill="#b58900">int x</text>
    <text x="110" y="84" font-size="20" fill="#073642" text-anchor="middle">1</text>

    <rect x="180" y="40" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="192" y="58" font-size="14" fill="#b58900">int y</text>
    <text x="230" y="84" font-size="20" fill="#073642" text-anchor="middle">2</text>

    <line x1="110" y1="96" x2="110" y2="146" stroke="#93a1a1" stroke-width="1.6" stroke-dasharray="5 4" marker-end="url(#copyArrow)"/>
    <line x1="230" y1="96" x2="230" y2="146" stroke="#93a1a1" stroke-width="1.6" stroke-dasharray="5 4" marker-end="url(#copyArrow)"/>
    <text x="120" y="126" font-size="12" fill="#93a1a1">复制</text>
    <text x="240" y="126" font-size="12" fill="#93a1a1">复制</text>

    <rect x="60" y="150" width="100" height="56" rx="6" fill="#f2f4f0" stroke="#93a1a1" stroke-width="1.6" stroke-dasharray="5 3"/>
    <text x="72" y="168" font-size="14" fill="#586e75">int a</text>
    <text x="110" y="194" font-size="20" fill="#586e75" text-anchor="middle">1</text>

    <rect x="180" y="150" width="100" height="56" rx="6" fill="#f2f4f0" stroke="#93a1a1" stroke-width="1.6" stroke-dasharray="5 3"/>
    <text x="192" y="168" font-size="14" fill="#586e75">int b</text>
    <text x="230" y="194" font-size="20" fill="#586e75" text-anchor="middle">2</text>

    <text x="230" y="232" font-size="13" fill="#dc322f" text-anchor="middle">交换 a、b 只是交换副本; x、y 仍是 1、2</text>
  </g>
</svg>

</div>

</div>

<div style="margin-top:10px;padding:8px 14px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;font-size:0.8em;text-align:left;">
一句话: 函数收到的是==副本==; 改副本不影响调用者.
</div>

---


<!-- slide data-notes="" -->##### 传址调用: 把地址传进去

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.78em;">

<div class="col-label">代码</div>

```C
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int x = 1, y = 2;
  swap(&x, &y);
  printf("x=%d, y=%d\n", x, y);  /* 2 1 */
  return 0;
}
```

<div style="margin-top:10px;padding:8px 14px;background:#f2f4f0;border-left:4px solid #859900;border-radius:4px;font-size:0.92em;">
运行结果: <code>x=2, y=1</code>——交换成功.
</div>

</div>

<div style="flex:1.05;">

<svg viewBox="0 0 340 250" style="max-width:620px;width:100%;height:auto;display:block;margin:0 auto;" role="img" aria-label="传址调用: a 和 b 分别指向 x 和 y">
  <defs>
    <marker id="ptrUp" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="6" markerHeight="6" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#268bd2"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="170" y="20" font-size="15" fill="#586e75" text-anchor="middle">传址: a、b 里存的是 x、y 的地址</text>

    <rect x="60" y="40" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="72" y="58" font-size="14" fill="#b58900">int x</text>
    <text x="110" y="84" font-size="20" fill="#073642" text-anchor="middle">2</text>

    <rect x="180" y="40" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="192" y="58" font-size="14" fill="#b58900">int y</text>
    <text x="230" y="84" font-size="20" fill="#073642" text-anchor="middle">1</text>

    <rect x="60" y="150" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#268bd2" stroke-width="2"/>
    <text x="72" y="168" font-size="14" fill="#268bd2">int *a</text>
    <text x="110" y="194" font-size="15.5" fill="#268bd2" text-anchor="middle" font-family="Menlo, monospace">&amp;x</text>

    <rect x="180" y="150" width="100" height="56" rx="6" fill="#fdf6e3" stroke="#268bd2" stroke-width="2"/>
    <text x="192" y="168" font-size="14" fill="#268bd2">int *b</text>
    <text x="230" y="194" font-size="15.5" fill="#268bd2" text-anchor="middle" font-family="Menlo, monospace">&amp;y</text>

    <line x1="110" y1="150" x2="110" y2="100" stroke="#268bd2" stroke-width="2" stroke-dasharray="5 3" marker-end="url(#ptrUp)"/>
    <line x1="230" y1="150" x2="230" y2="100" stroke="#268bd2" stroke-width="2" stroke-dasharray="5 3" marker-end="url(#ptrUp)"/>
    <text x="120" y="130" font-size="12" fill="#268bd2">指向 x</text>
    <text x="240" y="130" font-size="12" fill="#268bd2">指向 y</text>

    <text x="170" y="232" font-size="13" fill="#073642" text-anchor="middle">交换 *a、*b 后: x=2, y=1</text>
  </g>
</svg>

</div>

</div>

<div style="margin-top:10px;padding:8px 14px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;font-size:0.8em;text-align:left;">
一句话: 参数是指针 → 函数拿到==地址==, 通过 <code>*a</code>、<code>*b</code> 改的就是 main 里的 <code>x</code>、<code>y</code>.
</div>

---


<!-- slide data-notes="" -->##### 任务 1: 用 swap 轮换三个数

---

<style>.task-criteria ul{padding-left:1.2em;margin:4px 0 0;}.task-criteria li p{margin:0;}</style>

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 输入三个整数 `x`、`y`、`z`, 用 `swap` 把它们轮换: `x` 变成原来的 `y`, `y` 变成原来的 `z`, `z` 变成原来的 `x`.

样例:

```text
输入: 1 2 3
输出: 2 3 1
```

==提示==:

- 用两次 `swap`: `swap(&x, &y); swap(&y, &z);`
- 每次交换后变量里已经是新值, 想清楚第二步交换的是哪两个

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 用两次 `swap` 完成轮换</div>
<div>· 输入 1 2 3, 输出 2 3 1</div>
<div>· 不直接写 `x=y; y=z; z=...` 的赋值</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-swap.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-swap.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### scanf 与传址

---

<style>.scanf-pre pre{margin:0.25rem 0 !important;}</style>

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="scanf-pre" style="flex:1.1;font-size:0.76em;">

<div class="col-label">代码</div>

```C
int i;
scanf("%d", &i);    /* 传 i 的地址 */
```

```C
int i, *p = &i;
scanf("%d", p);     /* p 里已经是地址 */
```

```C
scanf("%d", &p);    /* 错误: 传的是 p 的地址 */
```

</div>

<div style="flex:1;font-size:0.76em;line-height:1.45;">

`scanf` 的参数必须是指针: 它要把输入写到那个地址.

- `&i` 是 i 的地址 → 输入写进 i
- `p` 已经保存了 `&i` → 直接用 `p`
- `&p` 是 p 自己的地址, 类型也不对 → 输入写不进 i

<div style="margin-top:8px;padding:8px 12px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;font-size:0.92em;">
记住: 有 `&` 就传变量地址; 已经是指针就直接传指针.
</div>

</div>

</div>

<svg viewBox="0 0 400 180" width="600" height="270" style="display:block;flex-shrink:0;margin:0 auto;" xmlns="http://www.w3.org/2000/svg" font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<defs><marker id="arrScanB" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="6" markerHeight="6" orient="auto"><path d="M0,0 L10,5 L0,10 z" fill="#268bd2"/></marker><marker id="arrScanR" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="6" markerHeight="6" orient="auto"><path d="M0,0 L10,5 L0,10 z" fill="#dc322f"/></marker></defs>
<line x1="200" y1="8" x2="200" y2="172" stroke="#93a1a1" stroke-width="1" stroke-dasharray="4 4"/>
<text x="100" y="20" font-size="11.5" fill="#859900" text-anchor="middle">scanf("%d", p)</text>
<circle cx="158" cy="16" r="8" fill="#859900"/>
<path d="M154,16 l3,3 l6,-7" fill="none" stroke="#fdf6e3" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round"/>
<rect x="58" y="34" width="84" height="44" rx="7" fill="#fdf6e3" stroke="#268bd2" stroke-width="2"/>
<text x="68" y="48" font-size="10" fill="#268bd2">p</text>
<text x="100" y="64" font-size="15" fill="#268bd2" text-anchor="middle">2000</text>
<line x1="100" y1="80" x2="100" y2="100" stroke="#268bd2" stroke-width="2" marker-end="url(#arrScanB)"/>
<text x="96" y="94" font-size="8.5" fill="#268bd2" text-anchor="end">p 已保存 &amp;i</text>
<rect x="58" y="102" width="84" height="44" rx="7" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
<text x="68" y="116" font-size="10" fill="#b58900">i</text>
<text x="100" y="134" font-size="20" fill="#073642" text-anchor="middle">42</text>
<text x="100" y="166" font-size="10" fill="#859900" text-anchor="middle">scanf 通过 p 写入 i</text>
<text x="300" y="20" font-size="11.5" fill="#dc322f" text-anchor="middle">scanf("%d", &amp;p)</text>
<circle cx="360" cy="16" r="8" fill="#dc322f"/>
<path d="M356,12 l8,8 M364,12 l-8,8" stroke="#fdf6e3" stroke-width="1.8" stroke-linecap="round"/>
<rect x="258" y="34" width="84" height="44" rx="7" fill="#fdf6e3" stroke="#dc322f" stroke-width="2"/>
<text x="268" y="48" font-size="10" fill="#dc322f">p</text>
<text x="300" y="55" font-size="9" fill="#93a1a1" text-anchor="middle">2000</text>
<line x1="284" y1="55" x2="316" y2="55" stroke="#93a1a1" stroke-width="1.2"/>
<text x="300" y="72" font-size="15" fill="#dc322f" text-anchor="middle">42</text>
<text x="398" y="48" font-size="9" fill="#dc322f" text-anchor="end">输入 42</text>
<line x1="396" y1="52" x2="344" y2="52" stroke="#dc322f" stroke-width="1.4" marker-end="url(#arrScanR)"/>
<line x1="300" y1="80" x2="300" y2="100" stroke="#dc322f" stroke-width="1.6" stroke-dasharray="4 3"/>
<path d="M295,86 l10,10 M305,86 l-10,10" stroke="#dc322f" stroke-width="2" stroke-linecap="round"/>
<rect x="258" y="102" width="84" height="44" rx="7" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.6"/>
<text x="268" y="116" font-size="10" fill="#93a1a1">i</text>
<text x="300" y="130" font-size="16" fill="#93a1a1" text-anchor="middle">?</text>
<text x="300" y="141" font-size="8.5" fill="#93a1a1" text-anchor="middle">未被写入</text>
<text x="300" y="166" font-size="10" fill="#dc322f" text-anchor="middle">&amp;p 是 p 自己的地址</text>
</svg>

---


<!-- slide data-notes="" -->##### 任务 2: 读入两个整数并交换

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 用 `scanf` 读入两个整数, 输出交换前的值; 调用 `swap(&x, &y)` 后, 再输出交换后的值.

样例:

```text
输入: 3 8
交换前: x=3, y=8
交换后: x=8, y=3
```

==提示==:

- `scanf` 的参数要地址: `scanf("%d", &x)`
- `swap` 的参数也是地址: `swap(&x, &y)`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 用 `scanf("%d", &x)`、`scanf("%d", &y)` 读入</div>
<div>· 调用 `swap(&x, &y)`</div>
<div>· 输出交换前、交换后两行</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-scanf-swap.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-scanf-swap.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 3: 一次带回最大和最小

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 输入 10 个整数, 完成 `max_min`, 通过指针参数一次带回最大值和最小值.

样例:

```text
输入 10 个数: 3 8 1 9 2 7 4 6 5 0
最大: 9
最小: 0
```

==提示==:

- `return` 只能带回一个值, 两个结果要用指针参数带出
- 先假设 `a[0]` 既是最大也是最小, 再遍历更新 `*max`、`*min`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· `max_min` 通过 `*max`、`*min` 写回结果</div>
<div>· 输出最大 9、最小 0</div>
<div>· 不改变 `main` 的输入/输出结构</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/minmax.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 minmax.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 3 参考: max_min

---

<style>.maxmin-code pre code{max-height:none!important;font-size:14px;line-height:1.25;}</style>

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="maxmin-code" style="flex:1.4;font-size:0.5em;">

```C{.line-numbers}
#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min)
{
  *max = *min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > *max) *max = a[i];
    else if (a[i] < *min) *min = a[i];
  }
}

int main(void)
{
  int b[N], big, small;
  for (int i = 0; i < N; i++)
    scanf("%d", &b[i]);
  max_min(b, N, &big, &small);
  printf("最大: %d\n", big);
  printf("最小: %d\n", small);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.7em;line-height:1.6;">

- `max_min(b, N, &big, &small)`——把 `big`、`small` 的==地址==传给函数, 函数通过指针把结果写回去
- `*max = *min = a[0]` 先假设, 遍历中更大/更小就更新
- 指针参数让函数一次"带回"两个值, 这是 `return` 单值限制的经典解法

<div style="margin-top:8px;padding:8px 12px;background:#f2f4f0;border-left:4px solid #859900;border-radius:4px;font-size:0.92em;">
`*max` 就是 main 里的 `big`, `*min` 就是 `small`.
</div>

</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 4: 再带回一个平均值

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 在 `max_min` 基础上增加 `double *avg` 参数, 一次带回最大、最小和平均值.

样例:

```text
输入 10 个数: 3 8 1 9 2 7 4 6 5 0
最大: 9
最小: 0
平均: 4.90
```

==提示==:

- 遍历时同时累加求和
- `*avg = (double)sum / n`——注意用浮点除法, 不要写成 `sum / n`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 签名增加 `double *avg`; 最大值、最小值仍用指针带回</div>
<div>· 平均值用浮点除法, 输出 `4.90`</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-minmax-avg.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-minmax-avg.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 使用 const 保护参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.78em;">

<div class="col-label">三种写法</div>

```C
void f(const int *p)
{
  *p = 0;   /* 错误: *p 只读 */
  p = &x;   /* 合法: p 可以改指向 */
}
```

```C
void f(int * const p)
{
  *p = 0;   /* 合法: *p 可以改 */
  p = &x;   /* 错误: p 只读 */
}
```

```C
void f(const int * const p)
{
  *p = 0;   /* 错误 */
  p = &x;   /* 错误 */
}
```

</div>

<div style="flex:1;font-size:0.78em;line-height:1.55;">

- `const int *p`: 锁 `*p`——不能通过 p 修改对象; p 可以改指向
- `int * const p`: 锁 `p`——p 不能改指向; `*p` 可以修改
- `const int * const p`: 两个都锁

<div style="margin-top:8px;padding:8px 12px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;font-size:0.92em;">
读法: `const` 在 `*` 左边锁值, 在 `*` 右边锁指针.
</div>

函数参数常用 `const int *a`: 表示函数只读数组, 不会修改它. 当参数是很大的结构/数组时, 传地址能省拷贝, `const` 又能保证"只看不改".

</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 5: 写一个只读的求和函数

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 完成 `int sum(const int *a, int n)`, 返回数组元素之和; 函数内部不能修改数组.

样例:

```text
{1, 2, 3, 4, 5} → sum = 15
```

==提示==:

- `const int *a` 表示"通过 a 不能修改 a[i]"
- 写完可以试着加一句 `a[i] = 0;`, 看编译器报什么错, 再注释掉

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 参数保持 `const int *a`</div>
<div>· 返回数组元素之和 15</div>
<div>· 函数内不修改数组</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-const-sum.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-const-sum.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 指针作为返回值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.76em;">

<div class="col-label">返回指针</div>

```C
int *max(int *a, int *b)
{
  if (*a > *b)
    return a;
  else
    return b;
}

int i = 1, j = 2;
int *p = max(&i, &j);  /* p 指向 j */
```

```C
int *find_middle(int a[], int n)
{
  return &a[n / 2];
}
```

</div>

<div style="flex:1;font-size:0.76em;line-height:1.55;">

- 函数可以返回指针: `p = max(&i, &j)` 后, p 指向 i 或 j
- 指针可以指向数组元素: `&a[i]` 是元素 i 的地址; `find_middle` 返回中间元素的指针
- 返回的指针必须指向==仍然存在==的对象: 参数、数组元素、全局/静态变量

<div style="margin-top:8px;padding:8px 12px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;font-size:0.82em;line-height:1.5;">
不要返回局部变量的地址:
<div style="margin-top:6px;font-family:Menlo,monospace;font-size:0.85em;color:#586e75;white-space:nowrap;">int *f(void) { int i; return &i; }  /* 错误 */</div>
函数返回后 i 就不存在了, 这个指针是悬空的.
</div>

</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 6: 返回指向最后一个最大元素的指针

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 完成 `int *last_max(int *a, int n)`, 返回指向==最后一个==最大元素的指针.

样例:

```text
数组: 3 8 1 9 2 7 4 6 9 0
最后一个最大值: 9 (下标 8)
```

==提示==:

- 用指针遍历: `for (int *p = a; p < a + n; p++)`
- 用 `>=` 更新当前最大值, 这样保留最后一个
- 返回指针, 不要返回值

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 返回 `int *`, 用 `>=` 保留最后一个最大值</div>
<div>· 输出 `9 (下标 8)`</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-last-max.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-last-max.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 概念: 为什么 `swap(int a, int b)` 改不了实参？传址版要改哪两处？

2. 概念: `scanf("%d", p)` 与 `scanf("%d", &p)` 有什么区别？

3. 代码阅读: `void f(int x, int *p) { x = 10; *p = 20; }`，执行 `int a = 1, b = 2; f(a, &b); printf("%d %d", a, b);` 输出什么？

4. 概念: `const int *p` 与 `int * const p` 的区别是什么？

5. 纠错: `int *f(void) { int i = 1; return &i; }` 错在哪里？应该怎么改？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
