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

## 变量与基本数据类型

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

---


<!-- slide data-notes="" -->

##### 提纲

---

- ==变量与基本数据类型==

- 代码展示: 编程能做什么

---


<!-- slide data-notes="" -->

##### 变量与赋值

---

大多数程序在产生输出之前往往需要执行一系列计算, 因此需要在程序执行过程中有一种 ==临时存储数据== 的方法

==变量==: (Variable)程序执行过程中临时存储数据的单元

==类型==: (type)每一个变量都有一个类型, 类型用来说明变量所存储的数据的种类, ==int, float, double, char==

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

##### 标识符与关键字

---

==标识符==: 变量、函数等对象的==名字==

- 由字母、数字、下划线组成; 不能以数字开头 (==10times== 非法)

- C 是==大小写敏感==的: `job`、`Job`、`jOb` …… 8 种排列是不同的名字

- 不能用关键字; 建议避免以下划线开头

---


<!-- slide data-notes="" -->

##### 标识符与关键字

---

==关键字==: C 语言保留的 32 个词, 全部==小写==:

| 关键字 | 关键字 | 关键字 | 关键字 | 关键字 | 关键字 | 关键字 | 关键字 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| auto | break | case | char | const | continue | default | do |
| double | else | enum | extern | float | for | goto | if |
| inline | int | long | register | restrict | return | short | signed |
| sizeof | static | struct | switch | typedef | union | unsigned | void |
| volatile | while | | | | | | |


命名风格: `student_name` 或 `studentName`, 选一种==保持统一==; 名字要有==含义==

---


<!-- slide data-notes="" -->

##### 变量与赋值 - 声明

---

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


<!-- slide data-notes="" -->

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

这里, 数值8是一个==初始化式==

---


<!-- slide data-notes="" -->

##### 变量与赋值 - 初始化

---

同一个声明中可以对任意数量的变量进行初始化, 如: 

```C
int height = 8, length = 12, width = 10;
```
或
```C
int height, length, width = 10;   /* 只有 width 被初始化! */
```

---


<!-- slide data-notes="" -->

##### 变量与赋值 - 赋值

---

==赋值==: 用 `=` 把值存进==已经声明==的变量

```C{.line-numbers}
int height;        /* 先声明 */
height = 8;        /* 再赋值: 把 8 存进 height */
height = 10;       /* 可以再改: height 现在是 10 */
```

- `=` 是==赋值==(把右边的值存到左边), 不是数学的"相等"

- 变量可以被反复赋值, 新值会==覆盖==旧值

- 先声明后赋值: `height = 8;` 写在 `int height;` 前面是==错误==的

- 对比: `int height = 8;` 是==初始化==(声明的同时给值)

---


<!-- slide data-notes="" -->

##### 变量与赋值 - 打印变量的值

---

==`printf`== 可用于打印变量的当前值

```C
#include <stdio.h>
int main() 
{
  int height = 2;
  char ch = 'a';
  float profit = 1500f;
  double pi = 3.14159;

  printf("Height: %d\n", height);
  printf("Character: %c\n", ch);
  printf("Profit: %f\n", profit);
  printf("Pi: %f\n", pi);
}
```

- ==%d==: int型变量占位符, 用来指明变量`height`的值显示的位置
- ==%c==: char型变量占位符, 用来指明变量`ch`的值显示的位置
- ==%f==: float型变量占位符, 用来指明变量`profit`的值显示的位置
- ==%f==: double型变量占位符 (printf 中 double 也用 %f; ==`%lf` 只有 scanf 需要==)

---


<!-- slide data-notes="" -->

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

输入出生年份, 输出今年的年龄 (纯变量 + 表达式)

```C{.line-numbers}
/* age.c: 计算年龄 */
#include <stdio.h>

int main(void) {
  int birth_year;

  printf("请输入出生年份: ");
  scanf("%d", &birth_year);

  int age = 2026 - birth_year;      /* 简单的减法表达式 */

  printf("今年 %d 岁\n", age);
  return 0;
}
```

- 三个"变量": `birth_year` (输入)、`age` (计算)、`2026` (常量)

- 表达式 `2026 - birth_year` 的结果直接赋给 age——==赋值 = 把右边算出来存进左边==

<span class="blue">:fa-lightbulb-o:</span> 加一点判断就能算"生日过了没"——那是第 4 周的内容

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

##### 代码演示3: 找零计算

---

==现场演示==

输入金额 (整数元), 输出需要各种面额==多少张==: `/` 与 `%` 的第一次实战

```C{.line-numbers}
/* change.c: 找零计算 */
#include <stdio.h>

int main(void) {
  int amount;

  printf("请输入金额 (元): ");
  scanf("%d", &amount);

  printf("100元: %d 张\n", amount / 100);     /* 整除: 有几个 100 */
  amount = amount % 100;                       /* 取余: 剩下多少 */

  printf(" 50元: %d 张\n", amount / 50);
  amount = amount % 50;

  printf(" 20元: %d 张\n", amount / 20);
  amount = amount % 20;

  printf(" 10元: %d 张\n", amount / 10);
  amount = amount % 10;

  printf("  5元: %d 张\n", amount / 5);
  amount = amount % 5;

  printf("  1元: %d 张\n", amount);
  return 0;
}
```

- `/` 求"有几个", `%` 求"剩多少"——两个运算符配合, 把一个数一层层拆开

- 课后 OJ 有 `change.c` 同款题目, 自己动手写一遍

---


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

---


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

##### 课堂编码

---

==轮到你了: 把课程演示变成自己的程序==

打开 CLion / VSCode, 现场完成 (10 分钟):

1. ==温度转换==: 输入摄氏温度, 输出华氏温度 ($F = \frac{9}{5}C + 32$)

2. ==成绩判断==: 输入一个成绩, 输出"及格"或"不及格"

提示:

- 变量: 需要什么类型? (`double`? `int`?)
- 输入: `scanf("%lf", &c);` —— 别忘了 ==&==
- 输出: `printf("%.1f\n", f);`

<span class="blue">:fa-lightbulb-o:</span> 卡住了? 先看课件对应的演示页, 再问助教——==今天每个人的程序都要能跑起来==

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 存储"成绩 98.5"用什么类型？"学号 20260001"呢？"性别 M"呢？

2. 声明一个整数变量 `height` 并初始化为 `175`，怎么写？

3. 用 `printf` 打印 double 型变量用哪个转换说明？用 `scanf` 读取整数到变量 `i`，调用怎么写？

4. TensorFlow / PyTorch 的性能核心由什么语言实现？

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="figs/see-you.png" width=500px>
</div>

---


