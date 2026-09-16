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

## 人工智能实践: KNN 分类

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 机器学习是什么: 用数据"学"出规律

- KNN 的思想: 近朱者赤

- 用 C 实现: 读数据 → 算距离 → 投票

- 现场演示: 鸢尾花分类

---


<!-- slide data-notes="" -->


##### 机器学习是什么

---

==机器学习==: 不直接写规则, 而是给程序一堆==数据==, 让它自己"总结"规律

<div class="fullborder">

| 类型 | 做什么 | 例子 |
| :-- | :-- | :-- |
| 监督学习 | 有答案的学习 | 分类 (垃圾邮件)、回归 (房价预测) |
| 无监督学习 | 没有答案, 找结构 | 聚类 (用户分群) |

</div>

- ==分类==: 输出是"哪一类" (如 鸢尾花的品种)
- ==回归==: 输出是"一个数" (如 房价)

<span class="blue">:fa-lightbulb-o:</span> 第 1 周说过: AI 的底层是 C——今天就用手写 C 代码实现一个真正的机器学习算法

---


<!-- slide data-notes="" -->


##### KNN 的思想: 近朱者赤

---

==KNN== (K-Nearest Neighbors, K 近邻): 新样本的类别 = 它==最近的 k 个邻居==里最多的那一类

- 训练阶段: 什么都不做, 只是==记住所有数据==

- 预测阶段: 算新样本到每个已知样本的==距离==, 取最近的 k 个, ==投票==定类别

- 距离: 欧氏距离 $d = \sqrt{\sum (x_i - y_i)^2}$ (就是勾股定理的推广)

- k 的作用: k=1 太敏感; k 太大又会"听邻居太远的意见"——一般取奇数 (3、5)

---


<!-- slide data-notes="" -->


##### 数据: 鸢尾花 (iris)

---

经典的分类数据集: 每个样本是一朵花, 4 个特征 + 1 个品种

```text
5.1,3.5,1.4,0.2,0     ← 花萼长、花萼宽、花瓣长、花瓣宽, 品种
4.9,3.0,1.4,0.2,0
7.0,3.2,4.7,1.4,1
6.3,3.3,6.0,2.5,2
...
```

- 品种 0/1/2 = setosa / versicolor / virginica

- 数据存在 ==iris.csv== 文本文件里——正好用上第 14 周的文件操作!

- 用 C 读数据: `fgets` 读一行 → `sscanf` 拆分字段 (第 14 周学过的组合)

---


<!-- slide data-notes="" -->


##### 用 C 实现 KNN: 总体思路

---

四个"积木", 全是学过的知识:

1. ==读数据== (第 14 周): `fgets` + `sscanf` 把每行拆成 4 个特征 + 1 个标签

2. ==算距离== (第 3 周数学库): 循环求差的平方和, 再开方 `sqrt`

3. ==找最近的 k 个== (第 5 周循环 + 第 8 周数组): 求每个训练样本的距离, 找最小的 k 个

4. ==投票== (第 4 周判断 + 第 8 周数组): 统计 k 个邻居里哪个类别最多

<span class="blue">:fa-lightbulb-o:</span> 没有新语法——难点只在"把已经会的东西组合起来"

---


<!-- slide data-notes="" -->


##### 读数据: fgets + sscanf

---

```C{.line-numbers}
#define MAX_SAMPLES 150
#define MAX_LINE 100

double features[MAX_SAMPLES][4];   /* 每行的 4 个特征 */
int labels[MAX_SAMPLES];           /* 每行的标签 */
int n_samples = 0;

FILE *fp = fopen("iris.csv", "r");
char line[MAX_LINE];
while (fgets(line, sizeof(line), fp) && n_samples < MAX_SAMPLES) {
  sscanf(line, "%lf,%lf,%lf,%lf,%d",
         &features[n_samples][0], &features[n_samples][1],
         &features[n_samples][2], &features[n_samples][3],
         &labels[n_samples]);
  n_samples++;
}
fclose(fp);
```

- `features[i]` 是一个 ==4 个 double== 的小数组——正好给第 13 周的距离函数用

---


<!-- slide data-notes="" -->


##### 算距离与 KNN 预测

---

```C{.line-numbers}
#include <math.h>

double distance(double a[4], double b[4])   /* 第 9 周: 数组作参数 */
{
  double sum = 0;
  for (int i = 0; i < 4; i++)
    sum += (a[i] - b[i]) * (a[i] - b[i]);
  return sqrt(sum);                          /* 第 3 周: math.h */
}

int knn_predict(double x[4], int k)
{
  int votes[3] = {0};                        /* 三类别的票数 */
  /* 简化版: 统计距离最小的 k 个邻居的类别 */
  /* 先算所有距离, 再找 k 个最小 (第 8 周: 选择排序的思路) */
  ...
  /* 找出票数最多的类别 */
  int best = 0;
  for (int c = 1; c < 3; c++)
    if (votes[c] > votes[best]) best = c;
  return best;
}
```

- 完整代码见课件目录 `code/knn.c`——现场演示运行

---


<!-- slide data-notes="" -->


##### 现场演示与讨论

---

==现场演示==

1. 编译运行 `knn.c`, 用 iris 数据做分类

2. 观察 ==k 取不同值== (k=1 / 3 / 5) 时预测结果的变化

3. 讨论: 把一部分数据==留出来当测试集==, 数一数预测对了多少——这就是"准确率"

<span class="blue">:fa-lightbulb-o:</span> 回顾第 1 周: AI 框架 (PyTorch/TensorFlow) 里的"KNN 分类器", 底层就是这样一段 C 代码——今天你亲手写了它的简化版

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. KNN 在"训练阶段"做了什么？为什么说它是"懒惰"的算法？

2. 预测一个新样本时，KNN 有哪三步？

3. 为什么计算距离要用 `sqrt`？不用开方会影响"找最近的 k 个"吗？

4. 把 iris 数据读进程序，用到了第 14 周的哪两个函数？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


