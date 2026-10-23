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
- 第二章：距离的度量 —— K-Means (聚类)
- 第三章：频率的发现 —— Apriori (关联)
- 第四章：概率的推断 —— 朴素贝叶斯 (分类)
- **第五章：异类的隔离 —— 孤立森林 (异常检测)**

五种经典算法：从规则、距离、频率、概率到隔离

---

<!-- slide -->

# 学习目标

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

