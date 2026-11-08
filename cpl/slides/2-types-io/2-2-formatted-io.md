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

<div style="font-size:0.85em;line-height:1.9;">

- 速查: printf 与转换说明 → 任务 1: 打印对齐的成绩表

- 速查: 转义序列 → 任务 2: 用转义序列打印三行

- 速查: scanf 与输入缓冲区 → 任务 3: 遗留换行的坑

- 格式串中的普通字符 → 任务 4: 一次读入混合类型

- printf/scanf 混淆、getchar/putchar → 任务 5: 大小写转换

- 综合案例: 分数相加 · 课堂小测

</div>

---


<!-- slide data-notes="" -->


##### printf: 格式串 = 普通字符 + 转换说明

---

先看输出: printf 把值填进格式串的空位:

<style>.p3 p{margin:0.3rem 2rem}</style>

<div class="p3">

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;font-size:0.78em;line-height:1.55;">

==`printf`== 必须提供格式字符串, 后跟要插入到串中的值:

```C
printf(格式串, 表达式1, 表达式2, ...);
```

格式串 = ==普通字符== (原样打印) + ==转换说明== (以 ==`%`== 开头, 用对应的值替换)

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

宽度 / 精度 / 左对齐, 一个例子:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;font-size:0.8em;">

```C
printf("|%-8s|%10.1f|\n", "name", 85.5);
```

输出: `|name••••|••••••85.5|`

</div>

<div style="flex:1;font-size:0.85em;line-height:1.65;">

`%-8s`: 宽 8、左对齐

`%10.1f`: 宽 10、1 位小数、右对齐

</div>

</div>

<div style="height:10px;"></div>

<span class="yellow">:fa-weixin:</span> 编译器==不检查==转换说明与参数的数量、类型: 多了少了、或用 `%d` 打印 `double` (`%d` 从整数通道取到的是无关值), 输出都==无意义==.

</div>

---


<!-- slide data-notes="" -->


##### 转换说明速查表

---

<style>.qt table{margin:6px auto!important}.qt th,.qt td{font-size:18px!important;padding:1px 8px!important;line-height:1.25!important}</style>

<div style="font-size:0.72em;line-height:1.55;">

刚才的 `%-8s`、`%10.1f` 只是其中两例, 完整清单如下:

写法: ==`%[标志][宽度][.精度]X`==, 如 ==`%-8s`== (宽 8、左对齐)、==`%10.1f`== (宽 10、1 位小数); 标志、宽度、精度都可省略 (省略精度时句点一并去掉).

<div class="fullborder qt" style="font-size:0.82em;">

| 转换说明 | 用于 | 示例 |
| :-- | :-- | :-- |
| `%d` | `int` | `42` |
| `%f` | `float` / `double` (printf) | `3.140000` |
| `%lf` | `double` (仅 scanf) | 读入 `1.75` |
| `%c` | `char` | `A` |
| `%s` | 字符串 (`char []`) | `Hi` |
| `%o` | 八进制整数 | `12` (由 10 得到) |
| `%x` | 十六进制整数 | `ff` (由 255 得到) |
| `%e` | 指数格式 | `1.234500e+03` |
| `%%` | 百分号本身 | `100%` |

</div>

<div style="display:flex;gap:18px;align-items:stretch;font-size:0.86em;line-height:1.5;">

<div style="flex:1;border-left:3px solid #268bd2;padding-left:10px;">

==printf 与 scanf 的 double 差异==: printf 的 `%f` 可打印 `float`/`double` (float 自动提升); scanf 读 `double` 必须用 `%lf`, 读 `float` 才用 `%f`.

</div>

<div style="flex:1;border-left:3px solid #859900;padding-left:10px;">

==宽度不够自动加宽==: 宽度 m 是最小字段宽度, 值更宽时自动加宽、不截断; ==`-`== 标志表示左对齐 (`%4d`→`•123`, `%-4d`→`123•`).

</div>

<div style="flex:1;border-left:3px solid #b58900;padding-left:10px;">

==精度 p 随 X 变==: `%d` 的 p 是最少位数 (不足补 0, 默认 1); `%f`/`%e` 的 p 是小数位数 (默认 6, p 为 0 不显示小数点); `%g` 按大小自动选 `%e`/`%f`, p 是最大有效位数并去掉尾随零.

</div>

</div>

</div>

---


<!-- slide data-notes="" -->##### 任务 1: 打印对齐的成绩表
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 打印下面的表, 三列==对齐== (科目左对齐, 分数右对齐保留 1 位小数, 等级右对齐)

```text
科目        分数    等级
语文        85.5       A
数学        92.0       A
英语        78.2       B
```

==提示==: 数据列用 `%10.1f` (总宽 10, 1 位小数) 与 `%8c`; 中文表头==不要用 `%8s`==——`%s` 的宽度按==字节==算, 一个汉字 3 字节却只占 2 列, 直接用固定空格对齐表头

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
  printf("科目        分数    等级\n");   /* 中文表头用固定空格 */
  printf("%-8s%10.1f%8c\n", "语文", 85.5, 'A');
  printf("%-8s%10.1f%8c\n", "数学", 92.0, 'A');
  printf("%-8s%10.1f%8c\n", "英语", 78.2, 'B');
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- 格式: `%[标志][宽度][.精度]转换`——`%-8s` 左对齐, `%10.1f` 右对齐保留 1 位

- ==中文表头不要用 `%8s`==: `%s` 的宽度按==字节==算, 一个汉字 3 字节却只占 2 列; 表头用固定空格, 数据列仍用 `%10.1f`/`%8c`

- ==列对齐的前提==: 每一行同一个位置用==相同的显示宽度==

- 宽度不够会自动加宽 (不会截断数字); 字符串超宽则照原样输出

- 表格类输出是 `printf` 宽度修饰最常见的用途

</div>
</div>

对齐靠宽度; 字符串里还有看不见的字符——转义序列:

---


<!-- slide data-notes="" -->


##### 转义序列: 反斜杠引出特殊字符

---

==转义序列== 让字符串包含非打印 (控制) 字符或具有特殊含义的字符; 反斜杠 ==`\`== 是==转义引子==——它和后面的一个字符合成"一个字符" (如 `\n` 是一个字符, 不是 `\` 和 `n` 两个).

<div class="fullborder" style="font-size:0.8em;">

| 转义序列 | 含义 | 示例 |
| :-- | :-- | :-- |
| `\n` | 换行符 | 光标移到下一行开头 |
| `\t` | 水平制表符 | `printf("A\tB")` 两列对齐 |
| `\"` | 双引号 `"` | `printf("\"Hi\"")` → `"Hi"` |
| `\\` | 一个反斜杠 `\` | `printf("C:\\temp")` → `C:\temp` |
| `\a` | 警报 (铃声) | 响铃 |
| `\b` | 回退符 | 光标退回一格 |

</div>

<div style="font-size:0.8em;line-height:1.5;">

- 一个字符串可以包含任意数量的转义序列: `printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");`

- 要打印双引号必须写 `\"`; 要打印单个 `\` 必须写 `\\`, 否则它会和后一个字符组成别的转义序列.

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

输出会了, 反过来看输入——scanf 怎么读?

---


<!-- slide data-notes="" -->


##### scanf（一）: 按格式串顺序匹配, 别忘 &

---

<div style="display:flex;align-items:flex-start;gap:24px;" class="split-rule">

<div style="flex:1;font-size:0.85em;line-height:1.7;">

<div class="col-label">要点</div>


- `scanf` 按格式串==从左到右==依次匹配; 格式串通常只含转换说明

- 通常每个变量前要加 ==`&`== (取地址), 告诉 `scanf` 把值存到哪里

- ==返回值== = 成功读入的项数, 可用于检查输入是否完整

- 读 ==`double`== 必须用 ==`%lf`== (读 `float` 才用 `%f`)

</div>

<div style="flex:1.1;font-size:0.62em;">

<div class="col-label">代码</div>


一次读入两个 int、两个 double:

```C{.line-numbers}
int i, j;
double x, y;

scanf("%d%d%lf%lf", &i, &j, &x, &y);
```

样本输入: `1 -20 .3 -4.0e3`

```
i=1  j=-20  x=0.3  y=-4000.0
```

</div>

</div>

<span class="yellow">:fa-weixin:</span> `scanf` 不检查转换说明的数量和类型是否与变量匹配; 顺序错了, 读到的是==无意义的值==.

一次读多个值已经清楚; 连续多次 scanf 时, 数据从哪来?

---


<!-- slide data-notes="" -->


##### scanf（二）: 输入先进缓冲区, 再逐个消费

---

<div style="display:flex;align-items:flex-start;gap:24px;" class="split-rule">

<div style="flex:1.05;font-size:0.8em;line-height:1.65;">

<div class="col-label">要点</div>


- 输入先进入==缓冲区==; `scanf` 每次从上次读到的位置接着读, 多次调用共享同一条输入流

- 对每个转换说明, `scanf` 在缓冲区里找合适的数据, 必要时==跳过空白== (空格 / 制表 / 换行)

- 读整数时先找数字或正负号, 继续读数字, 直到遇到==非数字==; 这个字符被==放回==, 留给下一次读取

- 缓冲区没有数据时, `scanf` ==等待用户输入==——交互式程序"卡住"往往是在等你敲键盘; 数据不匹配时则立即返回

</div>

<div style="flex:1;font-size:0.66em;">

<div class="col-label">代码</div>


<div style="line-height:1.2;text-align:left;margin-left:2rem;">同一个 scanf 调用, 数据从缓冲区来:</div>

```C{.line-numbers}
int i, j; double x, y;
scanf("%d%d%lf%lf", &i, &j, &x, &y);
```

输入的数字可以在同一行, 也可以分布在多行:

```
••1
-20•••.3
•••-4.0e3
```

`1-20.3-4.0e3` 的处理:

```
%d  → i=1, j=-20      (放回 - 和 .)
%lf → x=0.3, y=-4000.0 (放回 - 和换行)
```

</div>

</div>

<span class="yellow">:fa-weixin:</span> `%d` / `%f` 读完后停在第一个不能构成数字的字符; 换行符因此常留在缓冲区里——下一页的 `%c` 会读到它.

---


<!-- slide data-notes="" -->


##### 遗留换行: %c 会读到上一次的回车

---

<div style="display:flex;align-items:flex-start;gap:20px;" class="split-rule">

<div style="flex:1.2;font-size:0.55em;">

<div class="col-label">代码</div>


<div style="line-height:1.2;text-align:left;margin-left:2rem;">先看两条 scanf 如何依次读取:</div>

```C{.line-numbers}
int a, b;
printf("请输入两个整数: ");
scanf("%d", &a);          /* 读走 10, 剩 " 20↵" */
printf("a = %d\n", a);
scanf("%d", &b);          /* 跳过空格, 接着读 20 */
printf("b = %d\n", b);
```

用户只输入一行 `10 20↵`:

```
请输入两个整数: 10 20↵
a = 10
b = 20
```

</div>

<div style="flex:1;font-size:0.8em;line-height:1.65;">

<div class="col-label">要点</div>


- 输入==先全部进入缓冲区==, 两条 `scanf` 依次"消费": 第一个拿走 `10`, 第二个接着拿走 `20`

- `scanf` 读走的数据==不会再次被读到==; 夹在中间的 `printf` 只打印已读到的值

- 若第一次只输入 `10↵` 就回车, 第二个 `scanf` 在缓冲区找不到整数, 程序==卡住==等待继续输入

- `%d` / `%f` 跳过空白, ==`%c` 不跳过==——它读到的可能就是上一次留下的换行

</div>

</div>

<div style="display:flex;align-items:flex-start;gap:20px;margin-top:4px;">

<div style="flex:1.1;font-size:0.6em;">

```C
int n; char ch;
scanf("%d", &n);
scanf("%c", &ch);     /* ch 读到 '\n', 不是新字符! */
scanf(" %c", &ch);    /* 空格: 跳过所有空白 */
```

</div>

<div style="flex:1;font-size:0.64em;line-height:1.5;">

==修复==: 在 `%c` 前加一个空格 (`" %c"`), 格式串里的空白会跳过所有空白字符.

`scanf` 与 `getchar()` 混用同理: `scanf` 结束后==换行符还留在输入流里==, 会被后面的 `getchar()` 当"第一个字符"吃掉; 先 `getchar()` 把换行吃掉再读, 也常用于读整行之前.

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

换行的坑搞清楚了; 格式串里的普通字符也有讲究:

---


<!-- slide data-notes="" -->##### 格式串的普通字符: 必须逐字匹配

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

混合读入没问题; 但 printf 和 scanf 长得像, 容易混:

---


<!-- slide data-notes="" -->


##### printf 与 scanf: 三个易混点

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

<div style="font-size:0.7em;line-height:1.3;text-align:left;margin-left:2rem;">除了格式化读写, 还可以逐个字符读写:</div>

---

<!-- slide data-notes="" -->


##### getchar / putchar: 每次读写一个字符

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


##### 综合案例: 分数相加

---

<style>.frac pre code{font-size:18px!important;line-height:1.2!important}</style>

格式串里的 `/` 需要原样匹配; 用它读两个分数并相加:

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="frac" style="flex:1.3;font-size:0.62em;">

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
