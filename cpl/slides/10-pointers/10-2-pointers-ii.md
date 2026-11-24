---
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


<!-- slide data-notes="" -->##### 回顾 W8: swap 为什么没交换?

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.86em;line-height:1.6;">

<div class="col-label">W8 的传值版</div>

```C
void swap(int a, int b);   /* 交换的是副本 */
...
swap(x, y);                /* x、y 仍然是 3、5 */
```

<div style="margin-top:8px;padding:8px 12px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;">
形参 `a`、`b` 是副本; 函数返回, 副本销毁, main 的 x、y 不受影响.
</div>

</div>

<div style="flex:1.05;font-size:0.86em;line-height:1.6;">

<div class="col-label">W8 末尾预告的传址版</div>

```C
void swap(int *a, int *b);
swap(&x, &y);              /* 这次 x、y 真的交换 */
```

<div style="margin-top:8px;padding:8px 12px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
问题: 为什么 `&x`、`&y` 能改到 main 的变量? 这一页把"地址"讲清楚.
</div>

</div>

</div>

<div style="display:flex;gap:12px;margin-top:18px;font-size:0.9em;line-height:1.45;">

<div style="flex:1;padding:8px 12px;background:#f2f4f0;border-left:4px solid #268bd2;border-radius:4px;">
<b>① 地址</b><br>`&x` 到底是什么?
</div>

<div style="flex:1;padding:8px 12px;background:#f2f4f0;border-left:4px solid #b58900;border-radius:4px;">
<b>② 指针</b><br>`int *a` 里存什么?
</div>

<div style="flex:1;padding:8px 12px;background:#f2f4f0;border-left:4px solid #859900;border-radius:4px;">
<b>③ 解引用</b><br>`*a` 怎么改 x?
</div>

</div>

---

<!-- slide data-notes="" -->##### 传址调用: 把地址传进去

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="swapdemo-code" style="flex:1.05;font-size:0.72em;">

<style>.swapdemo-code pre code{max-height:none!important;font-size:13.5px;line-height:1.03;}</style>

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
  int *p = &x, *q = &y;

  swap(&x, &y);          /* 直接传地址 */
  printf("swap(&x,&y): x=%d, y=%d\n", x, y);

  x = 1; y = 2;          /* 重置 */
  swap(p, q);            /* p、q 里就是 &x、&y */
  printf("swap(p,q):   x=%d, y=%d\n", x, y);
  return 0;
}
```

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #859900;border-radius:4px;font-size:0.82em;">
运行结果:<br>
<code>swap(&x,&y) → x=2, y=1</code><br>
<code>swap(p,q)&nbsp;&nbsp; → x=2, y=1</code>
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

<div style="margin-top:6px;text-align:center;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/swap-demo.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 swap-demo.c</a>
</div>

</div>

</div>

<div style="margin-top:10px;padding:8px 14px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;font-size:0.8em;text-align:left;">
一句话: `swap(&x, &y)` 与 `swap(p, q)` 等价: p、q 里存的就是 `&x`、`&y`.
</div>

---


<!-- slide data-notes="" -->##### 任务 1: 拆分时间

---

<style>.task-criteria ul{padding-left:1.2em;margin:4px 0 0;}.task-criteria li p{margin:0;}</style>

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 读入总秒数 `total`, 完成 `split_time`, 把时、分、秒通过指针参数带回.

样例:

```text
输入: 3661
输出: 1 1 1
```

==提示==:

- 1 小时 = 3600 秒, 1 分钟 = 60 秒
- 三个结果都通过指针写回: `*h`、`*m`、`*s`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 函数用 `int *h, *m, *s` 三个指针输出</div>
<div>· 通过 `*h`、`*m`、`*s` 写回</div>
<div>· 输入 3661, 输出 1 1 1</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-split-time.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-split-time.c (骨架)</a>
</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 1 参考: 拆分时间

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="split-code" style="flex:1.1;font-size:0.66em;">

<style>.split-code pre code{max-height:none!important;font-size:16px;line-height:1.1;}</style>

<div class="col-label">参考实现 · split-time.c</div>

```C{.line-numbers}
#include <stdio.h>

void split_time(int total, int *h, int *m, int *s)
{
    *h = total / 3600;
    *m = total % 3600 / 60;
    *s = total % 60;
}

int main(void)
{
    int total, h, m, s;

    scanf("%d", &total);
    split_time(total, &h, &m, &s);
    printf("%d %d %d\n", h, m, s);

    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/split-time.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 split-time.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.5;">

<div class="col-label">运行结果</div>

```text
输入: 3661
输出: 1 1 1
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `total / 3600` → 小时
- `total % 3600 / 60` → 分钟
- `total % 60` → 秒
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
三个结果由 `*h`、`*m`、`*s` 写回; 函数不需要 `return` 多个值.
</div>

</div>

</div>

---

<!-- slide data-notes="" -->##### scanf 与传址: 完整例子

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="scanf-code" style="flex:1.1;font-size:0.62em;">

<style>.scanf-code pre code{max-height:none!important;font-size:15px;line-height:1.15;}</style>

<div class="col-label">完整代码 · scanf-demo.c</div>

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
    int i = 0;
    int *p = &i;

    printf("输入一个整数: ");
    scanf("%d", &i);          /* 方式 1: 传 i 的地址 */
    printf("i = %d, *p = %d\n", i, *p);

    printf("再输入一个整数: ");
    scanf("%d", p);           /* 方式 2: p 里已经是 &i */
    printf("i = %d, *p = %d\n", i, *p);

    /* scanf("%d", &p);  // 错误: &p 是 int ** */
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/scanf-demo.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 scanf-demo.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.72em;line-height:1.45;">

<div class="col-label">样例运行</div>

```text
输入一个整数: 42
i = 42, *p = 42
再输入一个整数: 7
i = 7, *p = 7
```

<div style="margin-top:8px;display:flex;flex-direction:column;gap:6px;font-size:0.9em;">

<div style="padding:6px 10px;background:#eef4e6;border-left:4px solid #859900;border-radius:4px;">
✓ <code>scanf("%d", &amp;i)</code> — 传 i 的地址
</div>

<div style="padding:6px 10px;background:#eef4e6;border-left:4px solid #859900;border-radius:4px;">
✓ <code>scanf("%d", p)</code> — p 里已经是 &amp;i
</div>

<div style="padding:6px 10px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;">
✗ <code>scanf("%d", &amp;p)</code> — &amp;p 是 p 自己的地址 (int **), 输入写不进 i
</div>

</div>

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;font-size:0.9em;">
记住: 有 `&` 就传变量地址; 已经是指针就直接传指针.
</div>

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 交换数组的首尾元素

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 读入 5 个整数存入数组 `a[5]`, 用 `swap` 交换 `a[0]` 与 `a[4]`, 输出交换后的数组.

样例:

```text
输入: 1 2 3 4 5
输出: 5 2 3 4 1
```

==提示==:

- 数组元素也是变量, 传地址用 `&a[i]`
- 交换首尾: `swap(&a[0], &a[4])`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 输入存入数组 `a[5]`</div>
<div>· 调用 `swap(&a[0], &a[4])`</div>
<div>· 输出 `5 2 3 4 1`</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-array-swap.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-array-swap.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 2 参考: 交换数组首尾元素

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="arrayswap-code" style="flex:1.1;font-size:0.66em;">

<style>.arrayswap-code pre code{max-height:none!important;font-size:15px;line-height:1.1;}</style>

<div class="col-label">参考实现 · array-swap.c</div>

```C{.line-numbers}
#include <stdio.h>

#define N 5

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int a[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    swap(&a[0], &a[N - 1]);

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/array-swap.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 array-swap.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.5;">

<div class="col-label">运行结果</div>

```text
输入: 1 2 3 4 5
输出: 5 2 3 4 1
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `&a[0]`、`&a[N-1]` 把首尾元素的==地址==传进 `swap`
- 函数内 `*a`、`*b` 直接改原数组元素
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
数组元素本身是变量; 传地址后, 函数里的修改会写回 main 的数组.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 任务 3: 一次带回最大、最小和平均值

---

<div style="font-size:0.68em;line-height:1.36;text-align:left;">

==任务==: 先把输入的 10 个整数存入数组 `a[10]`, 再完成 `max_min(a, 10, &max, &min, &avg)`: 函数一次遍历, 通过指针参数带回最大值、最小值和平均值.

样例:

```text
输入 10 个数: 3 8 1 9 2 7 4 6 5 0
最大: 9
最小: 0
平均: 4.50
```

<div style="display:flex;align-items:flex-start;gap:24px;margin-top:4px;">

<div style="flex:1.05;">

==提示==:

- `max_min(a, n, ...)`: 第一个参数是数组, 第二个是元素个数
- `return` 只能带回一个值; 最大/最小/平均用 `*max`、`*min`、`*avg` 带回
- 先假设 `a[0]` 是最值; 遍历时同时累加 `sum`, 最后 `*avg = (double)sum / n`

</div>

<div style="flex:0.95;">

<div class="task-criteria" style="margin:0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 签名包含 `double *avg`; 只遍历一次</div>
<div>· 通过 `*max`、`*min`、`*avg` 写回三个结果</div>
<div>· 平均值用浮点除法, 输出 `4.50`</div>
</div>

<div style="margin:10px 0 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-minmax-avg.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-minmax-avg.c (骨架)</a>
</div>

</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 任务 3 参考: 一次带回最大、最小和平均值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="minmaxavg-code" style="flex:1.1;font-size:0.6em;">

<style>.minmaxavg-code pre code{max-height:none!important;font-size:14.5px;line-height:1.12;}</style>

<div class="col-label">参考实现 · minmax-avg.c</div>

```C{.line-numbers}
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min, double *avg)
{
    int sum = a[0];
    *max = *min = a[0];
    for (int i = 1; i < n; i++) {
        sum += a[i];
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
    *avg = (double)sum / n;
}

int main(void)
{
    int b[N], big, small;
    double avg;

    printf("输入 %d 个数: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    max_min(b, N, &big, &small, &avg);
    printf("最大: %d\n", big);      /* 9 */
    printf("最小: %d\n", small);    /* 0 */
    printf("平均: %.2f\n", avg);    /* 4.50 */
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/minmax-avg.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 minmax-avg.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.5;">

<div class="col-label">运行结果</div>

```text
输入 10 个数: 3 8 1 9 2 7 4 6 5 0
最大: 9
最小: 0
平均: 4.50
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `max_min(b, N, &big, &small, &avg)` 一次带回三个结果
- 遍历时同时累加 `sum`, 最大值/最小值用 `*max`、`*min` 更新
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
`*avg = (double)sum / n` 必须用浮点除法, 否则 `sum / n` 会截断为整数.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 为什么用 const: 保护只读参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.78em;line-height:1.55;text-align:left;">

==问题==: 函数参数写成 `int *a` 时, 函数内部可以修改调用者的数组; 如果函数只负责读取, 这种修改往往是 bug.

`const` 把“只读”写进参数类型: 函数内若尝试修改, 编译器直接报错.

==常见用法==: 只读数组参数

```C
void print_array(const int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
```

</div>

<div style="flex:0.95;font-size:0.78em;line-height:1.55;text-align:left;">

==两种写法==

<table style="width:100%;margin-top:4px;font-size:0.95em;border-collapse:collapse;">
<tr style="color:#586e75;">
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">写法</th>
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">改所指内容</th>
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">改指针指向</th>
</tr>
<tr><td style="padding:3px 6px;"><code>const int *p</code></td><td style="padding:3px 6px;color:#dc322f;">✗ 编译错误</td><td style="padding:3px 6px;color:#859900;">✓ 合法</td></tr>
<tr><td style="padding:3px 6px;"><code>int * const q</code></td><td style="padding:3px 6px;color:#859900;">✓ 合法</td><td style="padding:3px 6px;color:#dc322f;">✗ 编译错误</td></tr>
<tr><td style="padding:3px 6px;"><code>const int * const r</code></td><td style="padding:3px 6px;color:#dc322f;">✗</td><td style="padding:3px 6px;color:#dc322f;">✗</td></tr>
</table>

<div style="margin-top:6px;font-size:0.95em;">
<code>const int *p</code> 与 <code>int const *p</code> 完全等价; 本课统一写 <code>const int *</code>.
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
读法: <code>const</code> 在 <code>*</code> 左边锁值, 在 <code>*</code> 右边锁指针.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 使用 const 保护参数: 两种常见写法

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="const-code" style="flex:1.1;font-size:0.58em;">

<style>.const-code pre code{max-height:none!important;font-size:13.5px;line-height:1.05;}</style>

<div class="col-label">完整代码 · const-demo.c</div>

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
    int i = 1, j = 2;

    const int *p = &i;        /* *p 只读; p 可以改指向 */
    printf("*p = %d\n", *p);  /* 1 */
    p = &j;                   /* 合法: 改 p 的指向 */
    printf("*p = %d\n", *p);  /* 2 */

    int * const q = &i;       /* q 只读; *q 可以改 */
    *q = 4;                   /* 合法: 改 i */
    printf("i = %d, *q = %d\n", i, *q);  /* 4 4 */

    /* 下面两句通不过编译:
       *p = 3;   // *p 只读
       q = &j;   // q 只读 */
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/const-demo.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 const-demo.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.70em;line-height:1.4;">

<div class="col-label">运行结果</div>

```text
*p = 1
*p = 2
i = 4, *q = 4
```

<table style="width:100%;margin-top:8px;font-size:0.9em;border-collapse:collapse;">
<tr style="color:#586e75;">
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">写法</th>
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">改所指内容</th>
<th style="text-align:left;padding:3px 6px;border-bottom:1px solid #d6d6c8;">改指针指向</th>
</tr>
<tr><td style="padding:3px 6px;"><code>const int *</code></td><td style="padding:3px 6px;color:#dc322f;">✗ 编译错误</td><td style="padding:3px 6px;color:#859900;">✓ 合法</td></tr>
<tr><td style="padding:3px 6px;"><code>int * const</code></td><td style="padding:3px 6px;color:#859900;">✓ 合法</td><td style="padding:3px 6px;color:#dc322f;">✗ 编译错误</td></tr>
<tr><td style="padding:3px 6px;"><code>const int * const</code></td><td style="padding:3px 6px;color:#dc322f;">✗</td><td style="padding:3px 6px;color:#dc322f;">✗</td></tr>
</table>

<div style="margin-top:8px;padding:6px 10px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;font-size:0.9em;">
<b>编译器的实际报错:</b><br>
<code>*p = 3;</code> → read-only variable is not assignable<br>
<code>q = &amp;j;</code> → cannot assign to variable 'q' with const-qualified type 'int *const'
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;font-size:0.9em;">
读法: <code>const</code> 在 <code>*</code> 左边锁值, 在 <code>*</code> 右边锁指针.
</div>

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 4: 只读求和

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 完成 `sum(const int *a, int n)`, 返回数组元素之和; 再试着在循环体里写 `a[i] = 0;`, 观察编译器的报错.

样例:

```text
数组: 1 2 3 4 5
sum = 15
```

==提示==:

- 用循环遍历数组并累加
- `const int *a` 表示不能通过 a 修改数组元素
- 补完循环后, 在循环体里写 `a[i] = 0;`, 编译器会报 `read-only variable is not assignable`

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 参数用 `const int *`; 返回 15</div>
<div>· 函数内不修改数组</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-const-sum.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-const-sum.c (骨架)</a>
</div>

</div>

---
<!-- slide data-notes="" -->##### 任务 4 参考: 只读求和

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="constsum-code" style="flex:1.1;font-size:0.6em;">

<style>.constsum-code pre code{max-height:none!important;font-size:14.5px;line-height:1.12;}</style>

<div class="col-label">参考实现 · const-sum.c</div>

```C{.line-numbers}
#include <stdio.h>

int sum(const int *a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        /* a[i] = 0;  // 错误: a[i] 只读 */
    }
    return s;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    printf("sum = %d\n", sum(a, 5));  /* 15 */
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/const-sum.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 const-sum.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.75em;line-height:1.45;">

<div class="col-label">运行结果</div>

```text
sum = 15
```

<div style="margin-top:8px;padding:6px 10px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;">
<b>试试:</b> 取消注释 <code>a[i] = 0;</code><br>
编译器报错: <code>read-only variable is not assignable</code>
</div>

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
`const int *a` 表示通过 a 不能修改数组元素; 函数只读, 不会改调用者的数组.
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
完成标准: 参数用 `const int *`; 返回 15; 函数内不修改数组.
</div>

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


<!-- slide data-notes="" -->##### 任务 5: 返回指向最后一个最大元素的指针

---

<div style="font-size:0.70em;line-height:1.38;text-align:left;">

==任务==: 完成 `int *last_max(int *a, int n)`, 返回指向==最后一个==最大元素的指针.

样例:

```text
数组: 3 8 1 9 2 7 4 6 9 0
最后一个最大值: 9
```

==提示==:

- 用下标遍历: `for (int i = 1; i < n; i++)`
- 用 `a[i] >= a[best]` 更新当前最大值下标, 这样保留最后一个
- 返回 `&a[best]`, 不要返回值

<div class="task-criteria" style="margin:8px 2rem 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 返回 `int *`, 用 `>=` 保留最后一个最大值下标</div>
<div>· 输出 `9`</div>
</div>

<div style="margin:10px 2rem 0;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/task-last-max.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-last-max.c (骨架)</a>
</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 5 参考: 返回指向最后一个最大元素的指针

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="lastmax-code" style="flex:1.1;font-size:0.62em;">

<style>.lastmax-code pre code{max-height:none!important;font-size:14.5px;line-height:1.12;}</style>

<div class="col-label">参考实现 · last-max.c</div>

```C{.line-numbers}
#include <stdio.h>

#define N 10

int *last_max(int *a, int n)
{
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[best])
            best = i;
    }
    return &a[best];
}

int main(void)
{
    int a[N] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
    int *p = last_max(a, N);

    printf("最后一个最大值: %d\n", *p);
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/10-pointers/code/last-max.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 last-max.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.5;">

<div class="col-label">运行结果</div>

```text
数组: 3 8 1 9 2 7 4 6 9 0
最后一个最大值: 9
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `best` 记录当前最大元素的下标
- 用 `a[i] >= a[best]` 比较, 遇到相同的最大值继续更新下标, 保留最后一个
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
返回 `&a[best]`; 指针指向数组元素, 数组仍然存在. main 通过 `*p` 读取值, 不使用指针算术.
</div>

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
