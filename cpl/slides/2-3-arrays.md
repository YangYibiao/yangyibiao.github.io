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

## 数组

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)

<!-- slide data-notes="" -->


##### 提纲

---

- 一维数组



<!-- slide data-notes="" -->


##### 标量变量与聚合变量

---

到目前为止, 我们所见的变量都是`标量`: 用于保存单一数据项. 

C 还支持聚合变量, 它可以存储一组一组的数值. 

C中有两种聚合类型: ==数组== 和结构体 

本章的重点是一维数组, 它在 C 语言中的作用比多维数组更大. 


<!-- slide data-notes="" -->

##### 一维数组

---

数组是包含多个数据值的数据结构, 每个数据值具有相同类型.

数据值称为元素, 可以根据它们在数组中的位置选择出来. 

最简单的数组是一维数组, 一维数组中的元素一个接一个地排列在单独一行中: 

<div class="fullborder">

| &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |

</div>

<!-- slide vertical=true data-notes="" -->



##### 一维数组

---

要声明一个数组, 必须指定数组元素的类型和数量: 

```C
int a[10];
```

元素可以是任何类型; 数组的长度可以是任何(整数)常量表达式. 


```C
#define N 10
…
int a[N];
```

可以用宏来定义数组的长度


<!-- slide vertical=true data-notes="" -->



##### 数组下标

---

要访问数组元素, 可在数组名后加上一个方括号括起来的整数值. 

这被称为对数组取下标或进行索引. 

长度为n的数组元素的索引从$0$到$n – 1$. 

若数组a长度为`10`, 元素依次可标记为$a[0], a[1], ..., a[9]$:

<div class="row1-2-column1-10-fullborder">
<!-- <div class="fullborder"> -->

| a[0] | $a[1]$ | $a[2]$ | $a[3]$ | $a[4]$ | $a[5]$ | $a[6]$ | $a[7]$ | $a[8]$ | $a[9]$ |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |

</div>


<!-- slide vertical=true  data-notes="" -->

##### 数组下标

---

形如`a[i]`的表达式是左值, 因此可以像普通变量一样使用它们: 

```C
a[0] = 1;
printf("%d\n", a[5]);
++a[i];
```

如果数组包含T类型的元素, 则每个元素都被视为T类型的变量. 


<!-- slide vertical=true data-notes="" -->



##### 数组下标

---

许多程序包含for循环, 对数组中的每个元素执行一些操作. 

对长度为N的数组a的常见操作示例: 

```C{.line-numbers}
for (i = 0; i < N; i++)
  a[i] = 0;             /* clears a */

for (i = 0; i < N; i++)
  scanf("%d", &a[i]);   /* reads data into a */

for (i = 0; i < N; i++)
  sum += a[i];          /* sums the elements of a */
```

---



<!-- slide vertical=true data-notes="" -->



##### 数组下标

---

C不检查下标的范围; 若超出范围, 程序可能执行不可预知的行为

$n$个元素的==数组索引==是从$0$到$n – 1$, 而不是从$1$到$n$: 

```C
int a[10], i;
for (i = 1; i <= 10; i++)
  a[i] = 0;
```

对于某些编译器, 这种表面上正确的for语句会导致无限循环. 


<!-- slide vertical=true data-notes="" -->

##### 数组下标

---

数组下标可以是任何整数表达式: 

```C
a[i + j * 10] = 0;
```

表达式甚至可能会产生副作用: 

```C
i = 0;
while (i < N)
  a[i++] = 0;
```

---


<!-- slide vertical=true data-notes="" -->

##### 数组下标

---

当数组下标有副作用时要小心: 

```C
i = 0;
while (i < N)
  a[i] = b[i++];
```

表达式`a[i] = b[i++]`访问并修改`i`的值, 导致未定义的行为. 

可通过从下标中移走自增操作来避免该问题: 

```C
for (i = 0; i < N; i++)
  a[i] = b[i];
```

---




<!-- slide data-notes="" -->



##### 程序: 数列反向

---

*reverse.c*程序提示用户输入一串数, 然后以相反的顺序输出这些数: 

输入 10 个号码: <u>34 82 49 102 7 94 23 11 50 31</u>
逆序: 31 50 11 23 94 7 102 49 82 34

程序在读取数字时将它们存储在一个数组中, 然后反向遍历数组, 挨个打印元素. 


<!-- slide vertical=true data-notes="" -->

##### 程序: 数列反向

---

*reverse.c*

```C{.line-numbers}
/* 数列反向 */

#include <stdio.h>
 
#define N 10
 
int main(void)
{
  int a[N], i;
 
  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);
 
  printf("In reverse order:");
  for (i = N - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");
 
  return 0;
}
```

---



<!-- slide data-notes="" -->

##### 数组初始化

---

与其他变量一样, 数组可以在声明时获得一个初始值. 

数组初始化式最常见的格式是用大括号括起来的常量表达式列表, 常量表达式之间用逗号分隔: 

```C
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

---


<!-- slide vertical=true data-notes="" -->

##### 数组初始化

---

如果初始化式比数组短, 则将数组的其余元素赋值为0: 

```C
int a[10] = {1, 2, 3, 4, 5, 6};
/* a 的初始值为 {1, 2、 3、 4、 5、 6、 0, 0, 0, 0} */
```

利用这一特性, 可以轻松地将数组初始化为全0: 

```C
int a[10] = {0};
/* a 的初始值为 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} */
```

大括号内只有一个 0, 因为初始化式完全为空是非法的

初始化式比要初始化的数组长也是非法的

<!-- slide vertical=true data-notes="" -->



##### 数组初始化

---

如果给定了初始化式, 可以省略数组的长度: 

```C
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

编译器利用初始化式的长度来确定数组的大小


<!-- slide vertical=true data-notes="" -->

##### 指定初始化式 (C99)

---

通常, 数组中只有相对较少的元素需要显式初始化.

其他元素可以进行默认赋值, 一个例子: 

```C
int a[15] = {0, 0, 29, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 48};
```

对于大数组, 以这种方式初始化既冗长又容易出错. 


<!-- slide vertical=true data-notes="" -->

##### 指定初始化式 (C99)

---

C99的指定初始化式可用来解决这个问题. 

前面的例子可以使用指定初始化式写为: 

```C
int a[15] = {[2] = 29, [9] = 7, [14] = 48};
```

括号中的数字称为指示符. 



<!-- slide vertical=true data-notes="" -->



##### 指定初始化式 (C99)

---

指定初始值化式可以使赋值更短且更易读. 

此外, 赋值的顺序不再是一个问题. 

前面例子的另一种写法: 

```C
int a[15] = {[14] = 48, [9] = 7, [2] = 29};
```

顺序无关


<!-- slide vertical=true data-notes="" -->



##### 指定初始化式 (C99)

---

指示符必须是整型常量表达式

如果要初始化的数组长度为$n$, 则指示符的值必须在$0$和$n–1$之间

如果省略数组的长度, 则指示符可以是任何非负整数

编译器将从最大指示符推导出数组长度, 以下数组将有$24$个元素: 

```C
int b[] = {[5] = 10, [23] = 13, [11] = 36, [15] = 29};
```

长度自动推导


<!-- slide vertical=true data-notes="" -->

##### 指定初始化式 (C99)

---

初始化式可同时使用逐元素初始化和指定初始化式: 

```C
int c[10] = {5, 1, 9, [4] = 3, 7, 2, [8] = 6};
```

<!-- slide data-notes="" -->



##### 程序: 检查重复数字

---

*repdigit.c*程序检查数中的数字是否出现多次. 

用户输入数后, 程序会显示重复数字或无重复数字: 

输入号码: <u>28212</u>
重复数字

数字28212有一个重复的数字 `2`; 而`9357`这样的数字没有. 


<!-- slide vertical=true data-notes="" -->



##### 程序: 检查重复数字

---

程序使用一个由`10`个布尔值的数组来跟踪数字中出现的数字. 

最初, `digit_seen`数组的每个元素为假. 

程序每次取出n中的一个数字, 并存储在变量`digit`中: 

- 如果`digit_seen[digit]`为真, 则`digit`在n中至少出现两次. 

- 如果`digit_seen[digit]`为假, 则`digit`之前未出现过, 将其设置为真并继续. 

<!-- slide vertical=true data-notes="" -->


##### 程序: 检查重复数字

---

*repdigit.c*

```C{.line-numbers}
/* 检查数字中是否有重复的数字 */
 
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
 
int main(void)
{
  bool digit_seen[10] = {false};
  int digit;
  long n;
 
  printf("Enter a number: ");
  scanf("%ld", &n);
  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit])
      break;
    digit_seen[digit] = true;
    n /= 10;
  }
 if (n > 0)
    printf("Repeated digit\n");
  else
    printf("No repeated digit\n");
 
  return 0;
}
```

---



<!-- slide data-notes="" -->

##### 对数组使用sizeof运算符

---

`sizeof`运算符可以确定数组的大小(字节数)

若数组`a`有`10`个整数, 则`sizeof(a)`为`40`(假定每个整数`4`字节)

我们还可以用`sizeof`来计算数组元素(如`a[0]`)的大小

将数组大小除以元素大小可以得出数组的长度: 

`sizeof(a) / sizeof(a[0])`

<!-- slide vertical=true data-notes="" -->



##### 对数组使用sizeof运算符

---

一些程序员在需要数组长度时使用sizeof表达式. 

如数组`a`清零操作的循环: 

```C
for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  a[i] = 0;
```

即使数组长度在日后需改变, 也无需修改循环

<!-- slide vertical=true data-notes="" -->



##### 对数组使用sizeof运算符

---

编译器可能会为表达式`i < sizeof(a) / sizeof(a[0])`生成警告信息. 

变量i类型可能是int(有符号), 而sizeof返回值类型为size_t无符号. 

将有符号整数与无符号整数进行比较可能危险, 但这里是安全的. 

<!-- slide vertical=true data-notes="" -->


##### 对数组使用sizeof运算符

---

为避免警告, 可将`sizeof(a) / sizeof(a[0])`强制转换为有符号整数: 

```C
for (i = 0; i < (int) (sizeof(a) / sizeof(a[0])); i++)
  a[i] = 0;
```

为数组大小的计算定义一个宏通常很有帮助: 

```C
#define SIZE ((int) (sizeof(a) / sizeof(a[0])))
 
for (i = 0; i < SIZE; i++)
  a[i] = 0;
```

宏表达式的括号需要加上，防止出现运算顺序不一致


<!-- slide data-notes="" -->



##### 程序: 计算利息

---

*interest.c*程序打印一张表格, 显示在几年内以不同利率投资的`100`美元的价值

用户输入利率和投资的年数

投资总价值每年计算一次, 表格将显示出在输入利率和紧随其后的4个更高利率下投资的总价值. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 计算利息

---

程序会话如下: 

```
Enter interest rate: 6
Enter number of years: 5
 
Years     6%     7%     8%     9%     10%
  1     106.00 107.00 108.00 109.00 110.00
  2     112.36 114.49 116.64 118.81 121.00
  3     119.10 122.50 125.97 129.50 133.10
  4     126.25 131.08 136.05 141.16 146.41
  5     133.82 140.26 146.93 153.86 161.05
```

打印n * m的二维数组

<!-- slide vertical=true data-notes="" -->



##### 程序: 计算利息

---

第二行数字的值取决于第一行数字, 因此:

- 将第一行存储在数组中. 

- 使用数组中的值来计算第二行. 

- 对第三行和后面的行重复此过程. 

该程序使用嵌套的for语句. 

- 外层循环从1计数到用户要求的年数. 

- 内层循环将从利率的最低值递增到最高值. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 计算利息

---

*interest.c*

```C{.line-numbers}
/* 打印复利表 */
 
#include <stdio.h>
 
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00
 
int main(void)
{
  int i, low_rate, num_years, year;
  double value[5];
 
  printf("Enter interest rate: ");
  scanf("%d", &low_rate);
  printf("Enter number of years: ");
  scanf("%d", &num_years);
  printf("\nYears");
  for (i = 0; i < NUM_RATES; i++) {
    printf("%6d%%", low_rate + i);
    value[i] = INITIAL_BALANCE;
  }
  printf("\n");
 
  for (year = 1; year <= num_years; year++) {
    printf("%3d    ", year);
    for (i = 0; i < NUM_RATES; i++) {
      value[i] += (low_rate + i) / 100.0 * value[i];
      printf("%7.2f", value[i]);
    }
    printf("\n");
  }
 
  return 0;
}
```

---



<!-- slide data-notes="" -->



##### 变长数组 (C99)

---

在C89中, 数组变量的长度必须由常量表达式指定. 

在C99中, 数组变量的长度也可使用非常量表达式(==变长数组==).

*reverse2.c*程序(*reverse.c*的修改版)展示了这种用法. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 使用变长数组 (C99)

---

*reverse2.c*

```C{.line-numbers}
/* 使用变长数组反转数列 - 仅限 C99 */
 
#include <stdio.h>
 
int main(void)
{
  int i, n;
 
  printf("How many numbers do you want to reverse? ");
  scanf("%d", &n);
 
  int a[n];   /* C99 only - length of array depends on n */

  printf("Enter %d numbers: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  printf("In reverse order:");
  for (i = n - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->

##### 变长数组 (C99)

---

*reverse2.c*程序中的数组a是变长数组. 

变长数组的长度是在程序执行时计算的. 

变长数组的主要优点是程序可以准确计算需要多少元素. 

如果程序员指定长度, 数组可能过长(浪费内存)或过短(导致出错). 



<!-- slide vertical=true data-notes="" -->


##### 变长数组 (C99)

---

变长数组的长度不一定要用变量来指定. 任意表达式都可以: 

```C
int a[3*i+5];
int b[j+k]; 
```
