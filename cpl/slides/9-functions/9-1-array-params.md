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

## 函数进阶: 数组作参数与作用域

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 函数化改造: 把排序封装成函数

- 一维数组作参数

- 二维数组作参数 (只能省略第一维)

- 案例: 矩阵转置、成绩统计的函数化

- 作用域与生命期

- 课堂编码与小测

---


<!-- slide data-notes="" -->


##### 函数化改造: 把排序封装成函数

---

第 7 周的排序把整段循环写在 main 里——想给另一组数据排序, 就得再抄一遍

```C
void sort(int a[], int n)          /* 把选择排序装进函数 */
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[min]) min = j;
    int t = a[i]; a[i] = a[min]; a[min] = t;
  }
}
```

```C
sort(a, 10);     /* 排 a 的前 10 个元素 */
sort(b, 5);      /* 同一段逻辑, 换个数组再用 */
```

- ==函数化改造==: 把重复的逻辑抽出来封装成函数——本周的核心任务

---


<!-- slide data-notes="" -->


##### 一维数组作参数

---

函数要操作数组, 就把数组传给函数:

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

- 原因第 11 周指针与数组揭晓 (数组名传的是地址)

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

把第 6 周的转置逻辑封装成函数:

```C{.line-numbers}
/* a: 3×4 的矩阵, b: 4×3 的转置结果 */
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

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

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

</div>

<div style="flex:1;">

求每个学生的总分 (每行求和), 结果写回一个一维数组:

二维数组进 (`scores`)、一维数组出 (`sums`)——都是"数组作参数"

- 按列统计要单独写: `sums[j]` 的清零放在==行循环之外== (只清一次), 累加行改成 `sums[j] += scores[i][j]` (结果数组长度变成 3)

</div>

</div>

<!-- slide data-notes="" -->


##### 标识符的作用域

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.7em;">

```C
int x = 0;            /* 文件作用域 */
void f(void)
{
  int x = 1;        /* 块作用域, 屏蔽全局 x */
  printf("%d", x);  /* 打印 1 */
}
```

</div>

<div style="flex:1;">

==作用域==: 标识符可以被使用的那段代码范围

- ==块作用域==: 函数体内 {} 覆盖的范围——局部变量、形式参数

- ==文件作用域==: 从定义位置到文件末尾——全局变量

- 内层屏蔽外层: 内层同名变量会==遮蔽==外层的

==局部变量==: 定义在函数内, 出了函数就不可见

- ==全局变量==: 定义在函数外, 整个文件可见; 少用为妙 (谁都可能改它)

</div>

</div>

<!-- slide data-notes="" -->


##### 变量的生命期

---

- ==动态变量==(默认): 函数被调用时诞生, 函数返回时消亡

- ==静态变量==(static): 与程序同生共死, 函数返回后==保留原值==

```C
void f(void)
{
  static int count = 0;  /* 只初始化一次 */
  count++;
  printf("第 %d 次调用\n", count);
}
```

- static 局部变量 = 带记忆的局部变量 (下次调用接着用上次的值)

---


<!-- slide data-notes="" -->


##### 演示: 局部变量的"垃圾值"

---

<div style="font-size:0.8em;">

```C
void f(void) {
    int i;                    /* 没有初始化 */
    printf("i = %d\n", i);
}
int main(void) { f(); return 0; }
```

</div>

一次运行的结果 (每次可能不同!): 

```
i = 32764
```

- 动态局部变量诞生时==不会自动清零==——里面是内存里残留的"垃圾值"

- 每次运行、每台机器都可能不同; 调试器里恰好是 `0` 只是假象

- 教训: ==局部变量必须初始化后再使用==; 编译加 `-Wall` 有时能提示 "used uninitialized"

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

为二维数组写三个函数:

1. 求全部元素之和: `int sum_matrix(int a[][4], int rows)`

2. 求第 col 列的平均分: `double col_average(int scores[][3], int n, int col)`

3. 判断一个 3×3 矩阵是否对称: `int is_symmetric(int a[3][3])`

<span class="blue">:fa-lightbulb-o:</span> 提示: 每个函数第一步都是想清楚==形参的列数写多少== (样例: `sum_matrix({{1,2,3,4},{5,6,7,8}}, 2)` 应为 36)

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 一维数组作参数的写法有哪两个编号要点？为什么函数里改数组会改到原数组？

2. `void f(int a[][4])` 能接收 `int m[3][5]` 吗？

3. 矩阵转置函数 `transpose(int a[][4], int b[][3], int rows)` 中，b 的列数为什么是 3？

4. static 局部变量和普通局部变量有什么不同？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


