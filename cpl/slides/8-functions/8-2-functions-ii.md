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

## 函数 (II)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 函数化改造: 素数、leap、primes、stars

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
  for (divisor = 2; divisor * divisor <= n; divisor++) {
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

- `divisor * divisor <= n` 就是检查到 $\sqrt{n}$ 的等价写法 (不用 math.h)

- 返回 1/0, 调用处 `if (is_prime(n))` 直接当条件——与 8-1 的写法一致

</div>

</div>

---

<!-- slide data-notes="" -->


##### leap.c

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.46em;">

```C
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

```C
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

<div style="flex:1;">

- 判断逻辑抽成 `is_leap_year(year)`, main 只剩输入输出

- 返回 1/0, `if (is_leap_year(year))` 直接当条件

- 以后想再判断闰年, 调函数即可——不用重写条件

<a href="code/leap.c" target="_blank">leap.c</a> · <a href="code/leap-re.c" target="_blank">leap-re.c</a>

</div>

</div>

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
    for (int j = 2; j * j <= i; j++) {
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
  for (int j = 2; j * j <= n; j++) {
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


##### 函数与栈

---

每次函数调用, 系统都会在==调用栈==(call stack)上做两件事:

- ==压栈==: 保存返回地址、局部变量、参数

- ==弹栈==: 函数返回后, 其局部变量随之消失

这就是局部变量"出了函数就没了"的原因, 也是递归能一层层返回的机制。

动画演示: [function-and-stack.html](function-and-stack.html)

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


