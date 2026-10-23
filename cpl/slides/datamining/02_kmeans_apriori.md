---
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
  math: false
---

@import "../../css/theme/solarized.css"
@import "../../css/logo.css"
@import "../../css/font.css"
@import "../../css/color.css"
@import "../../css/margin.css"
@import "../../css/table.css"
@import "../../css/main.css"

# @import "../../plugin/zoom/zoom.js"
# @import "../../plugin/customcontrols/plugin.js"
# @import "../../plugin/chalkboard/plugin.js"
# @import "../../plugin/chalkboard/style.css"
# @import "../../plugin/menu/menu.js"

# @import "../../js/anychart/anychart-core.min.js"
# @import "../../js/anychart/anychart-venn.min.js"
# @import "../../js/anychart/pastel.min.js"
# @import "../../js/anychart/venn-ml.js"


<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 经典数据挖掘算法

<hr class="width50 center">

### 杨已彪
### 南京大学计算机学院
### 计算机软件新技术全国重点实验室

#### yangyibiao@nju.edu.cn

<i class="fa fa-database"></i> 数据挖掘专题课程

---

<!-- slide -->

# 《经典数据挖掘算法》

- 第一章：规则的建立 —— 决策树 (分类)
- **第二章：距离的度量 —— K-Means (聚类)**
- 第三章：频率的发现 —— Apriori (关联)
- 第四章：概率的推断 —— 朴素贝叶斯 (分类)
- 第五章：异类的隔离 —— 孤立森林 (异常检测)

五种经典算法：从规则、距离、频率、概率到隔离

---

<!-- slide -->

# 学习目标

本部分结束后，希望大家能够：

- 理解聚类与分类的本质区别
- 掌握 K-Means 的核心思想与实现流程
- 理解关联规则挖掘的价值
- 掌握 Apriori 算法的基本原理
- 能够使用 Scikit-learn 和 Python 实现相关分析


---

<!-- slide -->

# 回顾：分类与聚类

分类（Classification）：

```text
有标签
```

例如：

- 好客户
- 坏客户

聚类（Clustering）：

```text
无标签
```

例如：

- 自动发现用户群体

---

<!-- slide -->

# 第二部分：K-Means

<i class="fa fa-users"></i>

关键词：

- 聚类
- 距离
- 无监督学习

---

<!-- slide -->

# 一个真实问题

某电商平台：

拥有100万用户。

已知：

- 年龄
- 消费金额
- 浏览次数

问题：

如何自动发现不同用户群体？

---

<!-- slide -->

# 人工分类的问题

如果人工定义：

- 高价值用户
- 普通用户
- 潜在流失用户

可能带有主观性。

有没有办法：

让数据自己说话？

---

<!-- slide -->

# K-Means核心思想

一句话：

> 让相似的数据聚在一起。

例如：

```text
学生
学生
学生

↓

学生群体A

教师
教师
教师

↓

教师群体B
```

---

<!-- slide -->

# K-Means中的“K”是什么？

K：

表示簇（Cluster）的数量。

例如：

```text
K = 3
```

表示：

希望最终得到3个群体。

---

<!-- slide -->

# K-Means中的Means是什么？

Means：

表示均值（中心点）。

每个簇：

都有一个中心。

```text
簇1中心
簇2中心
簇3中心
```

算法不断调整中心位置。

---

<!-- slide -->

# K-Means工作流程

```text
随机初始化K个中心
        ↓
计算距离
        ↓
分配样本
        ↓
更新中心
        ↓
重复迭代
```

直到中心不再变化。

---

<!-- slide -->

# 距离如何计算？

最常见：

欧氏距离

\[
d(x,y)=\sqrt{\sum(x_i-y_i)^2}
\]

直观理解：

两点之间直线距离。

---

<!-- slide -->

# 一个简单例子

数据：

```text
(1,1)
(2,1)
(8,9)
(9,8)
```

K=2

很自然形成：

```text
簇A:
(1,1)
(2,1)

簇B:
(8,9)
(9,8)
```

---

<!-- slide -->

# K-Means优化目标

希望：

簇内尽可能相似。

目标函数：

\[
\sum ||x-c||^2
\]

含义：

每个样本到中心的距离平方和最小。

---

<!-- slide -->

# K-Means为什么有效？

因为：

不断执行：

```text
分配
↓
更新
↓
分配
↓
更新
```

目标函数持续下降。

最终收敛。

---

<!-- slide -->

# K-Means代码实践：生成数据

```python
from sklearn.datasets import make_blobs

X, y = make_blobs(
    n_samples=1000,
    centers=4,
    cluster_std=1.0,
    random_state=42
)

print(X.shape)
```

---

<!-- slide -->

# K-Means代码实践：训练模型

```python
from sklearn.cluster import KMeans

model = KMeans(
    n_clusters=4,
    random_state=42
)

model.fit(X)
```

---

<!-- slide -->

# 查看聚类中心

```python
print(
    model.cluster_centers_
)
```

输出类似：

```text
[[ 4.5  2.1]
 [-6.8  8.2]
 ...]
```

---

<!-- slide -->

# 查看聚类结果

```python
labels = model.labels_

print(labels[:20])
```

输出：

```text
0 0 0 1 1 2 ...
```

表示所属簇编号。

---

<!-- slide -->

# 如何选择K？

核心问题：

K应该是多少？

常用方法：

- 肘部法（Elbow）
- 轮廓系数（Silhouette）

---

<!-- slide -->

# 肘部法

绘制：

```text
K
↓
误差平方和
```

随着K增加：

误差下降。

出现明显拐点：

即较优K值。


---

<!-- slide -->

# 轮廓系数

衡量：

```text
簇内紧密度
+
簇间分离度
```

取值：

```text
[-1,1]
```

越接近1越好。

---

<!-- slide -->

# K-Means优点

<i class="fa fa-thumbs-up"></i>

- 简单
- 高效
- 易实现
- 可扩展

适合大规模数据。


---

<!-- slide -->

# K-Means缺点

<i class="fa fa-warning"></i>

- 需要提前指定K
- 对异常值敏感
- 只能发现球状簇


---

<!-- slide -->

# K-Means应用场景

广泛用于：

- 用户画像
- 客户分群
- 社交网络分析
- 文档聚类
- 图像压缩

---

<!-- slide -->

# 思考题

如果数据如下：

```text
两个同心圆
```

K-Means效果会好吗？

---

<!-- slide -->

# 思考题参考答案

不会。

原因：

K-Means假设：

```text
簇近似球形
```

同心圆不满足该假设。

可考虑：

- DBSCAN
- 谱聚类

---

<!-- slide -->

# 第三部分：Apriori

<i class="fa fa-link"></i>

关键词：

- 频繁模式
- 关联规则
- 购物篮分析

---

<!-- slide -->

# 一个经典问题

超市发现：

```text
尿布
+
啤酒
```

经常同时购买。

问题：

如何自动发现这种规律？


---

<!-- slide -->

# 什么是关联规则？

形式：

```text
A → B
```

例如：

```text
牛奶 → 面包
```

含义：

购买牛奶的人

往往也购买面包。

---

<!-- slide -->

# Apriori核心思想

频繁项集：

经常同时出现的商品组合。

例如：

```text
{牛奶,面包}
```

出现很多次。

---

<!-- slide -->

# Apriori的关键假设

著名性质：

> 频繁项集的所有子集一定频繁。

例如：

如果：

```text
{A,B,C}
```

频繁。

那么：

```text
{A,B}
{A,C}
{B,C}
```

也必须频繁。

---

<!-- slide -->

# 支持度（Support）

定义：

\[
Support(A)=
\frac{A出现次数}{总交易数}
\]

例如：

100笔订单。

20笔包含牛奶。

支持度：

```text
20%
```

---

<!-- slide -->

# 置信度（Confidence）

定义：

\[
Confidence(A→B)
=
\frac{Support(A,B)}
{Support(A)}
\]

表示：

购买A后购买B的概率。

---

<!-- slide -->

# 提升度（Lift）

定义：

\[
Lift=
\frac{Confidence(A→B)}
{Support(B)}
\]

解释：

大于1：

正相关。

小于1：

负相关。

---

<!-- slide -->

# Apriori流程

```text
找频繁1项集
      ↓
生成频繁2项集
      ↓
生成频繁3项集
      ↓
...
```

不断剪枝。

---

<!-- slide -->

# Apriori代码实践

```python
import pandas as pd

data = pd.DataFrame([
 [1,1,0],
 [1,1,1],
 [1,0,1],
 [1,1,1]
], columns=["Milk","Bread","Beer"])

print(data)
```

---

<!-- slide -->

# 计算频繁项集

```python
from mlxtend.frequent_patterns import apriori

freq = apriori(
    data,
    min_support=0.5,
    use_colnames=True
)

print(freq)
```

---

<!-- slide -->

# 生成关联规则

```python
from mlxtend.frequent_patterns import association_rules

rules = association_rules(
    freq,
    metric="confidence",
    min_threshold=0.7
)

print(rules)
```

---

<!-- slide -->

# Apriori优点

<i class="fa fa-thumbs-up"></i>

- 结果容易理解
- 发现隐藏规律
- 强解释性

---

<!-- slide -->

# Apriori缺点

<i class="fa fa-warning"></i>

- 候选集爆炸
- 计算开销大
- 数据稀疏时效果下降

---

<!-- slide -->

# Apriori应用场景

- 商品推荐
- 联合营销
- 医疗关联分析
- 网络安全事件关联
- 用户行为分析

---

<!-- slide -->

# 思考题

支持度阈值设置过低：

会发生什么？

---

<!-- slide -->

# 思考题参考答案

结果：

- 频繁项集暴增
- 规则数量爆炸
- 计算成本急剧增加
- 噪声规则增多

---

<!-- slide -->

# Part 2 总结

完成内容：

✅ K-Means聚类

✅ 聚类中心思想

✅ K值选择

✅ Apriori关联规则

✅ 支持度、置信度、提升度

✅ Python实践

下一部分：

# 朴素贝叶斯 + 手算推演

---

# 《经典数据挖掘算法》
## Part 3：朴素贝叶斯 + 手算推演
### 总时长：约35分钟

---

<!-- slide -->

# Part 3 学习目标

本部分结束后，希望大家能够：

- 理解概率分类的基本思想
- 掌握贝叶斯定理的含义
- 理解朴素贝叶斯中的“朴素”假设
- 能够使用 Scikit-learn 实现分类
- 能够手工计算简单贝叶斯后验概率

---

<!-- slide -->

# 回顾：前面学了什么？

决策树：

```text
规则思维
```

K-Means：

```text
距离思维
```

Apriori：

```text
频率思维
```

本节进入：

```text
概率思维
```

---

<!-- slide -->

# 一个真实问题

假设：

你收到一封邮件。

内容如下：

```text
免费
中奖
点击领取
```

问题：

这是不是垃圾邮件？

---

<!-- slide -->

# 人类如何判断？

通常会想：

```text
以前见过类似内容吗？
```

如果：

- 垃圾邮件中经常出现
- 正常邮件中很少出现

那么：

垃圾邮件概率更高。

---

<!-- slide -->

# 贝叶斯思想

核心思想：

> 根据证据不断修正认知。

例如：

最初认为：

```text
垃圾邮件概率 = 10%
```

看到：

```text
中奖
免费
```

之后：

概率上升。

---

<!-- slide -->

# 贝叶斯定理

贝叶斯定理是概率推断的核心工具

$P(A|B)=\frac{P(B|A)P(A)}{P(B)}$

直观理解：

```text
先验认知
+
新证据
=
更新后的认知
```

---

<!-- slide -->

# 贝叶斯定理中的四个量

| 符号 | 含义 |
|--------|--------|
| P(A) | 先验概率 |
| P(B|A) | 似然 |
| P(B) | 证据概率 |
| P(A|B) | 后验概率 |

最终关注：

```text
P(A|B)
```

即：

看到证据后，

事件发生的概率。

---

<!-- slide -->

# 一个医学例子

某疾病：

```text
患病率 1%
```

检测准确率：

```text
99%
```

如果检测阳性：

是否一定患病？

很多人认为：

```text
99%
```

其实并不是。

---

<!-- slide -->

# 贝叶斯告诉我们什么？

除了检测准确率：

还必须考虑：

```text
疾病本身是否常见
```

即：

先验概率。

这是贝叶斯思想最重要的地方。

---

<!-- slide -->

# 什么是朴素贝叶斯？

Naive Bayes

朴素：

```text
假设所有特征彼此独立
```

例如：

```text
免费
中奖
点击
```

认为：

彼此没有关联。

虽然不完全真实。

但效果往往很好。

---

<!-- slide -->

# 为什么叫“朴素”？

现实世界：

特征通常相关。

例如：

```text
中奖
+
领奖
```

显然相关。

但朴素贝叶斯为了计算简单：

直接假设独立。

这是一种工程上的近似。

---

<!-- slide -->

# 分类过程

给定：

```text
特征
```

例如：

```text
免费
中奖
领取
```

分别计算：

```text
P(垃圾邮件)

P(正常邮件)
```

谁大选谁。

---

<!-- slide -->

# 一个简单例子

训练数据：

| 邮件 | 是否垃圾 |
|--------|--------|
| 免费中奖 | 是 |
| 点击领奖 | 是 |
| 项目通知 | 否 |
| 会议安排 | 否 |

新邮件：

```text
免费领奖
```

如何判断？

使用贝叶斯概率。

---

<!-- slide -->

# 朴素贝叶斯的优势

因为：

```text
联合概率
=
多个概率相乘
```

计算量非常小。

即使：

```text
10000个特征
```

也能快速处理。

---

<!-- slide -->

# 常见类型

Scikit-learn提供：

### GaussianNB

连续特征

### MultinomialNB

文本分类

### BernoulliNB

二值特征

---

<!-- slide -->

# GaussianNB代码实践

```python
from sklearn.datasets import make_classification
from sklearn.naive_bayes import GaussianNB

X, y = make_classification(
    n_samples=2000,
    n_features=10,
    n_informative=6,
    random_state=42
)

model = GaussianNB()

model.fit(X, y)
```

---

<!-- slide -->

# 模型预测

```python
pred = model.predict(
    X[:10]
)

print(pred)
```

输出：

```text
[1 0 1 1 0 ...]
```

---

<!-- slide -->

# 查看概率

```python
proba = model.predict_proba(
    X[:5]
)

print(proba)
```

输出：

```text
[[0.1 0.9]
 [0.8 0.2]
 ...]
```

表示：

属于每个类别的概率。

---

<!-- slide -->

# 模型评估

```python
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.3,
    random_state=42
)

model.fit(X_train, y_train)

print(
    model.score(X_test,y_test)
)
```

---

<!-- slide -->

# 朴素贝叶斯优点

<i class="fa fa-thumbs-up"></i>

- 简单
- 高效
- 可处理高维数据
- 小样本表现好
- 训练速度极快

---

<!-- slide -->

# 朴素贝叶斯缺点

<i class="fa fa-warning"></i>

- 独立性假设较强
- 特征相关时性能下降
- 表达能力有限

---

<!-- slide -->

# 典型应用场景

广泛用于：

- 垃圾邮件过滤
- 新闻分类
- 情感分析
- 医疗诊断辅助
- 风险识别



---

<!-- slide -->

# 手算推演开始

现在不使用代码。

亲手计算一次贝叶斯分类。



---

<!-- slide -->

# 已知条件

100封邮件：

```text
垃圾邮件：40封

正常邮件：60封
```

因此：

```text
P(垃圾)=0.4

P(正常)=0.6
```



---

<!-- slide -->

# 特征统计

词语：

```text
中奖
```

出现情况：

垃圾邮件：

```text
32/40
```

正常邮件：

```text
6/60
```

因此：

```text
P(中奖|垃圾)=0.8

P(中奖|正常)=0.1
```


---

<!-- slide -->

# 问题

收到新邮件：

```text
包含“中奖”
```

求：

```text
P(垃圾|中奖)
```

---

<!-- slide -->

# 第一步

计算：

```text
P(中奖)
```

根据全概率公式：

```text
P(中奖)
=
0.8×0.4
+
0.1×0.6
```

结果：

```text
0.38
```

---

<!-- slide -->

# 第二步

代入贝叶斯公式：

```text
P(垃圾|中奖)

=
0.8×0.4
/
0.38
```

---

<!-- slide -->

# 计算结果

```text
0.842
```

即：

```text
84.2%
```

因此：

该邮件大概率是垃圾邮件。

---

<!-- slide -->

# 思考题

如果：

```text
P(垃圾)=1%
```

其他条件不变。

结果会发生什么？

---

<!-- slide -->

# 思考题参考答案

后验概率会显著下降。

原因：

```text
先验概率极低
```

即使证据很强：

最终概率也未必高。

这正是贝叶斯思想的精髓。


---

<!-- slide -->

# 本部分总结

完成内容：

✅ 贝叶斯思想

✅ 贝叶斯定理

✅ 朴素贝叶斯分类

✅ Scikit-learn实践

✅ 手工计算后验概率

下一部分：

# 孤立森林 + 异常检测 + 课程总结

---

# 《经典数据挖掘算法》
## Part 4：孤立森林 + 分组研讨 + 算法图谱 + 课程总结
### 总时长：约40分钟

---

<!-- slide -->

# Part 4 学习目标

本部分结束后，希望大家能够：

- 理解异常检测问题
- 掌握 Isolation Forest 核心思想
- 学会使用 Scikit-learn 进行异常检测
- 综合比较五种经典算法
- 能够针对实际问题选择合适算法

---

<!-- slide -->

# 回顾：我们已经学习了什么？

| 思维方式 | 算法 |
|----------|----------|
| 规则 | 决策树 |
| 距离 | K-Means |
| 频率 | Apriori |
| 概率 | 朴素贝叶斯 |

今天最后一种思想：

```text
隔离（Isolation）
```

---

<!-- slide -->

# 一个现实问题

某银行每天：

```text
100万笔交易
```

其中：

```text
99.9%正常

0.1%异常
```

问题：

如何发现未知欺诈？

---

<!-- slide -->

# 为什么传统分类不够？

传统分类需要：

```text
大量标签
```

但现实中：

- 新型攻击
- 新型欺诈
- 新型故障

往往：

```text
没有历史样本
```

怎么办？

---

<!-- slide -->

# 什么是异常检测？

目标：

在大量正常数据中发现：

```text
少数特殊个体
```

例如：

- 欺诈交易
- 网络攻击
- 设备故障
- 数据错误


---

<!-- slide -->

# 第四部分：孤立森林

<i class="fa fa-search"></i>

Isolation Forest

提出时间：

```text
2008
```

已经成为工业界经典异常检测算法。

---

<!-- slide -->

# 一个有趣的问题

假设：

房间里有100个人。

其中：

99个人站在一起。

1个人站在角落。

问题：

谁最容易被发现？

答案：

```text
角落那个人
```

---

<!-- slide -->

# 孤立森林的核心思想

核心观点：

> 异常点更容易被孤立出来。

正常点：

```text
聚集在一起
```

异常点：

```text
远离群体
```

因此：

更容易被随机切分出来。

---

<!-- slide -->

# 随机切分示意

```text
正常点：

●●●●●●●●●

异常点：

          ▲
```

随机切分：

```text
很快就能单独圈出▲
```

---

<!-- slide -->

# 为什么叫“森林”？

因为：

不是一棵树。

而是：

```text
很多随机树
```

每棵树：

随机选择：

- 特征
- 切分点

最终综合结果。


---

<!-- slide -->

# 孤立树构建过程

```text
随机选择特征
       ↓
随机选择切分点
       ↓
划分数据
       ↓
继续递归
```

直到：

样本被隔离。

---

<!-- slide -->

# 路径长度

关键指标：

```text
Path Length
```

含义：

一个样本被隔离前：

经过多少次切分。

异常点：

```text
路径短
```

正常点：

```text
路径长
```

---

<!-- slide -->

# 异常得分

最终输出：

```text
Anomaly Score
```

接近：

```text
1
```

异常可能性高。

接近：

```text
0
```

异常可能性低。

---

<!-- slide -->

# Isolation Forest代码实践

生成模拟数据：

```python
import numpy as np

normal_data = np.random.randn(
    1000,
    2
)

outliers = np.random.uniform(
    low=8,
    high=10,
    size=(20,2)
)

X = np.vstack(
    [normal_data,outliers]
)
```

---

<!-- slide -->

# 训练模型

```python
from sklearn.ensemble import IsolationForest

model = IsolationForest(
    contamination=0.02,
    random_state=42
)

model.fit(X)
```

---

<!-- slide -->

# 预测异常

```python
pred = model.predict(X)

print(
    np.unique(pred,
              return_counts=True)
)
```

输出：

```text
-1 异常

 1 正常
```

---

<!-- slide -->

# 查看异常得分

```python
scores = model.score_samples(X)

print(
    scores[:10]
)
```

结果：

```text
值越小
越异常
```


---

<!-- slide -->

# 孤立森林优点

<i class="fa fa-thumbs-up"></i>

- 无需标签
- 高效
- 可扩展
- 适合高维数据
- 适合异常检测


---

<!-- slide -->

# 孤立森林缺点

<i class="fa fa-warning"></i>

- 结果解释性一般
- 参数敏感
- 无法提供异常原因


---

<!-- slide -->

# 典型应用场景

广泛用于：

- 欺诈检测
- 网络攻击检测
- 设备故障监测
- 金融风控
- 日志异常分析


---

<!-- slide -->

# 思考题

为什么Isolation Forest适合发现未知欺诈？


---

<!-- slide -->

# 思考题参考答案

因为：

```text
不依赖标签
```

关注：

```text
是否异常
```

而不是：

```text
属于哪个类别
```

因此：

能发现新型问题。


---

<!-- slide -->

# 分组研讨

<i class="fa fa-users"></i>

课堂练习


---

<!-- slide -->

# 研讨题目

某在线教育平台拥有：

```text
100万用户
```

数据包括：

- 用户年龄
- 学习时长
- 登录频率
- 课程购买记录
- 评论内容

任务：

希望提升平台运营效果。

请选择：

今天学习的算法。

说明理由。


---

<!-- slide -->

# 小组讨论要求

每组完成：

1. 选择算法
2. 说明原因
3. 预期输出结果
4. 如何评估效果

时间：

```text
10分钟讨论

5分钟分享
```


---

<!-- slide -->

# 参考答案示例

用户分群：

```text
K-Means
```

购买组合分析：

```text
Apriori
```

用户分类：

```text
决策树
```

异常账号发现：

```text
Isolation Forest
```

评论分类：

```text
朴素贝叶斯
```

---

<!-- slide -->

# 五种算法全景图

```text
规则
 ↓
决策树

距离
 ↓
K-Means

频率
 ↓
Apriori

概率
 ↓
朴素贝叶斯

隔离
 ↓
孤立森林
```

---

<!-- slide -->

# 算法对比图谱

| 算法 | 类型 | 输入 | 输出 |
|--------|--------|--------|--------|
| 决策树 | 分类 | 特征+标签 | 类别 |
| K-Means | 聚类 | 特征 | 簇 |
| Apriori | 关联分析 | 事务数据 | 规则 |
| 贝叶斯 | 分类 | 特征+标签 | 概率 |
| 孤立森林 | 异常检测 | 特征 | 异常分数 |


---

<!-- slide -->

# 算法能力对比

| 算法 | 可解释性 | 效率 | 标签需求 |
|--------|--------|--------|--------|
| 决策树 | ★★★★★ | ★★★★ | 需要 |
| K-Means | ★★★ | ★★★★★ | 不需要 |
| Apriori | ★★★★★ | ★★ | 不需要 |
| 贝叶斯 | ★★★★ | ★★★★★ | 需要 |
| 孤立森林 | ★★★ | ★★★★ | 不需要 |


---

<!-- slide -->

# 算法选择指南

如果问题是：

```text
预测类别
```

选择：

- 决策树
- 贝叶斯

如果问题是：

```text
自动分群
```

选择：

- K-Means

如果问题是：

```text
发现关联规律
```

选择：

- Apriori

如果问题是：

```text
发现异常
```

选择：

- Isolation Forest


---

<!-- slide -->

# 课程总结

今天学习了：

✅ 决策树

✅ K-Means

✅ Apriori

✅ 朴素贝叶斯

✅ 孤立森林

对应五种思想：

```text
规则
距离
频率
概率
隔离
```

---

<!-- slide -->

# 后续学习路线

第一阶段：

- 熟练掌握 Scikit-learn

第二阶段：

- Random Forest
- XGBoost
- DBSCAN

第三阶段：

- 深度学习
- 大语言模型

记住：

> 新技术层出不穷，但经典思想历久弥新。

---

<!-- slide -->

# 结束语

<i class="fa fa-graduation-cap"></i>

数据挖掘的价值：

不是让机器替代思考。

而是帮助我们：

```text
从海量数据中发现规律
```

谢谢大家！

Q & A

