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

<style>.reveal table{margin:0.5rem auto}</style>



<!-- slide data-notes="" -->

##### 提纲

---

- 运算符与算术运算

- 优先级与结合性

- 动手算一算

- 位运算

- 案例: 计算 ISBN-13 书号校验位

- 赋值运算符与复合赋值

- 自增和自减运算符

- 数学库函数

- 课堂小测

---


<!-- slide data-notes="" -->


##### 运算符与算术运算

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.02;font-size:0.82em;line-height:1.5;">

<span class="yellow">:fa-weixin:</span> C语言的特点在于更加强调==表达式的使用==: ==表达式==由==变量==、==常量==和==运算符==构成

C 的运算符包括: ==算术==、==关系==、==逻辑==、==赋值==、==自增和自减==及其他运算符

<div class="fullborder">

| 分类 | 运算符 | 说明 |
| :-- | :-- | :-- |
| 一元 (1 个操作数) | `+` `-` | 一元 `+` 什么也不做, 主要用于强调正数 |
| 二元 (2 个操作数) | `+ - * / %` | 加、减、乘、除、求余 |

</div>

- 二元运算符 (`%` 除外) 允许整数或浮点操作数, 也允许==混合==; `int` 与 `float/double` 混合时, 结果的类型为 `float/double`

- 例: `9 + 2.5` 得 ==11.5==, `6.7 / 2` 得 ==3.35==

</div>

<div style="flex:1;font-size:0.82em;line-height:1.5;">

==`/` 与 `%` 的要点==

- 两个操作数都是整数时, `/` 求商并==截断==小数: `1 / 2` 得 ==0==, `10 / 3` 得 ==3==

- `%` 求==余数==, 要求两个操作数都是整数, 否则==无法编译==: `10 % 3` 得 ==1==, `12 % 4` 得 ==0==

- 使用==零==作为 `/` 或 `%` 的右操作数会导致==未定义行为==

<span class="yellow">:fa-weixin:</span> C99 起, 除法结果总是==向零截断==, 且 `i % j` 的值与 `i` 有相同符号: `-10 / 3` 得 ==-3==, `-10 % 3` 得 ==-1==

<span class="blue">:fa-weixin:</span> ==由实现定义的行为==: C 标准故意不指定语言的某些部分 (为了==效率==, 常常意味着与硬件行为匹配), 例如 C89 中负数 `/`、`%` 的结果; 避免编写依赖具体实现的程序

</div>

</div>

---

<!-- slide data-notes="" -->##### 优先级与结合性

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;font-size:0.84em;line-height:1.5;">

`i + j * k` 是先加再乘, 还是先乘再加? 加括号可以消歧; 省略括号时, C 用==运算符优先级==规则来确定含义

==算术运算符== 的优先级 (高 → 低):

1. 一元 `+` `-`

2. 二元 `*` `/` `%`

3. 二元 `+` `-`

<div class="fullborder">

| 表达式 | 等价于 |
| :-- | :-- |
| `i + j * k` | `i + (j * k)` |
| `-i * -j` | `(-i) * (-j)` |
| `+i + j / k` | `(+i) + (j / k)` |

</div>

</div>

<div style="flex:1;font-size:0.84em;line-height:1.5;">

==结合性==: 多个==同优先级==运算符相邻时, 决定先算哪一边

- ==左结合==: 从左往右算, 二元 `*` `/` `%` `+` `-` 都是左结合

<div class="fullborder">

| 表达式 | 等价于 |
| :-- | :-- |
| `i - j - k` | `(i - j) - k` |
| `i * j / k` | `(i * j) / k` |

</div>

- ==右结合==: 从右往左算, 一元 `+` `-` 是右结合: `-+i` 等价于 `-(+i)`

<span class="blue">:fa-lightbulb-o:</span> 本课先记住: ==算术优先于关系, 关系优先于相等==; 拿不准时==加括号==, 意图最清楚

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 先手算, 再让程序验证
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 先在纸上写出下列表达式的值, 再让程序逐个打印验证:

1. `2 + 3 * 4`
2. `(2 + 3) * 4`
3. `10 / 3`
4. `10 % 3`
5. `10 / 3 * 3`
6. `2 + 3 > 4`
7. `1 < 2 == 1`

==提示==: 算术 > 关系 > 相等; 括号最高; `/` 截断, `%` 取余

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/3-types-io/code/task-priority.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-priority.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("2 + 3 * 4   = %d\n", 2 + 3 * 4);
  printf("(2 + 3) * 4 = %d\n", (2 + 3) * 4);
  printf("10 / 3      = %d\n", 10 / 3);
  printf("10 %% 3      = %d\n", 10 % 3);
  printf("10 / 3 * 3  = %d\n", 10 / 3 * 3);
  printf("2 + 3 > 4   = %d\n", 2 + 3 > 4);
  printf("1 < 2 == 1  = %d\n", 1 < 2 == 1);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `2+3*4` 是 14——乘法先于加法; 括号改变顺序得 20

- `10/3` 得 ==3== (截断), `10%3` 得 1; `10/3*3` 得 ==9==, 不是 10

- 关系/相等运算结果是 ==0 或 1==; `2+3>4` 等价于 `(2+3)>4`

- `1 < 2 == 1`: `<` 优先于 `==`, 结果是 ==1==

- 打印 `%` 时格式串里要写 ==`%%`== (百分号转义)

</div>
</div>

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

- 罪魁祸首是==整数除法的截断==: `9/4` 悄悄丢掉了小数部分 (下一课深入); 拿不准时==加括号==让意图明确: `(9 / 4) * 4` 或 `9 * 4 / 4`

---

<!-- slide data-notes="" -->


##### 动手算一算

---

<div style="font-size:0.86em;line-height:1.45;">

先自己心算下面表达式的值——不用编译器, 想清楚:

</div>

<div id="p8q" class="fullborder">

| 表达式 | 表达式 |
| :-- | :-- |
| 1. `10 + 20 % 7 * 3` | 5. `9 - 3 / 2 + 1` |
| 2. `2 + 3 * 4 / 2 % 3` | 6. `-5 - -3` |
| 3. `-10 / 3` | 7. `-5 + 6 * 4 % 5` |
| 4. `(10 + 4) / (3 + 1)` | 8. `10 - 4 % 3` |

</div>

<span class="blue">:fa-lightbulb-o:</span> 每题问自己两个问题: ==先算谁==? (优先级) 同级的==从左还是从右==? (结合性) 两个 `-` 挨着是什么意思? (一元负号)

<details style="font-size:0.8em;margin-top:4px;">

<summary style="cursor:pointer;color:#268bd2;">参考答案 (点击展开)</summary>

<div id="p8a" class="fullborder">

| 表达式 | 值 | 为什么 |
| :-- | :-- | :-- |
| `10 + 20 % 7 * 3` | `28` | `%` 高于 `+`; (20%7)*3 = 18 |
| `2 + 3 * 4 / 2 % 3` | `2` | 长链同级, 全部左结合: ((3*4)/2)%3 = 0 |
| `-10 / 3` | `-3` | 向零截断 (不是 -4!) |
| `(10 + 4) / (3 + 1)` | `3` | 括号管顺序, 管不了截断: 14/4 |
| `9 - 3 / 2 + 1` | `9` | 先截断: 3/2 = 1, 再 9-1+1 |
| `-5 - -3` | `-2` | (-5) - (-3); 第二个 `-` 是一元负号 |
| `-5 + 6 * 4 % 5` | `-1` | 先 6*4%5 = 4, 再 -5+4 |
| `10 - 4 % 3` | `9` | `%` 比 `-` 高 |

</div>

</details>

<style>#p8q table,#p8a table{margin:0.2rem auto}#p8q table{width:86%}#p8a table{width:97%}#p8q td,#p8a td,#p8a th{padding:0.08rem 0.45rem;font-size:1.0rem;line-height:1.2}</style>

---

<!-- slide data-notes="" -->


##### 位运算

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.08;font-size:0.8em;line-height:1.45;">

- 整数在内存里是==二进制==; ==位运算==逐位操作, 把 `int` 当成 32 根小开关

<div id="p9" class="fullborder">

| 运算符 | 含义 | 示例 (12 = `1100`, 10 = `1010`) |
| :-- | :-- | :-- |
| `&` | 按位与: 都是 1 才为 1 | `12 & 10 = 8` (`1000`) |
| `|` | 按位或: 有 1 就为 1 | `12 | 10 = 14` (`1110`) |
| `^` | 按位异或: 不同才为 1 | `12 ^ 10 = 6` (`0110`) |
| `~` | 按位取反: 0 变 1, 1 变 0 | `~12 = -13` (补码) |

</div>

手算: 两个数==对齐写成二进制==, 竖着一列一列算 (`&`/`|` 是一个符号, 别和 `&&`/`||` 搞混):

```
    1100   (12)
  & 1010   (10)
    1000   (8)
```

</div>

<div style="flex:1;font-size:0.8em;line-height:1.45;">

==移位==: `<<` 左移, `>>` 右移; 所有位整体挪动, 空出来的位置==补 0==

<div id="p9b" class="fullborder">

| 表达式 | 结果 | 规律 |
| :-- | :-- | :-- |
| `12 << 2` | `48` | ==乘 4== ($2^2$), `1100` → `110000` |
| `12 >> 2` | `3` | ==整除 4== ($2^2$), `1100` → `11` |
| `1 << 4` | `16` | 第 4 位亮起 |

</div>

- 左移 $n$ 位 = 乘 $2^n$; 右移 $n$ 位 = 整除 $2^n$ (对正数; 负数右移是实现定义的, 别依赖)

- 用途举例: `n & 1` 判奇偶 (结果是 1 就是奇数); `n << 1` 是乘 2 的快捷写法

<span class="blue">:fa-lightbulb-o:</span> 了解即可——知道"位运算在动二进制"就够了, 后面复合赋值会用到它们的缩写

</div>

</div>

<style>#p9 table,#p9b table{table-layout:auto;width:92%}#p9 td,#p9 th,#p9b td,#p9b th{padding:0.12rem 0.5rem;font-size:1.05rem;line-height:1.25}#p9 th:first-child,#p9 td:first-child{white-space:nowrap}#p9 table{margin:0.3rem auto}#p9b table{margin:0.3rem auto}</style>

---

<!-- slide data-notes="" -->##### 任务 3: 位运算实验 (选做)
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 令 `a = 12` (1100), `b = 10` (1010), 先手算再让程序打印这 6 个表达式:

```
a & b
a | b
a ^ b
~a
1 << 4
32 >> 2
```

样例 (常见结果): 8、14、6、-13、16、8

==提示==: 先把两个数写成二进制, ==逐位==算一遍再运行

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/3-types-io/code/task-bitwise.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-bitwise.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 3: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int a = 12, b = 10;
  printf("12 & 10 = %d\n", a & b);
  printf("12 | 10 = %d\n", a | b);
  printf("12 ^ 10 = %d\n", a ^ b);
  printf("~12     = %d\n", ~a);
  printf("1 << 4  = %d\n", 1 << 4);
  printf("32 >> 2 = %d\n", 32 >> 2);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `&`/`|`/`^` 逐位运算: 1100 & 1010 = 1000 (8)

- `~12` 得 ==-13==——负数用补码, 取反加一看不懂时翻回补码页

- `1 << 4` == 16, `32 >> 2` == 8: 左移相当于乘 2, 右移相当于除 2 (整数)

- 位运算在嵌入式/性能代码里常见; 本课要求==看懂==, 不要求熟练

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

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
/* Computes an ISBN-13 check digit (e.g., the textbook 978-7-04-030276-9) */
#include <stdio.h>
int main(void)
{
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
  int odd_sum, even_sum, total;

  printf("Enter the first twelve digits of an ISBN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, 
        &d10, &d11, &d12);
  odd_sum  = d1 + d3 + d5 + d7 + d9 + d11;
  even_sum = d2 + d4 + d6 + d8 + d10 + d12;
  total = odd_sum + 3 * even_sum;

  printf("Check digit: %d\n", (10 - total % 10) % 10);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.72em;line-height:1.4;">

教材 ISBN `978-7-04-030276-9` 的校验位计算示例: 

- 奇数位和: ==9 + 8 + 0 + 0 + 0 + 7 = 24==
- 偶数位和: ==7 + 7 + 4 + 3 + 2 + 6 = 29==
- 总数: ==24 + 3 × 29 = 111==
- ==111 mod 10 = 1==, 校验位 ==(10 - 1) mod 10 = 9== ✓

`isbn.c`



</div>

</div>

<!-- slide data-notes="" -->


##### 赋值运算符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.78em;line-height:1.42;">

==简单赋值==把值存进变量 (`=`); ==复合赋值==更新已有变量的值 (`+=`)

`v = e`: 先评估表达式 `e` 的值 (可以是常量、变量或更复杂的表达式), 然后将值复制到 `v` 中: 

```C{.line-numbers}
i = 5;            /* i is now 5  */
j = i;            /* j is now 5  */
k = 10 * i + j;   /* k is now 55 */
```

如果 ==`v`== 和 ==`e`== 的类型不同, 在赋值时 ==`e`== 的值将转换为 ==`v`== 的类型: 

<div style="font-size:0.85em;">

```C
int i;
float f;

i = 72.99f;   /* i is now 72 */
f = 136;      /* f is now 136.0 */
```

</div>

</div>

<div style="flex:1;font-size:0.78em;line-height:1.42;">

在许多编程语言中, 赋值是一个语句; 而在 ==C== 中, 赋值操作的结果类似运算符, 就像 `+` 一样

==赋值表达式 `v = e` 的值是赋值后 `v` 的值==

- 表达式 `i = 72.99f` 的值是 ==72==, 而不是 ==72.99==

由于赋值是运算符, 可以将多个赋值链接在一起; ==`=` 是右结合的==

```C{.line-numbers}
i = j = k = 0;      /* 等价于 i = (j = (k = 0)); */
```

<span class="yellow">:fa-weixin:</span> C 中==任何表达式都可以用作语句==, 其值被丢弃, 只有==副作用==有意义: `i--;` 有用, `i * j - 1;` 没用; 把 `i = j;` 误写成 `i + j;` 会得到一条==什么都不做==的表达式语句

</div>

</div>

---

<!-- slide data-notes="" -->


##### 复合赋值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.77em;line-height:1.38;">

使用变量的旧值来计算其新值的赋值很常见, 例如: `i = i + 2;`

使用 ==`+=`== 复合赋值运算符, 可改写为: 

```C
i += 2;   /* same as i = i + 2; */
```

还有其他九个复合赋值运算符: ==`-=` `*=` `/=` `%=`== 和==位运算的复合形式== (`^=` `&=` `>>=` `<<=` `|=`), 如 `i &= j` 等价于 `i = i & j`

<div class="fullborder">

| 写法 | 含义 |
| :-- | :-- |
| `v += e` | 将 v 加 e, 将结果存储在 v 中 |
| `v -= e` | 将 v 减 e, 将结果存储在 v 中 |
| `v *= e` | 将 v 乘以 e, 将结果存储在 v 中 |
| `v /= e` | 将 v 除以 e, 将结果存储在 v 中 |
| `v %= e` | 计算 v 除以 e 的余数, 将结果存储在 v 中 |

</div>

</div>

<div style="flex:1;font-size:0.77em;line-height:1.38;">

`v += e` 与 `v = v + e` 可能==不等价==

- ==运算符优先级==: `i *= j + k` 等价于 `i = i * (j + k)`, 与 `i = i * j + k` 不等价

- 复合运算符的左边必须是==可修改的左值==; `++i`、`i++` 都不是左值, `++i += e` 这类写法==非法==, 编译直接报错

<span class="blue">:fa-lightbulb-o:</span> 不要交换复合运算符的两个字符: `i =+ j` 能编译, 但相当于 `i = (+j)`, 只把 `j` 的值复制到 `i`

</div>

</div>

---

<!-- slide data-notes="" -->


##### 自增和自减运算符

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.12;font-size:0.77em;line-height:1.42;">

对变量最常见的两种操作是 ==自增== (加 `1`) 和 ==自减== (减 `1`); C 特别提供了 `++` 和 `--`

- `++` 将操作数加 1; `--` 将操作数减 1

- 有==前缀==运算符 (`++i`、`--i`) 与==后缀==运算符 (`i++`、`i--`)

- `i = i + 1;` 可写成 `i += 1;`, 最常用 `++i;`

<div class="fullborder">

| 表达式 (执行前 `i = 1`) | 表达式的值 | 执行后 `i` |
| :-- | :-- | :-- |
| `++i` | ==2== | 2 |
| `i++` | ==1== (旧值) | 2 |
| `--i` | ==0== | 0 |
| `i--` | ==1== (旧值) | 0 |

</div>

- 前缀: ==先加/减, 再使用新值==; 后缀: ==先使用旧值, 再加/减==

- 单独成句时 (`i++;`), 表达式的值被丢弃, 两种写法效果相同; ==区别只在"表达式的值"==

</div>

<div style="flex:1;font-size:0.77em;line-height:1.42;">

<div style="text-align:center;">

<svg viewBox="0 0 400 195" style="max-width:100%;height:195px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
  <text x="14" y="22" font-size="14" fill="#268bd2">++i (前缀)</text>
  <rect x="14" y="32" width="76" height="38" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
  <text x="52" y="57" font-size="15" fill="#073642" text-anchor="middle">i = 1</text>
  <path d="M90 51 H116" stroke="#268bd2" stroke-width="2" marker-end="url(#arrInc)"/>
  <rect x="120" y="32" width="76" height="38" rx="6" fill="#dceaf5" stroke="#268bd2" stroke-width="2.5"/>
  <text x="158" y="57" font-size="15" fill="#073642" text-anchor="middle">i = 2</text>
  <path d="M196 51 H222" stroke="#268bd2" stroke-width="2" marker-end="url(#arrInc)"/>
  <rect x="226" y="32" width="160" height="38" rx="6" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
  <text x="306" y="57" font-size="13" fill="#073642" text-anchor="middle">表达式的值 = 2</text>
  <text x="14" y="84" font-size="11.5" fill="#268bd2">先把 i 加 1, 再用新值</text>

  <text x="14" y="112" font-size="14" fill="#b58900">i++ (后缀)</text>
  <rect x="14" y="122" width="76" height="38" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
  <text x="52" y="147" font-size="15" fill="#073642" text-anchor="middle">i = 1</text>
  <path d="M90 141 H116" stroke="#b58900" stroke-width="2" marker-end="url(#arrInc2)"/>
  <rect x="120" y="122" width="140" height="38" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2.5"/>
  <text x="190" y="147" font-size="13" fill="#073642" text-anchor="middle">表达式的值 = 1</text>
  <path d="M260 141 H286" stroke="#b58900" stroke-width="2" marker-end="url(#arrInc2)"/>
  <rect x="290" y="122" width="96" height="38" rx="6" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
  <text x="338" y="147" font-size="15" fill="#073642" text-anchor="middle">i = 2</text>
  <text x="14" y="174" font-size="11.5" fill="#b58900">先用旧值, 再把 i 加 1</text>

  <text x="200" y="192" font-size="11" fill="#586e75" text-anchor="middle">i 最终都是 2; 表达式的值: 前缀 2, 后缀 1</text>

  <defs>
    <marker id="arrInc" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto">
      <path d="M0 0 L7 3.5 L0 7 z" fill="#268bd2"/>
    </marker>
    <marker id="arrInc2" markerWidth="7" markerHeight="7" refX="6" refY="3.5" orient="auto">
      <path d="M0 0 L7 3.5 L0 7 z" fill="#b58900"/>
    </marker>
  </defs>
</g>
</svg>

</div>

- 多个 `++`/`--` 混在同一个表达式中, 结果通常很难理解: `i=1, j=2` 时, `k = ++i + j++` 得 `k=4`, 而 `k = i++ + j++` 得 `k=3`

- ⚠ ==未定义行为==: 在同一个表达式里既修改又读取同一变量 (如 `printf("%d %d", i++, i)`), 求值顺序未定义, 输出因编译器而异——==永远不要这么写==; 实际编程中尽量==分行写==

</div>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 自增自减追踪
---
<div style="font-size:1.0em;line-height:1.75;">

==任务==: 令 `int i = 5;` 依次执行 `i++`、`++i`、`i--`、`--i`, 每条==语句==后打印 `i`

样例:

```
起始 i = 5
i++ 之后 i = 6
++i 之后 i = 7
```

==提示==: 语句形式下两者效果相同, ==区别在"表达式的值"==; 但==别把多个 ++ 和读取写进同一表达式== (未定义行为)

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/3-types-io/code/task-incdec.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-incdec.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 参考代码与要点
---
<div style="display:flex;align-items:flex-start;gap:24px;">
<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  int i = 5;
  printf("起始 i = %d\n", i);

  i++;                           /* 语句: 先用后加, 这里"用"不到 */
  printf("i++ 之后 i = %d\n", i);

  ++i;                           /* 语句: 先加后用 */
  printf("++i 之后 i = %d\n", i);

  i--;
  printf("i-- 之后 i = %d\n", i);

  --i;
  printf("--i 之后 i = %d\n", i);
  return 0;
}
```

</div>
<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `i++` 的==表达式值==是旧值 (5), `++i` 是新值 (7)——但本页把它们==单独成句==, 看不出差别

- 想观察差别, 要取表达式的值: `int a = i++;` 与 `int b = ++i;` 对比 a、b

- ⚠ ==未定义行为==: 把 `i++` 和读取 `i` 写进同一个表达式 (如 `printf("%d %d", i++, i)`) 时, 求值顺序未定义, 输出因编译器而异——==永远不要这么写==

- 结论: 单独成句时两种写法等价; 只有在表达式里取值时才有区别

</div>
</div>

---

<!-- slide data-notes="" -->##### 数学库函数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;font-size:0.8em;line-height:1.45;">

`+ - * / %` 就这么多, 要==开方、幂、对数、三角==? 调用 C 的==数学库函数==: 先 `#include <math.h>`

<div id="p19" class="fullborder">

| 函数 | 含义 |
| :-- | :-- |
| `fabs(x)` | 浮点数绝对值 |
| `sqrt(x)` | x 的平方根 |
| `pow(x, y)` | x 的 y 次方 |
| `exp(x)` / `log(x)` | e 的 x 次方 / 自然对数 |
| `log10(x)` | 常用对数 |
| `sin(x)` / `cos(x)` / `tan(x)` | 三角函数 (x 为==弧度==) |

</div>

- 返回值都是 ==double==, 打印用 `%f` (整数绝对值 `abs(x)` 不同: 它在 `<stdlib.h>` 中声明, 返回 `int`)

</div>

<div id="p19c" style="flex:1;font-size:0.62em;line-height:1.38;">

```C{.line-numbers}
#include <stdio.h>
#include <math.h>

int main(void) {
    printf("sqrt(9) = %f\n", sqrt(9.0));
    printf("pow(2, 10) = %f\n", pow(2.0, 10));
    printf("fabs(3 - 5.5) = %f\n", fabs(3 - 5.5));
    printf("sqrt(2) = %.3f\n", sqrt(2));
    /* 0.5 次方 = 开方 */
    printf("pow(2, 0.5) = %.3f\n", pow(2, 0.5)); 
    return 0;
}
```

运行结果: 

```
sqrt(9) = 3.000000
pow(2, 10) = 1024.000000
fabs(3 - 5.5) = 2.500000
sqrt(2) = 1.414
pow(2, 0.5) = 1.414
```

- 函数调用是==表达式==: `sqrt(9.0)` 可以直接放进 `printf` 里算; `pow(2, 0.5)` 就是 $\sqrt{2}$ (==0.5 次方 = 开方==); 控制小数位用 `%.3f`

</div>

</div>

<style>#p19 table{margin:0.2rem auto}#p19 td,#p19 th{padding:0.1rem 0.5rem;font-size:1.0rem;line-height:1.22}#p19c pre{font-size:0.95rem!important;line-height:1.28!important;margin:0.3rem 0}#p19c pre code{font-size:0.95rem!important;line-height:1.28!important}</style>

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `1 / 2` 的值是多少？`7 % 2` 呢？`9 % 3` 呢？

2. `-i * -j` 等价于什么？`i * j / k` 按什么顺序计算？

3. `i += 2` 等价于什么？`i *= j + k` 等价于 `i = i * j + k` 吗？

4. `i = 1; j = i++;` 执行后 `i` 和 `j` 分别是多少？

5. 计算 `sqrt(16)` 需要包含哪个头文件？



<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---



