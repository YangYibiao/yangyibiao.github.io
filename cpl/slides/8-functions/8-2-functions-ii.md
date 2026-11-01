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

## 函数 (II) · 声明、参数与函数化改造

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 函数声明 (为什么需要、原型、声明与定义)

- 参数传递 (传值、swap 陷阱、类型转换)

- return 与程序终止 (main 状态码、exit)

- 函数化改造: 素数、leap、primes、stars

- 函数与栈

- 课堂编码

- 课堂小测

---


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

<div style="flex:1;font-size:0.9em;line-height:1.6;">

<div style="font-weight:700;color:#268bd2;">📌 传值的优点</div>

`n` 是原始指数的==副本==, 函数里放心修改它 (`while (n-- > 0)`), 不再需要变量 i

<div style="font-weight:700;color:#268bd2;margin-top:10px;">📌 传值的代价</div>

想在函数里 "改外面" 的变量就做不到了——`decompose` 想分解出整数部分和小数部分: 函数不能返回两个数, 修改形参也==没用==

`decompose(3.14159, i, d)` 之后, i、d 纹丝不动

第 10 周学了指针, decompose 才能真正奏效 (swap 同理)

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

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 非 void 函数==必须==用 `return` 指定返回值

- 表达式通常是常量或变量, 也可以是更复杂的表达式 (`n >= 0 ? n : 0`)

<div style="font-weight:700;color:#268bd2;margin-top:10px;">📌 类型转换</div>

return 表达式的类型与返回类型不匹配时, 会被==隐式转换==为返回类型

声明返回 `int` 却 `return` 了 double, 值被截断成 int

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

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 通常 main 的返回类型是 `int`

- 老式 C 常省略返回类型 (默认 int)——C99 起==不合法==, 不要省略; 参数列表里的 `void` 省略合法, 但最好写上

<div style="font-weight:700;color:#268bd2;margin-top:10px;">📌 状态码</div>

main 的返回值是==状态码==: 正常结束返回 0; 异常结束返回==非 0==

每个程序都返回状态码是好习惯

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

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 结束程序的两种方式: main 里 `return`, 或调用 `<stdlib.h>` 的 `exit`——参数含义相同 (状态码)

- 0 有点模糊, 所以 C 提供宏: `EXIT_SUCCESS` (正常) / `EXIT_FAILURE` (异常), 定义在 `<stdlib.h>`, 通常为 0 和 1

<div style="font-weight:700;color:#268bd2;margin-top:10px;">📌 return 与 exit 的区别</div>

- `return` 只有由 ==main== 执行时才结束程序

- `exit` ==任何函数==里调用都会结束程序

</div>

</div>

---


<!-- slide data-notes="" -->##### 程序: 判定素数

---

==现场演示==: 写一个函数 `is_prime(n)` 判断素数, 主函数读入并输出结果

样例:

```
输入一个数: 34
不是素数
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 判断逻辑第 5 周写过 (break 版)——这次把它==做成函数==

---



<!-- slide data-notes="" -->


##### 程序: 判定素数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
/* 判断一个数是否为素数 */
#include <stdio.h>

int is_prime(int n)
{
  int divisor;

  if (n <= 1) {
    return 0;
  }
  for (divisor = 2; divisor <= n / divisor; divisor++) {
    if (n % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  int n;

  printf("输入一个数: ");
  scanf("%d", &n);
  if (is_prime(n)) {
    printf("是素数\n");
  } else {
    printf("不是素数\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 判断逻辑封装进 `is_prime`——main 只剩输入输出, 一眼看清

- `divisor <= n / divisor` 是检查到 $\sqrt{n}$ 的等价写法 (不用 math.h), 而且==不会溢出==

- 反例: 判断 n = 2147483647 (int 上限, 本身是素数), divisor 试到 46341 时 `46341 × 46341 = 2147488281` 超出 int 上限 2147483647, 溢出变成==负数== → 条件变 false, 循环提前结束, 素数被误判

- 返回 1/0, 调用处 `if (is_prime(n))` 直接当条件——与 8-1 的写法一致

</div>

</div>

---

<!-- slide data-notes="" -->


##### leap.c: 原版 vs 函数版

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:14px;align-items:start;font-size:0.5em;">

<div>

```C
/* 原版: 判断逻辑在 main 里 */
#include <stdio.h>
int main(void) {
  int year = 0;
  scanf("%d", &year);
  int leap = 0;
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    leap = 1;
  }
  if (leap == 0) {
    printf("%d 是平年\n", year);
  } else {
    printf("%d 是闰年\n", year);
  }
  return 0;
}
```

</div>

<div>

```C
/* 函数版: 判断逻辑抽成函数 */
#include <stdio.h>
int is_leap_year(int);
int main(void) {
  int year = 0;
  scanf("%d", &year);
  int leap = is_leap_year(year);
  if (leap == 0) {
    printf("%d 是平年\n", year);
  } else {
    printf("%d 是闰年\n", year);
  }
  return 0;
}
int is_leap_year(int n) {
  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    return 1;
  }
  return 0;
}
```

</div>

</div>

<div style="margin-top:8px;">

- 判断逻辑抽成 `is_leap_year(year)`, main 只剩输入输出

- 返回 1/0, `if (is_leap_year(year))` 直接当条件

- 以后想再判断闰年, 调函数即可——不用重写条件

<a href="code/leap.c" target="_blank">leap.c</a> · <a href="code/leap-re.c" target="_blank">leap-re.c</a>

</div>

---

<!-- slide data-notes="" -->##### primes.c: 原版 vs 函数版

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:14px;align-items:start;font-size:0.5em;">

<div>

```C
/* 原版: 判断逻辑埋在 main 里 */
#include <stdio.h>

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    // 判断 i 是否素数
    int prime = 1;
    for (int j = 2; j <= i / j; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      count++;
    }
  }
  printf("\n素数个数: %d", count);
  return 0;
}
```

</div>

<div>

```C
/* 函数版: is_prime 抽出来 */
#include <stdio.h>

int is_prime(int n) {
  for (int j = 2; j <= n / j; j++) {
    if (n % j == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    if (is_prime(i) == 1) {
      count++;
    }
  }
  printf("\n素数个数: %d", count);
  return 0;
}
```

</div>

</div>

<div style="margin-top:8px;">

- 原版: 素数逻辑埋在 main 的两层循环里; 函数版: `is_prime(i)` 一行调用——和第 4 页是同一个函数

- 函数化改造的套路: 把 "一块逻辑" 抽出来 → 起名字 → 参数进、返回值出

<a href="code/primes.c" target="_blank">primes.c</a> · <a href="code/primes-re.c" target="_blank">primes-re.c</a>

</div>

---

<!-- slide data-notes="" -->


##### stars.c

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
#include <stdio.h>

int main() {
  int lines = 0;
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++) {
    // 打印空格 (居中)
    for (int j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }
    // 打印 2*i+1 颗星
    for (int j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }
    if (i != lines - 1) {
      printf("\n");
    }
  }

  return 0;
}
```

</div>

<div style="flex:1;">

- 程序里 "打印一行 2*i+1 颗星" 的循环, 就是可以抽出来的函数 `print_stars(n)`

- 留到课堂编码: 你来做这个改造

- 提示: 打印空格的循环也可以抽成 `print_spaces(n)`——每个函数只做==一件事==

<a href="code/stars.c" target="_blank">stars.c</a>

</div>

</div>

<!-- slide data-notes="" -->


##### 函数与栈

---

每次函数调用, 系统都会在==调用栈==(call stack)上做两件事:

- ==压栈==: 保存返回地址、局部变量、参数

- ==弹栈==: 函数返回后, 其局部变量随之消失

这就是局部变量"出了函数就没了"的原因, 也是递归能一层层返回的机制。

动画演示: [function-and-stack.html](function-and-stack.html)

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

把下面的程序改写成"主函数 + 若干函数"的结构:

1. 计算平均值: `double average(double a, double b)`

2. 判定素数: `int is_prime(int n)`

3. 打印一行星号: `void print_stars(int n)`

<span class="blue">:fa-lightbulb-o:</span> 设计原则回顾: 每个函数只做==一件事==

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 概念: 函数调用之前必须有什么？函数声明的一般形式是什么？

2. 概念: 函数调用时栈上发生了什么？局部变量在函数返回后会怎样？

3. 代码阅读: 阅读 leap.c 函数版, `is_leap_year(1900)` 返回什么？为什么？

4. 纠错: swap 里交换了形参 a、b, 为什么 x、y 没变？(第 10 周解答)

5. 纠错: 闰年判断写成 `year % 4 == 0 || year % 400 == 0` (少了 `&& year % 100 != 0`) 会怎样？

---
<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


