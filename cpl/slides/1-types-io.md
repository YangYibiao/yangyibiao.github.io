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

## C语言基础

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->


##### 提纲

---

- 变量

- 数据类型

- 表达式

- 输入输出


<!-- slide data-notes="" -->


##### Circle.c

---

- ==输入半径 $r$: radius==
- ==输出:==
1. 周长  $L = 2\pi r$
2. 面积  $S = \pi r^2$
3. 球面面积 $A = 4 \pi r^2$
4. 体积 $V = \frac{4}{3} \pi r^3$
- ==要求:==
1. 每个结果占 $1$ 行
2. 小数点后保留 $4$ 位
3. 每个结果至少占 $15$ 字符, 左对齐
  > `_______________ : surface_area`
  > `_______________ : volume`

[演示-circle.c](../code/1-types-io/circle.c)

---


<!-- slide data-notes="" -->


##### mol.c

---

<font size = "7">$6$ 克氧气的分子数是多少?</font>

<br>

$Q = 6 / 32 \times 6.02 \times 10^{23}$

<br>

两种格式输出, 结果均使用<mark>科学计数法</mark>表示

- 第一行结果, 小数点后保留 $3$ 位
- 第二行结果, 保留 $5$ 位有效数字


[演示mol.c](../code/1-types-io/mol.c)

---



<!-- slide data-notes="" -->


##### A naive administration system

---

- ==录入信息==
1. Name (EN)     Gender (F/M)  （姓名、性别）
2. Birthday (mm-dd-yyyy)     Weekday (Xyz.) （出生日期、星期几）
3. C  Music Medicine （三门课程成绩）
4. Mean (.d)     Standard Deviation (.dd)    Ranking ($\%$) （平均成绩、标准差、排名）

- ==录入要求==
1. 每组信息占一行
2. 各项信息使用 `\t` 间隔
3. 各项信息遵循特定格式要求


Xiaojing Nan  F
05-20-1902    Tue.
100           90     80
90            5%

[演示-admin.c](../code/1-types-io/admin.c)


<!-- slide data-notes="" -->

##### char

---

![alt text](figs/img/char-image.png)

A `char` is actually an `int`.

<!-- slide data-notes="" -->

##### c string

--- 

# <code><font color = red>C string</font></code>
<code><font color = red size = 8>char first_name[] = "Tayu";</code></font>

A C string is a null-terminated (`\0`) sequence of characters.

String literal: 'T', 'a', 'y', 'u', '\0'



<!-- slide data-notes="" -->

##### Conversion Specification

---

<!--fit--> <code><font color = green><font color = red>%</font>[flags][width][.[precision]]<font color = red>specifier</font></font></code>

- <code><font color = red size = 7>%d</font></code>: decimal `int`
- <code><font color = red size = 7>%f</font></code>: `double`
- <code><font color = red size = 7>%e %E</font></code>: `double` ($-d.ddd \;\text{e} \pm dd$)
- <code><font color = red size = 7>%c</font></code>: `char`
- <code><font color = red size = 7>%s</font></code>: `C string`
- <code><font color = red size = 7>%%</font></code>: `%`




