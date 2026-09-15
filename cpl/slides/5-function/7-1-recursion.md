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

## 递归函数

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 递归: 自己调用自己

- 经典案例: 阶乘、斐波那契、汉诺塔

- 递归与栈

- 常见错误与课堂编码

---


<!-- slide data-notes="" -->


##### 递归

---

如果函数调用自身, 则它是递归的. 

以下函数利用公式$n! = n × (n – 1)!$递归地计算$n!$:

```C{.line-numbers}
int fact(int n)
{
  if (n <= 1)
    return 1;
  else
    return n * fact(n - 1);
}
```
---


要了解递归是如何工作的, 让我们来跟踪语句的执行

```C
i = fact(3);
```

1. fact(3) 发现 $3 \le 1$ 不成立, 所以调用
2. &emsp; fact(2), 发现 $2 \le 1$ 不成立, 所以调用
3. &emsp; &emsp; fact(1), 发现 $1 \le 1$ 成立, 所以返回1, 导致
4. &emsp; fact(2) 返回 $2 × 1 = 2$, 导致
2. fact(3) 返回 $3 × 2 = 6$.

---


<!-- slide data-notes="" -->


##### 递归的定义

---

n! 的计算可以递归定义:

n! = 1&emsp;(n = 0 或 n = 1)

n! = n × (n-1)!&emsp;(n > 1)

==递归==: 函数直接或间接地==自己调用自己==

- 基准情形: 最简单、直接给出答案 (n=0 或 1)

- 递归情形: 把问题缩小后调用自身 (n! = n × (n-1)!)

---


<!-- slide data-notes="" -->


##### 阶乘的递归实现

---

```C
long f(long n)
{
  if (n == 0 || n == 1)    /* 基准情形 */
    return 1;
  return n * f(n - 1);      /* 递归情形 */
}
```

---


<!-- slide data-notes="" -->


##### 递归执行过程

---

f(5) 的执行: 层层==递推==下去, 再层层==回归==上来

f(5) → 5×f(4) → 4×f(3) → 3×f(2) → 2×f(1) → 返回 1 → 2 → 6 → 24 → 120

- 每一层调用都==压栈==保存现场, 回归时逐层==弹栈==

- 递归深度 = 压栈层数; 递归过深会栈溢出

---


<!-- slide data-notes="" -->


##### Fibonacci 数列

---

F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)

```C
#include <stdio.h>
long fib(long n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fib(n - 1) + fib(n - 2);
}
int main(void)
{
  int n;
  scanf("%d", &n);
  printf("fib(%d) = %ld\n", n, fib(n));
  return 0;
}
```

- f(5) 会把 f(3)、f(2) 各算多遍——重复计算是朴素递归的代价

---


<!-- slide data-notes="" -->


##### 递归求最大公约数

---

辗转相除法用递归表达: gcd(a, b) = gcd(b, a % b)

```C
int gcd(int a, int b)
{
  if (b == 0) return a;      /* 基准情形 */
  return gcd(b, a % b);     /* 递归情形 */
}
```

- 循环版比较: while (r = a % b) { a = b; b = r; }——递归版更接近数学定义

---


<!-- slide data-notes="" -->


##### Hanoi 塔

---

3 根柱 A、B、C, 把 n 个盘子从 A 移到 C (大盘不能压小盘, 可借 B):

- n=1: 直接 A → C

- n>1: 先把上面 n-1 个 A → B (借 C), 再把最大盘 A → C, 最后 n-1 个 B → C (借 A)

```C
void Hanoi(int n, char A, char B, char C)
{
  if (n == 1)
    printf("%c -> %c\n", A, C);
  else {
    Hanoi(n - 1, A, C, B);
    printf("%c -> %c\n", A, C);
    Hanoi(n - 1, B, A, C);
  }
}
```

- 64 个盘子需 2^64 - 1 步——"把问题交给递归"的威力

---


<!-- slide data-notes="" -->


##### 递归与栈

---

以下递归函数使用公式$x^n = x × x ^{n –1}$计算$x^n$. 

```C{.line-numbers}
int power(int x, int n)
{
  if (n == 0)
    return 1;
  else
    return x * power(x, n - 1);
}
```
---


把条件表达式放入return语句中可以精简power函数: 

```C
int power(int x, int n)
{
    return n == 0 ? 1 : x * power(x, n - 1);
}
```

fact和power都会在调用时小心地测试==终止条件==. 

所有递归函数都需有终止条件以防止无限递归.

---


<!-- slide data-notes="" -->


##### 常见错误

---

- ==缺少基准情形==: 递归永不终止 (如忘了 n==0 的判断)

- ==问题没有缩小==: 每次调用与上次规模相同 (如 f(n) 里调用 f(n))

<span class="blue">:fa-lightbulb-o:</span> 写递归的两步检查: ① 基准情形对吗? ② 每次调用规模在变小吗?

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

1. 递归求和: sum(n) = n + sum(n-1)

2. 递归求幂: power(x, n) = x × power(x, n-1)

3. 递归打印整数 printd: 先打印 n/10 再打印 n%10

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 递归函数必须具备哪两个要素？

2. f(5) 计算 5! 的过程中，栈上最多同时压了几层调用？

3. fib(5) 中 fib(2) 被计算了几次？这说明了什么？

4. 递归和循环各适合什么场景？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


