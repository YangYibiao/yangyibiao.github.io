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

## 指针


<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### yangyibiao@nju.edu.cn


<!-- slide vertical=true data-notes="" -->

##### 提纲

---

- 指针变量

- 取地址运算符

- 间接寻址运算符

- 指针赋值

- 指针作为参数

- 指针作为返回值

- 动态内存分配

---

<!-- slide vertical=true data-notes="" -->

##### 指针变量

---

多数现代计算机中的内存被划分为字节

每个字节存储8位信息(Contents): 

<div class="top-2">
    <img src="img/11-1.png" width=400px>
</div>

<!-- ![w:500](img/11-1.png) -->

内存中每个字节都有一个==唯一的地址== (Address). 

---

<!-- slide vertical=true data-notes="" -->

##### 指针变量

---

内存中每个字节有一个==唯一的地址== (Address). 
如果内存中有n个字节, 其字节的地址可编号为: $0 \sim n – 1$

<div class="top-2">
    <img src="img/11-2.png" width=160px>
</div>

<!-- ![w:10 h:50](img/11-2.png) -->

若内存为8GB, $1GB = 2^{30}$ 字节, 则 $8GB = 2^{33}$字节
其内存地址编号为：$0 \sim 2^{33} - 1$

---



<!-- slide vertical=true data-notes="" -->

##### 指针变量

---

程序中的每个变量都占用一个或多个字节的内存, 例如:
```C
char c; // 一个字节
int i; // 四个字节
```

---


<!-- slide vertical=true data-notes="" -->

##### 指针变量

---

第一个字节的地址被称为变量的地址. 如图, 变量i的地址为 2000: 

<div class="top-2">
    <img src="img/11-3.png" width=300px>
</div>

<!-- ![h:20](img/11-3.png) -->

---



<!-- slide vertical=true data-notes="" -->

##### 指针变量

---

指针==变量==：用于存储 ==Address(内存地址)== 的==变量==

指针变量 ==存储的内容== 为 ==Address(内存地址)==

当将变量i的地址存储在指针变量p中时, 则p==指向==i:

```C
int i;
int *p; // 声明一个指向整数类型的指针变量p
p = &i; // &i指取变量i的地址, 赋值给指针变量p

*p = 8; // 等同于 i = 8, 对*p的操作等同于对i的操作
```

<div class="top-2">
    <img src="img/11-4.png" width=300px>
</div>

<!-- ![w:300](img/11-4.png) -->

---


<!-- slide vertical=true data-notes="" -->

##### 声明指针变量

---

当一个指针变量被声明时, 它的名字前面必须有一个星号: 

```C
int *p;
```

p是一个指针变量, 能够指向int类型的对象. 

使用术语==对象==而不是变量, 因p可以指向不属于变量的内存区域. 

---


<!-- slide vertical=true data-notes="" -->

##### 声明指针变量

---

指针变量可以与其他变量一起出现在声明中: 
```C
int i, j, a[10], b[20], *p, *q;
```
C中每个指针变量只能指向特定类型的对象: 
```C
int *p; /* 只指向int */
double *q; /* 只指向double */
char *r; /* 只指向char */
```

---


<!-- slide vertical=true data-notes="" -->

##### 取地址和间接寻址运算符

---

C提供了一对专门与指针一起使用而设计的运算符. 

要获取变量的地址, 使用 ==&== 取地址运算符. 

访问指针所指向的对象, 使用 ==*== 间接寻址运算符. 

---



<!-- slide vertical=true data-notes="" -->

##### 取地址运算符

---

声明指针变量会为指针留出空间, 但不会使其指向对象: 

```C
int *p;  /* 没有指向特定对象 */
```

在使用p之前需要初始化它. 

---



<!-- slide vertical=true data-notes="" -->

##### 取地址运算符

---

初始化指针变量的一种方式可以将变量的地址赋值给指针变量: 

```C
int i, *p;
…
p = &i;
```

把i的地址赋值给变量p, 使p指向i: 

![w:500](img/11-5.png)

---



<!-- slide vertical=true data-notes="" -->

##### 取地址运算符

---

可在声明指针变量时进行初始化: 

```C
int i;
int *p = &i;
```

i的声明也可以与指针p的声明合并: 

```C
int i, *p = &i;
```

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

一旦指针变量指向一个对象, 就可以使用 ==*== 间接寻址运算符来访问对象中存储的内容. 

如果p指向i, 则可以打印i的值: 

```C
printf("%d\n", *p);
```

- 对变量使用`&`运算符生成指向变量的指针

- 对指针使用`*`运算符则可以返回原始变量

```C
j = *&i; /* 等同于 j = i; */
```

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

p指向i, 则`*p`是i的别名. 

`*p`与i具有相同的值. 

更改`*p`的值会更改i的值. 

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

```C
int  i;
int *p;
p = &i;
```

![w:10](img/11-6.png)

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

`i = 1;`

![w:10](img/11-7.png)

```C
printf("%d\n",  i); /* 打印 1 */
printf("%d\n", *p); /* 打印 1 */
```

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

```C
*p = 2;
```

![w:500](img/11-8.png)

```C
printf("%d\n",  i); /* 打印 2 */
printf("%d\n", *p); /* 打印 2 */
```

---



<!-- slide vertical=true data-notes="" -->

##### 间接寻址运算符

---

将间接寻址运算符用于未初始化的指针变量会导致未定义行为: 

```C
int *p;
printf("%d", *p); /*** 错误的 ***/
```

给*p赋值特别危险: 

```C
int *p;
*p = 1; /*** 错误 ***/
```

---



<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

C允许使用赋值运算符来复制相同类型的指针. 

```C
int i, j, *p, *q;
```

指针赋值: 

```C
p = &i;
```

---



<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

```C
q = p;
```

q现在指向与p相同的位置: 

![w:500](img/11-9.png)

---



<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

p和q都指向i, 可通过`*p`或`*q`赋值来更改i: 

```C
*p = 1;
```

![w:500](img/11-10.png)

---


<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

```C
*q = 2;
```

![w:500](img/11-11.png)

任意数量的指针变量都可以指向同一个对象. 

---



<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

指针赋值: 
```C
q = p;
```

指向的对象赋值: 
```C
*q = *p;
```

---


<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

```C
p = &i;
q = &j;
i = 1;
```

![w:500](img/11-12.png)

---



<!-- slide vertical=true data-notes="" -->

##### 指针赋值

---

```C
*q = *p;
```

![w:500](img/11-13.png)

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

decompose函数的定义: 

```C
void decompose(double x, long * int_part, double *frac_part)
{
  *int_part = (long) x;
  *frac_part = x - *int_part;
}
```
---


<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

decompose函数的声明: 

```C
void decompose(double x, long * int_part, double *frac_part);
```

或

```C
void decompose(double, long *, double *);
```

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

调用decompose函数: 

```C
void decompose(double x, long * int_part, double *frac_part);

int main(void) {
  int i, d;
  decompose(3.14159, &i, &d);
  ...
}
```

---


<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

指向i的指针存储在int_part中, 指向d的指针存储在frac_part中: 

![w:50](img/11-14.png)

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

decompose函数体中的第一个赋值将x的值转换为long类型, 并将其存储在int_part指向的对象中:

![w:500](img/11-15.png)




<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

第二个赋值把`x - *int_part`的值存储到frac_part指向的对象中: 

![w:500](img/11-16.png)

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

scanf调用中的参数是指针: 
```C
int i;
…
scanf("%d", &i);
```
如果没有&, 传递给scanf函数的将是i的值. 

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

scanf的参数必须是指针, 但并非总需要`&`运算符: 

```C
int i, *p;
…
p = &i;
scanf("%d", p);
```

使用&运算符是错误的: 
```C
scanf("%d", &p); /*** 错误 ***/
```

---


<!-- slide vertical=true data-notes="" -->

##### 指针作为参数

---

不正确地向函数传递所需要的指针可能导致灾难性的后果. 
缺少&运算符的decompose调用: 
```C
decompose(3.14159, i, d); 
```
当decompose在 `*int_part` 和 `*frac_part` 中存储值时, 它将修改未知的内存地址, 而不是修改 i 和 d . 

在scanf的例子中, 通常不会检查出传递指针失败. 

---



<!-- slide vertical=true data-notes="" -->

##### 函数调用使用指针

---

函数间使用指针主要是为了效率: 

- 传递大的数组变量需要大量的存储空间, 浪费存储空间, 也浪费时间(数组拷贝). 

---



<!-- slide vertical=true data-notes="" -->

##### 程序: 查找数组中最大和最小的元素

---

max_min.c程序使用名为 max_min 的函数来查找数组中的最大和最小元素. max_min的原型: 

```C
void max_min(int a[], int n, int *max, int *min);
```

max_min的调用示例: 

```C
max_min(b, N, &big, &small);
```

当max_min找到数组b中的最大元素时, 它通过将其赋值给\*max来将值存储在big中, 通过将b的最小元素赋值给\*min将其存储在small中. 

---



<!-- slide vertical=true data-notes="" -->

##### 程序: 查找数组中最大和最小的元素

---

max_min.c会将 10 个数字读入一个数组, 将其传递给max_min函数, 并打印结果: 
输入10个数字: <u>34 82 49 102 7 94 23 11 50 31</u>
最大: 102
最小: 7

---


<!-- slide vertical=true data-notes="" -->

##### 程序: 查找数组中最大和最小的元素

---

maxmin.c

```C{.line-numbers}
/* Finds the largest and smallest elements in an array */
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
  int b[N], i, big, small;

  printf("Enter %d numbers: ", N);
  for (i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }
  max_min(b, N, &big, &small);

  printf("Largest: %d\n", big);
  printf("Smallest: %d\n", small);

  return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
  int i;

  *max = *min = a[0];
  for (i = 1; i < n; i++) {
    if (a[i] > *max) {
      *max = a[i];
    } else if (a[i] < *min) {
      *min = a[i];
    }
  }
}
```

---



<!-- slide vertical=true data-notes="" -->

##### 使用const保护参数

---

当参数是指向变量x的指针时, 我们通常假设x将被修改: 

```C
f(&x);
```

但是, 有可能 f 只读 x 的值, 而不是修改它. 

---



<!-- slide vertical=true data-notes="" -->

##### 使用const保护参数

---

可以使用const来表明函数不会更改指针参数所指向的对象. 

const放置在形式参数的声明中, 后面紧跟着其类型说明: 
```C
void f(const int *p)
{
  int j;
  *p = 0; /*** 错误 ***/
  p = &j; /*** 合法 ***/
}
```

尝试修改\*p, 编译器会报错. 

---



<!-- slide vertical=true data-notes="" -->

##### 使用const保护参数

---


```C
void f(int * const p)
{
  int j;
  *p = 0; /*** 合法 ***/
  p = &j; /*** 错误 ***/
}
```

```C
void f(const int * const p)
{
  int j;
  *p = 0; /*** 错误 ***/
  p = &j; /*** 错误 ***/
}
```

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为返回值

---

允许函数返回指针: 

```C{.line-numbers}
int *max(int *a, int *b)
{
  if (*a > *b)
    return a;
  else
    return b;
}
```

max函数返回作为参数传递给它的指针. 

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为返回值

---

调用max函数: 

```C
int *p, i, j;
…
p = max(&i, &j);
```

调用后, p指向i或j. 

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为返回值

---

函数还可以返回指向外部变量或静态局部变量的指针, 但永远不要返回指向自动局部变量的指针: 
```C
int *f(void)
{
  int i;
  …
  return &i; // i是局部变量, 错误代码
}
```

函数f返回后变量i对象不存在. 

---



<!-- slide vertical=true data-notes="" -->

##### 指针作为返回值

---

指针可以指向数组元素. 
如果a是一个数组, 则`&a[i]`是指向a中元素i的指针. 
函数返回指向数组中某个元素的指针有时很有用. 
下面的函数假设a有n个元素, 返回一个指向数组中间元素的指针: 
```C
int *find_middle(int a[], int n) {
    return &a[n/2];
}
```

---

<!-- slide vertical=true data-notes="" -->



##### 动态内存分配

---

`malloc`和`free`

C函数库提供`malloc`和`free`，分别用于执行动态内存的==分配==与==释放==

```C{.line-numbers}
int *a = NULL;
a = (int *)malloc(n * sizeof(int));
free(a);
```

申请后需要释放

<!-- slide vertical=true data-notes="" -->



##### 函数malloc

---

```C{.line-numbers}
#include<stdlib.h>
void *malloc(size_t _Size);
```

向`malloc`申请的空间的大小是以字节为单位的
返回类型默认是`void *`

```C
int *array = (int *) malloc(len * sizeof(int))
int *array = malloc(len * sizeof(int))
int *array = malloc(len * sizeof(*array))
```

示例: `malloc.c`

<!-- slide vertical=true data-notes="" -->



##### free

---

```C
#include<stdlib.h>
void free(void *pointer);
```

free(ptr):释放指针指向内存，指针变量依然存在(野指针)

为防止释放后写, 建议 ptr = NULL

- 需要释放之前动态申请的内存, 一对一配对使用
- 内存泄漏memory leak

示例: `malloc_space.c`


<!-- slide vertical=true data-notes="" -->



##### 动态内存分配的常见错误

---

- 申请了没有free

- 对NULL指针进行解引用

- 对分配的内存越界操作

- 释放并非动态分配的内存（段错误）

- 试图释放动态分配的内存的部分

- 释放后依旧试图继续使用



<!-- slide vertical=true data-notes="" -->


##### 一些其他memory allocation函数

---

```C
void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void *realloc(void *ptr, size_t new_size);
void free(void *ptr);
```

- malloc: allocates memory

- calloc: allocates and zeros memory

- realloc: expands previously allocated memory block

- free deallocates previoulsy allocated memory
---