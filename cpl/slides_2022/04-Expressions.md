---
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../css/theme/solarized.css"
@import "../css/logo.css"
@import "../css/font.css"
@import "../css/color.css"
@import "../css/margin.css"
@import "../css/table.css"
@import "../css/main.css"
@import "../plugin/zoom/zoom.js"
@import "../plugin/customcontrols/plugin.js"
@import "../plugin/customcontrols/style.css"
@import "../plugin/chalkboard/plugin.js"
@import "../plugin/chalkboard/style.css"
@import "../plugin/menu/menu.js"
@import "../js/anychart/anychart-core.min.js"
@import "../js/anychart/anychart-venn.min.js"
@import "../js/anychart/pastel.min.js"
@import "../js/anychart/venn-ml.js"



<!-- slide data-notes="" -->


<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 表达式

<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_



<!-- slide vertical=true data-notes="" -->


##### 提纲

---

- 算术运算符

- 赋值运算符

- 自增自减运算符

- 表达式求值

- 表达式语句



<!-- slide data-notes="" -->


##### 运算符

--- 

我的批注 C语言的特点是更多强调表达式而非语句

==表达式==是由==变量==、==常量==和==运算符==所构成的

C拥有丰富的运算符集合, 包括: 

- 算术运算符

- 关系运算符

- 逻辑运算符

- 赋值运算符

- 自增和自减运算符

- 其他运算符



<!-- slide vertical=true data-notes="" -->


##### 算术运算符

--- 

五个二元算术运算符(有两个操作数): 

- `+` 加法

- `-` 减法

- `*` 乘法

- `/` 除法

- `%` 求余

两个一元算术运算符(仅一个操作数): 

- `+` 一元加

- `-` 一元减



<!-- slide vertical=true data-notes="" -->


##### 一元算术运算符

---

一元运算符只需要一个操作数: 

```C
i = +1;
j = -i;
```

我的批注 一元`+`运算符什么也不做, 它主要用于强调数字常数是正数



<!-- slide vertical=true data-notes="" -->


##### 二元算术运算符

---

==i % j==是i除以j时的余数

> ==10 % 3==的值为1, 而==12 % 4==的值为0

- 二元算术运算符(%除外)允许使用整数或浮点操作数, 并允许混合

- 当==int==和==float==操作数混合时, 结果的类型为==float==

> ==9 + 2.5f== 的值为11.5, 而==6.7f / 2== 的值为3.35



<!-- slide vertical=true data-notes="" -->


##### `/`和`%`运算符

---

`/`和`%`运算符使用需要特别注意: 

- 当两个操作数都是整数时, `/`会==截断==结果: 值==1 / 2==是0, 而不是0.5

- `%`运算符要求整数作为操作数；任一操作数不是整数, 程序将无法编译

- 使用==零==作为`/`或`%`的==右操作数==会导致未定义的行为

- `/`和`%`与负操作数一起使用时的行为在C89中由实现定义

我的批注 C99中, 除法结果总是向零截断, 并且==i % j==的值与==i==有相同符号



<!-- slide vertical=true data-notes="" -->


##### 由实现定义的行为

---

我的批注 C标准故意不指定语言的某些部分

- 未指定部分是因为C语言更强调==效率==, 常常意味着与硬件行为相匹配

我的启示 避免编写依赖于由具体实现所定义的行为的程序



<!-- slide vertical=true data-notes="" -->


##### 运算符优先级

---

`i + j * k`表示:

- 将`i`和`j`相加, 然后乘以`k`?

- 将`j`和`k`相乘, 然后加上`i`?

一种方案是添加括号, 写成`(i + j) * k`或`i + (j * k)`

我的批注 若括号被省略, C使用==运算符优先级==规则来确定表达式含义



<!-- slide vertical=true data-notes="" -->


##### 运算符优先级

---

==算术运算符== 的优先级: 

- 最高: `+ -` (一元)

- 其次: `* / %` (二元)

- 最低: `+ -` (二元)

示例: 

<div class="fullborder">

| `i + j * k`  | 等价于  | `i + (j * k)`    | 
| :--          | :--    | :--              |
| `-i * -j`    | 等价于  | `(-i) * (-j)`    | 
| `+i + j / k` | 等价于  | `(+i) + (j / k)` | 

</div>



<!-- slide vertical=true data-notes="" -->


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



<!-- slide vertical=true data-notes="" -->


##### 运算符结合性

---

如果运算符从右向左结合, 则它是右结合的运算符

一元算术运算符(`+`和`-`)都是右结合的: 

`-+i`等价于`-(+i)`



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算产品代码校验位

---

<div class="top-2">
  <img src="../img/upc.png" width=100px>
</div>

条形码下方数字的含义: 

- 第一个数字: 商品类型

- 第一组五位数: 制造商

- 第二组五位数: 产品(包括包装尺寸)

- 末位数字: 校验位, 用于帮助识别前面数字中的错误



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算产品代码校验位

---

计算校验位流程: 

- 第`1`、`3`、`5`、`7`、`9`和第`11`位数字求和

- 第`2`、`4`、`6`、`8`和第`10`位数字求和

- 将第一个总和乘以 `3` 并与第二个总和相加

- 从总数中减去 `1`

- 计算调整后的总数除以 `10` 的余数

- 用 `9` 减去余数



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算产品代码校验位

---

产品编码为 $0 13800 15173 5$ 的校验位计算示例: 

- 第一个总和: $0 + 3 + 0 + 1 + 1 + 3 = 8$

- 第二个总和: $1 + 8 + 0 + 5 + 7 = 21$

- 将第一个总和乘以 $3$ 并加上第二个总和得到 $45$

- 减去 $1$ 得到 $44$

- 除以 $10$ 的余数是 $4$

- 从 $9$ 中减去余数

- 结果是 $5$



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算产品代码校验位

---

upc.c程序要求用户输入产品编码的前 $11$ 位数字, 然后显示相应的校验位: 

```C
Enter the first (single) digit: 0
Enter first group of five digits: 13800
Enter second group of five digits: 15173
Check digit: 5
```

该程序将每个数字组读取为五个一位数字

我的批注 要读取单个数字, 可以在==scanf==中使用`%1d`转换说明



<!-- slide vertical=true data-notes="" -->


##### 程序: 计算产品代码校验位

---

*upc.c*

```C{.line-numbers}
/* Computes a Universal Product Code check digit */
 
#include <stdio.h>
 
int main(void)
{
  int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
      first_sum, second_sum, total;
 
  printf("Enter the first (single) digit: ");
  scanf("%1d", &d);
  printf("Enter first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
  first_sum = d + i2 + i4 + j1 + j3 + j5;
  second_sum = i1 + i3 + i5 + j2 + j4;
  total = 3 * first_sum + second_sum;
 
  printf("Check digit: %d\n", 9 - ((total - 1) % 10));
 
  return 0;
}
```



<!-- slide vertical=true data-notes="" -->


##### 赋值运算符

---

- 简单赋值: 将值存储到变量中, 如`=`

- 复合赋值: 更新已经存储在变量中的值, 如`+=`



<!-- slide vertical=true data-notes="" -->


##### 简单赋值

---

`v = e`先评估表达式`e`的值, 然后将值复制到`v`中

`e`可以是常量、变量或更复杂的表达式: 

```C{.line-numbers}
i = 5;            /* i is now 5  */
j = i;            /* j is now 5  */
k = 10 * i + j;   /* k is now 55 */
```



<!-- slide vertical=true data-notes="" -->


##### 简单赋值

---

如果 ==`v`== 和 ==`e`== 的类型不同, 在赋值时 ==`e`== 的值将转换为 ==`v`== 的类型: 

```C
int i;
float f;

i = 72.99f;   /* i is now 72 */
f = 136;      /* f is now 136.0 */
```



<!-- slide vertical=true data-notes="" -->


##### 简单赋值

---

在许多编程语言中, 赋值是一个语句；而在 ==`C`== 中, 赋值操作的结果类似运算符, 就像运算符 ==`+`== 一样

赋值表达式 ==`v = e`== 的值是赋值后 ==`v`== 的值

- 表达式 `i = 72.99f` 的值是 $72$, 而不是 $72.99$

```C
i = j = 50 + 3;
```



<!-- slide vertical=true data-notes="" -->


##### 副作用(side effects)

---

修改操作数的运算符被称为具有 ==副作用== , 如 `i + j` 没有 副作用

简单的赋值运算符有副作用: 它修改了左操作数

- 表达式 `i = 0` 的结果为 `0`, 它的副作用是将 `0` 赋值给`i`



<!-- slide vertical=true data-notes="" -->


##### 副作用(side effects)

---

由于 ==赋值== 是一个运算符, 因此可以将多个赋值链接在一起: 

```C{.line-numbers}
i = j = k = 0;
```

==`=`== 运算符是右结合的, 所以这个赋值等价于

```C{.line-numbers}
i = (j = (k = 0));
```



<!-- slide vertical=true data-notes="" -->


##### 副作用(side effects)

---

需要注意由于类型转换导致的链式赋值中产生的非预期的结果: 

```C{.line-numbers}
int i;
float f;

f = i = 33.3f;
```

`i` 被赋值为 `33`, 然后 `f` 被赋值为 `33.0`, 而不是 `33.3`



<!-- slide vertical=true data-notes="" -->


##### 副作用(side effects)

---

允许 `v` 类型值的地方都可以进行形如 `v = e` 的赋值: 

```C{.line-numbers}
i = 1;
k = 1 + (j = i);
printf("%d %d %d\n", i, j, k);
/* prints "1 1 2" */
```

我的批注 ==嵌入式赋值== 会使程序难以阅读, 容易隐藏错误



<!-- slide vertical=true data-notes="" -->


##### 左值

---

赋值运算符需要一个 ==左值== 作为其左操作数

==左值== 表示存储在计算机内存中的对象, 而不是常量或计算结果

- 变量是左值

- `10`或`2 * i`这样的表达式不是左值



<!-- slide vertical=true data-notes="" -->


##### 左值

---

由于赋值运算符需要一个左值作为其左操作数, 因此将任何其他类型的表达式放在赋值表达式的左侧都是非法的: 

```C{.line-numbers}
12 = i;      /*** WRONG ***/
i + j = 0;   /*** WRONG ***/
-i = j;      /*** WRONG ***/
```

我的启示 编译器将产生一条错误消息, 例如"invalid lvalue in assignment"



<!-- slide vertical=true data-notes="" -->


##### 复合赋值

---

使用变量的旧值来计算其新值的赋值很常见

例如: 

`i = i + 2;`

使用 ==`+=`== 复合赋值运算符, 可改写为: 

```C
i += 2;   /* same as i = i + 2; */
```



<!-- slide vertical=true data-notes="" -->


##### 复合赋值

---

还有其他九个复合赋值运算符, 包括: 

==`-= *= /= %=`==  位运算(`^= &= >>= <<= |=`)

所有复合赋值运算符的工作方式大致相同: 

<div class="fullborder">

| v += e | 将v加e, 将结果存储在v中         |
| :--    | :--                          |
| v -= e | 将v减e, 将结果存储在v中         |
| v *= e | 将v乘以e, 将结果存储在v中        |
| v /= e | 将v除以e, 将结果存储在v中        |
| v %= e | 计算v除以e的余数, 将结果存储在v中 |

</div>



<!-- slide vertical=true data-notes="" -->


##### 复合赋值

---

`v += e`与`v = v + e`可能==不等价==

- 一是运算符优先级:  

`i *= j + k` 与 `i = i * j + k` 不等价

- 在极少数情况下, `v += e` 不同于 `v = v + e` 因为 `v`本身有副作用(如`v`为`++i`或`i++`等)



<!-- slide vertical=true data-notes="" -->


##### 复合赋值

---

我的启示 使用复合赋值运算符时, 不要交换构成复合运算符的两个字符

虽然`i =+ j`能编译通过, 但意义不同, 它相当于 `i = (+j)`, 它只是将`j`的值复制到`i`中



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

对变量最常见的两种操作是 ==自增==(加 `1`)和 ==自减==(减 `1`): 

```C{.line-numbers}
i = i + 1;
j = j - 1;
```

可以使用复合赋值运算符进行自增和自减: 

```C{.line-numbers}
i += 1;
j -= 1;
```



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

C 特别提供了 `++` 自增 和 `-–` 自减 运算符

- ==`++`== 运算符将操作数加1

- ==`--`== 运算符将操作数减1

自增和自减运算符使用起来很棘手: 

- 有前缀运算符(`++i`和`–-i`)或后缀运算符(`i++`和`i--`)

- 副作用是修改操作数的值



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

评估表达式`++i` (前缀自增) 的结果是`i + 1`, 副作用是`i`自增`1`: 

```C{.line-numbers}
i = 1;
printf("i is %d\n", ++i);   /* prints "i is 2" */
printf("i is %d\n", i);     /* prints "i is 2" */
```

评估表达式`i++` (后缀自增) 的结果是`i`, 副作用是`i`随后自增`1`: 

```C{.line-numbers}
i = 1;
printf("i is %d\n", i++);   /* prints "i is 1" */
printf("i is %d\n", i);     /* prints "i is 2" */
```



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

`++i`表示 ==立即自增i==, 而`i++`表示 ==暂时使用i的旧值, 稍后再自增i==

- 稍后是多久后？C语言标准没有指定精确的时间, 但可以放心的是`i`将在执行下一条语句之前一定会自增



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

`--`运算符与`++`运算符相似: 

```C{.line-numbers}
i = 1;
printf("i is %d\n", --i);   /* prints "i is 0" */
printf("i is %d\n", i);     /* prints "i is 0" */
i = 1;
printf("i is %d\n", i--);   /* prints "i is 1" */
printf("i is %d\n", i);     /* prints "i is 0" */
```



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

当`++`或`--`在同一个表达式中多次使用时, 结果通常很难理解, 如: 

```C{.line-numbers}
i = 1;
j = 2;
k = ++i + j++;
```

最后一条语句等价于:

```C{.line-numbers}
i = i + 1;
k = i + j;
j = j + 1;
```
i, j和k的最终值分别为 2, 3和4.



<!-- slide vertical=true data-notes="" -->


##### 自增和自减运算符

---

相反, 执行语句

```C{.line-numbers}
i = 1;
j = 2;
k = i++ + j++;
```

`i`、`j`和`k`的值最终为`2`、`3`和`3`



<!-- slide vertical=true data-notes="" -->


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



<!-- slide vertical=true data-notes="" -->


##### 表达式求值

---

我的启示 运算符优先级表可用于向缺少括号的表达式添加括号

从具有最高优先级的运算符开始, 在运算符及其操作数周围加上括号

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



<!-- slide vertical=true data-notes="" -->


##### 子表达式求值顺序

---

表达式的值可能取决于计算其子表达式的顺序

==C== 没有定义子表达式评估的先后顺序(涉及逻辑与、逻辑或、条件和逗号运算符的子表达式除外)

- 在表达式 `(a + b) * (c - d)` 中并未定义是应该先计算 `(a + b)` 还是应该先计算 `(c – d)`



<!-- slide vertical=true data-notes="" -->


##### 子表达式求值顺序

---

大多数表达式具有相同的值, 无论其子表达式的计算顺序如何

- 当子表达式修改其操作数时, 则上述表述不成立: 

```C{.line-numbers}
a = 5;
c = (b = a + 2) - (a = 1);
```

- 第二条语句的执行结果是未定义的



<!-- slide vertical=true data-notes="" -->


##### 子表达式求值顺序

---

我的启示 避免在表达式中访问变量值的同时也修改该变量的值

在遇到这样的表达式时可能会产生编译警告消息, 例如"对`a`的操作可能未定义" 



<!-- slide vertical=true data-notes="" -->


##### 子表达式求值顺序

---

我的启示 为防止出现问题, 最好避免在子表达式中使用赋值运算符

相反, 建议使用一串分离的赋值表达式: 

```C{.line-numbers}
a = 5;
b = a + 2;
a = 1;
c = b - a;
```

`c`的值是确定的, 将始终为 `6`



<!-- slide vertical=true data-notes="" -->


##### 子表达式求值顺序

---

除了赋值运算符之外, 唯一修改其操作数的运算符是自增和自减

我的启示 使用这些运算符时, 需注意表达式不能依赖于特定的求值顺序

```C{.line-numbers}
i = 2;
j = i * i++;
```

很自然地认为`j`被赋值为`4`. 然而, `j`也可以被赋值为`6`

- 获取第二个操作数(i 的原始值), 然后将i递增

- 第一个操作数( i的新值)

- i的新值和旧值相乘, 得到 6



<!-- slide vertical=true data-notes="" -->


##### 未定义的行为

---

`c = (b = a + 2) - (a = 1);`和`j = i * i++;`均会产生未定义的行为

未定义行为的可能影响: 

- 当使用不同的编译器编译时, 程序运行的行为可能会有所不同

- 该程序可能一开始就无法编译

- 能编译但无法运行

- 能运行, 但程序可能会崩溃、行为不正常或产生无意义的结果

我的启示 应避免未定义的行为



<!-- slide vertical=true data-notes="" -->


##### 表达式语句

---

C 有一个不寻常的规则, 即任何表达式都可以用作语句
例子: 

```C
++i;
```

i首先递增, 然后获取i的新值, 然后丢弃



<!-- slide vertical=true data-notes="" -->


##### 表达式语句

---

由于它的值被丢弃了, 除非表达式有副作用, 否则将表达式用作语句几乎没有意义: 

```C
i = 1;     /* useful */
i--;       /* useful */
i * j - 1; /* not useful */
```



<!-- slide vertical=true data-notes="" -->


##### 表达式语句

---

一个无意的编码错误很容易会创建一个 ==什么都不做== 的表达式语句

例如: `i = j;` 误编写为 `i + j;`

一些编译器会检测无意义的表达式语句；给出一个警告, 比如`"statement with no effect"`.


