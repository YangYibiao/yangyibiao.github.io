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

## 多文件组织

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 源文件与头文件

- #include、共享宏/类型/函数原型

- 保护头文件

- 构建多文件程序与 makefile

---


<!-- slide data-notes="" -->


##### 源文件

---

可以把 C 程序分割成任意数量的**源文件**. 

按照惯例, 源文件的扩展名是`.c`. 

每个源文件都包含程序的一部分, 主要是函数和变量的定义. 

其中一个源文件必须包含一个名为main的函数, 它是程序的起点. 


---

考虑编写一个简单的计算器程序的问题. 

该程序将计算以逆波兰表示法(RPN)输入的整数表达式, 运算符都跟在操作数后面. 

如果用户输入一个表达式, 例如: 

`30 5 - 7 *`

程序应打印其值(在本例中为175).


程序将逐个读取操作数和运算符, 使用栈来跟踪中间结果. 

- 如果程序读取一个数字, 它会将这个数字压入栈. 

- 如果程序读取一个运算符, 会从栈中弹出两个数字执行操作, 然后将结果压回栈. 

当程序执行到用户输入的末尾时, 表达式的值将在栈中.


计算表达式`30 5 - 7 *`的值: 
1. 将 30 压入栈. 
2. 将 5 压入栈. 
3. 从栈中弹出两个数字, 用30减5, 得到25, 然后将结果压回栈. 
4. 将 7 压入栈. 
5. 从栈中弹出两个数字, 将它们相乘, 然后将结果压回栈. 

栈现在将包含 175, 即表达式的值.


该程序的main函数将包含一个执行以下操作的循环: 

- 读取"记号"(数或运算符). 

- 如果记号是数字, 则将其压入栈. 

- 如果记号是运算符, 则从栈中弹出其操作数进行运算, 然后将结果推回栈.  

在将这样的程序分割为文件时, 将相关的函数和变量放在同一个文件中是有意义的.

---


<!-- slide data-notes="" -->


##### 源文件 (续)

---

读取记号的函数可以与任何需要用到记号的函数一起放入一个源文件(例如*token.c*). 

与栈相关的函数, 如push, pop, make_empty, is_empty和is_full可以放入另一个文件*stack.c*中. 

代表栈的变量也放入stack.c. 

main函数放入另一个文件calc.c中.


将程序拆分为多个源文件具有显着优势: 

- 将相关函数和变量分组到一个文件中可以使程序的结构清晰. 

- 每个源文件都可以单独编译, 节省时间. 

- 将函数分组放在不同的源文件中更利于复用.

---


<!-- slide data-notes="" -->


##### 头文件

---

当一个程序被分成几个源文件时出现的问题: 

- 一个文件中的函数如何调用另一个文件中定义的函数？ 

- 函数如何访问另一个文件中的外部变量？ 

- 两个文件如何共享相同的宏定义或类型定义？

`#include`指令, 它可以在任意数量的源文件之间共享信息. 


---

`#include`指令告诉预处理器插入指定文件的内容. 

可以将要在多个源文件之间共享的信息放入这样的文件中. 

`#include`然后可用于将该文件的内容带入每个源文件. 

以这种方式包含的文件称为**头文件**(有时称为包含文件). 

按照惯例, 头文件的扩展名为`.h`.

---


<!-- slide data-notes="" -->


##### #include 指令

---

`#include`指令有两种主要形式. 

第一个用于属于 C 自身库的头文件: 

```C
#include <文件名>
```

第二个用于所有其他头文件: 

```C
#include "文件名"
```

两者的区别在于编译器如何定位头文件.


定位头文件的典型规则: 

- ＃include <文件名>: 搜索系统头文件所在的目录(或多个目录). 

- ＃include "文件名": 先搜索当前目录, 后搜索系统头文件所在的目录(或多个目录). 

通常可以通过命令行选项(例如-I 路径)来更改搜索头文件的位置.


包含自己编写的头文件时不要使用尖括号: 

```C
#include <myheader.h> /*** 错误 ***/
```

预处理器可能会在保存系统头文件的地方查找*myheader.h*.


`#include`指令中的文件名可能包含有助于定位文件的信息, 例如目录的路径或驱动器号: 

```C
#include "c:\cprogs\utils.h"
/* Windows 路径 */

#include "/cprogs/utils.h"
/* UNIX 路径 */
```

`#include`指令中的引号使文件名看起来像字符串字面量, 但预处理器不会那样对待它们.


最好不要在`#include`指令中包含路径或驱动器信息. 

Windows `#include`指令的不良示例: 

```C
#include "d:utils.h"
#include "\cprogs\include\utils.h"
#include "d:\cprogs\include\utils.h"
```

更好的版本: 

```C
#include "utils.h"
#include "..\include\utils.h"
```


`#include`指令有第三种形式: 

```C
#include 标记
```

标记是任意预处理标记序列. 预处理器使用宏定义方式替换. 

宏替换完成后, `#include`指令的格式一定与前面两者之一匹配. 

该`#include`优点是文件名由宏定义, 不需"硬拷贝"到指令本身.


例子: 

```C
#if defined(IA32)
  #define CPU_FILE "ia32.h" 
#elif defined(IA64)
  #define CPU_FILE "ia64.h" 
#elif defined(AMD64)
  #define CPU_FILE "amd64.h"
#endif

#include CPU_FILE
```

---


<!-- slide data-notes="" -->


##### 共享宏定义和类型定义

---

大多数大型程序包含由多个源文件共享的宏定义和类型定义. 

这些定义应该放入头文件.


假设一个程序使用名为BOOL, TRUE和FALSE的宏. 

它们的定义可以放在一个名为*boolean.h*的头文件中: 

```C{.line-numbers}
#define BOOL int
#define TRUE 1
#define FALSE 0
```

任何需要这些宏的源文件将只包含该行

```C
#include "boolean.h"
```


两个文件都包含了boolean.h: 

<div class="top-2">
  <img src="../img/18-1.png">
</div>


类型定义在头文件中也很常见. 

例如可使用typedef来创建一个Bool类型, 而不是定义BOOL宏. 

如果我们这样做, boolean.h文件将有下列显示: 

```C
#define TRUE 1
#define FALSE 0
typedef int Bool;
```


将宏和类型的定义放在头文件中的优点: 

- 节省时间. 我们不必将定义复制到需要它们的源文件中. 

- 使程序更容易修改. 更改宏或类型的定义只需要编辑单个头文件. 

- 避免由源文件包含相同宏或类型的不同定义而导致的不一致.

---


<!-- slide data-notes="" -->


##### 共享函数原型

---

假设源文件包含对另一个文件foo.c中定义的函数f的调用. 

没有先声明的情况下调用f是有风险的. 

- 编译器假定f的返回类型是int. 

- 并假定形式参数的数量与f调用中的实际参数数量相匹配. 

- 实际参数自身由默认参数提升自动转换.


声明f可以解决问题, 但会造成维护方面的"噩梦". 

更好的方案是将f的原型放在头文件(foo.h)中, 然后将头文件包含在所有调用f的地方. 

还需要在foo.c中包含foo.h, 使编译器能够检查f在foo.h中的原型是否与它在foo.c中的定义相匹配.


如果foo.c包含其他函数, 则大多数应在foo.h中声明. 

但是, 仅在foo.c中使用的函数不应在头文件中声明；这样做会产生误导.


RPN 计算器示例用于说明头文件中函数原型的使用. 

*stack.c*包含make_empty, is_empty, is_full, push和pop函数的定义. 

这些函数的原型应放在stack.h头文件中: 

```C{.line-numbers}
void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);
```


文件calc.c中将包含stack.h以允许编译器检查出现在后一个文件中的栈函数的任何调用. 

文件stack.c中也将包含stack.h, 以便编译器可以验证stack.h中的原型是否与stack.c中的定义匹配.


<div class="top-2">
  <img src="../img/18-2.png">
</div>

---


<!-- slide data-notes="" -->


##### 共享变量声明

---

为了在文件之间共享一个函数, 将其定义放在一个源文件中, 然后将声明放在需要调用该函数的其他文件中. 

共享外部变量的方式大致相同.


一个同时声明和定义i的示例(使编译器为i留出空间): 

```C
int i;
```

关键字extern用于声明一个变量而不定义它: 

```C
extern int i;
```

extern告诉编译器i在程序的其他地方定义, 无需为其分配空间.


在数组的声明中使用extern时, 可以省略数组的长度: 

```C
extern int a[];
```

由于此时编译器没有为a分配空间, 所以不需要知道a的长度.


在多个源文件之间共享变量i, 首先将i的定义放在一个文件中: 

```C
int i;
```

如果i需要初始化, 可以把初始化式放在这里. 

其他文件将包含i的声明: 

```C
extern int i;
```

通过在每个文件中声明i, 就可以在这些文件中访问和/或修改i.


当同一变量的声明出现在不同的文件中时, 编译器无法检查声明是否与变量的定义匹配. 

例如, 一个文件可能包含定义

```C
int i;
```

而另一个文件包含声明

```C
extern long i;
```

这种错误会导致程序的行为异常.


为了避免不一致, 共享变量的声明通常放在头文件中. 

然后, 需要访问特定变量的源文件可以包含相应的头文件. 

此外, 含有变量定义的源文件需要包含含有变量声明的头文件, 使编译器能够检查两者是否匹配.

---


<!-- slide data-notes="" -->


##### 嵌套包含

---

头文件可能包含`#include`指令. 

stack.h包含以下原型: 

```C
int is_empty(void);
int is_full(void);
```

由于这些函数只返回 0 或 1, 最好将它们的返回类型声明为Bool: 

```C
Bool is_empty(void);
Bool is_full(void);
```

在 stack.h 中包含boolean.h, 以便在编译时可以使用Bool的定义.


传统上, C 程序员避免使用嵌套包含. 

然而, 对嵌套包含的偏见已经在很大程度上消失了, 部分原因是嵌套包含是 C++ 中的常见做法.

---


<!-- slide data-notes="" -->


##### 保护头文件

---

如果一个源文件两次包含相同的头文件, 可能会导致编译错误. 

当头文件包含其他头文件时, 此问题很常见. 

假设file1.h包含file3.h, file2.h包含file3.h, prog.c包含file1.h和file2.h.


<div class="top-2">
  <img src="../img/18-3.png">
</div>

编译prog.c时, file3.h将被编译两次.


两次包含相同的头文件并不总是会导致编译错误. 

如果文件只包含宏定义, 函数原型和/或变量声明, 则不会有任何困难. 

但是, 如果文件包含类型定义, 则会带来编译错误.


安全起见, 保护所有头文件不被多次包含可能是个好主意. 

这样, 可以稍后将类型定义添加到文件中, 而不会有忘记保护文件的风险. 

此外, 在程序开发过程中, 避免不必要地重新编译相同的头文件可以节省一些时间.


为了保护头文件, 将文件的内容包含在#ifndef - #endif对中. 

如何保护boolean.h文件: 

```C{.line-numbers}
#ifndef BOOLEAN_H
#define BOOLEAN_H

#define TRUE 1
#define FALSE 0
typedef int Bool;

#endif
```


使宏的名称类似于头文件的名称是避免与其他宏冲突的好方法. 

由于不能命名宏BOOLEAN.H, 所以像BOOLEAN_H这样的名称是一个不错的选择.

---


<!-- slide data-notes="" -->


##### 将程序划分为文件

---

设计程序需确定程序需要什么函数并将函数分为逻辑相关的组. 

一旦设计好程序, 就有一种简单的方法可以将其分成文件. 


---

每组函数都将放入一个单独的源文件(foo.c). 

为每个源文件创建一个同名的头文件(foo.h). 

- foo.h将包含foo.c中定义的函数的原型. 

- 仅在foo.c中使用的函数不应在foo.h中声明. 

foo.h将包含在需要调用foo.c中定义的函数的每个源文件中. 

foo.c也将包含foo.h, 编译器检查函数原型与定义是否匹配.


main函数将放入一个名称与程序名称匹配的文件中. 

main所在的文件中也可以有其他函数, 只要程序中的其他文件不会调用它们.

---


<!-- slide data-notes="" -->


##### 构建多文件程序

---

构建大型程序与构建小型程序所需的基本步骤相同: 

- 编译

- 链接


---

程序中的每个源文件都必须单独编译. 

头文件不需要编译. 

每当编译包含它的源文件时, 都会自动编译头文件的内容. 

对于每个源文件, 编译器都会生成一个包含目标代码的文件. 

这些文件(称为**目标文件**)在UNIX中具有扩展名.o, 在Windows中具有扩展名.obj.


链接器将上一步产生的目标文件与库函数的代码结合起来, 生成一个可执行文件. 

链接器的一个职责是解决编译器遗留的外部引用问题. 

当一个文件中的函数调用另一个文件中定义的函数或访问另一个文件中定义的变量时, 就会发生外部引用.


大多数编译器允许一步构建程序. 

构建justify的 GCC 命令:  
`gcc -o justify justify.c line.c word.c`

这三个源文件首先被编译成目标代码. 

然后目标文件自动传递给链接器, 链接器将它们组合成一个文件. 

-o选项表明我们希望将可执行文件命名为justify.

---


<!-- slide data-notes="" -->


##### makefile

---

为了更容易构建大型程序, UNIX发明makefile的概念.  

makefile不仅列出了作为程序一部分的文件, 而且还描述了文件之间的依赖关系. 

假设文件foo.c包含文件bar.h. 

我们说foo.c"依赖于"bar.h, 因为修改bar.h之后需要重新编译foo.c.


针对justify程序的UNIX系统的makefile: 
```
justify: justify.o word.o line.o
        gcc -o justify justify.o word.o line.o
	 
justify.o: justify.c word.h line.h
        gcc -c justify.c
	 
word.o: word.c word.h
        gcc -c word.c
	 
line.o: line.c line.h
        gcc -c line.c
```


有4组代码行；每个组称为一条规则. 

每个规则的第一行给出目标文件, 然后是它所依赖的文件. 

第二行是当目标文件依赖的文件发生改变而需要重新构建目标文件时要执行的命令.


在第一条规则中, justify(可执行文件)是目标文件: 
```
justify: justify.o word.o line.o
	      gcc -o justify justify.o word.o line.o
```

第一行说明justify依赖于文件justify.o, word.o和line.o. 

如果自上次构建程序以来这些文件中的任何一个发生了更改, 则需要重新构建justify. 

下一行的命令显示了如何进行重新构建.

---


<!-- slide data-notes="" -->


##### 链接期间的错误

---

一些编译时检测不到的错误会在链接时发现. 

如果程序中缺少函数或变量的定义, 链接器将无法解析对其的外部引用

导致出现诸如"undefined symbol"或"undefined reference"之类的消息.


链接过程中常见的错误原因: 
- 拼写错误. 如果变量或函数的名称拼写错误, 链接器将报告它丢失. 
- 缺少文件. 如果链接器找不到文件foo.c中的函数, 它可能不知道该文件. 
- 缺少库. 链接器可能无法找到程序中使用的所有库函数. 

在 UNIX 中, 当链接使用<math.h>的程序时, 可能需要指定-lm选项.

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 头文件里通常放什么？源文件 (.c) 里放什么？

2. 为什么头文件要加"保护宏"（#ifndef … #define … #endif）？

3. 三个 .c 文件一起编译，gcc 命令怎么写？

4. 把函数原型放进头文件、函数定义放进 .c 文件，有什么好处？

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="../figs/see-you.png" width=500px>
</div>

---


