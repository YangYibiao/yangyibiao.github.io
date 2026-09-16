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

# 智能程序设计（C语言）

<hr class="width50 center">

## 指针数组与函数指针

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 指向指针的指针

- 指针数组与带参数的 main

- 函数指针与 qsort

- AI 赋能程序设计 II

---


<!-- slide data-notes="" -->


##### 指向指针的指针

---

第 13 章介绍了指向指针的指针的概念. 

"指向指针的指针"的概念也经常出现在链式数据结构中. 

特别是, 当函数的实际参数是指针变量时, 可能会希望函数能够修改变量. 

这样做需要使用指向指针的指针. 


---

向add_to_list函数传递一个指向原始链表首结点的指针; 它返回一个指向新链表首结点的指针: 

```C{.line-numbers}
struct node *add_to_list(struct node *list, int n)
{
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = list;
  return new_node;
}
```


如果要修改add_to_list, 把new_node赋值给list, 而不是返回new_node, 这是不起作用的. 

调用函数: 
`add_to_list(first, 10);`

在调用点, first被复制到list中. 

函数可以改变list的值, 使其指向新结点, 但first不受影响.


让函数add_to_list修改first是可能的, 需要向add_to_list传递一个指向first的指针: 

```C{.line-numbers}
void add_to_list(struct node **list, int n)
{
  struct node *new_node;
   
  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->next = *list;
  *list = new_node;
}
```

---


<!-- slide data-notes="" -->


##### 命令行参数: 带参数的 main

---

运行程序时, 经常需要提供一些信息. 

这可能包括文件名或修改程序行为的开关. 

UNIX `ls`命令的示例: 

```
ls
ls –l
ls -l remind.c
```


命令行信息对所有程序都是可用的, 不仅仅是操作系统命令. 

要访问 ==命令行参数==, main必须含有两个参数: 
```C
int main(int argc, char *argv[])
{
  …
}
```

命令行参数在 C 标准中称为 ==程序参数==.


argc: (argument count)参数计数是命令行参数的数量. 

argv: (argument vector)参数向量是指向命令行参数的指针数组(以字符串形式存储). 

argv[0]指向程序名, 而argv[1]到argv[argc-1]指向剩余的命令行参数. 

argv[argc]总是一个空指针——一个不指向任何东西的特殊指针. 

宏NULL表示一个空指针.

---


<!-- slide data-notes="" -->


##### 指向函数的指针

---

C 不要求指针只指向数据; 也可以有指向函数的指针. 

函数占用内存单元, 因此每个函数都有一个地址. 

可以像使用指向数据的指针一样使用函数指针. 

将函数指针作为参数传递是相当普遍的. 


---

编写integrate函数求函数f在a点和b点之间的积分, 可以把f作为参数传入, 从而使其尽可能通用. 

integrate原型: 
```C
double integrate(double (*f)(double), double a, double b);
```
`*f`两边的括号表示f是指向函数的指针. 

另一种原型: 
```C
double integrate(double f(double), double a, double b);
```

---


<!-- slide data-notes="" -->


##### 函数指针作为参数

---

调用integrate计算sin函数从0到$\pi$/2的积分: 

`result = integrate(sin, 0.0, PI/2);`

当函数名后面没有括号时, C 编译器会生成一个指向该函数的指针. 

在integrate函数体内, 可以调用f指向的函数: 

`y = (*f)(x);`

允许使用f(x)代替(*f)(x) .

---


<!-- slide data-notes="" -->


##### qsort函数

---

C 库中一些功能强大的函数要求把函数指针作为参数. 

其中之一是qsort, 它的原型在<stdlib.h>中. 

qsort是一个通用的排序函数, 能够对任何数组进行排序.


必须告诉qsort如何确定两个数组元素中的哪个"更小". 

这是通过向qsort传递一个指向比较函数的指针来完成的. 

当给定两个指向数组元素的指针p和q时, 比较函数必须返回一个整数, 即: 

- 如果*p “小于” *q, 返回负数; 

- 如果*p “等于” *q, 返回零; 

- 如果*p “大于” *q, 返回正数.


qsort的原型: 
```C
void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
```

base必须指向数组中的第一个元素(或要排序的部分中的第一个元素). 

nmemb是要排序的元素数. 

size是每个数组元素的大小, 以字节为单位. 

compar是指向比较函数的指针.

---


<!-- slide data-notes="" -->


##### 函数指针的其他用途

---

尽管函数指针经常用作参数, 但这并不是它们的全部优点. 

C 将指向函数的指针视为指向数据的指针. 

它们可以存储在变量中, 也可以用作数组的元素, 结构或联合的成员. 

函数甚至可以返回函数指针.


可以存储指向函数的指针的变量, pf指向具有int型参数且返回void型值的函数: 

```C
void (*pf)(int);
```

如果f是这样一个函数, 可以通过以下方式使pf指向f: 

`pf = f;`

可以通过以下方式调用f: 

`(*pf)(i);`

或者

`pf(i);`

---


<!-- slide data-notes="" -->


##### 程序: 列三角函数表

---

tabulate.c程序打印显示cos、sin和tan函数值的表格. 

程序围绕名为tabulate的函数构建, 当传递函数指针f时, 它会打印出函数f的值. 

tabulate使用了ceil函数. 

当给定一个double类型的参数x时, ceil返回大于或等于x的最小整数.


tabulate.c的会话: 
```
Enter initial value: 0
Enter final value: .5
Enter increment: .1

     x        cos(x)
  -------    -------
  0.00000    1.00000
  0.10000    0.99500
  0.20000    0.98007
  0.30000    0.95534
  0.40000    0.92106
  0.50000    0.87758

     x        sin(x)
  -------    -------
  0.00000    0.00000
  0.10000    0.09983
  0.20000    0.19867
  0.30000    0.29552
  0.40000    0.38942
  0.50000    0.47943

     x        tan(x)
  -------    -------
  0.00000    0.00000
  0.10000    0.10033
  0.20000    0.20271
  0.30000    0.30934
  0.40000    0.42279
  0.50000    0.54630
```

---


<!-- slide data-notes="" -->

##### AI 赋能程序设计 II

---

==AI 与指针/函数指针==

- ==调试指针错误==: 把段错误 (Segmentation fault) 的代码发给 AI, 让它指出越界/未初始化指针
- ==解释疑难语法==: 让 AI 解释 `int (*f)(int, int)` 与 `int *f(int, int)` 的区别
- ==生成测试==: 让 AI 为你的字符串函数生成边界测试用例 (空串、超长串)
- ==项目陪练==: 第 15 周的 AI 实践项目, 可用 AI 做"结对伙伴", 但==代码必须自己读懂==

规则不变: ==先自己写, 再让 AI 改==。

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `int **pp;` 是什么？它和 `int *p;` 的区别？

2. `int a[5]; int *pa[5];` 中，`pa` 是什么？`pa[0]` 是什么类型？

3. `int (*f)(int, int);` 声明的是什么？`f = add;` 之后怎么通过 f 调用 add？

4. `qsort` 的第四个参数是什么类型？为什么排序函数需要它？

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="../figs/see-you.png" width=500px>
</div>

---


