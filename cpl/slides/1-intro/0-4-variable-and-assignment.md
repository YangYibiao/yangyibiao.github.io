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


<style>
:root { --r-main-font-size: 46px; }
</style>

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 变量与基本数据类型

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

---

<!-- slide data-notes="" -->##### 提纲

---

<div style="font-size:1.1em;line-height:1.85;">

今天用 ==6 个小任务== 学会变量与基本类型:

- 变量、类型、变量名 (5 分钟扫一遍)

- 任务 1: 打印年龄 —— `int`、声明、`printf`

- 任务 2: 输入出生年份算年龄 —— `scanf`

- 任务 3: 温度转换 —— `double`、小数格式

- 任务 4: 找零计算 —— `/` 与 `%`

- 任务 5: 字符与编码 —— `char`

- 任务 6: 交换两个数 —— 临时变量与赋值

- 语法补全 + 输入输出一览 + 课堂编码

</div>

---

<!-- slide data-notes="" -->##### 变量、类型与变量名

---

<div style="font-size:0.93em;line-height:1.62;">

==先想一个问题==: 求平均分——总分算出来之后, 在除以人数之前, ==放在哪里==?

- 程序需要一种==临时存储数据==的地方, 否则中间结果算完就丢

==变量==: 程序执行过程中, 用来临时存储数据的==有名字的单元==

<div style="display:flex;align-items:center;gap:16px;margin:10px 0;">
<div style="border:2px solid var(--solarized-blue);border-radius:8px;padding:8px 26px;text-align:center;background:#fdf6e3;"><span style="color:#268bd2;font-weight:700;font-size:1.1em;">height</span><br><span style="font-size:1.5em;font-weight:700;">175</span></div>
<div>← 名字叫 <code>height</code> 的"盒子", 里面装着 175</div>
</div>

==类型==: 每个变量都有类型, 用来说明盒子里装==什么种类的数据==——本课常用 `int`、`float`、`double`、`char`, 接下来随用随讲

==变量名==: 命名规则见后面「语法补全: 标识符与关键字」

概念扫完, 动手写第一个任务:

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 打印年龄

---

<div style="font-size:1.05em;line-height:1.85;">

==任务==: 把自己的年龄存进一个变量, 打印出来

样例:

```
我今年 19 岁
```

==提示==:

- 整数用什么类型? 打印整数用哪个占位符?

- 声明时就把值放进去——试试 `int age = 19;`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task1-print-age.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task1-print-age.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 参考代码与要点

---

参考实现: 声明、初始化、打印三步:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int age = 19;          /* 声明 + 初始化 */
  printf("我今年 %d 岁\n", age);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- ==声明==: `int age;` 告诉编译器"留一个装整数的盒子"

- ==初始化==: 声明的同时放值 `= 19`; 不初始化就读取, 可能得到==垃圾值==

- `printf` 里用 ==`%d`== 对应 int——占位符要和变量==类型一致==

- `=` 是==赋值== (把右边存进左边), 不是数学的"相等"

</div>

</div>

会打印了, 下一步让程序读入数据:

---

<!-- slide data-notes="" -->##### 任务 2: 输入出生年份, 算年龄

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 输入出生年份, 计算并输出今年的年龄

样例:

```
请输入出生年份: 2007
今年 19 岁
```

==提示==: 用 `scanf` 读入, 别漏了 `&`; 年龄 = `2026 - birth_year`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task2-age.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task2-age.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 参考代码与要点

---

参考实现: 读入、计算、输出三步:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
/* age.c: 计算年龄 */
#include <stdio.h>

int main(void) {
  int birth_year;

  printf("请输入出生年份: ");
  scanf("%d", &birth_year);

  int age = 2026 - birth_year;

  printf("今年 %d 岁\n", age);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `scanf("%d", &birth_year)`: `%d` 读整数, ==`&` 取地址==——漏掉 `&` 程序会出错

- `2026 - birth_year` 先==算出值==, 再存进 `age`——赋值右边可以是表达式

- `2026` 是==常量==, 不占变量盒子

- C99 起变量可以==随用随声明== (`int age` 写在中间也可以)

</div>

</div>

整数会了, 换成带小数的温度:

---

<!-- slide data-notes="" -->##### 任务 3: 摄氏转华氏

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 输入摄氏温度, 输出对应的华氏温度: $F = \frac{9}{5} C + 32$

样例:

```
请输入摄氏温度: 37.0
37.0 C = 98.6 F
```

==提示==: 温度会带小数——用什么类型? 输出保留一位小数: `%.1f`

<span class="blue">:fa-weixin:</span> 小心 `9 / 5`: 两个整数相除会==截断==

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task3-temp.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task3-temp.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 3: 参考代码与要点

---

参考实现: 用 double 存温度, 用 9.0/5 做浮点除法:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
/* temp.c: 摄氏转华氏 */
#include <stdio.h>

int main(void) {
    double c, f;
    printf("请输入摄氏温度: ");
    scanf("%lf", &c);

    f = 9.0 / 5 * c + 32;

    printf("%.1f C = %.1f F\n", c, f);
    return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `double` 存小数; 声明两个可以写在一起 `double c, f;`

- scanf 读 double 用 ==`%lf`==; printf 打印 double 用 ==`%f`== (写 `%.1f` 保留一位小数)

- `9.0 / 5` 而不是 `9 / 5`: 整数除法得 `1`, 浮点除法才是 `1.8`

- 浮点数是==近似存储==: `0.1` 可能是 `0.099999…`——比较两个浮点数要格外小心

</div>

</div>

小数会了, 再看整数除法与取余:

---

<!-- slide data-notes="" -->##### 任务 4: 找零计算

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 输入金额 (整数元), 输出需要各种面额==多少张==: 100、50、20、10、5、1

样例:

```
请输入金额 (元): 386
100元: 3 张
 50元: 1 张
 20元: 1 张
 10元: 1 张
  5元: 1 张
  1元: 1 张
```

==提示==: `/` 求"有几个", `%` 求"剩多少"——两个运算符配合, 把金额一层层拆开

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task4-change.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task4-change.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 4: 参考代码与要点

---

参考实现: 用 / 和 % 逐层拆金额:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;font-size:0.55em;">

```C{.line-numbers}
/* change.c: 找零计算 */
#include <stdio.h>
int main(void) {
  int amount;
  printf("请输入金额 (元): ");
  scanf("%d", &amount);
  printf("100元: %d 张\n", amount / 100);
  amount = amount % 100;
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

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `amount / 100`: 整数除法, 得到"有几个 100"

- `amount % 100`: 取余, 得到"剩下的钱"——再拿剩下的继续拆

- `amount = amount % 100;`: ==新值覆盖旧值==, 同一个变量反复赋值

- `/` 与 `%` 只对整数有意义; 浮点数不能取余

</div>

</div>

整数运算会了, 最后看字符:

---

<!-- slide data-notes="" -->##### 任务 5: 字符与编码

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 存一个大写字母, 输出它的 ASCII 编码; 再把编码存成整数, 输出对应的字符

样例:

```
M 的编码是 77
编码 77 对应 M
```

==提示==:

- 字符用 `char`, 值写在==单引号==里: `'M'`

- 同一个值, 用 `%c` 打印是字符, 用 `%d` 打印是编码——两种都试试

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task5-char.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task5-char.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 5: 参考代码与要点

---

参考实现: 同一个值, 两种占位符两种视角:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  char ch = 'M';
  int code = 77;

  printf("%c 的编码是 %d\n", ch, ch);
  printf("编码 %d 对应 %c\n", code, code);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `char` 存的其实是==字符的编码== (0~127 的整数): `'a'`=97, `'A'`=65, `'0'`=48

- ==单引号==是字符 (`'M'`), 双引号是字符串 (`"M"`)——字符串后面再讲

- `%c` 按字符打印, `%d` 按整数打印; 同一个 `ch` 两种视角

- 字符本质是整数, 可以参与运算 (如 `'a' - 'A'` 等于 32)——常用编码见==下一页 ASCII 表==

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 6: 交换两个数

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 读入两个整数 a、b, ==交换==它们的值后输出

样例:

```
输入: 3 5
输出: a=5 b=3
```

==提示==: 直接写 `a = b; b = a;` 会怎样? 试试看, 再用==临时变量==修正

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/1-intro/code/task-swap.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-swap.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 6: 参考代码与要点

---

<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>
int main(void)
{
  int a, b, t;
  scanf("%d %d", &a, &b);
  t = a;   /* 先把 a 存起来 */
  a = b;
  b = t;
  printf("a=%d b=%d\n", a, b);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- 直接 `a=b; b=a;`: 第一步就把 a 原值==覆盖==, 两次都变成 b 的值

- 用==临时变量== `t` 保存一个值, 再交换——这就是赋值"覆盖"特性的应用

- 顺序: 先存 a → 把 b 给 a → 把 t (原 a) 给 b

- 三行交换是后面排序、链表操作的==基本动作==

</div>
</div>

---

<!-- slide data-notes="" -->##### 工具页: ASCII 码速查

---

<div style="font-size:0.8em;line-height:1.5;">

==ASCII==: 常用字符的编码表 (0~127)。记住三组就够用:

<div class="fullborder">

| 字符 | 编码 | 字符 | 编码 | 字符 | 编码 |
| :-- | :-- | :-- | :-- | :-- | :-- |
| 空格 `' '` | 32 | `'0'` | 48 | `'A'` | 65 |
| `'!'` | 33 | `'1'` | 49 | `'B'` | 66 |
| `','` | 44 | `'9'` | 57 | `'Z'` | 90 |
| `'.'` | 46 | | | `'a'` | 97 |
| `'?'` | 63 | | | `'z'` | 122 |

</div>

- ==数字字符==: `'0'`~`'9'` 连续 → 48~57; 想得到数值要 `ch - '0'`

- ==大写字母==: `'A'`~`'Z'` 连续 → 65~90; ==小写==: `'a'`~`'z'` 连续 → 97~122

- ==小写比大写大 32==: `'a' - 'A' == 32`——后面做大小写转换会用到

- 换行 `\n` 的编码是 10; 控制字符不可打印, 用 `%c` 打印会看到怪符号

</div>

---

<!-- slide data-notes="" -->##### 语法补全: 标识符与关键字

---

编码表备查; 回到语法, 先看名字怎么起:

<div style="font-size:0.95em;line-height:1.8;">

==标识符==: 变量、函数等对象的==名字==

- 由字母、数字、下划线组成; ==不能以数字开头== (`10times` 非法)

- C 是==大小写敏感==的: `job`、`Job`、`jOb` 是三个不同的名字

- 不能用==关键字== (`int`、`return`、`if`、`while` …); 建议避免以下划线开头

- 起名要==见名知义==: `birth_year` 比 `a` 好; 风格统一

</div>

---

<!-- slide data-notes="" -->##### 语法补全: 声明、初始化与赋值

---

名字会起了, 再看变量怎么声明、初始化、赋值:

<div style="font-size:0.85em;line-height:1.6;">

```C{.line-numbers}
int height;          /* 声明: 留一个装整数的盒子, 但还没放值 */
int height = 8;      /* 初始化: 声明的同时放入 8 */
height = 10;         /* 赋值: 用新值覆盖旧值 */
```

<div class="top-1">
<svg viewBox="0 0 400 150" style="max-width:100%;height:190px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<text x="30" y="20" font-size="15.5" fill="#586e75" font-family="Menlo, monospace">int height;</text>
<rect x="30" y="30" width="150" height="70" rx="8" fill="#fdf6e3" stroke="#dc322f" stroke-width="2.5" stroke-dasharray="7 5"/>
<text x="105" y="70" font-size="40" fill="#dc322f" text-anchor="middle">?</text>
<text x="105" y="90" font-size="13.5" fill="#dc322f" text-anchor="middle">残留的垃圾值</text>
<text x="230" y="20" font-size="15.5" fill="#586e75" font-family="Menlo, monospace">int height = 8;</text>
<rect x="230" y="30" width="150" height="70" rx="8" fill="#dceaf5" stroke="#268bd2" stroke-width="2.5"/>
<text x="305" y="70" font-size="40" fill="#859900" text-anchor="middle">8</text>
<text x="305" y="90" font-size="13.5" fill="#586e75" text-anchor="middle">确定的值</text>
<text x="30" y="122" font-size="13.5" fill="#586e75">分配了盒子, 但没放值</text>
<text x="230" y="122" font-size="13.5" fill="#586e75">声明的同时放入 8</text>
<text x="200" y="145" font-size="13.5" fill="#b58900" text-anchor="middle">读未初始化的盒子 → 结果不可预知</text>
</g>
</svg>
</div>

- `=` 是==赋值==不是"相等"; 赋值前必须先声明

</div>

---

<!-- slide data-notes="" -->##### 输入输出格式一览

---

变量会用了, 还要会读写——四种常用类型的占位符:

<div class="fullborder">

| 类型 | printf 占位符 | scanf 占位符 | 例子 |
| :-- | :-- | :-- | :-- |
| `int` | `%d` | `%d` | `printf("%d", n);` / `scanf("%d", &n);` |
| `float` | `%f` | `%f` | `printf("%.1f", f);` / `scanf("%f", &f);` |
| `double` | `%f` | `%lf` | `printf("%.2f", d);` / `scanf("%lf", &d);` |
| `char` | `%c` | `%c` | `printf("%c", ch);` / `scanf(" %c", &ch);` |

</div>

<div style="font-size:0.9em;line-height:1.7;">

- ==scanf 的参数要加 `&`== (取地址); printf 不用

- double: ==printf 用 `%f`, scanf 用 `%lf`==——最容易混的一处

- `%.1f` / `%.2f`: 保留 1 位/2 位小数

- `%c` 前加空格 (` %c`) 可跳过遗留的空白/换行

</div>

---

<!-- slide data-notes="" -->##### 课堂编码

---

==轮到你了: 把课程演示变成自己的程序==——现场完成 (10 分钟):

1. ==温度转换==: 输入摄氏温度, 输出华氏温度 ($F = \frac{9}{5}C + 32$)

2. ==交换两个数==: 见任务 6, 先自己写一遍, 再对照参考页

提示:

- 变量: 需要什么类型? (`double`? `int`?)

- 输入: `scanf("%lf", &c);` —— 不要遗漏 ==&==

- 输出: `printf("%.1f\n", f);`

<span class="blue">:fa-lightbulb-o:</span> 卡住了? 温度转换看任务 3; 交换两个数先自己想, 再问助教——==今天每个人的程序都要能跑起来==

---

<!-- slide data-notes="" -->##### 课堂小测

---

程序跑通后, 用四道题检验概念:

1. 概念: 声明 `int x;` 与初始化 `int x = 5;` 有什么区别? 只声明不初始化就用, 可能发生什么?

2. 概念: 打印 double 用哪个占位符? 用 scanf 读 double 呢?

3. 代码阅读: `int a = 7, b = 2; printf("%d %f\n", a / b, a / 2.0);` 输出什么? 为什么?

4. 纠错: 下面三行各有错, 找出来并改正:
   ① `int 2age = 19;`
   ② `scanf("%d", age);`
   ③ `char c = "M";`

---

<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
