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

## 人工智能实践: 神经网络组件

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 一个"神经元"是什么: 加权和 + 激活函数

- 激活函数: sigmoid 与 ReLU

- 一层网络 = 矩阵乘法

- 动手: 单层网络做二分类

---


<!-- slide data-notes="" -->


##### 一个神经元

---

==神经元==: 把输入加权求和, 再经过一个==激活函数==

$$y = f(w_1 x_1 + w_2 x_2 + \dots + w_n x_n + b)$$

- $x_i$: 输入特征; $w_i$: ==权重==(每个输入有多重要); $b$: 偏置

- $f$: ==激活函数==, 给网络"非线性"能力 (没有它, 多层就等于一层)

- 用 C 表达: 一个循环求加权和, 再调用激活函数——就是第 5 周的函数!

```C
double neuron(double x[], double w[], double b, int n)
{
  double s = b;
  for (int i = 0; i < n; i++)
    s += w[i] * x[i];       /* 加权和 */
  return sigmoid(s);        /* 激活函数 */
}
```

---


<!-- slide data-notes="" -->


##### 激活函数: sigmoid 与 ReLU

---

==sigmoid==: 把任意数压到 (0, 1), 像一个"软开关"
$$\sigma(x) = \frac{1}{1 + e^{-x}}$$

```C
#include <math.h>
double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
```

==ReLU==: 负数变 0, 正数不变——简单却极其有效

```C
double relu(double x) { return x > 0 ? x : 0; }   /* 第 4 周: 条件表达式 */
```

- 观察: `sigmoid(0)` = 0.5; 很大 → 接近 1; 很小 → 接近 0

- 现场画图: 让程序打印一组 x 对应的 sigmoid 值, 看曲线形状

---


<!-- slide data-notes="" -->


##### 一层网络 = 矩阵乘法

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* W: 3×4 权重, x: 4 个输入, b: 3 个偏置, y: 3 个输出 */
for (int i = 0; i < 3; i++) {
  double s = b[i];
  for (int j = 0; j < 4; j++)
    s += W[i][j] * x[j];
  y[i] = sigmoid(s);
}
```

</div>

<div style="flex:1;">

一层有 3 个神经元、输入 4 个特征: 每个神经元各有一组权重

$$\mathbf{y} = f(W\mathbf{x} + \mathbf{b})$$

- $W$ 是 ==3×4 的权重矩阵== (3 个神经元 × 4 个特征)

- 这就是第 9 周写的==矩阵乘向量==: 三重循环退化为两重

第 1 周说"AI 的张量就是连续内存 + 指针, 矩阵乘法就是二维数组 + 循环"——这就是原样

</div>

</div>

<!-- slide data-notes="" -->


##### 动手: 单层网络做二分类

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C{.line-numbers}
/* 训练循环 (简化版): 每个样本预测 → 算误差 → 调权重 */
for (int epoch = 0; epoch < 100; epoch++) {
  for (int i = 0; i < n; i++) {
    double pred = sigmoid(w[0]*x[i][0] + w[1]*x[i][1]
                        + w[2]*x[i][2] + w[3]*x[i][3] + b);
    double err = labels[i] - pred;          /* 误差 */
    for (int j = 0; j < 4; j++)
      w[j] += 0.01 * err * x[i][j];         /* 调权重: 学! */
    b += 0.01 * err;
  }
}
```

</div>

<div style="flex:1;">

用昨天的 iris 数据, 只取两类 (0 和 1), 写一个==单层感知机==:

`0.01` 是==学习率==: 每步"学"多少

- 现场运行: 训练前后各测一次准确率, 看数字变好

</div>

</div>

<!-- slide data-notes="" -->


##### 回到第 1 周的问题

---

<span class="blue">:fa-lightbulb-o:</span> 第 1 周说过: ==AI 的底层是 C==

| 当时的说法 | 这两周你做了什么 |
| :-- | :-- |
| 张量 = 连续内存 + 指针 | `features[150][4]` 二维数组 |
| 矩阵乘法 = 二维数组 + 循环 | 第 9 周的矩阵乘法、今天的 W·x |
| BLAS 等库用 C 写 | 你的距离函数、神经元函数 |
| TinyML 跑在单片机上 | 整个程序没有动态内存也能跑 |

- PyTorch 里的 `nn.Linear(4, 3)` 就是这个 `for` 循环, 只不过它跑在 GPU 上并做了极致优化

- ==这门课学完的东西, 拼起来就是一个 AI 框架的迷你版==

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 一个神经元的计算分两步，分别是什么？

2. 如果没有激活函数，多层网络会退化成什么？

3. 一层的权重矩阵 W 是 3×4，它的行和列分别代表什么？

4. 训练循环里的"学习率"控制什么？调太大会怎样？

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="../figs/see-you.png" width=500px>
</div>

---


