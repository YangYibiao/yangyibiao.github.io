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

## 数据类型深化

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 类型修饰符与取值范围

- 赋值细节

- 常量与符号常量

- 案例: Circle 与 Sphere

---

<!-- slide data-notes="" -->


##### 类型修饰符

---

==修饰符==: 改变整数类型的取值范围, 或是否允许负号

<div class="fullborder">

| 修饰符           | 含义                                    |
| :--             | :--                                     |
| `short` / `long` | 短整型 / 长整型                          |
| `signed`         | 有符号 (默认, 可表示负数)                 |
| `unsigned`       | 无符号 (只表示 0 与正数, 范围更大)         |

</div>

常见组合: `short int`, `long int`, `unsigned int`, `unsigned long`

- 位数: `short` ≤ `int` ≤ `long`

<span class="blue">:fa-weixin:</span> 用 ==sizeof== 运算符可查看类型占用的字节数

---


<!-- slide data-notes="" -->

##### 类型: int

---

==int==变量: (整数integer的缩写)存储整数, 如`0`, `1`, `392`或`-2553`

- 取值范围是受限的, 最大的整数通常是$2 147 483 647$($2^{31}-1$)

- INT_MAX, INT_MIN (limits.h头文件中定义的常量)

```C
#include <stdio.h>
#include <limits.h>

int main(void) {
  printf("Max: %d, Min: %d", INT_MAX, INT_MIN);
  return 0;
}
```

---



<!-- slide data-notes="" -->


##### 类型: char

---

==char== 变量: 存储字符, 如'A'

- 用单引号括起来

- 存储的是字符对应的编码(0 ~ 127的整数)

- 字符'a'的值是97, 'A'的值是65, '0'的值是48, ' '的值是32

- 使用 %c 打印

<div class="top-2">
  <img src="../1-types-io/img/ASCII.png" width=500px>
</div>

```C
#include <stdio.h>
#include <ctype.h>

int main(void) {
  char gender = 'M';
  printf("%c\n", toupper(gender));
  printf("%c\n", gender + 32);
  return 0;
}
```

---


<!-- slide data-notes="" -->


==赋值==: 通过赋值的方式获得值

```C{.line-numbers}
height = 8;
lenght = 12;
width = 10;
gender = 'M';
```

`8`, `12`, `10`为常量

```C
char name[30] = "Alex";
char nation[20] = "China";
char address[60] = "XianLin Avenue, Qixia District, Nanjing, China 210023";
```

---


##### 变量与赋值 - 赋值

---

变量在赋值或者以其他方式使用之前必须先声明

```C{.line-numbers}
height = 9; /*** WRONG ***/
int height;
```

把包含小数点常量赋值给float型变量时, 最好在常量后加字母f:

```C
float profit = 2150.48f;
```

double类型的变量赋值不要加字母f: 

```C
double pi = 3.14159;
```

---
<!-- slide data-notes="" -->


##### 常量与符号常量

---

==常量==: 程序运行过程中其值已知且不能改变的量, 如 `8`, `12`, `10`, `'M'`

==符号常量==: 给常量起一个名字, 提高可读性、便于修改

- 宏定义: 预处理命令, 结尾==没有分号==

```C
#define PI 3.14159
#define GRAM_PER_MOL 32
```

- const限定: 声明为只读变量

```C
const double MOL = 6.02E23;
const int GRAM_PER_MOL = 32;
```

---


<!-- slide data-notes="" -->


##### 演示: Circle

---

给定一个圆的==半径== (如 $10$), 计算其==周长==和==面积==

$L = 2\pi r$ &emsp; $S = \pi r^2$

- 每个结果各占一行

- 小数点后保留两位

```C
/*
 * circle.c(计算周长和面积)
 */
#include <stdio.h>

int main(void) {
    int radius = 10;

    double circumference = 2 * 3.14159 * radius;
    double area = 3.14159 * radius * radius;

    // .2: precision 小数点后保留几位
    printf("circumference = %.2f\narea = %.2f\n", circumference, area);
    return 0;
}
```

---


<!-- slide data-notes="" -->


##### 演示: Sphere

---

给定一个球的==半径== (如 $100$), 计算其==表面积==和==体积==

$A = 4 \pi r^2\quad V = \frac{4}{3} \pi r^3$

- 每个结果占 $1$ 行, 小数点后保留 $4$ 位

- 每个结果至少占 $15$ 字符, 左对齐

```C
/*
 * sphere.c(球的体积和面积)
*/
#include <stdio.h>

int main() {
    int radius = 100;

    double surface_area = 4 * 3.14159 * radius * radius;
    double volume = 4.0 / 3 * 3.14159 * radius * radius * radius;

    // 15: width
    printf("%-15.4f : surface_area\n%-15.4f : volume\n",
           surface_area, volume);
}
```

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. `unsigned int` 与 `int` 的区别是什么？查看类型占用字节数用什么运算符？

2. 用 `#define` 定义符号常量时行末要不要分号？`const` 呢？

3. `INT_MAX` 在哪个头文件中定义？它代表什么？

4. 计算圆的面积时为什么要用符号常量 `PI` 而不是直接写 `3.14159`？

<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---



