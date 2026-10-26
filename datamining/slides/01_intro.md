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

<div class="bottom8"></div>

<h1 style="text-align:center;">经典数据挖掘算法</h1>

<hr class="width50 center">

<h2 style="text-align:center;">从规则发现到异常检测</h2>

<div class="bottom8"></div>

<h3 style="text-align:center;">南京大学计算机学院 &nbsp;&nbsp; 杨已彪</h3>

<h4 style="text-align:center;">计算机软件新技术全国重点实验室</h4>

<h4 style="text-align:center;"><a href="mailto:yangyibiao@nju.edu.cn">yangyibiao@nju.edu.cn</a></h4>

<div style="margin-top:26px;text-align:center;font-size:20pt;color:var(--solarized-base00);letter-spacing:3px;">
2026 年 10 月
</div>

---

<!-- slide -->

## 一个真实的网空场景

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:10px;font-size:1.1em;">
<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #268bd2;">
### 📡 数据态势

- 某内网:数千个监测节点
- 日产生日志:**千万级**
- 告警类型:上百类
- 状态变化:毫秒级高频

</div>
<div style="background:rgba(203,75,22,0.08);padding:10px 14px;border-radius:6px;border:1px solid rgba(203,75,22,0.45);">
### 🚨 指挥员要回答

- 哪些告警**最致命**,必须优先处置?
- 哪些行为**从未见过**,可能是 0-day ?
- 如何在**30 秒内**给出辅助判断?

</div>
</div>

<div style="margin-top:10px;padding:12px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;font-size:0.9em;">
🎯 数据规模已经远超人工处理能力 → **算法不是选择,是刚需**
</div>

---

<!-- slide -->

## 人工分析 vs 算法分析

假设:每天 **1000 万条日志**,查看一条需要 **1 秒**

<div style="display:grid;grid-template-columns:1fr 1fr;gap:14px;margin-top:12px;">

<div style="background:rgba(203,75,22,0.08);padding:10px 16px;border-radius:8px;border-left:4px solid #cb4b16;text-align:center;">
<div style="font-size:0.7em;color:var(--solarized-base00);">人工查看 1000 万条日志</div>
<div style="font-size:1.6em;font-weight:700;color:#cb4b16;line-height:1.35;">115 天</div>
<div style="font-size:0.65em;color:var(--solarized-base00);">1000 万条 × 1 秒/条 ÷ 86,400 秒/天 ≈ 115.7 天</div>
</div>

<div style="background:rgba(220,50,47,0.08);padding:10px 16px;border-radius:8px;border-left:4px solid #dc322f;text-align:center;">
<div style="font-size:0.7em;color:var(--solarized-base00);">攻击者完成一次渗透</div>
<div style="font-size:1.6em;font-weight:700;color:#dc322f;line-height:1.35;">&lt; 24 小时</div>
<div style="font-size:0.65em;color:var(--solarized-base00);">从入侵到得手,平均不到一天</div>
</div>

</div>

<div style="margin-top:10px;padding:12px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
**结论:** 人追不上数据,必须让算法先跑一遍,人来做 "最后 100 米" 的决策。
</div>

---

<!-- slide -->

## 从问题出发,而不是从算法出发

**既然必须用算法,选哪一种?** 先看人类专家做的四件事:

<div style="margin-top:12px;font-size:0.95em;">

<div style="background:rgba(38,139,210,0.06);padding:7px 16px;border-radius:8px;margin-bottom:8px;">
👨‍🔬 发现规律 (观察) &nbsp;&nbsp;<span style="color:#b58900;font-weight:700;">⟶</span>&nbsp;&nbsp; 🤖 **自动**发现规律
</div>

<div style="background:rgba(38,139,210,0.06);padding:7px 16px;border-radius:8px;margin-bottom:8px;">
👨‍🔬 总结经验 (归纳) &nbsp;&nbsp;<span style="color:#b58900;font-weight:700;">⟶</span>&nbsp;&nbsp; 🤖 **自动**学习经验
</div>

<div style="background:rgba(38,139,210,0.06);padding:7px 16px;border-radius:8px;margin-bottom:8px;">
👨‍🔬 制定规则 (经验) &nbsp;&nbsp;<span style="color:#b58900;font-weight:700;">⟶</span>&nbsp;&nbsp; 🤖 **自动**生成规则
</div>

<div style="background:rgba(38,139,210,0.06);padding:7px 16px;border-radius:8px;">
👨‍🔬 识别异常 (直觉) &nbsp;&nbsp;<span style="color:#b58900;font-weight:700;">⟶</span>&nbsp;&nbsp; 🤖 **自动**识别异常
</div>

</div>

<div style="margin-top:10px;padding:14px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
🎯 算法 ≠ 替代专家,而是 **扩展专家能力的 "数字参谋"**
</div>

---

<!-- slide -->

## 四种思维 · 四把 "战术武器"

**数据挖掘的四类经典问题,各选一个代表性算法**

<div style="display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:12px;font-size:0.8em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border-left:4px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;">📜 规则思维</div>
核心问题: 如何自动判定?
**决策树** · 恶意流量判据提取
</div>

<div style="background:rgba(203,75,22,0.08);padding:10px 14px;border-radius:8px;border-left:4px solid #cb4b16;">
<div style="font-weight:700;color:#cb4b16;">📏 距离思维</div>
核心问题: 谁和谁 "像"?
**K-Means** · 僵尸网络主机群发现
</div>

<div style="background:rgba(211,54,130,0.06);padding:10px 14px;border-radius:8px;border-left:4px solid #d33682;">
<div style="font-weight:700;color:#d33682;">🎲 概率思维</div>
核心问题: 可能性多大?
**朴素贝叶斯** · 邮件/URL 先验筛查
</div>

<div style="background:rgba(220,50,47,0.08);padding:10px 14px;border-radius:8px;border-left:4px solid #dc322f;">
<div style="font-weight:700;color:#dc322f;">🚨 异常思维</div>
核心问题: 谁 "格格不入"?
**孤立森林** · 未知威胁/0-day 发现
</div>

</div>

<div style="margin-top:10px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;font-size:1.1em;">
💡 **一句话记忆:** 规则找判据,距离找团伙,概率算风险,孤立抓异常。
</div>

---

<!-- slide -->

## 数据挖掘 vs 机器学习 · 区别

**四把武器都来自数据挖掘。它和常听到的 "机器学习" 是什么关系?** 同一个数据,两种目标 —— 以 "用户会不会流失?" 为例

<div class="twocol" style="font-size:0.9em;">

<div style="background:rgba(38,139,210,0.06);padding:14px 18px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

### 🤖 机器学习 · 预测未来

> 这个用户会流失吗?

输出:会 / 不会

关注:

- 准确率
- 泛化能力

</div>

<div style="background:rgba(133,153,0,0.08);padding:14px 18px;border-radius:8px;border:1px solid rgba(133,153,0,0.3);">

### 🔍 数据挖掘 · 发现规律

> 哪些用户容易流失?为什么?

输出:流失人群画像、流失因素

关注:

- 知识发现
- 可解释性

</div>

</div>

<div style="margin-top:8px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
💡 **一句话:** 机器学习求 "预测得准",数据挖掘求 "发现有规律"。
</div>

---

<!-- slide -->

## 数据挖掘 vs 机器学习 · 联系

<div class="twocol">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border:1px solid rgba(38,139,210,0.2);">

### 📚 学科视角 · 包含关系

<div style="text-align:center;font-size:0.95em;font-weight:700;color:#268bd2;line-height:1.3;">
人工智能<br>↓<br>机器学习<br>↓<br>数据挖掘
</div>

<div style="font-size:0.8em;">
机器学习包含数据挖掘 —— 数据挖掘是机器学习的**应用领域**。
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border:1px solid rgba(38,139,210,0.2);">

### 🛠 项目视角 · 完整过程

<div style="font-size:0.85em;">
机器学习算法(建模) → 领域知识(解释) → 可视化(呈现) → 产出**知识**
</div>

<div style="margin-top:8px;padding:8px 12px;background:rgba(38,139,210,0.06);border-left:3px solid #268bd2;border-radius:4px;font-size:0.7em;">
**例:** 孤立森林圈出异常主机 → 安全经验判定 "C2 心跳" → 态势图呈现 → 可行动的知识。
</div>

</div>

</div>

<div style="margin-top:6px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
🎯 **本课程定位:** 本课程要讲的经典算法,正是机器学习最核心的方法,也是数据挖掘 "发现规律" 的常用武器。
</div>

---

<!-- slide -->

## 大模型时代,为什么还学 "经典数据挖掘"?

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;font-size:0.8em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:8px;border-left:4px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;">1 结构化数据仍是主流</div>
日志、传感器、告警 —— 都是表格,不是自然语言
→ 经典算法原生适配,无需微调
</div>

<div style="background:rgba(211,54,130,0.06);padding:10px 14px;border-radius:8px;border-left:4px solid #d33682;">
<div style="font-weight:700;color:#d33682;">2 可解释性是刚需</div>
决策链路必须透明,不能给 "黑盒结论"
→ 指挥员要的是 "为什么",不是 "是什么"
</div>

<div style="background:rgba(203,75,22,0.08);padding:10px 14px;border-radius:8px;border-left:4px solid #cb4b16;">
<div style="font-weight:700;color:#cb4b16;">3 响应速度决定胜负</div>
推理以**毫秒**计,无需 GPU
→ 端侧/边缘节点直接部署
</div>

<div style="background:rgba(133,153,0,0.08);padding:10px 14px;border-radius:8px;border-left:4px solid #859900;">
<div style="font-weight:700;color:#859900;">4 理解原理才能创新</div>
不懂底层原理,只能在别人框架上调参
→ 面对新型威胁,能自己设计检测方法
</div>

</div>

<div style="margin-top:8px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
💡 **一句话:** 深度学习解决 "看得准",经典算法解决 "说得清、跑得快"。战场需要的是 **确定性 > 准确率**。
</div>

---

<!-- slide -->

## 大模型 ≠ 替代,而是 "站在经典肩膀上"

<div class="twocol" style="font-size:0.95em;">

<div style="background:rgba(38,139,210,0.06);padding:12px 16px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

### 🔬 大模型的底层,仍是经典

<div style="margin-top:8px;line-height:1.6;">
<span style="font-weight:700;color:#268bd2;">反向传播</span> <span style="color:#b58900;font-weight:700;">⟶</span> 梯度下降 + 链式法则(1986)
<br>
<span style="font-weight:700;color:#268bd2;">注意力机制</span> <span style="color:#b58900;font-weight:700;">⟶</span> 加权求和 + softmax
<br>
<span style="font-weight:700;color:#268bd2;">自回归生成</span> <span style="color:#b58900;font-weight:700;">⟶</span> 每一步都是重复做分类
<br>
<span style="font-weight:700;color:#268bd2;">Dropout</span> <span style="color:#b58900;font-weight:700;">⟶</span> 集成学习的投票思想
<br>
<span style="font-weight:700;color:#268bd2;">RLHF</span> <span style="color:#b58900;font-weight:700;">⟶</span> 强化学习的奖励优化
</div>

</div>

<div style="background:rgba(181,137,0,0.10);padding:12px 16px;border-radius:8px;border:1px solid rgba(181,137,0,0.3);">

### 🎯 经典是地基,大模型是高楼

- 数学基础没变:线性代数、概率论、微积分
- 优化逻辑没变:梯度下降仍是最核心的训练方式
- 评估方式没变:准确率、召回率、F1 仍在用

</div>

</div>

<div style="margin-top:10px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
💡 不了解经典,就无法理解大模型为什么有效、何时会失效 —— 更无法在需要时**创新**。
</div>

---

<!-- slide -->

## 从 "专用工具" 到 "通用引擎"

<div class="twocol" style="font-size:0.85em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 16px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

### 📐 经典算法范式

- 为**每个任务**单独设计特征
- 为**每个任务**单独选择模型
- 需要**标注数据**训练
- 输出**确定性规则**或**精确标签**
- 代表:决策树、K-Means、朴素贝叶斯、孤立森林

</div>

<div style="background:rgba(203,75,22,0.08);padding:10px 16px;border-radius:8px;border:1px solid rgba(203,75,22,0.3);">

### 🧠 大模型范式

- **一个模型**覆盖多种任务
- **自监督预训练** + 少量微调
- 自动学习**隐式特征表示**
- 输出**概率性生成**内容
- 代表:GPT、BERT、LLaMA

</div>

</div>

<div style="margin-top:8px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;">
💡 **范式变了,但数学没变。** 大模型是对经典原理的**规模化复用**,而非**颠覆**。
</div>

---

<!-- slide -->

## 两者互补,而非替代

<div class="twocol">

<div style="background:rgba(38,139,210,0.06);padding:10px 16px;border-radius:8px;border:1px solid rgba(38,139,210,0.25);">

### 🎯 经典 · 精确制导武器

| 优势 | 场景 |
|------|------|
| 推理**毫秒级** | 实时检测、端侧部署 |
| **完全可解释** | 审计追溯、合规要求 |
| 无需 GPU | 边缘节点、嵌入式设备 |
| 规则透明 | 一线人员可直接执行 |

</div>

<div style="background:rgba(203,75,22,0.08);padding:10px 16px;border-radius:8px;border:1px solid rgba(203,75,22,0.3);">

### 🧠 大模型 · 战略研判系统

| 优势 | 场景 |
|------|------|
| **语义理解**强 | 威胁情报分析、报告生成 |
| **泛化能力**强 | 零样本/少样本任务 |
| 处理**非结构化** | 文本、代码、对话 |
| **创造性**输出 | 攻击路径推演、辅助决策 |

</div>

</div>

<div style="margin-top:10px;padding:10px 16px;background:rgba(181,137,0,0.10);border-left:4px solid #b58900;border-radius:4px;text-align:center;">
🎯 **网空战场上,两者协同:** 大模型做 "宏观研判" → 经典算法做 "精确验证" → **人做最终决策**
</div>

---

<!-- slide -->

## 数据挖掘的 "六步作战流程"

<div style="font-size:0.72em;color:var(--solarized-base00);margin-bottom:2px;">武器选好了,一仗具体怎么打?</div>

```mermaid
%%{init: { 'theme': 'base', 'themeVariables': { 'fontSize': '20px', 'fontFamily': 'LXGWWenKai, \"Noto Sans SC\", sans-serif' }, 'flowchart': { 'nodeSpacing': 16, 'rankSpacing': 30 } } }%%
flowchart LR
    A["🎯 理解任务<br/>要打什么仗?"]
    --> B["📥 数据采集<br/>有什么情报?"]
    --> C["⚙ 数据处理<br/>清洗、对齐、降噪"]
    --> D["🧠 模型分析<br/>选哪把武器?"]
    --> E["📊 结果解释<br/>可信吗?为什么?"]
    --> F["🚀 辅助决策<br/>怎么行动?"]
```

<div style="margin-top:16px;padding:12px 16px;background:rgba(203,75,22,0.08);border-left:4px solid #cb4b16;border-radius:4px;">
⚠ 经验规律: 数据处理(C 步骤)通常占项目 **80%** 的时间。算法选型只占 **20%**。
</div>

---

<!-- slide -->

## 今天课程路线图 · 2.5 小时火力分配

| 时段 | 内容 | 战术目标 |
|------|------|----------|
| 0-15' | 开场总览(当前页 → 结束) | 建立全局认知框架 |
| 15'-40' | 📜 决策树 · 规则思维 | 能从日志中 "榨出" 可执行判据 |
| 40'-65' | 📏 K-Means · 距离思维 | 能发现 "无形" 的主机群组 |
| 65'-90' | 🎲 朴素贝叶斯 · 概率思维 | 能给出威胁的 "先验概率" |
| 90'-115' | 🚨 孤立森林 · 异常思维 | 能找到 "从未见过" 的威胁 |
| 115'-135' | 综合回顾 + 互动答疑 | 打通四把武器协同使用 |
| 135'-150' | 总结收尾 | 从问题出发选择方法 |

<div style="margin-top:10px;padding:8px 16px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.7em;">
🎯 **贯穿案例:** 某部内网异常流量事件 —— 每讲完一个算法,回来 "拼一块拼图"。
</div>

---

<!-- slide -->

## 希望大家带走什么?

<div class="twocol" style="font-size:1em;">

<div style="background:rgba(220,50,47,0.06);padding:12px 18px;border-radius:8px;border:1px solid rgba(220,50,47,0.25);">
<div style="font-weight:700;color:#dc322f;">❌ 不带走的</div>

- 背住数学公式
- 记住 Python 代码

</div>

<div style="background:rgba(133,153,0,0.08);padding:12px 18px;border-radius:8px;border:1px solid rgba(133,153,0,0.3);">
<div style="font-weight:700;color:#859900;">✅ 带走的</div>

- 理解 "问题-算法" 的匹配关系
- 理解每种算法背后的 "思维原型"
- 在真实场景中,能独立完成武器选型

</div>

</div>

<div style="margin-top:10px;text-align:center;font-size:1.3em;font-weight:600;color:#b58900;">
从问题出发选择方法
<span style="color:#888;font-weight:400;">而不是</span>
从算法出发寻找问题
</div>

---

