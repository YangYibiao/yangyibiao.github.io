---
presentation:
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

# C语言程序设计基础

<hr class="width50 center">

## C代码框架

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 指令

- 函数

- 语句



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

- ==预处理==: 预处理器(preprocessor)处理 ==`#`== 开头的指令

- ==编译==: 编译器将源程序翻译为机器指令(目标代码)

- ==链接==: 链接器把由编译器生成的目标代码和所需的其他附加代码合在一起, 最终产生完全可执行的程序



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

---

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

---

<!-- slide data-notes="" -->


##### 主函数

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

---

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


##### 代码演示1年龄

---

给定年份和当年的年龄，计算2280年时他的年龄



---

<!-- slide data-notes="" -->


##### 代码演示2

---

给定成绩，输出他优秀/良好/及格/不及格


<!-- slide data-notes="" -->


##### 代码演示3

---

给定用户输入的一个数，计算所有奇数的和



<!-- slide data-notes="" -->


##### 猜数字游戏

---

[游戏页面](https://www.abcya.com/games/guess_the_number)

[随机数rand函数](https://en.cppreference.com/w/c/numeric/random/rand)


---

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



