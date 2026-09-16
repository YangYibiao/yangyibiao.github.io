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

## 数组作函数参数

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 回顾: 一维数组作参数

- 二维数组作参数 (只能省略第一维)

- 案例: 矩阵转置、成绩统计的函数化

- 课堂编码

---


<!-- slide data-notes="" -->


##### 回顾: 一维数组作参数

---

上周排序函数用的写法, 三条规则回顾:

```C
int sum_array(int a[], int n)    /* 1. 形参: int a[], 长度单独传 */
{
  int i, sum = 0;
  for (i = 0; i < n; i++)
    sum += a[i];
  return sum;
}

total = sum_array(b, LEN);       /* 2. 调用: 只写数组名, 不加 [] */
```

- ==函数里改数组 = 改原数组==: 排序函数正是这样工作的

- 原因第 10 周指针章解释 (数组名传的是地址)

---


<!-- slide data-notes="" -->


##### 二维数组作参数

---

二维数组作参数时, ==只能省略第一维==的长度——列数必须写出来:

```C
int sum_matrix(int a[][4], int rows)   /* 列数 4 不能省 */
{
  int i, j, sum = 0;
  for (i = 0; i < rows; i++)
    for (j = 0; j < 4; j++)
      sum += a[i][j];
  return sum;
}
```

- 调用: `sum_matrix(m, 3)`——传数组名 + 行数 (m 是 `int[3][4]`)

- 为什么列数不能省? 编译器要知道"==一行有多长=="才能算出 `a[i][j]` 的位置

---


<!-- slide data-notes="" -->


##### 案例: 矩阵转置函数化

---

把昨天的转置逻辑封装成函数:

```C{.line-numbers}
/* a: rows×4 的矩阵, b: 4×rows 的转置结果 */
void transpose(int a[][4], int b[][3], int rows)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < 4; j++)
      b[j][i] = a[i][j];
}
```

```C
int a[3][4] = { ... }, b[4][3];
transpose(a, b, 3);        /* b 得到 a 的转置 */
```

- 形参里两个二维数组: `a[][4]` 和 `b[][3]`——各自写清自己的==列数==

---


<!-- slide data-notes="" -->


##### 案例: 成绩统计函数化

---

求每个学生的总分 (每行求和), 结果写回一个一维数组:

```C{.line-numbers}
/* scores: n 名学生 × 3 门课; sums: 存每个人的总分 */
void row_sums(int scores[][3], int n, int sums[])
{
  for (int i = 0; i < n; i++) {
    sums[i] = 0;
    for (int j = 0; j < 3; j++)
      sums[i] += scores[i][j];
  }
}
```

```C
int scores[5][3] = { ... };
int totals[5];
row_sums(scores, 5, totals);    /* totals 里是 5 个学生的总分 */
```

- 二维数组进 (`scores`)、一维数组出 (`sums`)——都是"数组作参数"

- 把 `sums[i] += scores[i][j]` 改成 `sums[j] += scores[i][j]` 就变成==按列统计==

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

为二维数组写三个函数:

1. 求全部元素之和: `int sum_matrix(int a[][4], int rows)`

2. 求第 col 列的平均分: `double col_average(int scores[][3], int n, int col)`

3. 判断矩阵是否对称: `int is_symmetric(int a[][3], int n)` (a[i][j] == a[j][i])

<span class="blue">:fa-lightbulb-o:</span> 提示: 每个函数第一步都是想清楚==形参的列数写多少==

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 二维数组作函数参数时，哪一维的长度可以省略？为什么？

2. `void f(int a[][4])` 能接收 `int m[3][5]` 吗？

3. 矩阵转置函数 `transpose(int a[][4], int b[][3], int rows)` 中，b 的列数为什么是 3？

4. 数组作参数时，函数里对数组元素的修改会不会影响调用者的数组？

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="../figs/see-you.png" width=500px>
</div>

---


