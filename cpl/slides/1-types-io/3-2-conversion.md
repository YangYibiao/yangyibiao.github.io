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

## 类型转换与未定义行为

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 表达式求值

- 副作用与左值

- 类型转换

- 编码实践

---


<!-- slide data-notes="" -->


##### 表达式求值

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.55em;">

到目前为止所涉及的运算符: 

<div class="threelines head-highlight-1 tr-hover">

| 优先级 | 名称       | 符号                           | 结合性 |
| :--   | :--       | :--                            | :--   |
| 1     | 自增自减(后缀) | `++ --`                    | left  |
| 2     | 自增自减(前缀)、正负号、按位取反 | `++ -- + - ~` | right |
| 3     | 乘法类     | `* / %`                        | left  |
| 4     | 加法类     | `+ -`                          | left  |
| 5     | 移位       | `<< >>`                        | left  |
| 6     | 按位与     | `&`                            | left  |
| 7     | 按位异或   | `^`                            | left  |
| 8     | 按位或     | `|`                            | left  |
| 9     | 赋值类     | `= += -= *= /= %= <<= >>= &= ^= |=` | right |

</div>

</div>

<div style="flex:1;">

- 单目运算符 (1、2 级) 高于双目算术; 位运算分三层 (5 移位、6-8 按位逻辑), 都在算术之下; 赋值 (9 级) 最低

- 结合性: 后缀 `++`/`--` 左结合; 前缀、一元 `+`/`-`/`~`、赋值是右结合; 其余左结合

- 为什么后缀 `++` 高于前缀? 语法里==后缀层贴着操作数==: `-x++` 是 `-(x++)`; 若反过来, `(-x)++` 是对非左值自增, 直接报错


<span class="blue">:fa-lightbulb-o:</span> 优先级表可用于给缺少括号的表达式==加括号==: 从最高优先级开始, 在运算符及其操作数周围加上括号 (下一页演示)。优先级是语言设计约定, 不必深究原因——==记表 + 拿不准就加括号==, 永远不会错

</div>

</div>

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

<!-- slide data-notes="" -->##### 子表达式求值顺序与未定义行为

---

表达式的值可能取决于==子表达式的计算顺序==——C 没有定义这个先后 (逻辑与或、条件、逗号运算符除外)

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.75em;">

```C{.line-numbers}
a = 5;
c = (b = a + 2) - (a = 1);   /* c 是几? */
```

```C{.line-numbers}
i = 2;
j = i * i++;                  /* j 是 4 还是 6? */
```

</div>

<div style="flex:1;">

- 同一表达式里==既读又改==同一变量, 产生==未定义的行为==: 结果随编译器不同而不同

- 后果可能是: 结果不同 / 崩溃 / ==\"看起来正常\"==——第三种最危险, 换个环境就翻车

- 规避: ==拆成多条语句==, 每句只做一件事

```C
b = a + 2;
a = 1;
c = b - a;      /* c 确定是 6 */
```

</div>

</div>

<span class="blue">:fa-lightbulb-o:</span> 避免在表达式中==访问变量值的同时也修改该变量==

---


<!-- slide data-notes="" -->

##### 副作用(side effects)

---

修改操作数的运算符被称为具有 ==副作用==; `i + j` 没有副作用, 而 ==赋值、自增自减==有

- 表达式 `i = 0` 的==结果==是 `0`, 副作用是把 `0` 存进 `i`

```C{.line-numbers}
i = 1;
k = 1 + (j = i);
printf("%d %d %d\n", i, j, k);
/* prints "1 1 2" */
```

- 这种==嵌入式赋值==语法合法, 但难读、易藏错——不推荐

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


<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.05;">

==隐式转换==: 不同类型混合运算/赋值时, 编译器自动转换

- 赋值: 右值自动转换为左值变量的类型

- 运算: 较低类型提升为较高类型 (`char`/`short` → `int`; `int` + `double` → `double`)

</div>

<div style="flex:1;font-size:0.75em;">

```C
int i;
double d = 3.14159;
i = d;      /* i 为 3 (截断小数) */
d = i;      /* d 为 3.0 */
```

```C
1 / 2;        /* 0   (整数除法) */
1.0 / 2;      /* 0.5 (2 提升为 double) */
```

</div>

</div>


<!-- slide data-notes="" -->


##### 演示: 为什么 %f 打出了奇怪的数?

---

<div style="font-size:0.8em;">

```C
int a = 9, b = 4;
printf("%d\n", a / b);          /* 2: 整数除法截断 */
printf("%f\n", a / b);          /* 错! 用 %f 打印 int → 结果不可预测 */
printf("%f\n", (double)a / b);  /* 2.250000: 先转换再除 */
printf("%f\n", a / 4.0);        /* 2.250000: 4.0 是 double, 整体提升 */
```

</div>

常见的运行结果: 

```
2
0.000000
2.250000
2.250000
```

- 类型转换发生在==运算时==: `a / b` 两个 `int` 相除, ==先截断、后转换==, 轮到 `printf` 时已经来不及了

- `%f` 期待 `double` 却收到 `int` → ==未定义行为==, 常见打出 `0.000000` 或乱码——`printf` 不会替你检查类型

- 正确姿势: 转换一个操作数 `(double)a / b`, 或直接用浮点字面量 `a / 4.0`

---

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

--


<!-- slide data-notes="" -->


##### 动手小练习: 四舍五入

---

`printf` 打印 `double` 会自动四舍五入, 但怎样把 `double` ==变量本身==四舍五入成整数?

<span class="yellow">:fa-weixin:</span> 提示: 强制转换是"向零截断"——小数部分直接丢掉。想个办法"借" `0.5`, 让截断变成四舍五入? 先自己写, 再翻页看参考代码

---


<!-- slide data-notes="" -->


##### 动手小练习: 四舍五入 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.7em;">

```C
#include <stdio.h>
int main(void) {
    double x;
    printf("请输入一个数: ");
    scanf("%lf", &x);
    int r = (int)(x + 0.5);
    printf("%.2f 四舍五入 = %d\n", x, r);
    return 0;
}
```

</div>

<div style="flex:1;">

- 核心一行: ==`(int)(x + 0.5)`==——先加 `0.5` 再截断, `3.7` → 4、`3.4` → 3

- 运行示例: 输入 `3.7` → `3.70 四舍五入 = 4`

- 试一试负数: `(int)(-3.7 + 0.5)` = `-3`, 但 -3.7 四舍五入应为 -4——C 的截断是==向零取整==, 负数要用 `(int)(x - 0.5)`

- 一个程序同时处理正负需要条件判断——==第 4 周==学完 `if` 就能写出来

</div>

</div>

---
<!-- slide data-notes="" -->


##### 编码实践: 数字拆分

---

输入一个==4 位整数== `N` (`1000`~`9999`), 输出两样东西: 

- 各位数字之==和==

- ==反转==后的数

例: 输入 `1234` → 输出 `和 = 10`、`反转 = 4321`

<span class="yellow">:fa-weixin:</span> 本题==假设输入合法== (就是 4 位数); 想拒绝非 4 位数的输入, 要等第 4 周学了 `if` 才能做校验

<span class="blue">:fa-lightbulb-o:</span> 提示: `/` 取高位、`%` 取低位——千位 = `n / 1000`, 百位呢? 反转数可以用 `%d%d%d%d` 打印四个一位数, 也可以重新组装。先自己写, 再翻页看参考代码

---


<!-- slide data-notes="" -->


##### 编码实践: 数字拆分 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.7em;">

```C
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    int qian = n / 1000;
    int bai  = n / 100 % 10;
    int shi  = n / 10 % 10;
    int ge   = n % 10;
    printf("和 = %d\n", qian + bai + shi + ge);
    printf("反转 = %d%d%d%d\n", ge, shi, bai, qian);
    return 0;
}
```

</div>

<div style="flex:1;">

- 千位 `n / 1000`; 百位 `n / 100 % 10`; 十位 `n / 10 % 10`; 个位 `n % 10`——==先除后模==, 一层层剥

- 反转数两种做法: `%d%d%d%d` 直接排四个一位数 (注意 `1000` 会打成 `0001`), 或 `ge*1000 + shi*100 + bai*10 + qian` 重新组装

- 输入 `1234` → `和 = 10`、`反转 = 4321`

</div>

</div>

<!-- slide data-notes="" -->


##### 课堂习题课

---

四道题, 限时 15 分钟, 每题都藏着==一个坑== (答案见讲义): 

1. ==时间换算==: 输入总秒数 `N`, 输出"X 小时 Y 分 Z 秒"。例: 输入 `3671`, 输出 `1 小时 1 分 11 秒`

2. ==温度转换==: 输入摄氏度 `C`, 输出华氏度 `F = C × 9 / 5 + 32`。检验: `100` 应输出 `212`; 若输出 `132`, 说明踩了整数除法的坑

3. ==平均分==: 输入三门课成绩 (整数), 输出平均分==保留两位小数==。例: 输入 `85 92 78`, 输出 `85.00`

4. (选做) ==XOR 交换==: 用位运算交换两个变量的值, ==不用临时变量==; 试试两个变量相同会怎样

---
<!-- slide data-notes="" -->


##### 课堂小测

---

1. `int i = (int) 3.9;` 中 `i` 的值是多少？`(float) 1 / 2` 的值是多少？

2. `i = d;` 中 d 是 double 型 3.99，赋值后 i 是多少？有精度损失提示吗？

3. 为什么 `j = i * i++;` 的结果不确定？这类表达式应该怎么避免？



<!-- slide data-notes="" -->


#####

---

<div class="top-2">
  <img src="../0-intro/figs/see-you.png" width=500px>
</div>

---


