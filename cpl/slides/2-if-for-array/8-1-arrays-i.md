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

## 一维数组

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 一维数组: 声明、下标、初始化

- 为什么需要数组

- 案例: 数列反向、检查重复数字

- 现场挑战: 最高分并列统计、进制转换、回文数

- sizeof 与变长数组

- AI 审计

---


<!-- slide data-notes="" -->


##### 标量变量与聚合变量

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

到目前为止的变量都是==标量==:

```C
int x = 5;    /* 一个变量存一个值 */
```

- 保存==单一==数据项

</div>

<div style="flex:1;">

C 还支持==聚合==:

```C
int a[10];    /* 一个名字存一组值 */
```

- 存储==一组一组==的数值

- 聚合类型有两种: ==数组==和结构体

</div>

</div>

---

本章主角: ==一维数组== (它在 C 语言中的作用比多维数组更大)

---

---


<!-- slide data-notes="" -->


##### 什么是一维数组

---

数组: 存多个==同类型==的值, 按位置取元素

一维数组的元素一个接一个排成一行:

<div class="fullborder">

| &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; | &emsp; |
| :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- | :---- |

</div>

---

- ==同类型==: 整个数组只有一种元素类型——声明时定死

- ==按位置==: 想取第几个就取第几个, 位置从 0 数起 (下一页讲下标)

---

<!-- slide data-notes="" -->


##### 数组的声明

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.75em;">

```C
int a[10];
│  │ │
│  │ └─ 长度: 10 个元素 (下标 0~9)
│  └──── 数组名: 这批数据共用的名字
└─────── 元素类型: 每个元素都是 int
```

```C
#define N 10
…
int a[N];
```

</div>

<div style="flex:1;">

声明一个数组, 需要定两件事: ==类型==和数量

---

元素可以是任何类型; 长度必须是(整数)==常量表达式==

可以用宏定义数组长度——改长度只改一处

</div>

</div>

---


<!-- slide data-notes="" -->##### 数组下标

---

访问某个元素: 数组名后加方括号, 里面放整数——叫作==取下标== (也叫索引)

长度为 n 的数组, 下标范围是 ==0 到 n-1==, 元素依次是 a[0], a[1], ..., a[n-1]:

<div class="row1-2-column1-10-fullborder">

| a[0] | $a[1]$ | $a[2]$ | $a[3]$ | $a[4]$ | $a[5]$ | $a[6]$ | $a[7]$ | $a[8]$ | $a[9]$ |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |

</div>

---

==重点==: 长度 n 的数组没有 a[n]——最后一个元素是 a[n-1]
<!-- slide data-notes="" -->##### 数组下标: 循环三件套

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C{.line-numbers}
for (i = 0; i < N; i++)
  a[i] = 0;             /* ① 清零 */

for (i = 0; i < N; i++)
  scanf("%d", &a[i]);   /* ② 读入 */

for (i = 0; i < N; i++)
  sum += a[i];          /* ③ 求和 */
```

</div>

<div style="flex:1;">

`a[i]` 是左值, 可以==像普通变量一样用==: 赋值、打印、自增都行

- 对数组的常见操作, 几乎都是"循环 + 下标"的这三个模式:

  - ① 清零 / 赋初值、② 逐个读入、③ 累加 / 统计

---

下标范围再强调一次: `for (i = 1; i <= 10; i++) a[i] = 0;` ==越界==——正确写法是从 0 到 N-1

</div>

</div>
<!-- slide data-notes="" -->##### 数组下标

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
a[i + j * 10] = 0;
```

</div>

<div style="flex:1;">

数组下标可以是任何整数表达式:

`i + j * 10` 先算出来, 再用结果当下标——下标不必是简单变量

</div>

</div>

---

<!-- slide data-notes="" -->##### 数组下标: 有副作用的下标

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
i = 0;
while (i < N)
  a[i++] = 0;      /* 下标顺带改了 i */
```

```C
i = 0;
while (i < N)
  a[i] = b[i++];   /*** 危险! ***/
```

```C
for (i = 0; i < N; i++)
  a[i] = b[i];     /* 安全写法 */
```

</div>

<div style="flex:1;">

下标表达式甚至可能会产生副作用:

`a[i] = b[i++]` 访问并修改 `i` 的值, 导致==未定义的行为==

把自增从下标中移走, 问题就消失了:

</div>

</div>
<!-- slide data-notes="" -->


##### 演示: 越界写会"伤及无辜"

---

<div style="font-size:0.8em;">

```C
int a[4] = {10, 20, 30, 40};
int secret = 99;
a[4] = 100;                  /* 合法下标只有 0~3! */
printf("secret = %d\n", secret);
```

</div>

运行结果 (常见, 但不保证): 

```
secret = 100
```

- 下标范围是 ==0 ~ n-1==; `a[4]` 越界写入, C 语言==不检查、不报错==

- 结果不可预知: 可能改坏相邻变量、可能崩溃、也可能碰巧没事——==不报错的错才是最危险的 bug==

- 教训: 循环写数组时==检查边界== (`i < n`), 不要依赖编译器或运气

---

<!-- slide data-notes="" -->


##### 为什么需要数组

---

我们已经会用数组了——回头想想: 它到底解决了什么问题?

---

- 第 1 周的"找最高分": 读一个、比一个、丢一个——==一个变量就够==, 因为不需要回头

- 有了数组, 问题就敢这样提了:

  - 把 10 个成绩==逆序==打印——读完了还要"回头"

  - 统计最高分有几人==并列==——同一批数据要看两遍

  - 给全班成绩==排序==——数据之间要反复比较

---

结论: 需要"回头"再看的数据, 必须先==存下来==——这就是数组要解决的问题

---

<!-- slide data-notes="" -->


##### 为什么需要数组 (不用数组会怎样)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
/* 不用数组: 变量不够用了 */
int n1, n2, n3, n4, n5;
int n6, n7, n8, n9, n10;

scanf("%d", &n1);    /* 第 1 个 */
scanf("%d", &n2);    /* 第 2 个 */
/* … 第 100 个怎么办? 第 i 个呢? */
```

```C
/* 用数组: 下标管理一批数据 */
int n[10];
int i;

for (i = 0; i < 10; i++)
  scanf("%d", &n[i]);
printf("%d", n[i]);  /* 想要第几个都行 */
```

</div>

<div style="flex:1;">

- 10 个变量写 10 行, 1000 个写 1000 行——而且==没法用循环==

- 数组给一批同类型数据==编号==: 用下标就能批量处理

- 这就是数组的第一个重要性: 让"一批数据"变成一个整体

</div>

</div>

---

<!-- slide data-notes="" -->##### 程序: 数列反向

---

==现场演示==: 输入 10 个数, 逆序输出

样例:

```
输入 10 个数: 34 82 49 102 7 94 23 11 50 31
逆序输出: 31 50 11 23 94 7 102 49 82 34
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 存储的顺序和打印的顺序是什么关系?

---



<!-- slide data-notes="" -->


##### 程序: 数列反向 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 数列反向 */
#include <stdio.h>

#define N 10

int main(void)
{
  int a[N], i;

  printf("输入 %d 个数: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  printf("逆序输出:");
  for (i = N - 1; i >= 0; i--)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}
```

</div>

<div style="flex:1;">

- 正着读 (`i` 从 0 到 N-1), 倒着打 (`i` 从 N-1 到 0)——==同一数组, 两种遍历方向==

- 数据先全部存下来, 才能"回头"——数组的价值就在这

</div>

</div>

---

---

<!-- slide data-notes="" -->##### 数组初始化

---

- 初始化式比数组短 → 其余元素==自动赋 0==: `int a[10] = {1, 2, 3};` (利用此特性可全 0 初始化: `int a[10] = {0};`; 初始化式完全为空非法, 比数组长也非法)

- 给定了初始化式可省略数组长度: `int a[] = {1, 2, 3};`——编译器从初始化式推出大小

- 只有相对较少的元素需要显式初始化时, 其他默认赋值: `int a[15] = {0, 0, 29, 0, 0, 0, 0, 0, 0, 7};`——对大数组这样写冗长易错<!-- slide data-notes="" -->##### 指定初始化式 (C99)

---

- C99 的==指定初始化式==解决冗长问题: `int a[15] = {[2] = 29, [9] = 7};`——括号中的数字称为==指示符==

- 赋值更短更易读, 且==顺序无关==: `int a[15] = {[9] = 7, [2] = 29};`

- 指示符须为整型常量表达式, 取值 0 ~ n-1; 省略长度时可为任意非负整数, 编译器从==最大指示符==推出长度: `int b[] = {[23] = 5};` → 24 个元素<!-- slide data-notes="" -->##### 程序: 检查重复数字

---

==现场演示==: 输入一个整数, 判断它的各位数字里有没有==重复==的 (如 28245 有重复的 2)

样例:

```
输入一个数: 28245
有重复数字
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 用==布尔数组== `digit_seen[10]` 记录 0~9 哪些出现过——第 3 周数字拆分 + 本周数组的组合

---



<!-- slide data-notes="" -->


##### 程序: 检查重复数字 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.4;font-size:0.55em;">

```C{.line-numbers}
/* 检查数字中是否有重复的数字 */
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
  bool digit_seen[10] = {false};
  int digit;
  long n;

  printf("输入一个数: ");
  scanf("%ld", &n);
  while (n > 0) {
    digit = n % 10;
    if (digit_seen[digit])
      break;
    digit_seen[digit] = true;
    n /= 10;
  }
  if (n > 0)
    printf("有重复数字\n");
  else
    printf("没有重复数字\n");
  return 0;
}
```

</div>

<div style="flex:1;">

- `digit_seen` 是==布尔数组==: 下标是数字 (0~9), 值是"出现过没有"

- 拆一位 → 查表 → 标记录 → 拆下一位; 查到已出现就 break

- 数组当"记账本"用——这是标志数组的经典模式

</div>

</div>

---

<!-- slide data-notes="" -->##### 现场挑战: 最高分并列统计

---

==现场演示==: 输入 10 个成绩, 输出==最高分==和==并列人数==

第 1 周我们"流式"找过最高分——一个变量就够了; 现在要数并列人数, 还能不存吗?

样例:

```
输入 10 个成绩: 5 8 3 8 2 9 1 9 9 4
最高分 9, 共 3 人并列
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 数组允许你"回头再看一遍"数据

---



<!-- slide data-notes="" -->


##### 现场挑战: 最高分并列统计 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 最高分与并列人数 */
#include <stdio.h>
#define N 10

int main(void)
{
  int score[N], i, max, count;

  printf("输入 %d 个成绩: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &score[i]);

  max = score[0];              /* 第一遍: 找最高分 */
  for (i = 1; i < N; i++)
    if (score[i] > max)
      max = score[i];

  count = 0;                   /* 第二遍: 数并列 */
  for (i = 0; i < N; i++)
    if (score[i] == max)
      count++;

  printf("最高分 %d, 共 %d 人并列\n", max, count);
  return 0;
}
```

</div>

<div style="flex:1;">

- ==两遍扫描==: 第一遍找 max, 第二遍数个数——不存数据就数不了第二遍

- 这就是"找最高分"的完全体: 第 1 周的流式写法到这里就到头了

- OJ 本周同款: 「最大值出现次数」——课上见、OJ 练

</div>

</div>

---

<!-- slide data-notes="" -->##### 现场挑战: 进制转换

---

==现场演示==: 输入十进制数 n 和进制 base (2~10), 输出转换结果

样例:

```
输入十进制数和进制: 13 2
1101
```

```
输入十进制数和进制: 100 8
144
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 注意输出顺序——先算出来的数字要后输出

---



<!-- slide data-notes="" -->


##### 现场挑战: 进制转换 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 进制转换: 反复取余存数组, 逆序输出 */
#include <stdio.h>

int main(void)
{
  int n, base, digits[32];
  int len = 0, i;

  printf("输入十进制数和进制: ");
  scanf("%d%d", &n, &base);

  do {
    digits[len++] = n % base;  /* 余数存进数组 */
    n /= base;
  } while (n > 0);

  for (i = len - 1; i >= 0; i--)  /* 逆序输出 */
    printf("%d", digits[i]);
  printf("\n");
  return 0;
}
```

</div>

<div style="flex:1;">

- 短除法的每一步余数==先后顺序是反的==——存进数组再逆序输出, 正好接上 reverse 的写法

- `len` 既是"下一个空位"又是"已存个数"——数组配合计数变量的经典搭档

- `do-while` 保证 n=0 也能输出一个 0; 16 进制要输出字母, 留作加餐

</div>

</div>

---

<!-- slide data-notes="" -->##### 现场挑战: 回文数

---

==现场演示==: 输入一个整数, 判断它是不是==回文数== (正着读倒着读一样, 如 1221、12321)

样例:

```
输入一个整数: 1221
1221 是回文数
```

```
输入一个整数: 1234
1234 不是回文数
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 先想清楚"第 i 位"和"倒数第 i 位"在数组里的下标关系

---



<!-- slide data-notes="" -->


##### 现场挑战: 回文数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 回文数: 数字拆进数组, 首尾对称比较 */
#include <stdio.h>

int main(void)
{
  long n, m;
  int digits[20], len = 0, i;

  printf("输入一个整数: ");
  scanf("%ld", &n);

  m = n;                       /* 拆数字, 个位在前 */
  do {
    digits[len++] = m % 10;
    m /= 10;
  } while (m > 0);

  for (i = 0; i < len / 2; i++)      /* 只比到一半 */
    if (digits[i] != digits[len - 1 - i]) {
      printf("%ld 不是回文数\n", n);
      return 0;
    }
  printf("%ld 是回文数\n", n);
  return 0;
}
```

</div>

<div style="flex:1;">

- 首尾对称: 第 i 位 vs 第 ==len-1-i== 位——下标关系的推演是这题的灵魂

- 发现不对称可以==提前 return==, 不用比完

- 只比到 `len/2`, 奇数长度中间那位不用比

</div>

</div>

---

<!-- slide data-notes="" -->##### 对数组使用sizeof运算符

---

- 用 `sizeof` 表达数组长度: `for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)` 清零——日后改长度无需改循环

- 可能告警: `i` 是 int (有符号), `sizeof` 返回 size_t (无符号); 此处安全, 也可强转避免: `(int) (sizeof(a) / sizeof(a[0]))`

- 为数组大小定义宏: `#define SIZE ((int) (sizeof(a) / sizeof(a[0])))`——宏要加括号, 防止运算顺序不一致<!-- slide data-notes="" -->


##### 变长数组 (C99)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
int n, i;

printf("输入几个数? ");
scanf("%d", &n);

int a[n];        /* C99: 长度运行时才定 */

for (i = 0; i < n; i++)
  scanf("%d", &a[i]);
```

```C
int a[3 * i + 5];   /* 长度可以是任意表达式 */
```

</div>

<div style="flex:1;">

数组 a 的长度由变量 n 决定, 是==变长数组==:

- 长度在==程序执行时==才计算——需要多少就开多少, 不多占、不漏放

- 长度不一定是变量, 任意(整数)表达式都可以:

---

==工程上少用==: C11 把 VLA 降为可选特性 (MSVC 一直不支持), 长度在栈上运行时分配、不可控——课堂了解即可, 实践优先用固定长度数组

</div>

</div>

<!-- slide data-notes="" -->

##### 程序: 计算利息 (数组保存中间状态)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
#define NUM_RATES 5
#define NUM_YEARS 5

double balance[NUM_RATES];
for (int r = 0; r < NUM_RATES; r++) {
  balance[r] = 100.0;
  for (int y = 1; y <= NUM_YEARS; y++) {
    balance[r] = balance[r] * (1 + 0.01 * (r + 3));   /* 每年复利 */
    printf("%8.2f", balance[r]);
  }
  printf("\n");
}
```

</div>

<div style="flex:1;">

本金 100 元, 5 种利率各存 5 年, 列出每年的余额:

关键: ==第 y+1 年的余额依赖第 y 年==——每一年的中间值都要==存下来==

- 数组的第三种用途: 除了"存一批数据"和"批量处理", 还能==保存中间状态==

</div>

</div>

<!-- slide data-notes="" -->##### AI 审计: 有 bug 吗?

---

==课堂互动==: 下面三段代码都是 AI 写的——每组先投票: ==有 bug / 没 bug==

```C
/* ① 把数组 a 全部清零 */
for (i = 1; i <= N; i++)
  a[i] = 0;
```

```C
/* ② 求数组 a 的最大值 */
int max = 0;
for (i = 0; i < N; i++)
  if (a[i] > max)
    max = a[i];
```

```C
/* ③ 把数组全部初始化为 1 */
int a[5] = {1};
```

<span class="blue">:fa-lightbulb-o:</span> 三个 bug 都是本讲刚讲过的知识点

---



<!-- slide data-notes="" -->


##### AI 审计: 揭晓

---

① ==有 bug==: 下标越界 (`a[N]` 不存在) 且漏了 `a[0]`——正确写法 `for (i = 0; i < N; i++)`

---

② ==有 bug==: `max = 0` 初始化的老坑——成绩全是负数时, 最大值"恒为 0"; 正确写法 `max = a[0]`, 从下标 1 开始比

---

③ ==有 bug==: `{1}` 只把 `a[0]` 初始化成 1, 其余自动补 0, 不是全 1——想全 1 得写循环

---

==带走清单==: 下标 0~n-1 吗? 最值用 `a[0]` 起步吗? 初始化式比数组短会怎样? ——写数组循环前先问自己这三句

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. `int a[10];` 中数组元素的下标范围是什么？越界会发生什么？

2. `int a[] = {1, 2, 3};` 中 a 的长度是多少？怎么用 sizeof 计算元素个数？

3. 写代码: 找出数组 {5, 2, 9, 1} 中的最小值。

4. C99 的变长数组 (VLA) 长度可以是什么？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


