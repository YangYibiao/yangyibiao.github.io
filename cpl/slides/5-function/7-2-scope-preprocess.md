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

# 智能程序设计（C语言）

<hr class="width50 center">

## 作用域、预处理与AI赋能

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 标识符的作用域

- 变量的生命期

- 预处理: #include、宏定义、条件编译

- AI 赋能程序设计 I

---


<!-- slide data-notes="" -->


##### 标识符的作用域

---

==作用域==: 标识符可以被使用的那段代码范围

- ==块作用域==: 函数体内 {} 覆盖的范围——局部变量、形式参数

- ==文件作用域==: 从定义位置到文件末尾——全局变量

- 内层屏蔽外层: 内层同名变量会==遮蔽==外层的

```C
int x = 0;            /* 文件作用域 */
void f(void)
{
  int x = 1;        /* 块作用域, 屏蔽全局 x */
  printf("%d", x);  /* 打印 1 */
}
```

- ==局部变量==: 定义在函数内, 出了函数就不可见

- ==全局变量==: 定义在函数外, 整个文件可见; 少用为妙 (谁都可能改它)

---


<!-- slide data-notes="" -->


##### 变量的生命期

---

- ==动态变量==(默认): 函数被调用时诞生, 函数返回时消亡

- ==静态变量==(static): 与程序同生共死, 函数返回后==保留原值==

```C
void f(void)
{
  static int count = 0;  /* 只初始化一次 */
  count++;
  printf("第 %d 次调用\n", count);
}
```

- static 局部变量 = 带记忆的局部变量 (下次调用接着用上次的值)

---


<!-- slide data-notes="" -->


##### 预处理概念

---

编译前的==预处理==阶段: 处理以 ==#== 开头的命令

- #include: 文件包含

- #define: 宏定义

- #if / #ifdef / #ifndef: 条件编译

---


<!-- slide data-notes="" -->


##### #include 文件包含

---

把指定文件的内容==原样复制==到 #include 所在位置

```C
#include <stdio.h>   /* 系统头文件, 尖括号 */
#include "myfile.h"  /* 自己的头文件, 引号 */
```

- 头文件里放: 函数原型、宏定义、结构体定义等"声明"

- 多文件项目的基础 (第 14 周详细讲)

---


<!-- slide data-notes="" -->


##### 宏定义: 类对象宏

---

==宏定义==: 用一个名字代表一段字符序列, 预处理时==文本替换==

```C
#define PI 3.14159
#define MAX_N 100

area = PI * r * r;   /* 展开为 area = 3.14159 * r * r; */
```

- 行末==没有分号==; 宏名习惯全大写

- 替换是纯文本的——表达式要==加括号==

```C
#define TWICE(x)  x + x     /* 危险! */
#define TWICE(x) ((x) + (x)) /* 安全 */
```

- 两个经典错误: ==`#define N = 100`== (多了等号) 和 ==`#define N 100;`== (多了分号)——宏是纯文本替换, 等号和分号会被原样带进代码

---


<!-- slide data-notes="" -->


##### 宏定义: 带参宏

---

==带参宏==: 像函数一样使用, 但只是文本替换

```C
#define MAX(a, b) ((a) > (b) ? (a) : (b))

x = MAX(p + q, r + s);
/* 展开为 x = ((p+q) > (r+s) ? (p+q) : (r+s)); */
```

- 宏 vs 函数: 宏是替换不求值, 参数无类型; 函数有类型检查

- 经典坑: MAX(i++, j) 会把 i 自增两次——带参宏参数==不要有副作用==

---


<!-- slide data-notes="" -->


##### 条件编译

---

==条件编译==: 按条件选择性地编译部分代码

```C
#define DEBUG 1

#ifdef DEBUG
  printf("调试信息: x=%d\n", x);
#endif
```

- #ifdef X / #ifndef X / #if 表达式 / #elif / #else / #endif

- 用途: 调试开关、跨平台代码 (第 14 周多文件再深入)

---


<!-- slide data-notes="" -->


##### AI 赋能程序设计 I

---

==AI 工具与函数==

- ==函数化重构==: 把第 6 周的长 main 发给 AI, 让它拆成函数并解释为什么这么拆

- ==理解递归==: 让 AI 画出 f(4) 的调用过程 (递推/回归), 或者用 AI 讲解 Hanoi 塔

- ==出题==: 让 AI 出 5 道递归练习题, 先自己做再对答案

规则不变: ==先自己写, 再让 AI 改==——AI 是副驾驶, 方向盘在自己手里。

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 局部变量和全局变量的作用域分别是什么？内层同名变量会发生什么？

2. static 局部变量与普通局部变量的区别是什么？

3. 带参宏 MAX(a, b) 为什么参数和整体都要加括号？MAX(i++, j) 有什么坑？

4. #ifdef DEBUG 的用途是什么？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


