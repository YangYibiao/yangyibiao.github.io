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
@import "../js/anychart/venn-entropy.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 格式化输入/输出

<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_



<!-- slide vertical=true data-notes="" -->


##### printf函数

---

- printf函数

- scanf函数



<!-- slide vertical=true data-notes="" -->


##### printf函数

---

==`printf`== 函数必须提供格式字符串, 后跟打印期间要插入到串中的任何值: 

```C
printf(字符串, 表达式1, 表达式2, ...);
```

格式字符串可以包含普通字符和转换说明, 以 ==`%`== 字符开头

==转换说明== 是一个占位符, 表示要在打印期间填充的值

- ==`%d`== 用于 ==`int`== 值

- ==`%f`== 用于 ==`float`== 值



<!-- slide data-notes="" -->


##### printf函数

---

格式字符串: 

- ==普通字符== 按出现在字符串中的方式打印

- ==转换说明== 则需用待显示的值来替换填充

```C{.line-numbers}
int i, j;
float x, y;
 
i = 10;
j = 20;
x = 43.2892f;
y = 5527.0f;
 
printf("i = %d, j = %d, x = %f, y = %f\n", i, j, x, y);

输出: 
i = 10, j = 20, x = 43.289200, y = 5527.000000
```



<!-- slide data-notes="" -->


##### printf函数

---

编译器不会检查格式字符串中转换说明数量与输出项数量是否匹配

- 转换说明过多: 

```C
printf("%d %d\n", i); /*** WRONG ***/
```

- 转换说明太少: 

```C
printf("%d\n", i, j); /*** WRONG ***/
```



<!-- slide data-notes="" -->


##### printf函数

---

- 编译器不会去检查转换说明是否合适

- 如果程序员使用了不正确的转换说明, 程序将产生无意义的输出

```C{.line-numbers}
int i;
float x;
printf("%f %d\n", i, x); /*** WRONG ***/
```



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



<!-- slide data-notes="" -->


##### 转换说明

---

最小字段宽度 ==m== 指定要打印的最小字符数

- 如果要打印的值需要少于 ==m== 个字符, 则在字段内右对齐

转换说明 ==`%4d`== 会将数字 ==`123`== 显示为 ==`•123`==(==`•`== 表示空格字符)

- 如果要打印的值需要超过 ==m== 个字符, 则字段宽度会自动扩展为所需的大小, 若 ==m== 前面加上减号会导致左对齐

转换说明 ==`%-4d`== 会将数字 ==`123`== 显示为 ==`123•`==



<!-- slide data-notes="" -->


##### 转换说明

---

精度 ==p== 的含义取决于转换说明符 ==X== 的选择

- 结合 ==%d== 说明符使用, ==%m.pX== 中的 ==p== 表示要显示的最小位数(如需要, 将在数字的开头添加额外的零)

- 如果 ==p== 省略, 则默认它的值为 ==1==



<!-- slide data-notes="" -->


##### 转换说明

---

浮点数的转换说明: 

- ==`%e`== — 指数格式: ==p== 表示小数点后应该出现多少位(默认为 ==6==); 如果 ==p== 为 ==0==, 则不显示小数点

- ==`%f`== — *固定十进制*格式:  ==p== 与 ==e== 说明符的含义相同

- ==`%g`== — 指数格式或固定十进制格式, 取决于数字的大小; ==p== 表示要显示的最大有效位数; ==%g== 不会显示尾随零. 如果在小数点后没有数字, 则 ==%g== 不显示小数点



<!-- slide data-notes="" -->


##### 程序: 使用printf格式化数字

---

*tprintf.c*程序使用 ==printf== 以各种格式显示整数和浮点数

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

Output:
|40|•••40|40•••|••040|
|•••839.210|•8.392e+02|839.21••••|
```



<!-- slide data-notes="" -->


##### 转义序列

---

形如 ==`\n`== 的代码称为 ==转义序列==

==转义序列==: 使字符串包含非打印(控制)字符和具有特殊含义的字符(如 ==`"`==)

转义序列的部分列表: 

<div class="fullborder">

| 警报(铃声) | \\a |
| :--       | :-- |
| 回退符     | \\b |
| 换行符     | \\n |
| 水平制表符  | \\t |

</div>



<!-- slide data-notes="" -->


##### 转义序列

---

- 一个字符串可以包含任意数量的转义序列: 

```C
printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
```

- 执行此语句会打印一个两行标题: 

```
Item    Unit    Purchase
        Price   Date
```



<!-- slide data-notes="" -->


##### 转义序列

---

另一常见的转义序列是 ==`\"`==, 代表 ==`"`== 字符: 

```C
printf("\"Hello!\""); /* prints "Hello!" */
```

要打印单个 ==`\`== 字符, 在字符串中放置两个 ==`\`==: 

```C
printf("\\"); /* prints one \ character */
```



<!-- slide data-notes="" -->


##### scanf函数

---

==`scanf`== 根据指定格式读取输入

==`scanf`== 格式字符串可以包含 ==普通字符== 和 ==转换说明==

==`scanf`== 接受的 ==转换说明== 与 ==`printf`== 基本相同



<!-- slide data-notes="" -->


##### scanf函数

---

我的批注 在多数情况下, ==`scanf`== 格式字符串只包含转换说明: 

```C{.line-numbers}
int i, j;
float x, y;

scanf("%d%d%f%f", &i, &j, &x, &y);
```

样本输入: 

`1 -20 .3 -4.0e3`

==`scanf`== 将变量 `i`、`j`、`x`和`y`赋值为 `1`、`–20`、`0.3` 和 `–4000.0`



<!-- slide data-notes="" -->


##### scanf函数

---

使用 ==`scanf`== 时, 程序员须自己检查: 

- ==转换说明== 的数量与 ==输入变量== 的数量是否相同

- 确保各个转换说明 ==适用于== 相应变量

==`&`== 符号通常需要用在 ==`scanf`== 调用中的每个变量之前

==`&`== 通常(但不总是)是必需的, 在读取输入至变量时需记住使用它



<!-- slide data-notes="" -->


##### scanf工作原理

---

- ==`scanf`== 尝试将输入字符组与格式字符串中的转换说明进行匹配

- 对每个转换说明, ==`scanf`== 尝试在输入数据中寻找适当类型数据, 必要时跳过空格

- ==`scanf`== 然后读取该数据, 当它到达不属于该数据类型的字符时停止

- 如果数据被成功读取, ==`scanf`== 将继续处理格式字符串的其余部分

- 如果数据读取不成功, ==`scanf`== 立即返回



<!-- slide data-notes="" -->


##### scanf工作原理

---

- ==`scanf`== 搜索数字时会忽略空白字符(空格、水平和垂直制表符、换页符和换行符)

- 读取四个数字的 ==`scanf`== 调用: 

```C
scanf("%d%d%f%f", &i, &j, &x, &y);
```

- 输入的数字可以在一行上, 也可以分布在多行上: 

```
••1
-20•••.3
•••-4.0e3
```



<!-- slide data-notes="" -->


##### scanf工作原理

---

```C
scanf("%d%d%f%f", &i, &j, &x, &y);

样本输入: 
••1
-20•••.3
•••-4.0e3
```

==`scanf`== 看到一个字符流(`¤`代表换行符): 

- `••1¤-20•••.3¤•••-4.0e3¤`

- ssrsrrrsssrrssssrrrrrr(`s` = 跳过;  `r` = 读取)



<!-- slide data-notes="" -->


##### scanf工作原理

---

我的启示 ==scanf== ==偷看== 当前的下一个字符, 若不符合要求就不读进它, 留到下次调用scanf时继续读取字符流中数据时检查是否符合要求，如果字符流中没有可用的数据就会等待用户输入



<!-- slide data-notes="" -->


##### scanf工作原理

---

- 当被要求读取整数时, ==`scanf`== 首先从输入搜索一个数字、一个加号或一个减号, 然后继续读取数字, 直到遇到nondigit

- 当被要求读取浮点数时, scanf查找 `+`或`-`(可选), 后跟 数字(可能包含小数点), 后跟指数(可选), 指数由字母`e`(或`E`)、一个`+`或`-`符号(可选) 和 一个或多个数字组成

我的批注 ==`%e`==、==`%f`== 和 ==`%g`== 与 ==`scanf`== 一起使用时可互换



<!-- slide data-notes="" -->


##### scanf工作原理

---

我的启示 当 ==`scanf`== 遇到不能成为当前变量一部分的字符时, 会 ==*放回*== 该字符以在扫描下一个 ==输入变量== 或在下一次 ==`scanf`== 调用时再读取



<!-- slide data-notes="" -->


##### scanf工作原理

---

样本输入: 

`1-20.3-4.0e3¤`

==`scanf`== 的调用与之前一致

```C
scanf("%d%d%f%f", &i, &j, &x, &y);
```

对应的 ==`scanf`== 处理该输入的步骤: 

- `%d` 将`1`存储到i中并将`-`字符放回去

- `%d` 将`–20`存储到j中并将`.`字符放回去

- `%f` 将`0.3`存储到x并放回`-`字符

- `%f` 将`–4.0×103`存储到y中并放回换行符



<!-- slide data-notes="" -->


##### 格式字符串中的普通字符

---

- 当在格式字符串中遇到一个或多个空白字符时, ==`scanf`== 从输入中读取空白字符, 直到它遇到一个非空白字符(即*放回*)

- 当它在格式字符串中遇到非空白字符时, ==`scanf`== 将其与下一个输入字符进行比较

- 如果匹配, 则 ==`scanf`== 丢弃输入字符并继续处理格式字符串

- 若不匹配, 则 ==`scanf`== 会将有问题的字符放回输入中, 然后中止



<!-- slide data-notes="" -->


##### 格式字符串中的普通字符

---

例子: 

- 如果格式字符串是 ==`"%d/%d"`== 并且输入是 ==`•5/•96`==, ==`scanf`== 成功

- 如果输入 ==`•5•/•96`==, 则 ==`scanf`== 失败, 因为格式字符串中的 ==`/`== 与输入中的空格不匹配

我的批注 要在第一个数字后允许空格, 需改用格式字符串 ==`"%d /%d"`==



<!-- slide data-notes="" -->


##### printf与scanf混淆

---

==`scanf`== 和 ==`printf`== 的调用看起来相似, 但两者之间存在显著差异

一个常见的错误是在`printf`调用中将`&`放在变量前面: 

```C
printf("%d %d\n", &i, &j);  /*** WRONG ***/
```



<!-- slide data-notes="" -->


##### printf与scanf混淆

---

我的批注 错误地假设 ==`scanf`== 格式字符串应该类似于 ==`printf`== 格式字符串是另一个常见错误

考虑以下 ==`scanf`== 调用: 

```C
scanf("%d, %d", &i, &j);
```

- ==`scanf`== 将首先在输入中查找一个整数, 并将其存储在变量 ==`i`== 中

- `scanf`将尝试将 ==`逗号`== 与 `下一个输入字符` 匹配

- 如果下一个输入字符是空格, 而不是逗号, 则scanf将终止而不读取j的值



<!-- slide data-notes="" -->


##### printf与scanf混淆

---

我的批注 多数情况下, 一定不要在 ==`scanf`== 格式化字符串的末尾放置换行符

对于 ==`scanf`==, 格式字符串中的 ==`换行符`== 相当于一个空格: 

- 导致 ==`scanf`== 前进到下一个非空白字符

- 如果格式化字符串是 ==`%d\n`==, ==`scanf`== 将跳过空格, 读取一个整数, 然后跳到下一个非空格字符

- 这种格式字符串会导致交互式程序 ==`挂起`== 直到用户输入下一个非空格字符为止



<!-- slide data-notes="" -->


##### 程序: 分数相加

---

*addfrac.c* 程序提示用户输入两个分数, 然后计算和打印它们的和

示例程序输出: 

Enter first fraction: <u>5/6</u>
Enter second fraction: <u>3/4</u>
The sum is 38/24



<!-- slide data-notes="" -->


##### 程序: 添加分数

---

*addfrac.c*

```C{.line-numbers}
/* Adds two fractions */
 
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
  printf("The sum is %d/%d\n",result_num, result_denom)

  return 0;
}
```