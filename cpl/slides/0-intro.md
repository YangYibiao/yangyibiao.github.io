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

## 课程介绍与C语言概述

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide vertical=true data-notes="" -->

##### 课程安排

---

授课: [杨已彪](http://cs.nju.edu.cn/yangyibiao), yangyibiao@nju.edu.cn

时间: 

- 理论: 45 学时理论，周五 2-4 节课 (第 3 ~ 17 周)

- 实验: 在线测试(OJ: Online Judge)

<span class="blue">:fa-lightbulb-o:</span> =="Talk is cheap. Show me the code."== -- Linus Torvalds
<span class="blue">:fa-lightbulb-o:</span> ==纸上得来终觉浅，绝知此事要躬行== -- 陆游



<!-- slide vertical=true data-notes="" -->

##### 课程答疑

---

[https://docs.cpl.icu/#/qa](https://docs.cpl.icu/#/qa)


<!-- slide vertical=true data-notes="" -->

##### 考核方式

---
(技术科学实验班+软件学院)

- 平时编程: 10% (每周1次OJ编程练习, 在线提交评测)

- 阶段机试 (15% + 20%)

- 课程项目: 25%(指选 + 自选题目（待定: 可能为期中项目, 也可能作为期末项目)

- 期末机试: 30% (上机编程考试: 在线、限时、闭卷)

- 教案发布: https://yangyibiao.github.io/cpl/index.html

- 课程网站: http://docs.cpl.icu

- 在线评测: http://oj.cpl.icu/




<!-- slide vertical=true data-notes="" -->

##### 课程说明

---

申请免修不免考直接教务网提交申请.

<!-- 申请免修不免考意味着: 因免修造成的一切后果自负, 而且平时作业、大作业、上机测验和期中/期末等均不免. -->

==强烈建议== 自学课件与教材中的内容; 

==友情提醒== 平时作业、上机测验、大项目等均需按时完成.




<!-- ##### 课程QQ群

---

发布教案、讨论、发布OJ实训作业

- 课程网站: https://cslab-cms.nju.edu.cn/

- 邀请码: H3RPB

- 课程QQ群: 651382342

  <img src="figs/img/QQgroup.jpeg" width=200px>
 -->


<!-- slide vertical=true data-notes="" -->

##### 课程教材

---

<div class="top-2">
  <img src="figs/img/book/cpm.jpg" width=200px height=270px>
</div>

- 书名: C语言程序设计 现代方法 第2版·修订版 (吕秀锋, 黄倩 译)

- 作者: K.N.King

- 出版: 人民邮电出版社



<!-- slide data-notes="" -->

##### 参考书目

---

<div class="top-2">
  <img src="figs/img/book/The_C_Programming_Language.png" width=200px height=270px>
</div>

- 书名: C程序设计语言

- 作者: (美)Brian W. Kernighan / (美)Dennis M. Ritchie

- 译者: 徐宝文、李志

- 出版: 机械工业出版社


<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## C语言概述

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 概述

---

- 计算机与编程语言

- 为什么学习==C语言==


<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

什么是计算机?

计算机: 

* 由==硬件==和==软件==组成

* 用于==接收、处理和存储数据==的电子设备

硬件：输入设备、输出设备、存储设备、CPU、内存、主板等物理组件

软件：操作系统、应用程序等，执行各种任务



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机的基本功能：

- ==输入==：各种输入设备（如键盘、鼠标、摄像头等）接收数据和指令

- ==处理==：通过中央处理器（CPU）执行指令，进行数据处理和计算。CPU为计算机核心组件，负责执行程序中的逻辑和算术运算。

- ==输出==：通过输出设备（如显示器、打印机、扬声器等）将处理结果呈现给用户。

- 存储：使用内存和存储设备来存储数据和程序。内存：临时存储正在处理的数据；存储设备：长期保存信息。

- 控制：通过操作系统和应用程序管理硬件资源，协调各组件的工作。



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机如何工作: 制作一杯咖啡

步骤分解:

1. 确定所需材料（咖啡粉、水、糖、牛奶等）

2. 煮水

3. 加入咖啡粉

4. 混合均匀

5. 根据需要加入糖或牛奶


将大问题==分解==为具体小步骤，逐步解决每个部分



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机如何工作: 制作一杯咖啡

1. ==输入==
材料准备：
咖啡粉、热水、牛奶（可选）、糖（可选）

2. ==处理==
步骤：
煮水：将水加热到适合冲泡咖啡的温度。
冲泡咖啡：将热水倒入咖啡粉中，等待几分钟，让咖啡充分浸泡。
加牛奶和糖（可选）：根据个人口味，加入牛奶和糖。

3. ==存储==
等待时间：在冲泡咖啡的过程中，咖啡的状态和时间可以视为存储。咖啡需要在特定时间内浸泡，以确保味道。

4. ==输出==
享用咖啡：完成后，将咖啡倒入杯中，准备饮用。



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机如何工作: 计算购物总价

假设你在超市购物, 购买了以下商品: 

- 苹果: 3个, 每个2元

- 香蕉: 5个, 每个1.5元

- 橙子: 2个, 每个3元



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机如何工作: 计算购物总价

1. ==输入==
计算机接收用户输入的信息: 
苹果数量: 3, 苹果单价: 2元
香蕉数量: 5, 香蕉单价: 1.5元
橙子数量: 2, 橙子单价: 3元

2. ==处理==
计算机执行以下计算: 
苹果总价 = 苹果数量 × 苹果单价 = 3 × 2 = 6元
香蕉总价 = 香蕉数量 × 香蕉单价 = 5 × 1.5 = 7.5元
橙子总价 = 橙子数量 × 橙子单价 = 2 × 3 = 6元

3. ==计算总价== 
总价 = 苹果总价 + 香蕉总价 + 橙子总价 = 6 + 7.5 + 6 = 19.5元

4. ==输出==
计算机将结果输出到屏幕上:
"购物总价为: 19.5元"
 


<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

制作咖啡/计算购物总价的过程，我们可以看到计算机的工作原理：

==输入==: 材料和配方（用户输入的数据）。
==处理==: 加热、冲泡和混合（CPU 执行指令）。
==存储==: 等待时间和状态（内存中的数据）。
==输出==: 完成的咖啡（计算机的结果展示）。



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

编程: 使用特定的==编程语言==编写指令, 控制计算机执行特定任务

- 接收输入

- 处理数据

- 存储数据

- 输出数据



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

计算机如何工作的?

![alt text](../img/howcomputerworks.png)



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

语言是人类沟通、交流的工具，交流思想、传递知识等

- ==符号==系统：语言由一系列符号（如词汇、字、音节）组成，每个符号都有特定的意义

- ==语法==规则：语言遵循特定的语法和结构规则，指导如何将符合组合成有意义的句子或表达



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

编程语言是用于与计算机进行交流的正式(formal)语言，提供一套规则和语法，使程序员能编写指令，以控制计算机的行为。

- 符号和语法：由特定符号、关键词和语法规则构成，能使用规则编写源代码

- 数据结构：提供用于组织和存储数据的方式，如数组、结构体等

- 控制结构：条件语句(如if, swtich)和循环(如for, while), 用于控制程序的执行流程



<!-- slide vertical=true data-notes="" -->

##### 计算机与编程语言

---

编程思维

- 逻辑思维
判断一个用户输入的数是否为偶数
- 问题分解：
制作一个简单的计算器（输入运算符
- 算法思维
排序用户输入的一组数字
- 抽象化
交通信号灯，抽象为3种状态
- 算法思维
将一组数字排序，比较相邻元素，如果顺序错误则交换，重复直到没有交换为止
- 条件判断
根据天气决定穿衣，如果下雨，穿雨衣或带雨伞，否则穿短袖
- 循环
打印1到100的数字



<!-- slide data-notes="" -->

##### C语言的起源

---

C语言起源可追溯到1970年代中期

==贝尔实验室==：C语言是在美国贝尔实验室（Bell Labs）由Dennis Ritchie和同事开发

==早期的开发==：C语言最早是在1972年创建，最初用于编写操作系统，特别是UNIX操作系统。Ritchie和团队使用C语言重写了UNIX的核心部分。



<!-- slide data-notes="" -->

##### C语言的起源

---

==标准化==：1978年，Brian Kernighan和Dennis Ritchie合著了《C程序设计语言》，对C语言的推广起到了重要作用。1989年，C语言被正式标准化为ANSI C，这为后来的C语言版本奠定了基础。

==影响力==：C语言以其高效性和灵活性被广泛应用于系统编程、嵌入式系统以及应用程序开发。它的设计理念和语法影响了后续许多编程语言，如C++、Java和C#等。



<!-- slide data-notes="" -->

##### C语言的标准化

---

K&R C

- Kernighan和Ritchie合作编写了《C程序设计语言》(1978)
- 没有正式的C语言标准, 这本书成了事实标准

C89/C90
- ANSI标准X3.159-1989(1988年完成, 1989年12月正式批准)
- 国际标准ISO/IEC 9899:1990

C99
- 国际标准ISO/IEC 9899:1999
- 包含了一些重要的改变



<!-- slide data-notes="" -->

##### 基于C的语言

---

C++包括C的所有特性, 添加了类和其他特性以支持面向对象编程

Java基于C++, 因此继承了许多C特性

C#是从C++和Java派生的新的语言

Perl吸收了C的许多特性



<!-- slide data-notes="" -->

##### C的特点

---

1. ==低层语言==
提供了对机器级概念的访问(字节和地址)

2. ==小型语言==
更有限的特性集合(K&R第2版参考手册仅用49页描述了整个C语言)
C语言很大程度依赖一个标准函数的库

3. ==宽松包容==
提供了比其他语言更高的自由度, 不强制进行详细的错误检查



<!-- slide data-notes="" -->

##### C的优点

---

- ==效率高==
- ==可移植==
- ==灵活==: C语言特性使用的限制非常少
- 功能强大: 庞大的数据类型和运算符集合
- 标准库
- 与LINUX集成



<!-- slide data-notes="" -->

##### C的缺点

---

- 程序容易隐藏错误

- 程序可能难以理解

- 程序可能难以维护



<!-- slide data-notes="" -->

##### 有效使用 C

---

- 深入理解以避免C语言的陷阱

- 避免过于复杂的代码

- 使用软件工具(lint, 调试器)使程序更可靠

- 利用现有的代码库

- 采用一套合理的编码规范

- 紧贴标准




<!-- - 输入：数据接收：计算机通过输入设备（如键盘、鼠标、扫描仪等）接收数据和指令。用户通过这些设备向计算机提供信息。

- 处理

-- 中央处理器（CPU）：CPU 是计算机的核心组件，负责执行指令和进行数据处理。它从内存中获取指令，并执行运算（如加法、减法）和逻辑判断（如条件判断）。
-- 指令周期：CPU 执行指令的过程通常分为取指（Fetch）、解码（Decode）和执行（Execute）三个阶段。
    
    - 取指：从内存中获取下一条指令。

    - 解码：将指令翻译为CPU可以理解的操作。
    
    - 执行：执行指令，处理数据。 -->


<!-- ##### 计算机与编程语言

---

算法思维：排序问题

将一组数字排序如（5，3，8，1）

算法：相邻元素


##### 计算机与编程语言

---

抽象化: 交通信号灯

抽象：交通信号灯有三种状态（红灯、黄灯、绿灯），每个状态对应不同的行为

不关注具体的设备，而是关注其功能和状态， -->

<!-- C 是 UNIX 的副产品, 由 Ken Thompson,  等人在贝尔实验室开发.

Thompson 设计了一种名为 B 的小型语言. 

B 基于 BCPL, 一种在 1960 年代中期开发的系统编程语言. -->
<!-- 到 1971 年, Ritchie 开始开发 B 的扩展版本.

起初, 他称他的语言为 NB("New B").

随着语言开始与B越来越不同, 他将其名称改为C.

到 1973 年, 该语言已经足够稳定, 可以用 C 重写 UNIX. -->



<!-- slide data-notes="" -->


<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## C语言基础

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->


##### 提纲

---

- 指令

- 函数

- 语句



<!-- slide vertical=true data-notes="" -->


##### 程序: 打印Hello NJU

---

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("Hello, NJU!\n");
  return 0;
}
```

- 代码可存储在 ==任意文件名== 的文件中, 通常用 ==`.c`== 作为扩展名, 假设文件名为`hw.c`

- 使用编译命令 ==`gcc hw.c`== 默认会将编译生成的可执行程序存储为`a.out`文件

- 使用编译命令 ==`gcc hw.c -o hw`== 可指定编译生成的可执行程序文件名为`hw`



<!-- slide data-notes="" -->


##### 程序: 打印Hello NJU

---

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("Hello, NJU!\n");
  return 0;
}
```

- ==`#include`== 为预处理指令, 引入C语言标准输入/输出库的头文件*stdio.h*

- ==`main函数`== 主函数, 程序入口, 任何C程序都需要一个main函数

- ==`printf`== 函数来自标准输入/输出库, `\n`为换行

- ==`return 0;`== 程序终止时向操作系统返回值`0`

- ==`void`== 参数类型, 可省略



<!-- slide data-notes="" -->


##### 编译与链接

---

三步由源码转换成可执行: 

- 预处理: 预处理器(preprocessor)处理 ==`#`== 开头的指令

- 编译: 编译器将源程序翻译为机器指令(目标代码)

- 链接: 链接器把由编译器生成的目标代码和所需的其他附加代码合在一起, 最终产生完全可执行的程序



<!-- slide data-notes="" -->


##### 集成开发环境

---

集编辑、编译、运行、调试的开发环境

- [CLion](https://www.jetbrains.com/clion/): ==推荐==, 学生邮箱可注册免费License

- [Visual Studio IDE](https://visualstudio.microsoft.com/zh-hans/vs/community/): 免费社区版(Community Edition)、需配置安全检查



<!-- slide data-notes="" -->


##### 简单C程序的一般形式

---

```C
指令

int main(void)
{
  语句
}
```

C使用 ==\{== 和 ==\}== 标识函数开始与结束, 类似其他语言begin和end

最简单的C程序包含三个关键的语言特性: 

- 指令: 预处理指令

- 函数: 可执行代码块, main函数

- 语句: 程序执行时的命令

---



<!-- slide data-notes="" -->


##### 指令

---

指令: 预处理指令, 在编译前修改程序内容的编辑命令, 示例: 

```C
#include <stdio.h>
```

==<stdio.h>== 是一个包含有关 C 标准 I/O 库信息的==头文件==

- 以 ==#== 开头, ==#== 用于将C代码中的指令与其他代码区分开来

- 默认只占一行, 每条指令的结尾没有分号或者其他特殊标记


==演示Hello NJU代码==


<!-- slide data-notes="" -->


##### 函数

---

C程序是函数的集合, 函数由一系列语句构成, 有两类函数: 

- 程序员编写的函数

- 库函数(library function): 作为C语言实现的一部分提供的函数

函数调用: 要求函数执行分配给它的任务称为调用函数



<!-- slide data-notes="" -->


##### 函数

---

术语==函数==源于数学: 在数学中, 函数指根据一个或多个给定参数进行数值计算的规则: 

$f(x) = x + 1$  对应C代码: 

```C
return x + 1;
```

$g(y, z) = y^2 - z^2$  对应C代码: 

```C
return y * y + z * z;
```

---


<!-- slide data-notes="" -->


##### 函数

---

C语言对 ==函数== 术语的使用更加宽松

- C语言中, 函数仅仅是一系列组合在一起并且赋予了名字的语句

- 某些函数计算数值, 某些函数则不; 

- 计算数值的函数用 ==return== 语句来指定所返回的值



<!-- slide data-notes="" -->


##### main函数

---

```C{.line-numbers}
int main()
{ 
  return 0;
}
``` 

- ==main== 函数是必须的, 不能写成Main或MAIN等

- ==main== 函数非常特殊: 程序执行时, 系统自动调用main函数

- ==main== 函数在程序终止时向操作系统返回一个状态码: 一般用0表示程序正常终止

- ==main== 函数末尾没有 ==return== 语句, 许多编译器会产生警告信息



<!-- slide data-notes="" -->


##### 语句

---

==语句== 是程序运行时要执行的命令, ==hw.c== 有两条语句

- 一条是 ==return== 语句

- 另一条是 ==函数调用== 语句

hw.c调用 ==printf== 函数来显示一个字符串: 

```C
  printf("Hello, World!\n");
```

---



<!-- slide data-notes="" -->


##### 语句

---

==C== 要求每个语句都以分号结尾

- 复合语句例外

- 指令通常只有一行, 并且不以分号结尾



<!-- slide data-notes="" -->


##### 语句

---

```C
printf("Hello, World!\n");
```

==printf== 函数是显示了一条字符串字面量(string literal)

- 当显示结束, ==printf== 函数不会自动跳转到下一行输出

- 为跳转至下一行, 须要在显示的字符串之后包含 ==\n== 换行



<!-- slide data-notes="" -->


##### 注释

---

注释: 文档说明, 可出现在程序任意位置, 用于描述程序用途等

- 多行: 以符号 ==/*== 开头, 以符号 ==*/== 结尾

- 单行: 以符号 ==//== 开头, 在行末自动终止 ( ==C99== )



<!-- slide data-notes="" -->


##### 注释

---

<span class="yellow">:fa-weixin:</span> 忘记终止注释可能会导致编译器忽略程序部分代码

```C{.line-numbers}
/* This is a comment */

/* Name: pun.c
   purpose: prints a bad pun
   author: K.N. King
*/

// Name: pun.c 
// Purpose: prints a bad pun
// Author: K.N. King
```

---



<!-- slide data-notes="" -->


##### 猜数字游戏

---

[游戏页面](https://www.abcya.com/games/guess_the_number)

[随机数rand函数](https://en.cppreference.com/w/c/numeric/random/rand)




<!-- slide data-notes="" -->


##### 猜数字游戏

---

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  int total_tries = 0;
  int limit, guess, reward;
  printf("Please choose the limit value:\n");
  scanf("%d", &limit);
  srand(time(NULL));
  reward = rand() % limit + 1;

  // printf("正确数值: %d\n", reward);
  while (total_tries < 7) {
    printf("Please guess the number\n");
    scanf("%d", &guess);
    // 检查是否猜对
    if (guess == reward) {
      printf("YOU WIN!\n");
      return 0;
    } else if (guess < reward) {
      printf("Smaller than the reward!\n");
    } else {
      printf("Larger than the reward!\n");
    }
    total_tries++; // number_of_tries = number_of_tries -1;
  }

  printf("YOU LOSE!\n");
  return 0;
}
```

---



