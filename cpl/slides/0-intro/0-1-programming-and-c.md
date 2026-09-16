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

## 程序设计与C语言入门

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 概述

---

- 什么是程序设计语言

- 什么是计算机

- 计算机与编程语言

- 编程思维

- 为什么学习==C语言== (答案在第二节课揭晓)

---


<!-- slide data-notes="" -->

##### 思考: 问题1

---

==问题1==：计算机和==计算器==有什么区别？

---


<!-- slide data-notes="" -->

##### 问题1 的答案: 为什么计算机什么都能做？

---

- 区别1: ==存储==——计算机有内存与外存, 可长期保存海量数据; 计算器只能暂存几个数

- 区别2: ==可编程==——计算器的功能固化在硬件里; 计算机装什么程序, 就能做什么事

- 区别3: ==处理的信息==——文本、图像、声音、视频; 计算器只会数值运算

- 点睛: 打开计算器 App, 计算机就能当计算器用, 计算器却永远变不成计算机

- 彩蛋: 计算器其实也是一种小计算机——区别不在"有没有芯片", 而在"程序能不能换"

==程序是计算机的灵魂==——我们要学的, 就是怎么给这台万能机器写指令

---


<!-- slide data-notes="" -->

##### 为什么需要高级语言

---

计算机只能执行 ==0 和 1== 组成的==机器指令==。语言是这样一步步进化来的:

<div class="fullborder">

| 语言 | 长这样 | 问题/特点 |
| :-- | :-- | :-- |
| 机器语言 | `10110000 00001100`<br>`00101100 00000101` | 难记、易错、依赖具体机器 |
| 汇编语言 | `MOV AL,12D`<br>`SUB AL,5D` | 助记符好记了, 但仍与机器绑定 |
| 高级语言 | `result = 12 - 5;` | 接近自然语言和数学==与机器无关== |

</div>

- 高级语言写的代码==需要翻译==才能执行——这个"翻译官"就是==编译器==

- 好处: 易学易用、易读易调试、==可移植==(换台机器不用重写)

- C 是高级语言中==离硬件最近==的一个: 既好用, 又高效

---
<!-- slide data-notes="" -->

##### 什么是程序设计语言

---

人类交流 → 机器交流

- 人类要交流需要语言（中文、英文）

- 人和计算机交流也需要"语言"——程序设计语言

对比：自然语言 vs 程序语言

- 自然语言灵活但有歧义
  - 如: ==南京市长江大桥==——是"南京市 · 长江大桥", 还是"南京市长 · 江大桥"?

- 程序语言严格、无歧义，让机器可以准确执行

==程序设计语言，就是人类和计算机沟通的工具==

---


<!-- slide data-notes="" -->

##### 程序能做什么

---

==程序是计算机的灵魂==, 那程序能做什么?

1. 排序一组成绩/批改试卷/统计单词个数等

2. 游戏、微信、自动驾驶背后都是程序

---


<!-- slide data-notes="" -->

##### 思考: 问题2

---

==问题2==：给全班 100 个同学的成绩，怎么让计算机找出最高分？

<span class="blue">:fa-lightbulb-o:</span> 提示: 你不能让它"看一眼"，只能一步步指挥它

---


<!-- slide data-notes="" -->

##### 算法: 找最高分

---

- ==问题2 的答案==: 人扫一眼就能找到最高分, 但计算机不能"看"

- 计算机的做法:
  1. ==假设==第一个成绩是最高分
  2. ==逐个比较==剩下的成绩
  3. 遇到更大的就==替换==
  4. 比较完, 剩下的一定是最高分

- 启示: 人觉得简单的事, 计算机需要一个==算法==

- 程序 = ==算法 + 数据==

---



<!-- slide data-notes="" -->

##### 什么是计算机

---

计算机: 由==硬件==和==软件==组成, 用于==接收、处理和存储数据==的电子设备

- 硬件：输入设备、输出设备、存储设备、CPU、内存、主板等物理组件

- 软件：操作系统、应用程序等，执行各种任务

---


<!-- slide data-notes="" -->

##### 计算机如何工作

---

<div style="display:flex;align-items:center;gap:20px;">

<div style="flex:1.25;">

- ==输入==：键盘、鼠标、摄像头等接收数据和指令

- ==处理==：CPU 执行指令，进行数据处理和计算

- ==存储==：内存临时存储正在处理的数据；存储设备长期保存信息

- ==输出==：显示器、打印机、扬声器等呈现处理结果

- ==控制==：操作系统和应用程序管理硬件资源，协调各组件

==编程==: 使用特定的==编程语言==编写指令, 控制计算机执行上述任务

</div>

<div style="flex:1;">
  <img src="figs/howcomputerworks.png" style="max-width:100%;">
</div>

</div>

---


<!-- slide data-notes="" -->

##### 计算机如何工作: 找最高分

---

用刚才问题2的例子: 计算机怎么找出 100 个成绩的最高分?

1. ==输入==: 逐个读入成绩

2. ==处理==: 与当前最高分比较, 更大就替换

3. ==存储==: 记住当前最高分 (内存)

4. ==输出==: 比较完, 打印最高分

---


<!-- slide data-notes="" -->

##### 编程思维

---

回头看"找最高分"的步骤, 写程序需要的东西全在里面:

- ==结构==: 顺序 (一步步执行)、判断 (if: 更大就替换)、循环 (重复比较, 直到比完)

- ==数据==: 存储——记住当前最高分 (变量)

- ==设计==: 分解——大问题拆成小步骤

接下来要学的, 就是把这些要素用 ==C 语言== 写出来!

---


<!-- slide data-notes="" -->

##### 程序需要什么: 本课程地图

---

有了语言, 写程序还需要什么? 从 ==输入 → 处理 → 存储 → 输出== 反推:

<div class="fullborder">

| 程序的需求 | 需要的元素 | 什么时候学 |
| :-- | :-- | :-- |
| 记住数据 | 变量、类型 | 第 2 周 |
| 计算 | 表达式、运算符 | 第 3 周 |
| 不同情况做不同事 | 判断 if / switch | 第 4 周 |
| 重复做 | 循环 while / for | 第 5 周 |
| 复用与分解 | 函数 | 第 6-7 周 |
| 一批数据 | 数组 | 第 8-9 周 |
| 字符串与内存 | 指针 | 第 10-11 周 |
| 复杂的数据组织 | 结构体、链表 | 第 12-13 周 |
| 长期保存数据 | 文件 | 第 14 周 |

</div>

<span class="blue">:fa-lightbulb-o:</span> 每一项都是"==因为需要, 所以才有=="——这就是本学期的路线图

---
<!-- slide data-notes="" -->


##### 程序: 打印Hello NJU

---

<div style="display:flex;align-items:flex-start;gap:20px;">

<div style="flex:1;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("Hello, NJU!\n");
  return 0;
}
```

</div>

<div style="flex:1.1;">

- ==`#include`==: 预处理指令, 引入标准输入/输出库的头文件*stdio.h*

- ==`main函数`==: 主函数, 程序入口, 任何C程序都需要一个main函数

- ==`printf`==: 输出, `\n`为换行

- ==`return 0;`==: 程序正常结束, 向操作系统返回值`0`

</div>

</div>

<div class="top-2"></div>

- 代码存为 ==`.c`== 文件 (假设文件名为`hw.c`)

- 编译: ==`gcc hw.c`== 生成可执行程序`a.out`; ==`gcc hw.c -o hw`== 指定生成`hw`

- ==`void`== 参数类型, 可省略

==演示Hello NJU代码==



<!-- slide data-notes="" -->


##### gcc 背后做了什么

---

一条 `gcc hw.c` 命令背后, 实际做了三件事:

- ==预处理==: 处理 `#` 开头的指令 (如 `#include`)

- ==编译==: 把 C 代码翻译成机器指令

- ==链接==: 把 printf 等库函数合到一起, 生成可执行程序

<span class="blue">:fa-weixin:</span> 这三件事都交给 gcc, 我们只写代码



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

C使用 ==\{== 和 ==\}== 标识函数开始与结束

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



<!-- slide data-notes="" -->


##### 主函数

---

```C{.line-numbers}
int main(void)
{ 
  return 0;
}
``` 

- ==main== 是程序==入口==: 程序执行时, 系统自动调用main函数

- ==main== 函数是必须的, 不能写成Main或MAIN等

- 程序终止时向操作系统返回状态码: ==0== 表示正常终止 (没有 ==return== 语句, 编译器会警告)

---

<!-- slide data-notes="" -->


##### 函数

---

C程序是==函数的集合==, 函数由一系列语句构成

- ==main== 只是其中的一个函数, 由系统自动调用

- ==printf== 是==库函数==(library function): 由 C 语言实现提供, 由 ==#include== 引入进来

- 程序员也可以自己编写函数, 给一段语句起名字; ==函数调用== 就是让函数执行分配给它的任务

- 术语==函数==源于数学: $f(x) = x + 1$ 对应C代码 ==`return x + 1;`==; 计算数值的函数用 ==return== 语句来指定所返回的值

---



<!-- slide data-notes="" -->


##### 语句

---

==语句== 是程序运行时要执行的命令, 示例: 

```C
printf("Hello, World!\n");
```

- 每条语句都以==分号==结尾 (复合语句例外; 指令通常只有一行且不以分号结尾)

- ==printf== 函数显示了一条字符串字面量(string literal)

- 显示结束, ==printf== 函数不会自动跳转到下一行输出, 需要 ==\n== 换行



<!-- slide data-notes="" -->


##### 程序是怎样构成的

---

程序是一串 ==token==: 编译器认识的最小单位

`printf("Height: %d\n", height);` 可以拆成 ==7 个 token==:

<div class="fullborder">

| 标识符 `printf` | `(` | 字符串 `"Height: %d\n"` | `,` | 标识符 `height` | `)` | `;` |
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |

</div>

- 空白(空格、换行、制表符)只是==分隔== token 的胶水

- 不能把 token 从中间拆开: `fl oat` 会报错

- 字符串字面量==不能跨行==

排版建议: 运算符两侧加空格、缩进显示嵌套、空行分隔逻辑单元

---

<!-- slide data-notes="" -->


##### 注释

---

<div style="font-size:0.72em;">

```C{.line-numbers}
/* hello.c: 我的第一个 C 程序
   打印 Hello NJU
*/
#include <stdio.h>     // 引入标准输入/输出库

int main(void)
{
  printf("Hello, NJU!\n");   // 输出问候, \n 换行
  return 0;                  // 程序正常结束
}
```

</div>

- 没有注释, 复杂的程序别人(包括一个月后的自己)很难看懂

- ==注释==: 写给人看的说明, 编译器会==完全忽略==

- 多行注释: ==/*== 开头, ==*/== 结尾, 可以跨行 (见代码顶部)

- 单行注释: ==//== 开头, 行末结束 (见代码行尾)

- <span class="yellow">:fa-weixin:</span> 忘记写 ==*/== 会导致编译器忽略大片代码

---

<!-- slide data-notes="" -->

##### 注释

---

==小挑战==: 猜猜这段程序的输出?

```C
printf("My ");    /* 忘记闭合这个注释
printf("cat ");
printf("has ");   /* 注释在这里才结束 */
printf("fleas");
```


---

<!-- slide data-notes="" -->

##### 注释

---

答案: 输出 ==My fleas==——第一个 /* 把中间两行"吞"进注释, 直到遇到第一个 */

---

<!-- slide data-notes="" -->


##### 猜数字游戏

---

[游戏页面](https://www.abcya.com/games/guess_the_number)

[随机数rand函数](https://en.cppreference.com/w/c/numeric/random/rand)


---

<!-- slide data-notes="" -->


##### 猜数字游戏: 代码

---

<div style="font-size:0.75em;">

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int guess;
  srand(time(NULL));
  int answer = rand() % 100 + 1;

  printf("猜一个数字(1-100):");
  scanf("%d", &guess);

  if (guess == answer)
    printf("猜中啦!\n");
  else if (guess < answer)
    printf("太小了!\n");
  else
    printf("太大了!\n");

  return 0;
}
```

</div>

---


<!-- slide data-notes="" -->


##### 猜数字游戏: 程序在做什么

---

- 三个 `#include`: stdio 提供 printf/scanf, stdlib 提供 rand/srand, time 提供 time

- `srand(time(...))`: 用当前时间做随机种子

- `answer = rand() % 100 + 1`: 悄悄生成 1~100 的==随机答案==

- `scanf` 读你的猜测 → `if/else` 比较 → 猜中/小了/大了

- 想连续猜 7 次? 第 5 周学完==循环==自己改造!

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 计算机和计算器最本质的区别是什么？

2. 写出 Hello World 程序的三要素：入口函数、输出函数、结束语句分别是什么？

3. 计算机找最高分的流程中，输入、处理、存储、输出分别对应什么？

4. C 程序中每条语句的结尾必须是什么符号？注释有哪两种写法？


<!-- slide data-notes="" -->


##### 课堂挑战

---

==挑战: 打印你的名片==

用 printf 输出一张个人名片, 至少包含:

1. 姓名

2. 学号

3. 一句想对全班同学说的话

比一比谁的名片最有个性!

---

<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---

