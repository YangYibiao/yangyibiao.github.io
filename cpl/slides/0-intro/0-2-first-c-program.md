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

## 初识C程序

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



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

编译运行之后, 我们来解剖一下 C 程序长什么样:



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

程序里还有写给==人==看的部分——注释:

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

学了不少语法, 来见一个完整的程序——猜数字游戏:

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

今天学了很多——检验一下:

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

