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

- 预处理与宏

- 源文件与头文件

- `#include`、共享宏/类型/函数原型

- 保护头文件

- 构建多文件程序与 makefile

---


<!-- slide data-notes="" -->


##### 预处理: 编译前的文本加工

---

编译前的==预处理==阶段: 处理以 ==#== 开头的命令

- `#include`: 文件包含——把指定文件的内容==原样复制==进来

- `#define`: 宏定义——文本替换

- `#if` / `#ifdef` / `#ifndef`: 条件编译——按条件选择性地编译代码

宏 = ==纯文本替换==。用 `gcc -E` 亲眼看看展开前后:

<div class="fullborder">

| 你写的 | 预处理后 (`gcc -E`) |
| :-- | :-- |
| `#define PI 3.14` | (定义行消失) |
| `area = PI * r * r;` | `area = 3.14 * r * r;` |

</div>

- 现场演示: `gcc -E celsius.c | tail -20`

<!-- slide data-notes="" -->

##### 预处理: 编译前的文本加工 (续)

---

- 记住"就是文本替换", 后面宏的所有怪现象都能解释

- 经典错误: ==`#define N = 100`== (多了等号) 和 ==`#define N 100;`== (多了分号)——文本替换会把它们原样带进代码

- 宏行末==没有分号==, 宏名习惯==全大写==

<!-- slide data-notes="" -->


##### 源文件

---

<div style="display:flex;align-items:flex-start;gap:24px;">



<div style="flex:1;font-size:0.6em;">

C 程序可分割成任意数量的==源文件== (扩展名 `.c`), 每个源文件包含程序的一部分 (主要是函数和变量的定义); 其中一个必须包含 `main` 函数, 作为程序的起点.

例: 逆波兰记法 (RPN) 计算器 (`30 5 - 7 *` → 175)——读取操作数与运算符, 用栈跟踪中间结果, 左列是程序划分方案.

</div>
</div>

<svg viewBox="0 0 400 180" style="max-width:100%;height:180px;" role="img" aria-label="RPN 计算器拆分为三个源文件">
  <defs>
    <marker id="mf-src-arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#268bd2"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="200" y="14" font-size="11" fill="#586e75" text-anchor="middle">RPN 计算器: 按功能拆成三个源文件</text>

    <rect x="140" y="26" width="120" height="44" rx="6" fill="#dceaf5" stroke="#268bd2" stroke-width="2"/>
    <text x="200" y="45" font-size="12.5" font-weight="700" fill="#073642" text-anchor="middle">calc.c</text>
    <text x="200" y="61" font-size="9" fill="#586e75" text-anchor="middle">main · 主循环</text>

    <rect x="10" y="100" width="120" height="50" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="70" y="119" font-size="12" font-weight="700" fill="#073642" text-anchor="middle">token.c</text>
    <text x="70" y="136" font-size="9.5" fill="#586e75" text-anchor="middle">get_token()</text>

    <rect x="270" y="100" width="120" height="62" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="330" y="119" font-size="12" font-weight="700" fill="#073642" text-anchor="middle">stack.c</text>
    <text x="330" y="136" font-size="9.5" fill="#586e75" text-anchor="middle">push / pop / ...</text>
    <text x="330" y="152" font-size="8.5" fill="#93a1a1" text-anchor="middle">栈变量也放这里</text>

    <line x1="160" y1="70" x2="72" y2="98" stroke="#268bd2" stroke-width="1.6" marker-end="url(#mf-src-arrow)"/>
    <line x1="240" y1="70" x2="328" y2="98" stroke="#268bd2" stroke-width="1.6" marker-end="url(#mf-src-arrow)"/>
    <text x="103" y="87" font-size="8.5" fill="#268bd2" text-anchor="middle">调用</text>
    <text x="297" y="87" font-size="8.5" fill="#268bd2" text-anchor="middle">调用</text>
    <text x="200" y="174" font-size="9" fill="#586e75" text-anchor="middle">每个 .c 单独编译; 相关的函数和变量放在一起</text>
  </g>
</svg>

<!-- slide data-notes="" -->


##### 源文件 (续)

---

读取记号的函数可以与任何需要用到记号的函数一起放入一个源文件(例如`token.c`). 

与栈相关的函数, 如push, pop, make_empty, is_empty和is_full可以放入另一个文件`stack.c`中. 

代表栈的变量也放入stack.c. 

main函数放入另一个文件calc.c中.


把程序拆成多个源文件的好处: 

- 将相关函数和变量分组到一个文件中可以使程序的结构清晰. 

- 每个源文件都可以单独编译, 节省时间. 

- 将函数分组放在不同的源文件中更利于复用.

---


<!-- slide data-notes="" -->


##### 头文件

---

<div style="display:flex;align-items:flex-start;gap:24px;">



<div style="flex:1;font-size:0.6em;">

程序拆成几个源文件后, 新问题来了: 

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

</div>

</div>

<!-- slide data-notes="" -->


##### #include 指令

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.5em;">

```C
#include <文件名>
```

```C
#include "文件名"
```

```C
#include <myheader.h> /*** 错误 ***/
```

</div>

<div style="flex:1;font-size:0.6em;">

`#include` 有两种写法: `<文件名>` 找 C 自带的库头文件, `"文件名"` 找其他头文件——区别在于编译器==去哪里找==:

- `<文件名>`: 搜索系统头文件目录
- `"文件名"`: 先搜当前目录, 再搜系统头文件目录

通常: 自带库用尖括号, 自己写的头文件用引号.

</div>

</div>

<!-- slide data-notes="" -->

##### #include 指令 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.5em;">

```C
#include "c:\cprogs\utils.h"
/* Windows 路径 */

#include "/cprogs/utils.h"
/* UNIX 路径 */
```

```C
#include "d:utils.h"
#include "\cprogs\include\utils.h"
#include "d:\cprogs\include\utils.h"
```

```C
#include "utils.h"
#include "..\include\utils.h"
```

</div>

<div style="flex:1;font-size:0.6em;">

路径可以写绝对路径, 也可以写相对路径.

Windows 路径中的反斜杠要转义 (`\\`), 或者改用 `/`.

`..` 表示上一级目录; 相对路径是相对源文件所在目录而言的.

</div>

</div>

<!-- slide data-notes="" -->

##### #include 指令 (续 2)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.5em;">

```C
#include 标记            /* 标记是宏名, 展开后须形如 <文件名> 或 "文件名" */
```

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

</div>

<div style="flex:1;font-size:0.6em;">

`#include` 后面也可以是一个宏名: 预处理器先展开宏, 再按展开结果包含文件.

条件编译常用来根据平台选择不同的头文件.

`#if` / `#elif` / `#else` / `#endif` 按常量表达式选择分支; `#ifdef` / `#ifndef` 检查宏是否已定义.

</div>

</div>

<!-- slide data-notes="" -->


##### 共享宏定义和类型定义

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
#define BOOL int
#define TRUE 1
#define FALSE 0
```

```C
#include "boolean.h"
```

</div>

<div style="flex:1;font-size:0.6em;">

大多数大型程序包含由多个源文件共享的宏定义和类型定义.

这些定义应该放入头文件.

假设一个程序使用名为 BOOL, TRUE 和 FALSE 的宏.

它们的定义可以放进一个叫 *boolean.h* 的头文件:

任何需要这些宏的源文件将只包含该行

两个文件都包含 boolean.h:

<div class="top-2">
  <img src="../img/18-1.png" width=380px>
</div>

</div>

</div>

<!-- slide data-notes="" -->

##### 共享宏定义和类型定义 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C
#define TRUE 1
#define FALSE 0
typedef int Bool;
```

</div>

<div style="flex:1;font-size:0.6em;">

类型定义在头文件中也很常见.

例如可使用 typedef 来创建一个 Bool 类型, 而不是定义 BOOL 宏.

这么做了之后, boolean.h 里会是:

把宏和类型定义放头文件的好处:

- 节省时间. 我们不必将定义复制到需要它们的源文件中.
- 使程序更容易修改. 更改宏或类型的定义只需要编辑单个头文件.
- 避免由源文件包含相同宏或类型的不同定义而导致的不一致.

</div>

</div>

<!-- slide data-notes="" -->


##### 宏定义: 带参宏

---

==带参宏==: 像函数一样使用, 但只是文本替换

```C
#define MAX(a, b) ((a) > (b) ? (a) : (b))

x = MAX(p + q, r + s);
/* 展开为 x = ((p+q) > (r+s) ? (p+q) : (r+s)); */
```

- 宏 vs 函数: 宏在预处理阶段只做==文本替换==, 实参不会先求值, 也没有类型; 但实参展开后可能出现多次——`MAX(i++, j)` 在 `i++ > j` 时会自增两次, 所以==不要传带副作用的实参==

- <span class="yellow">:fa-weixin:</span> 宏名与左括号之间==不能有空格==: `#define MAX (a,b) ...` 会被当成"无参数的 MAX", 报错信息离现场很远

---


<!-- slide data-notes="" -->


##### 共享函数原型

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);
```

</div>

<div style="flex:1;font-size:0.6em;">

源文件调用 foo.c 里定义的函数 f 时, 不声明会直接报错——C99 起==不再允许隐式声明== (GCC/Clang 默认报 error).

到处声明又造成维护"噩梦". 更好的方案: ==原型放头文件 (foo.h)==, 调用处都包含它; foo.c 也包含 foo.h, 让编译器核对原型与定义一致.

foo.c 的大多数函数应在 foo.h 声明; 只在 foo.c 内部使用的函数==不应==写进头文件 (会误导).

</div>

</div>

<!-- slide data-notes="" -->

##### 共享函数原型 (续)

---

RPN 计算器示例: `stack.c` 定义 make_empty / is_empty / is_full / push / pop, 原型放 stack.h; calc.c 包含 stack.h 检查调用, stack.c 也包含它核对定义一致:

<div class="top-2">
  <img src="../img/18-2.png" width=380px>
</div>

<!-- slide data-notes="" -->


##### 共享变量声明

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C
/* file1.c */
int i;                    /* 定义: 为 i 留空间 */
```

```C
/* file2.c */
extern int i;             /* 声明: i 在别处定义 */
```

```C
/* file2.c */
extern int a[];           /* 数组声明可省略长度 */
```

```C
/* file2.c (错误示例) */
extern long i;            /* 与 file1.c 的 int 定义类型不一致! */
```

</div>

<div style="flex:1;font-size:0.6em;">

共享函数: 定义放在一个源文件, 声明放在需要调用的其他文件; 共享外部变量的方式相同.

`extern` 关键字==只声明不定义== (不带初始化式时只为声明, 不分配空间).

==类型必须一致==: 某文件定义 `int i;`, 另一文件却写 `extern long i;`, 编译器可能查不出, 运行时行为异常.

</div>
</div>

<!-- slide data-notes="" -->


##### 嵌套包含

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C
int is_empty(void);
int is_full(void);
```

```C
Bool is_empty(void);
Bool is_full(void);
```

</div>

<div style="flex:1;font-size:0.6em;">

头文件可能包含`#include`指令. 

stack.h 里的原型:

这些函数只返回 0 或 1, 返回类型最好声明成 Bool:

在 stack.h 中包含boolean.h, 以便在编译时可以使用Bool的定义.


传统上, C 程序员避免使用嵌套包含. 

如今对嵌套包含已经没什么偏见了——部分原因是 C++ 里嵌套包含很常见。

</div>

</div>

<!-- slide data-notes="" -->


##### 保护头文件

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
#ifndef BOOLEAN_H
#define BOOLEAN_H

#define TRUE 1
#define FALSE 0
typedef int Bool;

#endif
```

</div>

<div style="flex:1;font-size:0.6em;">

如果一个源文件两次包含相同的头文件, 可能会导致编译错误. 

当头文件包含其他头文件时, 此问题很常见: file1.h 和 file2.h 都包含 file3.h, prog.c 又同时包含 file1.h 和 file2.h——编译 prog.c 时 file3.h 被编译两次:

<div class="top-2">
  <img src="../img/18-3.png" width=380px>
</div>

- 只含宏定义/函数原型/变量声明时重复包含没困难; 含==结构体/枚举定义或变量定义==就会编译错误

- 安全起见, ==所有头文件都加保护==: 以后往头文件里加类型定义也不用担心忘记保护

</div>

</div>

<!-- slide data-notes="" -->


##### 保护头文件: ifndef 写法

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
#ifndef BOOLEAN_H
#define BOOLEAN_H

#define TRUE 1
#define FALSE 0
typedef int Bool;

#endif
```

</div>

<div style="flex:1;font-size:0.6em;">

把文件的内容包在 `#ifndef` - `#endif` 对里:

- 第一次包含: `BOOLEAN_H` 未定义 → 定义它 + 展开内容

- 之后再包含: `BOOLEAN_H` 已定义 → 直接跳过全部内容

宏名照头文件名取 (`BOOLEAN.H` 不能作宏名, 用 `BOOLEAN_H`), 避免与其他宏冲突

</div>

</div>

<svg viewBox="0 0 400 190" style="max-width:100%;height:190px;" role="img" aria-label="头文件保护宏的两次包含">
  <defs>
    <marker id="hdr-arrow-green" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#859900"/>
    </marker>
    <marker id="hdr-arrow-red" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#dc322f"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <rect x="150" y="8" width="100" height="26" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="200" y="25" font-size="11" fill="#073642" text-anchor="middle">prog.c</text>

    <rect x="30" y="52" width="95" height="26" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="77" y="69" font-size="11" fill="#073642" text-anchor="middle">file1.h</text>
    <rect x="275" y="52" width="95" height="26" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="322" y="69" font-size="11" fill="#073642" text-anchor="middle">file2.h</text>

    <line x1="180" y1="34" x2="80" y2="50" stroke="#93a1a1" stroke-width="1.4" marker-end="url(#hdr-arrow-green)"/>
    <line x1="220" y1="34" x2="320" y2="50" stroke="#93a1a1" stroke-width="1.4" marker-end="url(#hdr-arrow-red)"/>

    <rect x="150" y="104" width="100" height="32" rx="5" fill="#dceaf5" stroke="#268bd2" stroke-width="2"/>
    <text x="200" y="125" font-size="11.5" font-weight="700" fill="#268bd2" text-anchor="middle">file3.h</text>

    <path d="M77,78 L77,120 L148,120" fill="none" stroke="#859900" stroke-width="1.7" marker-end="url(#hdr-arrow-green)"/>
    <path d="M322,78 L322,120 L252,120" fill="none" stroke="#dc322f" stroke-width="1.7" marker-end="url(#hdr-arrow-red)"/>
    <text x="81" y="98" font-size="8.5" fill="#859900">第 1 次: 展开</text>
    <text x="318" y="98" font-size="8.5" fill="#dc322f" text-anchor="end">第 2 次: 跳过</text>

    <text x="200" y="152" font-size="9" fill="#586e75" text-anchor="middle">同一份 file3.h, 编译 prog.c 时被包含两次</text>
    <text x="8" y="170" font-size="9.3" fill="#859900">第一次: FILE3_H 未定义 → 定义它, 展开内容</text>
    <text x="8" y="184" font-size="9.3" fill="#dc322f">第二次: FILE3_H 已定义 → 整段跳过</text>
  </g>
</svg>

<!-- slide data-notes="" -->


##### 将程序划分为文件

---

<div style="display:flex;align-items:flex-start;gap:24px;">



<div style="flex:1;font-size:0.6em;">

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

</div>

</div>

<!-- slide data-notes="" -->##### 构建多文件程序

---

- 构建大型程序与小型程序步骤相同: ==编译== + ==链接==

- 每个源文件必须单独编译 (头文件不编译, 随包含它的源文件一起编译); 编译器为每个源文件生成目标文件 (`.o` / `.obj`)

- 链接器把目标文件与库函数代码组合成可执行文件, 并解决==外部引用== (一个文件调用另一个文件中的函数或变量)

- 大多数编译器允许一步构建: `gcc -o justify justify.c line.c word.c`——三个源文件先编译成目标文件, 自动传给链接器; `-o` 指定可执行文件名

<svg viewBox="0 0 400 190" style="max-width:100%;height:190px;" role="img" aria-label="多文件编译与链接流程">
  <defs>
    <marker id="mf-build-arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#268bd2"/>
    </marker>
    <marker id="mf-build-arrow-g" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#859900"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="90" y="14" font-size="12" font-weight="700" fill="#268bd2" text-anchor="middle">① 编译</text>
    <text x="330" y="14" font-size="12" font-weight="700" fill="#859900" text-anchor="middle">② 链接</text>

    <rect x="8" y="26" width="82" height="32" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="49" y="46" font-size="11" fill="#073642" text-anchor="middle">justify.c</text>
    <rect x="8" y="82" width="82" height="32" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="49" y="102" font-size="11" fill="#073642" text-anchor="middle">word.c</text>
    <rect x="8" y="138" width="82" height="32" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="49" y="158" font-size="11" fill="#073642" text-anchor="middle">line.c</text>

    <rect x="148" y="26" width="72" height="32" rx="5" fill="#eee8d5" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="184" y="46" font-size="10.5" fill="#073642" text-anchor="middle">justify.o</text>
    <rect x="148" y="82" width="72" height="32" rx="5" fill="#eee8d5" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="184" y="102" font-size="10.5" fill="#073642" text-anchor="middle">word.o</text>
    <rect x="148" y="138" width="72" height="32" rx="5" fill="#eee8d5" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="184" y="158" font-size="10.5" fill="#073642" text-anchor="middle">line.o</text>

    <line x1="90" y1="42" x2="146" y2="42" stroke="#268bd2" stroke-width="1.6" marker-end="url(#mf-build-arrow)"/>
    <line x1="90" y1="98" x2="146" y2="98" stroke="#268bd2" stroke-width="1.6" marker-end="url(#mf-build-arrow)"/>
    <line x1="90" y1="154" x2="146" y2="154" stroke="#268bd2" stroke-width="1.6" marker-end="url(#mf-build-arrow)"/>
    <text x="118" y="37" font-size="8" fill="#586e75" text-anchor="middle">gcc -c</text>

    <line x1="220" y1="42" x2="252" y2="42" stroke="#93a1a1" stroke-width="1.3"/>
    <line x1="220" y1="98" x2="252" y2="98" stroke="#93a1a1" stroke-width="1.3"/>
    <line x1="220" y1="154" x2="252" y2="154" stroke="#93a1a1" stroke-width="1.3"/>
    <line x1="252" y1="42" x2="252" y2="154" stroke="#93a1a1" stroke-width="1.3"/>
    <line x1="252" y1="98" x2="284" y2="98" stroke="#859900" stroke-width="1.8" marker-end="url(#mf-build-arrow-g)"/>

    <rect x="286" y="80" width="88" height="36" rx="6" fill="#dceaf5" stroke="#268bd2" stroke-width="2"/>
    <text x="330" y="103" font-size="13" font-weight="700" fill="#268bd2" text-anchor="middle">justify</text>

    <rect x="286" y="146" width="88" height="24" rx="4" fill="#eee8d5" stroke="#b58900" stroke-width="1.2"/>
    <text x="330" y="162" font-size="9.5" fill="#073642" text-anchor="middle">库函数 (libc)</text>
    <line x1="330" y1="146" x2="330" y2="120" stroke="#859900" stroke-width="1.6" marker-end="url(#mf-build-arrow-g)"/>

    <text x="8" y="186" font-size="9" fill="#586e75">头文件 (.h) 不单独编译, 随包含它的 .c 源文件一起编译</text>
  </g>
</svg>
<!-- slide data-notes="" -->


##### makefile

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

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

</div>

<div style="flex:1;font-size:0.6em;">

为了更容易构建大型程序, UNIX 发明 makefile 的概念.

makefile 不仅列出了作为程序一部分的文件, 而且还描述了文件之间的依赖关系.

假设文件 foo.c 包含文件 bar.h.

我们说 foo.c "依赖于" bar.h, 因为修改 bar.h 之后需要重新编译 foo.c.

针对 justify 程序的 UNIX 系统的 makefile:

有 4 组代码行; 每个组称为一条规则.

每个规则的第一行给出目标文件, 然后是它所依赖的文件.

第二行是当目标文件依赖的文件发生改变而需要重新构建目标文件时要执行的命令.

</div>

</div>

<!-- slide data-notes="" -->

##### makefile (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```
justify: justify.o word.o line.o
        gcc -o justify justify.o word.o line.o   ← 错误: 命令行前是 8 个空格
```

</div>

<div style="flex:1;font-size:0.6em;">

在第一条规则中, justify(可执行文件)是目标文件:

第一行说明 justify 依赖于文件 justify.o, word.o 和 line.o.

如果自上次构建程序以来这些文件中的任何一个发生了更改, 则需要重新构建 justify.

下一行的命令显示了如何进行重新构建.

==每个命令行必须以 TAB 开头==——写 8 个空格, make 会报 `missing separator` 错误 (上面就是错误示范).

</div>

</div>

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

3. 纠错: make 报 `missing separator`，最可能是什么原因？应该改成什么？

4. 把函数原型放进头文件、函数定义放进 .c 文件，有什么好处？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
