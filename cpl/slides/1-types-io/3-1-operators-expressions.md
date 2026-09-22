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

## 运算符与表达式

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 运算符

- 优先级与结合性

- 数学库函数

- 赋值运算符

- 自增和自减运算符

- 案例: 计算 ISBN-13 书号校验位

---


<!-- slide data-notes="" -->


##### 运算符

---

<span class="yellow">:fa-weixin:</span> C语言的特点在于更加强调==表达式的使用==

==表达式==是由==变量==、==常量==和==运算符==所构成的

C拥有丰富的运算符集合, 包括: 

- 算术运算符
- 关系运算符
- 逻辑运算符
- 赋值运算符
- 自增和自减运算符
- 其他运算符

---

<!-- slide data-notes="" -->


##### 算术运算符

---

五个==二元==算术运算符 (两个操作数): `+` 加、`-` 减、`*` 乘、`/` 除、`%` 求余

两个==一元==算术运算符 (一个操作数): `+` 一元加、`-` 一元减

---

<!-- slide data-notes="" -->


##### 一元算术运算符

---

一元运算符只需要一个操作数: 

```C
i = +1;
j = -i;
```

<span class="yellow">:fa-weixin:</span> 一元`+`运算符什么也不做, 它主要用于强调数字常数是正数

---

<!-- slide data-notes="" -->


##### 二元算术运算符

---

==i % j==是i除以j时的余数

- 二元算术运算符(%除外)允许使用整数或浮点操作数, 并允许混合

- 当==int==和==float/double==操作数混合时, 结果的类型为==float/double==

1. ==10 % 3==的值为1, 而==12 % 4==的值为0
2. ==9 + 2.5== 的值为11.5, 而==6.7 / 2== 的值为3.35

---

<!-- slide data-notes="" -->


##### `/`和`%`运算符

---

`/`和`%`运算符使用需要特别注意: 

- 当两个操作数都是整数时, `/`会==截断==结果: 值==1 / 2==是0, 而不是0.5

- `%`运算符要求整数作为操作数; 任一操作数不是整数, 程序将无法编译

- 使用==零==作为`/`或`%`的==右操作数==会导致未定义的行为

- `/`和`%`与负操作数一起使用时的行为在C89中由实现定义

<span class="yellow">:fa-weixin:</span> C99中, 除法结果总是向零截断, 并且==i % j==的值与==i==有相同符号

---

<!-- slide data-notes="" -->


##### 由实现定义的行为

---

<span class="yellow">:fa-weixin:</span> C标准故意不指定语言的某些部分

- 未指定部分是因为C语言更强调==效率==, 常常意味着与硬件行为相匹配

<span class="blue">:fa-weixin:</span> 避免编写依赖于由具体实现所定义的行为的程序

---

<!-- slide data-notes="" -->##### 运算符优先级

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

`i + j * k` 是先加再乘, 还是先乘再加? 加括号可以消歧; 省略括号时, C 用==运算符优先级==规则来确定含义

==算术运算符== 的优先级:

- 最高: `+ -` (一元)

- 其次: `* / %` (二元)

- 最低: `+ -` (二元)

示例:

</div>

<div style="flex:1;">

<div class="fullborder">
| `i + j * k`  | 等价于  | `i + (j * k)`    |
| :--          | :--    | :--              |
| `-i * -j`    | 等价于  | `(-i) * (-j)`    |
| `+i + j / k` | 等价于  | `(+i) + (j / k)` |
</div>

</div>

</div>

<!-- slide data-notes="" -->


##### 运算符结合性

---

表达式有多个相同优先级操作符, 考虑运算符的结合性

如果运算符从左到右结合的, 则称它为==左结合运算符==

二元算术运算符`*`, `/`, `%`, `+`, `-`都是==左结合==的:

<div class="fullborder">

| `i - j – k` | 等价于 | `(i - j) - k` |
| :--         | :--   | :--           |
| `i * j / k` | 等价于 | `(i * j) / k` |

</div>

如果运算符从右向左结合, 则它是右结合的运算符

一元算术运算符(`+`和`-`)都是右结合的: 

`-+i`等价于`-(+i)`

---

<!-- slide data-notes="" -->


##### 演示: 一样的数字, 不一样的结果

---

<div style="font-size:0.8em;">

```C
#include <stdio.h>
int main(void) {
    printf("9 / 4 * 4 = %d\n", 9 / 4 * 4);
    printf("9 * 4 / 4 = %d\n", 9 * 4 / 4);
    return 0;
}
```

</div>

运行结果: 

```
9 / 4 * 4 = 8
9 * 4 / 4 = 9
```

- 同样的数字、同样的运算符, ==顺序不同结果不同==——这就是优先级与结合性的实际影响

- `9 / 4 * 4`: 左结合, 先算 `9/4` ==整除得 2==, 再 `×4` 得 `8`; `9 * 4 / 4`: 先得 `36`, 再 `/4` 得 `9`

- 罪魁祸首是==整数除法的截断==: `9/4` 悄悄丢掉了小数部分 (下一课深入)

- 拿不准时==加括号==, 让意图明确: `(9 / 4) * 4` 或 `9 * 4 / 4`

---

<!-- slide data-notes="" -->


##### 动手算一算

---

先自己心算下面表达式的值——不用编译器, 想清楚再翻页:

<div style="font-size:1.05em;">

1. `5 + 3 * 2`

2. `10 / 3`

3. `10 % 3`

4. `-10 / 3`

5. `2 + 3 * 4 / 2`

6. `(2 + 3) * 4 / 2`

7. `7 - 2 - 3`

8. `10 - 4 % 3`

</div>

<span class="blue">:fa-lightbulb-o:</span> 每题问自己两个问题: ==先算谁==? (优先级) 同级的==从左还是从右==? (结合性)

---

<!-- slide data-notes="" -->


##### 动手算一算: 答案

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.72em;">

<div class="fullborder">

| 表达式 | 值 | 为什么 |
| :-- | :-- | :-- |
| `5 + 3 * 2` | `11` | 先乘后加 |
| `10 / 3` | `3` | 整数除法截断 |
| `10 % 3` | `1` | 10 除以 3 余 1 |
| `-10 / 3` | `-3` | 向零截断 (不是 -4!) |
| `2 + 3 * 4 / 2` | `8` | 同级左结合 |
| `(2 + 3) * 4 / 2` | `10` | 括号先算 |
| `7 - 2 - 3` | `2` | 左结合: (7-2)-3 |
| `10 - 4 % 3` | `9` | `%` 比 `-` 高 |

</div>

</div>

<div style="flex:1;">

- 第 1、6、8 题: ==优先级==——`* / %` 高于 `+ -`

- 第 5、7 题: ==结合性==——同级从左往右

- 第 2、3、4 题: `/` 与 `%` 的截断、余数、负数向零

- 拿不准就==加括号==, 或拆成==多行==——程序是给人读的

</div>

</div>

---

<!-- slide data-notes="" -->


##### 数学库函数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;">

`+ - * / %` 就这么多, 要==开方、幂、对数、三角==? 调用 C 的==数学库函数==: 先 `#include <math.h>`, 编译时可能还要加选项 `-lm`

`sqrt`/`pow` 等返回 ==double==, 用 `%f` 打印

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

</div>

<div style="flex:1;font-size:0.72em;">

```C
#include <stdio.h>
#include <math.h>

int main(void) {
    double x = 9.0;
    printf("sqrt(9) = %f\n", sqrt(x));
    printf("2^10 = %f\n", pow(2.0, 10));
    printf("|3 - 5.5| = %f\n", fabs(3 - 5.5));
    printf("sqrt(2) = %.3f\n", sqrt(2));
    printf("pow(2, 0.5) = %.3f\n", pow(2, 0.5));  /* 0.5 次方 = 开方 */
    return 0;
}
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### 程序: 计算 ISBN-13 书号校验位

---

书背面条形码下方的 ISBN-13: 前 12 位数字, ==末位是校验位== (识别抄写或录入错误)

计算校验位流程: 

- 第`1`、`3`、`5`、`7`、`9`、`11`位 (奇数位) 数字求和
- 第`2`、`4`、`6`、`8`、`10`、`12`位 (偶数位) 数字求和
- 总数 = 奇数位和 + `3` × 偶数位和
- 校验位 = (`10` - 总数 mod `10`) mod `10`

---

<!-- slide data-notes="" -->


##### 程序: 计算 ISBN-13 书号校验位

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.72em;">

```C{.line-numbers}
/* Computes an ISBN-13 check digit (e.g., the textbook 978-7-04-030276-9) */

#include <stdio.h>

int main(void)
{
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
  int odd_sum, even_sum, total;

  printf("Enter the first twelve digits of an ISBN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
  odd_sum  = d1 + d3 + d5 + d7 + d9 + d11;
  even_sum = d2 + d4 + d6 + d8 + d10 + d12;
  total = odd_sum + 3 * even_sum;

  printf("Check digit: %d\n", (10 - total % 10) % 10);

  return 0;
}
```

</div>

<div style="flex:1;">

教材 ISBN `978-7-04-030276-9` 的校验位计算示例: 

- 奇数位和: $9 + 8 + 0 + 0 + 0 + 7 = 24$
- 偶数位和: $7 + 7 + 4 + 3 + 2 + 6 = 29$
- 总数: $24 + 3 \times 29 = 111$
- $111$ mod $10 = 1$
- 校验位: $(10 - 1)$ mod $10 = 9$ ✓
- 课间试试: 翻到课本封底, 验算 ISBN-13

`isbn.c`



</div>

</div>

<!-- slide data-notes="" -->


##### 赋值运算符

---

- ==简单赋值==: 把值存进变量 (`=`); ==复合赋值==: 更新已有变量的值 (`+=`)

`v = e`先评估表达式`e`的值, 然后将值复制到`v`中

`e`可以是常量、变量或更复杂的表达式: 

```C{.line-numbers}
i = 5;            /* i is now 5  */
j = i;            /* j is now 5  */
k = 10 * i + j;   /* k is now 55 */
```

如果 ==`v`== 和 ==`e`== 的类型不同, 在赋值时 ==`e`== 的值将转换为 ==`v`== 的类型: 

<div style="font-size:0.8em;">

```C
int i;
float f;

i = 72.99f;   /* i is now 72 */
f = 136;      /* f is now 136.0 */
```

</div>

---

<!-- slide data-notes="" -->


##### 简单赋值

---

在许多编程语言中, 赋值是一个语句; 而在 ==`C`== 中, 赋值操作的结果类似运算符, 就像运算符 ==`+`== 一样

赋值表达式 ==`v = e`== 的值是赋值后 ==`v`== 的值

- 表达式 `i = 72.99f` 的值是 $72$, 而不是 $72.99$

```C
i = j = 50 + 3;
```

<span class="yellow">:fa-weixin:</span> 由于 ==赋值== 是一个运算符, 因此可以将多个赋值链接在一起: 

```C{.line-numbers}
i = j = k = 0;
```

==`=`== 运算符是右结合的, 所以这个赋值等价于

```C{.line-numbers}
i = (j = (k = 0));
```

---

<!-- slide data-notes="" -->


##### 复合赋值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

使用变量的旧值来计算其新值的赋值很常见

例如: `i = i + 2;`

使用 ==`+=`== 复合赋值运算符, 可改写为: 

```C
i += 2;   /* same as i = i + 2; */
```

还有其他九个复合赋值运算符, 包括: ==`-= *= /= %=`== 和位运算(`^= &= >>= <<= |=`)

</div>

<div style="flex:1.1;">

<div class="fullborder">

| v += e | 将v加e, 将结果存储在v中         |
| :--    | :--                          |
| v -= e | 将v减e, 将结果存储在v中         |
| v *= e | 将v乘以e, 将结果存储在v中        |
| v /= e | 将v除以e, 将结果存储在v中        |
| v %= e | 计算v除以e的余数, 将结果存储在v中 |

</div>

</div>

</div>

---

<!-- slide data-notes="" -->


##### 复合赋值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;">

`v += e`与`v = v + e`可能==不等价==

- 一是运算符优先级:  

`i *= j + k` 与 `i = i * j + k` 不等价

- 在极少数情况下, `v += e` 不同于 `v = v + e` 因为 `v`本身有副作用(如`v`为`++i`或`i++`等)

</div>

<div style="flex:1;">

<span class="blue">:fa-lightbulb-o:</span> 使用复合赋值运算符时, 不要交换构成复合运算符的两个字符

虽然`i =+ j`能编译通过, 但意义不同, 它相当于 `i = (+j)`, 它只是将`j`的值复制到`i`中

</div>

</div>

---

<!-- slide data-notes="" -->


##### 自增和自减运算符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;">

对变量最常见的两种操作是 ==自增==(加 `1`)和 ==自减==(减 `1`)

可以使用复合赋值运算符进行自增和自减

C 特别提供了 `++` 自增 和 `-–` 自减 运算符

- ==`++`== 运算符将操作数加1

- ==`--`== 运算符将操作数减1

- 有前缀运算符(`++i`和`–-i`)或后缀运算符(`i++`和`i--`)

</div>

<div style="flex:1;font-size:0.75em;">

```C{.line-numbers}
i = i + 1;
j = j - 1;
```

```C{.line-numbers}
i += 1;
j -= 1;
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### 自增和自减运算符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C{.line-numbers}
i = 1;
printf("i is %d\n", ++i);   /* prints "i is 2" */
printf("i is %d\n", i);     /* prints "i is 2" */
```

```C{.line-numbers}
i = 1;
printf("i is %d\n", i++);   /* prints "i is 1" */
printf("i is %d\n", i);     /* prints "i is 2" */
```

```C{.line-numbers}
i = 1;
printf("i is %d\n", --i);   /* prints "i is 0" */
printf("i is %d\n", i);     /* prints "i is 0" */
i = 1;
printf("i is %d\n", i--);   /* prints "i is 1" */
printf("i is %d\n", i);     /* prints "i is 0" */
```

</div>

<div style="flex:1;">

评估表达式`++i` (前缀自增) 的结果是`i + 1`, 副作用是`i`自增`1`:

评估表达式`i++` (后缀自增) 的结果是`i`, 副作用是`i`随后自增`1`:

==`++i`表示立即自增i, 而`i++`表示暂时使用i的旧值, 稍后再自增i==

`--`运算符与`++`运算符相似:



</div>

</div>

<!-- slide data-notes="" -->


##### 自增和自减运算符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.72em;">

```C{.line-numbers}
i = 1;
j = 2;
k = ++i + j++;
```

```C{.line-numbers}
i = i + 1;
k = i + j;
j = j + 1;
```

```C{.line-numbers}
i = 1;
j = 2;
k = i++ + j++;
```

</div>

<div style="flex:1;">

当`++`或`--`在同一个表达式中多次使用时, 结果通常很难理解, 如:

最后一条语句等价于:

i, j和k的最终值分别为 2, 3和4.

相反, 执行语句

`i`、`j`和`k`的值最终为`2`、`3`和`3`

<span class="blue">:fa-lightbulb-o:</span> 多个`++`/`--`混用容易写错, 实际编程中尽量==分行写==

</div>

</div>

<!-- slide data-notes="" -->


##### 表达式语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;">

C 有一个不寻常的规则, 即任何表达式都可以用作语句

例如 `++i;`: i首先递增, 然后获取i的新值, 然后丢弃

由于它的值被丢弃了, 除非表达式有副作用, 否则将表达式用作语句几乎没有意义

一个无意的编码错误很容易会创建一个 ==什么都不做== 的表达式语句, 如 `i = j;` 误编写为 `i + j;`

</div>

<div style="flex:1;font-size:0.75em;">

```C
++i;
```

```C
i = 1;     /* useful */
i--;       /* useful */
i * j - 1; /* not useful */
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `1 / 2` 的值是多少？`7 % 2` 呢？`9 % 3` 呢？

2. `-i * -j` 等价于什么？`i * j / k` 按什么顺序计算？

3. `i += 2` 等价于什么？`i *= j + k` 等价于 `i = i * j + k` 吗？

4. `i = 1; j = i++;` 执行后 `i` 和 `j` 分别是多少？

5. 计算 `sqrt(16)` 需要包含哪个头文件？编译时可能还需要什么选项？



<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---



