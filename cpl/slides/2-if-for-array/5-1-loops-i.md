---
presentation:
  width: 1280
  height: 720
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

## 循环结构 (上)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 重复语句与 while

- do-while 语句

- break 与 continue

- 案例: 平方表、数列求和、整数的位数

---


<!-- slide data-notes="" -->


##### 重复语句

---

C语言的重复语句用于设置循环

循环(loop)是重复执行其他语句(循环体)的一种语句

在 C 语言中, 每个循环都有一个控制表达式

每次执行循环体(循环重复一次)时, 都要对控制表达式求值; 如果表达式为真(值不为零), 则循环继续执行

C 提供了三种重复语句: 

- ==while语句== 在循环体执行之前测试控制表达式

- ==do-while语句== 在循环体执行之后测试控制表达式

- ==for语句== 非常适合`递增`或`递减`计数变量的循环

---


<!-- slide data-notes="" -->


##### while语句

---

`while` 是设置循环最简单的方法, 形式为 `while (表达式) 语句`

- ==表达式==是==控制表达式==(条件表达式); ==语句==是==循环体==, 可为单条语句或 `{}` 复合语句

while语句示例: 

```C{.line-numbers}
while (i < n) /* 控制表达式 */
  i = i * 2; /* 循环体 */
```

执行while语句时, 首先计算控制表达式

- 非零 (true) 就执行循环体并再次测试; 持续到控制表达式变为零才停止

---

<!-- slide data-notes="" -->


##### while语句

---

用 `while` 计算 ≥ `n` 的最小 2 的幂: ```C{.line-numbers}
i = 1;
while (i < n)
  i = i * 2;
```

当n的值为 10 时, while语句的执行情况:

<div style="font-size:0.8em;">

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

</div>

---

<!-- slide data-notes="" -->


##### while语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C{.line-numbers}
while (i > 0) {
  printf("T minus %d and counting\n", i);
  i--;
}
```

```C{.line-numbers}
while (i < n) {
  i = i * 2;
}
```

```C{.line-numbers}
i = 10;
while (i > 0) {
  printf("T minus %d and counting\n", i);
  i--;
}
```

</div>

<div style="flex:1;">

循环体必须是单独的一条语句

如果需要多个语句, 只要用一对大括号构造成一条复合语句:

即使在没有严格要求的时候, 一些程序员也总是使用大括号:

以下语句显示一串"倒计数"信息:

最后打印的消息是`T minus 1 and counting`

</div>

</div>

<!-- slide data-notes="" -->


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

<!-- slide data-notes="" -->


##### 无限循环

---

如果控制表达式的值始终非零, while语句将无法终止

使用非零常量作为控制表达式来创建无限循环: 

```C
while (1) …
```

这样的while语句将永远执行, 除非它的循环体中含有跳出循环控制的语句(break, goto, return)或调用导致程序终止的函数

---

<!-- slide data-notes="" -->


##### 程序: 打印平方表

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```
This program prints a table of squares.
Enter number of entries in table: 5
1         1
2         4
3         9
4        16
5        25
```

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

</div>

<div style="flex:1;">

`square.c`程序使用`while`语句来打印一个平方表

用户指定表中的条目数:



</div>

</div>

<!-- slide data-notes="" -->


##### 程序: 数列求和

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

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

</div>

<div style="flex:1;">

`sum.c`程序对用户输入的整数数列求和: 

`输入整数(0 终止):` <u>8•23•71•5•0</u>
`总和是: 107`

该程序需要一个循环, 循环中使用scanf读取一个数字并将其累加



</div>

</div>

<!-- slide data-notes="" -->


##### do语句

---

do 语句的一般形式: `do 语句 while (表达式);`

执行do语句时, 先执行循环体, 再计算控制表达式的值

表达式的值不为零 $\rightarrow$ 执行循环体 $\rightarrow$ 计算表达式的值 $\rightarrow$ ....

将前面的`倒计数`程序用do语句重写: 

```C{.line-numbers}
i = 10;
do {
  printf("T minus %d and counting\n", i);
  --i;
} while (i > 0);
```

与 `while` 的唯一区别: do 的循环体==至少执行一次==

---

<!-- slide data-notes="" -->


##### do语句

---

<span class="blue">:fa-weixin:</span> 无论是否需要, 最好给所有的do语句都加上大括号, 没有大括号的do语句很容易被误认为是while语句

```C
do
  printf("T minus %d and counting\n", i--);
while (i > 0);
```

粗心的读者可能会认为单词while是while语句的开始. 

---

<!-- slide data-notes="" -->


##### 程序: 计算整数的位数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.58em;">

```
Enter a nonnegative integer: 60
The number has 2 digit(s).
```

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

</div>

<div style="flex:1;">

`numdigits.c`程序计算用户输入的整数的位数:

程序会反复将用户输入除以`10`, 直到变为`0`; 除法的次数就是所求的位数

此循环用do语句编写比使用while语句更好, 因为每个整数(包括`0`)都至少有一位数字



</div>

</div>

<!-- slide data-notes="" -->


##### break语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.65em;">

```C{.line-numbers}
for (d = 2; d < n; d++)
  if (n % d == 0)
    break;
```

```C{.line-numbers}
if (d < n)
  printf("%d is divisible by %d\n", n, d);
else
  printf("%d is prime\n", n);
```

</div>

<div style="flex:1;">

`break语句`可以把程序控制从 `switch` 语句中转移出来, 也可以用于跳出`while`、`do`或`for`循环

检查数字`n`是否为素数的循环可以在找到约数(因子)后立即使用break语句终止循环:

循环终止后, 可以使用`if语句`来确定循环是提前终止(因此n不是素数)还是正常终止(n是素数):



</div>

</div>

<!-- slide data-notes="" -->


##### break语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.65em;">

```C{.line-numbers}
for (;;) {
  printf("Enter a number (enter 0 to stop): ");
  scanf("%d", &n);
  if (n == 0)
    break;
  printf("%d cubed is %d\n", n, n * n * n);
}
```

```C{.line-numbers}
while (…) {
  switch (…) {
    …
    break;
    …
  }
}
```

</div>

<div style="flex:1;">

`break`语句对于编写退出点位于循环体中间而不是开头或结尾的循环特别有用

读取用户输入并在输入特定值时终止的循环通常属于这种类别:

`break语句`把程序控制从最内层的`while`、`do`、`for`或`switch`转移出去; 当这些语句嵌套时, `break语句`只能跳出一层嵌套:

`break`语句把程序控制从`switch`语句中转移出来, 但是不能跳出`while`循环

</div>

</div>

<!-- slide data-notes="" -->


##### continue语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.55em;">

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

</div>

<div style="flex:1;">

`continue`语句类似于`break`: 

- `break`将程序控制转移到循环体末尾之后

- `continue`将控制转移到循环体末尾之前

使用`break`会使程序控制跳出循环; 而`continue`会把程序控制保留在循环内

`break`和`continue`之间还有另一个区别: `break`可用于`switch`语句和循环(`while`、`do`和`for`), 而`continue`仅限于循环

使用`continue`语句的循环:

不使用`continue`编写的相同循环:



</div>

</div>

<!-- slide data-notes="" -->

##### 空语句: 一个分号的代价

---

==空语句==: 只有一个分号 `;`, 什么都不做

- 意外写出的空语句是经典 bug——多打的一个分号会让循环体/if 体变成"空":

```C
while (i < n);        /* BUG: 循环体是空语句 → 死循环! */
  sum += a[i++];      /* 这行其实只执行一次 */

if (d == 0);          /* BUG: if 的体是空语句 → 条件成立时什么都不做 */
  printf("zero");
```

- 编译器通常会警告 (`empty body in a while`), 但==不要依赖警告==

- 好习惯: ==循环体和 if 后面永远加大括号==, 哪怕只有一条语句

---

<!-- slide data-notes="" -->##### 课堂小测

---

1. while 和 do-while 唯一的区别是什么？

2. `while (1)` 是什么循环？怎么让它停下来？

3. break 和 continue 分别把控制转移到哪里？

4. 输入一个非负整数，输出它的位数（用 do-while），关键思路是什么？

<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


