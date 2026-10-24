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

@import "../css/theme/solarized.css"
@import "../css/logo.css"
@import "../css/font.css"
@import "../css/color.css"
@import "../css/margin.css"
@import "../css/table.css"
@import "../css/main.css"
@import "../css/datamining.css"

# @import "../../plugin/zoom/zoom.js"
# @import "../../plugin/customcontrols/plugin.js"
# @import "../../plugin/chalkboard/plugin.js"
# @import "../../plugin/chalkboard/style.css"
# @import "../../plugin/menu/menu.js"
# @import "../../js/anychart/anychart-core.min.js"
# @import "../../js/anychart/anychart-venn.min.js"
# @import "../../js/anychart/pastel.min.js"
# @import "../../js/anychart/venn-ml.js"

<!-- slide -->

# 决策树 · Decision Tree

<hr class="width30 center" style="margin-top:0.2rem;margin-bottom:0.2rem;">

<div style="text-align:center;font-size:0.75em;color:var(--solarized-base00);letter-spacing:2px;">
从 "专家经验" 到 "自动判据" 的桥梁
</div>

<div style="margin-top:30px;text-align:center;font-size:0.65em;color:var(--solarized-base00);">
**网空关键词:** 恶意流量判据提取 · 告警规则自动生成 · 白盒可解释
</div>

<div style="margin-top:100px;text-align:center;line-height:2.2;">
<div style="font-size:1.05em;font-weight:600;letter-spacing:1px;">
杨已彪
</div>
<div style="font-size:0.6em;color:var(--solarized-base00);">
yangyibiao@nju.edu.cn
</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:4px;">
南京大学计算机学院 · 计算机软件新技术全国重点实验室
</div>
<div style="margin-top:20px;font-size:0.5em;color:var(--solarized-base01);letter-spacing:3px;">
2026 年 10 月
</div>
</div>

---

<!-- slide -->

## 一个网空场景

<div style="margin-bottom:8px;">
某部**物理隔离**内网,监测节点持续上报流量特征。
**核心任务:** 判定某条外连请求是否为 **恶意 C2 通信**?
</div>

<div class="twocol" style="font-size:0.9em;">

<div>

### 🔓 入侵路径(已发生案例)

- 通过 **U 盘摆渡** 植入(震网病毒)
- 通过 **固件预置后门** 植入
- 通过 **供应链攻击** 植入
- 通过 **运维通道** 渗透

</div>

<div>

### 🕵️‍♂️ 隐蔽方式

- **伪装成合法协议**(HTTPS/DNS)
- **利用正常软件更新**通道
- **通过加密隧道**传输指令
- **低频心跳**长期潜伏

</div>

</div>

<div class="important" style="margin-top:4px;">
物理隔离 ≠ 绝对安全。攻击者已多次证明:**物理边界可以被技术手段穿透**。算法检测成为最后一道防线。
</div>

---

<!-- slide -->

## 决策树的核心思想

> 不断提问,逐层判定。以流量检测为例:

```mermaid
%%{init: { 'theme': 'base', 'themeVariables': { 'fontSize': '12px' } } }%%
flowchart LR
    A["📡 外连请求"]
    --> B{"端口 =443 ?"}

    B -->|否| C{"频率 >10/min ?"}
    B -->|是| D{"载荷 >1400B ?"}

    C -->|是| E["🔴 恶意 C2"]
    C -->|否| F["🟢 正常"]

    D -->|是| G{"间隔 <5s ?"}
    D -->|否| H["🟢 正常"]

    G -->|是| I["🔴 恶意 C2"]
    G -->|否| J["🟢 正常"]

    style A fill:#1a2a3a,stroke:#268bd2,stroke-width:2px,color:#fff
    style B fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style C fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style D fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style G fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style E fill:#2d1b1b,stroke:#e74c3c,stroke-width:2px,color:#e74c3c
    style I fill:#2d1b1b,stroke:#e74c3c,stroke-width:2px,color:#e74c3c
    style F fill:#1a2d1a,stroke:#27ae60,stroke-width:2px,color:#27ae60
    style H fill:#1a2d1a,stroke:#27ae60,stroke-width:2px,color:#27ae60
    style J fill:#1a2d1a,stroke:#27ae60,stroke-width:2px,color:#27ae60
```

<div style="margin-top:2px;padding:4px 14px;background:rgba(181,137,0,0.08);border-left:4px solid #b58900;border-radius:4px;">
**本质:** 自动寻找 "最有价值的问题",形成判定链条。
</div>

---

<!-- slide -->

## 什么是 "好特征"?

**网空场景:** 某内网采集了 1000 条外连日志(500 正常 + 500 恶意)

| 特征 | 划分效果 | 评价 |
|------|----------|------|
| **目标端口是否为 443 ?** | 左:450 恶意 +50 正常<br>右:50 恶意 +450 正常 | ✅ **好特征** |
| **协议是否为 TCP ?** | 左:250 恶意 +250 正常<br>右:250 恶意 +250 正常 | ❌ **差特征** |

> **好特征 = 能把 "混杂" 快速降为 "纯净"**

---

<!-- slide -->

## 熵 · 衡量 "混乱程度"

<div class="twocol">

<div style="background:rgba(38,139,210,0.06);padding:10px 16px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

<div style="font-weight:700;color:#268bd2;">📐 公式</div>

\[
H=-\sum p_i \log_2 p_i
\]

</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 16px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

<div style="font-weight:700;color:#268bd2;">📊 直观理解</div>

| 数据状态 | 熵值 |
|----------|------|
| 全是正常流量 | 0(纯净) |
| 正常/恶意各半 | 最大(混乱) |
| 全是恶意流量 | 0(纯净) |

</div>

</div>

<div style="margin-top:8px;padding:10px 16px;background:rgba(38,139,210,0.08);border-left:4px solid #268bd2;border-radius:4px;">
💡 网空含义: 熵越低,规则越精准,误报越少。
</div>

---

<!-- slide -->

## 信息增益 · 特征 "好" 的量化指标

定义:

\[
Gain = H(划分前) - H(划分后)
\]

| 划分效果 | 信息增益 |
|----------|----------|
| 划分后仍然混乱 | 小 |
| 划分后非常纯净 | 大 |

> 翻译成人话: 划分前多乱,划分后多不乱 —— 差值越大,这个特征越值得用。

---

<!-- slide -->

## 决策树算法演进

```mermaid
flowchart LR
    A["CART<br/>1984"]
    --> B["ID3<br/>1986"]
    --> C["C4.5<br/>1993"]
    --> D["Random Forest<br/>2001"]
    --> E["XGBoost<br/>2014"]

    style A fill:#1a2a3a,stroke:#586e75,stroke-width:2px,color:#839496
    style B fill:#1a2a3a,stroke:#268bd2,stroke-width:2px,color:#fff
    style C fill:#1a2a3a,stroke:#268bd2,stroke-width:2px,color:#fff
    style D fill:#1a2a3a,stroke:#586e75,stroke-width:2px,color:#839496
    style E fill:#1a2a3a,stroke:#586e75,stroke-width:2px,color:#839496
```

| 算法 | 年份 | 核心逻辑 |
|------|------|----------|
| ID3 | 1986 | 选择信息增益最大的特征 |
| C4.5 | 1993 | 使用 "增益率" |

**本课程重点: ID3(理解原理) + C4.5(工业常用)**

---

<!-- slide -->

## ID3 的问题:偏爱 "取值多" 的特征

假设某内网采集了 **1000 条外连日志**,每条都有唯一的 **Log ID**

| 特征 | 取值数量 | 信息增益 | 真实价值 |
|------|----------|----------|----------|
| **Log ID** | 1000 个 | 🔥 **最大** | ❌ 毫无价值 |
| **目标端口** | 少量 | 中等 | ✅ 很有价值 |

> ID3 会被 "Log ID" 这种无用特征欺骗 → 过拟合

---

<!-- slide -->

## C4.5 的改进:增益率

**增益率 = 信息增益 ÷ 固有值(惩罚项)**

| 特征 | 信息增益 | 固有值 | 增益率 | 效果 |
|------|----------|--------|--------|------|
| Log ID | 最大 | 最大 | ⬇ 被压低 | 不再被误选 |
| 目标端口 | 中等 | 小 | ⬆ 相对更高 | 公平竞争 |

> **类比:** ID3 是第一代预警系统,容易被 "花哨" 特征欺骗; C4.5 是第二代,加了 "公平性检查",更可靠。

---

<!-- slide -->

## ID3 与 C4.5

| 算法 | 核心逻辑 | 特点 |
|------|----------|------|
| **ID3** | 选择信息增益最大的特征 | 奠基,但偏好取值多的特征 |
| **C4.5** | 使用 "增益率" | 支持连续值/缺失值,工业更常用 |

> **一句话:** ID3 是先驱, C4.5 是升级版。两者差异 ≈ "第一代预警系统" vs "具备抗干扰能力的第二代预警系统"。

---

<!-- slide -->

## 决策树如何生成检测规则?

<div style="font-size:0.7em;color:var(--solarized-base00);margin-bottom:0.5rem;">
从历史数据中自动提取判据的五个步骤
</div>

```mermaid
%%{init: { 'theme': 'base', 'themeVariables': { 'fontSize': '16px' }, 'flowchart': { 'htmlLabels': true, 'nodeSpacing': 15, 'rankSpacing': 20 } } }%%
flowchart LR
    A["📡 已标注数据"]
    --> B["🔍 找最佳特征"]
    --> C["⚙ 生成规则"]
    --> D["🌿 构建完整树"]
    --> E["✅ 输出判据链"]
```

<div style="margin-top:4px;font-size:0.5em;color:var(--solarized-base00);text-align:center;">
步骤详解:历史流量日志(已标注) → 选择最佳判据特征(信息增益最大) → 按阈值切分生成规则节点 → 递归生成子规则构建完整树 → 输出白盒可追溯的判据链
</div>

<div style="margin-top:12px;padding:12px 16px;background:rgba(38,139,210,0.08);border-left:4px solid var(--solarized-blue);border-radius:4px;font-size:0.55em;">
❓ **标注数据从哪来?**
开源威胁情报: VirusTotal、AbuseIPDB 等已标注的 IP/域名黑名单 ·
公开数据集: CIC-IDS、UNSW-NB15 等带有攻击标签的流量数据集 ·
历史告警日志:安全分析师已确认的告警记录
⚠ 标注数据是监督学习的前提。数据质量 > 算法选择。
</div>

---

<!-- slide -->

## Sklearn 实践 · 核心代码

```python
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier

# 1. 生成模拟数据(10 维特征, 2000 样本)
X, y = make_classification(n_samples=2000, n_features=10,
                           n_informative=6, random_state=42)
# 2. 划分训练/测试集
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42)
# 3. 训练决策树(限制深度防过拟合)
model = DecisionTreeClassifier(max_depth=5, random_state=42)
model.fit(X_train, y_train)
# 4. 评估
print(f"Accuracy = {model.score(X_test, y_test):.4f}")
```

典型输出: Accuracy = 0.8833

---

<!-- slide -->

## 核心优势 · 可解释性

```python
from sklearn.tree import export_text
rules = export_text(model, feature_names=[
    'feature_0', 'feature_1', ..., 'feature_9'
])
print(rules)
```

输出:

```text
|--- feature_3 <= 0.75
|   |--- feature_7 <= -0.23
|   |   |--- class: 0
|   |--- feature_7 > -0.23
|   |   |--- feature_1 <= 0.45
|   |   |   |--- class: 1
|   |   |--- feature_1 > 0.45
|   |   |   |--- class: 0
|--- feature_3 > 0.75
|   |--- feature_5 <= 0.32
|   |   |--- class: 1
|   |--- feature_5 > 0.32
|   |   |--- class: 0
```

每条规则都可追溯: 为什么拦截这个 IP ? —— 因为满足规则链 A → B → C。

---

<!-- slide -->

## 决策树 · 优缺点(网空视角)

<div class="twocol">

<div style="background:rgba(133,153,0,0.08);padding:10px 16px;border-radius:8px;border:1px solid rgba(133,153,0,0.3);">

<div style="font-weight:700;color:#859900;">✅ 优点</div>

| 优势 | 网空含义 |
|------|----------|
| 易理解 | 一线人员可直接执行 |
| 可解释 | 指挥员知道 "为什么" |
| 推理快 | 毫秒级,适合端侧部署 |
| 无需 GPU | 边缘节点可直接运行 |

</div>

<div style="background:rgba(220,50,47,0.06);padding:10px 16px;border-radius:8px;border:1px solid rgba(220,50,47,0.25);">

<div style="font-weight:700;color:#dc322f;">⚠ 缺点</div>

| 劣势 | 应对策略 |
|------|----------|
| 易过拟合 | 限制深度 + 剪枝 |
| 对噪声敏感 | 集成方法平滑 |
| 稳定性差 | 随机森林/XGBoost |

</div>

</div>

<div style="margin-top:8px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
💡 网空启示: 深度学习做 "看得准",决策树做 "说得清、跑得快"。战场需要的是 确定性 > 准确率。
</div>

---

<!-- slide -->

## 决策树在网空领域的典型应用

| 场景 | 决策树做什么 |
|------|-------------|
| 🚨 **入侵检测** | 从流量特征提取可执行判据 |
| 🎯 **钓鱼 URL 识别** | 生成 "如果是 → 则拦截" 的规则链 |
| 🧠 **告警降噪** | 判断哪些告警真正值得关注 |
| 🔗 **攻击链还原** | 逐层判定每个环节的恶意概率 |
| 📋 **合规审计** | 提供白盒可追溯的判定依据 |

---

<!-- slide -->

## 随堂思考题

某部内网部署流量检测系统。

**方案 A:** 深度学习模型(准确率 92%,黑盒)

**方案 B:** 决策树模型(准确率 87%,白盒)

作为技术负责人,你倾向哪个?为什么?

---

<!-- slide -->

## 参考答案 · 决策树的价值在哪?

| 考量维度 | 深度学习 | 决策树 |
|----------|----------|--------|
| 准确率 | ✅ 略高 | ⚠ 略低 |
| 可解释性 | ❌ 黑盒 | ✅ 完全透明 |
| 审计追溯 | ❌ 无法追溯 | ✅ 每条规则可追溯 |
| 一线执行 | ❌ 依赖专家解读 | ✅ 直接可操作 |
| 部署门槛 | ❌ 需 GPU 集群 | ✅ 单机/边缘可跑 |
| 合规要求 | ⚠ 难通过 | ✅ 天然满足 |

> **网空核心命题:** 我们要的是 "确定性的可执行规则",而非 "概率性的黑盒判断"。

---

<!-- slide -->

## 本部分总结 · 决策树

<div style="color:#859900;">
✅ 核心思想:用 "最好的问题" 逐层切分数据
✅ 灵魂指标:信息增益 = 混乱减少的程度
✅ 最大优势:规则透明,一线可直接执行
✅ 网空定位:从 "专家经验" 到 "自动判据" 的桥梁
</div>

<div style="margin-top:10px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #268bd2;border-radius:4px;text-align:center;font-size:1.1em;">
💡 规则 ≠ 替代专家 · 规则 = 固化专家经验
</div>

---

<!-- slide -->

## 下一部分预告

<div style="text-align:center;">
📏 K-Means 聚类
当你不确定恶意行为 "长什么样" 的时候
—— 让数据自己 "抱团" 说话
</div>

---
