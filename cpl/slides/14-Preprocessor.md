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

## 预处理器


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- <a href="#/HowPreprocessorWorks">预处理器的工作原理</a>

- <a href="#/PreDirectives">预处理指令</a>

- <a href="#/MacroDef">宏定义</a>

- <a href="#/ConditionalCompilation">条件编译</a>

- <a href="#/MiscellaneousDirectives">其他指令</a>



<!-- slide vertical=true data-notes="" -->

##### 介绍

---

`#define`和`#include`这类的指令都是由**预处理器**处理的, 这是一个在编译之前处理C程序的软件. 

C(和C++)因为依赖预处理器而不同于其他的编程语言. 

预处理器是一个强大的工具, 但它也可能是难以发现的错误的来源. 



<!-- slide vertical=true id="HowPreprocessorWorks" data-notes="" -->

##### 预处理器的工作原理

---

预处理器查找以#字符开头的**预处理指令**. 

我们之前遇到过`#define`和`#include`指令. 

`#define`定义了一个宏, 一个代表其他东西的名称, 例如常量. 

通过存储宏的名称及其定义来响应`#define`指令. 

当这个宏被使用时, 预处理器"扩展"宏, 将其替换为定义值. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

`#include`告诉预处理器打开特定文件并将其内容作为正在编译的文件的一部分"包含"进来. 

例如, 代码行

```C
#include <stdio.h>
```

指示预处理器打开名为stdio.h的文件并将其内容加入程序. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

预处理器在编译过程中的作用: 
<div class="top-2">
  <img src="../img/17-1.png">
</div>



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

预处理器的输入是一个 C 程序, 可能包含指令. 

预处理器执行这些指令, 在处理过程中删除它们. 

预处理器的输出直接交给编译器. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

原来的celsius.c程序: 

```C{.line-numbers}
/* Converts a Fahrenheit temperature to Celsius */

#include <stdio.h>
	 
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)
	 
int main(void)
{
  float fahrenheit, celsius;
	 
  printf("Enter Fahrenheit temperature: ");
  scanf("%f", &fahrenheit);
	 
  celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
  printf("Celsius equivalent is: %.1f\n", celsius);
	 
  return 0;
}
```



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

预处理后的程序: 
```C{.line-numbers}
空行
空行
从stdio.h中引入的行
空行
空行
空行
空行
int main(void)
{
  float fahrenheit, celsius;
 
  printf("Enter Fahrenheit temperature: ");
  scanf("%f", &fahrenheit);
 
  celsius = (fahrenheit - 32.0f) * (5.0f / 9.0f);
 
  printf("Celsius equivalent is: %.1f\n", celsius);
 
  return 0;
} 
```



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

预处理器不仅仅执行指令. 

还用单个空格字符替换每个注释. 

一些预处理器更进一步, 删除了不必要的空白字符, 包括每一行开始用于缩进的空格和制表符. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

在 C 语言的早期, 预处理器是一个单独的程序. 

如今, 预处理器往往是编译器的一部分, 它的一些输出可能不一定是 C 代码. 

尽管如此, 将预处理器与编译器分开是很有用的. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

大多数 C 编译器都提供了一种查看预处理器输出的方法. 

某些编译器在指定某个选项时会生成预处理器的输出(GCC使用-E选项). 

其他的编译器会提高一个类似于集成的预处理器的独立程序. 



<!-- slide vertical=true data-notes="" -->

##### 预处理器的工作原理

---

注意: 预处理器对 C 的了解有限. 

因此, 它在执行指令时很可能产生非法的程序. 

对于复杂的程序, 检查预处理器的输出可能有助于定位这种错误. 



<!-- slide vertical=true id="PreDirectives" data-notes="" -->

##### 预处理指令

---

大多数预处理指令属于以下三类之一: 

- **宏定义**. `#define`指令定义一个宏; `#undef`指令删除一个宏定义. 

- **文件包含**. `#include`指令使指定文件的内容包含在程序中. 

- **条件编译**.  `#if`、`#ifdef`、`#ifndef`、`#elif`、`#else`和`#endif`指令允许将文本块包含在程序中或从程序中排除.  



<!-- slide vertical=true data-notes="" -->

##### 预处理指令

---

有几条规则适用于所有指令. 

- 指令都以#符号开始. 

    `#`符号不必位于行首, 只要它前面只有空格即可. 

在指令的符号之间可以插入任意数量的空格或水平制表符. 例子: 
    
```C
#   define     N     100
```



<!-- slide vertical=true data-notes="" -->

##### 预处理指令

---

**指令总是在第一个换行符处结束, 除非明确地指明继续. **

    要将指令延续到下一行, 必须以\字符结束当前行: 
```C
#define DISK_CAPACITY (SIDES *             \
                       TRACKS_PER_SIDE *   \
                       SECTORS_PER_TRACK * \
                       BYTES_PER_SECTOR)
```



<!-- slide vertical=true data-notes="" -->

##### 预处理指令

---

**指令可以出现在程序的任何位置. **

    但通常将`#define`和`#include`指令放在文件的开头, 其他指令放在后面. 

**注释可以与指令放在同一行. **

    在宏定义的末尾添加注释是一种很好的做法: 
    #define FREEZING_PT 32.0f /* freezing point of water */



<!-- slide vertical=true data-notes="" -->

##### 宏定义

---

从第 2 章开始使用的宏被称为简单的宏, 因为它们没有参数. 

预处理器还支持带参数的宏. 



<!-- slide vertical=true id="MacroDef" data-notes="" -->

##### 简单的宏

---

简单的宏(对象式宏)的定义: 

```C
#define 标识符 替换列表
```

替换列表是预处理标记序列. 可以包括标识符、关键字、数字常量、字符常量、字符串字面量、操作符和排列. 

无论标识符稍后出现在文件中的何处, 预处理器都会用替换列表替换它. 



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

宏定义中的任何额外符号都将成为替换列表的一部分. 

将=符号放在宏定义中是一个常见错误: 
```C
#define N = 100  /*** WRONG ***/
…
int a[N];        /* becomes int a[= 100]; */
```



<!-- slide vertical=true data-notes="" -->



##### 简单的宏

---

用分号结束宏定义是另一个常见的错误: 

```C
#define N 100;  /*** WRONG ***/
…
int a[N];       /* becomes int a[100;]; */
```

编译器可以检测由宏定义中的额外符号引起的大多数错误. 

但是, 编译器只会将宏的每次使用标记为不正确, 而不会直接找到错误的根源——宏定义. 



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

简单的宏主要用于定义"明示常量"——代表数字、字符和字符串值的名称: 

```C
#define STR_LEN 80
#define TRUE    1
#define FALSE   0
#define PI      3.14159
#define CR      '\r'
#define EOS     '\0'
#define MEM_ERR "Error: not enough memory"
```



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

使用#define为常量创建名称的优点: 

- **程序更易读. **宏的名称可以帮助读者理解常量的含义. 

- **程序更易于修改. **可以通过修改单个宏定义来更改整个程序中常量的值. 

- **可以帮助避免前后不一致或键盘输入错误. **如果像 3.14159 这样的数字常量在程序中多次出现, 很可能偶尔会被意外写成 3.1416 或 3.14195 . 



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

简单的宏还有其他用途. 

**对C语法做小的修改**

宏可以作为 C 符号的替代名称: 

```C
#define BEGIN {
#define END   }
#define LOOP for (;;)
```

改变C的语法通常不是一个好主意, 因为它会使程序更难被其他人理解. 



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

**对类型重命名**

第 5 章的一个例子: 

```C
#define BOOL int
```
类型定义是更好的选择. 

**控制条件编译**

宏在控制条件编译中发挥着重要作用. 

可以表明"调试模式"的宏: 

```C
#define DEBUG
```



<!-- slide vertical=true data-notes="" -->

##### 简单的宏

---

当宏用作常量时, C 程序员习惯上将其名称中的所有字母大写. 

但是, 对于如何将用于其他目的的宏大写并没有达成共识. 

- 一些程序员喜欢全部使用大写字母来引起对宏的注意. 

- 其他人更喜欢小写名称, 遵循 K&R 的风格. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

带参数的宏(函数式宏)的定义: 

`#define 标识符(x1, x2, …, xn) 替换列表`

x1, x2, …, xn是标识符(宏的参数). 

参数可以根据需要在替换列表中出现多次. 

在宏的名称和左括号之间没有空格. 

如有空格, 预处理器会将(x1, x2, …, xn)视为替换列表的一部分. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

当预处理器遇到带参数的宏的定义时, 它会将定义存储起来以备后用. 

在程序后面出现对表单标识符(y1, y2, ..., yn)的宏调用, 预处理器都会将其替换为replacement-list , 将y1替换为x1, 将y2替换为x2, 依此类推向前. 

带参数的宏通常用作简单的函数. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

带参数的宏的示例: 

```C
#define MAX(x,y)   ((x)>(y)?(x):(y))
#define IS_EVEN(n) ((n)%2==0)
```

这些宏的调用: 

```C
i = MAX(j+k, m-n);
if (IS_EVEN(i)) i++;
```

宏替换后的相同行: 
```C
i = ((j+k)>(m-n)?(j+k):(m-n));
if (((i)%2==0)) i++; 
```



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

一个更复杂的类函数宏: 

```C
#define TOUPPER(c) \
('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
```

<ctype.h>头文件提供了一个类似的名为toupper的函数. 

带参数的宏可能有一个空的参数列表: 

```C
#define getchar() getc(stdin)
```

空参数列表并不是真正需要的, 但它使getchar类似于一个函数. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

使用带参数的宏而不是真正的函数有几个优点: 

- 该程序可能会稍微快一些. 函数调用在程序执行期间通常需要一些开销, 但宏调用不需要. 

- 宏是"通用的". 宏可以接受任何类型的参数, 前提是生成的程序是有效的. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

带参数的宏也有缺点. 编译后的代码通常会更大. 

每个宏调用都会增加源程序的大小(因此也会增加编译代码). 

嵌套宏调用时, 问题变得更加复杂: 

```C
n = MAX(i, MAX(j, k));
```

预处理后的语句: 

```C
n = ((i)>(((j)>(k)?(j):(k)))?(i):(((j)>(k)?(j):(k))));
```



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

参数没有经过类型检查. 

调用函数时, 编译器会检查每个参数是否具有适当的类型. 

预处理器不会检查宏参数, 也不会对其进行转换. 

不可能有一个指向宏的指针. 

C 允许指向函数的指针, 这是一个有用的概念. 

宏在预处理期间被删除, 因此没有相应的"指向宏的指针"的概念. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

宏可以多次评估其参数. 

如果参数有副作用, 可能会发生意外行为: 

`n = MAX(i++, j);`

预处理后的同一行: 

`n = ((i++)>(j)?(i++):(j));`

如果i大于j , 那么i将(错误地)增加两次, 并且n将被分配一个意外的值. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

由多次评估宏参数引起的错误很难找到, 因为宏调用看起来与函数调用相同. 

更糟糕的是, 宏可能在大多数情况下都能正常工作, 只有某些具有副作用的参数才会失败. 

为了自我保护, 避免争论中的副作用是个好主意. 



<!-- slide vertical=true data-notes="" -->

##### 带参数的宏

---

带参数的宏可用作经常重复的代码段的模式. 

一个更容易显示整数的宏: 

`#define PRINT_INT(n) printf("%d\n", n)`

预处理器将
```C
PRINT_INT(i/j);
```

转为
```C
printf("%d\n", i/j);
```



<!-- slide vertical=true data-notes="" -->

##### `#`运算符

---

宏定义可能包含两个特殊运算符`#`和`##`. 

编译器无法识别这两个运算符; 相反, 它们是在预处理期间执行的. 

`#`运算符将宏参数转换为字符串文字; 它只能出现在带参数的宏的替换列表中. 

`#`执行的操作称为"字符串化". 



<!-- slide vertical=true data-notes="" -->

##### `#`运算符

---

`#`有很多用途; 让我们只考虑一个. 

假设我们决定在调试期间使用PRINT_INT宏作为打印整数变量和表达式值的便捷方式. 

`#`运算符使PRINT_INT可以标记它打印的每个值. 



<!-- slide vertical=true data-notes="" -->

##### `#`运算符

---

我们的新版本PRINT_INT: 

`#define PRINT_INT(n) printf(#n " = %d\n", n)`

调用
`PRINT_INT(i/j);`
会变成
`printf("i/j" " = %d\n", i/j);`

编译器自动连接相邻的字符串文字, 所以这个语句相当于
`printf("i/j = %d\n", i/j);`



<!-- slide vertical=true data-notes="" -->

##### `##`运算符

---

`##`运算符可以将两个标记"粘贴"在一起以形成一个标记. 

如果操作数之一是宏参数, 则在参数被相应参数替换后进行粘贴. 



<!-- slide vertical=true data-notes="" -->

##### `##`运算符

---

使用`##`运算符的宏: 

`#define MK_ID(n) i##n`

MK_ID三次的声明: 

`int MK_ID(1), MK_ID(2), MK_ID(3);`

预处理后的声明: 
`int i1, i2, i3;`



<!-- slide vertical=true data-notes="" -->

##### `##`运算符

---

`##`运算符有多种用途. 

考虑定义一个行为类似于前面描述的MAX宏的max函数的问题. 

单个max函数通常是不够的, 因为它只适用于一种类型的参数. 

相反, 我们可以编写一个扩展为max函数定义的宏. 

宏的参数将指定参数的类型和返回值. 



<!-- slide vertical=true data-notes="" -->

##### `##`运算符

---

如果我们使用宏创建多个名为max的函数, 程序将无法编译. 

为此, 使用##运算符可为max的每个版本创建一个不同的名称: 

```C{.line-numbers}
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
  return x > y ? x : y;         \
}

// 调用此宏: 
GENERIC_MAX(float)
```

```C
float float_max(float x, float y) { return x > y ? x : y; }
```



<!-- slide vertical=true data-notes="" -->

##### 宏的一般属性

---

有几条规则适用于简单宏和带参数的宏. 

宏的替换列表可能包含对其他宏的调用. 例子:

```C
#define PI 3.14159
#define TWO_PI (2*PI)
```

当它稍后在程序中遇到TWO_PI时, 预处理器将其替换为(2*PI). 

然后预处理器重新扫描替换列表以查看它是否包含其他宏的调用. 



<!-- slide vertical=true data-notes="" -->

##### 宏的一般属性

---

预处理器仅替换整个标记. 

嵌入在标识符、字符常量和字符串文字中的宏名称将被忽略. 
```C
#define SIZE 256

int BUFFER_SIZE;

if (BUFFER_SIZE > SIZE)
  puts("Error: SIZE exceeded");
```

预处理后: 
```C
int BUFFER_SIZE;

if (BUFFER_SIZE > 256)
  puts("Error: SIZE exceeded");
```



<!-- slide vertical=true data-notes="" -->

##### 宏的一般属性

---

宏定义通常会一直有效, 直到它出现在文件的末尾. 

宏不遵守正常的范围规则. 

函数体内定义的宏不是该函数的本地宏; 它保持定义到文件结束. 

除非新定义与旧定义相同, 否则宏不得定义两次. 

间距的差异是允许的, 但宏的替换列表(和参数, 如果有的话)中的标记必须相同. 



<!-- slide vertical=true data-notes="" -->

##### 宏的一般属性

---

`#undef`指令可能"未定义"宏. 

`#undef`指令的形式为

`#undef` 标识符

其中标识符是宏名称. 

`#undef`的一种用途是删除宏的现有定义, 以便为其赋予新定义. 



<!-- slide vertical=true data-notes="" -->

##### 宏定义中的括号

---

宏定义中的替换列表通常需要括号以避免意外结果. 

如果宏的替换列表包含运算符, 请始终将替换列表括在括号中: 
`#define TWO_PI (2*3.14159)`

此外, 每次出现在替换列表中时, 在每个参数周围加上括号: 
`#define SCALE(x) ((x)*10)`

如果没有括号, 我们不能保证编译器会将替换列表和参数视为整个表达式. 



<!-- slide vertical=true data-notes="" -->

##### 宏定义中的括号

---

一个说明需要在宏的替换列表周围放置括号的示例: 
```C
#define TWO_PI 2*3.14159
/* needs parentheses around replacement list */

conversion_factor = 360/TWO_PI;
```

语句在预处理后变成
```C
conversion_factor = 360/2*3.14159;
```

除法将在乘法之前执行. 



<!-- slide vertical=true data-notes="" -->

##### 宏定义中的括号

---

宏的替换列表中每次出现的参数也需要括号: 
```C
#define SCALE(x) (x*10)
/* needs parentheses around x */

j = SCALE(i+1);
```

语句在预处理后变成

```C
j = (i+1*10);
```



<!-- slide vertical=true data-notes="" -->

##### 创建更长的宏

---

逗号运算符可用于创建更复杂的宏, 它允许我们将替换列表设为一系列表达式. 

读取字符串然后打印它的宏: 
```C
#define ECHO(s) (gets(s), puts(s))
```

get和puts的调用是表达式, 因此使用逗号运算符组合它们是完全合法的. 

我们可以像调用函数一样调用ECHO: 
```C
ECHO(str);  /* becomes (gets(str), puts(str)); */
```



<!-- slide vertical=true data-notes="" -->

##### 创建更长的宏

---

使用大括号的ECHO的另一种定义: 
```C
#define ECHO(s) { gets(s); puts(s); }

if (echo_flag) 
 ECHO(str);
else 
 gets(str);
```

替换ECHO会得到以下结果: 
```C
if (echo_flag) 
 { gets(str); puts(str); };
else 
 gets(str);
```



<!-- slide vertical=true data-notes="" -->

##### 创建更长的宏

---

编译器将前两行视为完整的if语句: 
```C
if (echo_flag) 
 { gets(str); puts(str); }
```

它将后面的分号视为空语句并为else子句生成错误消息, 因为它不属于任何if. 

我们可以通过记住不要在每次调用ECHO后加上分号来解决这个问题, 但是这样程序就会看起来很奇怪. 



<!-- slide vertical=true data-notes="" -->

##### 创建更长的宏

---

逗号运算符解决了ECHO的这个问题, 但不是所有的宏. 

如果一个宏需要包含一系列语句, 而不仅仅是一系列表达式, 那么逗号运算符就没有帮助. 

解决方案是将语句包装在条件为 false 的do循环中: 

```C
do { … } while (0)
```

请注意, do语句末尾需要一个分号. 



<!-- slide vertical=true data-notes="" -->

##### 创建更长的宏

---

ECHO宏的修改版本: 
```C
#define ECHO(s)     \
        do {        \
          gets(s);  \
          puts(s);  \
        } while (0)
```

使用ECHO时, 后面必须跟一个分号, 完成do语句: 

```C
ECHO(str);
/* becomes */

   do { gets(str); puts(str); } while (0);
```



<!-- slide vertical=true data-notes="" -->

##### 预定义宏

---

C 有几个预定义的宏, 每个宏都表示整数常量或字符串字面量. 

__DATE__和__TIME__宏标识程序的编译时间. 使用__DATE__和__TIME__的示例: 

```C
printf("Wacky Windows (c) 2010 Wacky Software, Inc.\n");
printf("Compiled on %s at %s\n", __DATE__, __TIME__);
```

这些语句产生的输出: 
```
Wacky Windows (c) 2010 Wacky Software, Inc.
Compiled on Dec 23 2010 at 22:18:48
```

此信息有助于区分同一程序的不同版本. 



<!-- slide vertical=true data-notes="" -->

##### 预定义宏

---

我们可以使用__LINE__和__FILE__宏来帮助定位错误. 

一个可以帮助确定除以零的位置的宏: 

```C
#define CHECK_ZERO(divisor) \
  if (divisor == 0) \ 
    printf("*** Attempt to divide by zero on line %d " \
           "of file %s ***\n", __LINE__, __FILE__)
```

CHECK_ZERO宏将在除法之前调用: 
```C
CHECK_ZERO(j);
k = i / j;
```



<!-- slide vertical=true data-notes="" -->

##### 预定义宏

---

如果j恰好为零, 将打印以下形式的消息: 
```C
*** Attempt to divide by zero on line 9 of file foo.c ***
```

像这样的错误检测宏非常有用. 

assert的通用错误检测宏. 

剩余的预定义宏名为__STDC__ . 

如果编译器符合 C 标准(C89 或 C99), 则此宏存在并且值为 1. 



<!-- slide vertical=true data-notes="" -->

##### C99 中的其他预定义宏

---

C99 提供了一些额外的预定义宏. 

如果编译器是托管实现, 则 __STDC__HOSTED__ 宏表示常量1 . 否则, 宏的值为 0. 

的实现由编译器和执行 C 程序所需的其他软件组成. 

托管实现必须接受任何符合 C99 标准的程序. 

一个独立的实现不必编译使用复杂类型或标准头文件的程序, 而不是一些最基本的. 



<!-- slide vertical=true data-notes="" -->

##### C99 中的其他预定义宏

---

__STDC__VERSION__宏提供了一种检查编译器识别哪个版本的 C 标准的方法. 

- 如果编译器符合 C89 标准, 包括修正 1, 则值为199409L . 

- 如果编译器符合 C99 标准, 则值为199901L . 



<!-- slide vertical=true data-notes="" -->

##### C99 中的其他预定义宏

---

C99 编译器将定义最多三个附加宏, 但前提是编译器满足某些要求: 

- 如果编译器根据 IEC 60559 执行浮点运算, 则定义了__STDC_IEC_559__ (并且值为 1). 

- 如果编译器根据 IEC 60559 执行复数运算, 则定义了__STDC_IEC_559_COMPLEX__ (并且值为 1). 

- __STDC_ISO_10646__定义为yyyymm L , 如果宽字符由 ISO/IEC 10646 中的代码表示(修订为指定年份和月份). 



<!-- slide vertical=true data-notes="" -->

##### 空宏参数 (C99)

---

C99 允许宏调用中的任何或所有参数为空. 

这样的调用将包含与正常调用相同数量的逗号. 

无论相应的参数名称出现在替换列表中的何处, 它都不会被任何内容替换. 



<!-- slide vertical=true data-notes="" -->

##### 空宏参数 (C99)

---

```C
#define ADD(x,y) (x+y)
```

```C
i = ADD(j,k);
/* 预处理后的语句变成 */
i = (j+k);
```

```C
i = ADD(,k);
/* 变成 */
i = (+k);
```



<!-- slide vertical=true data-notes="" -->

##### 空宏参数 (C99)

---

当空参数是#或##运算符的操作数时, 适用特殊规则. 

#运算符将空参数"字符串化", 则结果为"" (空字符串): 

```C
#define MK_STR(x) #x
…
char empty_string[] = MK_STR();
```

预处理后的声明: 
`char empty_string[] = "";`



<!-- slide vertical=true data-notes="" -->

##### 空宏参数 (C99)

---

##运算符的参数之一为空, 则将其替换为不可见的"placemarker"标记. 

将普通标记与地标标记连接会产生原始标记(地标消失). 

如果连接两个地标标记, 则结果是单个地标. 

一旦宏扩展完成, 地标标记就会从程序中消失. 



<!-- slide vertical=true data-notes="" -->

##### 空宏参数 (C99)

---

例子: 
```C
#define JOIN(x,y,z) x##y##z
…
int JOIN(a,b,c), JOIN(a,b,), JOIN(a,,c), JOIN(,,c);
```

预处理后的声明: 
```C
int abc, ab, ac, c;
```

缺少的参数被位置标记标记替换, 然后在与任何非空参数连接时消失. 

JOIN宏的所有三个参数甚至都可能丢失, 这将产生一个空结果. 



<!-- slide vertical=true data-notes="" -->

##### 具有可变数量参数的宏 (C99)

---

C99 允许使用无限数量的参数的宏. 

这种宏可以将其参数传递给接受可变数量参数的函数. 

例子: 
```C
#define TEST(condition, ...) ((condition)? \
printf("通过测试: %s\n", #condition): \
printf(__VA_ARGS__))
```

...标记(省略号)位于参数列表的末尾, 前面是普通参数(如果有). 

__VA_ARGS__是一个特殊的标识符, 表示对应于省略号的所有参数. 



<!-- slide vertical=true data-notes="" -->

##### 具有可变数量参数的宏 (C99)

---

TEST宏的示例: 
```C
TEST(voltage <= max_voltage,
     "Voltage %d exceeds %d\n", voltage, max_voltage);

```

预处理器输出(重新格式化以提高可读性): 

```C
((voltage <= max_voltage)?
  printf("Passed test: %s\n", "voltage <= max_voltage"):
  printf("Voltage %d exceeds %d\n", voltage, max_voltage));
```

程序将显示消息
`Passed test: voltage <= max_voltage`
如果电压不超过max_voltage . 

否则, 它将显示电压和max_voltage的值: 
`Voltage 125 exceeds 120`



<!-- slide vertical=true data-notes="" -->

##### __func__标识符(C99)

---

__func__标识符的行为类似于存储当前执行函数名称的字符串变量. 

效果与每个函数在其主体的开头包含以下声明相同: 
```C
static const char __func__[] = "function-name";
```
其中function-name是函数的名称. 



<!-- slide vertical=true data-notes="" -->

##### __func__标识符(C99)

---

调试依赖__func__标识符的宏: 
```C
#define FUNCTION_CALLED() printf("%s called\n", __func__);
#define FUNCTION_RETURNS() printf("%s returns\n", __func__);
```

这些宏可用于跟踪函数调用: 
```C
void f(void)
{
  FUNCTION_CALLED();   /* displays "f called" */
  …
  FUNCTION_RETURNS();  /* displays "f returns" */
}
```

__func__的另一个用途: 它可以传递给一个函数, 让它知道调用它的函数的名称. 



<!-- slide vertical=true data-notes="" -->

##### 条件编译

---

C 预处理器识别许多支持条件编译的指令. 

此功能允许根据预处理器执行的测试结果包含或排除一段程序文本. 



<!-- slide vertical=true id="ConditionalCompilation" data-notes="" -->

##### #if和#endif指令

---

假设我们正在调试一个程序. 

我们希望程序打印某些变量的值, 所以我们在程序的关键部分调用printf . 

一旦我们找到了错误, 最好保留printf调用, 以防我们以后需要它们. 

条件编译允许我们保留调用, 但让编译器忽略它们. 



<!-- slide vertical=true data-notes="" -->

##### #if和#endif指令

---

第一步是定义一个宏并给它一个非零值: 
```C
#define DEBUG 1
```

#if - #endif对包围每组printf调用: 
```C
#if DEBUG
printf("Value of i: %d\n", i);
printf("Value of j: %d\n", j);
#endif
```



<!-- slide vertical=true data-notes="" -->

##### #if和#endif指令

---

在预处理期间,  #if指令将测试DEBUG的值. 

由于它的值不为零, 预处理器将在程序中保留两个printf调用. 

如果我们将DEBUG的值更改为零并重新编译程序, 预处理器将从程序中删除所有四行. 

#if - #endif块可以留在最终程序中, 如果出现任何问题, 可以在以后生成诊断信息. 



<!-- slide vertical=true data-notes="" -->

##### #if和#endif指令

---

#if和#endif指令的一般形式: 
```C
#if constant-expression
#endif
```

当预处理器遇到#if指令时, 它会计算常量表达式. 

如果表达式的值为零, 则#if和#endif之间的行将在预处理期间从程序中删除. 

否则, #if和#endif之间的行将保留. 



<!-- slide vertical=true data-notes="" -->

##### #if和#endif指令

---

#if指令将未定义的标识符视为值为 0 的宏. 

如果我们忽略定义DEBUG, 测试
```C
#if DEBUG
```
将失败(但不会生成错误消息). 

测试
```C
#if !DEBUG
```
将会成功. 



<!-- slide vertical=true data-notes="" -->

##### 定义的运算符

---

预处理器支持三个运算符: #、##和defined. 

当应用于标识符时, 如果标识符是当前定义的宏, 则定义生成值 1; 否则它会产生 0. 

定义的运算符通常与#if指令一起使用. 



<!-- slide vertical=true data-notes="" -->

##### 定义的运算符

---

例子: 
```C
#if defined(DEBUG)
…
#endif
```

DEBUG被定义为宏时, 才会包含#if和#endif之间的行. 

DEBUG周围的括号不是必需的: 
```C
#if defined DEBUG
```

没有必要给DEBUG一个值: 
```C
#define DEBUG
```



<!-- slide vertical=true data-notes="" -->

##### #ifdef和#ifndef指令

---

#ifdef指令测试标识符当前是否定义为宏: 
```C
#ifdef identifier
```

效果是一样的
```C
#if defined(identifier)
```

#ifndef指令测试标识符当前是否未定义为宏: 
```C
#ifndef identifier
```

效果是一样的
```C
#if !defined(identifier)
```

<!-- slide vertical=true data-notes="" -->



##### #elif和#else指令

---

#if、#ifdef和#ifndef块可以像普通if语句一样嵌套. 

发生嵌套时, 最好使用随着嵌套级别的增加而增加的缩进量. 

一些程序员在每个结束#endif上添加注释, 以指示匹配的#if测试的条件: 
```C
#if DEBUG
…
#endif /* DEBUG */
```

<!-- slide vertical=true data-notes="" -->



##### `#elif`和`#else`指令

---

`#elif`和`#else`可以与`#if`、`#ifdef`或`#ifndef`结合使用来测试一系列条件: 

```C{.line-numbers}
#if expr1
Lines to be included if expr1 is nonzero
#elif expr2
Lines to be included if expr1 is zero but expr2 is nonzero
#else
Lines to be included otherwise
#endif
```

任意数量的`#elif`指令(但最多一个`#else`)可以出现在#if和#endif之间. 



<!-- slide vertical=true data-notes="" -->

##### 条件编译的使用

---

条件编译除了调试之外还有其他用途. 

编写可移植到多台机器或操作系统的程序. 

例子: 
```C
#if defined(WIN32)
…
#elif defined(MAC_OS)
…
#elif defined(LINUX)
…
#endif
```



<!-- slide vertical=true data-notes="" -->

##### 条件编译的使用

---

编写可以用不同的编译器编译的程序. 

__STDC__宏的示例: 
```C
#if __STDC__
Function prototypes
#else
Old-style function declarations
#endif
```

如果编译器不符合 C 标准, 则使用旧式函数声明而不是函数原型. 



<!-- slide vertical=true data-notes="" -->

##### 条件编译的使用

---

为宏提供默认定义. 

条件编译可以检查当前是否定义了宏, 如果没有, 则给它一个默认定义: 
```C
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif
```



<!-- slide vertical=true data-notes="" -->

##### 条件编译的使用

---

暂时禁用包含注释的代码. 

/* … */注释不能用于"注释掉"已经包含/* … */注释的代码. 
可以使用 #if 指令代替: 

```C
#if 0
Lines containing comments
#endif
```



<!-- slide vertical=true data-notes="" -->

##### 条件编译的使用

---

第 15 章讨论了条件编译的另一个常见用途: 保护头文件不被多次包含. 



<!-- slide vertical=true data-notes="" -->

##### 其他指令

---

#error、#line和#pragma指令比我们已经研究过的更专业. 

这些指令的使用频率要低得多. 



<!-- slide vertical=true id="MiscellaneousDirectives" data-notes="" -->

##### #error指令

---

#error指令的形式: 
`#error message`
message是任何标记序列. 

如果预处理器遇到#error指令, 它会打印一条错误消息, 其中必须包含message . 

如果处理了#error指令, 一些编译器会立即终止编译, 而不尝试查找其他错误. 



<!-- slide vertical=true data-notes="" -->

##### #error指令

---

#error指令经常与条件编译结合使用. 

使用#error指令测试int类型最大值的示例: 
```C
#if INT_MAX < 100000
#error int type is too small
#endif
```



<!-- slide vertical=true data-notes="" -->

##### #error指令

---

#error指令经常出现在#if - #elif - #else系列的#else部分: 
```C
#if defined(WIN32)
…
#elif defined(MAC_OS)
…
#elif defined(LINUX)
…
#else
#error No operating system specified
#endif
```



<!-- slide vertical=true data-notes="" -->

##### #line指令

---

#line指令用于改变程序行的编号方式. 

#line指令的第一种形式: 
`#line n`
程序中的后续行将编号为n、n + 1、n + 2 等等. 

#line指令的第二种形式: 
`#line n "file"`
假定后续行来自file, 行号从n开始. 



<!-- slide vertical=true data-notes="" -->

##### #line指令

---

#line指令更改__LINE__宏的值(可能还有__FILE__ ) . 

在生成错误消息时会使用#line指令中的信息. 

假设以下指令出现在foo.c的开头: 
`#line 10 "bar.c"`
foo.c的第 5 行检测到错误, 则该消息将引用文件bar.c的第 13 行. 

#line指令主要由生成 C 代码作为输出的程序使用. 



<!-- slide vertical=true data-notes="" -->

##### #line指令

---

最著名的例子是yacc (Yet Another Compiler-Compiler), 它是一个 UNIX 实用程序, 可以自动生成编译器的一部分. 

程序员准备一个包含yacc信息以及 C 代码片段的文件. 

yacc从此文件生成一个 C 程序y.tab.c , 其中包含程序员提供的代码. 

通过插入#line指令,  yacc 诱使编译器相信代码来自原始文件. 

y.tab.c编译期间产生的错误消息将引用原始文件中的行. 



<!-- slide vertical=true data-notes="" -->

##### #pragma指令

---

#pragma指令提供了一种向编译器请求特殊行为的方法. 

#pragma指令的形式: 
`#pragma tokens`

#pragma指令可以非常简单(单个标记), 也可以更复杂: 
`#pragma data(heap_size => 1000, stack_size => 2000)`



<!-- slide vertical=true data-notes="" -->

##### #pragma指令

---

`#pragma`指令中可能出现的命令集对于每个编译器都是不同的. 

预处理器必须忽略任何包含无法识别命令的`#pragma`指令; 不允许给出错误信息. 

在 C89 中, 没有标准的编译指示——它们都是实现定义的. 

C99 有三个标准 pragma, 它们都使用STDC作为`#pragma`之后的第一个标记. 



<!-- slide vertical=true data-notes="" -->

##### `_Pragma`运算符 (C99)

---

C99 引入了`_Pragma`运算符, 它与`#pragma`指令一起使用. 

_Pragma表达式具有以下形式
`_Pragma ( string-literal )`

当遇到这样的表达式时, 预处理器会"去字符串化"字符串文字: 
- 字符串周围的双引号被删除. 
- \\"替换为". 
- \\\替换为\. 



<!-- slide vertical=true data-notes="" -->

##### `_Pragma`运算符 (C99)

---

然后将生成的标记视为出现在#pragma指令中. 

例如, 写作
`_Pragma("data(heap_size => 1000, stack_size => 2000)")`

和写一样
`#pragma data(heap_size => 1000, stack_size => 2000)`



<!-- slide vertical=true data-notes="" -->

##### `_Pragma`运算符 (C99)

---

`_Pragma`运算符让我们可以解决预处理指令不能生成另一个指令的事实. 

`_Pragma`是一个运算符, 而不是指令, 因此可以出现在宏定义中. 

这使得宏扩展可以留下`#pragma`指令. 



<!-- slide vertical=true data-notes="" -->

##### `_Pragma`运算符 (C99)

---

使用_Pragma运算符的宏: 
`#define DO_PRAGMA(x) _Pragma(#x)`

宏的调用: 
`DO_PRAGMA(GCC dependency "parse.y")`

展开后的结果: 
`#pragma GCC dependency "parse.y"`

传递给DO_PRAGMA的标记被字符串化为"GCC dependency \"parse.y\"" . 

`_Pragma`运算符对该字符串进行去字符串化, 生成`#pragma`指令. 


