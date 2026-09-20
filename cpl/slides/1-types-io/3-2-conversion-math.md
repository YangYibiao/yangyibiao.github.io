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

## 类型转换与数学库函数

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 表达式求值

- 副作用与左值

- 类型转换

- 数学库函数

- 编码实践

---


<!-- slide data-notes="" -->


##### 表达式求值

---

到目前为止所涉及的运算符: 

<div class="threelines column7-border-right-solid head-highlight-1 tr-hover row3-border-top-dashed row7-border-top-dashed">

| 优先级 | 名称       | 符号               | 结合性   |
| :--   | :--       | :--                | :--     |
| 1     | 自增(后缀) | `++`               | left    |
|       | 自减(后缀) | `--`               |         |
| 2     | 自增(前缀) | `++`               | right   |
|       | 自减(前缀) | `--`               |         |
|       | 一元正号   | `+`                |         |
|       | 一元负号   | `-`                |         |
| 3     | 乘法类     | `* / %`            | left    |
| 4     | 加法类     | `+ -`              | left    |
| 5     | 赋值       | `= *= /= %= += -=` | right   |

</div>

<span class="blue">:fa-lightbulb-o:</span> 运算符优先级表可用于向缺少括号的表达式添加括号: 从最高优先级的运算符开始, 在运算符及其操作数周围加上括号

---

<!-- slide data-notes="" -->


##### 表达式求值

---

例子: 

<div class="fullborder">

| `a = b += c++ - d + --e / -f`                 | 排序   |
| :--                                           | :--   |
| `a = b += (c++) - d + --e / -f`               | `1`   |
| `a = b += (c++) - d + (--e) / (-f)`           | `2`   |
| `a = b += (c++) - d + ((--e) / (-f))`         | `3`   |
| `a = b += (((c++) - d) + ((--e) / (-f)))`     | `4`   |
| `(a = (b += (((c++) - d) + ((--e) / (-f)))))` | `5`   |

</div>

---

<!-- slide data-notes="" -->##### 子表达式求值顺序

---

表达式的值可能取决于==子表达式的计算顺序==——C 没有定义这个先后 (逻辑与或、条件、逗号运算符除外)

- `(a + b) * (c - d)`: 先算哪个括号? 不确定; 大多数表达式结果相同, 但子表达式==修改操作数==时就不成立:

```C{.line-numbers}
a = 5;
c = (b = a + 2) - (a = 1);
```

- 第二条语句的执行结果是未定义的

<span class="blue">:fa-lightbulb-o:</span> 避免在表达式中访问变量值的同时也修改该变量的值<!-- slide data-notes="" -->


##### 子表达式求值顺序

---

<span class="blue">:fa-lightbulb-o:</span> 为防止出现问题, 最好避免在子表达式中使用赋值运算符

相反, 建议使用一串分离的赋值表达式: 

```C{.line-numbers}
a = 5;
b = a + 2;
a = 1;
c = b - a;
```

`c`的值是确定的, 将始终为 `6`

除了赋值运算符之外, 唯一修改其操作数的运算符是自增和自减

```C{.line-numbers}
i = 2;
j = i * i++;
```

很自然地认为`j`被赋值为`4`. 然而, `j`也可以被赋值为`6`——求值顺序不同, 结果不同

---

<!-- slide data-notes="" -->


##### 未定义的行为

---

`c = (b = a + 2) - (a = 1);`和`j = i * i++;`均会产生未定义的行为

未定义行为的可能影响: 

- 当使用不同的编译器编译时, 程序运行的行为可能会有所不同

- 该程序可能一开始就无法编译

- 能编译但无法运行

- 能运行, 但程序可能会崩溃、行为不正常或产生无意义的结果

<span class="blue">:fa-weixin:</span> 应避免未定义的行为

---

<!-- slide data-notes="" -->


##### 副作用(side effects)

---

修改操作数的运算符被称为具有 ==副作用== , 如 `i + j` 没有 副作用

- 简单的赋值运算符有副作用: 它修改了左操作数, 表达式 `i = 0` 的结果为 `0`, 它的副作用是将 `0` 赋值给`i`

- 允许 `v` 类型值的地方都可以进行形如 `v = e` 的赋值: 

```C{.line-numbers}
i = 1;
k = 1 + (j = i);
printf("%d %d %d\n", i, j, k);
/* prints "1 1 2" */
```

<span class="yellow">:fa-weixin:</span> ==嵌入式赋值== 会使程序难以阅读, 容易隐藏错误

---

<!-- slide data-notes="" -->


##### 左值

---

赋值运算符需要一个 ==左值== 作为其左操作数

==左值== 表示存储在计算机内存中的对象, 而不是常量或计算结果

- 变量是左值

- `10`或`2 * i`这样的表达式不是左值

```C{.line-numbers}
12 = i;      /*** WRONG ***/
i + j = 0;   /*** WRONG ***/
-i = j;      /*** WRONG ***/
```

<span class="blue">:fa-lightbulb-o:</span> 编译器将产生一条错误消息, 例如"invalid lvalue in assignment"

---

<!-- slide data-notes="" -->


##### 类型转换 - 隐式转换


==隐式转换==: 不同类型混合运算/赋值时, 编译器自动转换

- 赋值: 右值自动转换为左值变量的类型

```C
int i;
double d = 3.14159;
i = d;      /* i 为 3 (截断小数) */
d = i;      /* d 为 3.0 */
```

- 运算: 较低类型提升为较高类型 (`char`/`short` → `int`; `int` + `double` → `double`)

```C
1 / 2;        /* 0   (整数除法) */
1.0 / 2;      /* 0.5 (2 提升为 double) */
```


<!-- slide data-notes="" -->


##### 类型转换 - 强制转换

---

==强制转换==: 显式地把值转换为目标类型

```C
(float) 1 / 2;   /* 0.5 */
(int) 3.9;       /* 3 */
```

<span class="blue">:fa-lightbulb-o:</span> 强制转换的优先级很高, 只作用于紧邻的操作数; 需要转换整个表达式时要加括号, 如 ==(int) (3.9 + 1.1)==

- 强制转换还能==避免溢出==: ==先提升, 再运算==, 而不是算完再提升

```C
long i; int j = 1000000;
i = (long) j * j;      /* 正确: j 先转成 long, 乘法不会溢出 */
i = (long) (j * j);    /* 错误: j * j 已经在 int 里溢出了 */
```

---

---
<!-- slide data-notes="" -->


##### 数学库函数

---

调用数学库函数必须包含头文件 `#include <math.h>`, 并可能需加编译选项 `-lm`

<div class="fullborder">

| 函数                     | 含义                      |
| :--                      | :--                       |
| `abs(x)` / `fabs(x)`     | 整数 / 浮点数绝对值         |
| `sqrt(x)`                | x 的平方根                 |
| `pow(x, y)`              | x 的 y 次方                |
| `exp(x)` / `log(x)`      | e 的 x 次方 / 自然对数      |
| `log10(x)`               | 常用对数                   |
| `sin(x)` / `cos(x)` / `tan(x)` | 三角函数 (x 为==弧度==) |

</div>

```C
#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 9.0;
    printf("sqrt(9) = %f\n", sqrt(x));
    printf("2^10 = %f\n", pow(2.0, 10));
    printf("|3 - 5.5| = %f\n", fabs(3 - 5.5));
    return 0;
}
```

---

<!-- slide data-notes="" -->


##### 编码实践: mol

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.7em;">

```C
/*
 * mol.c(6克氧气的分子数)
 */
#include <stdio.h>

int main(void) {
    const double MOL = 6.02E23;
    const int GRAM_PER_MOL = 32;
    int mass = 6;

    double quantity = mass * 1.0 /GRAM_PER_MOL * MOL;

    printf("quantity = %.3e\nquantity = %.5g\n", quantity, quantity);
    return 0;
}
```

</div>

<div style="flex:1;">

$6$ 克氧气的分子数是多少?

$Q = 6 / 32 \times 6.02 \times 10^{23}$

两种格式输出, 结果均使用<mark>科学计数法</mark>表示

- 第一行结果, 小数点后保留 $3$ 位
- 第二行结果, 保留 $5$ 位有效数字



</div>

</div>
<!-- slide data-notes="" -->


##### 课堂小测

---

1. `int i = (int) 3.9;` 中 `i` 的值是多少？`(float) 1 / 2` 的值是多少？

2. `i = d;` 中 d 是 double 型 3.99，赋值后 i 是多少？有精度损失提示吗？

3. 计算 `sqrt(16)` 需要包含哪个头文件？编译时可能还需要什么选项？

4. 为什么 `j = i * i++;` 的结果不确定？这类表达式应该怎么避免？



<!-- slide data-notes="" -->


#####

---

<div class="top-2">
  <img src="../0-intro/figs/see-you.png" width=500px>
</div>

---


