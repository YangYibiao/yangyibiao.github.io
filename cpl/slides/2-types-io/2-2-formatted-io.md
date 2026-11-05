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

## 格式化输入输出

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 输出: printf与转换说明

- 转义序列

- 输入: scanf

- getchar与putchar

- 综合案例: 分数相加

---


<!-- slide data-notes="" -->


##### printf函数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;">

==`printf`== 函数必须提供格式字符串, 后跟打印期间要插入到串中的任何值: 
```C
printf(字符串, 表达式1, 表达式2, ...);
```

格式字符串可以包含普通字符和转换说明, 以 ==`%`== 字符开头

</div>

<div style="flex:1;text-align:center;">

<svg viewBox="0 0 400 195" style="max-width:100%;height:195px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
  <text x="200" y="18" font-size="11.5" fill="#586e75" text-anchor="middle">格式字符串 = 普通字符 + 占位符</text>

  <rect x="30" y="30" width="66" height="40" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.8"/>
  <text x="63" y="56" font-size="13" font-family="Menlo, monospace" fill="#073642" text-anchor="middle">"i = "</text>
  <rect x="100" y="30" width="44" height="40" rx="5" fill="#dceaf5" stroke="#268bd2" stroke-width="2.5"/>
  <text x="122" y="56" font-size="14" font-family="Menlo, monospace" fill="#268bd2" text-anchor="middle">%d</text>
  <rect x="148" y="30" width="78" height="40" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.8"/>
  <text x="187" y="56" font-size="13" font-family="Menlo, monospace" fill="#073642" text-anchor="middle">", j = "</text>
  <rect x="230" y="30" width="44" height="40" rx="5" fill="#dceaf5" stroke="#268bd2" stroke-width="2.5"/>
  <text x="252" y="56" font-size="14" font-family="Menlo, monospace" fill="#268bd2" text-anchor="middle">%d</text>
  <rect x="278" y="30" width="48" height="40" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.8"/>
  <text x="302" y="56" font-size="13" font-family="Menlo, monospace" fill="#073642" text-anchor="middle">"\n"</text>

  <path d="M122 106 V74" stroke="#268bd2" stroke-width="2" marker-end="url(#arrP)"/>
  <path d="M252 106 V74" stroke="#268bd2" stroke-width="2" marker-end="url(#arrP)"/>

  <rect x="72" y="106" width="100" height="34" rx="6" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
  <text x="122" y="128" font-size="13" font-family="Menlo, monospace" fill="#073642" text-anchor="middle">i = 10</text>
  <rect x="202" y="106" width="100" height="34" rx="6" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
  <text x="252" y="128" font-size="13" font-family="Menlo, monospace" fill="#073642" text-anchor="middle">j = 20</text>

  <text x="200" y="162" font-size="11" fill="#586e75" text-anchor="middle">按顺序一一对应, 值填进空位</text>
  <text x="200" y="186" font-size="13.5" fill="#859900" text-anchor="middle">输出: i = 10, j = 20↵</text>

  <defs>
    <marker id="arrP" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto">
      <path d="M0 0 L7 3.5 L0 7 z" fill="#268bd2"/>
    </marker>
  </defs>
</g>
</svg>

</div>

</div>

==转换说明== 是一个占位符, 表示要在打印期间填充的值
- ==`%d`== 用于 ==`int`== 值
- ==`%f`== 用于 ==`float`== / ==`double`== 值 (printf 中 float 自动提升为 double)
- ==`%c`== 用于 ==`char`== 值
- ==`%s`== 用于 ==`char []`== 值

---


<!-- slide data-notes="" -->


##### printf函数

---

格式字符串:
- ==普通字符== 按出现在字符串中的方式打印
- ==转换说明== 则需用待显示的值来替换填充

<div style="font-size:0.8em;">

```C{.line-numbers}
int i, j;
float x, y;
 
i = 10;
j = 20;
x = 43.2892f;
y = 5527.0f;

printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);
```

</div>

```
输出: 
i = 10, j = 20, x = 43.289200, y = 5527.000000
```

---


<!-- slide data-notes="" -->


##### printf函数

---

- 编译器==不检查==格式串与输出项是否匹配:

```C
printf("%d %d\n", i);    /*** WRONG: 转换说明过多 ***/
printf("%d\n", i, j);    /*** WRONG: 转换说明太少 ***/
```

- 也不检查转换说明是否合适; 用错了 → ==无意义的输出==

```C{.line-numbers}
int i;
float x;
printf("%f %d\n", i, x); /*** WRONG ***/
```

- `%d` 配 float/double 时, 读到的==不是这个数的比特==: 整数和浮点数调用时走==不同的通道==, `%d` 在整数通道里拿到的只是==残留的无关值== (第 3 周细讲)

<!-- slide data-notes="" -->


##### 转换说明

---

转换说明可以采用 ==`%m.pX`== 或 ==`%-m.pX`== 形式

- ==`m`== 和 ==`p`== 是整数常量
- ==`X`== 是一个字符
- ==`m`== 和 ==`p`== 都是可选的
- 如果省略 ==`p`==, 则分隔 ==`m`== 和 ==`p`== 的句点也应删除

在转换规约 ==`%10.2f`== 中, ==`m`== 为 ==`10`== , ==`p`== 为 ==`2`==, ==`X`== 为 ==`f`==
在转换规约 ==`%10f`== 中, ==`m`== 为 ==`10`== 且缺少 ==`p`==(连同句点)
在转换规约 ==`%.2f`== 中, ==`p`== 为 ==`2`==  且缺少 ==`m`==

---


<!-- slide data-notes="" -->


##### 转换说明

---

最小字段宽度 ==m== 指定要打印的最小字符数

- 如果要打印的值需要少于 ==m== 个字符, 则在字段内右对齐

转换说明 ==`%4d`== 会将数字 ==`123`== 显示为 ==`•123`==(==`•`== 表示空格字符)

- 如果要打印的值需要超过 ==m== 个字符, 则字段宽度会自动扩展为所需的大小, 若 ==m== 前面加上减号会导致左对齐

转换说明 ==`%-4d`== 会将数字 ==`123`== 显示为 ==`123•`==

---


<!-- slide data-notes="" -->


##### 转换说明

---

精度 ==p== 的含义取决于转换说明符 ==X== 的选择

- 结合 ==%d== 说明符使用, ==%m.pX== 中的 ==p== 表示要显示的最小位数(如需要, 将在数字的开头添加额外的零)

- 如果 ==p== 省略, 则默认它的值为 ==1==

浮点数的转换说明: 

- ==`%e`== 指数格式: ==p== 表示小数点后位数 (默认 6; p 为 0 不显示小数点)

- ==`%f`== 固定十进制格式: ==p== 含义与 `%e` 相同

- ==`%g`== 按数字大小自动选指数或定点: ==p== 表示最大有效位数, 不显示尾随零

---


<!-- slide data-notes="" -->


##### 程序: 使用printf格式化数字

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.68em;">

```C{.line-numbers}
/* Prints int and float values in various formats */ 
#include <stdio.h>
 
int main(void)
{
  int i;
  float x;
 
  i = 40;
  x = 839.21f;
 
  printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
  printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
 
  return 0;
}
```

</div>

<div style="flex:1;">

`tprintf.c`程序使用 ==printf== 以各种格式显示整数和浮点数

<div style="font-size:0.8em;">

```
输出:
|40|•••40|40•••|••040|
|•••839.210|•8.392e+02|839.21••••|
```

</div>

</div>

</div>

<!-- slide data-notes="" -->##### 任务 1: 打印对齐的成绩表
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 打印下面的表, 三列==对齐== (科目左对齐, 分数右对齐保留 1 位小数, 等级居中)

```
科目        分数    等级
语文      85.5      A
数学      92.0      A
英语      78.2      B
```

==提示==: 宽度修饰 `%8.1f` (总宽 8, 1 位小数, 右对齐); 左对齐用负号 `%-8s`; 表头与数据行==宽度一致==才对齐

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/2-types-io/code/task-table.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-table.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("%-8s%10s%8s\n", "科目", "分数", "等级");
  printf("%-8s%10.1f%8c\n", "语文", 85.5, 'A');
  printf("%-8s%10.1f%8c\n", "数学", 92.0, 'A');
  printf("%-8s%10.1f%8c\n", "英语", 78.2, 'B');
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- 格式: `%[标志][宽度][.精度]转换`——`%-8s` 左对齐, `%10.1f` 右对齐保留 1 位

- ==列对齐的前提==: 每一行同一个位置用==相同宽度==

- 宽度不够会自动加宽 (不会截断数字); 字符串超宽则照原样输出

- 表格类输出是 `printf` 宽度修饰最常见的用途

</div>
</div>

---


<!-- slide data-notes="" -->


##### 转义序列

---

形如 ==`\n`== 的代码称为 ==转义序列==

==转义序列==: 使字符串包含非打印(控制)字符和具有特殊含义的字符(如 ==`"`==)

转义序列的部分列表: 

<div class="fullborder">

| 警报(铃声) | \a |
| :--       | :-- |
| 回退符     | \b |
| 换行符     | \n |
| 水平制表符  | \t |

</div>

- 一个字符串可以包含任意数量的转义序列: 

  ```C
  printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
  ```

---

<!-- slide data-notes="" -->


##### 转义序列

---

<div>

另一常见的转义序列是 ==`\"`==, 代表 ==`"`== 字符: 

```C
printf("\"Hello!\""); /* prints "Hello!" */
```

</div>

<div>

要打印单个 ==`\`== 字符, 在字符串中放置两个 ==`\`==: 

```C
printf("\\"); /* prints one \ character */
```

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 用转义序列打印三行
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 打印下面的内容 (注意引号、反斜杠、制表符):

```
姓名	分数
"张三"	92
路径: C:\temp
```

==提示==: 换行 `\n`; 制表 `\t` (列间对齐); 双引号写 `\"`; 反斜杠本身写 `\\`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/2-types-io/code/task-escape.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-escape.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("姓名\t分数\n");
  printf("\"张三\"\t92\n");
  printf("路径: C:\\temp\n");
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `\n` 换行, `\t` 制表 (两列对齐比空格稳)

- `\"` 才能在字符串里打印出双引号; `\\` 才能打印出一个反斜杠

- 反斜杠是==转义引子==: 它和后面的字符合成"一个字符", 如 `\n` 是一个字符

- 反斜杠写单个会引发警告/意外转义 (如 `\t` 变制表符)

</div>
</div>

---


<!-- slide data-notes="" -->


##### scanf函数

---

==`scanf`== 根据指定格式读取输入; 格式字符串同样含==普通字符==与==转换说明==, 与 ==`printf`== 基本相同

<span class="yellow">:fa-weixin:</span> 在多数情况下, ==`scanf`== 格式字符串只包含转换说明: 

<div style="font-size:0.85em;">

```C{.line-numbers}
int i, j;
float x, y;

scanf("%d%d%f%f", &i, &j, &x, &y);
```

</div>

样本输入: 

`1 -20 .3 -4.0e3`

==`scanf`== 将变量 `i`、`j`、`x`和`y`赋值为 `1`、`–20`、`0.3` 和 `–4000.0`

---


<!-- slide data-notes="" -->


##### scanf函数

---

使用 ==`scanf`== 时, 程序员须自己检查: 

- ==转换说明== 的数量与 ==输入变量== 的数量是否相同

- 确保各个转换说明 ==适用于== 相应变量

==`&`== 符号通常需要用在 ==`scanf`== 调用中的每个变量之前

==`&`== 通常(但不总是)是必需的, 在读取输入至变量时需记住使用它

---

<!-- slide data-notes="" -->


##### scanf工作原理

---

- ==`scanf`== 尝试将输入字符组与格式字符串中的转换说明进行匹配

- 对每个转换说明, ==`scanf`== 尝试在输入数据中寻找适当类型数据, 必要时==跳过空格==

- 当被要求读取整数时, 首先搜索数字或正负号, 然后继续读取数字, 直到遇到非数字

- 遇到不能成为当前变量一部分的字符时, 会 ==放回== 该字符留待下次读取

- 如果数据读取不成功, ==`scanf`== 立即返回

- 输入流中没有可用的数据时, ==scanf 会等待用户输入==——交互式程序"卡住"往往就是在等你敲键盘

---

<!-- slide data-notes="" -->


##### scanf工作原理

---

- ==`scanf`== 搜索数字时忽略空白 (空格/制表/换行); 读取四个数字的调用: 

<div style="font-size:0.8em;">

```C
scanf("%d%d%f%f", &i, &j, &x, &y);
```

</div>

- 输入的数字可以在一行上, 也可以分布在多行上: 

<div style="font-size:0.8em;">

```
••1
-20•••.3
•••-4.0e3
```

</div>

样本输入 `1-20.3-4.0e3¤` 的处理步骤: 

- `%d` 把 `1` 存进 i、把 `-20` 存进 j (分别放回 `-` 和 `.`)

- `%f` 把 `0.3` 存进 x、把 `-4.0×10³` 存进 y (放回 `-` 和换行符)

---


<!-- slide data-notes="" -->

##### scanf 与输入缓冲区

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.68em;">

==scanf== 每次==从上次读到的位置接着读==, 程序里的多次调用共享同一条==输入字符流==: 

```C{.line-numbers}
int a, b;
printf("请输入两个整数: ");
scanf("%d", &a);          /* 读走 10, 剩 " 20↵" */
printf("a = %d\n", a);    /* 马上打印已读到的 */
scanf("%d", &b);          /* 跳过空格, 接着读 20 */
printf("b = %d\n", b);
```

用户==只输入一行== `10 20↵`: 

```
请输入两个整数: 10 20↵
a = 10
b = 20
```

</div>

<div style="flex:1;">

- 输入==先全部进入缓冲区==, 两条 ==`scanf`== 依次"消费": 第一个只拿走 `10`, 第二个接着拿走 `20`

- 夹在中间的 ==`printf`== 打印的是"已经读到的"——输入与输出互不干扰

- ==`scanf`== 读走的数据==不会再次被读到==(不回看、不重复)

<span class="yellow">:fa-weixin:</span> 试一试: 如果第一次只输入 `10↵` 就回车, 会发生什么? 程序会==卡住==等待继续输入——第二个 ==`scanf`== 在缓冲区里找不到整数

</div>

</div>

---


<!-- slide data-notes="" -->

##### scanf 读字符与"遗留的换行"

---

<div style="display:flex;align-items:flex-start;gap:20px;">

<div style="flex:1.25;">

- `%d`、`%f` 会自动跳过空格和换行; ==`%c` 不会==——它读到的可能就是上一次输入留下的换行符

```C
int n; char ch;
scanf("%d", &n);
scanf("%c", &ch);       /* 读到的是 '\n' 或空格, 不是用户新输入的字符! */
```

- 解决: 在 `%c` 前加一个空格表示"跳过空白": `scanf(" %c", &ch);`

- scanf 与 getchar 混用时的经典坑: scanf 结束后==换行符还留在输入流里==, 会被后面的 `getchar()` 当"第一个字符"吃掉

```C
scanf("%d", &n);
getchar();              /* 先把遗留的换行符吃掉, 再读下面的字符 */
```

</div>

<div style="flex:1;text-align:center;">

<svg viewBox="0 0 400 200" style="max-width:100%;height:200px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
  <text x="14" y="18" font-size="12" fill="#586e75">用户输入: 12↵</text>

  <rect x="20" y="28" width="42" height="36" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
  <text x="41" y="54" font-size="20" fill="#073642" text-anchor="middle">1</text>
  <rect x="62" y="28" width="42" height="36" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
  <text x="83" y="54" font-size="20" fill="#073642" text-anchor="middle">2</text>
  <rect x="104" y="28" width="42" height="36" rx="4" fill="#fde4e2" stroke="#dc322f" stroke-width="2.5"/>
  <text x="125" y="53" font-size="18" fill="#dc322f" text-anchor="middle">↵</text>

  <path d="M20 66 V72 H104 V66" fill="none" stroke="#268bd2" stroke-width="1.5"/>
  <path d="M62 72 V94" fill="none" stroke="#268bd2" stroke-width="2" marker-end="url(#arrScanA)"/>
  <path d="M125 64 V80 H190 V94" fill="none" stroke="#dc322f" stroke-width="2" marker-end="url(#arrScanB)"/>
  <text x="68" y="88" font-size="11" fill="#268bd2">%d</text>
  <text x="130" y="78" font-size="11" fill="#dc322f">%c</text>

  <rect x="18" y="96" width="92" height="44" rx="6" fill="#dceaf5" stroke="#268bd2" stroke-width="2.5"/>
  <text x="28" y="113" font-size="11" fill="#586e75">int n</text>
  <text x="64" y="134" font-size="20" fill="#073642" text-anchor="middle">12</text>
  <rect x="148" y="96" width="112" height="44" rx="6" fill="#fde4e2" stroke="#dc322f" stroke-width="2.5"/>
  <text x="158" y="113" font-size="11" fill="#586e75">char ch</text>
  <text x="204" y="134" font-size="18" fill="#dc322f" text-anchor="middle">'\n'</text>

  <text x="16" y="168" font-size="11.5" fill="#586e75">第一个 scanf: 只拿走 12, ↵ 留在缓冲区</text>
  <text x="16" y="189" font-size="11.5" fill="#dc322f">第二个 scanf("%c"): 直接读走 ↵, 不是新字符</text>

  <defs>
    <marker id="arrScanA" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto">
      <path d="M0 0 L7 3.5 L0 7 z" fill="#268bd2"/>
    </marker>
    <marker id="arrScanB" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto">
      <path d="M0 0 L7 3.5 L0 7 z" fill="#dc322f"/>
    </marker>
  </defs>
</g>
</svg>

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 3: 遗留换行的坑
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 先读年龄 (整数), 再读性别 (字符)——结果性别==读到了换行==, 打印为空。修复它。

样例:

```
输入: 19 M
期望: age=19 gender=M
```

==提示==: `scanf("%d")` 读完后缓冲区还剩一个 `\n`; 试在 `%c` 前==加一个空格==

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/2-types-io/code/task-newline.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-newline.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 3: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int age;
  char gender;

  scanf("%d", &age);
  scanf(" %c", &gender);   /* 空格: 跳过空白字符 */

  printf("age=%d gender=%c\n", age, gender);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `%d` 读完数字就停, ==换行还留在输入缓冲区==里

- `%c` 不跳过空白, 直接把那个 `\n` 读走——所以"看起来什么都没读到"

- 在 `%c` 前加==空格== (`" %c"`): 格式串里的空白会跳过所有空白字符

- 同类坑: 用 `getchar()` 手动吃掉换行, 也常用于读整行之前

</div>
</div>

---


<!-- slide data-notes="" -->##### 格式字符串中的普通字符

---

- 当在格式字符串中遇到一个或多个空白字符时, ==`scanf`== 从输入中读取空白字符, 直到它遇到一个非空白字符(即*放回*)

- 当它在格式字符串中遇到非空白字符时, ==`scanf`== 将其与下一个输入字符进行比较

- 如果匹配, 则 ==`scanf`== 丢弃输入字符并继续处理格式字符串

- 若不匹配, 则 ==`scanf`== 会将有问题的字符放回输入中, 然后中止

例子: 

- 如果格式字符串是 ==`"%d/%d"`== 并且输入是 ==`•5/•96`==, ==`scanf`== 成功

- 如果输入 ==`•5•/•96`==, 则 ==`scanf`== 失败, 因为格式字符串中的 ==`/`== 与输入中的空格不匹配

<span class="yellow">:fa-weixin:</span> 要在第一个数字后允许空格, 需改用格式字符串 ==`"%d /%d"`==

---

<!-- slide data-notes="" -->##### 任务 4: 一次读入混合类型
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 一行输入年龄、身高、性别, 读入 `int`、`double`、`char` 并回显:

```
输入 (年龄 身高 性别): 19 1.75 M
age=19 height=1.75 gender=M
```

==提示==: 三个转换说明按顺序匹配; `%c` 前留空格 (`" %c"`) 跳过空白; 别忘 `&`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/2-types-io/code/task-mixed-scanf.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-mixed-scanf.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 4: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int age;
  double height;
  char gender;

  printf("输入 (年龄 身高 性别): ");
  scanf("%d %lf %c", &age, &height, &gender);

  printf("age=%d height=%.2f gender=%c\n", age, height, gender);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- 一条 scanf 可以按顺序读多个值: `%d` → int, `%lf` → double, `%c` → char

- 输入里的空格会被格式串中的空白==跳过==; `%c` 不跳过, 所以写 `" %c"`

- scanf 的返回值是==成功读入的项数== (这里应为 3), 可用于检查输入

- 变量与转换说明==一一对应==, 顺序错了读到的是垃圾值

</div>
</div>

---


<!-- slide data-notes="" -->


##### printf与scanf混淆

---

==`scanf`== 和 ==`printf`== 的调用看起来相似, 但两者之间存在显著差异

- 一个常见的错误是在`printf`调用中将`&`放在变量前面: 

```C
printf("%d %d\n", &i, &j);  /*** WRONG ***/
```

- 不要错误地假设 ==`scanf`== 格式字符串应该类似于 ==`printf`==: 

```C
scanf("%d, %d", &i, &j);
```

若输入中逗号的位置实际是空格, 则scanf将终止而不读取j的值

- 多数情况下, 一定不要在 ==`scanf`== 格式化字符串的末尾放置换行符, 否则会导致交互式程序 ==挂起== 直到用户输入下一个非空格字符

---

<!-- slide data-notes="" -->


##### getchar与putchar

---

==getchar==: 读取单个字符

```C
int ch;              /* 注意: 返回值是 int, 不是 char! */
ch = getchar();      /* 从键盘读取一个字符, 存入 ch */
```

<span class="blue">:fa-lightbulb-o:</span> 为什么用 `int`? 因为 `getchar` 还可能返回 ==EOF==, `char` 装不下

==putchar==: 输出单个字符

```C
putchar(ch);      /* 在屏幕上显示字符 ch */
putchar('\n');    /* 输出换行符 */
```

<span class="blue">:fa-weixin:</span> getchar/putchar 读写字符的效率高于 scanf/printf, 在==字符处理==类程序(如统计输入字符个数)中常用

---

<!-- slide data-notes="" -->##### 任务 5: getchar / putchar 大小写转换
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 输入一个小写字母, 用 `getchar`/`putchar` 输出对应大写字母+换行:

```
输入: b
输出: B
```

==提示==: `getchar()` 返回字符的编码 (int); 小写比大写大 32: `c - 'a' + 'A'`

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/2-types-io/code/task-putchar.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-putchar.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 5: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int c = getchar();
  putchar(c - 'a' + 'A');
  putchar('\n');
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `getchar()` 读==一个字符==并返回编码 (int), 适合逐字符处理

- `putchar(c)` 输出一个字符; 用 `putchar('\n')` 换行

- 字符本质是整数: `c - 'a' + 'A'` 完成小写→大写 (差 32)

- 注意: 输入 "b 回车" 时, 回车还留在缓冲区——前面"遗留换行"的坑同理

</div>
</div>

---


<!-- slide data-notes="" -->


##### 程序: 分数相加

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}

#include <stdio.h>
 
int main(void)
{
  int num1, denom1, num2, denom2, result_num, result_denom;

  printf("Enter first fraction: ");
  scanf("%d/%d", &num1, &denom1);
 
  printf("Enter second fraction: ");
  scanf("%d/%d", &num2, &denom2);
 
  result_num = num1 * denom2 + num2 *denom1;
  result_denom = denom1 * denom2;
  printf("The sum is %d/%d\n",result_num, result_denom);

  return 0;
}
```

</div>

<div style="flex:1;">

示例程序输出: 

Enter first fraction: <u>5/6</u>
Enter second fraction: <u>3/4</u>
The sum is 38/24

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `printf("%-8.3f", x)` 中 `-`、`8`、`.3` 分别表示什么？

2. 要打印出字符 `"` 和 `\`，转义序列分别怎么写？

3. `scanf("%d/%d", &a, &b)` 要求用户怎么输入？

4. `getchar()` 返回值的类型是什么？为什么它适合读取字符？


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


