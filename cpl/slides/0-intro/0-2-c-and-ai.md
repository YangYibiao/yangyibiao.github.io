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

## C语言、人工智能与变量

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- C 简史与人工智能

- ==变量与基本数据类型==

- 三步走代码

- 开发环境与 AI 工具

---

<!-- slide data-notes="" -->

##### 回顾周二

---

周二我们知道了:

- 程序是计算机的==灵魂==, 程序 = ==算法 + 数据==

- 计算机工作的流程: ==输入 → 处理 → 存储 → 输出==

- 写程序需要的五种思维: 顺序、判断、循环、存储、分解

- 还动手写了自己的第一个程序 Hello World

今天: C 从哪里来、AI 为什么用 C, 然后开始写==真正的程序==!

---

<!-- slide data-notes="" -->

##### C语言的起源

---

- 1972年，==贝尔实验室==: Dennis Ritchie 开发 C，用于编写 ==UNIX== 操作系统

- 1978: Kernighan 和 Ritchie 合著《C程序设计语言》，成为事实标准

- 1989: 正式标准化为 ANSI C (C89/C90)，后续 C99、C11

- 影响力: 高效、灵活，广泛应用于系统编程、嵌入式系统

---


<!-- slide data-notes="" -->

##### 基于C的语言

---

- C++: 包括 C 的所有特性, 添加了类以支持面向对象编程

- Java: 基于 C++, 继承了许多 C 特性

- C#: 从 C++ 和 Java 派生

- Python: 解释器与核心计算库大量用 C 实现 (为 ==C语言与人工智能== 埋下伏笔)

---


<!-- slide data-notes="" -->

##### C的特点与优点

---

- ==低层语言==: 提供对机器级概念的访问 (字节和地址)

- ==小型语言==: 有限的特性集合, 很大程度依赖标准函数库

- ==宽松包容==: 高自由度, 不强制详细的错误检查

- 优点: ==效率高==、==可移植==、==灵活==、功能强大、标准库、与 Linux 集成

---


<!-- slide data-notes="" -->

##### C的缺点与应对

---

- 缺点: 程序容易隐藏错误、可能难以理解、可能难以维护

- 应对:
  - 深入理解以避免 C 语言的陷阱
  - 避免过于复杂的代码
  - 使用软件工具 (lint、调试器) 使程序更可靠
  - 采用一套合理的编码规范
  - 紧贴标准

---


<!-- slide data-notes="" -->

##### 什么是人工智能

---

人工智能 (Artificial Intelligence): 研究如何用计算机去==模拟、延伸和扩展==人的智能

- 图灵测试: 让机器表现得像人一样思考、学习、做决策

- 身边的 AI: 
  - <span class="blue">:fa-camera:</span> 人脸识别
  - <span class="blue">:fa-language:</span> 机器翻译
  - <span class="blue">:fa-car:</span> 自动驾驶
  - <span class="blue">:fa-microphone:</span> 语音助手 (Siri/小爱同学)
  - <span class="blue">:fa-comments:</span> 大语言模型 (GPT、DeepSeek 等)

---


<!-- slide data-notes="" -->

##### 人工智能简史

---

<span class="blue">:fa-lightbulb-o:</span> 你们觉得 Siri 会'听懂人话'吗？背后其实是 ==语音识别 + 大语言模型==

- 1950: 图灵提出"机器能思考吗？"，图灵测试

- 1956: 达特茅斯会议，"人工智能"正式诞生

- 1980s: 专家系统

- 2006~: 深度学习兴起

- 2017~: Transformer 架构 → 大语言模型 (GPT、DeepSeek 等)

---


<!-- slide data-notes="" -->

##### AI 的底层是 C

---

当我们用 Python 调用 AI 框架时，发生了什么？

<div style="display:flex;align-items:center;justify-content:center;gap:10px;font-size:0.85em;text-align:center;">
  <div style="border:2px solid var(--solarized-blue);border-radius:8px;padding:8px 16px;">Python<br>发出指令</div>
  <span class="blue" style="font-size:1.5em;">→</span>
  <div style="border:2px solid var(--solarized-red);border-radius:8px;padding:8px 16px;"><mark>C/C++ 高性能引擎</mark><br>完成所有计算</div>
  <span class="blue" style="font-size:1.5em;">→</span>
  <div style="border:2px solid var(--solarized-green);border-radius:8px;padding:8px 16px;">结果返回<br>Python</div>
</div>

- TensorFlow / PyTorch 核心: C++ 实现

- BLAS / LAPACK / OpenBLAS: 数值计算基石，C 语言编写

- CUDA: 从 C 扩展而来，驱动 GPU

- TinyML (如 TensorFlow Lite for Microcontrollers): 纯 C，跑在单片机上

---


<!-- slide data-notes="" -->

##### AI 的底层是 C

---

==C 语言是 AI 底层生态的通用接口==

- 学 C 能理解张量 (Tensor): 连续内存 + 指针

- 学 C 能理解矩阵运算: 二维数组 + 循环 + Cache 优化

- 学 C 能理解内存管理: malloc / free

- 学 C 才能看懂 PyTorch / TensorFlow 的"引擎"

---


<!-- slide data-notes="" -->

##### 变量与赋值

---

大多数程序在产生输出之前往往需要执行一系列计算, 因此需要在程序执行过程中有一种 ==临时存储数据== 的方法

==变量==: (Variable)程序执行过程中临时存储数据的单元

==类型==: (type)每一个变量都有一个类型, 类型用来说明变量所存储的数据的种类, 如 ==int, float, double, char==

---


<!-- slide data-notes="" -->

##### 类型: int

---

==int==变量: (整数integer的缩写)存储整数, 如`0`, `1`, `392`或`-2553`

- 取值范围是受限的, 最大的整数通常是$2 147 483 647$($2^{31}-1$)

- INT_MAX, INT_MIN (limits.h头文件中定义的常量)

```C
#include <stdio.h>
#include <limits.h>

int main(void) {
  printf("Max: %d, Min: %d", INT_MAX, INT_MIN);
  return 0;
}
```

---



<!-- slide data-notes="" -->


##### 类型: float/double

---

==float/double== 变量: 存储浮点数/双精度浮点数, 即可以带小数位, 如`379.125`

- ==float/double== 型变量算术运算通常比int型变量慢

- ==float/double== 在计算机中是近似存储的

<span class="blue">:fa-weixin:</span> 需要注意: 

- ==float/double== 型变量所存储的数值往往只是实际数值的一个近似值
- ==float/double== 型变量中存储0.1, 可能发现变量值为$0.099 999 999 999 999 87$

---


<!-- slide data-notes="" -->


##### 类型: char

---

==char== 变量: 存储字符, 如'A'

- 用单引号括起来

- 存储的是字符对应的编码(0 ~ 127的整数)

- 字符'a'的值是97, 'A'的值是65, '0'的值是48, ' '的值是32

- 使用 ==%c== 打印

```C
char gender = 'M';
printf("%c\n", gender);
```

---

<!-- slide data-notes="" -->


==声明==: 变量使用前必须对其进行 ==声明==(为编译器所做的描述)

- 指定变量的类型

- 说明变量的名字

```C
int main(void)
{
  声明
  语句
}
```

<span class="blue">:fa-weixin:</span> 在C99中, 声明可以不必出现在语句之前

---


##### 变量与赋值 - 声明

---

- 可以一次声明一个变量: 

```C{.line-numbers}
int height;
float profit;
char gender;
char name[20];
```

- 可以同时声明多个变量: 

```C{.line-numbers}
int height, length, width, volume;
float profit, loss;
char gender;
char name[30], nation[20], address[60];
```

---
<!-- slide data-notes="" -->


##### 变量与赋值 - 初始化

---

当程序开始执行时, 某些变量会自动设零, 而大多数则不会

- 没有默认值并且尚未在程序中赋值的变量是 ==未初始化的==(uninitialized)

- 若试图访问未初始化的变量, 可能会得到不可预知的结果

```C
int height = 8;
```

这里, 数值8是一个==初始化式==。

同一个声明中可以对任意数量的变量进行初始化, 如: 

```C
int height = 8, length = 12, width = 10;
```

或

```C
int height, length, width = 10;
```

---



<!-- slide data-notes="" -->


==`printf`== 可用于打印变量的当前值

```C
int height = 2;
char ch = 'a';
float profit = 1500f;
double pi = 3.14159;

printf("Height: %d\n", height);
printf("Character: %c\n", ch);
printf("Profit: %f\n", profit);
printf("Pi: %lf\n", pi);
```

==%d==: int型变量占位符, 用来指明变量`height`的值显示的位置
==%c==: char型变量占位符, 用来指明变量`ch`的值显示的位置
==%f==: float型变量占位符, 用来指明变量`profit`的值显示的位置
==%lf==: double型变量占位符, 用来指明变量`pi`的值显示的位置

---


##### 变量与赋值 - 打印变量的值

---

浮点数 

- 要显示`float`型变量, 需使用 ==`%f`== 代替 ==`%d`==, ==`%f`== 默认会显示出小数点后6位

- 如果要强制 ==`%f`== 显示小数点后 ==`p`== 位数字, 可以把 ==`.p`== 放置在 ==`%`== 和 ==`f`== 之间, 如: 

```C
printf("profit: %.2f", profit);
```

- ==`printf`== 打印的变量数量没有限制

```C
printf("Height: %d Length: %d", height, lenght);
```

---
<!-- slide data-notes="" -->


##### 读取输入

---

==`scanf`== 函数: C语言中对应于 ==`printf`== 的库函数

==`scanf`== 与 ==`printf`== 中的字母 ==`f`== 含义相同, 都表示``格式化``

```C
int i;
scanf("%d", &i); 
/* reads an integer; stores into i */
```

<span class="blue">:fa-weixin:</span> ==&== 符号通常(但不总是)在使用 ==`scanf`== 时是必需的

读取浮点值的scanf调用: 

```C
scanf("%f", &x); 
```

- ==`%f`== 告诉 ==`scanf`== 查找浮点格式的输入值(数字可能包含小数点, 但不是必须的)

---


<!-- slide data-notes="" -->


##### 代码演示1: 年龄

---

==现场演示==

给定年份和当年的年龄，计算2280年时他的年龄



---


<!-- slide data-notes="" -->


##### 代码演示2: 温度转换

---

==现场演示==

输入摄氏温度, 输出对应的华氏温度: $F = \frac{9}{5} C + 32$

```C
/* temp.c: 摄氏转华氏 */
#include <stdio.h>

int main(void) {
    double c, f;
    printf("Enter Celsius temperature: ");
    scanf("%lf", &c);

    f = 9.0 / 5 * c + 32;

    printf("%.1f C = %.1f F\n", c, f);
    return 0;
}
```

- 变量: `double` c, f (浮点数)

- 输入: `scanf("%lf", &c)` 读取 double

- `9.0 / 5` 而不是 `9 / 5` (整数除法的坑, 第 3 周细讲)

---

<!-- slide data-notes="" -->


##### 代码演示3: 成绩

---

==现场演示==

给定成绩，输出他优秀/良好/及格/不及格


<!-- slide data-notes="" -->


##### 代码演示4: 石头剪刀布

---

==现场演示==

你和电脑各出一个手势, 谁赢?

```C
/* rps.c: 石头剪刀布 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int player, computer;
    srand(time(NULL));
    computer = rand() % 3;   /* 0剪刀 1石头 2布 */

    printf("0剪刀 1石头 2布, 请出: ");
    scanf("%d", &player);

    if (player == computer) {
        printf("平局!\n");
    } else if ((player == 0 && computer == 2) ||
               (player == 1 && computer == 0) ||
               (player == 2 && computer == 1)) {
        printf("你赢了!\n");
    } else {
        printf("你输了!\n");
    }
    return 0;
}
```

- 变量 + 随机数 + if/else, 都是已经见过的元素

- 预告: if 语句第 4 周正式学, 随机数第 5 周猜数字改进版

---

<!-- slide data-notes="" -->


##### 集成开发环境

---

集编辑、编译、运行、调试的开发环境

- [CLion](https://www.jetbrains.com/clion/): ==推荐==
  - 学生邮箱可注册免费 License
  - 或使用校内激活服务器: ==http://210.28.133.13:22737== (==仅校内网络==可用)

- [Visual Studio IDE](https://visualstudio.microsoft.com/zh-hans/vs/community/): 免费社区版(Community Edition)、需配置安全检查



<!-- slide data-notes="" -->

##### AI 辅助编程工具

---

- 工具: GitHub Copilot、Cursor; DeepSeek、ChatGPT、Claude、Gemini

- 用法:
  - 概念理解: 让 AI 解释代码
  - 代码练习: 让 AI 出题、改题
  - 项目指导与代码审查

- 规则:
  - ==先自己写，再让 AI 改==：依赖 AI 的学生学不会编程
  - ==AI 是副驾驶，方向盘在自己手里==
  - 要求独立完成的作业，不用 AI 代写

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 存储"成绩 98.5"用什么类型？"学号 20260001"呢？"性别 M"呢？

2. 声明一个整数变量 `height` 并初始化为 `175`，怎么写？

3. 用 `printf` 打印 double 型变量用哪个转换说明？用 `scanf` 读取整数到变量 `i`，调用怎么写？

4. TensorFlow / PyTorch 的性能核心由什么语言实现？

<!-- slide data-notes="" -->


#####

---

<div class="top-2">
  <img src="figs/see-you.png" width=500px>
</div>

---