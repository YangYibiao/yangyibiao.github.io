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

## 输入输出


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- <a href="#/Streams">流</a>

- <a href="#/FileOp">文件操作</a>

- <a href="#/FormattedIO">格式化的输入输出</a>

- <a href="#/CharIO">字符的输入输出</a>

- <a href="#/LineIO">行的输入输出</a>

- <a href="#/BlockIO">块的输入输出</a>

- <a href="#/FilePosition">文件定位</a>

- <a href="#/StringIO">字符串的输入输出</a>

<!-- slide vertical=true data-notes="" -->



##### 介绍

---

C 的输入/输出库是标准库中最大和最重要的部分. 

<stdio.h>标头是输入/输出函数的主要存储库, 包括printf、scanf、putchar、getchar、puts和gets. 

本章提供有关这六个功能的更多信息. 

它还引入了许多新功能, 其中大部分处理文件. 

<!-- slide vertical=true data-notes="" -->



##### 介绍

---

要涵盖的主题: 
- Streams,  FILE类型, 输入输出重定向, 文本文件和二进制文件的区别
- 专门设计用于文件的函数, 包括打开和关闭文件的函数
- 执行"格式化"输入/输出的函数
- 读取和写入未格式化数据(字符、行和块)的函数
- 对文件的随机访问操作
- 写入字符串或从字符串读取的函数

<!-- slide vertical=true data-notes="" -->



##### 介绍

---

在 C99 中, 一些 I/O 函数属于<wchar.h>头文件. 

<wchar.h>函数处理宽字符而不是普通字符. 

<stdio.h>中读取或写入数据的函数称为字节输入/输出函数. 

<wchar.h>中的类似函数称为宽字符输入/输出函数. 

<!-- slide vertical=true data-notes="" -->



##### 流

---

在 C 中, 术语流表示任何输入源或任何输出目的地. 

许多小程序从一个流(键盘)获取所有输入, 并将其所有输出写入另一个流(屏幕). 

较大的程序可能需要额外的流. 

流通常表示存储在各种媒体上的文件. 

但是, 它们可以很容易地与网络端口和打印机等设备相关联. 

<!-- slide id="Stream" vertical=true data-notes="" -->



##### 文件指针

---

访问流是通过文件指针完成的, 该指针具有FILE类型 * .

FILE类型在< stdio.h>中声明. 

某些流由具有标准名称的文件指针表示. 

可以根据需要声明其他文件指针:  
`FILE *fp1, *fp2;`

<!-- slide vertical=true data-notes="" -->



##### 标准流和重定向

---

<stdio.h>提供了三个标准流: 
文件指针 流 默认含义
stdin 标准 输入键盘
stdout 标准 输出画面
stderr 标准 错误屏幕

这些流已准备好使用——我们不声明它们, 也不打开或关闭它们. 

<!-- slide vertical=true data-notes="" -->



##### 标准流和重定向

---

前面章节中讨论的 I/O 函数从stdin获取输入并将输出发送到stdout. 

许多操作系统允许通过称为重定向的机制更改这些默认含义. 

<!-- slide vertical=true data-notes="" -->



##### 标准流和重定向

---

强制程序从文件而不是键盘获取输入的典型技术:  
`demo <in.dat`  
这种技术称为输入重定向. 

输出重定向类似:  
`demo >out.dat`  
所有写入标准输出的数据现在都将进入out.dat文件, 而不是出现在屏幕上. 

<!-- slide vertical=true data-notes="" -->



##### 标准流和重定向

---

输入重定向和输出重定向可以结合使用:  
`demo <in.dat >out.dat`

<和>字符不必与文件名相邻, 并且重定向文件的列出顺序无关紧要:  
`demo <in.dat> out.dat`  
`demo >out.dat <in.dat`

<!-- slide vertical=true data-notes="" -->



##### 标准流和重定向

---

输出重定向的一个问题是写入标准输出的所有内容都被放入一个文件中. 

将错误消息写入stderr而不是stdout可以保证即使stdout已被重定向, 它们也会出现在屏幕上. 

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

<stdio.h>支持两种文件: 文本文件和二进制文件. 

文本文件中的字节代表字符, 允许人们检查或编辑文件. 
- C 程序的源代码存储在文本文件中. 

在二进制文件中, 字节不一定代表字符. 
- 字节组可能代表其他类型的数据, 例如整数和浮点数. 
- 可执行的 C 程序存储在二进制文件中. 

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

文本文件具有二进制文件不具备的两个特征. 

文本文件被分成几行. 文本文件中的每一行通常以一个或两个特殊字符结尾. 
- Windows: 回车符( '\x0d')后跟换行符( '\x0a')
- UNIX 和更新版本的 Mac OS: 换行符
- 旧版本的 Mac OS: 回车符

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

文本文件可能包含一个特殊的"文件结束"标记. 
- 在 Windows 中, 标记是'\x1a'(Ctrl-Z), 但这不是必需的. 
- 大多数其他操作系统, 包括 UNIX, 没有特殊的文件结束字符. 

在二进制文件中, 没有行尾或文件结束标记；所有字节都被平等对待. 

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

数据写入文件时, 可以以文本形式或二进制形式存储. 

将数字 32767 存储在文件中的一种方法是以文本形式将其写入字符 3、2、7、6 和 7: 
<div class="top-2">
  <img src="../img/21-1.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

另一种选择是以二进制形式存储数字, 这只需两个字节: 
<div class="top-2">
  <img src="../img/21-2.png">
</div>
  
以二进制存储数字通常可以节省空间. 

<!-- slide vertical=true data-notes="" -->



##### 文本文件与二进制文件

---

从文件读取或写入文件的程序必须考虑它是文本还是二进制文件. 

在屏幕上显示文件内容的程序可能会假设它是一个文本文件. 

另一方面, 文件复制程序不能假定要复制的文件是文本文件. 
- 如果是这样, 则不会完全复制包含文件结尾字符的二进制文件. 

当我们不能确定一个文件是文本文件还是二进制文件时, 假设它是二进制文件会更安全. 

<!-- slide vertical=true data-notes="" -->



##### 文件操作

---

简单是输入和输出重定向的吸引力之一. 

不幸的是, 重定向对于许多应用程序来说太有限了. 
- 当程序依赖重定向时, 它无法控制其文件；它甚至不知道他们的名字. 
- 如果程序需要同时读取两个文件或写入两个文件, 重定向将无济于事. 

当重定向不够时, 我们将使用<stdio.h>提供的文件操作. 

<!-- slide id="FileOp" vertical=true data-notes="" -->



##### 打开文件

---

打开文件以用作流需要调用fopen函数. 

fopen的原型: 
```C
FILE *fopen(const char * restrict filename,
	          const char * restrict mode);
```

filename是要打开的文件的名称. 
- 此参数可能包括有关文件位置的信息, 例如驱动器说明符或路径. 

mode是一个"模式字符串", 它指定我们打算对文件执行的操作. 

<!-- slide vertical=true data-notes="" -->



##### 打开文件

---

fopen的原型中,  restrict一词出现了两次. 

restrict是一个 C99 关键字, 表示文件名和模式应指向不共享内存位置的字符串. 

fopen的 C89 原型不包含限制, 但在其他方面是相同的. 

restrict对fopen的行为没有影响, 因此通常可以忽略它. 

<!-- slide vertical=true data-notes="" -->



##### 打开文件

---

fopen调用中的文件名包含\字符时要小心. 

通话  
`fopen("c:\project\test1.dat", "r")`  
将失败, 因为\t被视为字符转义. 

避免该问题的一种方法是使用\\而不是\:  
`fopen("c:\\project\\test1.dat", "r")`

另一种方法是使用/字符而不是\:  
`fopen("c:/project/test1.dat", "r")`

<!-- slide vertical=true data-notes="" -->



##### 打开文件

---

fopen返回程序可以(并且通常会)保存在变量中的文件指针: 
```C
fp = fopen("in.dat", "r");
/* 打开 in.dat 以供阅读 */
```

当它无法打开文件时,  fopen返回一个空指针. 

<!-- slide vertical=true data-notes="" -->



##### 模式

---

决定将哪个模式字符串传递给fopen的因素: 
- 要对文件执行哪些操作
- 文件是否包含文本或二进制数据

<!-- slide vertical=true data-notes="" -->



##### 模式

---

文本文件的模式字符串: 
字符串含义
"r"打开阅读
"w"打开写入(文件不需要存在)
"a"打开附加(文件不需要存在)
"r+"读写打开, 从头开始
"w+"打开读写(如果文件存在则截断)
"a+"打开读写(如果文件存在则追加)

<!-- slide vertical=true data-notes="" -->



##### 模式

---

二进制文件的模式字符串: 
字符串含义
" rb "打开阅读
" wb "打开写入(文件不需要存在)
" ab "打开以进行附加(文件不必存在)
" r+b " 或者 " rb +"读写打开, 从头开始
" w+b " 或者 " wb +"打开读写(如果文件存在则截断)
" a+b " 或者 " ab +"打开读写(如果文件存在则追加)

<!-- slide vertical=true data-notes="" -->



##### 模式

---

写入数据和附加数据有不同的模式字符串. 

当数据写入文件时, 它通常会覆盖以前存在的内容. 

当打开文件进行追加时, 写入文件的数据将添加到末尾. 

<!-- slide vertical=true data-notes="" -->



##### 模式

---

当打开文件进行读写时, 适用特殊规则. 
- 除非读取操作遇到文件末尾, 否则不先调用文件定位函数就无法从读取切换到写入. 
- fflush或调用文件定位函数, 则无法从写入切换到读取. 

<!-- slide vertical=true data-notes="" -->



##### 关闭文件

---

fclose函数允许程序关闭不再使用的文件. 

fclose的参数必须是从调用fopen或freopen获得的文件指针. 

如果文件成功关闭,  fclose返回零. 

否则, 它返回错误代码EOF(在<stdio.h>中定义的宏). 

<!-- slide vertical=true data-notes="" -->



##### 关闭文件

---

打开文件进行读取的程序概要: 
```C
#include <stdio.h>
#include <stdlib.h>
	 
#define FILE_NAME "example.dat"
	 
int main(void)
{
  FILE *fp;
	 
  fp = fopen(FILE_NAME, "r");
  if(fp == NULL) {
    printf("Can't open %s\n", FILE_NAME);
    exit(EXIT_FAILURE);
  }
  …
  fclose(fp);
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->



##### 关闭文件

---

看到fopen的调用与fp的声明相结合并不罕见:  
`FILE *fp = fopen(FILE_NAME, "r");`

或针对NULL的测试:  
`if((fp = fopen(FILE_NAME, "r")) == NULL) …`

<!-- slide vertical=true data-notes="" -->



##### 将文件附加到打开的流

---

freopen将不同的文件附加到已经打开的流中. 

freopen最常见的用途是将文件与标准流之一( stdin、stdout或stderr)相关联. 

调用freopen导致程序开始写入文件foo: 
```C
if(freopen("foo", "w", stdout) == NULL) {
	/* error; foo can't be opened */
}
```

<!-- slide vertical=true data-notes="" -->



##### 将文件附加到打开的流

---

freopen的正常返回值是它的第三个参数(文件指针). 

如果无法打开新文件, 则freopen返回一个空指针. 

<!-- slide vertical=true data-notes="" -->



##### 将文件附加到打开的流

---

C99 增加了一个新的转折点: 如果文件名是空指针,  freopen会尝试将流的模式更改为mode参数指定的模式. 

不需要实现来支持此功能. 

如果他们这样做, 他们可能会对允许的模式更改施加限制. 

<!-- slide vertical=true data-notes="" -->



##### 从命令行获取文件名

---

有几种方法可以为程序提供文件名. 
- 将文件名构建到程序中并没有提供太大的灵活性. 
- 提示用户输入文件名可能很尴尬. 
- 让程序从命令行获取文件名通常是最好的解决方案. 

demo的程序提供两个文件名的示例:  
`demo names.dat dates.dat`

<!-- slide vertical=true data-notes="" -->



##### 从命令行获取文件名

---

main定义为具有两个参数的函数来访问命令行参数: 
```C
int main(int argc, char *argv[])
{
  …
}
```

argc是命令行参数的数量. 

argv是指向参数字符串的指针数组. 

<!-- slide vertical=true data-notes="" -->



##### 从命令行获取文件名

---

argv[0]指向程序名,  argv[1]到argv[argc-1]指向剩余的参数,  argv[argc]是一个空指针. 

在演示示例中,  argc为 3, 而argv具有以下外观: 
<div class="top-2">
  <img src="../img/21-3.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### 程序: 检查文件是否可以打开

---

canopen.c程序确定文件是否存在以及是否可以打开以供阅读. 

用户会给程序一个文件名来检查:  
`canopen file`

然后程序将打印任一文件 能够 是 打开或归档 不能 是  打开. 

如果用户在命令行中输入错误数量的参数, 程序将打印消息`usage: canopen filename`.

<!-- slide vertical=true data-notes="" -->



##### canopen.c

---

```C
/* Checks whether a file can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;
 
  if(argc != 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }
 
  if((fp = fopen(argv[1], "r")) == NULL) {
    printf("%s can't be opened\n", argv[1]);
    exit(EXIT_FAILURE);
  }
 
  printf("%s can be opened\n", argv[1]);
  fclose(fp);
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

程序通常需要创建临时文件——这些文件只在程序运行时就存在. 

<stdio.h>提供了两个函数, tmpfile和tmpnam, 用于处理临时文件. 

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

tmpfile创建一个临时文件(以"wb+"模式打开), 该文件将一直存在, 直到它关闭或程序结束. 

调用tmpfile会返回一个文件指针, 该指针可用于稍后访问该文件: 
```C
FILE *tempptr;
…
tempptr = tmpfile();
/* 创建一个临时文件 */
```

如果创建文件失败, 则tmpfile返回一个空指针. 

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

使用tmpfile的缺点: 
- 不知道tmpfile创建的文件的名称. 
- 以后无法决定将该文件永久化. 

另一种方法是使用fopen创建一个临时文件. 

tmpnam函数可用于确保此文件与现有文件的名称不同. 

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

tmpnam为临时文件生成一个名称. 

如果其参数是空指针, 则tmpnam将文件名存储在静态变量中并返回指向它的指针: 
```C
char *filename;
…
filename = tmpnam(NULL);
/* 创建一个临时文件名 */
```

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

否则,  tmpnam 会将文件名复制到程序员提供的字符数组中: 
```C
char filename[L_tmpnam];
…
tmpnam(filename);
/* 创建一个临时文件名 */
```

在这种情况下,  tmpnam还返回一个指向该数组第一个字符的指针. 

L_tmpnam是<stdio.h>中的一个宏, 它指定创建一个包含临时文件名的字符数组需要多长时间. 

<!-- slide vertical=true data-notes="" -->



##### 临时文件

---

TMP_MAX宏(在<stdio.h>中定义)指定tmpnam可以生成的临时文件名的最大数量. 

如果无法生成文件名, 则tmpnam返回一个空指针. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

将数据传输到磁盘驱动器或从磁盘驱动器传输数据是一项相对较慢的操作. 

获得可接受性能的秘诀是缓冲. 

写入流的数据实际上存储在内存的缓冲区中；当它已满(或流已关闭)时, 缓冲区被"刷新". 

输入流可以用类似的方式缓冲: 缓冲区包含来自输入设备的数据；输入是从此缓冲区而不是设备本身读取的. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

缓冲可以极大地提高效率, 因为从缓冲区读取字节或将字节存储在缓冲区中非常快. 

将缓冲区内容传输到磁盘或从磁盘传输需要时间, 但是一个大的"块移动"比许多微小的字节移动要快得多. 

<stdio.h>中的函数在看起来有利时自动执行缓冲. 

在极少数情况下, 我们可能需要使用函数fflush、setbuf和setvbuf. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

通过调用fflush, 程序可以根据需要多次刷新文件的缓冲区. 

fp关联的文件的缓冲区的调用:  
`fflush(fp); /* 为 fp 刷新缓冲区 */`

所有输出流的调用:  
`fflush(NULL); /* 刷新所有缓冲区 */`

fflush如果成功则返回零, 如果发生错误则返回EOF . 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

setvbuf允许我们改变缓冲流的方式并控制缓冲区的大小和位置. 

该函数的第三个参数指定所需的缓冲类型: 
_IOFBF(全缓冲)
_IOLBF(行缓冲)
_IONBF(无缓冲)

对于未连接到交互式设备的流, 完全缓冲是默认设置. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

setvbuf的第二个参数(如果它不是空指针)是所需缓冲区的地址. 

缓冲区可能具有静态存储持续时间、自动存储持续时间, 甚至是动态分配的. 

setvbuf的最后一个参数是缓冲区中的字节数. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

调用setvbuf将流的缓冲更改为完全缓冲, 使用缓冲区数组中的N个字节作为缓冲区: 
```C
char buffer[N];
…
setvbuf(stream, buffer, _IOFBF, N);
```

setvbuf必须在打开流之后但在对其执行任何其他操作之前调用. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

使用空指针作为第二个参数调用setvbuf也是合法的, 它请求setvbuf创建具有指定大小的缓冲区. 

如果成功, setvbuf返回零. 

如果mode参数无效或请求不能被接受, 它返回一个非零值. 

<!-- slide vertical=true data-notes="" -->



##### 文件缓冲

---

setbuf是一个较旧的函数, 它假定缓冲模式和缓冲区大小的默认值. 

如果buf是空指针, 则调用setbuf(stream, buf)等价于  
`(void) setvbuf(stream, NULL, _IONBF, 0);`

否则, 它相当于  
`(void) setvbuf(stream, buf, _IOFBF, BUFSIZ);`  
其中BUFSIZ是在<stdio.h>中定义的宏. 

setbuf被认为是过时的. 

<!-- slide vertical=true data-notes="" -->



##### 杂项文件操作

---

删除和重命名功能允许程序执行基本的文件管理操作. 

与本节中的大多数其他函数不同, remove和rename使用文件名而不是文件指针. 

如果成功, 这两个函数都返回零, 如果失败, 则返回非零值. 

<!-- slide vertical=true data-notes="" -->



##### 杂项文件操作

---

remove删除文件: 
```C
remove("foo");
/* 删除名为"foo"的文件 */
```

如果一个程序使用fopen(而不是tmpfile)创建一个临时文件, 它可以使用remove在程序终止之前删除该文件. 

删除当前打开的文件的效果是实现定义的. 

<!-- slide vertical=true data-notes="" -->



##### 杂项文件操作

---

rename更改文件的名称: 
```C
rename("foo", "bar");
/* 将 "foo" 重命名为 "bar" */
```

如果程序决定将其永久化,  rename可以方便地重命名使用fopen创建的临时文件. 
- 如果已存在具有新名称的文件, 则效果由实现定义. 

如果要求重命名打开的文件, 重命名可能会失败. 

<!-- slide vertical=true data-notes="" -->



##### 格式化的 I/O

---

下一组库函数使用格式字符串来控制读写. 

printf和相关函数能够在输出期间将数据从数字形式转换为字符形式. 

scanf和相关函数能够在输入过程中将数据从字符形式转换为数字形式. 

<!-- slide id="FormattedIO" vertical=true data-notes="" -->



##### … printf函数

---

fprintf和printf函数将可变数量的数据项写入输出流, 使用格式字符串控制输出的外观. 

两个函数的原型都以...符号(省略号)结尾, 它表示可变数量的附加参数: 
```C
int fprintf(FILE * restrict stream,
	          const char * restrict format, ...);
int printf(const char * restrict format, ...);
```

两个函数都返回写入的字符数；负返回值表示发生了错误. 

<!-- slide vertical=true data-notes="" -->



##### … printf函数

---

printf总是写入stdout , 而fprintf写入由其第一个参数指示的流: 
```C
printf("Total: %d\n", total);
	/* writes to stdout */
fprintf(fp, "Total: %d\n", total);
	/* writes to fp */
```

调用printf等效于调用fprintf并以stdout作为第一个参数. 

<!-- slide vertical=true data-notes="" -->



##### … printf函数

---

fprintf适用于任何输出流. 

它最常见的用途之一是将错误消息写入stderr:  
`fprintf(stderr, "Error: data file can't be opened.\n");`

将消息写入stderr可以保证即使用户重定向stdout, 它也会出现在屏幕上. 

<!-- slide vertical=true data-notes="" -->



##### … printf函数

---

<stdio.h>中的另外两个函数可以将格式化的输出写入流. 

这些名为vfprintf和vprintf的函数相当晦涩难懂. 

两者都依赖于<stdarg.h>中声明的va_list类型, 因此它们与该标题一起讨论. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

printf和fprintf都需要包含普通字符和/或转换规范的格式字符串. 
- 普通字符按原样打印. 
- 转换规范描述了如何将剩余的参数转换为字符形式以供显示. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

…printf转换规范由%字符组成, 后跟多达五个不同的项目: 
<div class="top-2">
  <img src="../img/21-4.png">
</div>

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

标志(可选；允许多个): 
标志 含义
-在字段内左对齐. 
+签名转换产生的数字总是以
+或- . 
由有符号转换产生的非负数是
前面有一个空格. 
#八进制数以0开头, 非零十六进制数
与0x或0X . 浮点数总是有一个
小数点. 尾随零不会从数字中删除
g或G转换打印. 
0数字用前导零填充, 直到字段宽度. 
(零) 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

最小字段宽度(可选). 太小而无法占据该字段的项目将被填充. 
- 默认情况下, 空格会添加到项目的左侧. 

对于字段宽度而言太大的项目仍将完整显示. 

字段宽度是整数或字符* . 
- 如果*存在, 则从下一个参数获取字段宽度. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

精度(可选). 精度的含义取决于转换: 
  d , i , o , u , x , X : 最小位数(前导零是
如果数字的位数较少, 则添加)
  a , A , e , E , f , F : 小数点后的位数
  g , G : 有效位数
  s : 最大字节数

精度是一个句点( .), 后跟一个整数或字符* . 
- 如果*存在, 则从下一个参数获得精度. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

长度修饰符(可选). 表示要显示的项目的类型比正常的长或短. 
- %d通常指的是一个int值； %hd用于显示短 int和%ld用于显示long 诠释. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

长度
修饰符转换说明符含义
hh † d ,我, o , u , x , X 签 字符, 无符号 字符
  n 签 字符 *
H d ,我, o , u , x , X 短的 整数, 无符号 短的 整数
  n 短的 整数 *
ld ,我, o , u , x , X 长 整数, 无符号 长 整数
(埃尔) n 长 整数 *
  C wint_t
  s wchar_t *
  a , A , e , E , f , F , g , G无效果
 †仅限 C99

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

长度
修饰符转换说明符含义
 我† d ,我, o , u , x , X 长 长 整数, 
(厄尔)  未签名 长 长 整数 
  n 长 长 整数 *
j † d ,我, o , u , x , X 最大整数
  n intmax_t *
z † d ,我, o , u , x , X 尺寸_t
  n 尺寸_t *
t † d ,我, o , u , x , X ptrdiff_t
  n ptrdiff_t *
大号 一个, 一个,  e ,  E ,  f ,  F ,  g ,  G 长 双倍的
 †仅限 C99

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

转换说明符. 必须是下表中的字符之一. 
转换
 说明符含义
d , i将int值转换为十进制形式. 
o , u , x , X转换无符号数 以 8 为底的int值( o), 以
10( u) 或以 16 为底的( x , X).  x显示十六进制
数字a – f小写； X以大写形式显示它们. 
f , F †将双精度值转换为十进制形式, 将
小数点在正确的位置. 如果没有精度
指定, 在小数点后显示六位数字. 
†仅限 C99 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

转换
说明符 含义
e , E将双精度值转换为科学计数法. 如果不
指定精度, 显示后六位数
小数点. 如果选择e , 则指数在前
由字母e ;如果选择E , 则指数在前
由E . 
, _ _ g将double值转换为f形式或e形式. 
G在F和E形式之间进行选择. 
a † , A †将双精度值转换为十六进制科学值
使用 [ - ] 0x h形式的符号.  hhhh p ± d . 一个显示
小写的十六进制数字a – f ； A 将它们显示在
大写.  a或A的选择也会影响
字母x和p . 
†仅限 C99 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范

---

转换
说明符 含义
c将int值显示为无符号字符. 
s写入参数指向的字符. 停止
写入时指定的字节数
达到精度(如果存在)或空字符
遭遇. 
p转换一个void *可打印形式的值. 
n对应的参数必须指向一个对象
输入int . 在此对象中存储字符数
到目前为止, 由…printf的调用编写；不产生
输出. 
%写入字符% . 

<!-- slide vertical=true data-notes="" -->



##### C99 对...printf转换规范的更改

---

C99 更改了printf和fprintf的转换规范: 
- 附加长度修饰符
- 其他转换说明符
- 写无穷大和 NaN 的能力
- 支持宽字符
- 现在允许以前未定义的转换规范

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

显示标志对%d转换的影响的示例: 
申请转换结果 申请结果
规格转换为 123 转换为 –123
%8d •••••123 ••••-123
%-8d 123••••• -123••••
%+8d ••••+123 ••••-123
% 8d •••••123 ••••-123
%08d 00000123 -0000123
%-+8d +123•••• -123••••
%- 8d •123•••• -123••••
%+08d +0000123 -0000123
% 08d •0000123 -0000123

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

#标志对o、x、X、g和G转换的影响的示例: 
申请转换结果 申请结果
规范转换为 123 转换为 123.0
%8o •••••173
%#8o ••••0173
%8x ••••••7b
%#8x ••••0x7b
%8X ••••••7B
%#8X ••••0X7B
%8g •••••123
%#8g •123.000
%8G •••••123
%#8G •123.000
 
<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

显示最小字段宽度和精度对%s转换的影响的示例: 
申请结果 申请结果
转换 转换为 转换为
规范"虚假"                 "流行语"
%6s •虚假的流行语
%-6s 虚假• 流行语
%.4s 博古嗡嗡声
%6.4s ••bogu ••buzz
%-6.4s bogu•• 嗡嗡声••

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

示例显示%g转换如何以%e形式显示一些数字, 而另一些以%f形式显示: 
应用%.4g的结果
数字转换为数字
123456. 1.235e+05
   12345.6 1.235e+04
    1234.56 1235
     123.456 123.5
      12.3456 12.35
       1.23456 1.235
        .123456 0.1235
        .0123456 0.01235
        .00123456 0.001235
        .000123456 0.0001235
        .0000123456 1.235e-05
        .00000123456 1.235e-06

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

最小字段宽度和精度通常嵌入在格式字符串中. 

将*字符放在任何一个数字通常会出现的位置允许我们将其指定为格式字符串之后的参数. 

产生相同输出的printf调用: 
```C
printf("%6.4d", i);
printf("%*.4d", 6, i);
printf("%6.*d", 4, i);
printf("%*.*d", 6, 4, i);
```

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

*的一个主要优点是它允许我们使用宏来指定宽度或精度:  
`printf("%*d", WIDTH, i);`

宽度或精度甚至可以在程序执行期间计算:  
`printf("%*d", page_width / num_cols, i);`

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

%p转换用于打印指针的值: 
```C
printf("%p",(void *) ptr);
/* 显示 ptr 的值 */
```

指针很可能显示为八进制或十六进制数. 

<!-- slide vertical=true data-notes="" -->



##### …printf转换规范的示例

---

%n转换用于通过调用…printf找出到目前为止已打印了多少个字符. 

len的值为3: 
```C
printf("%d%n\n", 123, &len);
```

<!-- slide vertical=true data-notes="" -->



##### … scanf函数

---

fscanf和scanf从输入流中读取数据项, 使用格式字符串来指示输入的布局. 

在格式字符串之后, 任意数量的指针(每个都指向一个对象)作为附加参数跟随. 

输入项被转换(根据格式字符串中的转换规范)并存储在这些对象中. 

<!-- slide vertical=true data-notes="" -->



##### … scanf函数

---

scanf始终从stdin读取, 而fscanf从其第一个参数指示的流中读取: 
```C
scanf("%d%d", &i, &j);
/* 从标准输入读取 */
fscanf(fp, "%d%d", &i, &j);
/* 从 fp 读取 */
```

调用scanf等效于调用fscanf并以stdin作为第一个参数. 

<!-- slide vertical=true data-notes="" -->



##### … scanf函数

---

导致...scanf函数过早返回的错误: 
- 输入失败(无法读取更多输入字符)
- 匹配失败(输入的字符与格式字符串不匹配)

在 C99 中, 也可能由于编码错误而发生输入故障. 

<!-- slide vertical=true data-notes="" -->



##### … scanf函数

---

…scanf函数返回已读取并分配给对象的数据项的数量. 

如果在读取任何数据项之前发生输入失败, 它们将返回EOF . 

测试scanf返回值的循环很常见. 

一个循环读取一系列整数, 在出现问题的第一个迹象时停止: 
```C
while(scanf("%d", &i) == 1) {
	…
}
```

<!-- slide vertical=true data-notes="" -->



##### …scanf格式化字符串

---

…scanf函数的调用类似于…printf函数的调用. 

但是,  …scanf函数的工作方式不同. 

格式字符串表示…scanf函数在读取输入时尝试匹配的模式. 
- 如果输入与格式字符串不匹配, 则函数返回. 
- 不匹配的输入字符被"推回"以供将来读取. 

<!-- slide vertical=true data-notes="" -->



##### …scanf格式化字符串

---

一个…scanf格式的字符串可能包含三件事: 
- 转换规格
- 空白字符
- 非空白字符

<!-- slide vertical=true data-notes="" -->



##### …scanf格式化字符串

---

转换规范.  …scanf格式字符串中的转换规范类似于…printf格式字符串中的转换规范. 

大多数转换规范在输入项的开头跳过空白字符(例外是%[、%c和%n). 

转换规范从不跳过尾随空白字符

<!-- slide vertical=true data-notes="" -->



##### …scanf格式化字符串

---

空白字符. 格式字符串中的一个或多个空白字符与输入流中的零个或多个空白字符匹配. 

非空白字符.  %以外的非空白字符与输入流中的相同字符匹配. 

<!-- slide vertical=true data-notes="" -->



##### …scanf格式化字符串

---

格式字符串"ISBN %d-%d-%ld-%d"指定输入将包括: 
- 字母 ISBN
- 可能是一些空白字符
- 一个整数
- -字符_
- 一个整数(可能前面有空格字符)
- -字符_
- 一个长整数(可能前面有空格字符)
- -字符_
- 一个整数(可能前面有空格字符)

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

…scanf转换规范由字符%组成, 后跟: 
- *
- 最大字段宽度
- 长度修饰符
- 转换说明符

*(可选). 表示分配抑制: 读取输入项但未分配给对象. 
- *匹配的项目不包括在...scanf返回的计数中. 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

最大字段宽度(可选). 限制输入项中的字符数. 
- 在转换开始时跳过的空白字符不算在内. 

长度修饰符(可选). 表示将存储输入项的对象具有比正常更长或更短的类型. 

下一张幻灯片上的表格列出了每个长度修饰符以及与转换说明符组合时指示的类型. 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

长度
修饰符转换说明符含义
hh † d ,我, o , u , x , X , n 签 字符 * ,无符号 字符 *
H d ,我, o , u , x , X , n 短的 整数 * ,无符号 短的 整数 *
l d ,我, o , u , x , X , n 长 整数 * ,无符号 长 整数 *
() a , A , e , E , f , F , g , G _ 双倍的 *
  c、s或[ wchar_t *
我† d ,我, o , u , x , X , n 长 长 整数 * ,
( ell-ell)无符号 长 长 整数 *
j † d ,我, o , u , x , X , n intmax_t * , uintmax_t *
z † d ,我, o , u , x , X , n 尺寸_t *
t † d ,我, o , u , x , X , n ptrdiff_t *
大号 一个, 一个,  e ,  E ,  f ,  F ,  g ,  G 长 双倍的 *
†仅限 C99

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

转换说明符. 必须是下表中的字符之一. 
转换
 说明符含义
d匹配一个十进制整数；对应的论点
假定为int类型 * .
 i匹配一个整数；相应的论点是
假定为int类型 * .整数被假定为
以 10 为底, 除非它以0开头(表示八进制)
或使用0x或0X(十六进制). 
o匹配一个八进制整数；相应的论点是
假定为无符号类型 整数 * .
 u匹配十进制整数；对应的论点
假定为无符号类型 整数 * .

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

转换
说明符 含义
x , X匹配一个十六进制整数；相应的
假设参数的类型为 unsigned int * .
a † , A † , e , E , 匹配一个浮点数；相应的
f , F † , g , G参数被假定为float类型 * .
c匹配n 个字符, 其中n是最大字段
宽度, 如果未指定字段宽度, 则为一个字符. 这
相应的参数被假定为指向
字符数组(或字符对象, 如果没有字段宽度
指定的). 最后不添加空字符. 
s匹配一系列非空白字符, 然后
最后添加一个空字符. 相应的
参数被假定为指向字符数组的指针. 
†仅限 C99 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

转换
说明符 含义
[匹配来自 a 的非空字符序列
scanset, 然后在末尾添加一个空字符. 这
相应的参数被假定为指向
字符数组. 
p匹配格式为...printf的指针值 
会写的. 对应的论点是
假定为指向void的指针 *对象. 
n对应的参数必须指向一个对象
输入int . 在此对象中存储字符数
到目前为止, 通过调用…scanf阅读. 不消耗任何输入
...scanf的返回值不受影响. 
%匹配字符% . 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

+或-)开头. 

然而, o、u、x和X说明符将项目转换为无符号形式, 因此它们通常不用于读取负数. 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

[说明符是s说明符的更复杂(也更灵活)的版本. 

使用[的转换规范具有%[ set ]或%[^ set ]的形式, 其中set可以是任何字符集. 

%[ set ]匹配set(扫描集)中的任何字符序列. 

%[^ set ]匹配任何不在set中的字符序列. 

例子:  
%[abc]匹配任何只包含a、b和c的字符串.  
%[^abc]匹配任何不包含a、b或c的字符串. 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

许多...scanf转换说明符与<stdlib.h>中的数字转换函数密切相关. 

这些函数将字符串(如"-297")转换为其等效的数值(–297). 

,  d说明符查找可选的+或-符号, 后跟十进制数字；这与strtol函数所需的形式相同. 

<!-- slide vertical=true data-notes="" -->



##### …scanf转换规范

---

…scanf转换说明符和数值转换函数之间的对应关系: 
转换
说明符数值转换函数
d strtol以 10 为底
i strtol以 0 为基数
o strtoul以 8 为基础
你 strtoul以 10 为基数
x , X strtoul以 16 为底
a , A , e , E , f , F , g , G strtod

<!-- slide vertical=true data-notes="" -->



##### C99 对...scanf转换规范的更改

---

C99 更改了scanf和fscanf的转换规范: 
- 附加长度修饰符
- 其他转换说明符
- 读取无穷大和 NaN 的能力
- 支持宽字符

<!-- slide vertical=true data-notes="" -->



##### scanf示例

---

接下来的三个表包含scanf的示例调用. 

删除线中打印的字符被呼叫消耗. 

<!-- slide vertical=true data-notes="" -->



##### scanf示例

---

结合转换规范、空白字符和非空白字符的示例: 

scanf调用 输入 变量
n = scanf("%d%d", &i, &j);	12•,•34¤	n: 1
			i: 12
			j: unchanged
n = scanf("%d,%d", &i, &j);	12•,•34¤	n: 1
			i: 12
			j: unchanged
n = scanf("%d ,%d", &i, &j);	12•,•34¤	n: 2
			i: 12
			j: 34
n = scanf("%d, %d", &i, &j);	12•,•34¤	n: 1
			i: 12
			j: unchanged
<!-- slide vertical=true data-notes="" -->



##### scanf示例

---

显示分配抑制效果和指定字段宽度的示例: 

scanf调用 输入 变量
n = scanf("%*d%d", &i);	12•34¤	n: 1
			i: 34
n = scanf("%*s%s", str);	My•Fair•Lady¤	n: 1
			str: "Fair"
n = scanf("%1d%2d%3d", 	12345¤	n: 3
                       &i, &j, &k); 		i: 1
			j: 23
			k: 45
n = scanf("%2d%2s%2d", 	123456¤	n: 3
                        &i, str, &j); 		i: 12
			str: "34"  
			j: 56

<!-- slide vertical=true data-notes="" -->



##### scanf示例

---

说明i、[和n转换说明符的示例: 
scanf调用 输入 变量
n = scanf("%i%i%i", &i, &j, &k);	12•012•0x12¤	n: 3
			i: 12
			j: 10
			k: 18
n = scanf("%[0123456789]", str);	123abc¤	n: 1
			str: "123"
n = scanf("%[0123456789]", str);	abc123¤	n: 0
			str: unchanged
n = scanf("%[^0123456789]", str);	abc123¤	n: 1
			str: "abc"
n = scanf("%*d%d%n", &i, &j);	10•20•30¤	n: 1
			i: 20
			j: 5

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

如果我们要求...scanf函数读取和存储n 个数据项, 我们期望它的返回值为n . 

如果返回值小于n, 则出现问题: 
- 文件结束. 该函数在完全匹配格式字符串之前遇到文件结尾. 
- 读取错误. 该函数无法从流中读取字符. 
- 匹配失败. 数据项的格式错误. 

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

每个流都有两个与之关联的指示器: 错误指示器和文件结束指示器.  

打开流时, 这些指示符会被清除. 

遇到文件结束设置文件结束指示符, 读取错误设置错误指示符. 
- 当输出流上发生写入错误时, 也会设置错误指示符. 

匹配失败不会改变任何一个指标. 

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

一旦设置了错误或文件结束指示符, 它就会保持该状态, 直到它被显式清除, 可能通过调用clearerr函数. 
clearerr清除文件结尾和错误指示符: 
```C
clearerr(fp);
	/* clears eof and error indicators for fp */
```
clearerr并不经常需要, 因为其他一些库函数会清除一个或两个指标作为副作用. 

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

feof和ferror函数可用于测试流的指示符以确定对流的先前操作失败的原因. 

fp关联的流设置了文件结束指示符, 则调用feof(fp)将返回一个非零值. 

调用ferror(fp)返回一个非零值. 

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

当scanf返回小于预期的值时, 可以使用feof和ferror来判断原因. 
- 如果feof返回非零值, 则已到达输入文件的末尾. 
- 如果ferror返回非零值, 则在输入期间发生读取错误. 
- 如果两者都没有返回非零值, 则必须发生匹配失败. 

scanf的返回值表示在问题发生之前读取了多少数据项. 

<!-- slide vertical=true data-notes="" -->



##### 检测文件结束和错误情况

---

find_int函数是一个示例, 它显示了如何使用feof和ferror. 

find_int在文件中搜索以整数开头的行:  
`n = find_int("foo");`

find_int返回它找到的整数的值或错误代码: 
- –1 文件无法打开
- –2 读取错误
- –3 没有行以整数开头

<!-- slide vertical=true data-notes="" -->



##### 

---

```C
int find_int(const char *filename)
{
  FILE *fp = fopen(filename, "r");
  int n;
	 
  if(fp == NULL)
    return -1;               /* can't open file */
	 
  while(fscanf(fp, "%d", &n) != 1) {
    if(ferror(fp)) {
      fclose(fp);
      return -2;             /* read error */
    }
    if(feof(fp)) {
      fclose(fp);
      return -3;             /* integer not found */
    }
    fscanf(fp, "%*[^\n]");   /* skips rest of line */
  }
	 
  fclose(fp);
  return n;
}
```

<!-- slide vertical=true data-notes="" -->



##### 字符输入/输出

---

下一组库函数可以读取和写入单个字符. 

这些函数同样适用于文本流和二进制流. 

这些函数将字符视为int类型的值, 而不是char . 

一个原因是输入函数通过返回EOF来指示文件结束(或错误)条件, EOF是一个负整数常量. 

<!-- slide id="CharIO" vertical=true data-notes="" -->



##### 输出函数

---

putchar将一个字符写入标准输出流:  
`putchar(ch); /* 将 ch 写入标准输出 */`

fputc和putc将一个字符写入任意流: 
```C
fputc(ch, fp); /* 将 ch 写入 fp */
putc(ch, fp); /* 将 ch 写入 fp */
```

putc通常实现为宏(以及函数), 而fputc仅实现为函数. 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

putchar本身通常是一个宏:  
`#define putchar(c) putc((c), stdout)`

C 标准允许putc宏多次评估流参数, 而fputc不允许这样做. 

程序员通常更喜欢putc , 它提供了一个更快的程序. 

如果发生写入错误, 所有三个函数都会为流设置错误指示符并返回EOF . 

否则, 它们返回写入的字符. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

getchar从stdin读取一个字符: 
`ch = getchar();`

fgetc和getc从任意流中读取一个字符: 
```C
ch = fgetc(fp);
ch = getc(fp);
```

所有三个函数都将字符视为无符号 char值(然后在返回之前转换为int类型). 

EOF以外的负值. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

getc通常实现为宏(以及函数), 而fgetc仅实现为函数. 

getchar通常也是一个宏:  
`#define getchar() getc(stdin)`

程序员通常更喜欢getc而不是fgetc . 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

如果出现问题,  fgetc、getc和getchar函数的行为相同. 

在文件结束时, 他们设置流的文件结束指示符并返回EOF . 

如果发生读取错误, 它们会设置流的错误指示器并返回EOF . 

为了区分这两种情况, 我们可以调用feof或ferror. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

fgetc、getc和getchar最常见的用途之一是从文件中读取字符. 

的典型while循环: 
```C
while((ch = getc(fp)) != EOF) {
	…
}
```

始终将返回值存储在int变量中, 而不是char变量中. 

EOF测试char变量可能会给出错误的结果. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

ungetc函数"推回"从流中读取的字符并清除流的文件结束指示符. 

读取一系列数字的循环, 在第一个非数字处停止: 
```C
while(isdigit(ch = getc(fp))) {
	…
}
ungetc(ch, fp);
	/* pushes back last character read */
```

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

ungetc可以推回的字符数不等；只有第一次调用才能保证成功. 

调用文件定位函数(fseek、fsetpos或rewind)会导致推回的字符丢失. 

ungetc返回它被要求推回的字符. 
- 如果尝试推回EOF或推回超过允许的字符数, 则返回EOF. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 复制文件

---

fcopy.c程序制作文件的副本. 

执行程序时, 将在命令行中指定原始文件和新文件的名称. 

使用fcopy将文件f1.c复制到f2.c的示例:  
`fcopy f1.c f2.c`

如果命令行中的文件名不完全是两个, 或者其中一个文件都无法打开, fcopy将发出错误消息. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 复制文件

---

使用"rb"和"wb"作为文件模式使fcopy可以复制文本和二进制文件. 

如果我们改用"r"和"w", 程序不一定能够复制二进制文件. 

<!-- slide vertical=true data-notes="" -->



##### 复制文件

---

```C
/* Copies a file */
 
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;
  int ch;
 
  if(argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
 
  if((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }
 
  while((ch = getc(source_fp)) != EOF)
    putc(ch, dest_fp);
 
  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->



##### 线路 I/O

---

下一组中的库函数能够读取和写入行. 

这些函数主要用于文本流, 尽管将它们用于二进制流也是合法的. 

<!-- slide id="LineIO" vertical=true data-notes="" -->



##### 输出函数

---

puts函数将一串字符写入stdout:  
`puts("Hi, there!");  /* writes to stdout */`

在将字符写入字符串后,  puts总是添加一个换行符. 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

fputs是puts的更通用版本. 

它的第二个参数指示输出应写入的流:  
`fputs("Hi, there!", fp);  /* writes to fp */`

与puts不同,  fputs函数不会写入换行符, 除非字符串中存在换行符. 

如果发生写入错误, 这两个函数都返回EOF；否则, 它们返回一个非负数. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

gets函数从stdin读取一行输入:  
`gets(str); /* reads a line from stdin */`

get一个一个地读取字符, 将它们存储在str指向的数组中, 直到它读取一个换行符(它丢弃). 

fgets是更通用的 get 版本, 可以从任何流中读取. 

fgets也比gets更安全, 因为它限制了它将存储的字符数. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

将一行读入名为str的字符数组中的fgets调用:  
`fgets(str, sizeof(str), fp);`

fgets将读取字符, 直到它到达第一个换行符或sizeof(str) - 已读取 1 个字符. 

如果它读取换行符, fgets会将其与其他字符一起存储. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

如果发生读取错误或在存储任何字符之前到达输入流的末尾,  gets和fgets都会返回空指针. 

否则, 两者都返回它们的第一个参数, 该参数指向存储输入的数组. 

这两个函数都在字符串的末尾存储了一个空字符. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

在大多数情况下, 应使用fgets而不是gets. 

仅当保证读取的字符串适合数组时, gets才能安全使用. 

当没有保证(通常没有)时, 使用fgets会更安全. 

stdin作为其第三个参数传递, fgets将从标准输入流中读取:  
`fgets(str, sizeof(str), stdin);`

<!-- slide vertical=true data-notes="" -->



##### 块 I/O

---

fread和fwrite函数允许程序在一个步骤中读取和写入大块数据. 

fread和fwrite主要用于二进制流, 尽管——小心——也可以将它们用于文本流. 

<!-- slide id="BlockIO" vertical=true data-notes="" -->



##### 块 I/O

---

fwrite旨在将数组从内存复制到流中. 

fwrite调用中的参数: 
- 数组地址
- 每个数组元素的大小(以字节为单位)
- 要写入的元素数
- 文件指针

调用fwrite写入数组a的全部内容: 
```C
fwrite(a, sizeof(a[0]),
sizeof(a) / sizeof(a[0]), fp);
```

<!-- slide vertical=true data-notes="" -->



##### 块 I/O

---

fwrite返回实际写入的元素数. 

如果发生写入错误, 此数字将小于第三个参数. 

<!-- slide vertical=true data-notes="" -->



##### 块 I/O

---

fread将从流中读取数组的元素. 

将文件内容读入数组a的fread调用: 
```C
n = fread(a, sizeof(a[0]),
sizeof(a) / sizeof(a[0]), fp);
```

fread的返回值表示实际读取的元素数. 

此数字应等于第三个参数, 除非已到达输入文件的末尾或发生读取错误. 

<!-- slide vertical=true data-notes="" -->



##### 块 I/O

---

fwrite对于需要在终止之前将数据存储在文件中的程序来说很方便. 

稍后, 程序(或其他程序)可以使用fread将数据读回内存. 

数据不需要是数组形式. 

将结构变量s写入文件的fwrite调用:  
`fwrite(&s, sizeof(s), 1, fp);`

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

每个流都有一个关联的文件位置.  

打开文件时, 文件位置设置在文件的开头. 
- 在"附加"模式下, 初始文件位置可能在开头或结尾, 具体取决于实现. 

当执行读取或写入操作时, 文件位置会自动前进, 从而提供对数据的顺序访问. 

<!-- slide id="FilePosition" vertical=true data-notes="" -->



##### 文件定位

---

尽管顺序访问对许多应用程序来说都很好, 但有些程序需要能够在文件中跳转. 

如果文件包含一系列记录, 我们可能希望直接跳转到特定记录. 

<stdio.h>提供五个函数, 允许程序确定当前文件位置或更改它. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

fseek函数更改与第一个参数(文件指针)关联的文件位置. 

第三个参数是三个宏之一: 
- SEEK_SET文件开头
- SEEK_CUR当前文件位置
- SEEK_END文件结尾

第二个参数, 类型为long int , 是一个(可能是负数)字节数. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

使用fseek移动到文件的开头:  
`fseek(fp, 0L, SEEK_SET);`

使用fseek移动到文件末尾:  
`fseek(fp, 0L, SEEK_END);`

使用fseek向后移动 10 个字节:  
`fseek(fp, -10L, SEEK_CUR);`

如果发生错误(例如, 请求的位置不存在), fseek返回一个非零值. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

文件定位功能最好与二进制流一起使用. 

C 不禁止程序将它们与文本流一起使用, 但存在某些限制. 

对于文本流,  fseek只能用于移动到文本流的开头或结尾, 或者返回之前访问过的地方. 

对于二进制流,  fseek不需要支持第三个参数是SEEK_END的调用. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

ftell函数以长整数形式返回当前文件位置. 

ftell返回的值可能会被保存并稍后提供给fseek的调用:  
长文件位置；
```C
…
file_pos = ftell(fp);
/* 保存当前位置 */
…
fseek(fp, file_pos, SEEK_SET);
/* 回到原来的位置 */
```

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

如果fp是二进制流, 则调用ftell(fp)以字节计数的形式返回当前文件位置, 其中零表示文件的开头. 

如果fp是文本流, 则ftell(fp)不一定是字节数. 

因此, 最好不要对ftell返回的值执行算术运算. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

rewind函数将文件位置设置在开头. 

调用rewind(fp)几乎等同于fseek(fp, 0L, SEEK_SET) . 
- 区别？ rewind不返回值, 但会清除fp的错误指示符. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

fseek和ftell仅限于位置可以存储为长整数的文件. 

为了处理非常大的文件, C 提供了两个附加函数: fgetpos和fsetpos. 

这些函数可以处理大文件, 因为它们使用fpos_t类型的值来表示文件位置. 
- fpos_t值不一定是整数；例如, 它可以是一个结构. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

调用fgetpos(fp, &file_pos)将与fp关联的文件位置存储在file_pos变量中. 

调用fsetpos(fp, &file_pos)将fp的文件位置设置为存储在file_pos中的值. 

如果调用fgetpos或fsetpos失败, 它会在errno中存储一个错误代码. 

这两个函数在成功时返回零, 在失败时返回非零值. 

<!-- slide vertical=true data-notes="" -->



##### 文件定位

---

使用fgetpos和fsetpos保存文件位置并稍后返回的示例: 
```C
fpos_t file_pos;
…
fgetpos(fp, &file_pos);
  /* saves current position */
…
fsetpos(fp, &file_pos);
	/* returns to old position */
```

<!-- slide vertical=true data-notes="" -->



##### 程序: 修改零件记录文件

---

invclear.c程序执行的操作: 
- 打开包含零件结构的二进制文件. 
- 将结构读入数组. 
- 的on_hand成员设置为 0. 
- 将结构写回文件. 

"rb+"模式打开文件, 允许读写. 

<!-- slide vertical=true data-notes="" -->



##### invclear.c

---

```C
/* Modifies a file of part records by setting the quantity
   on hand to zero for all records */
 
#include <stdio.h>
#include <stdlib.h>
 
#define NAME_LEN 25
#define MAX_PARTS 100
 
struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];
 
int num_parts;

int main(void)
{
  FILE *fp;
  int i;
 
  if((fp = fopen("inventory.dat", "rb+")) == NULL) {
    fprintf(stderr, "Can't open inventory file\n");
    exit(EXIT_FAILURE);
  }
 
  num_parts = fread(inventory, sizeof(struct part),
                    MAX_PARTS, fp);
 
  for(i = 0; i < num_parts; i++)
    inventory[i].on_hand = 0;
 
  rewind(fp);
  fwrite(inventory, sizeof(struct part), num_parts, fp);
  fclose(fp);
 
  return 0;
}
```

<!-- slide vertical=true data-notes="" -->



##### 字符串 I/O

---

本节中描述的函数可以使用字符串读取和写入数据, 就好像它是一个流一样. 

sprintf和snprintf将字符写入字符串. 

sscanf从字符串中读取字符. 

<!-- slide id="StringIO" vertical=true data-notes="" -->



##### 字符串 I/O

---

三个类似的函数(vsprintf、vsnprintf和vsscanf)也属于<stdio.h> . 

这些函数依赖于在<stdarg.h>中声明的va_list类型, 因此它们将在第 26 章中讨论. 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

sprintf函数将输出写入字符数组(由其第一个参数指向)而不是流. 

"9/20/2010"写入日期的调用:  
`sprintf(date, "%d/%d/%d", 9, 20, 2010);`

sprintf在字符串末尾添加一个空字符. 

它返回存储的字符数(不包括空字符). 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

sprintf可用于格式化数据, 将结果保存在字符串中, 直到生成输出为止. 

sprintf也便于将数字转换为字符形式. 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

snprintf函数(C99 中的新功能)与 sprintf 相同, 只是多了一个名为n的第二个参数. 

不超过n – 1 个字符将写入字符串, 不包括终止空字符, 除非n为零, 否则始终写入. 

例子:  
`snprintf(name, 13, "%s, %s", "Einstein", "Albert");`

字符串"Einstein, Al"被写入name . 

<!-- slide vertical=true data-notes="" -->



##### 输出函数

---

snprintf返回在没有长度限制的情况下将被写入的字符数(不包括空字符). 

如果发生编码错误, snprintf返回一个负数. 

要查看snprintf是否有空间写入所有请求的字符, 我们可以测试它的返回值是否为非负且小于n. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

sscanf函数类似于scanf和fscanf. 

sscanf从字符串(由其第一个参数指向)中读取, 而不是从流中读取. 

sscanf的第二个参数是与scanf和fscanf使用的格式字符串相同的格式字符串. 

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

sscanf可以方便地从另一个输入函数读取的字符串中提取数据. 

使用fgets获取一行输入, 然后将该行传递给sscanf进行进一步处理的示例: 
```C
fgets(str, sizeof(str), stdin);
  /* reads a line of input */
sscanf(str, "%d%d", &i, &j);
	/* extracts two integers */
```

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

sscanf的一个优点是我们可以根据需要多次检查输入行. 

这使得更容易识别替代输入形式并从错误中恢复. 

月/日/年或月-日-年形式编写的日期的问题: 
```C
if(sscanf(str, "%d /%d /%d", &month, &day, &year) == 3)
  printf("Month: %d, day: %d, year: %d\n", month, day, year);
else if(sscanf(str, "%d -%d -%d", &month, &day, &year) == 3)
  printf("Month: %d, day: %d, year: %d\n", month, day, year);
else
  printf("Date not in the proper form\n"); 
```

<!-- slide vertical=true data-notes="" -->



##### 输入函数

---

与scanf和fscanf函数一样, sscanf返回成功读取和存储的数据项的数量. 

sscanf在找到第一项之前到达字符串的末尾(由空字符标记), 则返回EOF. 

<!-- slide vertical=true data-notes="" -->


