---
password: "cpl2026"
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

## 指针与字符串

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 字符串字面量与存储

- 字符串变量: 字符数组 vs 字符指针

- 字符串的读写

- 字符串库函数与综合案例

---


<!-- slide data-notes="" -->


##### 字符串字面量

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C
Candy
Is dandy
But liquor
Is quicker.
  --Ogden Nash
```

</div>

<div style="flex:1;">

程序处理的不只是数字——名字、句子、文件名……都是==字符串==。

本章涵盖==字符串常量==(C标准中称为字符串字面量)和==字符串变量==.

字符串是字符数组, 用特殊字符(空字符)标记结束.

C库提供了一组用于处理字符串的函数.

</div>

</div>

<!-- slide data-notes="" -->

##### 字符串字面量 (续)

---

字符串字面量: 用双引号括起来的字符序列。

`"When you come to a fork in the road, take it."`

字符串字面量可能包含转义序列.

转义字符经常出现在 printf 和 scanf 格式字符串中.

例如, 字符串

`"Candy\nIs dandy\nBut liquor\nIs quicker.\n  --Ogden Nash\n"`

每个 `\n` 字符使光标移到下一行:

<!-- slide data-notes="" -->


##### 字符串字面量的存储

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

当C编译器在程序中遇到长度为 ==$n$== 的字符串字面量时, 它会为该字符串分配 ==$n + 1$== 个字节的内存. 

这块空间存字符串的字符, 外加一个额外字符: 
==空字符== 标记字符串的结尾. 

空字符是所有位都为0的字节, 因此它用转义序列 =='\0'== 表示.

</div>

<div style="flex:1;font-size:0.62em;">

字符串字面量 "abc" 存储成 4 个字符的数组:

<div class="top-2">
  <img src="figs/14-1.png" height=70px>
</div>

空串 "" 只存一个空字符:

<div class="top-2">
  <img src="figs/14-2.png" height=60px>
</div>

</div>

</div>

---


<!-- slide data-notes="" -->


##### 对字符串字面量的操作

---

凡是能用 `char *` 指针的地方, 都能直接用字符串字面量:

<div style="font-size:0.85em;">

```C
char *p;
p = "abc"; /* 正确 */
```

</div>

该赋值使 p 指向字符串的第一个字符.

字符串字面量也可以取下标:

<div style="font-size:0.85em;">

```C
char ch;
ch = "abc"[1];  // ch is now 'b'
```

</div>

<!-- slide data-notes="" -->

##### 对字符串字面量的操作 (续)

---

把 0 ~ 15 的数字转成十六进制字符的函数:

<div style="font-size:0.85em;">

```C
char digit_to_hex_char(int digit)
{
  return "0123456789ABCDEF"[digit];
}
```

</div>

函数把字符串字面量当作只读数组使用: `digit` 是下标, 返回值是对应字符.

<!-- slide data-notes="" -->


##### 字符串字面量与字符常量

---

包含单个字符的字符串字面量与字符常量不同. 

- `"a"`由==指针==表示. 

- `'a'`由==整数==表示. 

合法调用: 
```C
printf("\n");
```

非法调用: 
```C
printf('\n'); /*** 错误的 ***/
```

---


<!-- slide data-notes="" -->


##### 字符串变量: 字符数组

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C
#define STR_LEN 80
…
char str[STR_LEN+1];
```

```C
char date1[8] = "June 14";
```

</div>

<div style="flex:1;">

任何一维字符数组都可以用来存储字符串.

字符串必须以空字符结尾.

用数组存字符串的难点:

- 很难判断一个字符数组是否被用作字符串.

- 字符串处理函数必须小心处理空字符.

- 确定字符串的长度需要搜索空字符.

</div>

</div>

<!-- slide data-notes="" -->

##### 字符串变量: 字符数组 (续)

---

如果字符串变量需要存储 80 个字符, 则必须将其声明为 81:

长度加 1 可以为字符串末尾的空字符留出空间.

定义一个代表 80 的宏, 然后加 1 是一种<u>惯用法</u>.

声明字符串变量时, 请务必为空字符留出空间.

不这样做可能会在程序执行时导致不可预知的结果.

字符串的实际长度取决于终止空字符的位置.

`STR_LEN + 1` 长度的字符数组可以保存长度为 0 ~ `STR_LEN` 之间的字符串.

<!-- slide data-notes="" -->

##### 字符串变量: 字符数组 (续 2)

---

字符串变量可以在声明时初始化:

编译器将自动添加一个空字符, 使 date1 可以用作字符串:

<div class="top-2">
  <img src="figs/14-3.png" height=100px>
</div>

"June 14" 在此上下文中不是字符串字面量.

C 编译器将其视为字符数组初始化式的缩写.

<!-- slide data-notes="" -->


##### 初始化字符串变量

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;font-size:0.6em;">

若初始化式太短无法填满字符串变量, 编译器会添加额外空字符:

```C
char date2[9] = "June 14";
```

字符串变量的初始化式不能长于变量, 但长度可以相同:

```C
char date3[7] = "June 14";
```

因为没有给空字符留空间, 编译器不会尝试存储空字符.

</div>

<div style="flex:1;font-size:0.6em;">

之后, date2 将如下所示:

<div class="top-2">
  <img src="figs/14-4.png" height=65px>
</div>

date3 的存储:

<div class="top-2">
  <img src="figs/14-5.png" height=75px>
</div>

</div>

</div>

---


<!-- slide data-notes="" -->


##### 字符数组与字符指针

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
char date[] = "June 14";
```

```C
char *date = "June 14";
```

</div>

<div style="flex:1;">

左侧第一个声明将 date 声明为一个数组:

左侧第二个声明则将 date 声明为一个指针:

由于数组和指针之间的密切关系, 这两种都可以用作字符串.

两种 date 之间存在的差异:

- 声明为数组时, 可以修改存储在 date 中的字符. 声明为指针时, date 指向不应修改的字符串字面量.

- 声明为数组时, date 是一个数组名. 声明为指针时, date 是一个可以指向其他字符串的指针变量.

</div>

</div>

<!-- slide data-notes="" -->

##### 字符数组与字符指针 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
char *p;
```

```C
char str[STR_LEN+1], *p;
p = str;
```

</div>

<div style="flex:1;">

声明

`char *p;`

不会为字符串分配空间.

在使用 p 作为字符串之前, 必须把 p 指向字符数组.

一种可能是把 p 指向一个字符串变量:

另一种可能是让 p 指向动态分配的字符串, 这一点后面讲到动态内存分配时再介绍.

</div>

</div>

<!-- slide data-notes="" -->


##### 写字符串: printf 与 puts

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C
char str[] = "Are we having fun yet?";
printf("%.6s\n", str);
puts(str);
```

</div>

<div style="flex:1;">

要打印字符串的一部分, 可以使用转换说明 ==%.ps==

==p== 是要打印的字符数量.

`printf("%.6s\n", str);` 将打印
`Are we`

`puts(str);` 打印整个字符串并自动换行 (相当于 `printf("%s\n", str)`).

</div>

</div>

<!-- slide data-notes="" -->

##### 写字符串: 字段宽度

---

转换说明 ==%ms== 将在大小为 ==m== 的字段内打印字符串.

如果字符串少于 ==m== 个字符, 则会在字段内右对齐输出.

如果要强制左对齐, 在 m 前面加一个减号.

m 和 p 可以组合使用:

转换说明 ==%m.ps== 会使字符串的前 ==p== 个字符打印在大小为 ==m== 的字段中.

例如:

```C
printf("%10.6s|\n", str);  /* 字段宽 10, 取前 6 个字符, 右对齐 */
printf("%-10.6s|\n", str); /* 左对齐 */
```

<!-- slide data-notes="" -->


##### 读字符串: scanf

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

转换说明 ==%s== 允许 scanf 将字符串读入字符数组:

`scanf("%s", str);`

str 被视为指针, 因此无需在 str 前添加 `&` 运算符.

scanf 会跳过空白字符, 然后读入字符并存储到 str 中, 直到遇到空白字符.

scanf 会在字符串的末尾存储一个空字符.

scanf 通常不会读取整行输入.

换行符会导致 scanf 停止读取, 空格和制表符也会.

</div>

</div>

<!-- slide data-notes="" -->

##### 读字符串: scanf (续)

---

要读取整行输入, 历史上常用 gets. gets 的特点:

- 不会在开始读字符串之前跳过空白字符.

- 持续读入直到找到<u>换行符</u>才停止.

- 忽略换行符而不存储它, 用空字符代替换行符.

但 gets 有严重缺陷, 下一页细讲.

<!-- slide data-notes="" -->

##### 读字符串: 为什么不用 gets

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.62em;">

不要使用 ==gets== 读取字符串:

- gets ==不检查缓冲区大小==, 输入过长会溢出 (缓冲区溢出漏洞的经典来源)

- ==C11 标准已把 gets 从语言中移除==; OJ 平台上的老题也要改用 fgets

==fgets== 会连换行符一起读入 (和 gets 不同), 需要时手工去掉末尾的 `\n`.

去掉换行符的写法 (`strlen` 声明在 `<string.h>` 中).

</div>

<div style="flex:1;font-size:0.62em;">

```C
char line[100];

/* Wrong: gets(line);  —— 危险且已移除 */
fgets(line, sizeof(line), stdin);   /* 正确: 带上限长度 */
```

```C
size_t l = strlen(line);
if (l > 0 && line[l - 1] == '\n')
  line[l - 1] = '\0';
```

</div>

</div>

---


<!-- slide data-notes="" -->


##### 逐个字符读字符串

---

<div style="display:flex;align-items:flex-start;gap:24px;">



<div style="flex:1;">

程序员经常自己编写输入函数. 需要考虑的问题: 

- 在开始存储字符串之前, 函数是否应该跳过空白字符？

- 什么字符会导致函数停止读取: 换行符、任何空白字符或其他字符？这个字符是存储在字符串中还是被丢弃？

- 如果输入字符串太长而无法存储, 函数应该做什么: 丢弃多余的字符或将它们留给下一次输入操作？


假设我们需要一个函数: 
(1)不跳过空白字符；
(2)在第一个换行符处停止读取(不存储到字符串中)；
(3)丢弃多余的字符. 

函数原型: `int read_line(char str[], int n);`

如果输入行包含多于 n-1 个字符, read_line 将丢弃额外的字符. 

read_line将返回实际存储在str中的字符数量.

</div>

</div>

<!-- slide data-notes="" -->


##### 逐个字符读字符串 (实现)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C{.line-numbers}
int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    if (i < n - 1)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}
```

</div>

<div style="flex:1;">

`getchar` 每次读入一个字符.

循环在换行符或文件结束处停止, 换行符不存入数组.

`i < n - 1` 保证数组留出一个位置给空字符; 超出的字符被读入后直接丢弃.

循环结束后补上空字符, 返回实际存储的字符数.

输入行不超过 `n-1` 个字符时, 返回值就是行长; 否则返回 `n-1`.

</div>

</div>

<!-- slide data-notes="" -->


##### 访问字符串中的字符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
int count_spaces(const char s[])
{
  int count = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ')
      count++;
  }
  return count;
}
```

```C{.line-numbers}
int count_spaces(const char *s)
{
  int count = 0;
  for (; *s != '\0'; s++) {
    if (*s == ' ')
      count++;
  }
  return count;
}
```

</div>

<div style="flex:1;">

由于字符串是以数组的方式存储的, 可以使用下标来访问字符串中的字符.

要处理字符串 s 中的每个字符, 可以设置一个循环来对计数器 i 进行自增并通过表达式 s[i] 选择字符.

---

计算字符串中空格数的函数:

用指针运算代替下标:

</div>

</div>

<!-- slide data-notes="" -->


##### strcpy(字符串复制)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C
strcpy(str2, "abcd");
/* str2 现在包含 "abcd" */
```

```C
strcpy(str1, str2);
/* str1 现在包含 "abcd" */
```

</div>

<div style="flex:1;font-size:0.75em;">

strcpy函数的原型: 

`char *strcpy(char *s1, const char *s2);`

strcpy、strlen、strcat、strcmp 都声明在 `<string.h>` 中, 使用前要 `#include <string.h>`.

strcpy将字符串s2复制到字符串s1中. 

准确地说, strcpy将 ==s2指向的字符串== 复制到 ==s1指向的数组中==. 

strcpy返回s1(指向目标字符串的指针).


调用strcpy, 把字符串"abcd"存储到str2中:

把str2的内容复制到str1:



</div>

</div>

<!-- slide data-notes="" -->


##### strlen(字符串长度)

---

strlen函数的原型: 

`size_t strlen(const char *s);`

size_t是一个typedef名称, 表示C的一种无符号整型.


strlen返回字符串s的长度, 不包括空字符. 例子: 

```C{.line-numbers}
int len;

len = strlen("abc");  /* len is now 3 */
len = strlen("");     /* len is now 0 */
strcpy(str1, "abc");
len = strlen(str1);   /* len is now 3 */
```

---


<!-- slide data-notes="" -->


##### strcat(字符串拼接)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
char str1[20], str2[20];
strcpy(str1, "abc");
strcat(str1, "def");
 /* str1 now contains "abcdef" */
strcpy(str1, "abc");
strcpy(str2, "def");
strcat(str1, str2);
 /* str1 now contains "abcdef" */ 
```

```C{.line-numbers}
char str1[20], str2[20];
strcpy(str1, "abc");
strcpy(str2, "def");
strcat(str1, strcat(str2, "ghi"));
/* str1 now contains "abcdefghi";
   str2 contains "defghi" */
```

</div>

<div style="flex:1;">

strcat函数的原型: 

`char *strcat(char *s1, const char *s2);`

strcat将字符串s2的内容附加到字符串s1的末尾. 

它返回s1(指向结果字符串的指针). strcat示例:

与strcpy一样, strcat返回的值通常会被丢弃. 

左侧最后一段代码使用了返回值:



</div>

</div>

<!-- slide data-notes="" -->


##### strcmp(字符串比较)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C
int strcmp(const char *s1, const char *s2);
```

```C
if (strcmp(str1, str2) < 0)    /* is str1 < str2? */
  …
```

```C
if (strcmp(str1, str2) <= 0) /* is str1 <= str2? */
  …
```

</div>

<div style="flex:1;">

strcmp函数的原型:

strcmp比较字符串s1和s2, 根据s1是小于、等于还是大于s2, 返回一个小于、等于或大于0的值.


检查str1是否小于str2:

检查str1是否小于或等于str2 :

通过选择适当的运算符(<、 <=、 >、 >=、 ==、 !=), 可以测试str1和str2之间的任何可能的关系.

</div>

</div>

<!-- slide data-notes="" -->


##### 程序: 打印一个月的提醒列表

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.5em;">

```
输入日期和提醒: 24 妈妈的生日
输入日期和提醒: 5 18:00 与朋友聚餐
输入日期和提醒: 26 看电影
输入日期和提醒: 7 10:30 看牙医
输入日期和提醒: 12 交作业
输入日期和提醒: 5 上课
输入日期和提醒: 12 上课
输入日期和提醒: 0

日期  提醒
  5 上课
  5 18:00 与朋友聚餐
  7 10:30 看牙医
 12 上课
 12 交作业
 24 妈妈的生日
 26 看电影
```
</div>

<div style="flex:1;">

`remind.c` 维护一个月的每日提醒列表：

用户逐条输入"日期 + 提醒内容"，输入 0 结束，程序按日期排序打印全部提醒。

scanf 用来读日期。

read_line 用来读提醒。

</div>

</div>

<!-- slide data-notes="" -->

##### 程序: 打印一个月的提醒列表 (续)

---

总体策略:

- 读入一系列日期和提醒的组合

- 按顺序存储(按日期排序)

- 显示

排序时要比较日期; 读提醒时要处理空格, 因此日期用 `scanf`, 整行提醒用 `read_line`.

<!-- slide data-notes="" -->


##### 程序: 打印一个月的提醒列表 (参考实现)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.42em;">

```C{.line-numbers}
#define MAX_REMIND 50
#define MSG_LEN 60

char reminders[MAX_REMIND][MSG_LEN + 3];
char day_str[3], msg_str[MSG_LEN + 1];
int day, i, j, num_remind = 0;

for (;;) {
  printf("输入日期和提醒: ");
  scanf("%2d", &day);
  if (day == 0)
    break;
  sprintf(day_str, "%2d", day);
  read_line(msg_str, MSG_LEN + 1);

  for (i = 0; i < num_remind; i++)
    if (strcmp(day_str, reminders[i]) < 0)
      break;
  for (j = num_remind; j > i; j--)
    strcpy(reminders[j], reminders[j - 1]);

  strcpy(reminders[i], day_str);
  strcat(reminders[i], msg_str);
  num_remind++;
}

printf("\n日期  提醒\n");
for (i = 0; i < num_remind; i++)
  printf(" %s\n", reminders[i]);
```

</div>

<div style="flex:1;font-size:0.58em;">

下面是 `main` 的核心代码 (节选), 完整程序见 `code/remind.c`.

- `reminders` 是二维字符数组, 每一行存"日期 + 提醒".
- 日期先用 `sprintf` 格式化成两位字符串, 再与提醒拼接.
- 插入时从后向前腾出位置, 保持按日期有序.
- 使用 `strcmp`、`strcpy`、`strcat`, 需要 `#include <string.h>`.

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/12-strings/code/remind.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 remind.c</a>

</div>

</div>

<!-- slide data-notes="" -->


##### 字符串惯用法: 搜索结尾与复制

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C{.line-numbers}
size_t strlen(const char *s)
{
  size_t n = 0;

  for (; *s != '\0'; s++) {
    n++;
  }

  return n;
}
```

```C{.line-numbers}
size_t strlen(const char *s)
{
  size_t n = 0;

  for (; *s; s++) {
    n++;
  }

  return n;
}
```

</div>

<div style="flex:1;">

n的初始化移到它的声明中:

条件`*s != '\0'`与`*s != 0`相同, 这又与`*s`相同. 

使用这些观察的strlen版本:

字符串复制的惯用法:

```C
while ((*s1++ = *s2++))
  ;
```

先把 `*s2` 赋给 `*s1`, 再让两个指针后移; 赋值为空字符时循环结束.

</div>

</div>

<!-- slide data-notes="" -->


##### 字符串数组

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
char planets[][8] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
```

```C
char *planets[] = {"Mercury", "Venus", "Earth",
                   "Mars", "Jupiter", "Saturn",
                   "Uranus", "Neptune", "Pluto"};
```

</div>

<div style="flex:1;">

存储字符串数组的方法不止一种.

一种选择是使用二维字符数组, 每行一个字符串:

数组中的行数可以省略, 但必须指定列数.

</div>

</div>

<!-- slide data-notes="" -->

##### 字符串数组 (续)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;">

<div class="top-2">
  <img src="figs/14-10.png" height=300px>
</div>

</div>

<div style="flex:1;font-size:0.62em;">

不幸的是, planets 数组浪费了相当多的空间(额外的空字符).

大多数字符串集合都是长字符串和短字符串的混合.

我们需要的是一个参差不齐的数组, 它的行可以有不同的长度.

用指向==字符串的指针的数组==来模拟 C 中的不规则数组:

`char *planets[]` 的每个元素是一个指针, 指向对应字符串字面量; 各行长度可以不同.

</div>

</div>

<!-- slide data-notes="" -->

##### 课堂小测

---

<p style="margin:0.25rem 2rem;"><strong>1. 概念：</strong> <code>"abc"</code> 和 <code>'a'</code> 的区别是什么？<code>"abc"</code> 在内存里占几个字节？</p>

<p style="margin:0.25rem 2rem;"><strong>2. 概念：</strong> <code>char s[] = "hello";</code> 与 <code>char *p = "hello";</code> 有什么区别？</p>

<p style="margin:0.25rem 2rem;"><strong>3. 代码阅读：</strong> 下面的程序输出什么？</p>

<div style="font-size:0.72em;">

```C
char s1[20] = "abc", s2[] = "def";
strcpy(s1, s2);
strcat(s1, "ghi");
printf("%s %d\n", s1, (int)strlen(s1));
```

</div>

<p style="margin:0.25rem 2rem;"><strong>4. 纠错：</strong> 下面的代码有两处错误，找出来并改正。</p>

<div style="font-size:0.72em;">

```C
char s[3];
strcpy(s, "abc");

char *p;
strcpy(p, "hi");
```

</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


