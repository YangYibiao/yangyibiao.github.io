---
presentation:
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

## 函数 (II) · 声明、参数与函数化改造

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 函数化改造: 素数、leap、primes、stars

- 数组作参数: 一维、二维、排序封装、矩阵与成绩案例

- 函数与栈

- 课堂编码

- 课堂小测

---


<!-- slide data-notes="" -->##### 程序: 判定素数

---

==现场演示==: 写一个函数 `is_prime(n)` 判断素数, 主函数读入并输出结果

样例:

```
输入一个数: 34
不是素数
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 判断逻辑第 5 周写过 (break 版)——这次把它==做成函数==

---



<!-- slide data-notes="" -->


##### 程序: 判定素数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
/* 判断一个数是否为素数 */
#include <stdio.h>

int is_prime(int n)
{
  int divisor;

  if (n <= 1) {
    return 0;
  }
  for (divisor = 2; divisor <= n / divisor; divisor++) {
    if (n % divisor == 0) {
      return 0;
    }
  }
  return 1;
}

int main(void)
{
  int n;

  printf("输入一个数: ");
  scanf("%d", &n);
  if (is_prime(n)) {
    printf("是素数\n");
  } else {
    printf("不是素数\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 判断逻辑封装进 `is_prime`——main 只剩输入输出, 一眼看清

- `divisor <= n / divisor` 是检查到 $\sqrt{n}$ 的等价写法 (不用 math.h), 而且==不会溢出==

- 反例: 判断 n = 2147483647 (int 上限, 本身是素数), divisor 试到 46341 时 `46341 × 46341 = 2147488281` 超出 int 上限 2147483647, 溢出变成==负数== → 条件变 false, 循环提前结束, 素数被误判

- 返回 1/0, 调用处 `if (is_prime(n))` 直接当条件——与 8-1 的写法一致

</div>

</div>

---

<!-- slide data-notes="" -->


##### leap.c: 原版 vs 函数版

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:14px;align-items:start;font-size:0.5em;">

<div>

```C
/* 原版: 判断逻辑在 main 里 */
#include <stdio.h>
int main(void) {
  int year = 0;
  scanf("%d", &year);
  int leap = 0;
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    leap = 1;
  }
  if (leap == 0) {
    printf("%d 是平年\n", year);
  } else {
    printf("%d 是闰年\n", year);
  }
  return 0;
}
```

</div>

<div>

```C
/* 函数版: 判断逻辑抽成函数 */
#include <stdio.h>
int is_leap_year(int);
int main(void) {
  int year = 0;
  scanf("%d", &year);
  int leap = is_leap_year(year);
  if (leap == 0) {
    printf("%d 是平年\n", year);
  } else {
    printf("%d 是闰年\n", year);
  }
  return 0;
}
int is_leap_year(int n) {
  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    return 1;
  }
  return 0;
}
```

</div>

</div>

<div style="margin-top:8px;">

- 判断逻辑抽成 `is_leap_year(year)`, main 只剩输入输出

- 返回 1/0, `if (is_leap_year(year))` 直接当条件

- 以后想再判断闰年, 调函数即可——不用重写条件

<a href="code/leap.c" target="_blank">leap.c</a> · <a href="code/leap-re.c" target="_blank">leap-re.c</a>

</div>

---

<!-- slide data-notes="" -->##### primes.c: 原版 vs 函数版

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:14px;align-items:start;font-size:0.5em;">

<div>

```C
/* 原版: 判断逻辑埋在 main 里 */
#include <stdio.h>

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    // 判断 i 是否素数
    int prime = 1;
    for (int j = 2; j <= i / j; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      count++;
    }
  }
  printf("\n素数个数: %d", count);
  return 0;
}
```

</div>

<div>

```C
/* 函数版: is_prime 抽出来 */
#include <stdio.h>

int is_prime(int n) {
  for (int j = 2; j <= n / j; j++) {
    if (n % j == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    if (is_prime(i) == 1) {
      count++;
    }
  }
  printf("\n素数个数: %d", count);
  return 0;
}
```

</div>

</div>

<div style="margin-top:8px;">

- 原版: 素数逻辑埋在 main 的两层循环里; 函数版: `is_prime(i)` 一行调用——和第 4 页是同一个函数

- 函数化改造的套路: 把 "一块逻辑" 抽出来 → 起名字 → 参数进、返回值出

<a href="code/primes.c" target="_blank">primes.c</a> · <a href="code/primes-re.c" target="_blank">primes-re.c</a>

</div>

---

<!-- slide data-notes="" -->


##### stars.c

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
#include <stdio.h>

int main() {
  int lines = 0;
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++) {
    // 打印空格 (居中)
    for (int j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }
    // 打印 2*i+1 颗星
    for (int j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }
    if (i != lines - 1) {
      printf("\n");
    }
  }

  return 0;
}
```

</div>

<div style="flex:1;">

- 程序里 "打印一行 2*i+1 颗星" 的循环, 就是可以抽出来的函数 `print_stars(n)`

- 留到课堂编码: 你来做这个改造

- 提示: 打印空格的循环也可以抽成 `print_spaces(n)`——每个函数只做==一件事==

<a href="code/stars.c" target="_blank">stars.c</a>

</div>

</div>

<!-- slide data-notes="" -->


##### 函数化改造: 把排序封装成函数

---

第 7 周的排序把整段循环写在 main 里——想给另一组数据排序, 就得再抄一遍

```C
void sort(int a[], int n)          /* 把选择排序装进函数 */
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
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
  for (i = 0; i < n; i++) {
    sum += a[i];
  }
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
  for (i = 0; i < rows; i++) {
    for (j = 0; j < 4; j++) {
      sum += a[i][j];
    }
  }
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
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      b[j][i] = a[i][j];
    }
  }
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
    for (int j = 0; j < 3; j++) {
      sums[i] += scores[i][j];
    }
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

---


<!-- slide data-notes="" -->


##### 函数与栈

---

先想一个问题: 函数返回之后, 它里面的局部变量==去哪儿了==? 下次再调用, 为什么又是全新的?

<div style="font-size:0.82em;line-height:2.1;background:rgba(38,139,210,0.06);padding:12px 18px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);font-family:Operator, 'LXGWWenKai', monospace;">
调用前:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[main]<br>
main 调用 f:&nbsp;&nbsp;&nbsp;[main][f]&nbsp;&nbsp;&nbsp;&nbsp;← 压栈: 放一张 "便签" (返回地址 + f 的参数和局部变量)<br>
f 调用 g:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[main][f][g]&nbsp;&nbsp;← 再压一张<br>
g 返回:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[main][f]&nbsp;&nbsp;&nbsp;&nbsp;← 弹栈: 揭掉最上面的便签, g 的局部变量随之消失<br>
f 返回:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[main]
</div>

- 每次函数调用, 系统在==调用栈==(call stack) 上放一张 "便签": 记下==返回地址==、==参数==、==局部变量==

- 函数返回时揭掉这张便签——局部变量 "出了函数就没了", 就是这个原因

- 栈是==后进先出==: 最后调用的函数最先返回——像一摞盘子, 只能从最上面拿

<span class="blue">:fa-lightbulb-o:</span> 周三的递归: 函数一层层调用自己, 栈就一层层长高——这个机制是理解递归的地基

---

<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

把下面的程序改写成"主函数 + 若干函数"的结构:

1. 计算平均值: `double average(double a, double b)`

2. 判定素数: `int is_prime(int n)`

3. 打印一行星号: `void print_stars(int n)`

<span class="blue">:fa-lightbulb-o:</span> 设计原则回顾: 每个函数只做==一件事==

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 概念: 函数调用时栈上发生了什么？局部变量在函数返回后会怎样？

2. 概念: 函数化改造后, `main` 里应该剩下什么？`is_prime(n)` 返回什么类型？

3. 代码阅读: 阅读 leap.c 函数版, `is_leap_year(1900)` 返回什么？为什么？

4. 纠错: 闰年判断写成 `year % 4 == 0 || year % 400 == 0` (少了 `&& year % 100 != 0`) 会怎样？

---
<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


