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

## 函数 (II) · 数组参数与函数化改造

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 回顾: 形式参数 vs 实际参数

- 回顾: 按值传递 (如何理解 + swap 为什么不生效)

- 函数化改造: 素数、闰年 (return 让代码更简洁)、素数统计、星号塔

- 课堂编码: 阶乘改写

- 数组作参数: 一维、排序封装、二维、生命游戏、成绩案例 (转置留作练习)

- 函数化四步: 10 个例子的总结收口

- 函数调用栈 (概念与例子)

- 课堂编码: 挑战 · 组合数

- 课堂小测

---


<!-- slide data-notes="" -->##### 回顾: 形式参数 vs 实际参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C{.line-numbers}
int is_prime(int n)      /* n 是==形式参数==: 定义里的占位名 */
{
  int d;

  if (n <= 1) {
    return 0;
  }
  for (d = 2; d <= n / d; d++) {
    if (n % d == 0) {
      return 0;
    }
  }
  return 1;
}
```

```C
int flag1 = is_prime(97);   /* 97 是==实际参数==: 返回值可保存 */
int flag2 = is_prime(m);   /* 变量也行: 把 m 的值复制给形参 n */
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- ==形式参数==: 函数定义里的占位名; 调用时拿到的是实参的==副本==

- 占位名是==定义时==的视角; 进入函数体后, 形参就是一个==已初始化的局部变量==——可以读, 也可以改 (下一页 `f` 里的 `n = n + 1` 就会改它)

- ==实际参数==: 调用时传进去的值——可以是常量、变量、任意同类型的表达式

- 标量按值传: 改形参==不影响==实参 (swap 陷阱, 上一讲讲过)

</div>

</div>

---

<!-- slide data-notes="" -->##### 如何理解按值传递

---

==按值传递==: 调用时, 把实参的==值==复制一份赋给形参——之后两者==互不影响==

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C{.line-numbers}
void f(int n)
{
  n = n + 1;              /* 改的是副本 */
  printf("n = %d\n", n);
}

int main(void)
{
  int x = 10;
  f(x);                   /* ≈ 函数开头先执行 n = x */
  printf("x = %d\n", x); /* 10, 不是 11 */
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

- 调用 `f(x)` 相当于函数开头先执行 ==`n = x`==——x 是赋值表达式的==右值== (只读它的值); 形参 n 拿到的是 x 的==值==, 不是 x 本身

- 类比: 把文件==复印==一份交给函数——复印件上的修改不会影响原件

- 数组是==例外==: 数组作参数时函数却能改到原数组——为什么是例外, 后面==指针部分==会详细介绍和分析

</div>

</div>

---

<!-- slide data-notes="" -->##### 回顾: swap 为什么不生效

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
void swap(int a, int b) {
    int t = a;  a = b;  b = t;      /* 交换的是 a、b 的值 */
}

int main(void) {
    int x = 3, y = 5;
    swap(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

运行结果:

```
x = 3, y = 5
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

- 按值传递的直接体现: `a`、`b` 拿到 `x`、`y` 的==值== (即副本)——函数内交换的是 a、b 的值, 与外面的 x、y ==没有关系==

- 换个角度看: 调用 `swap(x + 6, y + 5)` 传进去的是表达式的==值==, 没人指望 x、y 被改; `swap(x, y)` 传的同样是值, 不是变量本身

- 这是新手最困惑的现象之一: 函数明明执行了, 外界却看不到任何变化

- 记住这个结论——后面==指针部分==会用 `swap(&x, &y)` 真正交换两个变量; 想想 `scanf("%d", &x)` 里的 `&`: 它传的是同一种东西

</div>

</div>

---

<!-- slide data-notes="" -->##### 程序: 判定素数 · 原版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

原版 (判断逻辑埋在 main 里):

```C
#include <stdio.h>
int main(void) {
  int n, d, prime = 1;
  scanf("%d", &n);
  for (d = 2; d * d <= n; d++)
    if (n % d == 0) { prime = 0; break; }
  if (prime == 1) printf("是素数\n");
  else printf("不是素数\n");
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

<div style="background:#fdf6e3;border-left:3px solid #b58900;padding:6px 10px;margin-bottom:8px;">

==改造三步==: ① 输入是什么? ② 输出是什么? ③ 函数叫什么名字?——后面每个例子都这么问

</div>

==口头回答==: 三步怎么答? 下一页对照

<span class="blue">:fa-lightbulb-o:</span> 提示: 输入是 n, 输出是 "是/不是" (1/0), 函数名 is_prime

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#b58900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 打开代码工作区</a> <a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/prime-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 prime-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 程序: 判定素数 · 函数版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

函数版 (main 只剩输入输出):

```C
#include <stdio.h>
int is_prime(int n) {
  int d;
  if (n <= 1) return 0;
  for (d = 2; d <= n / d; d++)
    if (n % d == 0) return 0;
  return 1;
}
int main(void) {
  int n;
  printf("输入一个数: ");
  scanf("%d", &n);
  if (is_prime(n)) printf("是素数\n");
  else printf("不是素数\n");
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.85em;line-height:1.5;">

- `divisor <= n / divisor` 是 $\sqrt{n}$ 的等价写法 (不用 math.h), 不会溢出; 原版的 `d * d` 写法在 n 近 int 上限时溢出 (有符号溢出是==未定义行为==)——结果为负时条件恒真, 循环停不下来

- 顺手补上 `n <= 1`——原版对 n = 1 会误判; 改造不只是搬代码, 也顺手修 bug

- 返回 1/0, `if (is_prime(n))` 直接当条件——与 8-1 一致

</div>

</div>

---

<!-- slide data-notes="" -->##### leap.c: 原版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

第 4 周写过的闰年判断 (非函数版):

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

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==口头回答==: 把判断逻辑抽成函数, 三步怎么答? 下一页对照

<span class="blue">:fa-lightbulb-o:</span> 提示: 先回答三步——输入是年份, 输出是 "是/不是", 函数名?
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/leap-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 leap-re.c</a>


</div>

</div>

---



<!-- slide data-notes="" -->##### leap.c: 函数版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
/* 函数版: 判断逻辑抽成函数 */
#include <stdio.h>
int is_leap_year(int);
int main(void) {
  int year = 0;
  scanf("%d", &year);
  if (is_leap_year(year)) {
    printf("%d 是闰年\n", year);
  } else {
    printf("%d 是平年\n", year);
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

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 判断逻辑抽成 `is_leap_year(year)`, main 只剩输入输出; 开头的 `int is_leap_year(int);` 是 8-1 讲过的==函数原型==: 先声明, 后使用

- 返回 1/0, `if (is_leap_year(year))` 直接当条件; 以后想再判断, 调函数即可

<a href="code/leap-re.c" target="_blank">leap-re.c (改造前)</a> · <a href="code/leap-func.c" target="_blank">leap-func.c (函数版)</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 改造进阶: return 让代码更简洁

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
/* 啰嗦版: 用 if 包装 */
int is_leap_year(int n) {
  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    return 1;
  }
  return 0;
}
```

```C
/* 简洁版: 布尔表达式直接 return */
int is_leap_year(int n) {
  return (n % 4 == 0 && n % 100 != 0) || (n % 400 == 0);
}
```

```C
int is_even(int n) { return n % 2 == 0; }          /* 偶数 */
int is_digit(char c) { return c >= '0' && c <= '9'; }  /* 数字 */
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- 判断的结果本身就是 1 或 0——不需要 if 包装, ==直接 return 表达式==

- 一类经典小函数都是 "一行函数": 偶数、数字、大小写字母……

- ==提前 return== 也让代码更简洁: 找到就返回, 不需要 flag 变量——`is_prime` 就是这么写的

</div>

</div>

---

<!-- slide data-notes="" -->##### primes.c: 原版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

统计 2~max 的素数个数 (非函数版):

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

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==口头回答==: 把 "判断 i 是否素数" 的逻辑抽成 `is_prime(i)`

<span style="font-size:0.9em;">进一步: 把统计循环也抽成 `count_primes(max)`——main → count_primes → is_prime ==两层调用链==</span>

<span class="blue">:fa-lightbulb-o:</span> 复用前面刚写的 `is_prime`
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/primes-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 primes-re.c</a>


</div>

</div>

---



<!-- slide data-notes="" -->##### primes.c: 函数版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
/* 函数版: is_prime + count_primes 两层 */
#include <stdio.h>

int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int j = 2; j <= n / j; j++) {
    if (n % j == 0) {
      return 0;
    }
  }
  return 1;
}

int count_primes(int max) {        /* 统计也抽成函数 */
  int count = 0, i;

  for (i = 2; i <= max; i++) {
    if (is_prime(i) == 1) {        /* 调用 is_prime */
      count++;
    }
  }
  return count;
}

int main() {
  int max;
  scanf("%d", &max);
  printf("\n素数个数: %d", count_primes(max));   /* 一行调用 */
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.95em;line-height:1.7;">

- ==两层调用链==: main → `count_primes` → `is_prime`——函数不光能被 main 调用, 还能==调用别的函数==

- `is_prime` 被复用了==max-1 次== (i = 2..max), 与前面判定素数的函数是同一个——写一次, 处处用

- main 只剩读入和一行输出——主函数开始像一份 "说明书": 只写步骤, 细节藏进函数

<a href="code/primes-re.c" target="_blank">primes-re.c (改造前)</a> · <a href="code/primes-func.c" target="_blank">primes-func.c (函数版)</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### stars.c: 原版

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

- ==口头回答==: 程序里 "打印一行 2*i+1 颗星" 的循环, 就是可以抽出来的函数 `print_stars(n)`

- 提示: 打印空格的循环也可以抽成 `print_spaces(n)`——每个函数只做==一件事==
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/stars-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 stars-re.c</a>


<a href="code/stars.c" target="_blank">stars.c (改造前)</a>

</div>

</div>

<!-- slide data-notes="" -->##### stars.c: 函数版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.58em;">

```C{.line-numbers}
/* 星号塔: 函数版 (每个函数只做一件事) */
#include <stdio.h>

void print_spaces(int n)
{
  int j;

  for (j = 0; j < n; j++) {
    printf(" ");
  }
}

void print_stars(int n)
{
  int j;

  for (j = 0; j < n; j++) {
    printf("*");
  }
}

int main(void)
{
  int lines, i;

  printf("Enter lines: ");
  scanf("%d", &lines);

  for (i = 0; i < lines; i++) {
    print_spaces(lines - 1 - i);
    print_stars(2 * i + 1);
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

- 两个循环各自成函数: `print_spaces` 和 `print_stars`——每个函数只做==一件事==

- main 里的主体只剩一行行的==调用==, 星号塔的结构一目了然

- 这就是改造的目标: 主函数读起来像 "说明书", 细节都藏进函数

<a href="code/stars-re.c" target="_blank">stars-re.c (改造前)</a> · <a href="code/stars-func.c" target="_blank">stars-func.c (函数版)</a>


</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂编码: 阶乘改写

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
#include <stdio.h>

int main(void)
{
  int n, i;
  long f = 1;

  printf("输入 n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {    /* 计算 n! */
    f = f * i;
  }
  printf("%d! = %ld\n", n, f);
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==任务==: 抽出 `long factorial(int n)`, main 只剩输入、调用、输出

<span class="blue">:fa-lightbulb-o:</span> 提示: 阶乘函数在后面的递归课上还会==再次登场== (n! = n × (n-1)!)

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/factorial-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 factorial-re.c</a>

</div>

</div>

---


<!-- slide data-notes="" -->##### 一维数组作参数 · 原版

---

求数组元素之和 (非函数版):

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C{.line-numbers}
/* 求 b 的元素之和: 非函数版 */
#include <stdio.h>

int main(void)
{
  int b[5] = {3, 7, 1, 9, 4};
  int sum = 0, i;

  for (i = 0; i < 5; i++) {
    sum += b[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==2 分钟, 自己写==: 把求和逻辑抽成函数, main 只剩调用和输出

<span style="font-size:0.9em;">动手前想清楚两件事: ==数组怎么传==? ==长度怎么传==?——下一页揭晓标准写法及原因</span>

<span class="blue">:fa-lightbulb-o:</span> 提示: 想对另一组数据求和? 非函数版只能把循环再写一遍——今天要解决的就是这个

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/sum-array-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 sum-array-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 一维数组作参数

---

<div style="font-size:0.8em;margin:0;">函数要操作数组, 就把数组传给函数:</div>

<div style="font-size:0.95em;">

```C{.line-numbers}
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

</div>

<div style="text-align:center;margin:2px 0;">
<svg viewBox='0 0 640 120' style='max-width:100%;height:120px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='arr1d' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker></defs><text x='300' y='14' font-size='10' fill='#586e75' font-weight='700'>main: int b[5] = {3, 7, 1, 9, 4};</text><g font-size='13' fill='#073642' text-anchor='middle' font-weight='700'><rect x='300' y='22' width='44' height='30' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='322' y='42'>3</text><rect x='344' y='22' width='44' height='30' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='366' y='42'>7</text><rect x='388' y='22' width='44' height='30' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='410' y='42'>1</text><rect x='432' y='22' width='44' height='30' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='454' y='42'>9</text><rect x='476' y='22' width='44' height='30' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='498' y='42'>4</text></g><g font-size='8.5' fill='#586e75' text-anchor='middle' font-family='Menlo, monospace'><text x='322' y='66'>1000</text><text x='366' y='66'>1004</text><text x='410' y='66'>1008</text><text x='454' y='66'>1012</text><text x='498' y='66'>1016</text></g><rect x='18' y='20' width='240' height='84' rx='8' fill='#fdf6e3' stroke='#268bd2' stroke-width='2.5'/><text x='28' y='36' font-size='9.5' fill='#268bd2' font-weight='700'>sum_array 的栈帧</text><g font-weight='700'><rect x='28' y='44' width='95' height='24' rx='5' fill='#dceaf5' stroke='#268bd2' stroke-width='1.5'/><text x='75' y='60' font-size='11' fill='#073642' text-anchor='middle'>a = 1000</text><rect x='132' y='44' width='80' height='24' rx='5' fill='#fdf6e3' stroke='#586e75' stroke-width='1.5'/><text x='172' y='60' font-size='11' fill='#073642' text-anchor='middle'>n = 5</text></g><text x='28' y='90' font-size='8.5' fill='#859900'>函数里 a[i] = 改 b[i]</text><path d='M258 56 H296 V52' stroke='#268bd2' stroke-width='2' fill='none' marker-end='url(#arr1d)'/><text x='262' y='84' font-size='9' fill='#268bd2'>只传开头地址</text><text x='18' y='114' font-size='9.5' fill='#586e75'>数组名传开头位置，不传长度 → 长度必须单独传 n</text></g></svg>
</div>

<div style="font-size:0.75em;line-height:1.4;">

- 形参 `int a[]` 只拿到数组的==开头位置==, 不携带长度信息——长度必须由调用者单独传

- ==函数里改数组 = 改原数组==: 排序函数正是这样工作的

- 为什么能改到原数组, 原因在后面的指针部分揭晓 (数组名传的是地址)

<span style="font-size:0.9em;"><a href="code/sum-array-re.c" target="_blank">sum-array-re.c (改造前)</a> · <a href="code/sum-array-func.c" target="_blank">sum-array-func.c (函数版)</a></span>

</div>

---


<!-- slide data-notes="" -->##### 排序封装: 原版

---

第 7 周的选择排序 (非函数版):

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C{.line-numbers}
/* 选择排序: 非函数版 */
#include <stdio.h>

int main(void)
{
  int a[10], n = 10, i, j;

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int t = a[i];
    a[i] = a[min];
    a[min] = t;
  }

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==口头回答==: 把排序逻辑抽成函数, main 里只剩读入、一行调用、输出

<span style="font-size:0.9em;">动手前想清楚: ==数组怎么传==? ==长度怎么传==?——和 sum_array 是同样的两个问题</span>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/sort-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 sort-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 函数化改造: 把排序封装成函数

---

第 7 周的排序把整段循环写在 main 里——想给另一组数据排序, 就得再写一遍

<div>

```C{.line-numbers}
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

</div>

<div style="font-size:0.8em;line-height:1.5;">

- ==函数化改造==: 把重复的逻辑抽出来封装成函数——本周的核心任务

<span style="font-size:0.9em;"><a href="code/sort-re.c" target="_blank">sort-re.c (改造前)</a> · <a href="code/sort-func.c" target="_blank">sort-func.c (函数版)</a></span>

</div>


---


<!-- slide data-notes="" -->##### 二维数组作参数 · 原版

---

求矩阵元素之和 (非函数版):

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C{.line-numbers}
/* 求 m 的元素之和: 非函数版 */
#include <stdio.h>

int main(void)
{
  int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int sum = 0, i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      sum += m[i][j];
    }
  }
  printf("sum = %d\n", sum);
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==口头回答==: 把求和逻辑抽成函数, main 只剩调用和输出

<span style="font-size:0.9em;">动手前想清楚: 数组怎么传? 行数怎么传? ==列数怎么传==?——二维比一维多一个问题, 下一页揭晓</span>

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/sum-matrix-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 sum-matrix-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 二维数组作参数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.58em;">

```C{.line-numbers}
int sum_matrix(int a[][4], int rows)   /* 列数 4 不能省 */
{
  int sum = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      sum += a[i][j];
    }
  }
  return sum;
}
```

```C
int m[3][4] = { ... };
sum_matrix(m, 3);       /* 数组名 + 行数 */
```

<div style="text-align:center;margin:4px 0 2px;">
<svg viewBox='0 0 400 210' style='max-width:100%;height:175px;display:block;margin:0 auto;'><g font-family='LXGWWenKai, Noto Sans SC, sans-serif'><defs><marker id='arr2d' markerWidth='8' markerHeight='8' refX='7' refY='4' orient='auto'><path d='M0 0 L8 4 L0 8 z' fill='#268bd2'/></marker></defs><text x='18' y='15' font-size='10.5' fill='#073642' font-weight='700'>int a[3][4]：按行连续存放</text><g font-size='9' fill='#586e75' text-anchor='middle'><text x='55' y='24'>j=0</text><text x='89' y='24'>j=1</text><text x='123' y='24'>j=2</text><text x='157' y='24'>j=3</text></g><g font-size='9' fill='#586e75' text-anchor='end'><text x='32' y='43'>i=0</text><text x='32' y='67'>i=1</text><text x='32' y='91'>i=2</text></g><g font-size='11' fill='#073642' text-anchor='middle' font-weight='700'><g><rect x='38' y='28' width='34' height='24' fill='#dceaf5' stroke='#93a1a1'/><rect x='72' y='28' width='34' height='24' fill='#dceaf5' stroke='#93a1a1'/><rect x='106' y='28' width='34' height='24' fill='#dceaf5' stroke='#93a1a1'/><rect x='140' y='28' width='34' height='24' fill='#dceaf5' stroke='#93a1a1'/><text x='55' y='44'>1</text><text x='89' y='44'>2</text><text x='123' y='44'>3</text><text x='157' y='44'>4</text></g><g><rect x='38' y='52' width='34' height='24' fill='#eee8d5' stroke='#93a1a1'/><rect x='72' y='52' width='34' height='24' fill='#eee8d5' stroke='#93a1a1'/><rect x='106' y='52' width='34' height='24' fill='#eee8d5' stroke='#93a1a1'/><rect x='140' y='52' width='34' height='24' fill='#eee8d5' stroke='#93a1a1'/><text x='55' y='68'>5</text><text x='89' y='68'>6</text><text x='123' y='68'>7</text><text x='157' y='68'>8</text></g><g><rect x='38' y='76' width='34' height='24' fill='#fdf6e3' stroke='#93a1a1'/><rect x='72' y='76' width='34' height='24' fill='#fdf6e3' stroke='#93a1a1'/><rect x='106' y='76' width='34' height='24' fill='#fdf6e3' stroke='#93a1a1'/><rect x='140' y='76' width='34' height='24' fill='#fdf6e3' stroke='#93a1a1'/><text x='55' y='92'>9</text><text x='89' y='92'>10</text><text x='123' y='92'>11</text><text x='157' y='92'>12</text></g></g><g font-weight='700'><text x='195' y='40' font-size='10' fill='#586e75'>a[i][j] 的偏移 =</text><text x='195' y='57' font-size='12' fill='#268bd2'>i × 4 + j</text></g><text x='195' y='78' font-size='9.5' fill='#586e75'>列数 4 = 每行 4 个元素</text><text x='195' y='93' font-size='9.5' fill='#586e75'>= 行与行之间的步长</text><path d='M106 100 V132' stroke='#268bd2' stroke-width='2' fill='none' marker-end='url(#arr2d)'/><text x='114' y='120' font-size='9' fill='#268bd2'>按行铺开</text><g font-size='10' fill='#073642' text-anchor='middle' font-weight='700'><rect x='18' y='136' width='30' height='22' fill='#dceaf5' stroke='#93a1a1'/><text x='33' y='151'>1</text><rect x='48' y='136' width='30' height='22' fill='#dceaf5' stroke='#93a1a1'/><text x='63' y='151'>2</text><rect x='78' y='136' width='30' height='22' fill='#dceaf5' stroke='#93a1a1'/><text x='93' y='151'>3</text><rect x='108' y='136' width='30' height='22' fill='#dceaf5' stroke='#93a1a1'/><text x='123' y='151'>4</text><rect x='138' y='136' width='30' height='22' fill='#eee8d5' stroke='#93a1a1'/><text x='153' y='151'>5</text><rect x='168' y='136' width='30' height='22' fill='#eee8d5' stroke='#93a1a1'/><text x='183' y='151'>6</text><rect x='198' y='136' width='30' height='22' fill='#eee8d5' stroke='#93a1a1'/><text x='213' y='151'>7</text><rect x='228' y='136' width='30' height='22' fill='#eee8d5' stroke='#93a1a1'/><text x='243' y='151'>8</text><rect x='258' y='136' width='30' height='22' fill='#fdf6e3' stroke='#93a1a1'/><text x='273' y='151'>9</text><rect x='288' y='136' width='30' height='22' fill='#fdf6e3' stroke='#93a1a1'/><text x='303' y='151'>10</text><rect x='318' y='136' width='30' height='22' fill='#fdf6e3' stroke='#93a1a1'/><text x='333' y='151'>11</text><rect x='348' y='136' width='30' height='22' fill='#fdf6e3' stroke='#93a1a1'/><text x='363' y='151'>12</text></g><g fill='none' stroke-width='2'><path d='M18 164 V170 H138 V164' stroke='#268bd2'/><path d='M138 164 V170 H258 V164' stroke='#b58900'/><path d='M258 164 V170 H378 V164' stroke='#859900'/></g><g font-size='9' text-anchor='middle' font-weight='700'><text x='78' y='182' fill='#268bd2'>第 0 行</text><text x='198' y='182' fill='#b58900'>第 1 行</text><text x='318' y='182' fill='#859900'>第 2 行</text></g><text x='18' y='202' font-size='9.5' fill='#586e75'>所以形参必须写 int a[][4]：编译器要用 4 计算 a[i][j] 的地址</text></g></svg>
</div>

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

- 二维数组作参数, ==只能省略第一维==——列数必须写出来

- 为什么列数不能省? 二维数组在内存里==按行连续存放==; 要跳到第 i 行, 先要知道一行有多少个元素——列数就是这个步长, 所以 `a[][4]` 的 4 不能省

- 调用: 传==数组名 + 行数==——写法朴素, 但数组传的是开头位置, 函数能改到原数组 (和标量不同)

<div style="font-size:0.55em;line-height:1.3;margin-top:2px;"><a href="code/sum-matrix-re.c" target="_blank">sum-matrix-re.c (改造前)</a> · <a href="code/sum-matrix-func.c" target="_blank">sum-matrix-func.c (函数版)</a></div>

</div>

</div>

---

<!-- slide data-notes="" -->##### 生命游戏 · 原版

---



<div style="display:flex;align-items:flex-start;gap:20px;">

<div style="flex:1.25;font-size:0.45em;">

```C{.line-numbers}
/* 演化一代: 数邻居 + 套规则 + 打印, 全在 main 里 */
#include <stdio.h>
#define SIZE 8

int main(void)
{
  int board[SIZE + 2][SIZE + 2] = {{0}};
  int next[SIZE + 2][SIZE + 2] = {{0}};
  int i, j, m, n, cnt;

  /* 初始: 一个滑翔机 (初始画面见右栏) */
  board[2][3] = 1;  board[3][4] = 1;
  board[4][2] = 1;  board[4][3] = 1;  board[4][4] = 1;

  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      cnt = -board[i][j];
      for (m = i - 1; m <= i + 1; m++) {
        for (n = j - 1; n <= j + 1; n++) {
          cnt += board[m][n];
        }
      }
      if (board[i][j] == 1) {
        next[i][j] = (cnt == 2 || cnt == 3);
      } else {
        next[i][j] = (cnt == 3);
      }
    }
  }

  for (i = 1; i <= SIZE; i++) {       /* 打印新一代 */
    for (j = 1; j <= SIZE; j++) {
      printf("%c", next[i][j] ? '*' : '.');
    }
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.75em;line-height:1.5;">

==先看效果==: 左上角的小三角叫==滑翔机==——演化一代后, 它移动了一格:

<div style="font-size:0.55em;font-family:Menlo,Consolas,monospace;line-height:1.35;background:#fdf6e3;padding:8px;border-radius:6px;">
初始:          下一代:
........       ........
..*.....       ........
...*....       ..*.*...
.***....       ...**...
........       ...*....
........       ........
........       ........
........       ........
</div>

==规则==: 活格子活邻居 2 或 3 → 活, 否则死; 死格子活邻居恰好 3 → 活; 边界技巧——四周加一圈 0, 数邻居不用判断边界

==同桌讨论 1 分钟==: 先别写代码——打算拆成几个函数? 每个函数的==输入、输出==是什么?

<span class="blue">:fa-lightbulb-o:</span> 提示: 想演化 10 代? 非函数版要再套一层循环——五层嵌套; 函数版只需一个十代循环

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/game-of-life-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 game-of-life-re.c</a>

</div>

</div>

---


<!-- slide data-notes="" -->##### 生命游戏 · 函数版 (一): 数邻居与演化

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
int count_neighbors(int board[][SIZE + 2], int i, int j)
{
  int cnt = -board[i][j], m, n;

  for (m = i - 1; m <= i + 1; m++) {
    for (n = j - 1; n <= j + 1; n++) {
      cnt += board[m][n];
    }
  }
  return cnt;
}

void next_generation(int board[][SIZE + 2])
{
  int new_board[SIZE + 2][SIZE + 2] = {{0}};
  int i, j, cnt;

  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      cnt = count_neighbors(board, i, j);
      if (board[i][j] == 1) {
        new_board[i][j] = (cnt == 2 || cnt == 3);
      } else {
        new_board[i][j] = (cnt == 3);
      }
    }
  }
  /* 先算后写: 后面的格子还要读旧的邻居状态, 不能边算边写 */
  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.6;">

- `count_neighbors`: ==一个格子==数邻居——`cnt = -board[i][j]` 先把自己减掉, 因为自己也被数进去了

- `next_generation`: 对==每个格子==调用 count_neighbors 并套三条规则, 结果写进 new_board 再==写回== board——数组形参让这个写回能改到原数组

- 为什么两块棋盘? 先全部算到 new_board 再整体写回——本代已改的格子会==污染==后面格子的邻居判断

- 函数之间==嵌套调用==: next_generation 调 count_neighbors——函数可以调用函数

</div>

</div>

---

<!-- slide data-notes="" -->##### 生命游戏 · 函数版 (二): 打印与动画

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
void print_board(int board[][SIZE + 2])
{
  int i, j;

  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
}

int main(void)
{
  int board[SIZE + 2][SIZE + 2] = {{0}};
  int i;

  board[2][3] = 1;  board[3][4] = 1;
  board[4][2] = 1;  board[4][3] = 1;  board[4][4] = 1;

  for (i = 0; i < 20; i++) {
    print_board(board);
    next_generation(board);
    sleep(1);            /* 停 1 秒 */
    system("clear");     /* 清屏重画 → 动画 */
  }
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.72em;line-height:1.45;">

只改 main 的循环——加上==停顿==和==清屏==, 就能看到滑翔机在屏幕上移动:

- `print_board`: 打印棋盘——和演化逻辑==分开==, 想改输出格式只动这里

- main 只剩三件事: ==初始化==滑翔机 → 二十代循环 {打印, 演化, 停顿, 清屏}——读起来像说明书

- 二维数组作参数的核心规则: `int board[][SIZE + 2]` 列数==必须写== (编译器要算 board[i][j] 的位置)

- 加动画==只改 main==: `sleep(1)` 每代停 1 秒, `system("clear")` 清屏重画——三个函数一行未动

- ==先猜再验==: 运行起来观察滑翔机的运动——你发现什么规律? (每 4 代平移一格, ==斜着飞过屏幕==)

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/game-of-life-anim.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 game-of-life-anim.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 案例: 成绩统计 · 原版

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

求每个学生的总分 (非函数版):

```C{.line-numbers}
/* 5 名学生 x 3 门课: 非函数版 */
#include <stdio.h>

int main(void)
{
  int scores[5][3] = {{80, 85, 90}, {70, 75, 80}, {90, 92, 88},
                      {60, 65, 70}, {85, 80, 90}};
  int sums[5];
  int i, j;

  for (i = 0; i < 5; i++) {
    sums[i] = 0;
    for (j = 0; j < 3; j++) {
      sums[i] += scores[i][j];
    }
  }

  for (i = 0; i < 5; i++) {
    printf("student %d total: %d\n", i + 1, sums[i]);
  }
  return 0;
}
```

</div>

<div style="flex:1;font-size:1.0em;line-height:1.7;">

==3 分钟, 自己写==: 把每行求和抽成函数, main 只剩调用和输出——二维数组进, 结果往哪放? 下一页对照

<span class="blue">:fa-lightbulb-o:</span> 提示: 二维数组进 (`scores`)、一维数组出 (`sums`)——两个都是 "数组作参数"

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/8-functions/code/row-sums-re.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 row-sums-re.c</a>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 案例: 成绩统计 · 函数版

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

==练习==: 按列求和呢? `sums[j]` 的清零该放在哪个循环之外? 结果数组的长度是多少?

<a href="code/row-sums-re.c" target="_blank">row-sums-re.c (改造前)</a> · <a href="code/row-sums-func.c" target="_blank">row-sums-func.c (函数版)</a>

</div>

</div>

---

<!-- slide data-notes="" -->##### 函数化改造 · 四步总结

---

==函数化四步==: ① 找输入 ② 定返回/输出参数 ③ 搬代码 ④ 改调用——今天 10 个例子全部按这四步走; 标量返回==值==, 数组靠==输出参数== (改原数组/写进另一个数组):

<div style="font-size:0.5em;">

| 例子 | 输入 | 返回 / 输出参数 | 调用 |
|------|------|----------------|------|
| `is_prime` | `int n` | 1/0 | `if (is_prime(n))` |
| `count_primes` | `int max` | 个数 | `count_primes(max)` |
| `is_leap_year` | `int n` | 1/0 | `is_leap_year(year)` |
| `print_stars` | `int n` | 无 (打印) | `print_stars(2 * i + 1)` |
| `sum_array` | `a[], n` | 和 | `sum_array(b, 5)` |
| `sort` | `a[], n` | 无 (改原数组) | `sort(a, 10)` |
| `sum_matrix` | `a[][4], rows` | 和 | `sum_matrix(m, 3)` |
| `transpose` | `a[][4], b[][3], rows` | 无 (写进 b) | `transpose(a, b, 3)` |
| `row_sums` | `scores[][3], n, sums[]` | 无 (写进 sums) | `row_sums(scores, 5, totals)` |
| `combination` | `m, n` | 值 | ==你自己写== |

</div>

<div style="display:flex;gap:24px;font-size:0.9em;">

<span>==练习==: 矩阵转置 `transpose`——两个形参的列数各写几? (<a href="code/transpose-re.c" target="_blank">题面</a> · <a href="code/transpose-func.c" target="_blank">答案</a>)</span>

<span>→ 一路都在说 "数组是例外"——为什么? 答案藏在函数调用的幕后, 下一节揭晓</span>

</div>

---


<!-- slide data-notes="" -->##### 函数调用栈 · 概念

---

<div style="font-size:0.85em;line-height:1.5;">

函数不执行的时候是什么? 编译后它只是==代码区==里静静躺着的一段指令——像书架上的菜谱, 不做事也不占台面; 一被调用, 系统才为==这一次调用==在栈上放一张便签。同一张菜谱能反复做菜——同一个函数每次调用都是独立的一次:

</div>

先想一个问题: 函数返回之后, 它里面的局部变量==去了哪里==? 下次再调用, 为什么又是全新的?

<div style="display:grid;grid-template-columns:0.9fr 1.1fr;gap:16px;align-items:start;">

<div style="text-align:center;">
<svg viewBox="0 0 460 440" style="max-width:100%;height:340px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<rect x="30" y="346" width="200" height="60" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="130" y="364" font-size="18" fill="#073642" text-anchor="middle">main</text>
<text x="130" y="381" font-size="11" fill="#586e75" text-anchor="middle">局部变量</text>
<text x="130" y="396" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<rect x="30" y="286" width="200" height="60" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="130" y="304" font-size="18" fill="#073642" text-anchor="middle">f</text>
<text x="130" y="321" font-size="11" fill="#586e75" text-anchor="middle">参数 · 局部变量</text>
<text x="130" y="336" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<rect x="30" y="226" width="200" height="60" rx="8" fill="#dceaf5" stroke="#268bd2" stroke-width="3"/>
<text x="130" y="244" font-size="18" fill="#073642" text-anchor="middle">g</text>
<text x="130" y="261" font-size="11" fill="#586e75" text-anchor="middle">参数 · 局部变量</text>
<text x="130" y="276" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<line x1="130" y1="226" x2="130" y2="206" stroke="#268bd2" stroke-width="2"/>
<text x="130" y="199" font-size="14" fill="#268bd2" text-anchor="middle">栈顶: g 正在执行</text>
</g>
</svg>
</div>

<div style="font-size:0.85em;line-height:1.6;">

- 每次函数调用, 系统在==调用栈== (call stack) 上放一张 "便签"——术语叫==栈帧== (stack frame): 记下==返回地址==、==参数==、==局部变量==

- ==返回地址==: 函数结束后, 回到调用处==继续执行的下一行==

- 函数返回时揭掉这张便签——局部变量 "出了函数就没了", 就是这个原因

- 栈是==后进先出==: 最后调用的函数最先返回——像一摞便签, 后放的压在最上面, 只能先揭最上面那张

</div>

</div>

---


<!-- slide data-notes="" -->##### 函数调用栈 · 便签上放了什么

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.62em;">

```C{.line-numbers}
/* primes.c 函数版: 两层调用链 */
#include <stdio.h>

int is_prime(int n) {
  int d;
  if (n <= 1) return 0;
  for (d = 2; d <= n / d; d++) {
    if (n % d == 0) return 0;
  }
  return 1;
}

int count_primes(int max) {
  int i, count = 0;
  for (i = 2; i <= max; i++) {
    if (is_prime(i)) count++;
  }
  return count;
}

int main(void) {
  printf("%d\n", count_primes(10));
  return 0;
}
```

</div>

<div style="flex:1;display:flex;flex-direction:column;justify-content:space-between;align-self:stretch;">

<div style="font-size:0.9em;line-height:1.6;">

拿刚才的 primes.c 函数版看: main → count_primes → is_prime ==两层调用==, 运行时栈上叠着三张便签

</div>

<svg viewBox="0 0 520 440" style="max-width:100%;height:400px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<rect x="30" y="346" width="200" height="60" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="130" y="364" font-size="18" fill="#073642" text-anchor="middle">main</text>
<text x="130" y="381" font-size="11" fill="#586e75" text-anchor="middle">无局部变量</text>
<text x="130" y="396" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<rect x="30" y="286" width="200" height="60" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="130" y="304" font-size="18" fill="#073642" text-anchor="middle">count_primes</text>
<text x="130" y="321" font-size="11" fill="#586e75" text-anchor="middle">参数 max · 局部 i, count</text>
<text x="130" y="336" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<rect x="30" y="226" width="200" height="60" rx="8" fill="#dceaf5" stroke="#268bd2" stroke-width="3"/>
<text x="130" y="244" font-size="18" fill="#073642" text-anchor="middle">is_prime</text>
<text x="130" y="261" font-size="11" fill="#586e75" text-anchor="middle">参数 n · 局部 d</text>
<text x="130" y="276" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<line x1="130" y1="226" x2="130" y2="206" stroke="#268bd2" stroke-width="2"/>
<text x="130" y="199" font-size="14" fill="#268bd2" text-anchor="middle">栈顶</text>
<rect x="290" y="346" width="200" height="60" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="390" y="364" font-size="18" fill="#073642" text-anchor="middle">main</text>
<text x="390" y="381" font-size="11" fill="#586e75" text-anchor="middle">无局部变量</text>
<text x="390" y="396" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<rect x="290" y="286" width="200" height="60" rx="8" fill="#dceaf5" stroke="#268bd2" stroke-width="3"/>
<text x="390" y="304" font-size="18" fill="#073642" text-anchor="middle">count_primes</text>
<text x="390" y="321" font-size="11" fill="#586e75" text-anchor="middle">参数 max · 局部 i, count</text>
<text x="390" y="336" font-size="11" fill="#586e75" text-anchor="middle">返回地址</text>
<line x1="420" y1="226" x2="420" y2="206" stroke="#268bd2" stroke-width="2" stroke-dasharray="6 4"/>
<text x="420" y="199" font-size="14" fill="#b58900" text-anchor="middle">已撕掉</text>
<path d="M 232 262 L 286 300" stroke="#586e75" stroke-width="2" fill="none" marker-end="url(#arr4)"/>
<text x="259" y="294" font-size="12" fill="#586e75" text-anchor="middle">返回</text>
<defs>
<marker id="arr4" markerWidth="8" markerHeight="8" refX="7" refY="4" orient="auto">
<path d="M 0 0 L 8 4 L 0 8 z" fill="#586e75"/>
</marker>
</defs>
</g>
</svg>

</div>

</div>

---

<!-- slide data-notes="" -->##### 函数调用栈 · 小结

---

- is_prime 返回时, 栈顶的便签被==撕掉==: 局部变量 d 随之消失, 控制权按 "返回地址" 回到 count_primes

- count_primes 的循环一次次调用 is_prime, 每次都放一张==全新的便签==——所以每次的局部变量都是新的

- 数组作参数时, 便签上记的不是整个数组, 而是数组的==开头位置==——函数顺着位置改到原数组; 普通参数记的是==值的副本==——这就是 "数组是例外" 的原因

<span class="blue">:fa-lightbulb-o:</span> 后面的递归课: 函数一层层调用自己, 栈上便签一层层叠高——今天先记住这张图

<a href="function-and-stack.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🎬 打开调用栈动画 (逐帧压栈/弹栈)</a> <a href="https://pythontutor.com/c.html" target="_blank" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#859900;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">🌐 在 Python Tutor 中演示 (粘贴左栏代码, 逐行看栈帧)</a>

---


<!-- slide data-notes="" -->##### 课堂编码: 挑战 · 组合数

---

==挑战==: 用今天写好的 `factorial` 写 `combination`——C(m,n) = m! / (n!(m-n)!), 原型 `long combination(int m, int n)`; main → combination → factorial ==两层调用链==, 运行时栈上就叠着刚才那样的两层便签

`factorial` 被调用了三次、参数各不同——小函数可以组合成更大的函数

<span style="font-size:0.9em;">==追问==: 试试 m = 30——为什么结果不对? (提示: 30! 超出 long 的容量——Windows 上 long 只有 32 位, 13! 就溢出; Mac/Linux 64 位也到 20!)</span>

---


---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 概念: 函数调用时栈上发生了什么? 局部变量在函数返回后会怎样?

2. 概念: 数组作参数时, 为什么长度要单独传? 二维数组的形参为什么列数不能省?

3. 代码阅读: 阅读 leap-func.c (函数版), `is_leap_year(1900)` 返回什么? 为什么?

4. 纠错: 二维数组形参写成 `int a[][]`, 能编译吗? 为什么? 正确的写法是什么?

---
<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


