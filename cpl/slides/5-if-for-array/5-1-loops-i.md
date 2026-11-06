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

- 为什么需要循环: 三种循环语句

- while 语句与复合循环体

- do-while 与输入校验

- 案例: 平方表、数列求和、整数的位数

- break、continue 与空语句陷阱

- 课堂小测: 概念 + 编码

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

<div style="text-align:center;margin-top:6px;">
<svg viewBox="0 0 400 200" style="max-width:100%;height:190px;">
  <defs>
    <marker id="ar51g" markerWidth="7" markerHeight="7" refX="5.5" refY="3" orient="auto">
      <path d="M0,0 L6,3 L0,6 Z" fill="#586e75"/>
    </marker>
    <marker id="ar51b" markerWidth="7" markerHeight="7" refX="5.5" refY="3" orient="auto">
      <path d="M0,0 L6,3 L0,6 Z" fill="#268bd2"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <line x1="133" y1="8" x2="133" y2="160" stroke="#eee8d5" stroke-width="2" stroke-dasharray="5 5"/>
    <line x1="266" y1="8" x2="266" y2="160" stroke="#eee8d5" stroke-width="2" stroke-dasharray="5 5"/>

    <text x="66" y="24" font-size="15" font-weight="700" fill="#268bd2" text-anchor="middle" font-family="Menlo, monospace">while</text>
    <polygon points="66,36 94,54 66,72 38,54" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="66" y="58" font-size="11" fill="#073642" text-anchor="middle">条件</text>
    <line x1="66" y1="72" x2="66" y2="84" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <text x="73" y="81" font-size="9.5" fill="#859900">真</text>
    <rect x="38" y="86" width="56" height="22" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="66" y="101" font-size="10.5" fill="#073642" text-anchor="middle">循环体</text>
    <line x1="94" y1="54" x2="114" y2="54" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <text x="101" y="48" font-size="9.5" fill="#dc322f">假</text>
    <path d="M38 97 H28 V54 H35" fill="none" stroke="#268bd2" stroke-width="2" marker-end="url(#ar51b)"/>
    <text x="66" y="132" font-size="10" fill="#586e75" text-anchor="middle">先判断,可能 0 次</text>

    <text x="200" y="24" font-size="14" font-weight="700" fill="#268bd2" text-anchor="middle" font-family="Menlo, monospace">do-while</text>
    <rect x="172" y="34" width="56" height="22" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="200" y="49" font-size="10.5" fill="#073642" text-anchor="middle">循环体</text>
    <line x1="200" y1="56" x2="200" y2="68" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <polygon points="200,70 228,86 200,102 172,86" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="200" y="90" font-size="11" fill="#073642" text-anchor="middle">条件</text>
    <path d="M172 86 H160 V45 H169" fill="none" stroke="#268bd2" stroke-width="2" marker-end="url(#ar51b)"/>
    <text x="166" y="66" font-size="9.5" fill="#859900" text-anchor="middle">真</text>
    <line x1="200" y1="102" x2="200" y2="114" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <text x="207" y="111" font-size="9.5" fill="#dc322f">假</text>
    <text x="200" y="130" font-size="10" fill="#586e75" text-anchor="middle">先执行,至少 1 次</text>

    <text x="333" y="24" font-size="15" font-weight="700" fill="#268bd2" text-anchor="middle" font-family="Menlo, monospace">for</text>
    <rect x="301" y="30" width="64" height="20" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="333" y="44" font-size="10.5" fill="#073642" text-anchor="middle" font-family="Menlo, monospace">i = 1</text>
    <text x="369" y="44" font-size="8.5" fill="#93a1a1">初始化</text>
    <line x1="333" y1="50" x2="333" y2="58" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <polygon points="333,60 359,74 333,88 307,74" fill="#fdf6e3" stroke="#b58900" stroke-width="2"/>
    <text x="333" y="78" font-size="10" fill="#073642" text-anchor="middle">条件</text>
    <line x1="333" y1="88" x2="333" y2="96" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <text x="340" y="95" font-size="9.5" fill="#859900">真</text>
    <rect x="301" y="98" width="64" height="20" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="333" y="112" font-size="10.5" fill="#073642" text-anchor="middle">循环体</text>
    <line x1="333" y1="118" x2="333" y2="124" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <rect x="301" y="126" width="64" height="20" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="333" y="140" font-size="10.5" fill="#073642" text-anchor="middle" font-family="Menlo, monospace">i++</text>
    <text x="369" y="140" font-size="8.5" fill="#93a1a1">步长</text>
    <path d="M365 136 H380 V74 H362" fill="none" stroke="#268bd2" stroke-width="2" marker-end="url(#ar51b)"/>
    <line x1="307" y1="74" x2="288" y2="74" stroke="#586e75" stroke-width="1.5" marker-end="url(#ar51g)"/>
    <text x="296" y="68" font-size="9.5" fill="#dc322f">假</text>
    <text x="333" y="158" font-size="10" fill="#586e75" text-anchor="middle">初始化 → 条件 → 体 → 步长</text>

    <text x="200" y="186" font-size="11.5" fill="#586e75" text-anchor="middle">while / for 先判断;do-while 先执行——三者可互相改写</text>
  </g>
</svg>
</div>

---


<!-- slide data-notes="" -->


##### while语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.7em;">

`while` 是最简单的循环语句, 形式为 `while (表达式) 语句`

- ==表达式==是==控制表达式==(条件表达式); ==语句==是==循环体==, 可为单条语句或 `{}` 复合语句

例: 找 ≥ `n` 的最小 2 的幂:

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

</div>

<div style="flex:1;font-size:0.72em;">

`n = 10` 时, `while` 的执行过程:

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

- 执行过程: 先计算控制表达式; ==非零 (true) 就执行循环体并再次测试==, 持续到控制表达式变为零才停止

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

<div style="flex:1;font-size:0.9em;line-height:1.5;">

循环体必须是==一条==语句

要执行多条语句, 就用大括号包成==一条复合语句==:

即使只有一条语句, ==建议也用大括号==——以后加语句不用补:

看一个火箭发射倒计时的例子: 打印 10、9、…、1, 最后喊出"发射!"

最后一行输出是 `发射!`

</div>

</div>

<!-- slide data-notes="" -->


##### while语句: 注意点与无限循环

---

- 循环结束时, 控制表达式==一定为假==——倒计时循环结束, 说明 `i ≤ 0` 了

- 循环体可能==一次都不执行==——条件在循环体之前先判定

- 倒计时还有更简洁的写法 (`i--` 直接在 printf 里用掉):

```C{.line-numbers}
while (i > 0) {
  printf("%d\n", i--);
}
```

- 控制表达式==恒为非零==就是无限循环: `while (1) { … }` 会永远执行, 除非循环体里有 `break`、`goto`、`return`, 或调用终止程序的函数

---
<!-- slide data-notes="" -->


##### 程序: 打印平方表

---

==现场演示==: 打印平方表——用户指定行数, 每行输出"数字 + 它的平方"

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/5-if-for-array/code/skeleton.c" style="display:inline-block;margin:4px 0 0;padding:3px 10px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.75em;text-decoration:none;">⚡ 打开 skeleton.c</a>

样例 (输入 5):

```
请输入行数: 5
         1         1
         2         4
         3         9
         4        16
         5        25
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 两列右对齐——之前的 `%10d` 字段宽度还记得吗?

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

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/5-if-for-array/code/skeleton.c" style="display:inline-block;margin:4px 0 0;padding:3px 10px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.75em;text-decoration:none;">⚡ 打开 skeleton.c</a>

样例:

```
输入整数 (0 结束): 8 23 71 5 0
总和是: 107
```

<span class="blue">:fa-lightbulb-o:</span> 提示: `0` 是==哨兵值==——本身不参与求和, 只用来表示"输完了"

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

<!-- slide data-notes="" -->##### 任务 1: 猜数字 (循环版)

---

<div style="font-size:0.95em;line-height:1.6;">

==任务==: 程序心里想好一个 1~100 的整数 (骨架里已设为 42), 你反复输入猜测, 程序提示"太大"或"太小", 直到猜中; 最后输出猜了几次

样例:

```
猜一个 1~100 的整数: 50
太大了
猜一个 1~100 的整数: 25
太小了
猜一个 1~100 的整数: 42
猜对了! 你猜了 3 次
```

==提示==:

- 先读一次, 再进入 while——循环条件就是"没猜中"

- 每轮: 比较并提示 → 计数 → 再读下一个; 猜中那次不在循环体里, 计数别漏

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/5-if-for-array/code/task1-guess.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task1-guess.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 1: 参考代码与要点

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
/* guess.c: 猜数字循环版 */
#include <stdio.h>
int main(void) {
  int secret = 42, guess, count = 0;
  printf("猜一个 1~100 的整数: ");
  scanf("%d", &guess);
  while (guess != secret) {
    if (guess > secret) printf("太大了\n");
    else                printf("太小了\n");
    count++;
    printf("猜一个 1~100 的整数: ");
    scanf("%d", &guess);
  }
  count++;
  printf("猜对了! 你猜了 %d 次\n", count);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- 循环条件 `guess != secret`: 猜中就退出——沿用"先读一次, 再判断"的哨兵模式

- 循环体末尾再读一次, 下一轮判断的才是新输入; 忘了这句就是死循环

- 计数: 循环体里的 `count++` 只数"猜错"的次数, 猜中那次在循环外, 所以结束后再 `count++`

- 也可以用 `while (1)` + 猜中时 `break`——下一节的 break 会让这种写法更直接

</div>

</div>

---

<!-- slide data-notes="" -->


##### do语句

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.7em;">

一般形式: `do 语句 while (表达式);`

==最典型的用途: 输入校验==——必须先读一次, 才知道合不合法:

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

<div style="flex:1;font-size:0.74em;">

- 执行顺序: ==先执行循环体 → 再算控制表达式 → 非零再来一轮==

- 与 `while` 的唯一区别: 循环体==至少执行一次==——`0` 也是一位数, 至少拆一次位

- "先读后判"的场景 `while` 写起来别扭 (得先预读一次), do-while 刚刚好——对比数列求和的预读写法

- <span class="blue">:fa-weixin:</span> ==建议给所有 do 语句都加大括号==——没有大括号的 `do` 容易被误读成 `while` 的开头:

```C
do
    printf("%d\n", i--);
while (i > 0);   /* 这个 while 不是新循环 */
```

</div>

</div>

---
<!-- slide data-notes="" -->##### 任务 2: 各位数字之和

---

<div style="font-size:1.0em;line-height:1.75;">

==任务==: 输入一个非负整数, 输出它各位数字之和; 0 也要能正确处理

样例:

```
输入一个非负整数: 12345
各位数字之和 = 15
输入一个非负整数: 0
各位数字之和 = 0
```

==提示==:

- 拆位老办法: `% 10` 取末位, `/ 10` 去掉末位

- 至少要做一次——`do-while` 正合适; 想想输入 0 时 while 版会怎样

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/5-if-for-array/code/task2-digit-sum.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task2-digit-sum.c (骨架)</a>

</div>

---

<!-- slide data-notes="" -->##### 任务 2: 参考代码与要点

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.1;font-size:0.6em;">

```C{.line-numbers}
/* digitsum.c: 各位数字之和 */
#include <stdio.h>
int main(void) {
  int n, sum = 0;

  printf("输入一个非负整数: ");
  scanf("%d", &n);

  do {
    sum += n % 10;
    n /= 10;
  } while (n > 0);

  printf("各位数字之和 = %d\n", sum);
  return 0;
}
```

</div>

<div style="flex:1;font-size:0.9em;line-height:1.7;">

- `n % 10` 取末位、`n /= 10` 缩位, 循环到 n 变 0——和"计算整数的位数"是同一套拆位

- 用 do-while: 0 也是一位数, 循环体==至少执行一次==; 换成 `while (n > 0)`, 输入 0 时一次都不进 (本题 sum 初值 0 碰巧对, 换成统计位数就错了)

- 循环结束后 n 已经被改成 0; 还要用原数的话, 先复制一份 (下一节"位数"的例子就是这么做的)

- `sum` 是累加器, 初值必须为 ==0==——和数列求和的 `sum` 一样

</div>

</div>

---

<!-- slide data-notes="" -->


##### 程序: 计算整数的位数

---

==现场演示==: 输入一个非负整数, 输出它是几位数

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/5-if-for-array/code/skeleton.c" style="display:inline-block;margin:4px 0 0;padding:3px 10px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.75em;text-decoration:none;">⚡ 打开 skeleton.c</a>

样例:

```
输入一个非负整数: 60
它有 2 位数字
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 每除以 10 一次, 位数就多 1——直到除成 0。想想为什么这里用 do-while 比 while 更合适?

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

<style>.break51 p:last-child { margin-bottom: 0 !important; }</style>

<div class="break51" style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.15;font-size:0.62em;">

`break` 把控制从 `switch` 中转出, 也可跳出循环。

检查 `n` 是否为素数的循环, 找到因子后立即 `break`:

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n = 13, d = 2;
    while (d < n) {
        if (n % d == 0) {
            break;
        }
        d++;
    }
    if (d < n) {
        printf("%d 能被 %d 整除\n", n, d);
    } else {
        printf("%d 是素数\n", n);
    }
    return 0;
}
```

循环终止后, 用 `if` 判断: ==提前终止 → n 不是素数==; ==正常终止 → n 是素数==。

</div>

<div style="flex:1;font-size:0.62em;">

`break` 适合==退出点位于循环体中间==的场景 (读取输入并在特定值时终止):

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n;
    while (1) {
        printf("输入一个数 (0 结束): ");
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        printf("%d 的立方是 %d\n", n, n * n * n);
    }
    return 0;
}
```

- `break` 只跳出==最内层==的一层 `while`/`do`/`for`/`switch`

- `switch` 里的 `break` 只结束 `switch` 本身; 要跳出外层 `while`, 需在外层另写 `break`

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
  n++;             /* 先计数: continue 不能跳过它 */
  if (i == 0) {
    continue;      /* 跳过除零 */
  }
  sum += 100 / i;
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
  n++;
  if (i != 0) {
    sum += 100 / i;
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

1. (概念) while 和 do-while 唯一的区别是什么？

2. (概念) break 和 continue 分别把控制转移到哪里？

3. (编码) 输入整数直到 `0` 为止, 输出其中==最大值==

<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---


