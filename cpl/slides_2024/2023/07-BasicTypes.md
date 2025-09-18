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

## 基本类型

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### yangyibiao@nju.edu.cn


---

<!-- slide vertical=true data-notes="" -->


##### 提纲

---

- 整数类型

- 浮点类型

- 字符类型

- 类型转换

- 类型定义

- sizeof运算符

---



<!-- slide vertical=true data-notes="" -->



##### 基本类型

---

C 的基本(内置)类型: 

- 整数类型, 包括长整型、短整型和无符号整型

- 浮点类型(float, double, long double)

- char

- _Bool(C99)



<!-- slide data-notes="" -->


##### 整数类型

---

C 支持两种完全不同的数值类型: 整数类型和浮点类型

- 整数类型的值是整数

- 浮点类型的值可以有小数部分

整数类型又分为两类: 有符号型和无符号型



<!-- slide vertical=true data-notes="" -->


##### 有符号整数和无符号整数

---

有符号整数: 如果为正数或`0`, 最左边位(符号位)为`0`; 如果为负数, 则符号位为`1`

- 最大的`16`位整数的二进制表示形式是$0111111111111111$, 其值为$32,767$ ($2^{15} – 1$)

- 最大的`32`位整数是$01111111111111111111111111111111$, 其值为$2,147,483,647$ ($2^{31} – 1$)

无符号位的整数(最左边的位是数值的一部分)称为无符号整数

- 最大的`16`位无符号整数是$65,535$ ($2^{16} – 1$)

- 最大的`32`位无符号整数是$4,294,967,295$ ($2^{32} – 1$)



<!-- slide vertical=true data-notes="" -->


##### 有符号整数和无符号整数

---

默认情况下, ==C==中整数变量都是有符号的——最左位是符号位

要告诉编译器变量没有符号位, 需要把它声明为`unsigned`类型

无符号整数主要用于系统编程和底层与机器相关的应用



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

- `int`类型通常是`32`位, 但在老的CPU上可能是`16`位

- 长整型(`long`)可能比普通整型有更多位; 短整型(`short`)可能有更少的位

- 说明符`long`和`short`以及`signed`和`unsigned`可以与`int`组合起来

只有6种组合可以产生不同的类型: 

```C
short int         unsigned short int
int unsigned      int
long int          unsigned long int
```

说明符的顺序无关紧要, 单词`int`可以省略(`long int`可以缩写为`long`)

---

<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

6种整数类型中的每一种表示的取值范围因机器而异

==C==标准要求:

- `short int`、`int`和`long int`都必须都覆盖一个确定的最小取值范围

- `int`不得短于`short int`, `long int`不得短于`int`

---


<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

`16`位机上整数类型通常的取值范围: 

<div class="fullborder">

| 类型                | 最小值            | 最大值         |
| :--                | :--              | :--           |
| short int          | $–32,768$        | $32,767$        |
| unsigned short int | $0$              | $65,535$        |
| int                | $–32,768$        | $32,767$        |
| unsigned int       | $0$              | $65,535$        |
| long int           | $–2,147,483,648$ | $2,147,483,647$ |
| unsigned long int  | $0$              | $4,294,967,295$ |

</div>

---



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

`32` 位机上整数类型通常的取值范围: 

<div class="fullborder">

| 类型                | 最小值          | 最大值         |
| :--                | :--               | :--           |
| short int          | $–32,768$           | $32,767$         |
| unsigned short int | $0$                 | $65,535$         |
| int                | $–2,147,483,648$    | $2,147,483,647$  |
| unsigned int       | $0$                 | $4,294,967,295$  |
| long int           | $–2,147,483,648$    | $2,147,483,647$  |
| unsigned long int  | $0$                 | $4,294,967,295$  |

</div>


---

<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

64 位机上整数类型通常的取值范围: 

<div class="fullborder">

|  类型  |    最小值 | 最大值 |
| :-- | :-- | :-- |
| short int          | $–32,768$        | $32,767$ |
| unsigned short int | $0$              | $65,535$ |
| int                | $–2,147,483,648$ | $2,147,483,647$ |
| unsigned int       | $0$              | $4,294,967,295$ |
| long int           | $–2^{63}$        | $2^{63}–1$ |
| unsigned long int  | $0$              | $2^{64}–1$ |

</div>

`<limits.h>`头文件定义了每种整数类型最小值和最大值的宏



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

C99 提供了两个额外的标准整数类型: `long long int, unsigned long long int`

这两个`long long`类型都至少`64`位宽

`long long int`类型值的范围通常为 $–2^{63} (–9,223,372,036,854,775,808)$ 到 $2^{63} – 1 (9,223,372,036,854,775,807)$

`unsigned long long int`类型值的范围通常为 $0$ 到 $2^{64} – 1 (18,446,744,073,709,551,615)$


---

<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

C99中把`short int, int, long int, long long int`类型(以及signed char类型)称为标准有符号整型

`unsigned short int, unsigned int, unsigned long int, unsigned long long int`类型(以及unsigned char类型和_Bool类型)称为标准无符号整型

除了标准的整数类型以外, C99 标准还允许在具体实现时定义扩展的整数类型(包括有符号的和无符号的)



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

常量是在程序中以文本形式出现的数

C 允许用`十进制(基数为10)`、`八进制(基数为8)`和`十六进制(基数为16)`书写整数常量



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

八进制数仅使用数字`0`到`7`

- 八进制数中的每一位表示一个`8`的幂

- 八进制数 237 表示成十进制数就是 
$2 × 8^2 + 3 × 8^1 + 7 × 8^0 = 128 + 24 + 7 = 159$

十六进制数是用数字`0~9`加上字母`A~F`(代表`10~15`)书写的

- 十六进制数中的每一位表示一个`16`的幂

- 十六进制数 1AF 的十进制数值为 
$1 × 16^2 + 10 × 16^1 + 15 × 16^0 = 256 + 160 + 15 = 431$



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

十进制常量包含0~9 中的数字, 但不能以零开头: 
`15    255    32767`

八进制常量只包含0~7中的数字, 并且必须以零开头: 
`017   0377   077777`

十六进制常量包含`0~9`中的数字和`a~f`中的字母, 且总以0x开头: 
`0xf   0xff   0x7fff`

十六进制常量中的字母可以是大写, 也可以是小写: 
`0xff  0xfF   0xFf   0xFF   0Xff   0XfF   0XFf   0XFF`



<!-- slide vertical=true data-notes="" -->


##### 整数类型

---

十进制整数常量的类型通常是`int`

如果常量的值太大而无法存储在`int`型中, 就用`long int`类型

如果出现`long int`不够用的罕见情况, 编译器会用`unsigned long int`作为最后的尝试

对于八进制或十六进制常量, 规则略有不同: 编译器将依次尝试`int, unsigned int, long int, unsigned long int`类型, 直到找到能表示该常数的类型



<!-- slide vertical=true data-notes="" -->


##### 整数常量

---

强制编译器把常量作为长整型来处理, 需在后面加上字母L(或l):
`15L  0377L  0x7fffL`

为了指明是无符号常数, 可以在常量后面加上字母U(或u): 
`15U  0377U  0x7fffU`

L和U可以结合使用: 
`0xffffffffUL`

L和U的顺序和大小写无所谓



<!-- slide vertical=true data-notes="" -->


##### C99 中的整数常量

---

以LL或ll(两个字母的大小写必须匹配)结尾的整数常量是`long long int`型的

在LL或ll之前或之后添加字母U(或u)表示该整数常量是`unsigned long long int`型

C99 确定整数常量类型的规则与 C89 有些不同

对于没有后缀(`U, u, L, l, LL, ll`)的十进制常量, 其类型是`int, long, long long int`中能表示该值的`最小`类型



<!-- slide vertical=true data-notes="" -->


##### C99 中的整数常量

---

对于八进制或十六进制常量, 可能的类型顺序是`int、unsigned int、long int、unsigned long int、long long int和unsigned long long int`

常量后面的任何后缀都会改变可能类型的列表

- 以U(或u)结尾的常量类型一定是`unsigned int`、`unsigned long int`和`unsigned long long int`中的一种

- 以L(或l)结尾的十进制常量类型一定是`long int`或 `long long int`



<!-- slide vertical=true data-notes="" -->


##### 整数溢出

---

整数溢出是对整数执行算术运算时, 其结果因为太大而无法表示

- 对两个int值进行算术运算时, 结果必须仍然能用int类型来表示

- 否则(表示结果所需的位数太多), 就会发生溢出



<!-- slide vertical=true data-notes="" -->


##### 整数溢出

---

整数溢出时的行为要根据操作数是有符号型还是无符号型来确定

==有符号整数运算==中发生溢出时, 行为是未定义的(不确定的)

==无符号整数运算==中发生溢出时, 结果是有定义的: 

- 对$2^{n}$取模, `n`是用于存储结果的位数(如一般`unsigned int`是`32`位)



<!-- slide vertical=true data-notes="" -->


##### 读/写整数

---

读写无符号整数、短整数和长整数需要一些新的转换说明符

读写无符号整数时, 使用字母u、o或x代替转换说明中的d

```C{.line-numbers}
unsigned int u;
 
scanf("%u", &u);   /* 以10为基数读取u */
printf("%u", u);   /* 以10为基数输出u */
scanf("%o", &u);   /* 以8为基数读取u */
printf("%o", u);   /* 以8为基数输出u */
scanf("%x", &u);   /* 以16为基数读取u */
printf("%x", u);   /* 以16为基数输出u */
```

---

<!-- slide vertical=true data-notes="" -->


##### 读/写整数

---

读写短整数时, 在d、o、u或x前面加上字母h: 

```C{.line-numbers}
short s;
scanf("%hd", &s);
printf("%hd", s);
```

读写长整数时, 在d、o、u或x前面加上字母l: 

```C{.line-numbers}
long l;
scanf("%ld", &l);
printf("%ld", l);
```

读写长长整数(仅限 C99)时, 在d、o、u或x前面加上字母ll: 

```C{.line-numbers}
long long ll;
scanf("%lld", &ll);
printf("%lld", ll);
```

---

<!-- slide vertical=true data-notes="" -->


##### 程序: 数列求和(改进版)

---

*sum.c*程序(第 6 章)对整数数列求和

该程序的一个问题是sum的值可能超出int型变量允许的最大值

如果程序在整数长度为16位机器上运行, 可能会发生以下情况: 

This program sums a series of integers.
Enter integers (0 to terminate): <u>10000 20000 30000 0</u>
The sum is: -5536

当有符号整数发生溢出时, 结果是未定义的

可以把变量改换成long型来改进程序



<!-- slide vertical=true data-notes="" -->


##### 程序: 数列求和(改进版)

---

*sum2.c*

```C{.line-numbers}
/* 对数列求和(使用长整型变量)*/
 
#include <stdio.h>
 
int main(void)
{
  long n, sum = 0;
 
  printf("This program sums a series of integers.\n");
  printf("Enter integers (0 to terminate): ");
 
  scanf("%ld", &n);
  while (n != 0) {
    sum += n;
    scanf("%ld", &n);
  }
  printf("The sum is: %ld\n", sum);
 
  return 0;
}
```

---

<!-- slide vertical=true data-notes="" -->


##### 浮点类型

---

C 提供了3种浮点类型, 对应三种不同的浮点格式: 

- float &emsp; &emsp; &emsp; &emsp; 单精度浮点数

- double &emsp; &emsp; &emsp;&emsp; 双精度浮点

- long double &emsp; &emsp; 扩展精度浮点数



<!-- slide vertical=true data-notes="" -->


##### 浮点类型

---

当精度要求不严格时, float是合适的

double为大多数程序提供了足够的精度

long double很少使用

C 标准没有说明float、double和long double类型提供的精度到底是多少, 因为不同的计算机可以用不同的方法存储浮点数

大多数现代计算机都遵循 IEEE 标准 754(即IEC 60559)的规范



<!-- slide vertical=true data-notes="" -->


##### IEEE 浮点标准

---

IEEE标准由IEEE开发

它提供了两种主要的浮点数格式: 单精度(32 位)和双精度(64 位)

数值以科学记数法的形式存储, 每一个数都由三部分组成: 符号、指数和小数

在单精度格式中, 指数长度为`8`位, 而小数为`23`位最大值约为$3.40 × 10^{38}$, 精度是6 个十进制数字



<!-- slide vertical=true data-notes="" -->


##### 浮点类型

---

根据 IEEE 标准实现时float和double的特征: 

<div class="fullborder">

| 类型   | 最大值                    | 最小值                | 精度         | 
| :--    | :--                     | :--                  | :--          |
| float  | $1.17549 × 10^{–38}$    | $3.40282 × 10^{38}$  |  6位    |
| double | $2.22507 × 10^{–308}$   | $1.79769 × 10^{308}$ | 15位 |

</div>

在不遵循 IEEE 标准的计算机上, 此表无效

事实上, 在某些机器上, float可以有和double相同的数值集合, 或者double可以有和long double相同的数值集合



<!-- slide vertical=true data-notes="" -->


##### 浮点类型

---

定义浮点类型特征的宏可以在`<float.h>`头文件中找到

在 C99 中, 浮点类型分为两类

实浮点类型(`float, double, long double`)

复数类型(`float _Complex, double _Complex, long double _Complex`)



<!-- slide vertical=true data-notes="" -->


##### 浮点常量

---

浮点常量可以有多种书写方式

书写数字 `57.0` 的有效方式: 

```C
57.0  57.  57.0e0  57E0  5.7e1  5.7e+1 .57e2  570.e-1
```

浮点常量必须包含小数点或指数; 指数指明了对前面的数进行缩放所需的10 的幂次

指数必须以字母E(或e)开头可选符号+或-在E(或e)之后



<!-- slide vertical=true data-notes="" -->


##### 浮点常量

---

默认情况下, 浮点常量以双精度数的形式存储

要表明只需要单精度, 可以在常量的末尾加上字母F或f, 如57.0F

要表明一个常量必须以long double格式存储, 可以在常量的末尾加上字母L或l, 如57.0L



<!-- slide vertical=true data-notes="" -->


##### 读/写浮点数

---

转换说明符`%e`、`%f`和`%g`用于读写单精度浮点数

读取double类型的值时, 将字母l放在e、f或g前面: 

```C
double d;

scanf("%lf", &d);
```

<span class="yellow">:fa-weixin:</span> 字母 $l$ 仅用于scanf函数格式串, 不用于printf函数格式串

- printf函数格式串中, 转换e、f和g可用于写float或double类型的值

- 读写long double类型的值时, 将字母L放在e、f或g前



<!-- slide vertical=true data-notes="" -->


##### 字符类型

---

唯一还没讨论的基本类型是char类型

char类型的值可能因计算机而异, 不同的计算机可能有不同的字符集



<!-- slide vertical=true data-notes="" -->


##### 字符集

---

最常用的字符集是ASCII(美国信息交换标准码)字符集, 它用7位代码表示128个字符 

ASCII码中, 数字`0~9`用`0110000~0111001`码来表示, 大写字母`A~Z`用`1000001~1011010`码表示

<div class="fulltable">

| 数字  | 码   | 数字  | 码   |
| :--: | :--: | :--: | :--: |
| 0 | 0110000 | 5 | 0110100 |
| 1 | 0110001 | 6 | 0110101 | 
| 2 | 0110010 | 7 | 0110111 |
| 3 | 0110011 | 8 | 0111000 |
| 4 | 0110100 | 9 | 0111001 |

</div>

---

<!-- slide vertical=true data-notes="" -->


##### 字符集

---

char类型的变量可以用任何单字符赋值: 

```C
char ch;
 
ch = 'a';   /* 小写字母 a */
ch = 'A';   /* 大写字母 A */
ch = '0';   /* 0 */
ch = ' ';   /* 空格 */
```

字符常量需要用==单引号==括起来, 而不是双引号



<!-- slide vertical=true data-notes="" -->


##### 字符操作

---

在 C 中字符的操作很简单, 因为C把字符当作小整数进行处理

在 ASCII 码中, 字符的取值范围是$0000000 \sim 1111111$, 可以看成是$0~127$的整数

字符`'a'`的值是`97`, `'A'`的值是`65`, `'0'`的值是`48`, `' '`的值是`32`

字符常量实际上是`int类型`而不是`char类型`



<!-- slide vertical=true data-notes="" -->


##### 字符操作

---

当计算中出现字符时, C 使用它对应的整数值

考虑以下示例, 假设采用ASCII字符集: 

```C{.line-numbers}
char ch;
int i;
 
i = 'a';       /* i is now 97   */
ch = 65;       /* ch is now 'A' */
ch = ch + 1;   /* ch is now 'B' */ 
ch++;          /* ch is now 'C' */
```

---


<!-- slide vertical=true data-notes="" -->


##### 字符操作

---

可以像数字那样对字符进行比较
将小写字母转换为大写字母的if语句: 
```C
if ('a' <= ch && ch <= 'z')
  ch = ch - 'a' + 'A';
```
`'a' <= ch` 这样的比较使用的是字符所对应的整数值

这些值取决于使用的字符集, 因此使用`<、<=、>`和`>=`比较字符的程序可能不可移植



<!-- slide vertical=true data-notes="" -->


##### 字符操作

---

字符具有与数字相同的属性, 这一事实会带来好处

例如, 可以让for语句中的控制变量遍历所有大写字母: 

```C
for (ch = 'A'; ch <= 'Z'; ch++) …
```

将字符视为数字的缺点: 

- 可能导致编译器无法捕获的错误

- 允许无明确含义的表达式, 例如: `'a' * 'b' / 'c'`

- 可能会妨碍可移植性, 因为程序可能依赖于对字符集的假设



<!-- slide vertical=true data-notes="" -->


##### 有符号字符和无符号字符

---

char类型与整数类型一样存在有符号和无符号两种

- 有符号字符的取值范围是`–128~127`

- 无符号字符的取值范围是`0~255`

一些编译器将char视为有符号类型, 有些则视为无符号类型

C 允许使用signed和unsigned来修饰char: 

```C{.line-numbers}
signed char sch;
unsigned char uch;
```

---

<!-- slide vertical=true data-notes="" -->


##### 有符号字符和无符号字符

---

C89 使用术语==整值类型==来统称整数类型和字符类型

枚举类型也属于整数类型

C99 不使用术语整值类型

相反, 它将整数类型的含义扩展为包括字符类型和枚举类型

C99 的`_Bool类型`被认为是无符号整数类型



<!-- slide vertical=true data-notes="" -->


##### 算术类型

---

整数类型和浮点类型统称为算术类型

C89中算术类型的分类: 

- 整值类型

- 字符类型(`char`)

- 有符号整型(`signed char, short int, int, long int`)

- 无符号整型(`unsigned char, unsigned short int, unsigned int, unsigned long int`)

- 枚举类型

- 浮点类型(`float、double, long double`)



<!-- slide vertical=true data-notes="" -->


##### 算术类型

---

C99 分类更复杂: 

- 整数类型

- 字符类型(`char`)

- 有符号整型, 包括标准的(`signed char, short int, int, long int, long long int`)和扩展的

- 无符号整型, 包括标准的(`unsigned char, unsigned short int, unsigned int, unsigned long int, unsigned long long int, _Bool`)和扩展的

- 枚举类型

- 浮点类型

- 实数浮点类型(`float, double, long double`) 

- 复数类型(`float_Complex, double_Complex, long double_Complex`)



<!-- slide vertical=true data-notes="" -->


##### 转义序列

---

字符常量通常是用单引号括起来的单个字符

某些特殊字符(包括换行符)不能以这种方式书写, 不可见的(非打印字符)或者无法从键盘输入

转义序列提供了一种表示这些字符的方法

有两种转义序列: ==字符==转义序列和==数字==转义序列



<!-- slide vertical=true data-notes="" -->


##### 转义序列

---

完整的字符转义序列集合: 

<div class="fullborder">

| Name          | Escape Sequence | 
| :--           | :--|
| Alert (bell)  | `\a` | 
| Backspace     | `\b` | 
| Form feed     | `\f` |
| New line      | `\n` |
| Carriage return | `\r` |
| Horizontal tab  | `\t` |
| Vertical tab    | `\v` |
| Backslash       | `\\` | 
| Question mark   | `\?` |
| Single quote    | `\'` |
| Double quote    | `\"` |

</div>



<!-- slide vertical=true data-notes="" -->


##### 转义序列

---

字符转义很方便, 但并非所有无法打印的ASCII字符都存在转义

字符转义也无法用于表示基本128个ASCII字符之外的字符

数字转义序列可以表示任何字符, 可以解决此问题

特殊字符的数字转义序列使用字符的八进制或十六进制值

例如, 某个ASCII转义字符(十进制值为27)的八进制值为`33`, 十六进制值为`1B`



<!-- slide vertical=true data-notes="" -->


##### 转义序列

---

八进制转义序列由`\`后跟一个最多三个数字的八进制数组成, 例如`\33`或`\033`

十六进制转义序列由`\x`后跟一个十六进制数组成, 例如`\x1b`或`\x1B`

`x`必须小写, 但十六进制数字不限大小写



<!-- slide vertical=true data-notes="" -->


##### 转义序列

---

当用作字符常量时, 转义序列必须用单引号括起来

例如, 表示转义字符的常量可以写作`'\33'`(或`'\x1b'`)

转义序列往往有点隐晦, 可以使用#define给它们命名: 

```C
#define ESC '\33'
```

转义序列也可以嵌入到字符串中



<!-- slide vertical=true data-notes="" -->


##### 字符处理函数

---

==C==的`toupper库函数`是一种快速且可移植的大小写转换方法: 

```C
ch = toupper(ch);
```

toupper返回其参数的大写版本

调用toupper的程序需要包含头文件: 

```C
#include <ctype.h>
```

C 函数库提供了许多其他有用的字符处理函数



<!-- slide vertical=true data-notes="" -->


##### 用scanf和printf读/写字符

---

转换说明`%c`允许`scanf`和`printf`读写单个字符: 

```C
char ch;

scanf("%c", &ch); /* 读取一个字符 */
printf("%c", ch); /* 写入一个字符 */
```

scanf不会跳过空白字符

强制scanf读取字符前==跳过==空白字符, 需在转换说明`%c`前加空格: 

```C
scanf(" %c", &ch);
```

---


<!-- slide vertical=true data-notes="" -->


##### 用scanf和printf读/写字符

---

scanf读字符不会跳过空格, 可检查读取的字符是否是换行符

以下代码循环读取并忽略当前输入行中剩余的所有字符: 

```C
do {
  scanf("%c", &ch);
} while (ch != '\n');
```

- 循环退出时, ch变量一定是换行符

- 下次调用scanf时, 它将读取下一输入行中的第一个字符



<!-- slide vertical=true data-notes="" -->


##### 用getchar和putchar读/写字符

---

单字符输入和输出, getchar和putchar是scanf和printf的替代方法

putchar用于输出单个字符: 

```C
putchar(ch);
```

每次调用getchar时, 它都会读取一个字符并将其返回: 

```C
ch = getchar();
```

getchar返回一个int值而不是char值, 因此ch通常具有int类型

与scanf一样, getchar在读取时不会跳过空白字符



<!-- slide vertical=true data-notes="" -->


##### 用getchar和putchar读/写字符

---

使用getchar和putchar(而不是scanf和printf)可以节省执行时间

getchar和putchar比scanf和printf逻辑简单得多

scanf和printf旨在按不同格式读写多种类型的数据

getchar和putchar通常被实现为宏以提高速度

getchar常用于多种C语言的惯用法: 搜索字符、跳过字符等



<!-- slide vertical=true data-notes="" -->


##### 用getchar和putchar读/写字符

---

考虑以下scanf循环, 我们曾用它来跳过输入行剩余部分: 

```C{.line-numbers}
do {
  scanf("%c", &ch);
} while (ch != '\n');
```

使用getchar重写可以得到以下代码: 

```C{.line-numbers}
do {
  ch = getchar();
} while (ch != '\n');
```

---


<!-- slide vertical=true data-notes="" -->


##### 用getchar和putchar读/写字符

---

将getchar的调用移到控制表达式中可以精简循环: 

```C
while ((ch = getchar()) != '\n')
  ;
```

不需要ch变量也可以将getchar的返回值与换行符进行比较: 

```C
while (getchar() != '\n')
  ;
```

---


<!-- slide vertical=true data-notes="" -->


##### 用getchar和putchar读/写字符

---

getchar在跳过字符的循环以及搜索字符的循环中很有用

使用getchar语句跳过空白字符: 

```C
while ((ch = getchar()) == ' ')
  ;
```
当循环终止时, ch将包含getchar遇到的第一个==非空白字符==



<!-- slide vertical=true data-notes="" -->



##### 用getchar和putchar读/写字符

---

<span class="blue">:fa-lightbulb-o:</span> 混合使用getchar和scanf时要小心

scanf函数倾向于遗留下它==扫视==过但未读取的字符(包括换行符): 

```C
printf("请输入一个整数: ");
scanf("%d", &i);
printf("输入命令: ");
command = getchar();
```

- 在读取输入至i的同时, scanf调用将会留下没有消耗掉的任意字符(不用, ==放回==)

- getchar函数随后将取回第一个剩余字符(用掉, ==不放回==)



<!-- slide vertical=true data-notes="" -->


##### 程序: 确定消息的长度

---

*length.c*程序显示用户输入的消息的长度: 

```
Enter a message: Brevity is the soul of wit.
Your message was 27 character(s) long.
```

长度包括空格和标点符号, 但不包括消息末尾的换行符

scanf和getchar都可以读取字符, 但程序员大多会选择getchar

*length2.c*没有使用变量存储由getchar读取的字符



<!-- slide vertical=true data-notes="" -->


##### 程序: 确定消息的长度

---

*length.c*

```C{.line-numbers}
/* 确定消息的长度 */
 
#include <stdio.h>
 
int main(void)
{
  char ch;
  int len = 0;
 
  printf("Enter a message: ");
  ch = getchar();
  while (ch != '\n') {
    len++;
    ch = getchar();
  }
  printf("Your message was %d character(s) long.\n", len);
 
  return 0;
}
```

---



<!-- slide vertical=true data-notes="" -->


##### 程序: 确定消息的长度

---

*length2.c*

```C{.line-numbers}
/* 确定消息的长度 */
 
#include <stdio.h>
 
int main(void)
{
  int len = 0;
 
  printf("Enter a message: ");
  while (getchar() != '\n')
    len++;
  printf("Your message was %d character(s) long.\n", len);
 
  return 0;
}
```

---


<!-- slide vertical=true data-notes="" -->


##### 类型转换

---

为了让计算机执行算术运算, 通常要求操作数有相同的大小(相同的位数), 并以相同的方式存储

表达式中可以混合使用不同基本类型, C编译器可能需要生成将某些操作数转换成不同类型的指令, 使硬件能对表达式进行计算

- 如果将16位short型数和32位int型数相加, 编译器会将short型值转换为32位值

- 如果将int型数和float型数相加, 编译器会将int型值转换为float



<!-- slide vertical=true data-notes="" -->


##### 类型转换

---

==隐式转换==: 编译器自动处理而无需程序员介入的转换(implicit)

==显式转换==: 程序员使用强制运算符进行的转换(explicit)

C有大量不同的算术类型, 因此执行隐式转换的规则较为复杂



<!-- slide vertical=true data-notes="" -->


##### 类型转换

---

进行隐式转换的情况: 

- 当算术或逻辑表达式中的操作数类型不相同时

- 当赋值运算符右侧表达式的类型与左侧变量的类型不匹配时

- 当函数调用中的实参类型与对应形参的类型不匹配时

- 当return语句中表达式的类型与函数返回的类型不匹配时

第 9 章将讨论后两种情况



<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

常用算术转换适用于大多数二元运算符的操作数

表达式`f + i`, 若f的类型为`float`, i的类型为`int`, 则常用算术转换将会应用在表达式的各个操作数上

将i转换为float类型比将f转换为int类型更安全

- 当整数转换为float时, 可能发生的最坏情况是精度的轻微损失

- 相反, 将浮点数转换为int会导致数字的小数部分的损失

- 如果原始float数大于最大的整数或小于最小的整数, 得到的结果则毫无意义



<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

常用算术转换的策略: 将操作数转换为可以安全适用于两个数值的==最狭小的==数据类型

为了统一操作数的类型, 通常可以将相对狭小类型的操作数转换为另一个操作数的类型来实现(即所谓的==提升==)

最常用的是==整值提升==, 将字符或短整数转换为int类型(或在某些情况下转换为unsigned int)

执行常用算术转换的规则可以分为两种情况: 

- 任一操作数的类型是浮点类型

- 两种操作数类型都不是浮点类型



<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

任一操作数的类型是浮点类型

- 如果一个操作数的类型为long double, 那么将另一操作数转换为long double类型

- 否则, 如果一个操作数的类型为double, 那么将另一操作数转换为double类型

- 否则, 如果一个操作数的类型为float, 那么将另一操作数转换为float类型

例如: 如果一个操作数的类型为long int, 另一个操作数的类型为double, 则long int类型的操作数会被转换为double类型



<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

若操作数类型都不是浮点类型，会先对两个操作数执行整值提升

然后按照下图对类型较狭小的操作数进行提升: 

<div class="fulltable">

|`unsigned long int`|
|:-- |
|&emsp; $\Uparrow$|
|`long int`|
|&emsp; $\Uparrow$|
|`unsigned int`|
|&emsp; $\Uparrow$|
|`int`|

</div>

---


<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

当有符号与无符号操作数组合时, 把有符号操作数转换为无符号

- 此规则可能会导致隐蔽的编程错误

- 最好尽量避免使用无符号整数, 特别是不要将它与有符号整数混合使用



<!-- slide vertical=true data-notes="" -->


##### 常用算术转换

---

常用算术转换示例: 

```C{.line-numbers}
char c;
short int s;
int i;
unsigned int u;
long int l;
unsigned long int ul;
float f;
double d;
long double ld;
 
i = i + c;     /* c is converted to int               */
i = i + s;     /* s is converted to int               */
u = u + i;     /* i is converted to unsigned int      */
l = l + u;     /* u is converted to long int          */
ul = ul + l;   /* l is converted to unsigned long int */
f = f + ul;    /* ul is converted to float            */
d = d + f;     /* f is converted to double            */
ld = ld + d;   /* d is converted to long double       */
```

---


<!-- slide vertical=true data-notes="" -->


##### 赋值过程中的转换

---

常用算术转换不适用于赋值运算

赋值运算右边的表达式会被转换为左边变量的类型: 

```C
char c;
int i;
float f;
double d;
 
i = c;   /* c is converted to int   */
f = i;   /* i is converted to float */
d = f;   /* f is converted to double */
```

---


<!-- slide vertical=true data-notes="" -->


##### 赋值过程中的转换

---

把浮点数赋值给整型变量会丢掉该数的小数部分: 

```C
int i;
 
i = 842.97;    /* i is now 842 */
i = -842.97;   /* i is now -842 */
```

把某种类型的值赋给类型更狭小的变量时, 如果该值超出变量类型的范围, 将会得到无意义的结果: 

```C
c = 10000;    /*** WRONG ***/
i = 1.0e20;   /*** WRONG ***/
f = 1.0e100;  /*** WRONG ***/
```

---

<!-- slide vertical=true data-notes="" -->


##### 赋值过程中的转换

---

如果要将浮点常量赋值给float型变量, 最好加上f后缀: 

```C
f = 3.14159f;
```

如果没有后缀, 常量3.14159将是double类型, 可能会有警告消息



<!-- slide vertical=true data-notes="" -->


##### C99 中的隐式转换

---


C99的隐式转换规则略有不同

每个整数类型都有一个==整数转换等级==

从高到低排列: 

1. long long int, unsigned long long int
2. long int, unsigned long int
3. int, unsigned int
4. short int, unsigned short int
5. char, signed char, unsigned char
6. _Bool

C99的整数提升可以将任何等级低于int和unsigned int的类型转换为int(只要该类型的所有值都可以用int类型表示)或unsigned int



<!-- slide vertical=true data-notes="" -->


##### C99 中的隐式转换

---

C99 执行常用算术转换的规则可以分为两种情况: 

- 任一操作数的类型是浮点类型, 且都不是复数类型, 规则和以前一样

- 两种操作数类型都不是浮点类型



<!-- slide vertical=true data-notes="" -->


##### C99 中的隐式转换

---

两种操作数类型都不是浮点类型. 

若两个操作数的类型相同, 过程结束

否则, 依次尝试以下规则: 

- 若两个操作数都是有符号或都是无符号, 将转换等级较低的转换为等级较高的

- 若无符号操作数等级高于或等于有符号操作数等级, 将有符号转换为无符号类型

- 若有符号操作数类型可表示无符号操作数类型的所有值, 将无符号操作数转换为有符号操作数类型

- 否则, 将两个操作数都转换为与有符号操作数的类型相对应的无符号类型



<!-- slide vertical=true data-notes="" -->


##### C99 中的隐式转换

---

所有算术类型都可以转换为_Bool类型

> 如果原始值为0, 则转换结果为0; 否则结果为1



<!-- slide vertical=true data-notes="" -->


##### 强制类型转换

---

C的隐式转换很方便, 但有时需要从更大程度上控制类型转换

出于这个原因, C 提供了强制类型转换

强制类型转换<u>表达式格式</u>: 

```C
 (类型名)表达式
```

==类型名==指定表达式应转换成的类型



<!-- slide vertical=true data-notes="" -->


##### 强制类型转换

---

使用强制类型转换表达式计算float类型值的小数部分: 

```C
float f, frac_part;
frac_part = f - (int) f;
```

`f`和`(int)f`的区别在于小数部分在强制类型转换时被丢弃

强制类型转换表达式可用于显示那些肯定会发生的类型转换: 

```C
i = (int) f; /* f 转换为 int */
```

---


<!-- slide vertical=true data-notes="" -->


##### 强制类型转换

---

强制转换表达式可以用来强制编译器进行转换

```C
float quotient;
int dividend, divisor;

quotient = dividend / divisor; 
```

为了避免除法的结果丢弃小数部分, 需要转换操作数的类型: 

```C
quotient = (float) dividend / divisor;
```

将被除数转换为float类型会迫使编译器将除数也转换为float类型



<!-- slide vertical=true data-notes="" -->


##### 强制类型转换

---

C将==(类型名)==视为一元运算符

一元运算符优先级==高于==二元运算符, 编译器会将表达式

```C
(float) dividend / divisor
```
解释为: 
```C
((float) dividend) / divisor
```

其他实现相同效果的方法: 
```C
quotient = dividend / (float) divisor;
quotient = (float) dividend / (float) divisor;
```

---


<!-- slide vertical=true data-notes="" -->


##### 强制类型转换

---

有时需要使用强制类型转换以避免溢出: 

```C{.line-numbers}
long i;
int j = 1000;
 
i = j * j;    /* 可能发生溢出 */
```

使用强制类型转换可避免数据溢出问题: 

```C{.line-numbers}
i = (long) j * j;
```

注意, 语句

```C {.line-numbers}
i = (long) (j * j); /*** WRONG ***/
```

是不对的, 因为溢出在强制类型转换之前已经发生了



<!-- slide vertical=true data-notes="" -->


##### 类型定义

---

`#define`指令可用于创建一个宏, 定义布尔型数据:

```C 
#define BOOL int
```

更好的方法是利用类型定义的特性: 

```C
typedef int Bool;
```

现在, Bool类型可以和内置的类型名一样使用, 例如

```C
Bool flag;    /* 与 int flag相同;  */
```

---


<!-- slide vertical=true data-notes="" -->


##### 类型定义的优点

---

类型定义使程序更易于理解

如果cash_in和cash_out用于存储美元数量, 则将代码

```C
float cash_in, cash_out;
```

改写为下面的写法更有实际意义: 

```C
typedef float Dollars;
Dollars cash_in, cash_out;
```

---


<!-- slide vertical=true data-notes="" -->


##### 类型定义的优点

---

类型定义还可以使程序更易于修改

要将Dollars重新定义为double类型, 只需更改类型定义: 

```C
typedef double Dollars;
```

如果不使用类型定义, 就需要找到所有存储美元数量的float类型变量并更改它们的声明

---


<!-- slide vertical=true data-notes="" -->


##### 类型定义和可移植性

---

类型定义是编写可移植程序的重要工具

将程序从一台计算机移动到另一台计算机可能引发的问题是不同计算机上的类型取值范围可能不同

如果i是int型变量, 则赋值语句

```C
i = 100000;
```

在整数为32位的机器上没问题, 但在16位的机器上会出错

---


<!-- slide vertical=true data-notes="" -->


##### 类型定义和可移植性

---

为了更大的可移植性, 考虑使用typedef定义新的整数类型名

假设编写的程序需用变量存储产品数量, 取值范围$0-50,000$

可以使用long类型的变量, 但更倾向于使用int类型的变量:

- 算术运算时int比long运算速度快

- int类型变量占用的空间较少


---

<!-- slide vertical=true data-notes="" -->


##### 类型定义和可移植性

---

可以定义自己的==数量==类型, 而不使用int类型来声明数量变量:

```C
typedef int Quantity;
```

并使用此类型声明变量: 

```C
Quantity q;
```

当把程序传输到使用较短整数的机器上时, 需更改类型定义:

```C
typedef long Quantity;
```

<span class="blue">:fa-lightbulb-o:</span> 更改Quantity的定义可能会影响Quantity类型变量的使用方式



<!-- slide vertical=true data-notes="" -->


##### 类型定义和可移植性

---

C语言库用typedef为因不同的实现而可能不同的类型创建类型名

这些类型的名称通常以`_t`结尾, 常见的例子:

```C
typedef long int ptrdiff_t;
typedef unsigned long int size_t;
typedef int wchar_t;
```

C99中<stdint.h>用typedef定义占特定位数整数类型名, 如int32_t



<!-- slide vertical=true data-notes="" -->


##### sizeof运算符

---

```C
sizeof (类型名)
```

表达式的值是无符号整数, 表示存储属于类型名的值所需==字节数==

sizeof(char)的值始终为 1, 但其他类型的值可能有所不同

在 32 位机器上, sizeof(int)通常为 4



<!-- slide vertical=true data-notes="" -->


##### sizeof运算符

---

通常情况下sizeof运算符也可应用于常量、变量和表达式

如果i和j是int型变量, 则sizeof(i)和sizeof(i + j)在32位机器上均为4

- 与应用于类型时不同, sizeof应用于表达式时不需要括号

- 可以用sizeof i代替sizeof(i) 

- 若考虑运算符优先级, 可能需要括号

- sizeof i + j会被解释为(sizeof i) + j, 因为一元运算符优先级高于二元运算符

---


<!-- slide vertical=true data-notes="" -->


##### sizeof运算符

---

显示sizeof值需要小心, 因为sizeof表达式的类型是size_t, 这是由实现定义的类型

在 C89 中, 最好在显示之前将表达式的值转换为已知类型: 

```C
printf("Size of int: %lu\n", (unsigned long) sizeof(int));
```

C99 中的printf可以直接显示size_t值, 在转换说明中的一般整数代码前使用字母z: 

```C
printf("Size of int: %zu\n", sizeof(int));
```

---
