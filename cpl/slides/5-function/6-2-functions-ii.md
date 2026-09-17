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

- 函数化改造: leap / primes / stars

- 函数与栈

- 课堂编码

---


<!-- slide data-notes="" -->


##### 程序: 判定素数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.48em;">

```C{.line-numbers}
/* 判断一个数是否为素数 */
 
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
 
bool is_prime(int n)
{
  int divisor;
 
  if (n <= 1)
    return false;
  for (divisor = 2; divisor * divisor <= n; divisor++)
    if (n % divisor == 0)
      return false;
  return true;
}

int main(void)
{
  int n;
 
  printf("Enter a number: ");
  scanf("%d", &n);
  if (is_prime(n))
    printf("Prime\n");
  else
    printf("Not prime\n");
  return 0;
}
```

</div>

<div style="flex:1;">

`prime.c`程序测试一个数字是否为素数: 

Enter a number: <u>34</u>
Not prime

该程序定义一个名为is_prime的函数, 如果其参数是质数则返回true, 否则返回false. 

is_prime将其参数n除以从2到n的平方根之间的每个数字, 只要有一个余数为0, n就不是素数.


---

`prime.c`



</div>

</div>

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
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
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
    printf("%d is a common year\n", year);
  } else {
    printf("%d is a leap year\n", year);
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

<a href="code/leap.c" target="_blank">leap.c</a>

---

<a href="code/leap-re.c" target="_blank">leap-re.c</a>



</div>

</div>

<!-- slide data-notes="" -->##### primes.c (原版)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
#include <stdio.h>

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    // determine if i is a prime
    int prime = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      count++;
//      printf("%d ", i);
    }
  }
  printf("\ntotal count: %d", count);
  return 0;
}
```

</div>

<div style="flex:1;">

<a href="code/primes.c" target="_blank">primes.c</a>

原版: 主函数里逐个判断

</div>

</div>
<!-- slide data-notes="" -->##### primes-re.c (函数版)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
#include <stdio.h>
int is_prime(int n) {
  int prime = 1;
  for (int j = 2; j * j <= n; j++) {
    if (n % j == 0) {
      prime = 0;
      break;
    }
  }
  return prime;
}
int main() {
  int max;
  scanf("%d", &max);
  int count = 0;
  for (int i = 2; i <= max; i++) {
    // determine if i is a prime
    int prime = is_prime(i);
    if (prime == 1) {
      count++;
    }
  }
  printf("\ntotal count: %d", count);
  return 0;
}
```

</div>

<div style="flex:1;">

---

<a href="code/primes-re.c" target="_blank">primes-re.c</a>

</div>

</div>
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
    // NUm ' '
    for (int j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }
    // 2 * i + 1 '*'
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

1. 把"判定素数"的循环改写为函数 `is_prime(n)`，它返回什么类型？

2. leap.c 中的 `leap` 函数返回 1/0 表示什么含义？

3. 函数调用时栈上发生了什么？局部变量在函数返回后会怎样？

4. stars.c 中打印一行的循环被抽成了什么函数？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


