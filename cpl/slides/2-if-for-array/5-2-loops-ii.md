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

## 循环结构 (下)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- for 语句与常见用法

- C99 的 for 与逗号运算符

- 嵌套循环: 打印星号塔

- 算法案例: 累加累乘、素数、非完全平方数

---


<!-- slide data-notes="" -->


##### for语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C
for (表达式1; 表达式2; 表达式3) 语句
```

```C
for (i = 10; i > 0; i--)
    printf("%d\n", i);
```

```C
表达式1;
while (表达式2) {
  语句
  表达式3;
}
```

</div>

<div style="flex:1;">

`for` 特别适合==次数已知==的循环 ("重复 n 次"型)——三件事 (从几开始、到哪停、每次加几) 排在一行, 一眼看清; 也能用于其他循环。一般形式:

- 表达式1: ==初始化==——只在循环开始前执行一次

- 表达式2: ==条件==——非零就继续, 为零结束

- 表达式3: ==递增/递减==——每轮最后执行

`for` 和 `while` 几乎总能互相改写 (如左)

</div>

</div>

<!-- slide data-notes="" -->


##### for语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;">

表达式1 和表达式3 都是==语句==, 它们的==值==无关紧要——起作用的是==副作用== (赋值、自增自减)

所以表达式3 ==不一定非要是 `i++`/`i--`==——步长 2、累加之类都行:

<span class="blue">:fa-weixin:</span> 小注: 表达式3 写 `i--` 还是 `--i` 结果一样 (只看副作用, 不看值)——第 3 周自增自减的知识在这里兑现

</div>

<div style="flex:1;font-size:0.72em;">

```C
/* 求 2+4+6+...+n 的偶数和 */
int sum = 0;
for (i = 2; i <= n; i += 2)
    sum += i;
```

```C
/* 表达式3 也可以是累加: 一行写完累加循环 */
for (i = 1; i <= n; sum += i++)
    ;
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### for语句常见用法

---

`for` 最适合==向上计数==或==向下计数==, 四种常见写法:

```C{.line-numbers}
/* 从0计数到n – 1 */       for (i = 0; i < n; i++) ...
/* 从1计数到n */           for (i = 1; i <= n; i++) ...
/* 从n – 1倒数到0 */       for (i = n - 1; i >= 0; i--) ...
/* 从n倒数到1 */           for (i = n; i > 0; i--) ...
```

常见的 for 错误:

- 方向写反: 向上计数用 `<`/`<=`, 向下计数用 `>`/`>=`——把 `>` 写成 `<` 方向就反了

- 把比较符写成 `==`: 初始值就不成立, 循环体==一次都不执行==

- ==差一错误== (off-by-one): 把 `i < n` 写成 `i <= n` 会多循环一次

---

<!-- slide data-notes="" -->


##### 演示: 浮点计数循环的陷阱

---

<div style="font-size:0.8em;">

```C
#include <stdio.h>
int main(void) {
    int i;
    double x;
    for (i = 0, x = 0.0; i <= 10; i++, x += 0.1)
        printf("%2d 次累加后: %.17f\n", i, x);
    return 0;
}
```

</div>

运行结果 (节选): 

```
 1 次累加后: 0.10000000000000001
 2 次累加后: 0.20000000000000001
 3 次累加后: 0.30000000000000004
...
10 次累加后: 0.99999999999999989
```

- `0.1` 在二进制里是无限循环小数 (第2周讲过), 累加 ==10 次并不是 1.0==

- 若用 ==`for (x = 0.0; x != 1.0; x += 0.1)`==: 第 10 次后 `x` 并不等于 `1.0`, 循环==停不下来== (或次数不对)

- 教训: ==不要用浮点数计数/判等==; 循环次数用整数控制、浮点只参与运算; 比较浮点用 `x < 1.0` 而不是 `x != 1.0`

---

<!-- slide data-notes="" -->


##### for语句省略表达式

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C{.line-numbers}
i = 10;
for (; i > 0; --i)
  printf("%d\n", i);
```

```C{.line-numbers}
for (i = 10; i > 0;)
  printf("%d\n", i--);
```

```C
  for (;;) …
```

</div>

<div style="flex:1;">

`C`允许省略`for语句`中的表达式

省略表达式1: 循环前不初始化:

省略表达式3: 循环体必须自己让条件最终变假:

当`for`语句同时省略第一个和第三个表达式时, 它和`while`语句没有任何分别, `while`版本更清晰, 因此更推荐

省略表达式2: ==默认为真==, 循环不会自己停 (除非 break)——`for(;;)` 就是最常见的无限循环写法:



</div>

</div>

<!-- slide data-notes="" -->


##### C99中的for语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C
for (int i = 0; i < n; i++)
  …
```

```C{.line-numbers}
for (int i = 0; i < n; i++) {
  …
  printf("%d", i); /* 合法的; i 在循环内可见 */
  …
}
printf("%d", i); /*** WRONG ***/
```

```C{.line-numbers}
for (int i = 0, j = 0; i < n; i++)
  …
```

</div>

<div style="flex:1;">

C99 里, for 的表达式1 可以换成==声明==:

循环变量不用提前声明, 直接在 for 里声明==专用变量==:

循环内声明的变量==出了循环就用不了==:

通常建议让 for 声明自己的循环控制变量——方便、可读性好; 但如果循环结束后还要用这个变量, 就只能在循环外声明

for 可以一次声明多个变量 (类型相同):



</div>

</div>

<!-- slide data-notes="" -->


##### 逗号运算符

---

`for` 需要两个初始化表达式或一次递增多个变量时, 可用==逗号表达式==作第一或第三个表达式, 形式为:

```C
表达式1, 表达式2
```

计算逗号表达式的步骤:

- 首先计算表达式1并且丢弃计算出的值
- 然后计算表达式2, 并把它的值作为整个表达式的值

<span class="blue">:fa-weixin:</span> 逗号运算符的优先级==低于==所有其他运算符, 结合方向为左结合

例子: 

```C
i = 1, j = 2, k = i + j   /* (i=1), (j=2), (k=i+j) */
```

---

<!-- slide data-notes="" -->


##### 程序: 打印平方表 (for版)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 使用 for 语句打印一个平方表 */
 
#include <stdio.h>
 
int main(void)
{
  int i, n;
  
  printf("请输入行数: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++)
    printf("%10d%10d\n", i, i * i);
 
  return 0;
}
```

</div>

<div style="flex:1;">

使用 `for` 语句重写平方表程序:

对比 while 版本: for 把初始化、判定、递增三件事集中在一行, 计数循环更清晰

</div>

</div>

<!-- slide data-notes="" -->


##### 嵌套循环: 打印星号塔

---

==现场演示==: 输入高度 n, 打印 n 行的星号塔 (第 i 行有 i 颗星)

<div class="top-2">
  <img src="../3-for-a-while/figs/stars.jpg" width=450px>
</div>

<span class="blue">:fa-lightbulb-o:</span> 提示: 需要==两层循环==——外层控制行数, 内层控制每行星号个数; 外层每执行一次, 内层完整跑一轮。先自己写, 再翻页看参考代码

---


<!-- slide data-notes="" -->


##### 嵌套循环: 打印星号塔 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
/* stars.c: 打印星号塔 */
#include <stdio.h>

int main(void)
{
    int n;
    printf("输入高度: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {        /* 外层: 控制行数 */
        for (int j = 1; j <= i; j++)      /* 内层: 控制每行星号个数 */
            printf("*");
        printf("\n");
    }
    return 0;
}
```

</div>

<div style="flex:1;">

- 外层 `i` 从 1 到 n: 第 i 行

- 内层 `j` 从 1 到 i: 打印 i 颗星——内层的上限==依赖外层变量==, 这是嵌套循环的精髓

- 输入 `5` → 5 行星号塔

</div>

</div>

<!-- slide data-notes="" -->


##### 算法案例: 数据交换、累加、累乘

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==数据交换==: 交换两个变量的值 (借助临时变量)

==累加==: 计算 1+2+...+n

==累乘==: 计算 n! (注意: 初始值为 1, 且很快溢出)

<span class="blue">:fa-weixin:</span> 累加器初始化为 0, 累乘器初始化为 1——这是循环的经典写法

</div>

<div style="flex:1;font-size:0.8em;">

```C
int a = 3, b = 5, t;
t = a; a = b; b = t;   /* a 为 5, b 为 3 */
```

```C
int sum = 0;
for (int i = 1; i <= n; i++)
    sum += i;
```

```C
int product = 1;
for (int i = 1; i <= n; i++)
    product *= i;
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### 算法案例: 素数判断

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
/* primes.c: 判断 n 是否为素数 */
#include <stdio.h>

int main(void) {
    int n, d;
    printf("输入一个数: ");
    scanf("%d", &n);

    for (d = 2; d < n; d++)
        if (n % d == 0)
            break;              /* 找到约数, 提前退出 */

    if (d < n)
        printf("%d 不是素数\n", n);
    else
        printf("%d 是素数\n", n);
    return 0;
}
```

</div>

<div style="flex:1;">

判断 n 是否为素数: 检查 2 ~ n-1 之间是否存在约数

<div class="top-2">
  <img src="../3-for-a-while/figs/prime.jpg" width=350px>
</div>

<span class="blue">:fa-lightbulb-o:</span> 改进: 只需检查到 $\sqrt{n}$ (下节课配合 sqrt 函数实现)

</div>

</div>

<!-- slide data-notes="" -->


##### 算法案例: 非完全平方数的和

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

```C
/* perfectsquare.c: 1~n 中非完全平方数之和 */
#include <stdio.h>
#include <math.h>

int main(void) {
    int n, sum = 0;
    printf("输入 n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int r = (int) sqrt(i);
        if (r * r == i)
            continue;          /* 完全平方数, 跳过 */
        sum += i;
    }
    printf("非完全平方数之和 = %d\n", sum);
    return 0;
}
```

</div>

<div style="flex:1;">

计算 1~n 中所有==非完全平方数==的和

<div class="top-2">
  <img src="../3-for-a-while/figs/perfectSquare.gif" width=300px>
</div>

<span class="blue">:fa-lightbulb-o:</span> continue + sqrt 的组合: 循环与数学库函数的第一次合作

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `for (i = 0; i < n; i++)` 循环体执行了多少次？

2. `for (;;)` 是什么循环？省略的三个表达式分别默认什么？

3. 打印 n 行星号塔，外层和内层循环分别控制什么？

4. 计算 1+2+...+100 用循环怎么写？如果 n=100，累乘 100! 用什么类型存结果？



<!-- slide data-notes="" -->


#####

---

<div class="top-2">
  <img src="../0-intro/figs/see-you.png" width=500px>
</div>

---


