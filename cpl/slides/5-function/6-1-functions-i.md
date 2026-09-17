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

- 软件设计原则

- 函数的定义与调用

- 函数声明

- 参数传递

- return 与程序终止

---


<!-- slide data-notes="" -->


##### 软件设计原则

---

==复用==

模块化：便于调试、代码理解

封装：隐藏实现细节，仅暴漏有限、必要的接口

---

---


<!-- slide data-notes="" -->


##### 函数

---

函数是一连串组合在一起并命名的语句. 

每个函数本质上都是一个自带声明和语句的小程序. 

功能优势: 

- 一个程序可以分成更容易理解和修改的小块. 

- 可以避免重复编写要多次使用的代码. 

- 最初属于某个程序的功能可以在其他程序中重用. 

---

---


<!-- slide data-notes="" -->


##### 函数的定义和调用

---

```C
int printf(const char*          format, ... );
int scanf(const char          *format, ... );
```

```C
char str[1024];
scanf("%s", str);

int a, b;
scanf("%d%d", &a, &b);
printf("a + b is : %d", a + b);
```

---

---


<!-- slide data-notes="" -->


##### 函数定义

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

函数定义的<u>一般格式</u>:

---

函数的 ==返回类型== 是函数返回值的类型. 

函数返回类型的规则: 

- 函数不能返回数组. 

- 指定返回类型为void表示该函数没有返回值. 

- 在C89中, 如果省略返回类型, 则假定该函数的返回值是int类型. 

- 在C99中, 省略返回类型是不合法的. 

---


---

一些程序员习惯把返回类型放在函数名的上边:

如果返回类型很冗长, 比如unsigned long int类型, 把返回类型单独放在一行会更清晰.

</div>

</div>

<!-- slide data-notes="" -->


##### 函数定义

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

<div style="flex:1;">

函数名之后是参数列表. 

需在每个形式参数前面说明其类型 , 形式参数间用逗号分隔. 

如果函数没有形式参数, 则应在括号里加上单词void.


---

函数体可能包括声明和语句. 

average函数的另一个版本:

---

函数体内声明的变量不能被其他函数检查或修改. 

在C89中, 变量声明必须出现语句之前. 

在C99中, 变量声明和语句可混合, 只要变量在使用前声明过即可.

</div>

</div>

<!-- slide data-notes="" -->


##### 函数定义

---

若返回类型为void的函数(void函数), 其函数体可以为空: 

```C
void print_pun(void)
{
}
```

在程序开发过程中, 留下空函数体是有意义的.

---


<!-- slide data-notes="" -->


##### 程序: 计算平均值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
double average(double a, double b)
{
  return (a + b) / 2;
}
```

</div>

<div style="flex:1;">

定义一个名为average函数, 计算两个double类型数值的平均值:

开头的单词double是average函数的返回类型. 

标识符a和b(函数形式参数)表示调用average需提供的两个数.


---

每个函数都有一个大括号括起来的执行部分, 称为 ==函数体==. 

average函数的函数体由一条`return`语句构成. 

执行这条语句会使函数"返回"到调用它的地方. 

表达式`(a + b) / 2`的值将作为函数的返回值.


---

函数调用需要函数名和实际参数列表. 

average(x, y)是对average函数的调用. 

实际参数用于向函数提供信息. 

调用average(x, y)的效果是把变量x和y的值复制给形式参数a和b. 

实际参数不一定是变量, 任何正确类型的表达式都可以. 

average(5.1, 8.9)和average(x/2, y/3)都是合法的函数调用.

</div>

</div>

<!-- slide data-notes="" -->##### 程序: 计算平均值 (average.c)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
printf("Average: %g\n", average(x, y));
```

```C
avg = average(x, y); 
```

```C{.line-numbers}
/* Computes pairwise averages of three numbers */
 
#include <stdio.h>
 
double average(double a, double b)
{
  return (a + b) / 2;
}
 
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
```

</div>

<div style="flex:1;">

我们把average函数的调用放在需要使用其返回值的地方. 

计算并显示x和y平均值的语句:

不保存average函数的返回值, 程序显示这个值然后丢弃它. 

如果要在稍后程序中用到返回值, 可以把返回值赋值给变量:

---

*average.c*程序读取3个数并使用average函数计算它们的平均值, 每次计算一对数的平均值: 

Enter three numbers: <u>3.5 9.6 10.2</u>
Average of 3.5 and 9.6: 6.55
Average of 9.6 and 10.2: 9.9
Average of 3.5 and 10.2: 6.85

---


---

*average.c*

</div>

</div>
<!-- slide data-notes="" -->##### 程序: 打印倒计时 (countdown.c)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* Prints a countdown */
 
#include <stdio.h>
 
void print_count(int n)
{
  printf("T minus %d and counting\n", n);
} 
 
int main(void)
{
  int i;
 
  for (i = 10; i > 0; --i)
    print_count(i);
 
  return 0;
}
```

</div>

<div style="flex:1;">

---

*countdown.c*

输出: T minus 10 and counting ... T minus 1 and counting

</div>

</div>
<!-- slide data-notes="" -->


##### 程序: 显示倒计时

---

为了指明一个函数 ==没有返回值==, 设定它的返回类型是 ==void==: 

```C
void print_count(int n)
{
  printf("T minus %d and counting\n", n);
}
```

void是一种没有值的类型. 

print_count的调用必须自成一个语句: 

```C
print_count(i);
```

*countdown.c*程序在循环内调用了10次print_count.

---


<!-- slide data-notes="" -->


##### 程序: 显示双关语(改进版)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
void print_pun(void)
{
  printf("To C, or not to C: that is the question.\n");
}
```

```C
print_pun();
```

```C{.line-numbers}
/* Prints a bad pun */
 
#include <stdio.h>
 
void print_pun(void)
{
  printf("To C, or not to C: that is the question.\n");
}
 
int main(void)
{
  print_pun();
  return 0;
}
```

</div>

<div style="flex:1;">

当函数没有参数时, 可将单词void放在函数名后面的括号中:

调用不带实际参数的函数, 只需写出函数名后跟括号(==括号必须==):

*pun2.c*程序测试了print_pun函数.


---

pun2.c



</div>

</div>

<!-- slide data-notes="" -->


##### 函数调用

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
average(x, y)
print_count(i)
print_pun()
```

```C
print_pun;   /*** WRONG ***/
```

```C
print_count(i);
print_pun();
```

```C
avg = average(x, y);
if (average(x, y) > 0)
  printf("Average is positive\n");
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

为了清楚地表明函数的返回值是被故意丢弃的, C 允许在函数调用之前加上(void):

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

假设我们重新编排*average.c*程序, 将average函数的定义放在main函数的定义之后.



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

这是为average函数添加了声明的*average.c*程序.

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

```C{.line-numbers}
int power(int x, int n)
{
  int i, result = 1;

  for (i = 1; i <= n; i++)
    result = result * x;

  return result;
}
```

</div>

<div style="flex:1;">

在C中, 参数是通过值传递的: 

- 调用函数时, 计算出每个实际参数的值, 并将其赋值给相应的形式参数. 

- 函数执行时, 对形式参数的改变不会影响实际参数的值, 形式参数包含的是实际参数值的副本.


---

参数按值传递既有优点也有缺点. 

因为形式参数的修改不会影响到对应的实际参数, 可以把形式参数作为函数内的变量来使用, 从而减少需要的变量的数量.


---

以下函数, 计算数字x的n次幂: $x^n$



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

  while (n-- > 0)
    result = result * x;

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

第 11 章展示了如何使decompose函数奏效.

</div>

</div>

<!-- slide data-notes="" -->


##### 实际参数的转换

---

C允许实际参数的类型与形式参数的类型不匹配的函数调用. 

实际参数如何转换取决于编译器在调用函数之前是否已经遇到函数的原型(或函数的完整定义).


---

编译器在调用之前遇到了原型. 

每个参数的值都隐式转换为相应形式参数的类型, 类似赋值一样. 

示例: 如果将int型的实际参数传递给期望得到double型参数的函数, 则该实际参数将自动转换为double类型.

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
  if (i < 0)
    return;
  printf("%d", i);
}
```

```C
void print_pun(void)
{
  printf("To C, or not to C: that is the question.\n");
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

如果非void函数未能执行return语句, 则程序尝试使用函数的返回值的行为是未定义的.

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

为了指示异常终止, main应该返回一个非0的值. 

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

main中执行return语句是终止程序的一种方法. 

另一个是调用exit函数, 它属于`<stdlib.h>`头. 

传递给exit的实际参数与main的返回值具有相同的含义: 两者都表示程序在终止时的状态. 

为了表示正常终止, 传递0:

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

1. 函数定义由哪两部分组成？`return` 的作用是什么？

2. 函数调用之前必须有什么？函数声明的一般形式是什么？

3. C 语言中参数按什么方式传递？实参和形参是什么关系？

4. `void` 返回类型表示什么？`exit(0)` 与 `return 0` 有什么区别？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


