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

## 函数 (I)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 为什么需要函数: 回文素数案例与设计原则

- 函数定义与调用 (案例: 素数判断)

- 返回类型 void 与无参函数 (案例: 倒计时、sort 空壳)

- 函数声明

- 参数传递 (传值、swap 陷阱、类型转换)

- return 与程序终止

---


<!-- slide data-notes="" -->


##### 案例: 回文素数

---

输入 $m$、$n$ ($m \le n$), 完成==三个任务==:

1. 输出 $[m, n]$ 里全部的==回文素数== (既是素数、又是回文数)

2. 统计 $[m, n]$ 里素数有多少个

3. 判断 $n$ 是不是回文数

样例: 输入 `100 200` → 回文素数 `101 131 151 181 191`, 素数个数 `21`, `200 不是回文数`

==现场演示==: 只用第 5 周学的循环, ==不用函数==, 把这个程序写出来

<span class="blue">:fa-lightbulb-o:</span> 先想想: 三个任务里, 哪道检查会被==反复使用==? 第 5 周是不是写过其中一道?

---

<!-- slide data-notes="" -->##### 不用函数: 检查写了四遍

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.48em;">

```C{.line-numbers}
/* 三个任务: 不用函数 */
#include <stdio.h>

int main(void)
{
  int m, n, i, d, rev, t;
  int count = 0;

  printf("输入 m n (m<=n): ");
  scanf("%d%d", &m, &n);

  for (i = m; i <= n; i++) {
    /* 任务 1: 输出回文素数 */
    /*   素数检查 (第一次) */
    int is_prime = 1;
    for (d = 2; d * d <= i; d++) {
      if (i % d == 0) {
        is_prime = 0;
        break;
      }
    }
    /*   回文检查 (第一次) */
    t = i; rev = 0;
    while (t > 0) { rev = rev * 10 + t % 10; t = t / 10; }
    if (is_prime && rev == i) {
      printf("%d ", i);
    }

    /* 任务 2: 统计素数个数 */
    /*   素数检查 (第二次, 一字不差) */
    is_prime = 1;
    for (d = 2; d * d <= i; d++) {
      if (i % d == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      count++;
    }
  }
  printf("\n素数个数: %d\n", count);

  /* 任务 3: 判断 n 是不是回文数 */
  /*   回文检查 (第二次, 一字不差) */
  t = n; rev = 0;
  while (t > 0) { rev = rev * 10 + t % 10; t = t / 10; }
  if (rev == n) {
    printf("%d 是回文数\n", n);
  } else {
    printf("%d 不是回文数\n", n);
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 素数检查出现==两次==、回文检查出现==两次==——一模一样的代码, 纯复制粘贴

- 三个任务里混着四段检查, `main` 已经 40 多行, 想看清"程序在干什么"都难

- 素数检查要改 (比如 `d * d <= i` 优化成 `d <= i / d`), ==两处都要改==; 漏改一处, 统计和输出对不上, 错得莫名其妙

<a href="code/palindrome-prime.c" target="_blank">palindrome-prime.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 用函数: 检查各写一遍

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.52em;">

```C{.line-numbers}
/* 三个任务: 用函数 */
#include <stdio.h>

int is_prime(int n)          /* 素数检查: 写一次 */
{
  int d;

  for (d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome(int n)     /* 回文检查: 写一次 */
{
  int rev = 0, t = n;

  while (t > 0) {
    rev = rev * 10 + t % 10;
    t = t / 10;
  }
  return rev == n;
}

int main(void)
{
  int m, n, i, count = 0;

  printf("输入 m n (m<=n): ");
  scanf("%d%d", &m, &n);

  for (i = m; i <= n; i++) {
    /* 任务 1: 输出回文素数 */
    if (is_prime(i) && is_palindrome(i)) {
      printf("%d ", i);
    }
    /* 任务 2: 统计素数个数 */
    if (is_prime(i)) {
      count++;
    }
  }
  printf("\n素数个数: %d\n", count);

  /* 任务 3: 判断 n 是不是回文数 */
  if (is_palindrome(n)) {
    printf("%d 是回文数\n", n);
  } else {
    printf("%d 不是回文数\n", n);
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 两道检查各写==一遍==; `is_prime` 被调用了 2×(n-m+1) 次, `is_palindrome` (n-m+1)+1 次——==零复制==

- `main` 只剩三个任务的一行行调用, 程序在干什么==一眼看清==

- 检查要改? 只改==一处==

- `if (is_prime(i) && is_palindrome(i))`: 函数的返回值可以直接当条件用——这是今天要学的核心玩法

<a href="code/palindrome-prime-re.c" target="_blank">palindrome-prime-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 软件设计原则

---

同样一段检查要抄很多遍, 改 bug 就要改很多处——函数给代码起名字, 一次写好、处处使用

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:12px;margin-top:10px;font-size:0.8em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">
<div style="font-weight:700;color:#268bd2;">🔁 复用</div>
同样的逻辑只写==一遍==, 需要时调用即可 —— 改 bug 只改一处
</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">
<div style="font-weight:700;color:#268bd2;">🧩 模块化</div>
程序拆成小块, ==更容易调试、理解== —— 每块只做一件事
</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">
<div style="font-weight:700;color:#268bd2;">📦 封装</div>
隐藏实现细节, 只暴露有限、必要的==接口==
</div>

</div>

刚才的 `is_prime` 和 `is_palindrome` 就是例证: 各写一遍、反复调用——复用、模块化、封装, 一个案例全用上
<!-- slide data-notes="" -->


##### 函数

---

函数是==打包在一起并起名字==的一组语句。

每个函数本质上都是一个自带声明和语句的小程序. 

功能优势: 

- 一个程序可以分成更容易理解和修改的小块. 

- 可以避免重复编写要多次使用的代码. 

- 最初属于某个程序的功能可以在其他程序中重用. 

---


<!-- slide data-notes="" -->


##### 函数的定义和调用

---

==其实你早就在用函数了==——`printf` 和 `scanf` 就是标准库提供的函数, 它们的声明来自头文件:

```C
int printf(const char *format, ...);
int scanf(const char *format, ...);
```

```C
char str[1024];
scanf("%s", str);

int a, b;
scanf("%d%d", &a, &b);
printf("a + b is : %d", a + b);
```

---


<!-- slide data-notes="" -->


##### 函数定义 · 语法骨架

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
返回类型 函数名(形式参数)
{
  声明
  语句
}
```

```C{.line-numbers}
double
average(double a, double b)
{
  return (a + b) / 2;
}
```

</div>

<div style="flex:1;">

- 函数的 ==返回类型== 是返回值的类型

- 规则: 不能返回数组; ==void== 表示没有返回值; C89 省略默认 int; ==C99 不允许省略==

- 返回类型很冗长时 (如 `unsigned long int`), 也有的习惯把它单独放一行——左栏 `double` 就是这么放的

</div>

</div>

<!-- slide data-notes="" -->


##### 函数定义 · 参数列表与函数体

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
double average(double a, double b)
{
  double sum;       /* declaration */
 
  sum = a + b;      /* statement */
  return sum / 2;   /* statement */
}
```

</div>

<div style="flex:1;font-size:0.85em;line-height:1.6;">

<div style="font-weight:700;color:#268bd2;">📌 参数列表</div>

每个==形式参数==前都要说明类型, 参数之间用逗号分隔

没有形式参数时, 括号里写 `void`

<div style="font-weight:700;color:#268bd2;margin-top:10px;">📌 函数体</div>

由大括号包围, 里面可以写==声明==和==语句==

函数体内声明的变量, 其他函数无法访问或修改

C89: 声明必须写在语句之前; C99: 声明与语句可以混合 (使用前声明过即可)

</div>

</div>

<!-- slide data-notes="" -->


##### 函数定义 · 空函数体

---

返回类型为 `void` 的函数, 函数体可以==为空==: 

```C
void sort(int a[], int n)
{
}
```

- 空函数体 = ==占位== (stub): 开发时先把所有函数定义好 (哪怕空着), 程序就能==编译、运行==

- 之后再逐个填充实现 —— 像盖房子: 先立好框架, 再砌墙装修

- 兑现上周的承诺: "后面学了函数, 就能把排序封装成 `sort(a, n)`"——壳先立起来, 排序实现第 9 周再填

---


<!-- slide data-notes="" -->


##### 程序: 素数判断

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

开场案例里的 `is_prime`——现在逐行拆解它的定义。第 5 周用循环写过素数判断, 今天把它==函数化==.

```C{.line-numbers}
int is_prime(int n)
{
  int d;

  for (d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return 0;              /* 找到因子, 不是素数 */
    }
  }
  return 1;                  /* 没找到因子, 是素数 */
}
```

- 开头的 `int` 是返回类型: 是素数返回 1, 不是返回 0

- `n` 是形式参数, 表示待判断的数; 调用时复制实际参数的值

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- ==函数体==由大括号包围, 里面是声明 `int d` 和循环

- 函数可以有==多条 return==: 执行到哪条, 就从哪条返回

- 调用需要函数名和实际参数: `is_prime(97)`、`is_prime(m)` 都是合法调用

- 实际参数可以是任意同类型的表达式, 不一定是变量

</div>

</div>

<!-- slide data-notes="" -->##### 程序: 素数判断 (prime.c)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* prime.c: 输出 2 ~ 100 的全部素数 */
#include <stdio.h>

int is_prime(int n)
{
  int d;

  for (d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  int i;

  for (i = 2; i <= 100; i++) {
    if (is_prime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}
```

</div>

<div style="flex:1;">

- 把 `is_prime` 的调用放在 `if` 里, 返回值直接当==条件==用——非 void 函数的调用就是一个值

- 2 ~ 100 的素数:

2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97

- 对比第 5 周: 那时要判断一个数, 得把循环抄一遍; 现在写一次, 判断 99 次

</div>

</div>
<!-- slide data-notes="" -->


##### 返回类型: void

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

函数==没有返回值==, 返回类型就写 ==void==: 

```C
void print_count(int n)
{
  printf("%d\n", n);
}
```

==没有参数==时, 括号里写 `void`, 调用时也必须写==空括号==:

```C
void print_line(void)
{
  printf("====\n");
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

`void` 是一种没有值的类型

`print_count` 的调用必须自成一个语句: `print_count(i);`——`countdown.c` 在循环里调用了 10 次

---

`print_line` 的调用: `print_line();`——括号不能省, 否则编译器把它当成变量

</div>

</div>

<!-- slide data-notes="" -->##### 程序: 打印倒计时

---

==现场演示==: 把火箭倒计时封装成函数——`print_count(n)` 打印一行数字, 主函数循环调用它完成 10 到 1 的倒计时

样例输出:

```
10
9
...
1
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 函数只负责"打印一行", 循环调用放在 main 里——第 5 周的知识和函数第一次配合

---


<!-- slide data-notes="" -->


##### 程序: 打印倒计时 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 火箭倒计时: 函数 + 循环 */
#include <stdio.h>

void print_count(int n)
{
  printf("%d\n", n);
}

int main(void)
{
  int i;

  for (i = 10; i > 0; --i) {
    print_count(i);
  }
  printf("发射!\n");

  return 0;
}
```

</div>

<div style="flex:1;">

- `print_count` 每次调用只打印一行——==一个函数只做一件事==

- 循环在 main 里, 函数被调用了 10 次——函数和循环第一次配合

- 输出: 10、9、…、1、发射!

<span class="blue">:fa-lightbulb-o:</span> 练习: 用同样方式写 `gcd(a, b)`——辗转相除法 (大数除小数取余, 直到余数为 0), 比倒计时更有"算法味"

</div>

</div>

---
<!-- slide data-notes="" -->


##### 函数调用

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
average(x, y)
print_count(i)
print_line()
```

```C
print_line;   /*** WRONG ***/
```

```C
print_count(i);
print_line();
```

```C
avg = average(x, y);
if (average(x, y) > 0) {
  printf("Average is positive\n");
}
printf("The average is %g\n", average(x, y));
```

</div>

<div style="flex:1;">

函数调用由函数名和用括号括起来的实际参数列表组成:

如果没有括号, 就无法调用函数:

该语句是合法的, 但没有任何作用.


---

void函数的调用后边始终跟着分号, 使该调用成为语句:

调用非void函数会产生一个值, 该值可存储在变量中或打印等:



</div>

</div>

<!-- slide data-notes="" -->


##### 函数调用

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
average(x, y);  /* discards return value */
```

```C
num_chars = printf("Hi, Mom!\n");
```

```C
printf("Hi, Mom!\n"); /* discards return value */
```

```C
(void) printf("Hi, Mom!\n");
```

</div>

<div style="flex:1;">

如果不需要非void函数返回的值, 总是可以将其丢弃:

此调用是表达式语句的示例: 计算出语句的值, 但不保存它.


---

丢掉average函数的返回值是奇怪的, 但有些情况下是有意义的. 

printf返回它打印的字符个数. 

在以下调用之后, num_chars的值为 9:

我们通常会丢弃printf的返回值:

---

返回值==故意不要==时, 可以在调用前加 `(void)` 表明:

使用(void)可以让别人清楚编写者是故意丢弃了返回值, 而不是忘记了.

</div>

</div>

<!-- slide data-notes="" -->


##### 函数声明

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
 
int main(void)
{
  double x, y, z;
 
  printf("Enter three numbers: ");
  scanf("%lf%lf%lf", &x, &y, &z);
  printf("Average of %g and %g: %g\n", x, y, average(x, y));
  printf("Average of %g and %g: %g\n", y, z, average(y, z));
  printf("Average of %g and %g: %g\n", x, z, average(x, z));

  return 0;
}
 
double average(double a, double b)
{
  return (a + b) / 2;
}
```

</div>

<div style="flex:1;">

C不要求函数的定义在其调用之前. 

假设我们重新编排`average.c`程序, 将average函数的定义放在main函数的定义之后.



</div>

</div>

<!-- slide data-notes="" -->


##### 函数声明

---

main 里调用 average 时编译器没有它的信息: 不报错, 而是假设它返回 `int`——为该函数创建了==隐式声明==


---

实参个数与类型也无法检查, 只能默认提升"希望最好"; 后面遇到真实定义 (返回 `double`) 才会报错


---

避免方法一: 定义总写在调用之前——可惜有时做不到, 且顺序不自然、难读

---


<!-- slide data-notes="" -->


##### 函数声明

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
返回类型 函数名(参数);
```

```C{.line-numbers}
#include <stdio.h>
 
double average(double a, double b);   /* DECLARATION */

int main(void)
{
  double x, y, z;

  printf("Enter three numbers: ");
  scanf("%lf%lf%lf", &x, &y, &z);
  printf("Average of %g and %g: %g\n", x, y, average(x, y));
  printf("Average of %g and %g: %g\n", y, z, average(y, z));
  printf("Average of %g and %g: %g\n", x, z, average(x, z));

  return 0;
}
 
double average(double a, double b)    /* DEFINITION */
{
  return (a + b) / 2;
}
```

```C
double average(double, double);
```

</div>

<div style="flex:1;">

幸运的是, C提供了更好的解决方案: 在调用函数之前声明它. 

函数声明为编译器提供函数的简要介绍, 完整定义将在以后给出. 

函数声明的<u>一般形式</u>:

函数的声明必须与函数的定义一致. 

这是为average函数添加了声明的`average.c`程序.

---

我们正在讨论的这类函数声明称为函数原型. 

C也有旧式的函数声明, 其中括号是空的. 

函数原型不必指定函数形参的名字, 只要显示它们的类型即可:

但最好不要省略形参的名字.


---

C99遵循的规则: 在调用函数之前, 必须先对其进行声明或定义. 

调用函数时, 如果此前编译器未见其声明或定义, 会导致出错.

</div>

</div>

<!-- slide data-notes="" -->


##### 实际参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

计算数字 x 的 n 次幂 $x^n$:

```C{.line-numbers}
int power(int x, int n)
{
  int i, result = 1;

  for (i = 1; i <= n; i++) {
    result = result * x;
  }

  return result;
}
```

调用: `printf("%d\n", power(2, 5));` → 输出 32

</div>

<div style="flex:1;">

C 里参数是==按值传递==的: 

- 调用函数时, 计算出每个实际参数的值, 并将其赋值给相应的形式参数

- 函数里改形参==不影响实参==——形参只是实参的副本

---

按值传递既有优点也有缺点: 

- ==优点==: 形参可以当函数内的普通变量用, 少声明几个变量 (下一页的 power 就这么写)

- ==缺点==: 想在函数里 "改外面" 的变量, 做不到——下一页的 decompose 就是典型例子

</div>

</div>

<!-- slide data-notes="" -->


##### 实际参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
int power(int x, int n)
{
  int result = 1;

  while (n-- > 0) {
    result = result * x;
  }

  return result;
}
```

```C
void decompose(double x, long int_part, double frac_part)
{
  int_part = (long) x;
  frac_part = x - int_part;
}
```

```C
decompose(3.14159, i, d);
```

</div>

<div style="flex:1;">

n是原始指数的副本, 函数可以安全修改它, 从而不再需要变量i:

---

C对参数按值传递的要求使得编写某些类型的函数变得困难. 

假设需要一个将double型的值分解为整数和小数部分的函数. 

函数不能返回两个数, 尝试将两个变量传递给函数并修改它们:

---

函数调用:

可惜的是, i和d不会因为赋值给int_part和frac_part而受到影响. 

第 10 周学了指针, decompose 就能真正奏效 (swap 同理).

</div>

</div>

<!-- slide data-notes="" -->


##### 演示: swap 为什么不生效?

---

<div style="font-size:0.8em;">

```C
void swap(int a, int b) {
    int t = a;  a = b;  b = t;      /* 交换的是副本! */
}

int main(void) {
    int x = 3, y = 5;
    swap(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

</div>

运行结果: 

```
x = 3, y = 5
```

- 传值调用: `a`、`b` 只是 `x`、`y` 的==副本==, 函数内交换副本, 外面==纹丝不动==

- 换个角度看: 如果调用 `swap(x + 6, y + 5)`, 传进去的是表达式的==值==——显然没人指望 x、y 被改; `swap(x, y)` 传的同样是值, 不是变量本身

- 这是新手最困惑的现象之一: 函数明明执行了, "为什么没效果?"

- 记住这个悬念——==第 10 周学指针==后, 用 `swap(&x, &y)` 就能真正交换 (先记下来, 不剧透)

---

<!-- slide data-notes="" -->


##### 实际参数的转换

---

C 允许实际参数的类型与形式参数的类型==不匹配==: 怎么转换, 取决于调用前编译器==有没有见过原型==

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.6em;">

```C{.line-numbers}
double average(double a, double b)
{
  return (a + b) / 2;
}

int main(void)
{
  int x = 3, y = 5;
  printf("%g\n", average(x, y));   /* int 实参 */
  return 0;
}
```

</div>

<div style="flex:1;">

==见过原型== (本页): 每个参数的值被==隐式转换==为形参的类型, 就像==赋值==一样

- `average(x, y)`: x、y 是 int, 传给 double 形参时自动转成 double——安全, 结果正确 (输出 4)

==没见过原型== (下一页): 执行默认参数提升, ==危险==——square 的例子

</div>

</div>

---


<!-- slide data-notes="" -->


##### 实际参数的转换

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
 
int main(void)
{
  double x = 3.0;
  printf("Square: %d\n", square(x));
 
  return 0;
}
 
int square(int n)
{
  return n * n;
}
```

```C
printf("Square: %d\n", square((int) x));
```

</div>

<div style="flex:1;">

编译器在调用之前没有遇到原型. 

编译器执行默认的实际参数提升: 

float类型的实际参数转换为double类型. 

执行整值提升, 把char和short类型的实际参数转换为int类型. (C99为整数提升)


---

依赖默认的实际参数提升是危险的, 例如:

在调用square时, 编译器不知道它需要一个int类型的参数.


---

编译器在$x$上执行默认的实际参数提升, 但没有任何效果. 

函数期望int类型的实际参数, 却获得了double类型值, 所以调用square将产生无效的结果. 

将square的实际参数强制转换为正确的类型可以解决该问题:

更好的解决方案是在调用square之前提供该函数的原型. 

C99中, 没有提供函数声明或定义时调用square函数是错误的.

</div>

</div>

<!-- slide data-notes="" -->


##### return语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C
return 表达式;
```

```C
return 0;
return status;
return n >= 0 ? n : 0;
```

</div>

<div style="flex:1;">

非void的函数必须使用return语句来指定它将返回的值. 

return语句的 <u>格式</u>:

表达式通常只是常量或变量, 但也可以是更复杂的表达式:

---

如果return语句中表达式的类型与函数的返回类型不匹配, 则表达式将被隐式转换为返回类型. 

*如果声明函数返回int型值, 但return语句包含double类型表达式, 则表达式的值将被转换为int类型.*

</div>

</div>

<!-- slide data-notes="" -->


##### return语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
return;  /* return in a void function */
```

```C{.line-numbers}
void print_int(int i)
{
  if (i < 0) {
    return;
  }
  printf("%d", i);
}
```

```C
void print_count(int n)
{
  printf("%d\n", n);
  return;   /* OK, but not needed */
}
```

</div>

<div style="flex:1;">

没有给出表达式, return语句可以出现在返回类型为void的函数中:

如:

---

return语句可以出现在void函数的末尾:

在C89中, 函数中return语句不是必需的. 

非 `void` 函数==忘了写 return==, 再去用它的返回值, 行为是未定义的。

</div>

</div>

<!-- slide data-notes="" -->


##### 程序终止

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C
int main(void)
{
  …
}
```

```C
main()
{
  …
}
```

</div>

<div style="flex:1;">

通常, main的返回类型是int:

以往的C常省略main的返回类型, 利用的是返回类型默认int的传统:

---

省略函数的返回类型在C99中是不合法的, 因此最好不要这么做. 

在main的参数列表中省略void是合法的, 但最好包含它.


---

main返回的值是一个状态码, 在程序终止时可以检测 ==状态码==. 

如果程序正常终止, main应该返回0. 

要表示==异常结束==, main 返回一个非 0 值。

确保每个C程序都返回一个状态码是一种很好的做法.

</div>

</div>

<!-- slide data-notes="" -->


##### exit函数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
exit(0);   /* normal termination */
```

```C
exit(EXIT_SUCCESS);
```

```C
exit(EXIT_FAILURE);
```

```C
return 表达式;
```

```C
exit(表达式);
```

</div>

<div style="flex:1;">

在 main 里执行 return 是结束程序的一种方式。

另一个是调用exit函数, 它属于`<stdlib.h>`头. 

传递给exit的实际参数与main的返回值具有相同的含义: 两者都表示程序在终止时的状态. 

要表示==正常结束==, 返回 0:

---

由于0有点模糊, 所以C允许用EXIT_SUCCESS来代替(效果一样):

传递EXIT_FAILURE表示异常终止:

`EXIT_SUCCESS`和`EXIT_FAILURE`是定义在`<stdlib.h>`中的宏. 

- `EXIT_SUCCESS`和`EXIT_FAILURE`的值是由实现定义的, 通常为0和1.


---

main中的语句

等价于

return和exit的区别在于: 

- 无论哪个函数调用exit都会导致程序终止. 

- return语句仅当由main函数调用时才会导致程序终止.

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 概念: 函数定义由哪几部分组成？`return` 的作用是什么？

2. 概念: C 语言中参数按什么方式传递？实参和形参是什么关系？

3. 代码阅读: 调用 `is_prime(9)` 和 `is_prime(11)` 各返回什么？`is_prime` 里的 `return 0` 执行后, 循环还会继续吗？

4. 纠错: 下面的函数想交换两个变量的值, 调用后为什么 x、y 没变？该怎么改（先不剧透, 第 10 周解答）？

```C
void swap(int a, int b) {
    int t = a;  a = b;  b = t;
}
```

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


