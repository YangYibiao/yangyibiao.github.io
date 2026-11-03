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

---


<!-- slide data-notes="" -->


##### 指向指针的指针

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
struct node *add_to_list(struct node *list, int n)
{
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = list;
  return new_node;
}
```

</div>

<div style="flex:1;font-size:0.6em;">

链表章见过 `struct node *next`——"指向指针的指针"是再进一步:

"指向指针的指针"的概念也经常出现在链式数据结构中.

特别是, 当函数的实际参数是指针变量时, 可能会希望函数能够修改变量.

这样做需要使用指向指针的指针.

传给 add_to_list 一个指向原链表首结点的指针; 它返回新链表首结点的指针:

如果要修改 add_to_list, 把 new_node 赋值给 list, 而不是返回 new_node, 这是不起作用的.

调用函数: `add_to_list(first, 10);`

在调用点, first 被复制到 list 中.

函数可以改变 list 的值, 使其指向新结点, 但 first 不受影响.

</div>

</div>

<!-- slide data-notes="" -->

##### 指向指针的指针 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
void add_to_list(struct node **list, int n)
{
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = *list;
  *list = new_node;
}
```

</div>

<div style="flex:1;font-size:0.6em;">

想让 add_to_list 修改 first 本身, 就传 first 的地址 (指向指针的指针):

`add_to_list(&first, 10);`

在函数内部, `list` 是 `first` 的地址; `*list` 就是 `first` 本身.

因此 `*list = new_node;` 修改的是调用者的 `first`, 而不是一个副本.

`new_node->next = *list;` 把新结点接到原来的首结点之前.

这解决了按值传递无法修改头指针的问题.

</div>

</div>

<!-- slide data-notes="" -->


##### 命令行参数: 带参数的 main

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```
ls
ls –l
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

##### 指向函数的指针 (续)

---

编写 integrate 函数求函数 f 在 a 点和 b 点之间的积分, 可以把 f 作为参数传入, 从而使其尽可能通用.

```C
double integrate(double (*f)(double), double a, double b);
```

- `*f` 两边的括号表示 f 是指向函数的指针.
- 去掉括号写成 `double f(double)` 也可以, 编译器会把它当作函数指针参数.
- 调用时直接传函数名, 例如 `integrate(sin, 0.0, PI/2)`.

<!-- slide data-notes="" -->


##### 函数指针作为参数

---

调用 integrate 计算 sin 从 0 到 $\pi/2$ 的积分: 

`result = integrate(sin, 0.0, PI/2);`

当函数名后面没有括号时, C 编译器会生成一个指向该函数的指针. 

在 integrate 函数体里, 可以调用 f 指向的函数: 

`y = (*f)(x);`

允许使用f(x)代替(*f)(x) .

---


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


##### 函数指针的其他用途

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
void (*pf)(int);
```

</div>

<div style="flex:1;font-size:0.6em;">

尽管函数指针经常用作参数, 但这并不是它们的全部优点.

C 将指向函数的指针视为指向数据的指针.

它们可以存储在变量中, 也可以用作数组的元素, 结构或联合的成员.

函数甚至可以返回函数指针.

可以存储指向函数的指针的变量, pf 指向具有 int 型参数且返回 void 型值的函数:

如果 f 是这样一个函数, 可以通过以下方式使 pf 指向 f:

`pf = f;`

</div>

</div>

<!-- slide data-notes="" -->

##### 函数指针的其他用途 (续)

---

可以通过以下方式调用 f:

`(*pf)(i);`

或者

`pf(i);`

函数指针也可以组成数组, 按编号选择要调用的函数:

```C
void (*ops[2])(int) = {f, g};
ops[0](i);
```

这种写法把"做什么"变成数据, 常用于命令表和回调.

<!-- slide data-notes="" -->##### 程序: 列三角函数表

---

==现场演示==: 输入初值、终值、步长, 打印一张三角函数表 (sin、cos、tan 三张)

样例:

```
输入初值: 0
输入终值: 0.5
输入步长: 0.1

     x        cos(x)
  -------    -------
  0.00000    1.00000
  0.10000    0.99500
  ...
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 同一个循环跑三次, 每次换一个数学函数——怎么把"函数"当作参数传进去?

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/12-strings/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>

---



<!-- slide data-notes="" -->


##### 程序: 列三角函数表 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.5em;">

```C{.line-numbers}
/* 列三角函数表: 函数指针作参数 */
#include <stdio.h>
#include <math.h>

void tabulate(double (*f)(double), double a, double b, double step)
{
    double x;
    printf("     x       f(x)\n");
    printf("  -------   -------\n");
    for (x = a; x <= b; x += step)
        printf("  %7.5f  %7.5f\n", x, f(x));
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
}```

</div>

<div style="flex:1;">

- ==函数指针== `f` 作参数: `tabulate(f, a, b, step)`——三次调用传 `cos`/`sin`/`tan`

- `f(x)` 调用指针指向的函数——循环体一模一样, 只换函数

- 函数指针的典型用途: 把"做什么"也变成参数

</div>

</div>

---

<!-- slide data-notes="" -->

##### 课堂小测

---

1. `int **pp;` 是什么？它和 `int *p;` 的区别？

2. `int a[5]; int *pa[5];` 中，`pa` 是什么？`pa[0]` 是什么类型？

3. `int (*f)(int, int);` 声明的是什么？`f = add;` 之后怎么通过 f 调用 add？

4. `qsort` 的第四个参数是什么类型？为什么排序函数需要它？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


