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

<div style="font-size:1.3em;text-align:left;margin-left:2rem;">

- 多维数组: 声明、访问与存储

- 多维数组初始化

- ==矩阵运算==: 转置、乘法、统计

- 案例: 幻方、生命游戏


</div>

---


<!-- slide data-notes="" -->


##### 多维数组: 声明

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

表格类数据天然是"行×列": 成绩表、棋盘、矩阵……==二维数组==就是一张表

```C
int m[5][9];
```

- `int`——==元素类型==: 每个格子都是 int

- `m`——==数组名==: 这张表的名字

- `[5][9]`——==5 行 9 列==

</div>

<div style="flex:1.3;">

行、列下标都从 0 开始:

<div class="row1-5-column2-10-fullborder">

|     |   0    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
|  0  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  1  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  2  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  3  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |
|  4  | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |

</div>

</div>

</div>

---

怎么访问每一个格子? 下一页

---

<!-- slide data-notes="" -->


##### 多维数组: 访问

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.65em;">

```C
m[2][3] = 42;          /* 第 2 行第 3 列 = 42 */
printf("%d", m[2][3]); /* 像普通变量一样用 */

/* ---- 配合循环, 扫过一整行 ---- */
for (j = 0; j < 9; j++)
  printf("%d ", m[2][j]);
```

</div>

<div style="flex:1;">

访问 i 行 j 列的元素, 写成 `m[i][j]`:

- `m[i]` 是第 i 行, `m[i][j]` 是这一行里的第 j 个元素

- 行下标 0~4, 列下标 0~8——都从 0 数起

- 配合循环就能扫过一整行——稍后的嵌套循环页正式登场

</div>

</div>

---

下一行代码看起来和它几乎一样——却是==最容易写错==的写法

---

<!-- slide data-notes="" -->


##### 陷阱: m[i,j] 不是 m[i][j]

---

```C
m[i][j]    /* 第 i 行第 j 列 */
m[i,j]     /*** WRONG: 不是二维访问! ***/
```

`m[i,j]` 里的逗号是==逗号运算符==: 先算 i、再算 j, 整个表达式等于 `m[j]`——只取了第 j 行, 根本不是二维访问

- C 编译不报错——又是"能编译但答非所问"的坑

- 键盘上多打一个逗号, 程序就悄悄错了

---


<!-- slide data-notes="" -->


##### 多维数组的存储: 行主序

---

==表格只是模型==: 内存里没有"行"——二维数组是==按行连续存放==的: 第 0 行存完, 紧跟着第 1 行, 依此类推

<div class="fullborder">

| m[0][0] | m[0][1] | … | m[0][8] | m[1][0] | … | m[1][8] | … | m[4][0] | … | m[4][8] |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; | &zwnj; |

</div>

---

这就是==行主序== (row-major): 有了它, 就知道 `a[i][j]` 在内存中的位置——后面的矩阵运算、指针都建立在这上面

---


<!-- slide data-notes="" -->


##### 二维数组与嵌套循环

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

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

</div>

<div style="flex:1;">

嵌套 for 循环非常适合处理多维数组——==外层行, 内层列==

单位矩阵: `row == col` 放 1, 其余放 0

想只处理对角线以上? 改 `if` 的条件就行



</div>

</div>

<!-- slide data-notes="" -->


##### 多维数组初始化

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1, 0},
                {0, 1, 0, 1, 1, 0, 0, 1, 0},
                {1, 1, 0, 1, 0, 0, 0, 1, 0},
                {1, 1, 0, 1, 0, 0, 1, 1, 1} };
```

```C
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1, 0},
                {0, 1, 0, 1, 1, 0, 0, 1, 0} };
```

</div>

<div style="flex:1;">

把一维初始化式==嵌套==起来, 就得到二维数组的初始化式

高维数组以此类推

---

初始化式不足以填满时, 其余元素==自动补 0==:

下面的初始化式只填了前三行——后两行自动为 0



</div>

</div>

<!-- slide data-notes="" -->


##### 多维数组初始化: 省略与指定

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C
/* ① 内层不够填满一行: 该行剩下自动补 0 */
int m[5][9] = { {1, 1, 1, 1, 1, 0, 1, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1},
                {0, 1, 0, 1, 1, 0, 0, 1},
                {1, 1, 0, 1, 0, 0, 0, 1},
                {1, 1, 0, 1, 0, 0, 1, 1, 1} };

/* ② 内层花括号可以省略: 填满一行自动换行 */
int m[5][9] = {1, 1, 1, 1, 1, 0, 1, 1, 1,
               0, 1, 0, 1, 0, 1, 0, 1, 0,
               0, 1, 0, 1, 1, 0, 0, 1, 0,
               1, 1, 0, 1, 0, 0, 0, 1, 0,
               1, 1, 0, 1, 0, 0, 1, 1, 1};

/* ③ C99 指定初始化式同样适用 */
double ident[2][2] = {[0][0] = 1.0, [1][1] = 1.0};
```

</div>

<div style="flex:1;">

- ① 内层不够填满一行时, 该行剩下的元素自动为 `0`

- ② 内层花括号可以==省略==——填满一行, 自动开始下一行

- ② 省略有==风险==: 多一个或少一个元素, 后面的全乱, 编译器会告警

- ③ C99 指定初始化式也适用: 创建 2×2 单位矩阵, 未指定的默认为 0

</div>

</div>

<!-- slide data-notes="" -->

##### 矩阵运算: 转置

---

转置: 行列互换, ==b[j][i] = a[i][j]==

```C
int a[3][4] = { {1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12} };
int b[4][3];

for (int i = 0; i < 3; i++) {
  for (int j = 0; j < 4; j++) {
    b[j][i] = a[i][j];   /* 行列互换 */
  }
}
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
for (int i = 0; i < m; i++) {
  for (int j = 0; j < p; j++) {
    c[i][j] = 0;
    for (int k = 0; k < n; k++) {
      c[i][j] += a[i][k] * b[k][j];
    }
  }
}
```

- ==三层循环==: 外层两重选行与列, 最内层求和

- 神经网络的核心运算就是矩阵乘法 (GEMM): 全连接、卷积、注意力最后都归到它——三层循环是朴素版, 真实库还会做分块、向量化优化

---


<!-- slide data-notes="" -->

##### 矩阵运算: 按行/按列统计

---

统计每行的和、每列的和 (成绩表场景):

```C
/* scores: 5 名学生 × 3 门课 */
int row_sum[5] = {0}, col_sum[3] = {0};

for (int i = 0; i < 5; i++) {
  for (int j = 0; j < 3; j++) {
    row_sum[i] += scores[i][j];   /* 每行: 某学生的总分 */
    col_sum[j] += scores[i][j];   /* 每列: 某门课的总分 */
  }
}
```

- ==一次遍历同时算两个方向==: 行和进 row_sum[i], 列和进 col_sum[j]

---


<!-- slide data-notes="" -->


##### 案例: 幻方

---

==幻方==: n×n 的格子填 1 ~ n², 每行、每列、两条对角线的和都相等 (n 取==奇数==)

奇数阶幻方的经典构造法 (de la Loubère):

- 1 放在第一行正中间

- 下一个数往==右上==走一格; 走出棋盘就==回绕==

- 右上已被占用, 就改往==正下==走一格

样例 (n=3):

```
 8  1  6
 3  5  7
 4  9  2
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 先想清楚"右上"对应两个下标怎么变, "回绕"用什么运算

---

<!-- slide data-notes="" -->


##### 案例: 幻方 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.62em;">

```C{.line-numbers}
/* 奇数阶幻方: 右上走 + 回绕 + 冲突下移 */
#include <stdio.h>
#define N 3

int main(void)
{
  int magic[N][N] = {0};
  int i, j, num;

  i = 0; j = N / 2;              /* 1 放在第一行正中间 */
  for (num = 1; num <= N * N; num++) {
    magic[i][j] = num;
    int ni = (i - 1 + N) % N;    /* 右上候选 (回绕) */
    int nj = (j + 1) % N;
    if (magic[ni][nj] != 0) {    /* 被占: 改往正下 */
      i = (i + 1) % N;
    } else {
      i = ni; j = nj;
    }
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%3d", magic[i][j]);
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- "右上"是两个下标的==同时变化==: 行 -1、列 +1——二维数组的下标游戏

- 走出棋盘用 `% N` ==回绕==——前面学过的取余又一次实战

- 格子非 0 就是已被占用: 用数组内容==做标记==, 不用额外的 visited 数组

- 把 N 改成 5, 就是 5×5 幻方——每行和都是 65

- 此法只对==奇数== N 成立: 偶数阶另有构造法 (2×2 干脆不存在幻方)

</div>

</div>

<!-- slide data-notes="" -->

##### 案例: 生命游戏

---

细胞自动机: 网格里每个格子是"活(1)"或"死(0)", 每一代按==邻居==数更新:

- 活细胞: 2 或 3 个活邻居 → 继续活; 否则死 (孤独或拥挤)

- 死细胞: 恰好 3 个活邻居 → 复活

样例: 竖着的"三连"过一代, 变横着的"三连":

```
.....        .....
..#..        .....
..#..  -->   .###.
..#..        .....
.....        .....
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 更新第 (i,j) 格时, 邻居们必须还是==旧一代==的

---

<!-- slide data-notes="" -->


##### 生命游戏: 动画演示

---

<video controls width="1100">
  <source src="../4-loops/videos/Conway-Game-of-Life.mp4" type="video/mp4">
  [下载视频](../4-loops/videos/Conway-Game-of-Life.mp4) 观看。
</video>

---

[Conway's Game of Life @ wiki](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

---

<!-- slide data-notes="" -->


##### 案例: 生命游戏 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;font-size:0.55em;">

```C{.line-numbers}
/* 生命游戏: 一代更新 */
#include <stdio.h>
#define N 5

int main(void)
{
  int old_grid[N][N] = {0,0,0,0,0, 0,0,1,0,0, 0,0,1,0,0,
                        0,0,1,0,0, 0,0,0,0,0};
  int new_grid[N][N];
  const char cell[] = {'.', '#'};   /* 对照表: 0->. 1-># */
  int i, j, di, dj, count;

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      count = 0;
      for (di = -1; di <= 1; di++) {
        for (dj = -1; dj <= 1; dj++) {
          int ni = i + di, nj = j + dj;
          if (ni >= 0 && ni < N && nj >= 0 && nj < N && !(di == 0 && dj == 0))
            if (old_grid[ni][nj])
              count++;
        }
      }
      if (old_grid[i][j])
        new_grid[i][j] = (count == 2 || count == 3);
      else
        new_grid[i][j] = (count == 3);
    }
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%c ", cell[new_grid[i][j]]);
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- ==两张表==是关键: 从 `old` 数邻居、写进 `new`——边数边改会把旧一代污染掉

- 邻居计数: 外面两重定位格子, 里面两重扫 3×3 邻域 (去掉自己)

- 边界: 棋盘外的格子当死细胞——`ni >= 0 && ni < N` 挡住

- 想跑多代: 把 `new` 拷回 `old` 再来一轮——这就是==整张表更新==

- `cell` 是 const==对照表==: 0/1 变图案——上一课学的常量数组派上用场

</div>

</div>

---

<!-- slide data-notes="" -->


##### 杨辉三角

---

==现场演示==: 打印杨辉三角的前 6 行

样例:

```
   1
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 第 i 行第 j 个数, 是"上一行"的哪两个数之和?

---

<!-- slide data-notes="" -->


##### 杨辉三角 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>
#define N 6
int main(void)
{
  int a[N][N] = {0};
  int i, j;

  for (i = 0; i < N; i++) {
    a[i][0] = 1;                  /* 每行开头是 1 */
    for (j = 1; j <= i; j++)
      a[i][j] = a[i-1][j-1] + a[i-1][j];
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++)
      printf("%4d", a[i][j]);
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 关系式 `a[i][j] = a[i-1][j-1] + a[i-1][j]` 是二维下标的==经典推演==

- 只用到下三角——上半部分自动是 0, 打印时只打 `j <= i`

- `{0}` 全零初始化: 第 1 行和每行开头, 都靠它兜底

</div>

</div>

---

<!-- slide data-notes="" -->


##### 蛇形填数

---

==现场演示==: n×n 的格子, 从 1 开始==螺旋==往里填

样例 (n=5):

```
 1  2  3  4  5
16 17 18 19  6
15 24 25 20  7
14 23 22 21  8
13 12 11 10  9
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 右、下、左、上四个方向轮流走; 每走完一边, 边界往里收一格

---

<!-- slide data-notes="" -->


##### 蛇形填数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
#define N 5
int main(void)
{
  int a[N][N] = {0};
  int num = 1, top = 0, bottom = N - 1;
  int left = 0, right = N - 1;
  int i, j;

  while (top <= bottom && left <= right) {
    for (i = left; i <= right; i++) a[top][i] = num++;   /* → */
    top++;
    for (i = top; i <= bottom; i++) a[i][right] = num++; /* ↓ */
    right--;
    for (i = right; i >= left; i--) a[bottom][i] = num++;/* ← */
    bottom--;
    for (i = bottom; i >= top; i--) a[i][left] = num++;  /* ↑ */
    left++;
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%3d", a[i][j]);
    printf("\n");
  }
  return 0;
}
```

</div>

<div style="flex:1;">

- 四个==边界变量== (top/bottom/left/right) 每轮收缩——二维数组的"橡皮筋"

- 四个方向的循环依次执行, 下标变化各不相同——走位练习的集大成

- `num++` 顺手当计数器: 填一格、涨一个

</div>

</div>

---

<!-- slide data-notes="" -->


##### 数独校验

---

==现场演示==: 读入 9×9 数独, 判断是否违反规则 (OJ 1081 同款)

输入: 9 行, 每行 9 个整数 (1~9)

规则: 每行、每列、每个 3×3 九宫格, 都恰好是 1~9 各一次

样例输出:

```
Right   (合法)
Wrong   (有重复)
```

<span class="blue">:fa-lightbulb-o:</span> 方向提示: 三次扫描, 每次都是标志数组查重——和 repdigit 同款

---

<!-- slide data-notes="" -->


<!-- slide data-notes="" -->


##### 数独校验 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.5em;">

```C{.line-numbers}
#include <stdio.h>
#define N 9
int main(void)
{
  int board[N][N], i, j, k, ok = 1;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      scanf("%d", &board[i][j]);

  for (i = 0; i < N && ok; i++) {          /* 每行查重 */
    int seen[10] = {0};
    for (j = 0; j < N; j++) {
      if (seen[board[i][j]]) { ok = 0; break; }
      seen[board[i][j]] = 1;
    }
  }
  for (j = 0; j < N && ok; j++) {          /* 每列查重 */
    int seen[10] = {0};
    for (i = 0; i < N; i++) {
      if (seen[board[i][j]]) { ok = 0; break; }
      seen[board[i][j]] = 1;
    }
  }
  for (i = 0; i < N && ok; i += 3)         /* 九宫格查重 */
    for (j = 0; j < N && ok; j += 3) {
      int seen[10] = {0};
      for (k = 0; k < 9; k++) {
        int v = board[i + k / 3][j + k % 3];
        if (seen[v]) { ok = 0; break; }
        seen[v] = 1;
      }
    }
  printf(ok ? "Right\n" : "Wrong\n");
  return 0;
}
```

</div>

<div style="flex:1;">

- 三种扫描 (行/列/九宫格) 是同一招==标志数组查重==的三次使用

- 九宫格的坐标 `i + k/3`、`j + k%3` 是==二维下标推演==的高光时刻

- 出错就 `ok = 0` 提前退出——早停的思想

</div>

</div>

---

<!-- slide data-notes="" -->


##### 课堂小测 (1/2)

---

1. 声明一个 3 行 4 列的整型二维数组，怎么写？访问第 2 行第 3 列的元素怎么写？

2. `m[i,j]` 与 `m[i][j]` 有什么区别？

---

<!-- slide data-notes="" -->


##### 课堂小测 (2/2)

---

3. 二维数组在内存中是怎么存储的（行主序是什么意思）？

4. 矩阵乘法的三层循环里，最内层的循环在做什么？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

# 下周见!

<hr class="width50 center">

## 未完待续

---


