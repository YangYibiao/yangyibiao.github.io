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



<!-- slide data-notes="" -->


<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 选择语句

<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_



<!-- slide vertical=true data-notes="" -->


##### 提纲

---


逻辑表达式

`if` 语句

`switch` 语句

<!-- slide vertical=true data-notes="" -->



##### 选择语句

---

到目前为止, 我们已经讲完了返回语句和表达式语句. 

`C` 的其他大部分语句: 

- 选择语句: `if`和`switch`

- 循环语句: `while`, `do`和`for`

- 跳转语句: `break`, `continue`和`goto`(`return`也属于这一类)

- 其他语句: 复合语句 和 空语句(Null)



<!-- slide data-notes="" -->


##### 逻辑表达式

---

`C` 的一些语句需要测试一个表达式的值, 看它是真还是假

例如, 一个`if`语句可能需要测试表达式`i < j`真值则表示`i小于j`

在许多编程语言中, 诸如`i < j`之类的表达式会有一个特殊的 ==布尔== 或 ==逻辑== 类型

在 `C` 中, 如`i < j`的比较会产生一个整数: `0` (==假==)或 `1` (==真==)

```C
10 < 11
11 < 10
1 < 2.5
5.6 < 4
```



<!-- slide vertical=true data-notes="" -->


##### 关系运算符

---

`C` 的关系运算符: 

<div class="threelines column1-border-left-solid column1-border-right-solid column2-border-right-solid head-highlight-1 tr-hover">

| 符号 | 含义 |
| :-- | :-- |
| `<` | 小于 |
| `>` | 大于 |
| `<=`| 小于或等于 |
| `>=`| 大于或等于 |

</div>

这些运算符在表达式中使用时会产生 `0` (==假==)或 `1` (==真==)

关系运算符可用于比较整数和浮点数, 允许不同类型的混合运算



<!-- slide vertical=true data-notes="" -->


##### 关系运算符

---

关系运算符的优先级 ==低于== 算术运算符

```C
i + j < k – 1
``` 

表示

```C
(i + j) < (k - 1)
```

关系运算符是左结合的



<!-- slide vertical=true data-notes="" -->


##### 关系运算符

---

表达方式 `i < j < k` 是合法的, 但并不是测试 `j` 的大小是否在 `i` 和 `k` 之间

因为 `<` 运算符是`左结合的`, 所以这个表达式等价于
  
```C
(i < j) < k
```

- `i < j` 产生的 `1` 或 `0` 随后将与k进行比较

- 并非测试`j`是否位于`i`与`k`之间

我的批注 正确的表达式是 `i < j && j < k`



<!-- slide vertical=true data-notes="" -->


##### 判等运算符

---

C 提供了两个判等运算符: 

<div class="threelines column1-border-left-solid column1-border-right-solid column2-border-right-solid head-highlight-1 tr-hover">

| 符号  | 含义   |
| :--  | :--    |
| `==` | 等于   |
| `!=` | 不等于 |

</div>

判等运算符也是`左结合的`, 产生 `0` (==假==)或 `1` (==真==)作为其结果. 

判等运算符优先级 ==低于== 关系运算符, 因此表达式: 

`i < j == j < k`
等价于
`(i < j) == (j < k)`



<!-- slide vertical=true data-notes="" -->


##### 逻辑运算符

---

利用逻辑运算符, 可以从简单逻辑表达式构建复杂逻辑表达式: 

<div class="threelines column1-border-left-solid column1-border-right-solid column2-border-right-solid head-highlight-1 tr-hover">

| 符号 | 含义 |
| :-- | :-- |
| `!` | 逻辑非 |
| `&&` | 逻辑与 |
| `||` | 逻辑或 |

</div>

`!`运算符是一元的, 而`&&`和`||`是二元的

逻辑运算符产生 `0` 或 `1` 作为其结果

逻辑运算符将任何非零操作数视为真值, 零值操作数视为假值



<!-- slide vertical=true data-notes="" -->


##### 逻辑运算符

---

逻辑运算符的操作: 

- 如果 ==表达式== 的值为 `0`, 则 ==!表达式== 的值为`1`

- 如果 ==表达式1== 和 ==表达式2== 值都不为零, 则 ==表达式1 && 表达式2== 的值为 `1`

- 如果 ==表达式1== 或 ==表达式2== 中任意一个不为零, 则 ==表达式1 || 表达式2== 的值为 `1`

- 其他情况下, 这些运算符产生的值都为 `0`



<!-- slide vertical=true data-notes="" -->


##### 逻辑运算符

---

==&&== 和 ==||== 会进行 =="短路"== 计算: 先计算左操作数, 然后是右操作数

若表达式的值可 ==单独== 从左操作数推导出来, 则不计算右操作数

例子: `(i != 0) && (j / i > 0)`

- 先计算`(i != 0)` 如果`i`不等于 `0`, 则计算`(j / i > 0)`的值

- 若`i`为`0`, 则整个表达式必定为假, 因此无需计算`(j / i > 0)`

- 如果没有短路计算, 就会发生除零



<!-- slide vertical=true data-notes="" -->


##### 逻辑运算符

---

因为 ==&&== 和 ==||== 两种运算符的短路特性, 逻辑表达式中的副作用可能不会产生

例子: `i > 0 && ++j > 0`

- 如果`i > 0`为假, 则不会计算`++j > 0`, `j`也就不会自增

- 可以将条件表达式修改为 ==`++j > 0 && i > 0`==, 更好的方法是`j`先自增



<!-- slide vertical=true data-notes="" -->


##### 逻辑运算符

---

`!`运算符与一元加号和减号运算符具有相同的优先级

`&&`和`||`的优先级低于关系运算符和等式运算符

例子: `i < j && k == m`

表示: `(i < j) && (k == m)`

- `!`运算符是右结合的

- `&&`和`||`是左结合的



<!-- slide vertical=true data-notes="" -->


##### if语句

---

`if` 语句允许程序通过判定表达式的值是真还是假, 以便在两个选项之间进行选择

`if` 语句最简单的形式为:

==[if语句]== &emsp; `if (表达式) 语句`

当执行 `if` 语句时, 计算表达式; 如果其值为非零, 则执行语句, 例子: 

```C{.line-numbers}
if (line_num == MAX_LINES)
  line_num = 0;
```

我的批注 表达式两边的圆括号是必须的，它是`if`语句的组成部分



<!-- slide vertical=true data-notes="" -->


##### if语句

---

我的启示 将`==`(判等)和`=`(赋值)混淆是常见的 ==C== 语言编程错误

```C{.line-numbers}
if (i == 0) …  
/* 检查i是否等于0 */

if (i = 0) … 
/* 将0赋值给i, 然后检查结果是否为非零 */
```



<!-- slide vertical=true data-notes="" -->


##### if语句

---

通常, `if`语句中的表达式检查变量是否在某个值范围内

判定i是否满足 $0 \leq i < n$:

`if (0 <= i && i < n) …`

要判定相反的条件(`i`超出范围):

`if (i < 0 || i >= n) …`



<!-- slide vertical=true data-notes="" -->


##### 复合语句

---

在`if`语句模板中, 需注意statement(语句)是单数, 而不是复数: 

`if (表达式) 语句`

要使`if`语句控制两条或更多条语句, 要使用 ==复合语句==

==[复合语句]== &emsp; `{ 多条语句 }`

在一组语句周围放置大括号会强制编译器将其视为单个语句



<!-- slide vertical=true data-notes="" -->


##### 复合语句

---

例子: 

```C
{ line_num = 0; page_num++; }
```

复合语句通常放在多行中, 每行一条语句: 

```C
{
  line_num = 0;
  page_num++;
}
```

每个内部语句仍然以分号结尾, 但复合语句本身没有分号



<!-- slide vertical=true data-notes="" -->


##### 复合语句

---

if语句中使用的复合语句示例: 

```C
if (line_num == MAX_LINES) {
  line_num = 0;
  page_num++;
}
```

复合语句在循环和其他C语法要求单个语句的地方也很常见



<!-- slide vertical=true data-notes="" -->


##### else子句

---

`if`语句可能有`else`子句: 

`if (表达式) 语句 else 语句`

如果表达式的值为`0`, 则执行`else`后面的语句

例子: 

```C{.line-numbers}
if (i > j)
  max = i;
else
  max = j;
```



<!-- slide vertical=true data-notes="" -->


##### else子句

---

当`if`语句包含`else`子句时, `else`应该放在哪里？

许多 C 程序员将它与语句开头的`if`对齐

当内部语句很短, `if`和`else`可放在同一行: 

```C{.line-numbers}
if (i > j) max = i;
else max = j;
```



<!-- slide vertical=true data-notes="" -->


##### else子句

---

`if`语句嵌套在其他`if`语句中也很普遍: 

```C{.line-numbers}
if (i > j)
  if (i > k)
    max = i;
  else 
    max = k;
else
  if (j > k)
    max = j;
  else 
    max = k;
```

`else`与匹配的`if`对齐可以使嵌套层次更易辨别



<!-- slide vertical=true data-notes="" -->


##### else子句

---

为避免混淆, 最好添加大括号: 

```C{.line-numbers}
if (i > j) {
  if (i > k) 
    max = i;
  else 
    max = k;
} else {
  if (j > k) 
    max = j;
  else 
    max = k;
}
```



<!-- slide vertical=true data-notes="" -->


##### else子句

---

`if`语句中尽可能多地使用大括号: 

```C{.line-numbers}
if (i > j) {
  if (i > k) {
    max = i;
  } else {
    max = k;
  }
} else {
  if (j > k) {
    max = j;
  } else {
    max = k;
  }
}
```



<!-- slide vertical=true data-notes="" -->


##### else子句

---

使用大括号的优点(即使在不需要时): 

- 使程序更易于修改, 可以轻松地将更多语句添加到任何`if`或`else`子句中

- 避免使用`if`或`else`子句时忘记使用大括号而导致的错误



<!-- slide vertical=true data-notes="" -->


##### 级联式if语句

---

"级联" `if`语句通常是判定一系列条件的最佳方式, 一旦其中一个条件为真就停止

例子: 

```C{.line-numbers}
if (n < 0)
  printf("n is less than 0\n");
else
  if (n == 0)
    printf("n is equal to 0\n");
  else
    printf("n is greater than 0\n");
```



<!-- slide vertical=true data-notes="" -->


##### 级联式if语句

---

尽管第二个if语句嵌套在第一个中, 但 C 程序员通常不会对它进行缩进

相反, 他们将每个else与原始if对齐: 

```C{.line-numbers}
if (n < 0)
  printf("n is less than 0\n");
else if (n == 0)
  printf("n is equal to 0\n");
else
  printf("n is greater than 0\n"); 
```



<!-- slide vertical=true data-notes="" -->


##### 级联式if语句

---

这种布局避免了判定数量很多时过度缩进的问题: 

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



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算经纪人佣金

---

当通过经纪人出售或购买股票时, 经纪人的佣金通常取决于所交易股票的价值

假设经纪人收取下表中的金额: 

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

最低收费为 `$39`



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算经纪人佣金

---

*broker.c*程序要求用户输入交易金额, 然后显示佣金金额: 

Enter value of trade: <u>30000</u>
Commission: `$166.00`

该程序的核心是一个级联的`if`语句, 用于判定交易属于哪个范围



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算经纪人佣金

---

*broker.c*

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



<!-- slide vertical=true data-notes="" -->


##### "悬空else"的问题

---

我的启示 当 `if` 语句嵌套时, 千万当心出现"悬空else"问题

```C
if (y != 0)
  if (x != 0)
    result = x / y;
else
  printf("Error: y is equal to 0\n");
```

缩进暗示`else`子句属于外部if语句

然而, 根据C 语言的规则, `else`子句实际上属于尚未与`else`配对的最近的`if`语句



<!-- slide vertical=true data-notes="" -->


##### "悬空else"的问题

---

正确缩进的版本如下: 

```C{.line-numbers}
if (y != 0)
  if (x != 0)
    result = x / y;
  else
    printf("Error: y is equal to 0\n");
```



<!-- slide vertical=true data-notes="" -->


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

我的启示 `if`语句中使用大括号可以避免这一问题



<!-- slide vertical=true data-notes="" -->


##### 条件表达式

---

`C` 的条件运算符允许表达式根据条件的值产生两个值之一

条件运算符 由两个符号(`?`和`:`)组成, 它们必须一起使用: 

[条件表达式] &emsp; `表达式1 ? 表达式2 : 表达式3`

- 操作数可以是任何类型

- 结果表达式被称为条件表达式



<!-- slide vertical=true data-notes="" -->


##### 条件表达式

---

条件运算符需要三个操作数, 因此通常被称为三元运算符

条件表达式`表达式1 ? 表达式2 : 表达式3`读作`如果表达式1成立, 那么表达式2, 否则表达式3.`

表达式分阶段计算: 

- 首先计算`表达式1`, 如果它的值不为零, 则计算`表达式2`, 它的值是整个条件表达式的值

- 如果`表达式1`的值为零, 那么`表达式3`的值就是整个条件表达式的值



<!-- slide vertical=true data-notes="" -->


##### 条件表达式

---

例子: 

```C{.line-numbers}
int i, j, k;

i = 1;
j = 2;
k = i > j ? i : j;          /* k is now 2 */
k = (i >= 0 ? i : 0) + j;   /* k is now 3 */
```

括号是必需的, 因为条件运算符的优先级低于到目前为止讨论的其他运算符的优先级, 赋值运算符除外



<!-- slide vertical=true data-notes="" -->


##### 条件表达式

---

我的启示 条件表达式往往会使程序更短但更难理解, 因此最好谨慎使用它们

条件表达式常用于返回语句: 

```C
return i > j ? i : j;
```



<!-- slide vertical=true data-notes="" -->


##### 条件表达式

---

printf函数调用有时可以从条件表达式中受益, 我们可以将

```C{.line-numbers}
if (i > j)
  printf("%d\n", i);
else
  printf("%d\n", j);
```

简单地写成: 

```C
printf("%d\n", i > j ? i : j);
```

条件表达式在某些类型的宏定义中也很常见



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

多年来, `C` 语言缺乏合适的布尔类型, `C89` 标准中也没有定义

一种解决的方法是声明一个int变量, 然后将其赋值为 0 或 1: 

```C{.line-numbers}
int flag;
 
flag = 0;
…
flag = 1;
```

虽然这个方案有效, 但它对程序的可读性贡献不大



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

为了使程序更易于理解, C89的程序员用TRUE和FALSE等名称定义宏: 

```C{.line-numbers}
#define TRUE 1
#define FALSE 0
```

对标志flag的赋值现在看起来更加自然: 

```C{.line-numbers}
flag = FALSE;
…
flag = TRUE;
```



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

要判定标志flag是否为真, 我们可以写

```C
if (flag == TRUE) …
```

或者直接

```C
if (flag) …
```

后一种形式更简洁, 如果flag的值不是 0 或 1, 它也可以正常工作



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

要测试标志flag是否为假, 我们可以写

```C
if (flag == FALSE) …
```

或者

```C
if (!flag) …
```



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

将这个想法更进一步, 我们甚至可以定义一个可以用作类型的宏: 

`#define BOOL int`

声明布尔变量时, `BOOL`可以代替`int`: 

`BOOL flag;`

这样就很清楚看出flag不是一个普通的整数变量, 而是代表一个布尔变量



<!-- slide vertical=true data-notes="" -->


##### C89中的布尔值

---

`C99` 提供了`Bool`类型

可以通过这样写来声明布尔变量

`_Bool flag;`

`_Bool`是整数类型, 所以`_Bool`变量实际上只是变相的整数变量

然而, 与普通整数变量不同的是, `_Bool`变量只能分配 `0` 或 `1`

尝试将非零值存储到`_Bool`变量中会导致变量被赋值为 `1`: 

`flag = 5;   /* flag is assigned 1 */`



<!-- slide vertical=true data-notes="" -->


##### C99中的布尔值

---

对`_Bool`变量执行算术运算是合法的, 但不建议

打印`_Bool`变量也是合法的(显示 0 或 1)

当然, 可以在if语句中测试`_Bool`变量: 

```C
if (flag)   /* tests whether flag is 1 */
  …
```



<!-- slide vertical=true data-notes="" -->


##### C99中的布尔值

---

`C99` 的`<stdbool.h>`头文件可以更轻松地处理布尔值

它定义了一个宏`bool`, 它代表`_Bool`

如果包含`<stdbool.h>`, 我们可以写

`bool flag;   /* same as _Bool flag; */`

`<stdbool.h>`还提供了名为`true`和`false`的宏, 它们分别代表 `1` 和 `0`, 因此可以这样写: 

```C
flag = false;
…
flag = true;
```



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

级联if语句用于将表达式与一系列值进行比较: 

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



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

switch语句是另一种选择: 

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



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

`switch`语句可能比级联`if`语句更容易阅读

`switch`语句通常比`if`语句执行更快

`switch`语句最常见的形式: 

```C{.line-numbers}
switch (表达式) {
  case 常量表达式: 语句
  …
  case 常量表达式: 语句
  default: 语句
}
```



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

单词`switch`后面必须跟一个括号中的整数表达式——控制表达式

字符在 `C` 中被视为整数, 因此可以在`switch`语句中进行判定

但是, 浮点数和字符串不符合条件



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

每个`case`都以下面的标签形式开头

`case 常量表达式:`

常量表达式与普通表达式很相似, 只是它不能包含变量或函数调用

- 5是一个常数表达式, 5 + 10也是一个常数表达式, 但n + 10不是常量表达式(除非n是表示常量的宏)

case 标签中的常量表达式必须计算为整数(可接受字符)



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

在每个案例标签之后是任意数量的语句

语句周围不需要大括号

每组中的最后一条语句通常是break



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

不允许有重复的case标签

案例的顺序无关紧要, 默认case不需要排在最后

一组语句之前可以有几个 case 标签: 

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



<!-- slide vertical=true data-notes="" -->


##### switch语句

---

为了节省空间, 可以将多个case标签放在同一行: 

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

如果缺少`default`, 且控制表达式的值与任何case都不匹配, 则控制传递到switch之后的下一条语句



<!-- slide vertical=true data-notes="" -->


##### break语句的作用

---

执行`break`语句会导致程序从`switch`语句中 ==中断==

在 `switch` 之后的下一条语句继续执行

`switch`语句实际上是 ==计算跳转== 的一种形式

- 计算控制表达式时, 控制跳转到与switch表达式的值匹配的 case 标签

- case 标签是一个标记, 表示switch中的一个位置



<!-- slide vertical=true data-notes="" -->


##### break语句的作用

---

没有 `break`(或其他跳转语句), 控制将流入下一个 `case`

例子: 
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

如果`grade`的值为 `3`, 则打印的消息为
`GoodAveragePoorFailingIllegal grade`



<!-- slide vertical=true data-notes="" -->


##### break语句的作用

---

省略`break`有时是故意的, 但通常是因为疏忽

明确指出故意省略`break`语句是个好的习惯: 

```C{.line-numbers}
switch (grade) {
  case 4: case 3: case 2: case 1:
    num_passing++;
    /* FALL THROUGH */
  case 0: total_grades++;
    break;
}
```

尽管最后一个 `case` 永远不需要`break`语句, 但包含一个`break`可以避免在将来添加 `case` 时出错



<!-- slide vertical=true data-notes="" -->


##### 程序: 以法律形式打印日期

---

合同和其他法律文件通常按以下方式注明日期: 

`Dated this __________ day of __________ , 20__ .`

*date.c*程序将以这种形式显示日期: 

Enter date (mm/dd/yy): <u>7/19/14</u>
Dated this 19th day of July, 2014.

该程序使用`switch`语句将`"th"`(或`"st"`或`"nd"`或`"rd"`)添加到日期, 并将月份打印为单词而不是数字



<!-- slide vertical=true data-notes="" -->


##### 程序: 以法律形式打印日期

---

*date.c*

```C{.line-numbers}
/* Prints a date in legal form */

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
    case 1:  printf("January");   break;
    case 2:  printf("February");  break;
    case 3:  printf("March");     break;
    case 4:  printf("April");     break;
    case 5:  printf("May");       break;
    case 6:  printf("June");      break;
    case 7:  printf("July");      break;
    case 8:  printf("August");    break;
    case 9:  printf("September"); break;
    case 10: printf("October");   break;
    case 11: printf("November");  break;
    case 12: printf("December");  break;
  }
 
  printf(", 20%.2d.\n", year);
  return 0;
}
```