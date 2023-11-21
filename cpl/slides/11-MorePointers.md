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

## 指针


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- 动态内存分配
- 


<!-- slide vertical=true data-notes="" -->



##### 动态内存分配

---

可变长数组`int array[n]`
- 不推荐

`malloc`和`free`

C函数库提供`malloc`和`free`，分别用于执行动态内存的==分配==与==释放==

```C{.line-numbers}
int *a = NULL;
a = (int *)malloc(n * sizeof(int));
free(a);
```

申请后需要释放

<!-- slide vertical=true data-notes="" -->



##### 函数malloc

---

```C{.line-numbers}
#include<stdlib.h>
void *malloc(size_t _Size);
```

向`malloc`申请的空间的大小是以字节为单位的
返回类型默认是`void *`

```C
int *array = (int *) malloc(len * sizeof(int))
int *array = malloc(len * sizeof(int))
int *array = malloc(len * sizeof(*array))
```

示例: `malloc.c`

<!-- slide vertical=true data-notes="" -->



##### free

---

```C
#include<stdlib.h>
void free(void *pointer);
```

free(ptr):释放指针指向内存，指针变量依然存在(野指针)

为防止释放后写, 建议 ptr = NULL

- 需要释放之前动态申请的内存, 一对一配对使用
- 内存泄漏memory leak

示例: `malloc_space.c`


<!-- slide vertical=true data-notes="" -->



##### 动态内存分配的常见错误

---

- 申请了没有free

- 对NULL指针进行解引用

- 对分配的内存越界操作

- 释放并非动态分配的内存（段错误）

- 试图释放动态分配的内存的部分

- 释放后依旧试图继续使用



<!-- slide vertical=true data-notes="" -->


##### 一些其他memory allocation函数

---

```C
void *malloc(size_t size);
void *calloc(size_t nitems, size_t size);
void *realloc(void *ptr, size_t new_size);
void free(void *ptr);
```

- malloc: allocates memory

- calloc: allocates and zeros memory

- realloc: expands previously allocated memory block

- free deallocates previoulsy allocated memory