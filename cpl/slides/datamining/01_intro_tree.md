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
- 第五章：异类的隔离 —— 孤立森林 (异常检测)

五种经典算法：从规则、距离、频率、概率到隔离

---

<!-- slide -->

# 课程目标

本课程结束后，希望大家能够：

- 理解五种经典算法的核心思想
- 理解决策树、聚类、关联分析、概率分类、异常检测之间的区别
- 掌握 Scikit-learn 的基本使用方法
- 能够针对实际问题选择合适算法

---

<!-- slide -->

# 为什么还要学习经典算法？

> 大模型已经很强了，经典机器学习还有价值吗？

<div class="twocol">

<div>

### 为什么仍然重要？

- 数据量有限
- 模型需要可解释
- 训练成本低
- 部署成本低
- 工业界广泛使用

</div>

<div>

### 典型应用

🏦 银行风控

🏥 医疗诊断

🎯 推荐系统

👤 用户画像

🛡️ 网络安全

</div>

</div>

---

<!-- slide -->

# 数据挖掘与机器学习

二者关系：

人工智能<br>
↓<br>
机器学习<br>
↓<br>
数据挖掘

机器学习：
- 更关注预测

数据挖掘：
- 更关注发现规律

例如：

机器学习：

> 明天会下雨吗？

数据挖掘：

> 哪些因素导致下雨？

---

<!-- slide -->

# 为什么选择这五种算法？

## 五种思想

| 思想 | 代表算法 |
|--------|--------|
| 规则 | 决策树 |
| 距离 | K-Means |
| 频率 | Apriori |
| 概率 | 朴素贝叶斯 |
| 隔离 | 孤立森林 |

覆盖：

- 分类
- 聚类
- 关联分析
- 异常检测

四大核心任务。


---

<!-- slide -->

# 五种算法的世界版图

| 算法 | 金融 | 电商 | 医疗 | 安全 |
|--------|--------|--------|--------|--------|
| 决策树 | 风控 | 用户分类 | 辅助诊断 | 入侵检测 |
| K-Means | 客户分群 | 用户画像 | 病人分群 | 流量分析 |
| Apriori | 欺诈关联 | 商品推荐 | 药物关联 | 攻击链分析 |
| 贝叶斯 | 信贷审批 | 文本分类 | 疾病预测 | 垃圾邮件 |
| 孤立森林 | 欺诈检测 | 异常订单 | 异常病例 | 异常流量 |

---

<!-- slide -->

# 数据挖掘的一般流程

```text
原始数据
    ↓
数据清洗
    ↓
特征工程
    ↓
模型训练
    ↓
结果分析
    ↓
业务决策
```

经验规律：

- 数据处理占80%
- 建模占20%

---

<!-- slide -->

# 开场案例：信用卡欺诈检测

假设：

一家银行每天产生：

- 500万笔交易
- 50万客户
- 欺诈比例低于0.1%

问题：

如何自动发现欺诈行为？

---

<!-- slide -->

# 人工分析为什么不可行？

假设：

每条记录查看10秒。

那么：

```text
5000000 × 10秒

≈ 50000000秒

≈ 579天
```

结论：

人工无法完成。

必须依赖算法。

---

<!-- slide -->

# 如果你是算法工程师？

你可能想到：

- 制定规则
- 学习历史案例
- 寻找相似用户
- 发现异常行为

事实上：

这正对应今天的五种算法。

---

<!-- slide -->

# 案例与算法对应关系

| 问题 | 算法 |
|--------|--------|
| 是否欺诈？ | 决策树 |
| 欺诈概率是多少？ | 贝叶斯 |
| 用户自动分群？ | K-Means |
| 哪些行为经常一起出现？ | Apriori |
| 如何发现未知欺诈？ | 孤立森林 |

---

<!-- slide -->

# 第一部分：决策树

<i class="fa fa-tree"></i>

Decision Tree

关键词：

- 分类
- 规则
- 可解释

---

<!-- slide -->

# 一个简单问题

银行审批贷款时：

关注：

- 收入
- 年龄
- 信用评分

最终输出：

```text
批准
拒绝
```

人类通常怎么做？

不断提问。

---

<!-- slide -->

# 决策树的核心思想

不断提问。

例如：

```text
收入 > 10万 ?
      |
     是
      |
信用评分 > 80 ?
      |
     是
      |
    批准
```

本质：

> 自动寻找最有价值的问题。

---

<!-- slide -->

# 什么是好问题？

假设：

100人：

- 50个好客户
- 50个坏客户

如果一个问题能变成：

```text
左边：45好 5坏

右边：5好 45坏
```

那么：

这个问题很有价值。

---

<!-- slide -->

# 信息熵（Entropy）

用于衡量混乱程度。

公式：

\[
H=-\sum p_i \log_2 p_i
\]

无需记忆。

只需理解：

- 越混乱 → 熵越高
- 越纯净 → 熵越低

---

<!-- slide -->

# 熵的直观理解

| 数据情况 | 熵 |
|-----------|------|
| 全是正类 | 0 |
| 全是负类 | 0 |
| 各占50% | 最大 |

因此：

好的划分：

> 快速降低熵。

---

<!-- slide -->

# 信息增益

定义：

\[
Gain = H(before)-H(after)
\]

含义：

划分前的不确定性

减去

划分后的不确定性

越大越好。

---

<!-- slide -->

# ID3算法

经典决策树算法。

步骤：

1. 计算每个特征的信息增益
2. 选择最大者
3. 划分数据
4. 递归构建子树

直到：

- 节点足够纯净
- 达到停止条件

---

<!-- slide -->

# C4.5算法

ID3升级版。

改进：

- 支持连续值
- 支持缺失值
- 使用增益率

工业界使用更加广泛。

---

<!-- slide -->

# 决策树训练流程

```text
根节点
   ↓
选择最佳特征
   ↓
划分数据
   ↓
生成子节点
   ↓
继续划分
```

直到生成完整树。

---

<!-- slide -->

# Sklearn实践：生成数据

```python
from sklearn.datasets import make_classification

X, y = make_classification(
    n_samples=2000,
    n_features=10,
    n_informative=6,
    random_state=42
)

print(X.shape)
```

输出：

```text
(2000, 10)
```

---

<!-- slide -->

# Sklearn实践：划分训练集

```python
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.3,
    random_state=42
)
```

训练集：

70%

测试集：

30%

---

<!-- slide -->

# Sklearn实践：训练模型

```python
from sklearn.tree import DecisionTreeClassifier

model = DecisionTreeClassifier(
    max_depth=5,
    random_state=42
)

model.fit(
    X_train,
    y_train
)
```

---

<!-- slide -->

# Sklearn实践：评估模型

```python
accuracy = model.score(
    X_test,
    y_test
)

print(
    f"Accuracy={accuracy:.4f}"
)
```

典型输出：

```text
Accuracy=0.88
```

---

<!-- slide -->

# Sklearn实践：查看规则

```python
from sklearn.tree import export_text

rules = export_text(model)

print(rules)
```

得到：

```text
feature_3 <= 0.75
...
```

这正是决策树最大的优势：

可解释。

---

<!-- slide -->

# 决策树优点

<i class="fa fa-thumbs-up"></i>

- 易理解
- 易解释
- 训练快
- 推理快
- 支持非线性边界

---

<!-- slide -->

# 决策树缺点

<i class="fa fa-warning"></i>

- 易过拟合
- 对噪声敏感
- 稳定性较差

数据稍有变化：

树结构可能变化很大。

---

<!-- slide -->

# 如何防止过拟合？

常见方法：

- 限制树深度
- 限制叶子节点
- 剪枝
- 随机森林
- Boosting

例如：

- Random Forest
- XGBoost

---

<!-- slide -->

# 决策树应用场景

广泛用于：

- 银行风控
- 用户流失预测
- 医疗诊断
- 客户分类
- 入侵检测

原因：

> 可解释。

---

<!-- slide -->

# 随堂思考题

某银行审批贷款。

可用特征：

- 收入
- 信用评分
- 工作年限

问题：

为什么决策树比神经网络更容易获得业务部门认可？

---

<!-- slide -->

# 思考题参考答案

原因：

- 规则透明
- 容易解释
- 满足审计要求
- 便于监管部门检查

很多行业：

准确率不是唯一目标。

可解释性同样重要。

---

<!-- slide -->

# 本部分总结

完成内容：

✅ 数据挖掘概述

✅ 五种经典算法全景图

✅ 信用卡欺诈案例

✅ 决策树核心思想

✅ 信息熵与信息增益

✅ Scikit-learn实践

---

<!-- slide -->

下一部分：

# K-Means 聚类 + Apriori关联规则

---