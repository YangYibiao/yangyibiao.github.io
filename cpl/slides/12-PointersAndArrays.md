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

# C语言程序设计基础

<hr class="width50 center">

## 指针和数组


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- 指针的算术运算

- 指针用于数组处理

- 数组名作为指针

- 指针和多维数组

- C99中的指针和变长数组

<!-- slide vertical=true data-notes="" -->



##### 引言

---

C语言允许对指针进行算术运算

指针==可代替数组下标==对数组进行处理

C语言中指针和数组之间的关系非常紧密

理解指针与数组之间的关系对于熟练掌握C语言非常重要

<!-- slide vertical=true data-notes="" -->



##### 指针算术

---

第 11 章展示了指针可以指向数组元素: 
```C
int a[10], *p;
p = &a[0];
```
图形表示: 

<div class="top-2">
    <img src="../img/13-1.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 指针算术

---

可以通过p访问a[0]. 例如, 可以通过下面写法将值5存储在a[0]中: 

`*p = 5;`

图示如下: 

<div class="top-2">
    <img src="../img/13-2.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 指针算术

---

如果p指向数组a的一个元素, 则可以通过对p执行指针算术运算(或地址运算)来访问a的其他元素

C支持三种(且只有三种)==指针运算==形式:

- 指针加上整数

- 指针减去整数

- 两个指针相减

<!-- slide vertical=true data-notes="" -->



##### 将整数添加到指针

---

将整数j添加到指针p会产生一个指向第j个元素的指针, 该元素位于p指向的元素之后. 

更准确地说, 如果p指向数组元素a[i], 那么p + j指向a[i+j]. 

假设有以下声明: 

```C
int a[10], *p, *q, i;
```

<!-- slide vertical=true data-notes="" -->



##### 将整数添加到指针

---

指针加法示例: 
```C
p = &a[2];
q = p + 3;
p += 6;
```

<div class="top-2"><img src="../img/13-3.png" width=280px></div>

<!-- slide vertical=true data-notes="" -->



##### 从指针中减去整数

---

如果p指向a[i], 那么p-j指向a[i-j]. 

例子: 

```C
p = &a[8]; 
q = p - 3;
p -= 6;
```

<div class="top-2">
    <img src="../img/13-4.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 从另一个指针中减去一个指针

---

当一个指针从另一个指针中减去时, 结果是==指针之间的距离==(以数组元素测量). 

如果p指向a[i]并且q指向a[j], 那么$p - q$等于$i - Ĵ$. 

```C
p = &a[5];
q = &a[1];
```

<div class="top-2">
    <img src="../img/13-5.png" width=300px>
</div>

```C
i = p - q; /* i is  4 */
i = q - p; /* i is -4 */
```

<!-- slide vertical=true data-notes="" -->



##### 从另一个指针中减去一个指针

---

我的启示 对不指向数组元素的指针执行算术运算导致未定义的行为

我的启示 只有两个指针指向同一个数组时, 把它们相减才有意义


<!-- slide vertical=true data-notes="" -->



##### 比较指针

---

关系运算符(<, <=, >, >=)和判等运算符(==, !=)进行指针比较. 

使用关系运算符仅对指向同一数组元素的指针有意义. 比较的结果取决于数组中两个元素的相对位置. 

```C
p = &a[5];
q = &a[1];
p <= q; // expression value: 0
p >= q; // expression value: 1
```

任务完成后: 
- p<=q的值为0
- p>=q的值为1. 

<!-- slide vertical=true data-notes="" -->



##### 指向复合字面量的指针(C99)

---

指针指向由复合字面量创建的数组中的元素是合法的: 

int *p = (int []){3, 0, 3, 4, 1};

使用复合字面量可以省去我们先声明一个数组变量然后让p指向该数组的第一个元素的麻烦: 

```C
int a[] = {3, 0, 3, 4, 1};
int *p = &a[0];
```

<!-- slide vertical=true data-notes="" -->



##### 使用指针进行数组处理

---

指针算法允许我们通过重复递增指针变量来访问数组的元素. 

对数组a的元素求和的循环: 

```C
#define N 10
…
int a[N], sum, *p;
…
sum = 0;
for (p = &a[0]; p < &a[N]; p++)
    sum += *p;
```

<!-- slide vertical=true data-notes="" -->



##### 使用指针进行数组处理

---

在第一次迭代结束时: 

在第二次迭代结束时: 

在第三次迭代结束时: 

<div class="top-2">
    <img src="../img/13-6.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 使用指针进行数组处理

---

`for`语句中的条件`p < &a[N]`值得特别提及. 
将地址运算符应用于`a[N]`是合法的, 即使此元素不存在. 

<!-- slide vertical=true data-notes="" -->



##### 结合*和++运算符

---

C程序员经常结合使用*(间接寻址)和++运算符. 
修改数组元素后前进到下一个元素的语句: 
`a[i++] = j;`
对应的指针版本: 
`*p++ = j;`
因为++的后缀版本优先于*, 编译器将其视为
`*(p++) = j;`

<!-- slide vertical=true data-notes="" -->



##### 结合*和++运算符

---

*和++的可能组合: 

<div class="fullborder">

| 表达  | 意义 |
| :--: | :--: |  
| *p++或*(p++) | 表达式的值是*p在递增之前, 之后自增p |
| (*p)++ | 表达式的值为*p在递增之前, 稍后增加*p |
|*++p或*(++p) | 先递增p, 表达式的值为*p后递增   |
| ++*p或++(*p)| 先递增*p, 表达式的值为*p后递增  |

</div>
 
<!-- slide vertical=true data-notes="" -->



##### 结合*和++运算符

---

\*和++最常见的组合是*p++, 它在循环中很方便. 而不是写

```C
for (p = &a[0]; p < &a[N]; p++)
    sum += *p;
```

对数组a的元素求和, 我们可以写

```C
p = &a[0];
while (p < &a[N])
sum += *p++;
```

<!-- slide vertical=true data-notes="" -->



##### 结合*和++运算符

---

*和--运算符的混合方式与*和++相同. 
对于结合了*和--的应用程序, 让我们回到第 10 章的堆栈示例. 
堆栈的原始版本依赖于一个名为top的整数变量来跟踪内容数组中的“堆栈顶部”位置. 
让我们将top替换为最初指向内容数组的元素 0 的指针变量: 
```C
int *top_ptr = &contents[0]; 
```

<!-- slide vertical=true data-notes="" -->



##### 结合*和++运算符

---


新的push和pop函数: 
```C
void push(int i)
{
	if (is_full())
	    stack_overflow();
	else
	    *top_ptr++ = i;
}
  
int pop(void)
{
    if (is_empty())
	    stack_underflow();
	else
	    return *--top_ptr;
}
```
<!-- slide vertical=true data-notes="" -->



##### 使用数组名称作为指针

---

指针算法是数组和指针相关的一种方式. 
另一个关键关系: 
 数组的名称可以用作指向数组中第一个元素的指针. 
这种关系简化了指针算术并使数组和指针更加通用. 

<!-- slide vertical=true data-notes="" -->



##### 使用数组名称作为指针

---

假设a声明如下: 
```C
int a[10];
```
使用a作为指针的示例: 
```C
*a = 7; /* 将 7 存储在 a[0] */
*(a+1) = 12; /* 将 12 存储在 a[1] */
```
一般来说, 一个 + i与&a[i]相同. 
两者都表示指向 a 的元素i的指针. 
此外,  *(a+i)等价于a[i] . 
两者都代表元素i本身. 

<!-- slide vertical=true data-notes="" -->



##### 使用数组名称作为指针

---

数组名称可以用作指针这一事实使得编写遍历数组的循环变得更加容易. 
原始循环: 
```C
for (p = &a[0]; p < &a[N]; p++)
    sum += *p;
```
简化版: 
```C
for (p = a; p < a + N; p++)
    sum += *p;
```
<!-- slide vertical=true data-notes="" -->



##### 使用数组名称作为指针

---

尽管数组名可以用作指针, 但不能为其分配新值. 
试图让它指向其他地方是一个错误: 
```C
while (*a != 0)
    a++; /*** 错误的 ***/
```
这不是很大的损失;我们总是可以将a复制到指针变量中, 然后更改指针变量: 
```C
p = a;
while (*p != 0)
    p++;
```
<!-- slide vertical=true data-notes="" -->



##### 程序: 反转一系列数字(重访)

---

的reverse.c程序读取 10 个数字, 然后以相反的顺序写入这些数字. 
原始程序将数字存储在一个数组中, 下标用于访问数组的元素. 
reverse3.c是一个新版本的程序, 其中下标已被指针算法取代. 


<!-- slide vertical=true data-notes="" -->



##### 程序: 反转一系列数字(重访)

---

反向3.c
 
/* 反转一系列数字(指针版本) */
```C
#include <stdio.h>
 
#define N 10
 
int main(void)
{
  int a[N], *p;
 
  printf("Enter %d numbers: ", N);
  for (p = a; p < a + N; p++)
    scanf("%d", p);
 
  printf("In reverse order:");
  for (p = a + N - 1; p >= a; p--)
    printf(" %d", *p);
  printf("\n");
 
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---

传递给函数时, 数组名称被视为指针. 
例子: 
```C
int find_largest(int a[], int n)
{
    int i, max;
 
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

```
调用find_largest : 
```C
largest = find_largest(b, N);
```
此调用导致将指向b的第一个元素的指针分配给a ;数组本身不会被复制. 

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---

数组参数被视为指针这一事实具有一些重要的后果. 
后果一: 普通变量传给函数时, 其值被复制;对相应参数的任何更改都不会影响变量. 
相反, 用作参数的数组不受更改保护. 


<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---

例如, 以下函数通过将零存储到其每个元素中来修改数组: 
```C
void store_zeros(int a[], int n)
{
    int i;
  
    for (i = 0; i < n; i++)
        a[i] = 0;
}
```


<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---

为了表明一个数组参数不会被改变, 我们可以在它的声明中包含单词const: 
```C
int find_largest(const int a[], int n)
{
    …
}
```
如果存在const, 编译器将检查find_largest的主体中是否没有对a元素的赋值. 

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---

结果 2: 将数组传递给函数所需的时间不取决于数组的大小. 
传递一个大数组没有任何惩罚, 因为没有制作数组的副本. 

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---
结果 3: 如果需要, 可以将数组参数声明为指针. 
find_largest可以定义如下: 
```C
int find_largest(int *a, int n)
{
    …
}
```
声明为指针, 相当于将其声明为数组;编译器将声明视为相同. 

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---
尽管将参数声明为数组与将其声明为指针相同, 但对于变量而言并非如此. 
以下声明使编译器为 10 个整数留出空间: 
```C
int a[10];
```
以下声明使编译器为指针变量分配空间: 
```C
int *a;
```

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---
在后一种情况下,  a不是数组;试图将其用作数组可能会导致灾难性的后果. 
例如, 赋值
```C
*a = 0; /*** 错误的 ***/
```
a指向的地方存储 0 . 
因为我们不知道a指向哪里, 所以对程序的影响是不确定的. 

<!-- slide vertical=true data-notes="" -->



##### 数组参数(重新访问)

---
结果 4: 带有数组参数的函数可以传递一个数组“切片”——一系列连续元素. 
将find_largest应用于数组b的元素 5 到 14 的示例: 
```C
largest = find_largest(&b[5], 10);
```

<!-- slide vertical=true data-notes="" -->



##### 使用指针作为数组名

---
C 允许我们给指针下标, 就好像它是一个数组名一样: 
```C
#define N 10
…
int a[N], i, sum = 0, *p = a;
…
for (i = 0; i < N; i++)
    sum += p[i];
```
编译器将p[i]视为*(p+i) . 

<!-- slide vertical=true data-notes="" -->



##### 指针和多维数组

---

正如指针可以指向一维数组的元素一样, 它们也可以指向多维数组的元素. 
本节探讨使用指针处理多维数组元素的常用技术. 

<!-- slide vertical=true data-notes="" -->



##### 多维数组的元素

---

第 8 章展示了 C 以行优先顺序存储二维数组. 
r行的数组的布局: 
  
<div class="top-2">
    <img src="../img/13-7.png">
</div>

如果p最初指向第 0 行第 0 列的元素, 我们可以通过重复递增p来访问数组中的每个元素. 


<!-- slide vertical=true data-notes="" -->



##### 多维数组的元素

---

考虑将以下数组的所有元素初始化为零的问题: 
int a[NUM_ROWS][NUM_COLS];
显而易见的技术是使用嵌套的 for循环: 
int row, col;
…
for (row = 0; row < NUM_ROWS; row++)
    for (col = 0; col < NUM_COLS; col++)
        a[row][col] = 0;
如果我们将a视为整数的一维数组, 则一个循环就足够了: 
int * p;
…
for (p = &a[0][0]; p <= &a[NUM_ROWS-1][NUM_COLS-1]; p++)
    *p = 0;

<!-- slide vertical=true data-notes="" -->



##### 多维数组的元素

---

尽管将二维数组视为一维可能看起来像是作弊, 但它适用于大多数 C 编译器. 
像这样的技术肯定会损害程序的可读性, 但是——至少对于一些较旧的编译器——会产生补偿性的效率提升. 
但是, 对于许多现代编译器, 速度优势通常很少或没有. 

<!-- slide vertical=true data-notes="" -->



##### 处理多维数组的行

---
指针变量p也可用于处理二维数组的一行中的元素. 
为了访问第i行的元素, 我们将p初始化为指向数组a中第i行的元素 0 : 
p = &a[i][0];
或者我们可以简单地写
p = a[i];


<!-- slide vertical=true data-notes="" -->



##### 处理多维数组的行

---
对于任何二维数组a , 表达式a[i]是指向第i行第一个元素的指针. 
要了解这为何有效, 请回想一下a[i]等价于*(a + 一) . 
因此,  &a[i][0]与&(*(a[i] + 0)) , 相当于&*a[i] . 
这与a[i]相同, 因为&和*运算符取消. 


<!-- slide vertical=true data-notes="" -->



##### 处理多维数组的行

---
清除数组a的第i行的循环: 
int a[NUM_ROWS][NUM_COLS], *p, i;
…
for (p = a[i]; p < a[i] + NUM_COLS; p++)
    *p = 0;
由于a[i]是指向数组a的第i行的指针, 我们可以将a[i]传递给期望一维数组作为其参数的函数. 
换句话说, 设计用于处理一维数组的函数也可以处理属于二维数组的行. 


<!-- slide vertical=true data-notes="" -->



##### 处理多维数组的行

---

考虑find_largest , 它最初设计用于查找一维数组的最大元素. 
我们可以很容易地使用find_largest来确定二维数组a的第i行中的最大元素: 
largest = find_largest(a[i], NUM_COLS);


二维数组的列中的元素并不容易, 因为数组是按行而不是按列存储的. 
数组a 的列i的循环: 
int a[NUM_ROWS][NUM_COLS],  (*p)[NUM_COLS], i;
…
for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    (*p)[i] = 0;


任何数组的名称都可以用作指针, 不管它有多少维, 但需要注意. 
例子: 
int a[NUM_ROWS][NUM_COLS];
a不是指向a[ 0 ][0]的指针;相反, 它是指向a[0]的指针. 
C 将a视为一维数组, 其元素是一维数组. 
当用作指针时,  a 的类型为int (*)[NUM_COLS] (指向长度为NUM_COLS的整数数组的指针). 



<!-- slide vertical=true data-notes="" -->



##### 处理多维数组的行

---

知道a指向a[0]对于简化处理二维数组元素的循环很有用. 
而不是写
for (p = &a[0]; p < &a[NUM_ROWS]; p++)
    (*p)[i] = 0;
要清除数组a的第i列, 我们可以写
for (p = a; p < a + NUM_ROWS; p++)
    (*p)[i] = 0;


<!-- slide vertical=true data-notes="" -->



##### 使用多维数组的名称作为指针

---

我们可以“欺骗”一个函数, 使其认为多维数组实际上是一维的. 
第一次尝试使用find_largest来查找a中的最大元素: 
largest = find_largest(a, NUM_ROWS * NUM_COLS);
/* 错误的 */
这是一个错误, 因为 a 的类型是int (*)[NUM_COLS]但find_largest需要一个int类型的参数 * .
正确的调用: 
largest = find_largest(a[0], NUM_ROWS * NUM_COLS);
a[0]指向第 0 行中的元素 0, 它的类型为int * (编译器转换后). 


<!-- slide vertical=true data-notes="" -->



##### 指针和可变长度数组 (C99)

---

允许指针指向可变长度数组 (VLA) 的元素. 
一个普通的指针变量将用于指向一维 VLA 的元素: 
void f(int n)
{
    int [n], *p;
    p = a;
    …
}

<!-- slide vertical=true data-notes="" -->



##### 指针和可变长度数组 (C99)

---

当 VLA 有多个维度时, 指针的类型取决于除第一个维度之外的每个维度的长度. 
二维示例: 
void f(int m, int n)
{
    int a[m][n], (*p)[n];
    p = a;
    …
}
由于p的类型取决于n , 它不是常数, 因此p被称为具有可变修改的类型. 

<!-- slide vertical=true data-notes="" -->



##### 指针和可变长度数组 (C99)

---

赋值的有效性, 例如p = a不能总是由编译器确定. 
以下代码将编译, 但仅当m和n相等时才正确: 
int a[m][n], (*p)[m];
p = a;
如果m不等于n , 任何后续使用p将导致未定义的行为. 


<!-- slide vertical=true data-notes="" -->



##### 指针和可变长度数组 (C99)

---

可变修改类型受到某些限制. 
最重要的限制: 可变修改类型的声明必须在函数体内或函数原型中. 

<!-- slide vertical=true data-notes="" -->



##### 指针和可变长度数组 (C99)

---

指针算法适用于 VLA. 
二维 VLA: 
int a[m][n];
能够指向 a 行的指针: 
int (*p)[n];
清除a 的i列的循环: 
for (p = a; p < a + m; p++)
	(*p)[i] = 0;


