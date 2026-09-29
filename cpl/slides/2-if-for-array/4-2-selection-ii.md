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

## 选择结构 (下)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 级联式 if 语句

- 悬空 else 与条件表达式

- switch 语句与 break

- 布尔值与闰年化简

- 案例: 经纪人佣金与法律日期

---


<!-- slide data-notes="" -->


##### 级联式if语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C{.line-numbers}
if (n < 0)
  printf("n is less than 0\n");
else
  if (n == 0)
    printf("n is equal to 0\n");
  else
    printf("n is greater than 0\n");
```

</div>

<div style="flex:1;">

"级联" `if` 语句适合==逐级判定==: 一旦某个条件为真就停止, 后面的不再判断

例子: 判断 n 与 0 的关系 (负/零/正)——如左



</div>

</div>

<!-- slide data-notes="" -->


##### 级联式if语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.58em;">

==具体例子== (判断 n 与 0 的关系): 

```C{.line-numbers}
if (n < 0)
  printf("n is less than 0\n");
else if (n == 0)
  printf("n is equal to 0\n");
else
  printf("n is greater than 0\n"); 
```

</div>

<div style="flex:0.9;font-size:0.58em;">

==通用形式==: 

```C
if (表达式)
  语句
else if (表达式)
  语句
…
else if (表达式)
  语句
else
  语句
```

</div>

</div>

- 其实 `else if` 是嵌套: 第二个 `if` 嵌在第一个的 `else` 里

- 惯例: ==不缩进==, 每个 `else` 与第一个 `if` 对齐, 写成 `else if` 链

- 好处: 判定很多时避免==层层缩进==; 一旦某个条件为真, 后面的分支不再判断

<!-- slide data-notes="" -->


##### 程序: 计算经纪人佣金

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.6em;">

股票交易的佣金取决于交易金额, 某经纪人按下表收费: 

<div class="threelines column1-border-left-solid column2-border-right-solid column1-border-right-solid head-highlight-1 tr-hover">

| 交易规模            | 佣金率        |
| :--                | :--          |
| 低于`$2,500`        | `$30 + 1.7%` |
| `$2,500–$6,250`    | `$56 + 0.66%`|
| `$6,250–$20,000`   | `$76 + 0.34%`|
| `$20,000–$50,000`  | `$100 + 0.22%`|
| `$50,000–$500,000` | `$155 + 0.11%`|
| 超过`$500,000`      | `$255 + 0.09%`|

</div>

- 另有==最低收费==: 佣金不足 `$39` 按 `$39` 收

</div>

<div style="flex:1;">

`broker.c` 输入交易金额, 输出佣金: 

```
Enter value of trade: 30000
Commission: $166.00
```

- 核心是一个==级联 if==, 判定交易落在哪个区间

- 两个要点: 区间按大小==从低到高排==, 只需 `<` 不用 `&&`; 最后再==用 if 兜住最低收费==

</div>

</div>

<!-- slide data-notes="" -->


##### 程序: 计算经纪人佣金

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
/* Calculates a broker's commission */
#include <stdio.h>
int main(void)
{
  float commission, value;
  printf("Enter value of trade: ");
  scanf("%f", &value);
  if (value < 2500.00f)
    commission = 30.00f + .017f * value;
  else if (value < 6250.00f)
    commission = 56.00f + .0066f * value;
  else if (value < 20000.00f)
    commission = 76.00f + .0034f * value;
  else if (value < 50000.00f)
    commission = 100.00f + .0022f * value;
  else if (value < 500000.00f)
    commission = 155.00f + .0011f * value;
  else
    commission = 255.00f + .0009f * value;
  if (commission < 39.00f)
    commission = 39.00f;
  printf("Commission: $%.2f\n", commission);
  return 0;
}
```

</div>

<div style="flex:1;">

- 六个区间 → 六个分支: 从低到高, 每个条件==只写上限== (`value < 2500.00f` …)

- 佣金不足 `$39` 时, 最后一个 `if` 把佣金==兜底==到 `$39`

- 对照左栏: 每个 `else if` 对应表里一行

</div>

</div>

<!-- slide data-notes="" -->


##### "悬空else"的问题

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;font-size:0.55em;">

==缩进暗示的版本== (程序员想配外层): 

```C
if (y != 0)
  if (x != 0)
    result = x / y;
else
  printf("Error: y is equal to 0\n");
```

</div>

<div style="flex:1;font-size:0.55em;">

==C 的实际配对== (else 属于最近的 if): 

```C{.line-numbers}
if (y != 0)
  if (x != 0)
    result = x / y;
  else
    printf("Error: y is equal to 0\n");
```

</div>

</div>

- C 的规则: ==else 属于尚未配对的最近一个 if==——缩进骗不了编译器

- 后果: `y` 为 0 时反而==静默跳过== (不报错); `x` 为 0 时却误报 "y is equal to 0"

- 下一页看大括号修复版

<!-- slide data-notes="" -->


##### "悬空else"的问题

---

为了使`else`子句成为外部`if`语句的一部分, 可以将内部`if`语句用大括号括起来: 

```C
if (y != 0) {
  if (x != 0)
    result = x / y;
} else
  printf("Error: y is equal to 0\n");
```

<span class="blue">:fa-weixin:</span> `if`语句中使用大括号可以避免这一问题

---


<!-- slide data-notes="" -->


##### 条件表达式

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

==条件表达式== 根据条件的值产生==两个值之一==

形式: `表达式1 ? 表达式2 : 表达式3`

```C{.line-numbers}
/* 求绝对值 */
x = (n >= 0) ? n : -n;
```

读作: "如果表达式1成立, 那么表达式2, 否则表达式3"

</div>

<div style="flex:1;">

- 两个符号 (`?` 和 `:`) ==必须一起使用==; 需要三个操作数, 所以也叫==三元运算符==

- 操作数可以是任何类型

- ==分阶段计算==: 先算表达式1; 非零 → 算表达式2, 其值即整个表达式的值; 为零 → 算表达式3

</div>

</div>

<!-- slide data-notes="" -->


##### 条件表达式

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C{.line-numbers}
int i, j, k;

i = 1;
j = 2;
k = i > j ? i : j;          /* k is now 2 */
k = (i >= 0 ? i : 0) + j;   /* k is now 3 */

printf("%d\n", i > j ? i : j);   /* prints 2 */
```

</div>

<div style="flex:1;">

例子:

括号是必需的, 因为条件运算符的优先级低于到目前为止讨论的其他运算符的优先级, 赋值运算符除外

<span class="blue">:fa-weixin:</span> 条件表达式往往会使程序更短但更难理解, 因此最好谨慎使用它们

条件表达式常用于返回语句: `return i > j ? i : j;`

printf 的实参也可以直接写条件表达式 (如左最后一行)



</div>

</div>

<!-- slide data-notes="" -->


##### switch语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;font-size:0.5em;">

==级联 if 版==: 

```C{.line-numbers}
if (grade == 4)
  printf("Excellent");
else if (grade == 3)
  printf("Good");
else if (grade == 2)
  printf("Average");
else if (grade == 1)
  printf("Poor");
else if (grade == 0)
  printf("Failing");
else
  printf("Illegal grade"); 
```

</div>

<div style="flex:1;font-size:0.5em;">

==switch 版==: 

```C{.line-numbers}
switch (grade) {
  case 4:  printf("Excellent");
           break;
  case 3:  printf("Good");
           break;
  case 2:  printf("Average");
           break;
  case 1:  printf("Poor");
           break;
  case 0:  printf("Failing");
           break;
  default: printf("Illegal grade");
           break;
}
```

</div>

<div style="flex:1;">

- 级联 if 适合==区间判定==; 与一系列==离散值==比较时, switch 更清晰

- 同一个 `grade` 要写六遍 `==` vs 一个 `switch (grade)`

- 每个分支末尾的 `break` 后面细讲

</div>

</div>

<!-- slide data-notes="" -->


##### switch语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C{.line-numbers}
switch (表达式) {
  case 常量表达式: 语句
  …
  case 常量表达式: 语句
  default: 语句
}
```

</div>

<div style="flex:1;">

`switch` 比级联 `if` 更易读、通常更快; 最常见的形式:

单词`switch`后面必须跟一个括号中的==整数表达式==——控制表达式; 字符在 `C` 中被视为整数, 因此可以在`switch`语句中进行判定; 但是, 浮点数和字符串不符合条件

- 每个`case`都以下面的标签形式开头: `case 常量表达式:`

- 常量表达式不能包含变量或函数调用: `5`、`5 + 10`是常量表达式, `n + 10`不是(除非n是表示常量的宏)

</div>

</div>

<!-- slide data-notes="" -->


##### switch语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
switch (grade) {
  case 4:
  case 3:
  case 2:
  case 1:  printf("Passing");
           break;
  case 0:  printf("Failing");
           break;
  default: printf("Illegal grade");
           break;
}
```

</div>

<div style="flex:1;">

在每个案例标签之后是任意数量的语句, 语句周围不需要大括号; 每组中的最后一条语句通常是break

- 不允许有重复的case标签

- 案例的顺序无关紧要, 默认case不需要排在最后

一组语句之前可以有几个 case 标签:



</div>

</div>

<!-- slide data-notes="" -->


##### switch语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

为了节省空间, 可以将多个case标签放在同一行

如果缺少`default`, 且控制表达式的值与任何case都不匹配, 则控制传递到switch之后的下一条语句

</div>

<div style="flex:1.15;font-size:0.72em;">

```C{.line-numbers}
switch (grade) {
  case 4: case 3: case 2: case 1:
    printf("Passing");
    break;
  case 0: 
    printf("Failing");
    break;
  default: 
    printf("Illegal grade");
    break;
}
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### break语句的作用

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.6em;">

```C{.line-numbers}
switch (grade) {
  case 4:  printf("Excellent");
  case 3:  printf("Good");
  case 2:  printf("Average");
  case 1:  printf("Poor");
  case 0:  printf("Failing");
  default: printf("Illegal grade");
}
```

</div>

<div style="flex:1;">

执行`break`语句会导致程序从`switch`语句中 ==中断==, 在 `switch` 之后的下一条语句继续执行

`switch`语句实际上是 ==计算跳转== 的一种形式

- 计算控制表达式时, 控制跳转到与switch表达式的值匹配的 case 标签

- case 标签是一个标记, 表示switch中的一个位置

没有 `break`(或其他跳转语句), 控制将流入下一个 `case`:

如果`grade`的值为 `3`, 则打印的消息为 `GoodAveragePoorFailingIllegal grade`

</div>

</div>

<!-- slide data-notes="" -->


##### break语句的作用

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

省略`break`有时是故意的, 但通常是因为疏忽

明确指出故意省略`break`语句是个好的习惯

尽管最后一个 `case` 永远不需要`break`语句, 但包含一个`break`可以避免在将来添加 `case` 时出错

</div>

<div style="flex:1.15;font-size:0.72em;">

```C{.line-numbers}
switch (grade) {
  case 4: case 3: case 2: case 1:
    num_passing++;
    /* FALL THROUGH */
  case 0: total_grades++;
    break;
}
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### 程序: 以法律形式打印日期

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.5em;">

```C{.line-numbers}
#include <stdio.h>
int main(void)
{
  int month, day, year;
  printf("Enter date (mm/dd/yy): ");
  scanf("%d /%d /%d", &month, &day, &year);
  printf("Dated this %d", day);
  switch (day) {
    case 1: case 21: case 31:
      printf("st"); break;
    case 2: case 22:
      printf("nd"); break;
    case 3: case 23:
      printf("rd"); break;
    default: printf("th"); break;
  }
  printf(" day of ");
  switch (month) {
  case 1:  printf("January");   break;  case 2:  printf("February");  break;
  case 3:  printf("March");     break;  case 4:  printf("April");     break;
  case 5:  printf("May");       break;  case 6:  printf("June");      break;
  case 7:  printf("July");      break;  case 8:  printf("August");    break;
  case 9:  printf("September"); break;  case 10: printf("October");   break;
  case 11: printf("November");  break;  case 12: printf("December");  break;
  }
  printf(", 20%.2d.\n", year);
  return 0;
}
```

</div>

<div style="flex:1;">

合同和其他法律文件通常按以下方式注明日期: 

`Dated this __________ day of __________ , 20__ .`

`date.c`程序将以这种形式显示日期: 

Enter date (mm/dd/yy): <u>7/19/14</u>
Dated this 19th day of July, 2014.

该程序使用`switch`语句将`"th"`(或`"st"`或`"nd"`或`"rd"`)添加到日期, 并将月份打印为单词而不是数字



</div>

</div>

<!-- slide data-notes="" -->


##### 演示: 闰年判断的化简

---

==现场演示==: 把上一课的闰年嵌套版==化简==

用 ==`&&`== 和 ==`||`== 把三条规则合并成一个布尔表达式: "能被 4 整除且不能被 100 整除, 或能被 400 整除"

---


<!-- slide data-notes="" -->


##### 演示: 闰年判断的化简 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.65em;">

```C
#include <stdio.h>

int main(void) {
    int year = 0;
    scanf("%d", &year);

    int leap = 0; // boolean; indicator; flag
    // &&: and (&); ||: or (|); !: not
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (leap) {
      printf("%d is a leap year\n", year);
    } else {
      printf("%d is a common year\n", year);
    }
    return 0;
}
```

</div>

<div style="flex:1;">

==现场演示==

用逻辑运算化简级联 if (leap.c):

<span class="blue">:fa-lightbulb-o:</span> 级联 if → 条件合并 → 布尔表达式直接赋值, 三种写法功能相同; 测试 2024/1900/2000 与嵌套版一致

</div>

</div>

<!-- slide data-notes="" -->

##### 布尔值 (C99)

---

`C89` 没有布尔类型, 我们一直用 `int` 变量当标志 (比如上一页的 `leap`)

`C99` 提供了真正的布尔类型: `_Bool` + 头文件 `<stdbool.h>` 的 `bool / true / false`

```C
#include <stdbool.h>

bool leap = false;
…
leap = true;
if (leap) …      /* 直接测试 */
if (!leap) …     /* 测试是否为假 */
```

- `bool` 变量只能存 `0` 或 `1`: `flag = 5;` 会变成 `1`

- 建议: 新代码用 `<stdbool.h>` 的 `bool`——但==不强制==, `int` 标志照旧能用 (本课作业两种都行)

---
<!-- slide data-notes="" -->


##### 课堂小测

---

1. 级联式 if 语句适合什么场景？它和嵌套 if 的书写区别是什么？

2. 条件表达式 `i > j ? i : j` 的值是什么？可以嵌套使用吗？

3. switch 语句中如果漏写 break 会发生什么？多个 case 共用一段代码怎么写？

4. 悬空 else 问题中，else 实际和哪个 if 配对？如何避免歧义？



<!-- slide data-notes="" -->


#####

---

<div class="top-2">
  <img src="../0-intro/figs/see-you.png" width=500px>
</div>

---


