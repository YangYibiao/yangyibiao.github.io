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
<style>.reveal pre code{max-height:none!important;overflow:visible!important}.small-code pre{font-size:1em!important}.left-justify p,.left-justify li{text-align:left!important}</style>

# 智能程序设计（C语言）

<hr class="width50 center">

## 指针数组与函数指针

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 指向指针的指针

- 指针数组与带参数的 main

- 函数指针与 qsort

- 指针声明怎么读 (复杂声明的解读小结)


<!-- slide data-notes="" -->


##### 指向指针的指针

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
void skip_spaces(char *p)
{
  while (*p == ' ')
    p++;
  printf("%s\n", p);
}

int main(void)
{
  char str[] = "   hello";
  char *p = str;

  skip_spaces(p);
  printf("%s\n", p);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.6em;">

函数参数按值传递. 调用 `skip_spaces(p)` 时, p 的值被复制给形参.

函数内的 `p` 是副本, 在函数里移动它, 调用者的 `p` 不受影响.

程序输出: 第一行是 `hello`, 第二行开头仍有三个空格, 后接 `hello`.

如果希望函数修改指针变量本身 (让它指向别处), 需要把指针的地址传进去.

这样做需要使用指向指针的指针.

</div>

</div>

<!-- slide data-notes="" -->

##### 指向指针的指针 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
void skip_spaces(char **p)
{
  while (**p == ' ')
    (*p)++;
}

int main(void)
{
  char str[] = "   hello";
  char *p = str;

  skip_spaces(&p);
  printf("%s\n", p);   /* hello */
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.6em;">

`char **p` 表示 p 指向一个 `char *` 变量.

实参是 `&p`, 类型为 `char **`; 形参 `p` 保存调用者指针变量的地址.

`*p` 就是调用者的 `p`; `(*p)++` 让它指向下一个字符.

因此函数返回后, 调用者的 `p` 已经指向 `hello` 的首字符.

括号不能省略: `*p++` 等价于 `*(p++)`, 移动的是形参 p 本身, 而不是调用者的指针.

</div>

</div>

<!-- slide data-notes="" -->


##### 命令行参数: 带参数的 main

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```
ls
ls -l
ls -l remind.c
```

```C
int main(int argc, char *argv[])
{
  …
}
```

</div>

<div style="flex:1;font-size:0.6em;">

运行程序时, 经常需要提供一些信息.

这可能包括文件名或修改程序行为的开关.

UNIX `ls` 命令的示例:

命令行信息对所有程序都是可用的, 不仅仅是操作系统命令.

要用==命令行参数==, main 必须带两个参数:

命令行参数在 C 标准中称为 ==程序参数==.

</div>

</div>

<!-- slide data-notes="" -->

##### 命令行参数: 带参数的 main (续)

---

`argc` 与 `argv` 的含义:

| 表达式 | 含义 |
| ---- | ---- |
| `argc` | 命令行参数的数量 (含程序名) |
| `argv[0]` | 程序名 |
| `argv[1]` … `argv[argc-1]` | 其余命令行参数 |
| `argv[argc]` | 空指针 NULL |

以 `./demo names.dat dates.dat` 为例, `argc` 为 3: `argv[0]` = `"./demo"`, `argv[1]` = `"names.dat"`, `argv[2]` = `"dates.dat"`, `argv[3]` = `NULL`.

`argv` 是一个==指针数组==: 元素类型是 `char *`, 分别指向一个参数字符串. 类似地, `int *pa[5]` 是含 5 个 `int *` 元素的数组, `pa[0]` 的类型是 `int *`.

<!-- slide data-notes="" -->


##### 指向函数的指针

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
double integrate(double (*f)(double), double a, double b);
```

```C
double integrate(double f(double), double a, double b);
```

</div>

<div style="flex:1;font-size:0.6em;">

C 不要求指针只指向数据; 也可以有指向函数的指针.

函数占用内存单元, 因此每个函数都有一个地址.

可以像使用指向数据的指针一样使用函数指针.

将函数指针作为参数传递是相当普遍的.

</div>

</div>

<!-- slide data-notes="" -->

##### 指向函数的指针: integrate 的参数与调用

---

<div style="display:grid;grid-template-columns:1.08fr 1fr;gap:24px;align-items:start;">

<div class="left-justify" style="font-size:0.84em;text-align:left;">

integrate 求函数 f 在 a 到 b 之间的积分; 把 f 作为参数, 同一个 integrate 就能处理不同函数.

```C
double integrate(double (*f)(double),
                 double a, double b);

double result = integrate(sin, 0.0, PI/2);
```

- `*f` 两边的括号表示 f 是==指向函数的指针==;
- 去掉括号写成 `double f(double)` 也可以, 编译器同样当作函数指针参数;
- 函数名后面没有括号时生成指向该函数的指针, 调用时直接传 `sin`;
- `PI` 需要自己定义, 如 `#define PI 3.141592653589793`.

</div>

<div class="left-justify" style="font-size:0.84em;text-align:left;">

在 integrate 函数体里, 可以调用 f 指向的函数:

```C
double y = (*f)(x);   /* 等价于 f(x) */
```

- `(*f)(x)` 先解引用 f, 再调用得到的函数;
- `f(x)` 是允许的简写, 两者效果相同;
- 这就是"把函数当参数": 循环不变, 只换传入的函数.

</div>

</div>

<!-- slide data-notes="" -->


##### qsort函数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

</div>

<div style="flex:1;font-size:0.6em;">

C 库中一些功能强大的函数要求把函数指针作为参数.

其中之一是 qsort, 原型在 `<stdlib.h>` 里。

qsort 是一个通用的排序函数, 能够对任何数组进行排序.

必须告诉 qsort 如何确定两个数组元素中的哪个"更小".

做法: 给 qsort 传一个==指向比较函数的指针==.

base 必须指向数组中的第一个元素 (或要排序的部分中的第一个元素).

nmemb 是要排序的元素数.

size 是每个数组元素的大小, 以字节为单位.

compar 是指向比较函数的指针.

</div>

</div>

<!-- slide data-notes="" -->

##### qsort函数 (续)

---

<div style="font-size:0.92em;">

比较函数拿到两个元素的指针 p、q, 返回一个整数:

- 如果 `*p` "小于" `*q`, 返回负数;
- 如果 `*p` "等于" `*q`, 返回零;
- 如果 `*p` "大于" `*q`, 返回正数.

例如, 比较两个 int:

```C
int cmp_int(const void *p, const void *q)
{
  int a = *(const int *)p, b = *(const int *)q;
  return (a > b) - (a < b);
}
```

调用时把函数名传给 qsort:

`qsort(a, n, sizeof(a[0]), cmp_int);`

</div>

<!-- slide data-notes="" -->

##### 函数指针的其他用途: 变量与数组

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:24px;align-items:start;">

<div style="font-size:0.84em;">

函数指针可以像数据指针一样==保存到变量、组成数组、作为参数和返回值==.

```C
void (*pf)(int);   /* 指向 "参数 int、返回 void" 的函数 */
pf = f;            /* 让 pf 指向 f */
pf(i);             /* 调用 f(i), 等价于 (*pf)(i) */
```

- `pf` 是一个变量, 保存函数的地址;
- `pf(i)` 与 `(*pf)(i)` 等价.

</div>

<div style="font-size:0.84em;">

函数指针数组可以按编号选择要调用的函数:

```C
void (*ops[2])(int) = {f, g};
ops[0](i);   /* 调用 f(i) */
ops[1](i);   /* 调用 g(i) */
```

把"做什么"变成数据, 常用于命令表和回调.

</div>

</div>

<!-- slide data-notes="" -->

##### 程序: 列三角函数表

---

==现场演示==: 输入初值、终值、步长, 打印 sin、cos、tan 三张三角函数表

样例:

```
输入初值: 0
输入终值: 0.5
输入步长: 0.1

     x        f(x)
  -------    -------
  0.00000    1.00000
  0.10000    0.99500
  ...
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 同一个循环跑三次, 每次换一个数学函数——怎么把"函数"当作参数传进去?

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/12-strings/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>


<!-- slide data-notes="" -->

##### 程序: 列三角函数表 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="small-code" style="flex:1.4;min-width:0;font-size:0.34em;">

```C{.line-numbers}
/* 列三角函数表: 函数指针作参数 */
#include <stdio.h>
#include <math.h>
void tabulate(double (*f)(double), double a,
              double b, double step)
{
    int n = (int)((b - a) / step + 0.5);
    printf("     x       f(x)\n");
    printf("  -------   -------\n");
    for (int i = 0; i <= n; i++) {
        double x = a + i * step;
        printf("  %7.5f  %7.5f\n", x, f(x));
    }
}
int main(void)
{
    double a, b, step;
    printf("输入初值: ");
    scanf("%lf", &a);
    printf("输入终值: ");
    scanf("%lf", &b);
    printf("输入步长: ");
    scanf("%lf", &step);
    printf("\ncos(x):\n");
    tabulate(cos, a, b, step);
    printf("\nsin(x):\n");
    tabulate(sin, a, b, step);
    printf("\ntan(x):\n");
    tabulate(tan, a, b, step);
    return 0;
}
```

</div>

<div style="flex:1;min-width:0;font-size:0.64em;">

- ==函数指针== `f` 作参数: `tabulate(f, a, b, step)`——三次调用传 `cos`/`sin`/`tan`

- `f(x)` 调用指针指向的函数——循环体一模一样, 只换函数

- 函数指针的典型用途: 把"做什么"也变成参数

</div>

</div>

<!-- slide data-notes="" -->

##### 指针声明怎么读: 规则与圆括号

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:24px;align-items:start;">

<div style="font-size:0.82em;">

==两条读法规则==:

1. ==从标识符出发==, 由内向外读;
2. 有选择时, ==`[]` 和 `()` 优先于 `*`==; 圆括号可以改变优先级.

</div>

<div style="font-size:0.82em;">

==之字形读法==: 从标识符往右读 (`[]`/`()`) → 折回往左读 (`*`) → 再往右……直到读完.

</div>

</div>

<div style="font-size:0.82em;">

```C
int *ap[10];        /* ap 先和 [] 结合: 指针数组 */
float *fp(float);   /* fp 先和 () 结合: 返回指针的函数 */
int (*p)[NUM_COLS]; /* p 先是指针: 行指针 */
void (*pf)(int);    /* pf 是函数指针 */
```

</div>

`int *p[10]` 是==指针数组==, `int (*p)[10]` 是==行指针==, 只差一对圆括号: ==加括号让 `*` 从最后结合变成最先结合==.

<!-- slide data-notes="" -->##### 指针声明怎么读 · 综合练习

---

<div style="font-size:0.85em;line-height:1.6;">

==先遮住类型名, 从标识符开始, 逐层读出下列声明的含义:==

1. `int *p[5];`

2. `int (*p)[5];`

3. `char *(*f[3])(char *);`

4. `int *(*x[10])(void);`

</div>

<span class="blue">:fa-lightbulb-o:</span> 提示: 从标识符出发; 有圆括号先看圆括号; `[]`/`()` 与标识符先结合, 再考虑 `*`

<details style="font-size:0.8em;margin-top:10px;">
<summary style="cursor:pointer;color:#268bd2;">参考答案 (点击展开)</summary>

1. `p` 是数组 (5 个元素), 元素是 `int *` → ==指针数组==

2. `p` 是指针, 指向"含 5 个 int 的数组" → ==行指针==

3. `f` 是数组 (3 个元素), 元素是函数指针: 参数 `char *`, 返回 `char *`

4. `x` 是数组 (10 个元素), 元素是函数指针: 无参, 返回 `int *`

</details>

---

<!-- slide data-notes="" -->

##### 课堂小测

---

1. `int **pp;` 是什么？它和 `int *p;` 的区别？

2. `int a[5]; int *pa[5];` 中，`pa` 是什么？`pa[0]` 是什么类型？

3. `int (*f)(int, int);` 声明的是什么？`f = add;` 之后怎么通过 f 调用 add？

4. `qsort` 的第四个参数是什么类型？为什么排序函数需要它？


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续


