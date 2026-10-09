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

## 循环结构 (上)

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 重复语句与 while

- do-while 语句

- break 与 continue

- 案例: 平方表、数列求和、整数的位数

---


<!-- slide data-notes="" -->


##### 为什么需要循环

---

有些工作就是"同一件事做很多遍":

- 打印 1 到 100——手写 100 行 `printf`?

- 输入 100 个成绩求平均——声明 100 个变量?

- 之前讲过的"找最高分"——求用户输入数据的最大值, 当时只能处理固定几个数

计算机最擅长==不厌其烦地重复==——==循环==就是把这个能力交给你的语法

---


<!-- slide data-notes="" -->


##### 三种循环语句

---

C 有三种循环语句 (控制表达式的玩法下面细讲):

- ==while==: 先判断, 再执行

- ==do-while==: 先执行, 再判断

- ==for==: 最适合计数循环

---


<!-- slide data-notes="" -->


##### while语句

---

`while` 是设置循环最简单的方法, 形式为 `while (表达式) 语句`

- ==表达式==是==控制表达式==(条件表达式); ==语句==是==循环体==, 可为单条语句或 `{}` 复合语句

while 示例: 

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n, i = 1;
    scanf("%d", &n);
    while (i < n)        /* 控制表达式 */
        i = i * 2;       /* 循环体 */
    printf("%d\n", i);
    return 0;
}
```

执行while语句时, 首先计算控制表达式

- 非零 (true) 就执行循环体并再次测试; 持续到控制表达式变为零才停止

---

<!-- slide data-notes="" -->


##### while语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

用 `while` 找 ≥ `n` 的最小 2 的幂:

```C{.line-numbers}
i = 1;
while (i < n)
  i = i * 2;
```

</div>

<div style="flex:1.15;font-size:0.72em;">

`n = 10` 时, while 的执行过程:

```C{.line-numbers}
i = 1;        i 现在是 1
i < n?        是, 继续
i = i * 2;    i 现在是 2
i < n?        是, 继续
i = i * 2;    i 现在是 4
i < n?        是, 继续
i = i * 2;    i 现在是 8
i < n?        是, 继续
i = i * 2;    i 现在是 16
i < n?        否, 退出循环
```

</div>

</div>

---

<!-- slide data-notes="" -->


##### while语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

```C{.line-numbers}
while (i > 0) {          /* 循环体: 两条语句 */
  printf("%d\n", i);
  i--;
}
```

```C{.line-numbers}
while (i < n) {          /* 循环体只有一条语句 */
  i = i * 2;
}
```

```C{.line-numbers}
i = 10;
while (i > 0) {
  printf("%d\n", i);
  i--;
}
printf("发射!\n");
```

</div>

<div style="flex:1;">

循环体必须是==一条==语句

要执行多条语句, 就用大括号包成==一条复合语句==:

即使只有一条语句, ==建议也用大括号==——以后加语句不用补:

看一个火箭发射倒计时的例子: 打印 10、9、…、1, 最后喊出"发射!"

最后一行输出是 `发射!`

</div>

</div>

<!-- slide data-notes="" -->


##### while语句

---

while 的几个注意点: 

- 循环结束时, 控制表达式==一定为假==——倒计时循环结束, 说明 `i ≤ 0` 了

- 循环体可能==一次都不执行==——条件在循环体之前先判定

- 倒计时还有更简洁的写法 (`i--` 直接在 printf 里用掉): 

```C{.line-numbers}
while (i > 0)
  printf("%d\n", i--);
```

---

<!-- slide data-notes="" -->


##### 无限循环

---

如果控制表达式的值始终非零, while语句将无法终止

控制表达式恒为非零, 就是无限循环: 

```C
while (1) …
```

这样的while语句将永远执行, 除非它的循环体中含有跳出循环控制的语句(break, goto, return)或调用导致程序终止的函数

---

<!-- slide data-notes="" -->


##### 程序: 打印平方表

---

==现场演示==: 打印平方表——用户指定行数, 每行输出"数字 + 它的平方"

样例 (输入 5):

```
请输入行数: 5
         1         1
         2         4
         3         9
         4        16
         5        25
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 两列右对齐——第 2 周的 `%10d` 字段宽度还记得吗?

---


<!-- slide data-notes="" -->


##### 程序: 打印平方表 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
/* 打印平方表 */
#include <stdio.h>

int main(void)
{
  int i, n;

  printf("请输入行数: ");
  scanf("%d", &n);

  i = 1;
  while (i <= n) {
    printf("%10d%10d\n", i, i * i);
    i++;
  }

  return 0;
}
```

</div>

<div style="flex:1;">

- `i` 从 1 到 n, 循环条件 `i <= n`——==计数循环==用 while 的最常见写法

- 循环体两条语句: 打印一行 + 计数递增——所以用大括号

- `%10d`: 占 10 格右对齐, 两列对齐成表

</div>

</div>

<!-- slide data-notes="" -->


##### 程序: 数列求和

---

==现场演示==: 对用户输入的整数数列求和——用户不断输入整数, 直到输入 ==`0`== 为止, 输出总和

样例:

```
输入整数 (0 结束): 8 23 71 5 0
总和是: 107
```

<span class="blue">:fa-lightbulb-o:</span> 提示: `0` 是==哨兵值==——本身不参与求和, 只用来表示"输完了"。先自己写, 再翻页看参考代码

---


<!-- slide data-notes="" -->


##### 程序: 数列求和 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
/* 对数列求和 */
#include <stdio.h>

int main(void)
{
  int n, sum = 0;

  printf("输入整数 (0 结束): ");
  scanf("%d", &n);
  while (n != 0) {
    sum += n;
    scanf("%d", &n);
  }
  printf("总和是: %d\n", sum);

  return 0;
}
```

</div>

<div style="flex:1;">

- 先读一个数, 不是 `0` 就累加、再读下一个——==读一个, 判一个, 加一个==

- `sum` 初值必须为 ==0== (累加的起点)

- 哨兵值模式: 用特殊值标记"输入结束", 循环条件就是 `n != 0`

</div>

</div>

<!-- slide data-notes="" -->


##### do语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.7em;">

一般形式: `do 语句 while (表达式);`

==do-while 最典型的用途: 输入校验==——必须先读一次, 才知道合不合法:

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n;
    do {
        printf("请输入一个正整数: ");
        scanf("%d", &n);
    } while (n <= 0);
    printf("你输入了 %d\n", n);
    return 0;
}
```

</div>

<div style="flex:1;">

- 执行顺序: ==先执行循环体 → 再算控制表达式 → 非零再来一轮==

- 与 `while` 的唯一区别: 循环体==至少执行一次==

- "先读后判"的场景 while 写起来很别扭 (得先预读一次), do-while 刚刚好——对比上一页数列求和的预读写法

</div>

</div>

---

<!-- slide data-notes="" -->


##### do语句

---

<span class="blue">:fa-weixin:</span> ==建议给所有 do 语句都加大括号==——没有大括号的 do 很容易被误读成 while:

```C
do
    printf("%d\n", i--);
while (i > 0);
```

- 粗心的读者会把结尾的 `while` 当成新循环的开头 

---

<!-- slide data-notes="" -->


##### 程序: 计算整数的位数

---

==现场演示==: 输入一个非负整数, 输出它是几位数

样例:

```
输入一个非负整数: 60
它有 2 位数字
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 每除以 10 一次, 位数就多 1——直到除成 0。想想为什么这里用 do-while 比 while 更合适? 先自己写, 再翻页看参考代码

---


<!-- slide data-notes="" -->


##### 程序: 计算整数的位数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.65em;">
```C{.line-numbers}
/* 计算整数的位数 */
#include <stdio.h>

int main(void)
{
  int digits = 0, n;

  printf("输入一个非负整数: ");
  scanf("%d", &n);

  do {
    n /= 10;
    digits++;
  } while (n > 0);

  printf("它有 %d 位数字\n", digits);
  return 0;
}
```

</div>

<div style="flex:1;">

- 思路: 反复除以 `10` 直到变 `0`, ==除的次数就是位数== (60 → 6 → 0, 两次 → 2 位)

- 为什么用 do-while: 每个整数==至少有一位数字==——输入 `0` 时 while 版会输出 0 位 (错的!), do-while 先除一次正好

- `digits` 初值 0, 每轮 +1——计数循环的惯用写法

</div>

</div>

<!-- slide data-notes="" -->


##### break语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.65em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n = 13, d = 2;
    while (d < n) {
        if (n % d == 0)
            break;
        d++;
    }
    if (d < n)
        printf("%d 能被 %d 整除\n", n, d);
    else
        printf("%d 是素数\n", n);
    return 0;
}
```

</div>

<div style="flex:1;">

`break语句`可以把程序控制从 `switch` 语句中转移出来, 也可以用于跳出`while`、`do`或`for`循环

检查数字`n`是否为素数的循环可以在找到约数(因子)后立即使用break语句终止循环:

循环终止后, 可以使用`if语句`来确定循环是提前终止(因此n不是素数)还是正常终止(n是素数):



</div>

</div>

<!-- slide data-notes="" -->


##### break语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.65em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n;
    while (1) {
        printf("输入一个数 (0 结束): ");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%d 的立方是 %d\n", n, n * n * n);
    }
    return 0;
}
```

```C{.line-numbers}
while (…) {
  switch (…) {
    …
    break;
    …
  }
}
```

</div>

<div style="flex:1;">

`break`语句对于编写退出点位于循环体中间而不是开头或结尾的循环特别有用

读取用户输入并在输入特定值时终止的循环通常属于这种类别:

`break语句`把程序控制从最内层的`while`、`do`、`for`或`switch`转移出去; 当这些语句嵌套时, `break语句`只能跳出一层嵌套:

`break`语句把程序控制从`switch`语句中转移出来, 但是不能跳出`while`循环

</div>

</div>

<!-- slide data-notes="" -->


##### continue语句

---

任务: ==读入 10 个整数, 计算 100/i 的和==——`i` 为 `0` 时除零会崩溃, 必须跳过

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;font-size:0.55em;">

==用 continue 的版本==: 

```C{.line-numbers}
n = 0;
sum = 0;
while (n < 10) {
  scanf("%d", &i);
  if (i == 0)
    continue;      /* 跳过除零 */
  sum += 100 / i;
  n++;
}
```

</div>

<div style="flex:1;font-size:0.55em;">

==不用 continue 的版本==: 

```C{.line-numbers}
n = 0;
sum = 0;
while (n < 10) {
  scanf("%d", &i);
  if (i != 0) {
    sum += 100 / i;
    n++;
  }
}
```

</div>

</div>

- `break` 跳出循环; `continue` 跳到==本轮循环体末尾==, 直接进入下一轮 (循环照常继续)

- 效果: 读到 `0` 必须跳过——否则 `100 / i` ==除零崩溃==; continue 的必要性不依赖题目规定, 而是程序的生死问题

- 另一个区别: `break` 可用于 switch 和循环; ==`continue` 只能用于循环==



<!-- slide data-notes="" -->

##### 空语句: 一个分号的代价

---

==空语句==: 只有一个分号 `;`, 什么都不做

- 意外写出的空语句是经典 bug——多打的一个分号会让循环体/if 体变成"空":

```C
while (i < n);        /* BUG: 循环体是空语句 → 死循环! */
  sum += i++;         /* 这行其实只执行一次 */

if (d == 0);          /* BUG: if 的体是空语句 → 条件成立时什么都不做 */
  printf("zero");
```

- 编译器通常会警告 (`empty body in a while`), 但==不要依赖警告==

- 好习惯: ==循环体和 if 后面永远加大括号==, 哪怕只有一条语句

---

<!-- slide data-notes="" -->##### 课堂小测

---

1. while 和 do-while 唯一的区别是什么？

2. `while (1)` 是什么循环？怎么让它停下来？

3. break 和 continue 分别把控制转移到哪里？

4. 输入一个非负整数，输出它的位数（用 do-while），关键思路是什么？

<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


