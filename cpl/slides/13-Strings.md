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

# C语言程序设计基础

<hr class="width50 center">

## 字符串


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- <a href="#/strliteralsr">字符串字面量</a>

- 字符串变量

- 字符串的读和写

- 访问字符串中的字符

- 使用C语言的字符串库

- 字符串惯用法

- 字符串数组

<!-- slide vertical=true data-notes="" -->



##### 引言

---

本章涵盖**字符串常量**（在 C 标准中称为字符串字面量）和**字符串变量**。

字符串是字符数组，用特殊字符（空字符）标记结束。

C 库提供了一组用于处理字符串的函数。

<!-- slide vertical=true data-notes="" -->



##### 字符串字面量

---

字符串字面量是用双引号括起来的字符序列：
`"When you come to a fork in the road, take it."`

字符串字面量可能包含转义序列。

转义字符经常出现在printf和scanf格式字符串中。

例如，字符串
`"Candy\nIs dandy\nBut liquor\nIs quicker.\n  --Ogden Nash\n"`

每个\n字符使光标移到下一行：
```
Candy
Is dandy
But liquor
Is quicker.
	--Ogden Nash
```

<!-- slide id="strliteralsr" vertical=true data-notes="" -->



##### 字符串字面量

---

反斜杠字符( \ )可用于将字符串字面量从一行延续到下一行：
```C
printf("When you come to a fork in the road, take it.  \
--Yogi Berra");
```

通常， \字符可用于将程序的两行或多行连接成一行。

<!-- slide vertical=true data-notes="" -->



##### 字符串字面量

---

有一种更好的方法来处理长字符串字面量。

当两个或多个字符串字面量相邻时，编译器会将它们连接成一个字符串。

此规则允许我们将字符串字面量拆分为两行或多行：
```C
printf("When you come to a fork in the road, take it. "
	       "--Yogi Berra");
```

<!-- slide vertical=true data-notes="" -->



##### 如何存储字符串字面量

---

当 C 编译器在程序中遇到长度为n的字符串字面量时，它会为该字符串分配n + 1 个字节的内存。

这块内存空间将用来存储字符串中的字符，以及一个额外的字符——null 字符——标记字符串的结尾。

空字符是所有位都为0的字节，因此它用转义序列\0表示。

<!-- slide vertical=true data-notes="" -->



##### 如何存储字符串字面量

---

字符串字面量“abc”存储为4个字符的数组：
<div class="top-2">
    <img src="../img/14-1.png" width=280px>
</div>

字符串""存储为一个空字符：
<div class="top-2">
    <img src="../img/14-2.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 如何存储字符串字面量

---

因为字符串字面量存储为数组，编译器将其视为char * 类型的指针.

printf和scanf都需要一个char * 类型的值作为它们的第一个参数。

下面的printf调用传递了“abc”的地址（一个指向字母a在内存中存储位置的指针）：
`printf("abc");` 

<!-- slide vertical=true data-notes="" -->



##### 对字符串字面量的操作

---

可以在任何允许使用char * 指针的地方使用字符串字面量 ：
```C
char *p;
p = "abc";
```

该赋值使p指向字符串的第一个字符。

<!-- slide vertical=true data-notes="" -->



##### 对字符串字面量的操作

---

可以对字符串字面量取下标：
```C
char ch;
ch = "abc"[1];
```
ch的新值将是字母b 。

将 0 ~ 15 的数字转换为等价的十六进制的字符形式的函数：
```C
char digit_to_hex_char(int digit)
{
	return "0123456789ABCDEF"[digit];
}
```

<!-- slide vertical=true data-notes="" -->



##### 对字符串字面量的操作

---

尝试修改字符串字面量会导致未定义的行为：
```C
char *p = "abc";
*p = 'd';   /*** WRONG ***/
```

尝试更改字符串字面量可能会导致程序崩溃或行为异常。

<!-- slide vertical=true data-notes="" -->



##### 字符串字面量与字符常量

---

包含单个字符的字符串字面量与字符常量不同。

- "a"由**指针**表示。

- 'a'由**整数**表示。

printf的合法调用：
```C
printf("\n");
```

非法调用：
```C
printf('\n'); /*** 错误的 ***/
```

<!-- slide vertical=true data-notes="" -->



##### 字符串变量

---

任何一维字符数组都可以用来存储字符串。

字符串必须以空字符结尾。

这种方法的难点：

- 很难判断一个字符数组是否被用作字符串。
- 字符串处理函数必须小心处理空字符。
- 确定字符串的长度需要搜索空字符。

<!-- slide vertical=true data-notes="" -->



##### 字符串变量

---

如果字符串变量需要存储 80 个字符，则必须将其声明为 81：
```C
#define STR_LEN 80
…
char str[STR_LEN+1];
```

长度加1可以为字符串末尾的空字符留出空间。

定义一个代表 80 的宏，然后加 1 是一种惯用法。

<!-- slide vertical=true data-notes="" -->



##### 字符串变量

---

声明字符串变量时，请务必为空字符留出空间。

不这样做可能会在程序执行时导致不可预知的结果。

字符串的实际长度取决于终止空字符的位置。

STR_LEN + 1 长度的字符数组可以保存长度为 0 ~ STR_LEN之间的字符串。

<!-- slide vertical=true data-notes="" -->



##### 初始化字符串变量

---

字符串变量可以在声明的同时初始化：
```C
char date1[8] = "June 14"; 
```

编译器将自动添加一个空字符，以便date1可以用作字符串：
<div class="top-2">
    <img src="../img/14-3.png" width=280px>
</div>
 
"June  14" 在此上下文中不是字符串字面量。

相反，C 将其视为数组初始值设定项的缩写。

<!-- slide vertical=true data-notes="" -->



##### 初始化字符串变量

---

如果初始化程序太短而无法填充字符串变量，编译器会添加额外的空字符：
```C
char date2[9] = "June  14" ; 
```

date2的外观：
<div class="top-2">
    <img src="../img/14-4.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 初始化字符串变量

---

字符串变量的初始值设定项不能长于变量，但长度可以相同：
```C
char date3[7] = "June 14";
```

空字符没有空间，因此编译器不会尝试存储空字符：
<div class="top-2">
    <img src="../img/14-5.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 初始化字符串变量

---

字符串变量的声明可能会省略它的长度，在这种情况下编译器会计算它：
```C
char date4[] = "June 14";
```

date4留出八个字符，足以存储“June 14”中的字符加上一个空字符。

如果初始化程序很长，则省略字符串变量的长度特别有用，因为手动计算长度容易出错。

<!-- slide vertical=true data-notes="" -->



##### 字符数组与字符指针

---

宣言
```C
char date[] = "June 14";
```
date声明为一个数组， 

长相相似的
```C
char *date = "June 14";
```

声明date是一个指针。
由于数组和指针之间的密切关系，任何一个版本都可以用作字符串。

<!-- slide vertical=true data-notes="" -->



##### 字符数组与字符指针

---

date之间存在显着差异。
在数组版本中，可以修改存储在日期中的字符。在指针版本中，日期指向不应修改的字符串字面量。
在数组版本中，日期是一个数组名称。在指针版本中，日期是一个可以指向其他字符串的变量。

<!-- slide vertical=true data-notes="" -->



##### 字符数组与字符指针

---

宣言
```C
char *p;
```
不为字符串分配空间。

在我们可以将p用作字符串之前，它必须指向一个字符数组。
一种可能性是使p指向一个字符串变量：
```C
char str[STR_LEN+1], *p;
p = str;
```

另一种可能性是使p指向动态分配的字符串。

<!-- slide vertical=true data-notes="" -->



##### 字符数组与字符指针

---

使用未初始化的指针变量作为字符串是一个严重的错误。
尝试构建字符串"abc" ：
```C
char *p;

p[0] = 'a';    /*** WRONG ***/
p[1] = 'b';    /*** WRONG ***/
p[2] = 'c';    /*** WRONG ***/
p[3] = '\0';   /*** WRONG ***/
```

由于p尚未初始化，这会导致未定义的行为。

<!-- slide vertical=true data-notes="" -->



##### 读写字符串

---

使用printf或puts编写字符串很容易。

读取字符串有点困难，因为输入可能比存储它的字符串变量长。

要一步读取字符串，我们可以使用scanf或gets 。

作为替代方案，我们可以一次读取一个字符的字符串。

<!-- slide vertical=true data-notes="" -->



##### printf和puts编写字符串

---

%s转换规范允许printf写入一个字符串：
```C
char str[] = "Are we having fun yet?";
printf("%s\n", str);
```

输出将是
Are we having fun yet?
printf将字符串中的字符一一写入，直到遇到空字符。

<!-- slide vertical=true data-notes="" -->



##### printf和puts编写字符串

---

要打印字符串的一部分，请使用转换规范%。附言_

p是要显示的字符数。

该声明
```C
printf("%.6s\n", str);
```
将打印
Are we 

<!-- slide vertical=true data-notes="" -->



##### printf和puts编写字符串

---

% m s转换将在大小为m的字段中显示一个字符串。

如果字符串少于m个字符，它将在字段内右对齐。

m前面放一个减号。

m和p值可以组合使用。

% m形式的转换规范。 p s使字符串的前p个字符显示在大小为m的字段中。

<!-- slide vertical=true data-notes="" -->



##### printf和puts编写字符串

---

printf不是唯一可以编写字符串的函数。

C 库还提供puts ：
`puts(str);`

写完一个字符串后， puts总是写一个额外的换行符。

<!-- slide vertical=true data-notes="" -->



##### scanf和gets读取字符串

---

%s转换规范允许scanf将字符串读入字符数组：
`scanf("%s", str);`

str被视为指针，因此无需将&运算符放在str前面。

scanf时，它会跳过空白，然后读取字符并将它们存储在str中，直到遇到空白字符。

scanf总是在字符串的末尾存储一个空字符。

<!-- slide vertical=true data-notes="" -->



##### scanf和gets读取字符串

---

scanf通常不会读取整行输入。

换行符会导致scanf停止读取，但空格或制表符也会。

要读取整行输入，我们可以使用gets 。

获取的属性：
在开始读取输入之前不跳过空格。
读取直到找到换行符。
丢弃换行符而不是存储它；空字符取而代之。

<!-- slide vertical=true data-notes="" -->



##### scanf和gets读取字符串

---

考虑以下程序片段：
```C
char sentence[SENT_LEN+1];
printf("Enter a sentence:\n");
scanf("%s", sentence);
```

假设在提示之后
Enter a sentence:

用户进入该行
To C, or not to C: that is the question.

scanf将字符串“To”存储在句中。

<!-- slide vertical=true data-notes="" -->



##### scanf和gets读取字符串

---

假设我们将scanf替换为gets ：
`gets(sentence);`

当用户输入与之前相同的输入时， gets将存储字符串
"  To C, or not to C: that is the question."

在句子中。

<!-- slide vertical=true data-notes="" -->



##### scanf和gets读取字符串

---

当他们将字符读入数组时， scanf和get无法检测到它何时已满。

因此，它们可能会存储超出数组末尾的字符，从而导致未定义的行为。

% n s而不是%s可以使scanf更安全。

n是一个整数，表示要存储的最大字符数。

获取本质上是不安全的； fgets是一个更好的选择。

<!-- slide vertical=true data-notes="" -->



##### 逐个字符读取字符串

---

程序员经常编写自己的输入函数。

需要考虑的问题：
该函数是否应该在开始存储字符串之前跳过空格？
什么字符导致函数停止读取：换行符、任何空白字符或其他字符？这个字符是存储在字符串中还是被丢弃？
如果输入字符串太长而无法存储，该函数应该做什么：丢弃多余的字符或将它们留给下一次输入操作？

<!-- slide vertical=true data-notes="" -->



##### 逐个字符读取字符串

---

假设我们需要一个函数（1）不跳过空白字符，（2）在第一个换行符处停止读取（未存储在字符串中），以及（3）丢弃多余的字符。

函数原型：
`int read_line(char str[], int n);`

如果输入行包含超过n个字符， read_line将丢弃额外的字符。

read_line将返回它存储在str中的字符数。

<!-- slide vertical=true data-notes="" -->



##### 逐个字符读取字符串

---

read_line主要由一个循环组成，该循环调用getchar来读取一个字符，然后将该字符存储在str中，前提是还有空间：
```C
int read_line(char str[], int n)
{
  int ch, i = 0;
  
  while ((ch = getchar()) != '\n')
	  if (i < n)
	    str[i++] = ch;
	str[i] = '\0';   /* terminates string */
	return i;        /* number of characters stored */
}
```

ch具有int类型而不是char类型，因为getchar返回一个int值。

<!-- slide vertical=true data-notes="" -->



##### 逐个字符读取字符串

---

在返回之前， read_line在字符串末尾放置一个空字符。

标准函数（例如scanf和gets）会自动在输入字符串的末尾放置一个空字符。

如果我们正在编写自己的输入函数，我们必须承担这个责任。

<!-- slide vertical=true data-notes="" -->



##### 访问字符串中的字符

---

由于字符串存储为数组，我们可以使用下标来访问字符串中的字符。

要处理字符串s中的每个字符，我们可以设置一个循环来增加计数器i并通过表达式s[i]选择字符。

<!-- slide vertical=true data-notes="" -->



##### 访问字符串中的字符

---

计算字符串中空格数的函数：
```C
int count_spaces(const char s[])
{
 int count = 0, i;

 for (i = 0; s[i] != '\0'; i++)
   if (s[i] == ' ')
     count++;
 return count;
}
```

<!-- slide vertical=true data-notes="" -->



##### 访问字符串中的字符

---

使用指针算法而不是数组下标的版本：
```C
int count_spaces(const char *s)
{
 int count = 0;

 for (; *s != '\0'; s++)
   if (*s == ' ')
     count++;
 return count;
} 
```

<!-- slide vertical=true data-notes="" -->



##### 访问字符串中的字符

---

count_spaces示例提出的问题：

使用数组操作还是指针操作来访问字符串中的字符更好吗？我们可以使用其中一个或两个。传统上，C 程序员倾向于使用指针操作。

字符串参数应该声明为数组还是指针？两者没有区别。

参数的形式（s[]或*s）是否影响可以作为参数提供的内容？不。

<!-- slide vertical=true data-notes="" -->



##### 使用 C 字符串库

---

一些编程语言提供了可以复制字符串、比较字符串、连接字符串、选择子字符串等的运算符。

相比之下，C 的运算符在处理字符串时基本上没有用处。

字符串在 C 中被视为数组，因此它们的限制方式与数组相同。

特别是，它们不能使用运算符进行复制或比较。

<!-- slide vertical=true data-notes="" -->



##### 使用 C 字符串库

---

直接尝试复制或比较字符串将失败。

无法使用=运算符将字符串复制到字符数组中：
```C
char str1[10], str2[10];
…
str1 = "abc";  /*** WRONG ***/
str2 = str1;   /*** WRONG ***/
```

使用数组名作为=的左操作数是非法的。

用=初始化字符数组是合法的：
```C
char str1[10] = "abc";
```
在这种情况下， =不是赋值运算符。

<!-- slide vertical=true data-notes="" -->



##### 使用 C 字符串库

---


<!-- slide vertical=true data-notes="" -->



##### 使用 C 字符串库

---

尝试使用关系或相等运算符比较字符串是合法的，但不会产生所需的结果：
```C
if (str1 == str2) …   /*** WRONG ***/
```

该语句将str1和str2作为指针进行比较。

由于str1和str2有不同的地址，表达式str1 == str2的值必须为 0。

<!-- slide vertical=true data-notes="" -->



##### 使用 C 字符串库

---

C 库提供了一组丰富的函数来对字符串执行操作。

需要字符串操作的程序应包含以下行：
`#include <string.h>`

在后续示例中，假设str1和str2是用作字符串的字符数组。

<!-- slide vertical=true data-notes="" -->



##### strcpy （字符串复制）函数

---

strcpy函数的原型：
`char *strcpy(char *s1, const char *s2);`

strcpy将字符串s2复制到字符串s1中。
准确地说，我们应该说“ strcpy将s2指向的字符串复制到s1指向的数组中”。

strcpy返回s1 （指向目标字符串的指针）。

<!-- slide vertical=true data-notes="" -->



##### strcpy （字符串复制）函数

---

在str2中存储字符串“abcd”的strcpy调用：
```C
strcpy（str2，“abcd”）;
/* str2 现在包含 "abcd" */
```

str2的内容复制到str1的调用：
```C
strcpy（str1，str2）;
/* str1 现在包含 "abcd" */
```

<!-- slide vertical=true data-notes="" -->



##### strcpy （字符串复制）函数

---

在调用strcpy(str1, str2) ， strcpy无法检查str2字符串是否适合str1 指向的数组。

如果不是，则会发生未定义的行为。

<!-- slide vertical=true data-notes="" -->



##### strcpy （字符串复制）函数

---

调用strncpy函数是一种更安全但速度较慢的复制字符串的方法。

strncpy有第三个参数，它限制将被复制的字符数。

str2复制到str1的strncpy调用：
`strncpy(str1, str2, sizeof(str1));`

<!-- slide vertical=true data-notes="" -->



##### strcpy （字符串复制）函数

---

str2的长度大于或等于str1数组的大小， strncpy将使str1不带终止空字符。

使用strncpy的更安全方法：
```C
strncpy(str1, str2, sizeof(str1) - 1);
str1[sizeof(str1)-1] = '\0';
```

第二条语句保证str1始终以空值结尾。

<!-- slide vertical=true data-notes="" -->



##### strlen （字符串长度）函数

---

strlen函数的原型：
`size_t strlen(const char *s);`

size_t是一个typedef名称，表示 C 的无符号整数类型之一。

<!-- slide vertical=true data-notes="" -->



##### strlen （字符串长度）函数

---

strlen返回字符串s的长度，不包括空字符。

例子：
```C
int len;

len = strlen("abc");  /* len is now 3 */
len = strlen("");     /* len is now 0 */
strcpy(str1, "abc");
len = strlen(str1);   /* len is now 3 */
```

<!-- slide vertical=true data-notes="" -->



##### strcat （字符串连接）函数

---

strcat函数的原型：
`char *strcat(char *s1, const char *s2);`

strcat将字符串s2的内容附加到字符串s1的末尾。

它返回s1 （指向结果字符串的指针）。

strcat示例：
```C
strcpy(str1, "abc");
strcat(str1, "def");
 /* str1 now contains "abcdef" */
strcpy(str1, "abc");
strcpy(str2, "def");
strcat(str1, str2);
 /* str1 now contains "abcdef" */ 
```

<!-- slide vertical=true data-notes="" -->



##### strcat （字符串连接）函数

---

与strcpy一样， strcat返回的值通常会被丢弃。

以下示例显示了如何使用返回值：
```C
strcpy(str1, "abc");
strcpy(str2, "def");
strcat(str1, strcat(str2, "ghi"));
 /* str1 now contains "abcdefghi";
    str2 contains "defghi" */
```

<!-- slide vertical=true data-notes="" -->



##### strcat （字符串连接）函数

---

strcat(str1, 如果str1数组的长度不足以容纳 str2 中的字符，则str2 )会导致未定义的行为。

例子：
```C
char str1[6] = "abc";

strcat(str1, "def");   /*** WRONG ***/
```

str1被限制为六个字符，导致strcat写入超出数组末尾。

<!-- slide vertical=true data-notes="" -->



##### strcat （字符串连接）函数

---

strncat函数是strcat的一个更安全但速度较慢的版本。

像strncpy一样，它有第三个参数来限制它将复制的字符数。

调用strncat ：
`strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);`

strncat将以空字符终止str1 ，该空字符不包含在第三个参数中。

<!-- slide vertical=true data-notes="" -->



##### strcmp （字符串比较）函数

---

strcmp函数的原型：
`int strcmp(const char *s1, const char *s2);`

strcmp比较字符串s1和s2 ，返回一个小于、等于或大于 0 的值，具体取决于s1是小于、等于还是大于s2 。

<!-- slide vertical=true data-notes="" -->



##### strcmp （字符串比较）函数

---

测试str1是否小于str2 ：
```C
if (strcmp(str1, str2) < 0)    /* is str1 < str2? */
 …
```

测试str1是否小于或等于str2 ：
```C
if (strcmp(str1, str2) <= 0) /* is str1 <= str2? */
 …
```

通过选择适当的运算符（ < 、 <= 、 > 、 >= 、 == 、 != ），我们可以测试str1和str2之间的任何可能关系。

<!-- slide vertical=true data-notes="" -->



##### strcmp （字符串比较）函数

---

strcmp认为s1小于s2 ：

s1和s2的前i个字符匹配，但 s1 的 ( i +1 )st 字符小于s2的 ( i +1)st 字符。

s1的所有字符都匹配s2 ，但s1比s2短。

<!-- slide vertical=true data-notes="" -->



##### strcmp （字符串比较）函数

---

在比较两个字符串时， strcmp查看字符串中字符的数字代码。

一些底层字符集的知识有助于预测strcmp会做什么。

ASCII 的重要属性：
A–Z、a–z 和 0–9 具有连续代码。
所有大写字母都小于所有小写字母。
数字小于字母。
空格小于所有打印字符。

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

remind.c程序打印一个月的每日提醒列表。

用户将输入一系列提醒，每个提醒都以一个月中的某一天为前缀。

当用户输入 0 而不是有效日期时，程序将打印所有输入的提醒列表，按天排序。

下一张幻灯片显示了该程序的会话。

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

Enter day and reminder: 24 Susan's birthday
Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
Enter day and reminder: 26 Movie - "Chinatown"
Enter day and reminder: 7 10:30 - Dental appointment
Enter day and reminder: 12 Movie - "Dazed and Confused"
Enter day and reminder: 5 Saturday class
Enter day and reminder: 12 Saturday class
Enter day and reminder: 0
	 
Day Reminder
  5 Saturday class
  5 6:00 - Dinner with Marge and Russ
  7 10:30 - Dental appointment
 12 Saturday class
 12 Movie - "Dazed and Confused“
 24 Susan's birthday
 26 Movie - "Chinatown"

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

总体策略：
阅读一系列每日提醒组合。
按顺序存储它们（按天排序）。
显示它们。

scanf将用于读取日期。

read_line将用于阅读提醒。

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

字符串将存储在一个二维字符数组中。

数组的每一行都包含一个字符串。

程序读取一天后采取的行动及其相关提醒：
搜索数组以确定日期所属的位置，使用strcmp进行比较。
使用strcpy将该点以下的所有字符串向下移动一个位置。
将日期复制到数组中并调用strcat将提醒附加到日期。

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

一个复杂的问题：如何在两个字符的字段中右对齐日期。

解决方案：使用scanf将日期读入整数变量，然后调用sprintf将日期转换回字符串形式。

sprintf类似于printf ，不同之处在于它将输出写入字符串。

调用
`sprintf(day_str, "%2d", day);`
day的值写入day_str 。

<!-- slide vertical=true data-notes="" -->



##### 程序：打印一个月的提醒清单

---

以下scanf调用可确保用户输入的数字不超过两位：
`scanf("%2d", &day);`

<!-- slide vertical=true data-notes="" -->



##### remind.c

---
```C
/* Prints a one-month reminder list */
 
#include <stdio.h>
#include <string.h>
 
#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */
 
int read_line(char str[], int n);
 
int main(void)
{
  char reminders[MAX_REMIND][MSG_LEN+3];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, j, num_remind = 0;
 
  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);
 
    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);
 
    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);
 
    num_remind++;
  }
 
  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);
 
  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;
 
  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
```

<!-- slide vertical=true data-notes="" -->



##### 字符串习语

---

操作字符串的函数是惯用语的丰富来源。

strlen和strcat函数来探索一些最著名的习语。

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

strlen版本，使用变量来跟踪字符串的长度：
```C
size_t strlen(const char *s)
{
 size_t n;

 for (n = 0; *s != '\0'; s++)
   n++;
 return n;
}
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

n的初始化移到它的声明中：
```C
size_t strlen(const char *s)
{
 size_t n = 0;

 for (; *s != '\0'; s++)
   n++;
 return n;
}
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

条件*s != '\0'与*s相同 != 0 ，这又与*s相同。
使用这些观察的strlen版本：
```C
size_t strlen(const char *s)
{
 size_t n = 0;

 for (; *s; s++)
   n++;
 return n;
}
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

下一个版本增加s并在同一个表达式中测试*s：
```C
size_t strlen(const char *s)
{
 size_t n = 0;

 for (; *s++;)
   n++;
 return n;
} 
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

用while语句替换for语句会给出以下版本的strlen：
```C
size_t strlen(const char *s)
{
 size_t n = 0;

 while (*s++)
   n++;
 return n;
}
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

尽管我们已经对strlen进行了相当多的压缩，但很可能我们还没有提高它的速度。

一个运行速度更快的版本，至少在某些编译器中：

```C
size_t strlen(const char *s)
{
 const char *p = s;

 while (*s)
   s++;
 return s - p;
}
```

<!-- slide vertical=true data-notes="" -->



##### 搜索字符串的结尾

---

“在字符串末尾搜索空字符”的成语：
```C
	while (*s)     while (*s++)
	  s++;           ;
```


第一个版本让s指向空字符。

第二个版本更简洁，但s指向刚刚超过空字符。

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

复制字符串是另一种常见的操作。

为了介绍 C 的“字符串复制”习语，我们将开发两个版本的strcat函数。

strcat的第一个版本（下一张幻灯片）使用两步算法：
s1末尾的空字符并让p指向它。
将字符从s2一个一个复制到p指向的位置。

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---
```C
char *strcat(char *s1, const char *s2) 
{
 char *p = s1;

 while (*p != '\0')
   p++;
 while (*s2 != '\0') {
   *p = *s2;
   p++;
   s2++;
 }
 *p = '\0';
 return s1;
}
```

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

p最初指向s1字符串中的第一个字符：
<div class="top-2">
    <img src="../img/14-6.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

第一个while语句定位s1末尾的空字符并让p指向它：
<div class="top-2">
    <img src="../img/14-7.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

第二个while语句重复将一个字符从s2指向的位置复制到p指向的位置，然后递增p和s2 。

假设s2最初指向字符串"def" 。

第一次循环迭代后的字符串：

<div class="top-2">
    <img src="../img/14-8.png" width=280px>
</div>


<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

当s2指向空字符时，循环终止：

<div class="top-2">
    <img src="../img/14-9.png" width=280px>
</div>

在p指向的位置放置一个空字符后， strcat返回。

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

strcat的精简版：
```C
char *strcat(char *s1, const char *s2) 
{
 char *p = s1;

 while (*p)
   p++;
 while (*p++ = *s2++)
   ;
 return s1;
}
```

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

流线型strcat函数的核心是“字符串复制”习语：
```C
while (*p++ = *s2++)
 ;
```

忽略两个++运算符，括号内的表达式是一个赋值：
`*p = *s2`

赋值后， p和s2递增。

重复计算此表达式会将字符从s2指向的位置复制到p指向的位置。

<!-- slide vertical=true data-notes="" -->



##### 复制字符串

---

但是是什么导致循环终止？

while语句测试由赋值*p复制的字符 = *s2 。

除空字符外的所有字符都测试为真。

后循环终止，因此将复制空字符。

<!-- slide vertical=true data-notes="" -->



##### 字符串数组

---

存储字符串数组的方法不止一种。

一种选择是使用二维字符数组，每行一个字符串：
```C
char planets[][8] = {"Mercury", "Venus", "Earth",
                    "Mars", "Jupiter", "Saturn",
                    "Uranus", "Neptune", "Pluto"};
```

数组中的行数可以省略，但我们必须指定列数。

<!-- slide vertical=true data-notes="" -->



##### 字符串数组

---

不幸的是，行星数组包含相当多的浪费空间（额外的空字符）：
<div class="top-2">
    <img src="../img/14-10.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 字符串数组

---

大多数字符串集合将混合长字符串和短字符串。

我们需要的是一个参差不齐的数组，它的行可以有不同的长度。

指向字符串的指针的数组来模拟 C 中的不规则数组：
```C
char *planets[] = {"Mercury", "Venus", "Earth",
                  "Mars", "Jupiter", "Saturn",
                  "Uranus", "Neptune", "Pluto"};
```

<!-- slide vertical=true data-notes="" -->



##### 字符串数组

---

这个微小的变化对行星的存储方式产生了巨大的影响：
<div class="top-2">
    <img src="../img/14-11.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 字符串数组

---

要访问行星名称之一，我们需要做的就是为行星数组下标。

访问行星名称中的字符与访问二维数组元素的方式相同。

行星数组中搜索以字母 M 开头的字符串的循环：
```C
for (i = 0; i < 9; i++)
 if (planets[i][0] == 'M')
   printf("%s begins with M\n", planets[i]);
```

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

当我们运行一个程序时，我们经常需要向它提供信息。

这可能包括修改程序行为的文件名或开关。

UNIX ls命令的示例：
```
ls
ls –l
ls -l remind.c
```

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

所有程序都可以使用命令行信息，而不仅仅是操作系统命令。

要访问命令行参数， main必须有两个参数：
```C
int main(int argc, char *argv[])
{
 …
}
```


命令行参数在 C 标准中称为程序参数。

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

argc （“参数计数”）是命令行参数的数量。

argv （“参数向量”）是指向命令行参数的指针数组（存储为字符串）。

argv[0]指向程序的名称，而argv[1]到argv[argc-1]指向剩余的命令行参数。

argv[argc]总是一个空指针——一个不指向任何东西的特殊指针。
宏NULL表示一个空指针。

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

如果用户输入命令行
`ls -l remind.c`

那么argc将为 3，而argv将具有以下外观：
<div class="top-2">
    <img src="../img/14-12.png" width=280px>
</div>

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

由于argv是一个指针数组，因此访问命令行参数很容易。

通常，需要命令行参数的程序会设置一个循环，依次检查每个参数。

编写这样一个循环的一种方法是使用一个整数变量作为argv数组的索引：
```C
int i;

for (i = 1; i < argc; i++)
 printf("%s\n", argv[i]);
```

<!-- slide vertical=true data-notes="" -->



##### 命令行参数

---

另一种技术是设置指向argv[1]的指针，然后重复递增指针：
```C
char **p;

for (p = &argv[1]; *p != NULL; p++)
 printf("%s\n", *p);
```

<!-- slide vertical=true data-notes="" -->



##### 程序：检查行星名称

---

Planet.c程序说明了如何访问命令行参数。

该程序旨在检查一系列字符串，以查看哪些是行星的名称。

字符串放在命令行上：
planet Jupiter venus Earth fred

该程序将指示每个字符串是否是行星名称，如果是，则显示行星的编号：
```
Jupiter is planet 5
venus is not a planet
Earth is planet 3
fred is not a planet
```

<!-- slide vertical=true data-notes="" -->



##### planet.c

---

```C
/* Checks planet names */
 
#include <stdio.h>
#include <string.h>
 
#define NUM_PLANETS 9
 
int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;
  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (strcmp(argv[i], planets[j]) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }
 
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->


