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

## 二维数组与矩阵运算

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 多维数组: 声明、访问与存储

- 多维数组初始化

- ==矩阵运算==: 转置、乘法、统计

- 案例: 发牌程序

---


<!-- slide data-notes="" -->


##### 多维数组: 声明与访问

---

数组可以有任意维数

下面的声明创建了一个二维数组(数学术语称为矩阵): 

`int m[5][9];`

数组m有5行9列, 行和列下标都从0开始索引: 

<div class="row1-5-column2-10-fullborder">

|     |   0    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |
| :-: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
|  0  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  1  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  2  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  3  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  4  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |

</div>


为了访问i行j列的元素, 需要写成`m[i][j]`的形式. 

表达式`m[i]`指定数组m第i行, 而`m[i][j]`选择该行中第j个元素. 

不要把`m[i][j]`写成`m[i,j]` 

这里, C将逗号视为 ==逗号运算符==, 因此`m[i,j]`等同于`m[j]`

---


<!-- slide data-notes="" -->


##### 多维数组的存储: 行主序

---

虽然我们以表格形式显示二维数组, 但这并不是它们在计算机内存中实际存储的方式. 
行主序存储数组, 从第 0 行开始, 接着第 1 行, 依此类推. 
数组m的存储方式: 

<div class="top-2">
    <img src="figs/8-4.png" width=400px>
</div>

<!-- <div class="row0-2-column2-11-fullborder">

|     |   >     |  >     |  row0   | >       | >      | row1    | ...    |   >     | >      | row4    |
| :-: | :----:  | :----: | :----:  | :----:  | :----: | :----:  | :----: | :----:  | :----: | :----:  |
|     | m[0][0] | ...    | m[0][8] | m[1][0] | ...    | m[1][8] | ...    | m[4][0] | ...    | m[4][8] |

</div> -->

---


<!-- slide data-notes="" -->


##### 二维数组与嵌套循环

---

嵌套for循环非常适合处理多维数组. 

单位矩阵的数组的初始化: ==嵌套的for循环==

```C{.line-numbers}
#define N 10

double ident[N][N];
int row, col;
 
for (row = 0; row < N; row++) {
  for (col = 0; col < N; col++) {
    if (row == col)
      ident[row][col] = 1.0;
    else
      ident[row][col] = 0.0;
  }
}
```

---

---


<!-- slide data-notes="" -->


##### 多维数组初始化

---

通过嵌套一维初始化式的方法可以产生二维数组的初始化式: 

```C
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1, 0},
                {0, 1, 0, 1, 1, 0, 0, 1, 0},
                {1, 1, 0, 1, 0, 0, 0, 1, 0},
                {1, 1, 0, 1, 0, 0, 1, 1, 1} };
```

高维数组的初始化式以类似的方式构造. 

C 提供了多种方法来缩写多维数组的初始化式


如果初始值化式不足以填充整个多维数组, 则剩余元素赋值为0. 

下面初始化式只填充了数组m的前三行; 后两行将赋值为0: 

```C
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1, 0},
                {0, 1, 0, 1, 1, 0, 0, 1, 0} };
```

---

---


<!-- slide data-notes="" -->


##### 多维数组初始化: 省略与指定

---

如果内层列表的长度不足以填满数组的一行, 则该行中的剩余元素将初始化为`0`: 

```C
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1},
                {0, 1, 0, 1, 1, 0, 0, 1},
                {1, 1, 0, 1, 0, 0, 0, 1},
                {1, 1, 0, 1, 0, 0, 1, 1, 1} };
```

---


内层的花括号可以 ==省略==: 

```C
int m[5][9] = {1, 1, 1, 1, 1, 0, 1, 1, 1,
               0, 1, 0, 1, 0, 1, 0, 1, 0,
               0, 1, 0, 1, 1, 0, 0, 1, 0,
               1, 1, 0, 1, 0, 0, 0, 1, 0,
               1, 1, 0, 1, 0, 0, 1, 1, 1};
```

一旦编译器发现数值足以填满一行, 它就会开始填充下一行. 

多维数组中省略内层大括号有风险, 额外的元素或缺失的元素会影响剩下的初始化式, 省略的花括号会引起编译警告


C99 的指定初始化式也适用于多维数组. 

创建2×2单位矩阵: 

```C
double ident[2][2] = {[0][0] = 1.0, [1][1] = 1.0};
```

像通常一样, 所有未指定值的元素都默认为0.

---


<!-- slide data-notes="" -->

##### 矩阵运算: 转置

---

转置: 行列互换, ==b[j][i] = a[i][j]==

```C
int a[3][4] = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}};
int b[4][3];

for (int i = 0; i < 3; i++)
  for (int j = 0; j < 4; j++)
    b[j][i] = a[i][j];   /* 行列互换 */
```

- 3×4 的矩阵 a 转置后是 4×3 的矩阵 b

- 注意 b 的行列数与 a ==正好相反==

---


<!-- slide data-notes="" -->

##### 矩阵运算: 乘法

---

矩阵乘法: $c_{ij} = \sum_k a_{ik} \times b_{kj}$ (a 的列数必须等于 b 的行数)

```C
/* a: m×n, b: n×p, c: m×p */
for (int i = 0; i < m; i++)
  for (int j = 0; j < p; j++) {
    c[i][j] = 0;
    for (int k = 0; k < n; k++)
      c[i][j] += a[i][k] * b[k][j];
  }
```

- ==三层循环==: 外层两重选行与列, 最内层求和

- 这是 AI 里"矩阵乘法"的最朴素版本 (第 15 周 AI 实践会看到它)

---


<!-- slide data-notes="" -->

##### 矩阵运算: 按行/按列统计

---

统计每行的和、每列的和 (成绩表场景):

```C
/* scores: 5 名学生 × 3 门课 */
int row_sum[5] = {0}, col_sum[3] = {0};

for (int i = 0; i < 5; i++)
  for (int j = 0; j < 3; j++) {
    row_sum[i] += scores[i][j];   /* 每行: 某学生的总分 */
    col_sum[j] += scores[i][j];   /* 每列: 某门课的总分 */
  }
```

- ==一次遍历同时算两个方向==: 行和进 row_sum[i], 列和进 col_sum[j]

---


<!-- slide data-notes="" -->


##### 常量数组

---

在声明数组的最开始处加上 ==const== 可以使数组成为 ==常量==: 

```C
const char hex_chars[] =
  {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
   'A', 'B', 'C', 'D', 'E', 'F'};
```

程序不应修改声明为const的数组.


将数组声明为const的优点: 

- 表明程序不会更改数组. 

- 帮助编译器捕获错误. 

- const不仅限于数组, 也可用于任何别的变量. 

- const常用于数组的声明, 以保护在程序执行过程中不变的信息.

---


<!-- slide data-notes="" -->


##### 程序: 发牌

---

*deal.c*程序说明了二维数组和常量数组的用法. 

该程序从一副标准的扑克牌中随机处理一手牌. 

标准套牌中的每张牌都有花色{梅花&clubs;(`c`), 方块&diams;(`d`), 红桃&hearts;(`h`), 黑桃&spades;(`s`)}和等级{$2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A$}.


用户将指定手中应该有多少张牌: 

输入手牌数量: <u>5</u>
你的牌: 7c 2s 5d as 2h

需要解决的问题: 

- 如何从牌组中随机挑选牌？

- 如何避免两次选择同一张牌？

---


<!-- slide data-notes="" -->


##### 程序: 发牌 (代码)

---

为了随机挑选卡片, 可以采用一些 C 库函数: 

- time函数(来自`<time.h>`): 返回当前时间, 用一个数表示. 

- srand函数(来自`<stdlib.h>`): 初始化 C 的随机数生成器. 

- rand函数(来自`<stdlib.h>`): 每次调用时都会产生一个看似随机的数. 

通过使用%运算符, 缩放rand函数返回值, 使其介于0和3之间(表示花色)或介于0和12之间(表示等级).


in_hand数组用于记录已经选择过的牌. 

数组有4行13列; 每个元素对应52 张牌中的一张. 

数组的所有元素一开始都为假. 

每随机选择一张牌时, 检查in_hand中该牌对应的元素为真或假. 

- 如果为真, 就需要选择另一张牌. 

- 如果为假, 就把ture存储到对应的元素中, 以便稍后提醒我们这张牌已经被选中.


一旦验证了一张卡片是`"新"`的, 就需要将它的等级和花色转换成字符, 然后显示出来. 

为了将等级和花色转换为字符形式, 程序设置两个字符数组: 一个用于等级, 一个用于花色

然后用等级和花色作为下标取数组元素. 

数组在程序执行期间不会改变, 因此被声明为`const`.


*deal.c*

```C{.line-numbers}
/* 随机发牌 */
 
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define NUM_SUITS 4
#define NUM_RANKS 13
 
int main(void)
{
  bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
  int num_cards, rank, suit;
  const char rank_code[] = {'2','3','4','5','6','7','8',
                            '9','t','j','q','k','a'};
  const char suit_code[] = {'c','d','h','s'};
  srand((unsigned) time(NULL));

  printf("Enter number of cards in hand: ");
  scanf("%d", &num_cards);
 
  printf("Your hand:");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;    /* picks a random suit */
    rank = rand() % NUM_RANKS;    /* picks a random rank */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = true;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");
 
  return 0;
}
```

---

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 声明一个 3 行 4 列的整型二维数组，怎么写？访问第 2 行第 3 列的元素怎么写？

2. `m[i,j]` 与 `m[i][j]` 有什么区别？

3. 二维数组在内存中是怎么存储的（行主序是什么意思）？

4. 矩阵乘法的三层循环里，最内层的循环在做什么？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


