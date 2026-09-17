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

## 一维数组

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 为什么需要数组

- 一维数组: 声明、下标、初始化

- 案例: 数列反向、找最高分、检查重复数字

- sizeof 与变长数组

---


<!-- slide data-notes="" -->


##### 标量变量与聚合变量

---

到目前为止, 我们所见的变量都是`标量`: 用于保存单一数据项. 

C 还支持聚合变量, 它可以存储一组一组的数值. 

C中有两种聚合类型: ==数组== 和结构体 

本章的重点是一维数组, 它在 C 语言中的作用比多维数组更大. 

---

---


<!-- slide data-notes="" -->


##### 一维数组

---

数组是包含多个==同类型==数据值的数据结构, 元素按位置选择; 一维数组的元素一个接一个排成一行: 

<div class="fullborder">

| &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |

</div>

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

---

---


<!-- slide data-notes="" -->##### 数组下标

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">



</div>

<div style="flex:1;">

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

</div>

</div>
<!-- slide data-notes="" -->##### 数组下标

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
a[0] = 1;
printf("%d\n", a[5]);
++a[i];
```

```C{.line-numbers}
for (i = 0; i < N; i++)
  a[i] = 0;             /* clears a */

for (i = 0; i < N; i++)
  scanf("%d", &a[i]);   /* reads data into a */

for (i = 0; i < N; i++)
  sum += a[i];          /* sums the elements of a */
```

```C
int a[10], i;
for (i = 1; i <= 10; i++)
  a[i] = 0;
```

</div>

<div style="flex:1;">

形如`a[i]`的表达式是左值, 因此可以像普通变量一样使用它们:

如果数组包含T类型的元素, 则每个元素都被视为T类型的变量. 

---


许多程序包含for循环, 对数组中的每个元素执行一些操作. 

对长度为N的数组a的常见操作示例:

C不检查下标的范围; 若超出范围, 程序可能执行不可预知的行为

$n$个元素的==数组索引==是从$0$到$n – 1$, 而不是从$1$到$n$:

对于某些编译器, 这种表面上正确的for语句会导致无限循环. 

</div>

</div>
<!-- slide data-notes="" -->##### 数组下标

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
a[i + j * 10] = 0;
```

```C
i = 0;
while (i < N)
  a[i++] = 0;
```

```C
i = 0;
while (i < N)
  a[i] = b[i++];
```

```C
for (i = 0; i < N; i++)
  a[i] = b[i];
```

</div>

<div style="flex:1;">

数组下标可以是任何整数表达式:

表达式甚至可能会产生副作用:

当数组下标有副作用时要小心:

表达式`a[i] = b[i++]`访问并修改`i`的值, 导致未定义的行为. 

可通过从下标中移走自增操作来避免该问题:

*reverse.c*程序提示用户输入一串数, 然后以相反的顺序输出这些数: 

输入 10 个号码: <u>34 82 49 102 7 94 23 11 50 31</u>
逆序: 31 50 11 23 94 7 102 49 82 34

程序在读取数字时将它们存储在一个数组中, 然后反向遍历数组, 挨个打印元素. 

</div>

</div>
<!-- slide data-notes="" -->


##### 程序: 数列反向

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

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

```C
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
```

</div>

<div style="flex:1;">

*reverse.c*

与其他变量一样, 数组可以在声明时获得一个初始值. 

数组初始化式最常见的格式是用大括号括起来的常量表达式列表, 常量表达式之间用逗号分隔:



</div>

</div>

<!-- slide data-notes="" -->


##### 程序: 找最高分

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
#include <stdio.h>
int main(void)
{
  int numbers[5] = {23, 56, 78, 13, 11};
  int max = numbers[0];

  for (int i = 1; i < 5; i++)
    if (numbers[i] > max)
      max = numbers[i];

  printf("max is %d\n", max);
  return 0;
}
```

</div>

<div style="flex:1;">

还记得第 1 周的"找最高分"吗? 现在用数组把它==真正写出来==:

第 1 周的四步算法: 假设第一个 → 逐个比较 → 更大就替换 → 输出

- 循环 + 数组 = 处理成百上千个数据的起点

</div>

</div>

<!-- slide data-notes="" -->##### 数组初始化

---

- 初始化式比数组短 → 其余元素==自动赋 0==: `int a[10] = {1, 2, 3};` (利用此特性可全 0 初始化: `int a[10] = {0};`; 初始化式完全为空非法, 比数组长也非法)

- 给定了初始化式可省略数组长度: `int a[] = {1, 2, 3};`——编译器从初始化式推出大小

- 只有相对较少的元素需要显式初始化时, 其他默认赋值: `int a[15] = {0, 0, 29, 0, 0, 0, 0, 0, 0, 7};`——对大数组这样写冗长易错<!-- slide data-notes="" -->##### 指定初始化式 (C99)

---

- C99 的==指定初始化式==解决冗长问题: `int a[15] = {[2] = 29, [9] = 7};`——括号中的数字称为==指示符==

- 赋值更短更易读, 且==顺序无关==: `int a[15] = {[9] = 7, [2] = 29};`

- 指示符须为整型常量表达式, 取值 0 ~ n-1; 省略长度时可为任意非负整数, 编译器从==最大指示符==推出长度: `int b[] = {[23] = 5};` → 24 个元素<!-- slide data-notes="" -->


##### 程序: 检查重复数字

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

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

</div>

<div style="flex:1;">

程序使用一个由`10`个布尔值的数组来跟踪数字中出现的数字. 

最初, `digit_seen`数组的每个元素为假. 

程序每次取出n中的一个数字, 并存储在变量`digit`中: 

- 如果`digit_seen[digit]`为真, 则`digit`在n中至少出现两次. 

- 如果`digit_seen[digit]`为假, 则`digit`之前未出现过, 将其设置为真并继续. 

---


*repdigit.c*

`sizeof`运算符可以确定数组的大小(字节数)

若数组`a`有`10`个整数, 则`sizeof(a)`为`40`(假定每个整数`4`字节)

我们还可以用`sizeof`来计算数组元素(如`a[0]`)的大小

将数组大小除以元素大小可以得出数组的长度: 

`sizeof(a) / sizeof(a[0])`


---

</div>

</div>

<!-- slide data-notes="" -->##### 对数组使用sizeof运算符

---

- 用 `sizeof` 表达数组长度: `for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)` 清零——日后改长度无需改循环

- 可能告警: `i` 是 int (有符号), `sizeof` 返回 size_t (无符号); 此处安全, 也可强转避免: `(int) (sizeof(a) / sizeof(a[0]))`

- 为数组大小定义宏: `#define SIZE ((int) (sizeof(a) / sizeof(a[0])))`——宏要加括号, 防止运算顺序不一致<!-- slide data-notes="" -->


##### 变长数组 (C99)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

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

```C
int a[3*i+5];
int b[j+k]; 
```

</div>

<div style="flex:1;">

*reverse2.c*

*reverse2.c*程序中的数组a是变长数组. 

变长数组的长度是在程序执行时计算的. 

变长数组的主要优点是程序可以准确计算需要多少元素. 

如果程序员指定长度, 数组可能过长(浪费内存)或过短(导致出错). 

---


变长数组的长度不一定要用变量来指定. 任意表达式都可以:



</div>

</div>

<!-- slide data-notes="" -->

##### 程序: 计算利息 (数组保存中间状态)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
#define NUM_RATES 5
#define NUM_YEARS 5

double balance[NUM_RATES];
for (int r = 0; r < NUM_RATES; r++) {
  balance[r] = 100.0;
  for (int y = 1; y <= NUM_YEARS; y++) {
    balance[r] = balance[r] * (1 + 0.01 * (r + 3));   /* 每年复利 */
    printf("%8.2f", balance[r]);
  }
  printf("\n");
}
```

</div>

<div style="flex:1;">

本金 100 元, 5 种利率各存 5 年, 列出每年的余额:

关键: ==第 y+1 年的余额依赖第 y 年==——每一年的中间值都要==存下来==

- 数组的第三种用途: 除了"存一批数据"和"批量处理", 还能==保存中间状态==

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `int a[10];` 中数组元素的下标范围是什么？越界会发生什么？

2. `int a[] = {1, 2, 3};` 中 a 的长度是多少？怎么用 sizeof 计算元素个数？

3. 写代码: 找出数组 {5, 2, 9, 1} 中的最小值。

4. C99 的变长数组 (VLA) 长度可以是什么？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


