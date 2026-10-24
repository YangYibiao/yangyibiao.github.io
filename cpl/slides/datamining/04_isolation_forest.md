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
@import "../../css/datamining.css"

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

<h1 style="text-align:center;">孤立森林 · 异常即信号</h1>

<hr class="width50 center">

<h2 style="text-align:center;">当恶意样本极度稀少,连 "规律" 都无从总结的时候</h2>

<div class="bottom8"></div>

<h3 style="text-align:center;">南京大学计算机学院 &nbsp;&nbsp; 杨已彪</h3>

<h4 style="text-align:center;">计算机软件新技术全国重点实验室</h4>

<h4 style="text-align:center;"><a href="mailto:yangyibiao@nju.edu.cn">yangyibiao@nju.edu.cn</a></h4>

<div style="margin-top:26px;text-align:center;font-size:20pt;color:var(--solarized-base00);letter-spacing:3px;">
2026 年 10 月
</div>

---

<!-- slide -->

## 从朴素贝叶斯到孤立森林 · 一个自然的追问

| 朴素贝叶斯帮我们解决了 | 但还有一个问题 |
|-----------------------|---------------|
| 在不确定性下做判断 → 输出概率 | **如果连 "正常/恶意" 的样本都没有呢?** |
| 需要一定数量的历史标注数据 | **0-day 攻击根本没有历史样本** |
| 能回答 "有多大概率是恶意" | **能发现 "从未见过" 的威胁吗?** |

> **核心转折:** 前面的算法都在 "学习规律"。但如果攻击者用的是**从未出现过的新手法**,规律根本不存在 —— 我们只能靠**"异常"**来发现它。

**孤立森林**:不需要标注、不需要历史样本,专门解决 "未知的未知" 问题。

---

<!-- slide -->

## 一个网空场景: 0-day 攻击的发现

某部内网运行正常,每天产生海量流量日志。已部署基于规则的 IDS,但攻击者使用 **0-day 漏洞** 进入内网。

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;margin-top:8px;">

<div style="background:rgba(38,139,210,0.06);padding:14px 16px;border-radius:8px;border:1px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;font-size:0.65em;">❌ 传统方法失效</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">
- 规则库中没有该攻击的特征
- 历史数据中没有标注样本
- 决策树/贝叶斯**无法训练**
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:14px 16px;border-radius:8px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.65em;">✅ 孤立森林的思路</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">
- 不需要知道 "恶意" 长什么样
- 只需要知道 **"正常" 长什么样**
- 发现 **"不像正常"** 的行为 → 异常
</div>

</div>

</div>

<div style="margin-top:8px;padding:6px 14px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.45em;text-align:center;">
🎯 **本部分目标:** 在没有任何标注样本的情况下,用 **"异常即信号"** 的思路发现未知威胁。
</div>

---

<!-- slide -->

## 什么是异常检测?

> **异常检测 = 在海量数据中发现 "少数派"**

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;margin-top:8px;">

<div style="background:rgba(133,153,0,0.08);padding:12px 16px;border-radius:8px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.65em;">✅ 正常数据</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">
- 大量出现(**99%**)
- 彼此相似
- 符合预期模式
</div>

</div>

<div style="background:rgba(220,50,47,0.08);padding:12px 16px;border-radius:8px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#e74c3c;font-size:0.65em;">🚨 异常数据</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">
- 极少出现(**1%**)
- 与主流不同
- 偏离预期模式
</div>

</div>

</div>

<div style="margin-top:8px;padding:6px 14px;background:rgba(231,76,60,0.06);border-left:4px solid #e74c3c;border-radius:4px;font-size:0.45em;">
💡 **网空含义:** 0-day 攻击、未知恶意软件、APT 渗透 —— 它们的行为模式一定与 "正常" 不同。找到这个 "不同",就找到了威胁线索。
</div>

---

<!-- slide -->

## 孤立森林的核心思想

> **异常点更容易被 "隔离" 出来。**

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:16px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #586e75;">
<div style="font-weight:700;color:#f39c12;font-size:0.65em;">👥 直观类比</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">
房间里有 **100 个人**:

- 99 个人站在一起(**正常群体**)
- 1 个人站在角落(**异常个体**)

**问题:** 谁最容易被发现?

**答案:** 角落里的那个人。
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #586e75;">
<div style="font-weight:700;color:#27ae60;font-size:0.65em;">🎯 算法映射</div>

<div style="font-size:0.5em;line-height:1.8;margin-top:4px;">

| 直觉 | 算法 |
|------|------|
| 人群聚集 | **正常点**:在数据空间中密集分布 |
| 角落孤立 | **异常点**:远离数据密集区域 |
| 容易发现 | **路径短**:异常点容易被随机切分隔离 |

</div>

</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;margin-top:6px;">

<div style="background:rgba(133,153,0,0.08);padding:8px 12px;border-radius:6px;border-left:4px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.5em;">🟢 正常点</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">
**聚集在一起** → 需要多次切分才能分开
</div>
</div>

<div style="background:rgba(220,50,47,0.08);padding:8px 12px;border-radius:6px;border-left:4px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;font-size:0.5em;">🔴 异常点</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">
**远离群体** → 几次切分就能单独隔离
</div>
</div>

</div>

<div style="margin-top:6px;padding:4px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.4em;text-align:center;">
💡 **孤立森林就是把这个直觉变成了算法。** 无需标注、无需先验知识,通过随机切分寻找容易被隔离的点。
</div>

---

<!-- slide -->

## 孤立森林的核心思想 · 图解

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #27ae60;text-align:center;">
<div style="font-weight:700;color:#27ae60;font-size:0.65em;">🟢 正常点(聚集)</div>

<div style="font-size:1.6em;line-height:1.8;letter-spacing:4px;margin-top:4px;font-weight:300;">
⬤ ⬤ ⬤ ⬤ ⬤
</div>

<div style="font-size:0.45em;color:var(--solarized-base00);margin-top:2px;">
密集分布 · 相互靠近
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #e74c3c;text-align:center;">
<div style="font-weight:700;color:#e74c3c;font-size:0.65em;">🔴 异常点(孤立)</div>

<div style="font-size:1.6em;line-height:1.8;letter-spacing:8px;margin-top:4px;">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲
</div>

<div style="font-size:0.45em;color:var(--solarized-base00);margin-top:2px;">
远离群体 · 单独存在
</div>

</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.5em;">✂ 正常点:需要很多刀</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">
密集区域 → 多次随机切分才能分开
</div>
<div style="font-size:0.8em;color:#27ae60;margin-top:2px;">
⬤⬤⬤⬤⬤ → ⬤⬤ → ⬤ → ✅ 隔离
</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;font-size:0.5em;">✂ 异常点:几刀就孤立</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">
远离群体 → 随机切分很快单独分离
</div>
<div style="font-size:0.8em;color:#e74c3c;margin-top:2px;">
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▲ → ✂ → ✅ 隔离
</div>
</div>

</div>

<div style="margin-top:6px;padding:4px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.4em;text-align:center;">
💡 **关键直觉:** 异常点远离群体 → 更容易被随机切分 "隔离" 出来 → 路径更短
</div>

---

<!-- slide -->

## 为什么叫 "森林"?

> **孤立森林 = 多棵 "孤立树" 的集合**

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;margin-top:8px;">

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;font-size:0.65em;">🌲 孤立树(单棵)</div>

<div style="font-size:0.45em;line-height:1.8;margin-top:4px;">
1. 随机选一个**特征**
2. 随机选一个**切分点**
3. 把数据分成**左右两份**
4. **递归重复**,直到每个点都被隔离
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:8px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.65em;">🌳 孤立森林(多棵)</div>

<div style="font-size:0.45em;line-height:1.8;margin-top:4px;">
- 构建**很多棵**孤立树(默认 **100 棵**)
- 每棵树用**不同的随机切分**
- 综合所有树的结果 → **更稳定可靠**
</div>

</div>

</div>

<div style="margin-top:6px;padding:6px 14px;background:rgba(243,156,18,0.06);border-left:4px solid #f39c12;border-radius:4px;font-size:0.4em;">
💡 **类比:** 单棵树的判断可能有偏差,但多棵树综合判断就很可靠。这就是 **"集成学习"** 的思路 —— 集中多人的智慧,比依赖一个人更可靠。
</div>

---

<!-- slide -->

## 孤立树构建过程

```mermaid
%%{init: { 'theme': 'base', 'themeVariables': { 'fontSize': '15px' }, 'flowchart': { 'htmlLabels': true, 'nodeSpacing': 12, 'rankSpacing': 18 } } }%%
flowchart LR
    A["📊 原始数据"]
    --> B["🎲 随机选特征"]
    --> C["✂ 随机选切分点"]
    --> D["📦 切分为两组"]
    --> E{"是否隔离?"}
    E -->|否| B
    E -->|是| F["✅ 记录路径长度"]

    style A fill:#1a2a3a,stroke:#268bd2,stroke-width:2px,color:#fff
    style B fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style C fill:#1a2a3a,stroke:#f39c12,stroke-width:2px,color:#fff
    style D fill:#1a2a3a,stroke:#268bd2,stroke-width:2px,color:#fff
    style E fill:#1a2a3a,stroke:#e74c3c,stroke-width:2px,color:#fff
    style F fill:#1a2d1a,stroke:#27ae60,stroke-width:2px,color:#27ae60
```

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;margin-top:6px;font-size:0.4em;">

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #586e75;">
🔑 **关键步骤:**

1. 随机选一个特征
2. 随机选一个切分点
3. 将数据分成左右两份
</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #586e75;">
⏱ **终止条件:**

样本被完全隔离 → 记录路径长度

否则 → 递归重复上述过程
</div>

</div>

---

<!-- slide -->

## 路径长度 · 核心指标

**一个具体例子:外连频率**

<div style="background:rgba(38,139,210,0.06);padding:4px 10px;border-radius:6px;border:1px solid #586e75;margin-top:4px;font-size:0.45em;">
<div style="font-weight:700;color:#f39c12;font-size:0.85em;text-align:center;margin-bottom:2px;">✂ 随机切分过程对比</div>

| 步骤 | 数据(外连频率,次/小时) | 说明 |
|------|--------------------------|------|
| 原始数据 | [2, 3, 3, 4, 5, 5, 6, 7, 8, **25**] | 9 台正常(2~8),1 台异常(25) |
| 第 1 刀(随机) | 切在 **5** → [2,3,3,4,5,5] ｜ [6,7,8,**25**] | 异常点仍在右侧组 |
| 第 2 刀(随机) | 切在 **7** → [6,7] ｜ [8,**25**] | 继续切分右侧组 |
| 第 3 刀(随机) | 切在 **10** → [8] ｜ [**25**] | 异常点被单独分离 ✅ |

</div>

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:6px;margin-top:4px;font-size:0.35em;">

<div style="background:rgba(38,139,210,0.06);padding:3px 8px;border-radius:4px;border-left:4px solid #27ae60;">
**为什么正常点难切?**

- 位于密集区域(2~8)
- 周围全是邻居,随机切分很难单独切出一个

👉 需要很多刀才能分开
</div>

<div style="background:rgba(38,139,210,0.06);padding:3px 8px;border-radius:4px;border-left:4px solid #e74c3c;">
**为什么异常点容易切?**

- 位于稀疏区域(25)
- 远离所有邻居,随机切分很容易单独切出

👉 少数几刀就能隔离
</div>

</div>

<div style="margin-top:3px;padding:2px 8px;background:rgba(38,139,210,0.06);border-left:3px solid #268bd2;border-radius:4px;font-size:0.45em;text-align:center;">
💡 异常点不是 "被识别" 出来的,而是 "更容易被随机切分孤立" 出来的。
</div>

---

<!-- slide -->

## 异常得分 · 最终输出

将路径长度转换为 异常得分(0~1):

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:8px;margin-top:6px;">

<div style="background:rgba(220,50,47,0.08);padding:8px;border-radius:6px;border:1px solid #e74c3c;text-align:center;font-size:0.55em;">
🔴 得分接近 **1**
异常可能性高
→ 值得深入排查
</div>

<div style="background:rgba(38,139,210,0.10);padding:8px;border-radius:6px;border:1px solid #f39c12;text-align:center;font-size:0.55em;">
🟡 得分接近 **0.5**
边界区域
→ 可进一步研判
</div>

<div style="background:rgba(133,153,0,0.08);padding:8px;border-radius:6px;border:1px solid #27ae60;text-align:center;font-size:0.55em;">
🟢 得分接近 **0**
高度正常
→ 无需关注
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 12px;border-radius:6px;border-left:4px solid #268bd2;margin-top:4px;font-size:0.5em;">
💡 **网空含义:** 异常得分不是 "是不是恶意",而是 "有多不像正常"。得分越高,越值得深入调查。
</div>

---

<!-- slide -->

## Sklearn 实践 · 生成数据 + 训练模型

```python
import numpy as np
from sklearn.ensemble import IsolationForest

# 1. 生成正常数据(1000 个,集中在原点附近)
normal = np.random.randn(1000, 2)
# 2. 生成异常数据(20 个,远离正常区域)
outliers = np.random.uniform(low=6, high=8, size=(20, 2))
# 3. 合并数据
X = np.vstack([normal, outliers])
# 4. 训练孤立森林
model = IsolationForest(contamination=0.02, random_state=42)
model.fit(X)
```

contamination 参数: 预期异常比例,这里设为 2% (20/1020 ≈ 2%)

---

<!-- slide -->

## Sklearn 实践 · 预测与得分

```python
# 1. 预测异常(-1=异常, 1=正常)
pred = model.predict(X)
print(np.unique(pred, return_counts=True))
# 输出: (array([-1,  1]), array([20, 1000]))

# 2. 查看异常得分(值越小越异常)
scores = model.score_samples(X)
print(scores[:10])

# 3. 查看 Top 5 异常点
top5_idx = np.argsort(scores)[:5]
print(f"Top 5 异常索引: {top5_idx}")
print(f"Top 5 异常得分: {scores[top5_idx]}")
```

关键理解: 孤立森林的得分是负值,越负越异常。实际使用时可以取负值或归一化到 0-1 区间。

---

<!-- slide -->

## 孤立森林 · 优缺点(网空视角)

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;font-size:0.55em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #27ae60;">
✅ 核心优势

| 优势 | 网空价值 |
|------|----------|
| 无需标签 | 不需要标注正常/恶意样本 |
| 发现未知威胁 | 能检测 0-day、新型攻击 |
| 极快 | 海量日志分钟级完成异常筛选 |
| 高维友好 | 可处理数千维特征 |
| 无需先验知识 | 不需要提前知道 "恶意长什么样" |

</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #e74c3c;">
⚠ 固有局限

| 局限 | 网空应对 |
|------|----------|
| 只能发现 "不像正常" | 需要人工研判确认是否为攻击 |
| 无法区分攻击类型 | 只能提供 "可疑候选",不能替代深入分析 |
| 对参数敏感 | 需要根据数据特点调参(contamination 等) |

</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;text-align:center;">
💡 **定位:** 孤立森林不是 "判官",而是 "筛选器" —— 从海量数据中圈出少量可疑目标,让专家聚焦。
</div>

---

<!-- slide -->

## 孤立森林在网空领域的典型应用

| 场景 | 孤立森林做什么 | 为什么选它 |
|------|---------------|-----------|
| 🚨 **0-day 攻击发现** | 从流量中标记行为异常的主机 | 不需要已知攻击样本 |
| 🔗 **APT 检测** | 发现长时间潜伏的异常行为链 | 能发现 "慢速" 异常 |
| 📊 **日志异常分析** | 从海量日志中筛选可疑条目 | 极快,适合大数据量 |
| 🌐 **DNS 隧道检测** | 标记异常的 DNS 请求模式 | 高维特征处理能力强 |
| 🧠 **未知恶意软件发现** | 从进程行为中圈出异常 | 不需要恶意软件签名 |

---

<!-- slide -->

## 随堂思考题

某部内网部署了异常检测系统。

数据: 1 万条流量日志(无任何标注)

已知: 其中可能存在 0-day 攻击的痕迹,但不知道有多少

**方案 A:** 用决策树训练(需要人工标注数据)

**方案 B:** 用孤立森林检测(无需标注)

问题: 你选择哪个方案?孤立森林发现异常后,下一步应该做什么?

---

<!-- slide -->

## 如何选择? —— 方案对比

**选择:方案 B(孤立森林)**

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:10px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #268bd2;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">📌 优势</div>
<div style="font-size:0.5em;font-weight:700;color:#268bd2;margin-top:2px;">无需标注</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">0-day 攻击无历史样本,监督模型无法训练</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #27ae60;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">📌 优势</div>
<div style="font-size:0.5em;font-weight:700;color:#27ae60;margin-top:2px;">快速筛选</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">从 1 万条中圈出可疑 TOP 10-20</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #f39c12;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">📌 优势</div>
<div style="font-size:0.5em;font-weight:700;color:#f39c12;margin-top:2px;">人机协同</div>
<div style="font-size:0.4em;color:var(--solarized-base00);margin-top:2px;">分析师聚焦少量候选,效率提升 100 倍</div>
</div>

</div>

<div style="display:flex;align-items:center;justify-content:center;gap:10px;margin-top:6px;padding:6px 14px;background:rgba(38,139,210,0.06);border-radius:6px;border:1px solid rgba(38,139,210,0.1);font-size:0.5em;">
<div style="font-weight:700;color:#268bd2;">🌲 孤立森林</div>
<div style="color:var(--solarized-base00);">→ 初筛(10-20 条)</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">↓</div>
<div style="font-weight:700;color:#f39c12;">👤 分析师</div>
<div style="color:var(--solarized-base00);">→ 逐条研判</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">↓</div>
<div style="font-weight:700;color:#27ae60;">✅ 确认攻击</div>
<div style="color:var(--solarized-base00);">→ 提取特征 → 更新规则库</div>
</div>

<div style="margin-top:4px;padding:3px 10px;background:rgba(231,76,60,0.06);border-left:3px solid #e74c3c;border-radius:4px;font-size:0.45em;text-align:center;">
🎯 **核心价值:** 孤立森林做 "初筛",专家做 "终判"。从 1 万条聚焦到 10 条,让专家的工作从 "大海捞针" 变成 "精准打击"。
</div>

---

<!-- slide -->

## 本部分总结 · 孤立森林

<div style="display:grid;grid-template-columns:1fr 1fr;gap:8px;font-size:0.6em;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #268bd2;">
💡 核心思想
异常点更容易被隔离 — 异常即信号
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #f39c12;">
🔑 关键区别
无需标注 — 不需要任何正常/恶意样本
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #27ae60;">
📊 核心指标
路径长度:异常点路径短,正常点路径长
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #e74c3c;">
🎯 网空定位
从 "已知威胁检测" 到 "未知威胁发现" 的认知跃迁
</div>

</div>

<div style="margin-top:8px;padding:8px 14px;background:rgba(38,139,210,0.08);border-radius:6px;text-align:center;font-size:0.7em;border:1px solid rgba(38,139,210,0.15);">
孤立森林不是 "判官",而是 "筛选器" —— 从海量数据中圈出可疑目标,让专家聚焦。
</div>

---

<!-- slide -->

## 综合回顾 · 四种思维 · 四把武器

| 遇到的情况 | 任务 | 选用武器 |
|------------|------|----------|
| 已知威胁,需要可执行的规则 | 分类 | 📜 决策树 |
| 未知威胁,没有标注,找异常群体 | 聚类 | 📏 K-Means |
| 判断概率,辅助决策 | 概率分类 | 🎲 朴素贝叶斯 |
| 从未见过的 0-day | 异常检测 | 🚨 孤立森林 |

<div style="display:flex;align-items:center;justify-content:center;gap:10px;margin-top:10px;padding:8px 16px;background:rgba(38,139,210,0.06);border-radius:6px;border:1px solid rgba(38,139,210,0.1);font-size:0.45em;">
<div style="font-weight:700;color:#268bd2;">📜 决策树</div>
<div style="color:var(--solarized-base00);">规则 · 有标注</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">→</div>
<div style="font-weight:700;color:#f39c12;">📏 K-Means</div>
<div style="color:var(--solarized-base00);">距离 · 无标注</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">→</div>
<div style="font-weight:700;color:#27ae60;">🎲 朴素贝叶斯</div>
<div style="color:var(--solarized-base00);">概率 · 可信度</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">→</div>
<div style="font-weight:700;color:#e74c3c;">🚨 孤立森林</div>
<div style="color:var(--solarized-base00);">隔离 · 未知威胁</div>
</div>

> **一句话记忆:** 规则找判据,距离找团伙,概率算风险,孤立抓异常。

---

<!-- slide -->

## 课程总结

今天一起走过四种思维:

✅ 📜 决策树 —— 从 "专家经验" 到 "自动判据"

✅ 📏 K-Means —— 没有答案时,让数据自己 "抱团"

✅ 🎲 朴素贝叶斯 —— 用概率量化不确定性

✅ 🚨 孤立森林 —— 异常本身就是信号

> 今天这四种是 "思维原型" —— 具体算法原理的展开,后续课程还会继续深入。

<div style="margin-top:6px;text-align:center;font-size:1.2em;font-weight:600;color:#f39c12;">
从问题出发选择方法
<span style="color:#888;font-weight:400;">而不是</span>
从算法出发寻找问题
</div>

---

<!-- slide -->

## 结束语

<div style="text-align:center;margin-top:60px;">
经典算法的价值,不是让机器替代思考,
而是帮助我们从海量数据中发现规律、
从确定到不确定、从已知到未知。

**新技术层出不穷,但经典思想历久弥新。**

<br>
<br>

### 谢谢大家!

<br>

Q & A
</div>

---
