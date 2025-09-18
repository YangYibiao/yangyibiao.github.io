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



<!-- slide data-notes="" -->


<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 循环

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide vertical=true data-notes="" -->


##### 提纲

---

- while循环

- do-while循环

- for语句

- 退出循环(break, continue, goto)

- 空语句



<!-- slide data-notes="" -->


##### 重复语句

---

C语言的重复语句用于设置循环

循环(loop)是重复执行其他语句(循环体)的一种语句

在 C 语言中, 每个循环都有一个控制表达式

每次执行循环体(循环重复一次)时, 都要对控制表达式求值

如果表达式为真(值不为零), 则循环继续执行



<!-- slide vertical=true data-notes="" -->


##### 重复语句

---

C 提供了三种重复语句: 

- ==while语句== 在循环体执行之前测试控制表达式

- ==do-while语句== 在循环体执行之后测试控制表达式

- ==for语句== 非常适合`递增`或`递减`计数变量的循环



<!-- slide vertical=true data-notes="" -->


##### while语句

---

使用while语句是设置循环的最简单方法

while语句具有以下形式

```C
while (表达式)  语句 
```

- ==表达式== 是 ==控制表达式==, 也叫做 ==条件表达式==

- ==语句== 是 ==循环体==

<span class="yellow">:fa-weixin:</span> 语句可以是`单条语句`, 也可以是使用`{}`括起来的`复合语句`



<!-- slide vertical=true data-notes="" -->


##### while语句

---

while语句示例: 

```C{.line-numbers}
while (i < n) /* 控制表达式 */
  i = i * 2; /* 循环体 */
```

执行while语句时, 首先计算控制表达式

- 如果其值为非零 (true), 则执行循环体并再次测试表达式

- 该过程持续进行, 直到控制表达式的值变为零才停止. 



<!-- slide vertical=true data-notes="" -->


##### while语句

---

使用while语句计算大于或等于数字`n`的最小的2的幂: 

```C{.line-numbers}
i = 1;
while (i < n)
  i = i * 2;
```

当n的值为 10 时, while语句的执行情况:

```C{.line-numbers}
i = 1;          i is now 1         
Is i < n?       Yes; continue      
i = i * 2;      i is now 2         
Is i < n?       Yes; continue      
i = i * 2;      i is now 4         
Is i < n?       Yes; continue      
i = i * 2;      i is now 8         
Is i < n?       Yes; continue      
i = i * 2;      i is now 16        
Is i < n?       No; exit from loop 
```

---


<!-- slide vertical=true data-notes="" -->


##### while语句

---

循环体必须是单独的一条语句

如果需要多个语句, 只要用一对大括号构造成一条复合语句:

```C{.line-numbers}
while (i > 0) {
  printf("T minus %d and counting\n", i);
  i--;
}
```

即使在没有严格要求的时候, 一些程序员也总是使用大括号:

```C{.line-numbers}
while (i < n) {
  i = i * 2;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### while语句

---

以下语句显示一串"倒计数"信息: 

```C{.line-numbers}
i = 10;
while (i > 0) {
  printf("T minus %d and counting\n", i);
  i--;
}
```

最后打印的消息是`T minus 1 and counting`



<!-- slide vertical=true data-notes="" -->


##### while语句

---

对while语句的一些讨论: 

- 当while循环终止时, 控制表达式为假. 因此, 当由i>0控制的循环终止, $i\leq0$ 为真. 

- while循环体可能根本不会执行, 因为控制表达式在循环体执行之前进行判定. 

- while语句通常可以有多种写法. 倒计数循环的更简洁版本: 

```C{.line-numbers}
while (i > 0)
  printf("T minus %d and counting\n", i--);
```

---


<!-- slide vertical=true data-notes="" -->


##### 无限循环

---

如果控制表达式的值始终非零, while语句将无法终止

使用非零常量作为控制表达式来创建无限循环: 

```C
while (1) …
```

这样的while语句将永远执行, 除非它的循环体中含有跳出循环控制的语句(break, goto, return)或调用导致程序终止的函数



<!-- slide vertical=true data-notes="" -->


##### 程序: 打印平方表

---

*square.c*程序使用`while`语句来打印一个平方表

用户指定表中的条目数: 

```
This program prints a table of squares.
Enter number of entries in table: 5
1         1
2         4
3         9
4        16
5        25
```
---


<!-- slide vertical=true data-notes="" -->


##### 程序: 打印平方表

---

*square.c*

```C{.line-numbers}
/* 使用 while 语句打印一个平方表 */
 
#include <stdio.h>
 
int main(void)
{
  int i, n;
  
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
 
  i = 1;
  while (i <= n) {
    printf("%10d%10d\n", i, i * i);
    i++;
  }
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 程序: 数列求和

---

`sum.c`程序对用户输入的整数数列求和: 

该程序对整数数列求和

`输入整数(0 终止):` <u>8•23•71•5•0</u>
`总和是: 107`

该程序需要一个循环, 循环中使用scanf读取一个数字并将其累加



<!-- slide vertical=true data-notes="" -->


##### 程序: 数列求和

---

*sum.c*

```C{.line-numbers}
/* 对数列求和 */
 
#include <stdio.h>
 
int main(void)
{
  int n, sum = 0;
  
  printf("This program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");
 
  scanf("%d", &n);
  while (n != 0) {
    sum += n;
    scanf("%d", &n);
  }
  printf("The sum is: %d\n", sum);
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### do语句

---

do语句的一般形式: 

```C
do 语句 while (表达式);
```

执行do语句时, 先执行循环体, 再计算控制表达式的值

表达式的值不为零 $\rightarrow$ 执行循环体 $\rightarrow$ 计算表达式的值 $\rightarrow$ ....



<!-- slide vertical=true data-notes="" -->


##### do语句

---

将前面的`倒计数`程序用do语句重写: 

```C{.line-numbers}
i = 10;
do {
  printf("T minus %d and counting\n", i);
  --i;
} while (i > 0);
```

do语句和while语句往往没有什么区别

唯一的区别是do语句的循环体总是`至少执行一次`



<!-- slide vertical=false data-notes="" -->


##### do语句

---

<span class="blue">:fa-lightbulb-o:</span> 无论是否需要, 最好给所有的do语句都加上大括号, 没有大括号的do语句很容易被误认为是while语句

```C
do
  printf("T minus %d and counting\n", i--);
while (i > 0);
```

粗心的读者可能会认为单词while是while语句的开始. 



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算整数的位数

---

*numdigits.c*程序计算用户输入的整数的位数: 

```
Enter a nonnegative integer: 60
The number has 2 digit(s).
```

程序会反复将用户输入除以`10`, 直到变为`0`; 除法的次数就是所求的位数

此循环用do语句编写比使用while语句更好, 因为每个整数(包括`0`)都至少有一位数字



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算整数的位数

---

*numdigits.c*

```C{.line-numbers}
/* 计算整数的位数 */
 
#include <stdio.h>
 
int main(void)
{
  int digits = 0, n;
 
  printf("Enter a nonnegative integer: ");
  scanf("%d", &n);
 
  do {
    n /= 10;
    digits++;
  } while (n > 0);
 
  printf("The number has %d digit(s).\n", digits);
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### for语句

---

for语句非常适合使用`计数`变量的循环, 当然它也可以用于其他类型的循环

for语句的一般形式:

```C
for (表达式1; 表达式2; 表达式3) 语句
```

- 表达式1: 初始化表达式

- 表达式2: 条件判断表达式

- 表达式3: 变量递增/减表达式

```C
for (i = 10; i > 0; i--) 
  printf("T minus %d and counting\n", i);
```

---



<!-- slide vertical=true data-notes="" -->


##### for语句

---

for语句与while语句密切相关

除了极少数情况外, for循环总是可以用等效的while循环代替:

```C
表达式1;
while (表达式2) {
  语句
  表达式3;
}
```

表达式1是一个初始化步骤, 只在循环开始之前执行一次



<!-- slide vertical=true data-notes="" -->


##### for语句

---

表达式2 控制循环终止(只要表达式2的值非零, 循环就会继续执行)

表达式3 是每次循环中最后被执行的一个操作

将此模式应用于先前的for循环示例:

```C
i = 10;
while (i > 0) {
  printf("T minus %d and counting\n", i);
  i--;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### for语句

---

研究等效的while语句有助于更好地理解for语句

例如, 如果`i--`被替换为`—-i`会如何？

```C
for (i = 10; i > 0; --i) 
  printf("T minus %d and counting\n", i);
```

等效的while循环表明这种更改对循环没有影响:

```C
i = 10;
while (i > 0) {
  printf("T minus %d and counting\n", i);
  --i;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### for语句

---

for语句中的第一个和第三个表达式都是以语句的方式执行的, 它们的值是无关紧要的——它们有用仅仅是因为有副作用

因此, 这两个表达式通常是赋值递增/递减表达式



<!-- slide vertical=true data-notes="" -->


##### for语句常见用法

---

for语句通常是`向上计数`(==变量递增==)或`向下计数`(==变量递减==)循环的最佳选择

对于向上或向下计数总共n次的情况, for语句通常具有以下形式:

```C{.line-numbers}
/* 从0计数到n – 1 */       for (i = 0; i < n; i++) ...
/* 从1计数到n */           for (i = 1; i <= n; i++) ...
/* 从n – 1倒数到0 */       for (i = n - 1; i >= 0; i--) ...
/* 从n倒数到1 */           for (i = n; i > 0; i--) ...
```

---


<!-- slide vertical=true data-notes="" -->


##### for语句常见用法

---

常见的for语句错误:

- 在控制表达式中把`>`写成`<`(或者相反). 向上计数循环的控制语句应使用`<`或`<=`运算符. 向下计数循环应该使用`>`或`>=`

- 在控制表达式中把`<`、`<=`、`>`或`>=`写成`==`. `i==n`这样的判定没有意义, 因为它的初始值不为真

- 循环次数差一错误, 例如在控制表达式中把`i < n`写为`i <= n`



<!-- slide vertical=true data-notes="" -->


##### for语句省略表达式

---

`C`允许省略`for语句`中的表达式

如果省略第一个表达式, 则在执行循环之前没有初始化的操作:

```C{.line-numbers}
i = 10; 
for (; i > 0; --i) 
  printf("T minus %d and counting\n", i);
```

如果省略第三个表达式, 则循环体需要确保第二个表达式的值最终变为`false`:

```C{.line-numbers}
for (i = 10; i > 0;) 
  printf("T minus %d and counting\n", i--);
```

---


<!-- slide vertical=true data-notes="" -->


##### for语句省略表达式

---

当`for`语句同时省略第一个和第三个表达式时, 它和`while`语句没有任何分别:

```C{.line-numbers}
for (; i > 0;) 
  printf("T minus %d and counting\n", i--);
```

等价于

```C{.line-numbers}
while (i > 0)
  printf("T minus %d and counting\n", i--);
```

`while`版本更清晰, 因此更推荐



<!-- slide vertical=true data-notes="" -->


##### for语句省略表达式

---

如果省略第二个表达式, 则它 ==默认为真值==, 因此for语句不会终止(除非以其他方式停止)

例如, 一些程序员使用下面的for语句来建立一个无限循环:

```C
  for (;;) …
```

---


<!-- slide vertical=true data-notes="" -->


##### C99中的for语句

---

在 `C99` 中, `for`语句中的第一个表达式可以替换为声明

此功能允许程序员声明一个供循环使用的变量(作用域): 

```C
for (int i = 0; i < n; i++)
  …
```

变量i不需要在此语句之前声明



<!-- slide vertical=true data-notes="" -->


##### C99中的for语句

---

由`for`语句声明的变量不能在循环外访问(在循环外不可见):

```C{.line-numbers}
for (int i = 0; i < n; i++) {
  …
  printf("%d", i); /* 合法的; i 在循环内可见 */
  …
}
printf("%d", i); /*** WRONG ***/
```

---


<!-- slide vertical=true data-notes="" -->


##### C99中的for语句

---

让`for`语句声明它自己的循环控制变量通常是一个好主意: 它很方便且程序的可读性更强

但是, 如果程序需要在循环终止后访问该变量, 则必须使用以前的`for`语句格式

`for`语句可以声明多个变量, 只要它们的类型相同:

```C{.line-numbers}
for (int i = 0, j = 0; i < n; i++)
  …
```

---


<!-- slide vertical=true data-notes="" -->


##### 逗号运算符

---

有时, 一个`for`语句可能需要有两个(或多个)初始化表达式, 或者一个在循环中每次递增几个变量的表达式

这种效果可以通过使用逗号表达式作为`for`语句中的第一个或第三个表达式来实现

逗号表达式具有以下形式

```C
表达式1, 表达式2
```

其中表达式1和表达式2是任意两个表达式



<!-- slide vertical=true data-notes="" -->


##### 逗号运算符

---

逗号表达式的计算分两个步骤: 

- 首先, 计算表达式1并丢弃它的值

- 其次, 对表达式2求值; 它的值是整个表达式的值

对表达式1的计算应该有副作用; 如果没有, 则表达式1没有任何作用

- 当计算逗号表达式`++i, i + j`时, `i`首先自增, 然后计算`i + j`

- 如果`i`和`j`的值分别为 `1` 和 `5`, 则表达式的值为 `7`, 并且`i`将自增到 `2`



<!-- slide vertical=true data-notes="" -->


##### 逗号运算符

---

逗号运算符是左结合的, 因此编译器会将

```C
i = 1, j = 2, k = i + j
```
解释为
```C
((i = 1), (j = 2)), (k = (i + j))
```

由于逗号表达式中的左操作数在右操作数之前求值, 因此`i = 1`、 `j = 2`和`k = i + j`将从左到右执行



<!-- slide vertical=true data-notes="" -->


##### 逗号运算符

---

逗号运算符可以将两个表达式`粘合`在一起构成一个表达式

逗号运算可以方便某些宏定义

for语句是可能使用逗号运算符的其他语句

例子:

```C{.line-numbers}
for (sum = 0, i = 1; i <= N; i++)
  sum += i;
```

使用额外的逗号, `for`语句可以初始化更多的变量



<!-- slide vertical=true data-notes="" -->


##### 程序: 打印平方表

---

*square2.c* 通过将其 `while` 循环转换为 `for` 循环来改进 *square.c* 程序(第6.1节)

```C{.line-numbers}
/* 使用 for 语句打印一个平方表 */
 
#include <stdio.h>
 
int main(void)
{
  int i, n;
  
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
 
  for (i = 1; i <= n; i++)
    printf("%10d%10d\n", i, i * i);
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 程序: 打印平方表

---

`for`语句的三个表达式没有任何限制

尽管这些表达式通常对同一个变量进行初始化、判定和更新, 但并不要求它们以任何方式相关

square3.c程序等价于square2.c, 但包含一个`for`语句, 用于初始化一个变量(square)、判定另一个变量(i)并增加第三个变量(odd)

`for`语句的灵活性有时会很有用, 但在这种情况下, 原始程序更清晰



<!-- slide vertical=true data-notes="" -->


##### 程序: 打印平方表

---

*square3.c*

```C{.line-numbers}
/* 使用奇数方法打印一个平方表 */
 
#include <stdio.h>
 
int main(void)
{
  int i, n, odd, square;
  
  printf("This program prints a table of squares.\n");
  printf("Enter number of entries in table: ");
  scanf("%d", &n);
 
  i = 1;
  odd = 3;
  for (square = 1; i <= n; odd += 2) {
    printf("%10d%10d\n", i, square);
    ++i;
    square += odd;
  }
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 退出循环

---

循环的正常退出点是在开始处(如在`while`或`for`语句中)或结束处(do语句)

使用`break`语句, 可以编写一个循环中间退出点的循环, 甚至可以设置多个退出点



<!-- slide vertical=true data-notes="" -->


##### break语句

---

`break语句`可以把程序控制从 `switch` 语句中转移出来, 也可以用于跳出`while`、`do`或`for`循环

检查数字`n`是否为素数的循环可以在找到约数(因子)后立即使用break语句终止循环:

```C{.line-numbers}
for (d = 2; d < n; d++)
  if (n % d == 0)
    break;
```

---


<!-- slide vertical=true data-notes="" -->


##### break语句

---

循环终止后, 可以使用`if语句`来确定循环是提前终止(因此n不是素数)还是正常终止(n是素数):

```C{.line-numbers}
if (d < n)
  printf("%d is divisible by %d\n", n, d);
else
  printf("%d is prime\n", n);
```

---


<!-- slide vertical=true data-notes="" -->


##### break语句

---

`break`语句对于编写退出点位于循环体中间而不是开头或结尾的循环特别有用

读取用户输入并在输入特定值时终止的循环通常属于这种类别:

```C{.line-numbers}
for (;;) {
  printf("Enter a number (enter 0 to stop): ");
  scanf("%d", &n);
  if (n == 0)
    break;
  printf("%d cubed is %d\n", n, n * n * n);
}
```

---


<!-- slide vertical=true data-notes="" -->


##### break语句

---

`break语句`把程序控制从最内层的`while`、`do`、`for`或`switch`转移出去

当这些语句嵌套时, `break语句`只能跳出一层嵌套. 例子:

```C{.line-numbers}
while (…) {
  switch (…) {
    …
    break;
    …
  }
}
```

`break`语句把程序控制从`switch`语句中转移出来, 但是不能跳出`while`循环



<!-- slide vertical=true data-notes="" -->


##### continue语句

---

`continue`语句类似于`break`: 

- `break`将程序控制转移到循环体末尾之后

- `continue`将控制转移到循环体末尾之前

使用`break`会使程序控制跳出循环; 而`continue`会把程序控制保留在循环内

`break`和`continue`之间还有另一个区别: `break`可用于`switch`语句和循环(`while`、`do`和`for`), 而`continue`仅限于循环



<!-- slide vertical=true data-notes="" -->


##### continue语句

---

使用`continue`语句的循环:

```C{.line-numbers}
n = 0;
sum = 0;
while (n < 10) {
  scanf("%d", &i);
  if (i == 0)
    continue;
  sum += i;
  n++;
  /* continue jumps to here */
}
```

---


<!-- slide vertical=true data-notes="" -->


##### continue语句

---

不使用`continue`编写的相同循环:

```C{.line-numbers}
n = 0;
sum = 0;
while (n < 10) {
  scanf("%d", &i);
  if (i != 0) {
    sum += i;
    n++;
  }
}
```

---


<!-- slide vertical=true data-notes="" -->


##### goto语句

---

`goto`语句能够跳转到函数中任何有标号的语句处

标签是放置在语句开头的标识符:

`标识符: 语句`

一个语句可能有多个标号

`goto`语句自身的格式:

```C
goto 标识符;
```

执行语句`goto L;`会跳转到`标签L`之后的语句, 该语句必须与`goto语句`在同一函数中



<!-- slide vertical=true data-notes="" -->


##### goto语句

---

如果 `C` 没有`break语句`, 可以使用`goto语句`退出循环: 

```C{.line-numbers}
for (d = 2; d < n; d++)
  if (n % d == 0)
    goto done;

done:
if (d < n)
  printf("%d is divisible by %d\n", n, d);
else
  printf("%d is prime\n", n);
```

---


<!-- slide vertical=true data-notes="" -->


##### goto语句

---

C中很少需要`goto`语句

`break`、`continue`、`return语句`(本质上是受限的`goto`语句)和`exit函数`足以处理在其他语言中需要`goto`的大多数情况

尽管如此, `goto`语句偶尔还是有用的



<!-- slide vertical=true data-notes="" -->


##### goto语句

---

考虑从包含`switch`语句的循环中退出的问题

`break`语句不会产生预期的效果: 它可以跳出 `switch` 语句, 但无法跳出循环

goto语句解决了这个问题:

```C{.line-numbers}
while (…) {
  switch (…) {
    …
    goto loop_done;   /* break won't work here */
    …
  }
}

loop_done: …
```

`goto`语句对于退出嵌套循环也很有用

<!-- slide vertical=true data-notes="" -->


##### 程序: 账单结算

---

许多简单的交互式程序会向用户提供可供选择的命令列表

输入命令后, 程序会执行对应的操作, 然后提示用户输入下一条命令

这个过程一直持续到用户选择`退出`或`停止`命令

这类程序的核心是循环:

```C{.line-numbers}
for (;;) {
  提示用户输入命令;
  读取命令;
  执行命令;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 程序: 账单结算

---

执行该命令将需要`switch`语句(或级联if语句):

```C{.line-numbers}
for (;;) {
  提示用户输入命令;
  读取命令;
  switch (command) {
    case command1: 执行 操作1 ; break;
    case command2: 执行 操作2 ; break;
      .
      .
      .
    case commandn: 执行 操作n ; break;
    default: 打印错误信息; break;
  }
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 程序: 账单结算

---

*checks.c*程序使用这种类型的循环核对账目

允许用户清除账户余额, 往账户上存钱, 从账户取钱, 显示当前余额, 退出程序



<!-- slide vertical=true data-notes="" -->


##### 程序: 账单结算

---

`*** ACME 账簿结算程序 ***`

```{.line-numbers}
Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit

Enter command: 1
Enter amount of credit: 1042.56
Enter command: 2
Enter amount of debit: 133.79
Enter command: 1
Enter amount of credit: 1754.32
Enter command: 2
Enter amount of debit: 1400
Enter command: 2
Enter amount of debit: 68
Enter command: 2
Enter amount of debit: 50
Enter command: 3
Current balance: $1145.09
Enter command: 4
```

---


<!-- slide vertical=true data-notes="" -->


##### 程序: 账单结算

---

*checking.c*

```C{.line-numbers}
/* 账簿结算 */
 
#include <stdio.h>
 
int main(void)
{
  int cmd;
  float balance = 0.0f, credit, debit;
 
  printf("*** ACME checkbook-balancing program ***\n");
  printf("Commands: 0=clear, 1=credit, 2=debit, ");
  printf("3=balance, 4=exit\n\n");
  for (;;) {
    printf("Enter command: ");
    scanf("%d", &cmd);
    switch (cmd) {
      case 0:
        balance = 0.0f;
        break;
      case 1:
        printf("Enter amount of credit: ");
        scanf("%f", &credit);
        balance += credit;
        break;
      case 2:
        printf("Enter amount of debit: ");
        scanf("%f", &debit);
        balance -= debit;
        break;
      case 3:
        printf("Current balance: $%.2f\n", balance);
        break;
      case 4:
        return 0;
      default:
        printf("Commands: 0=clear, 1=credit, 2=debit, ");
        printf("3=balance, 4=exit\n\n");
        break;
    }
  }
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 空语句

---

语句可以为空: 除了末尾的分号外, 没有其他符号

以下行包含三个语句:

```C
i = 0; ; j = 1;
```

空语句主要有一个好处: 编写空循环体的循环. 



<!-- slide vertical=true data-notes="" -->


##### 空语句

---

考虑以下寻找素数的循环:

```C{.line-numbers}
for (d = 2; d < n; d++)
  if (n % d == 0)
    break;
```

如果 `n % d == 0` 条件被移到循环的控制表达式中, 循环体就会变为空:

```C{.line-numbers}
for (d = 2; d < n && n % d != 0; d++)
  ; /* 空循环体 */
```

为避免混淆, C 程序员习惯上将空语句单独放在一行. 



<!-- slide vertical=true data-notes="" -->


##### 空语句

---

`if`、`while`或`for`语句的圆括号后放置分号会创建空语句

- 示例 1:

```C{.line-numbers}
if (d == 0);                          /*** WRONG ***/
  printf("Error: Division by zero\n");
```

`printf`的调用不在if语句中, 所以不管d是否等于 0 都会执行

- 示例 2:

```C{.line-numbers}
i = 10;
while (i > 0);                        /*** WRONG ***/
{
  printf("T minus %d and counting\n", i);
  --i;
}
```

额外的分号会创建一个无限循环



<!-- slide vertical=true data-notes="" -->


##### 空语句

---

- 示例 3:

```C{.line-numbers}
i = 11;
while (--i > 0);                /*** WRONG ***/
  printf("T minus %d and counting\n", i);
```

循环体只执行一次; 打印的信息是:

`T minus 0 and counting`

- 示例 4:

```C{.line-numbers}
for (i = 10; i > 0; i--);       /*** WRONG ***/
  printf("T minus %d and counting\n", i);
```

同样, 循环体只执行一次, 并打印与示例 3 中相同的信息. 



<!-- slide vertical=true data-notes="" -->


##### 习题1

---

for语句的输出?

```C{.line-numbers}
for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
  printf("%d ", i);
```

---

<!-- slide vertical=true data-notes="" -->

##### 习题2

---

哪条语句和其他语句不等价（假设循环体一样）

```C{.line-numbers}
for (i = 0; i < 10; i++) { printf("%d", i); }
for (i = 0; i < 10; ++i) { printf("%d", i); }
for (i = 0; i++ < 10; ) { printf("%d", i); }
```