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

<h1 style="text-align:center;">朴素贝叶斯 · 从规则到概率</h1>

<hr class="width50 center">

<h2 style="text-align:center;">当判定需要 "可信度" 而非 "是/否" 的时候</h2>

<div class="bottom8"></div>

<h3 style="text-align:center;">南京大学计算机学院 &nbsp;&nbsp; 杨已彪</h3>

<h4 style="text-align:center;">计算机软件新技术全国重点实验室</h4>

<h4 style="text-align:center;"><a href="mailto:yangyibiao@nju.edu.cn">yangyibiao@nju.edu.cn</a></h4>

<div style="margin-top:26px;text-align:center;font-size:20pt;color:var(--solarized-base00);letter-spacing:3px;">
2026 年 10 月
</div>

---

<!-- slide -->

## 从决策树到朴素贝叶斯 · 一个自然的追问

| 决策树帮我们解决了 | 但还有一个问题 |
|-------------------|---------------|
| 从数据中提取**可执行规则** | **不是所有判定都能用 "是/否" 回答** |
| 输出:**是恶意/不是恶意** | **如何输出 "恶意" 的概率是多大?** |
| 规则是确定的 | **战场需要概率 —— 不确定性的量化** |

> **核心转折:** 有些场景下,我们需要的不仅是一个结论,而是这个结论的**可信度**。

**朴素贝叶斯**:解决 "在不确定性下做判断" 的问题 —— 输出不是 "是/否",而是**概率**。

---

<!-- slide -->

## 一个网空场景:钓鱼邮件识别

某部收到一批邮件,需要判定是否为钓鱼邮件。

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:12px;font-size:0.55em;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #586e75;">
**📋 已知情报**

| 情报 | 数据 |
|------|------|
| 历史钓鱼邮件比例 | **15%**(先验概率) |
| 钓鱼邮件中含 "紧急" | **80%** |
| 正常邮件中含 "紧急" | **10%** |

</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #f39c12;">
**❓ 待求解的问题**

> 新邮件包含 **"紧急"** 字样

它是钓鱼邮件的概率 **有多大?**

</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;margin-top:6px;font-size:0.5em;">

<div style="background:rgba(133,153,0,0.08);padding:8px 12px;border-radius:6px;border:1px solid #27ae60;">
**🌳 决策树会怎么做?**
"是否包含 '紧急' ?"
→ 是 → **判定为钓鱼**
输出:**是/否**
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #268bd2;">
**📊 贝叶斯会怎么做?**
用历史数据 + 贝叶斯公式
→ 计算**后验概率**
输出:**P(钓鱼 | 紧急) = ?**
</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;">
💡 **本部分目标:** 学会在不确定条件下,用**概率**而非**规则**来做判断。
</div>

---

<!-- slide -->

## 人类的直觉 vs 贝叶斯

人类在判断时,已经在**潜意识里使用贝叶斯思想**:

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:14px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;font-size:0.65em;">🧠 人类的直觉</div>

<div style="font-size:0.55em;line-height:1.8;margin-top:4px;">
看到 **"紧急"** 这个词
↓
在脑中搜索:
- 钓鱼邮件中,有多少包含 "紧急" ?
- 正常邮件中,有多少包含 "紧急" ?
↓
综合判断 → 直觉上觉得 **"这封邮件有问题"**
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:12px 14px;border-radius:6px;border:1px solid #f39c12;">
<div style="font-weight:700;color:#f39c12;font-size:0.65em;">📐 贝叶斯定理</div>

<div style="font-size:0.5em;line-height:1.6;margin-top:4px;">
<div style="text-align:center;padding:4px 0;background:rgba(38,139,210,0.04);border-radius:4px;font-size:1.2em;">
P(钓鱼 | 紧急) = P(紧急 | 钓鱼) × P(钓鱼) / P(紧急)
</div>

**符号对应直觉:**

- **P(钓鱼)** → 以前见过钓鱼邮件吗?
- **P(紧急 | 钓鱼)** → 钓鱼邮件中 "紧急" 多吗?
- **P(紧急)** → "紧急" 本身常见吗?

</div>

</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;text-align:center;">
💡 **贝叶斯做的,就是把人类的这种直觉 "数学化" —— 用概率代替 "感觉",用公式代替 "大概"**
</div>

---

<!-- slide -->

## 决策树 vs 朴素贝叶斯 · 一个直观对比

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;font-size:0.55em;">

<div style="background:rgba(38,139,210,0.06);padding:14px 18px;border-radius:8px;border:1px solid #268bd2;">
<div style="font-size:1.2em;font-weight:700;color:#268bd2;">🌳 决策树</div>

| 维度 | 说明 |
|------|------|
| 输出 | **是/否** |
| 规则 | 如果 A 则 B |
| 本质 | 确定性逻辑 |
| 适用 | 有明确判据的场景 |

<div style="margin-top:6px;padding:4px 10px;background:rgba(38,139,210,0.06);border-radius:4px;text-align:center;">
> 像 **对答案**
</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:14px 18px;border-radius:8px;border:1px solid #f39c12;">
<div style="font-size:1.2em;font-weight:700;color:#f39c12;">🎲 朴素贝叶斯</div>

| 维度 | 说明 |
|------|------|
| 输出 | **87% 是恶意** |
| 规则 | 概率推理 |
| 本质 | 不确定性量化 |
| 适用 | 需要可信度的场景 |

<div style="margin-top:6px;padding:4px 10px;background:rgba(243,156,18,0.06);border-radius:4px;text-align:center;">
> 像 **打分**
</div>

</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(231,76,60,0.06);border-left:4px solid #e74c3c;border-radius:4px;font-size:0.5em;text-align:center;">
🎯 **网空启示:** 战场上,我们需要的往往不是 "是不是",而是 "有多大概率是" —— 后者更有决策价值。
</div>

---

<!-- slide -->

## 贝叶斯思想 · 根据证据修正认知

> **先有一个初始判断(先验),看到新证据后更新判断(后验)。**

<div style="display:flex;align-items:center;justify-content:space-between;gap:8px;margin:8px 0;padding:8px 12px;background:rgba(38,139,210,0.06);border-radius:6px;border:1px solid #586e75;">
<div style="text-align:center;flex:1;">
<div style="font-size:0.5em;color:var(--solarized-base00);">初始判断</div>
<div style="font-size:0.7em;font-weight:700;color:#268bd2;">\( P(\text{钓鱼}) = 15\% \)</div>
<div style="font-size:0.45em;color:var(--solarized-base00);">(看到证据之前)</div>
</div>
<div style="font-size:1.2em;color:var(--solarized-base00);">→</div>
<div style="text-align:center;flex:1.2;">
<div style="font-size:0.5em;color:var(--solarized-base00);">看到证据</div>
<div style="font-size:0.7em;font-weight:700;color:#f39c12;">"紧急" 字样</div>
<div style="font-size:0.45em;color:var(--solarized-base00);">(获得了新信息)</div>
</div>
<div style="font-size:1.2em;color:var(--solarized-base00);">→</div>
<div style="text-align:center;flex:1;">
<div style="font-size:0.5em;color:var(--solarized-base00);">更新后的判断</div>
<div style="font-size:0.7em;font-weight:700;color:#27ae60;">\( P(\text{钓鱼} \mid \text{紧急}) \approx 58\% \)</div>
<div style="font-size:0.45em;color:var(--solarized-base00);">(结合先验 + 证据)</div>
</div>
</div>

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:8px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border-left:4px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;font-size:0.6em;">🔹 先验概率</div>
<div style="font-size:0.7em;font-weight:600;color:#268bd2;">\( P(\text{钓鱼}) \)</div>
<div style="font-size:0.5em;color:var(--solarized-base00);">看到证据之前的初始判断</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border-left:4px solid #f39c12;">
<div style="font-weight:700;color:#f39c12;font-size:0.6em;">🔸 似然</div>
<div style="font-size:0.7em;font-weight:600;color:#268bd2;">\( P(\text{紧急} \mid \text{钓鱼}) \)</div>
<div style="font-size:0.5em;color:var(--solarized-base00);">证据在目标类别中的表现</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border-left:4px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.6em;">🔹 后验概率</div>
<div style="font-size:0.7em;font-weight:600;color:#27ae60;">\( P(\text{钓鱼} \mid \text{紧急}) \)</div>
<div style="font-size:0.5em;color:var(--solarized-base00);">看到证据之后的更新判断</div>
</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;text-align:center;">
💡 用新证据修正旧认知,让判断越来越接近真相。
</div>

---

<!-- slide -->

## 贝叶斯定理 · 数学表达

\[
\small
P(A|B) = \frac{P(B|A) \times P(A)}{P(B)}
\]

<div style="font-size:0.85em;">

| 符号 | 含义 | 网空场景对应 |
|------|------|-------------|
| \(P(A \mid B)\) | 后验概率:看到证据 B 后,事件 A 发生的概率 | 看到 "紧急" 字样后,是钓鱼邮件的概率 |
| \(P(A)\) | 先验概率:看到证据前,事件 A 发生的概率 | 历史中钓鱼邮件的比例(15%) |
| \(P(B \mid A)\) | 似然:在事件 A 发生的条件下,看到证据 B 的概率 | 钓鱼邮件中出现 "紧急" 的概率(80%) |
| \(P(B)\) | 证据概率:看到证据 B 的总概率 | 所有邮件中出现 "紧急" 的总概率 |

</div>

> 翻译成人话: 后验概率 = 先验 × 证据的 "说服力"

---

<!-- slide -->

## 贝叶斯定理 · 一个直观类比

> **贝叶斯定理就像 "破案" —— 用新证据逐步锁定真凶。**

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:10px;margin-top:8px;">

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border-top:4px solid #268bd2;">
<div style="font-size:0.55em;color:var(--solarized-base00);">🔍 破案角色</div>
<div style="font-size:0.65em;font-weight:700;color:#268bd2;margin-top:2px;">案发前的怀疑程度</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border-top:4px solid #f39c12;">
<div style="font-size:0.55em;color:var(--solarized-base00);">🔍 破案角色</div>
<div style="font-size:0.65em;font-weight:700;color:#268bd2;margin-top:2px;">嫌疑人的作案特征</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border-top:4px solid #27ae60;">
<div style="font-size:0.55em;color:var(--solarized-base00);">🔍 破案角色</div>
<div style="font-size:0.65em;font-weight:700;color:#27ae60;margin-top:2px;">综合判断</div>
</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:10px;margin-top:4px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-size:0.5em;color:var(--solarized-base00);">📐 数学对应</div>
<div style="font-size:0.65em;font-weight:700;color:#268bd2;margin-top:2px;">先验 \( P(A) \)</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-size:0.5em;color:var(--solarized-base00);">📐 数学对应</div>
<div style="font-size:0.65em;font-weight:700;color:#f39c12;margin-top:2px;">似然 \( P(B \mid A) \)</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-size:0.5em;color:var(--solarized-base00);">📐 数学对应</div>
<div style="font-size:0.65em;font-weight:700;color:#27ae60;margin-top:2px;">后验 \( P(A \mid B) \)</div>
</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr 1fr;gap:10px;margin-top:4px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #586e75;">
<div style="font-size:0.5em;color:var(--solarized-base00);">🎯 网空对应</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:2px;">历史钓鱼邮件比例</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #586e75;">
<div style="font-size:0.5em;color:var(--solarized-base00);">🎯 网空对应</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:2px;">"紧急" 在钓鱼邮件中的概率</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #586e75;">
<div style="font-size:0.5em;color:var(--solarized-base00);">🎯 网空对应</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:2px;">看到 "紧急" 后的钓鱼概率</div>
</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;text-align:center;">
💡 贝叶斯就是用数学方式模拟人类 "根据新证据调整判断" 的思维方式。
</div>

---

<!-- slide -->

## 贝叶斯公式 · 推导

**理解条件概率:** \( P(A|B) \) = 在 B 条件下 A 的概率(如:紧急邮件中钓鱼的比例)

<div style="display:grid;grid-template-columns:1fr 0.2fr 1fr 0.2fr 1fr;gap:4px;align-items:center;font-size:0.5em;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;font-size:0.9em;">1 条件概率定义</div>
\[
P(A|B) = \frac{P(A \cap B)}{P(B)}
\]
"在 B 条件下 A 的概率"
= A 和 B 同时发生 ÷ B 发生
</div>

<div style="text-align:center;font-size:1.2em;color:var(--solarized-base00);">→</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #f39c12;">
<div style="font-weight:700;color:#f39c12;font-size:0.9em;">2 联合概率对称</div>
\[
P(A \cap B) = P(B|A) \times P(A)
\]
"A 和 B 同时发生"
= 在 A 条件下 B 的概率 × A 的概率
</div>

<div style="text-align:center;font-size:1.2em;color:var(--solarized-base00);">→</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.9em;">3 代入 → 贝叶斯公式</div>
\[
P(A|B) = \frac{P(B|A) \times P(A)}{P(B)}
\]
\[
\small
= \frac{P(B|A)P(A)}{P(B|A)P(A) + P(B|\bar{A})P(\bar{A})}
\]
</div>

</div>

<div style="margin-top:6px;padding:4px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.45em;text-align:center;">
💡 每一步都源于条件概率的定义,贝叶斯公式本身没有引入任何额外假设。
</div>

---

<!-- slide -->

## 贝叶斯 vs 直接统计

<div style="font-size:0.5em;">
**背景:** 某机构历史上钓鱼邮件仅占 1%。当前情报: 0-day 攻击爆发,钓鱼占比已升至 **40%**。

**历史观察数据(100 封邮件):**

| 类别 | 邮件数 | 含 "点击链接" |
|------|--------|-------------|
| 钓鱼 | 1 | 1 (100%) |
| 正常 | 99 | 5 (≈ 5%) |
</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;font-size:0.38em;margin-top:4px;">

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;font-size:1.1em;">❌ 直接统计</div>

含 "点击链接" 的邮件共 **6 封**(1 封钓鱼 + 5 封正常)

\[
P(\text{钓鱼}|\text{点击链接}) = \frac{1}{1+5} \approx 16.7\%
\]

**问题:** 被大量 "正常" 邮件稀释,严重低估真实风险。
</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:1.1em;">✅ 贝叶斯</div>

**已知:**

- 先验: \( P(\text{钓鱼}) = 40\% \),\( P(\text{正常}) = 60\% \)
- 似然: \( P(\text{点击链接}|\text{钓鱼}) = 1/1 = 1 \)
- 似然: \( P(\text{点击链接}|\text{正常}) = 5/99 \approx 0.05 \)

**公式:**

\[
P(\text{钓鱼}|\text{点击链接}) =
\frac{P(\text{点击链接}|\text{钓鱼}) \times P(\text{钓鱼})}
{P(\text{点击链接}|\text{钓鱼}) \times P(\text{钓鱼}) +
P(\text{点击链接}|\text{正常}) \times P(\text{正常})}
\]

**代入:**

\[
= \frac{1 \times 0.4}{1 \times 0.4 + 0.05 \times 0.6}
= \frac{0.4}{0.43}
\approx 93\%
\]

融合情报先验(40%),纠正了历史偏差。
</div>

</div>

<div style="margin-top:4px;padding:2px 10px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.35em;text-align:center;">
💡 直接统计 "向后看" (被历史数据淹没),贝叶斯 "向前看" (融合实时情报)
</div>

---

<!-- slide -->

## 朴素贝叶斯 · "朴素" 在哪里?

> **核心假设:所有特征互相独立。**

<div style="display:grid;grid-template-columns:1fr 1.2fr;gap:14px;margin-top:6px;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;font-size:0.65em;">📧 邮件特征</div>

<div style="font-size:0.55em;line-height:1.6;margin-top:2px;">
新邮件包含:

- **紧急**
- **中奖**
- **链接**

</div>

</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #f39c12;">
<div style="font-weight:700;color:#f39c12;font-size:0.65em;">🧠 朴素假设</div>

<div style="font-size:0.5em;line-height:1.5;margin-top:2px;">
这些特征**互相独立**,互不影响:

\[
\small
P(\text{紧急}, \text{中奖}, \text{链接} \mid \text{钓鱼})
=
P(\text{紧急} \mid \text{钓鱼})
\times
P(\text{中奖} \mid \text{钓鱼})
\times
P(\text{链接} \mid \text{钓鱼})
\]

</div>

</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;font-size:0.45em;margin-top:4px;">

<div style="background:rgba(133,153,0,0.08);padding:6px 12px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;font-size:0.85em;">✅ 为什么有效?</div>

- 计算量从**指数级**降为**线性级**
- 高维数据也能快速处理
- 文本分类中效果优异

</div>

<div style="background:rgba(220,50,47,0.08);padding:6px 12px;border-radius:6px;border:1px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;font-size:0.85em;">⚠ 现实中的局限</div>

- 特征通常**相关**("紧急"+"中奖" 常同时出现)
- 但朴素假设在实际应用中**效果依然很好**

</div>

</div>

<div style="margin-top:4px;padding:4px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.4em;text-align:center;">
💡 "朴素" 不是 "幼稚" —— 它是一种**工程上的简化**,用可接受的精度换取计算效率。
</div>

---

<!-- slide -->

## 贝叶斯如何做决策?

> **计算每个类别的后验概率,选择概率最大的那个。**

<div style="display:grid;grid-template-columns:1fr 1.2fr 1fr;gap:10px;margin-top:8px;">

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border:1px solid #268bd2;text-align:center;">
<div style="font-size:0.5em;color:var(--solarized-base00);">📧 输入</div>
<div style="font-size:0.65em;font-weight:700;color:#073642;margin-top:2px;">新邮件特征</div>
<div style="font-size:0.5em;color:var(--solarized-base00);margin-top:4px;">
紧急 · 中奖 · 链接
</div>
</div>

<div style="font-size:1.2em;color:var(--solarized-base00);display:flex;align-items:center;justify-content:center;">→</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border:1px solid #f39c12;text-align:center;">
<div style="font-size:0.5em;color:var(--solarized-base00);">📊 计算</div>
<div style="font-size:0.5em;color:#073642;margin-top:2px;line-height:1.6;">
\( P(\text{钓鱼} \mid \text{特征}) = ? \)
\( P(\text{正常} \mid \text{特征}) = ? \)
</div>
</div>

<div style="font-size:1.2em;color:var(--solarized-base00);display:flex;align-items:center;justify-content:center;">→</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 12px;border-radius:6px;border:1px solid #27ae60;text-align:center;">
<div style="font-size:0.5em;color:var(--solarized-base00);">✅ 决策</div>
<div style="font-size:0.65em;font-weight:700;color:#27ae60;margin-top:2px;">选概率最大的</div>
<div style="font-size:0.5em;color:var(--solarized-base00);margin-top:4px;">
谁大 → 判给谁
</div>
</div>

</div>

<div style="margin-top:6px;padding:4px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.45em;text-align:center;">
💡 贝叶斯不做 "是/否" 判断,而是**计算每个类别的概率,选最大的那个** —— 决策过程与 "对答案" 截然不同,更像在 "打分比高低"。
</div>

---

<!-- slide -->

## 一个网空例子 · 逐步计算

<div style="font-size:0.5em;">
某机构历史邮件统计:

| 类别 | 先验概率 | 含 "紧急" | 含 "中奖" |
|------|----------|----------|----------|
| 钓鱼 | 15% | 80% | 60% |
| 正常 | 85% | 10% | 5% |

**新邮件同时包含 "紧急" 和 "中奖"**

求: \( P(\text{钓鱼} \mid \text{紧急}, \text{中奖}) = ? \)

> 朴素贝叶斯假设: "紧急" 和 "中奖" 相互独立
</div>

<div style="margin-top:2px;padding:4px 10px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.4em;">
💡 接下来:先算证据 \( P(\text{紧急}, \text{中奖}) \),再算后验概率
</div>

---

<!-- slide -->

## 第一步 · 计算 P(证据)

**📊 历史数据回顾:**

| 类别 | 先验 | 含 "紧急" | 含 "中奖" |
|------|------|----------|----------|
| 钓鱼 | **15%** | **80%** | **60%** |
| 正常 | **85%** | **10%** | **5%** |

<div style="font-size:0.5em;margin-top:4px;">
\[
\begin{aligned}
P(\text{紧急}, \text{中奖})
&= P(\text{紧急},\text{中奖}|\text{钓鱼}) \times P(\text{钓鱼}) +
  P(\text{紧急},\text{中奖}|\text{正常}) \times P(\text{正常}) \\
&= (\textcolor{#e74c3c}{0.8} \times \textcolor{#f39c12}{0.6}) \times \textcolor{#268bd2}{0.15} +
  (\textcolor{#e74c3c}{0.1} \times \textcolor{#f39c12}{0.05}) \times \textcolor{#268bd2}{0.85} \\
&= 0.48 \times 0.15 + 0.005 \times 0.85 \\
&= 0.072 + 0.00425 \\
&= 0.07625
\end{aligned}
\]
</div>

> **P(证据) ≈ 7.6%** — 所有邮件中同时包含 "紧急" 和 "中奖" 的比例

---

<!-- slide -->

## 第二步 · 计算 P(钓鱼 | 证据)

**📊 历史数据回顾:**

| 类别 | 先验 | 含 "紧急" | 含 "中奖" |
|------|------|----------|----------|
| 钓鱼 | **15%** | **80%** | **60%** |
| 正常 | **85%** | **10%** | **5%** |

<div style="font-size:0.44em;margin-top:0;">
**朴素贝叶斯假设:** "紧急" 和 "中奖" 相互独立

\[
\begin{aligned}
P(\text{钓鱼}|\text{紧急},\text{中奖})
&= \frac{P(\text{紧急}|\text{钓鱼}) \times P(\text{中奖}|\text{钓鱼}) \times P(\text{钓鱼})}{P(\text{紧急},\text{中奖})} \\[2pt]
&= \frac{(\textcolor{#e74c3c}{0.8}) \times (\textcolor{#f39c12}{0.6}) \times \textcolor{#268bd2}{0.15}}{0.07625} \\[2pt]
&= \frac{0.48 \times 0.15}{0.07625} \\[2pt]
&= \frac{0.072}{0.07625} \\[2pt]
&\approx 0.944
\end{aligned}
\]
</div>

> **结论:约 94.4% 概率是钓鱼邮件!**

---

<!-- slide -->

## 计算结果解读

<div style="display:grid;grid-template-columns:1fr 1.5fr 1.5fr;gap:8px;font-size:0.6em;margin-top:4px;">

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #586e75;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">判断阶段</div>
<div style="font-weight:700;margin-top:2px;">先验</div>
<div style="font-weight:700;margin-top:2px;">看到 "紧急"</div>
<div style="font-weight:700;margin-top:2px;">+"中奖"</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #586e75;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">概率</div>
<div style="font-weight:700;color:#268bd2;margin-top:2px;">15%</div>
<div style="font-weight:700;color:#f39c12;margin-top:2px;">≈ 58%</div>
<div style="font-weight:700;color:#27ae60;margin-top:2px;font-size:1.1em;">94.4%</div>
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 10px;border-radius:6px;border:1px solid #586e75;text-align:center;">
<div style="font-size:0.55em;color:var(--solarized-base00);">说明</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:2px;">仅凭历史数据</div>
<div style="font-size:0.55em;color:var(--solarized-base00);margin-top:2px;">"紧急" 是一个强信号</div>
<div style="font-size:0.55em;color:#27ae60;margin-top:2px;">两个证据叠加,信心大幅提升</div>
</div>

</div>

<div style="display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:6px;font-size:0.55em;">

<div style="background:rgba(38,139,210,0.10);padding:6px 10px;border-radius:6px;border-left:4px solid #268bd2;">
**📊 中间计算(看到 "紧急" 时):**

\[
P(\text{钓鱼}|\text{紧急}) =
\frac{0.8 \times 0.15}{0.8 \times 0.15 + 0.1 \times 0.85}
\approx 58.5\%
\]

</div>

<div style="background:rgba(133,153,0,0.08);padding:6px 10px;border-radius:6px;border-left:4px solid #27ae60;">
**🎯 最终判断(两个证据叠加):**

\[
P(\text{钓鱼}|\text{紧急},\text{中奖})
= \frac{0.8 \times 0.6 \times 0.15}{0.07625}
\approx 94.4\%
\]

</div>

</div>

<div style="margin-top:4px;padding:4px 12px;background:rgba(243,156,18,0.06);border-left:4px solid #f39c12;border-radius:4px;font-size:0.55em;text-align:center;">
💡 **实战含义:** 单看 "紧急" 不可靠(58%),加上 "中奖" 后可信度显著上升(94%)。这就是贝叶斯 "**多证据综合研判**" 的价值 —— **不是孤立的证据,而是证据的叠加效应**。
</div>

---

<!-- slide -->

## 先验的重要性 · 两个维度

### 同样的证据,不同的先验 → 不同的结论

| 场景 | 先验 P(钓鱼) | 后验 \(P(\text{钓鱼} \mid \text{紧急}, \text{中奖})\) |
|------|-------------|----------------------|
| 某机构 A(钓鱼邮件常见) | 15% | **94.4%** |
| 某机构 B(钓鱼邮件罕见) | 1% | **~49%** |

<div style="display:grid;grid-template-columns:1fr 1fr;gap:10px;margin-top:6px;font-size:0.45em;">

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border-left:4px solid #268bd2;">
**🌍 空间维度:不同机构基线不同**

- 机构 A 经常被钓鱼攻击 → 先验 15%
- 机构 B 防护严密 → 先验 1%
- 同样的特征在不同环境下意义不同

</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border-left:4px solid #f39c12;">
**⏰ 时间维度:同一机构态势变化**

- 平时:先验 1%
- 攻击爆发时:先验 40%
- 先验需要随威胁态势**动态调整**

</div>

</div>

<div style="margin-top:4px;padding:4px 10px;background:rgba(231,76,60,0.06);border-left:4px solid #e74c3c;border-radius:4px;font-size:0.4em;">
⚠ **网空启示:** 先验不是拍脑袋决定的 —— 它应该反映**当前、本地**的威胁态势,既是空间维度上需要本地化的基线水平,也是时间维度上需要动态更新的实时情报。
</div>

---

<!-- slide -->

## Sklearn 实践 · 生成数据 + 训练模型

```python
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

# 生成模拟数据(10 维特征, 2000 样本)
X, y = make_classification(n_samples=2000, n_features=10,
                           n_informative=6, random_state=42)
# 划分训练/测试集
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42)
# 训练朴素贝叶斯
model = GaussianNB()
model.fit(X_train, y_train)
print(f"准确率: {model.score(X_test, y_test):.4f}")
```

典型输出: 准确率: 0.8750

---

<!-- slide -->

## Sklearn 实践 · 预测与概率

```python
# 对新样本进行预测
pred = model.predict(X_test[:10])
print(pred)  # [1 0 1 1 0 ...]

# 查看每个类别的概率
proba = model.predict_proba(X_test[:5])
print(proba)
```

概率输出示例:

```text
[[0.12 0.88]   → 第 1 个样本: 88% 属于类别 1
 [0.91 0.09]   → 第 2 个样本: 91% 属于类别 0
 [0.05 0.95]   → 第 3 个样本: 95% 属于类别 1
 ...]
```

这是决策树做不到的:不仅告诉你答案,还告诉你 "有多大把握"。

---

<!-- slide -->

## Sklearn 实践 · 三种朴素贝叶斯变体

```python
from sklearn.naive_bayes import GaussianNB, MultinomialNB, BernoulliNB
```

| 变体 | 适用场景 | 数据要求 |
|------|----------|----------|
| GaussianNB | 连续特征(如流量大小、频率) | 特征服从正态分布 |
| MultinomialNB | 文本分类、计数特征 | 非负频次数据 |
| BernoulliNB | 二值特征(0/1) | 布尔值/二元特征 |

**网空场景选择建议:**

| 网空场景 | 推荐变体 |
|----------|----------|
| 流量统计特征(连续值) | GaussianNB |
| DNS 查询类型、协议标志(计数) | MultinomialNB |
| 是否存在某特征(0/1) | BernoulliNB |

---

<!-- slide -->

## 朴素贝叶斯 · 优缺点(网空视角)

<div style="display:grid;grid-template-columns:1fr 1fr;gap:12px;font-size:0.55em;">

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #27ae60;">
✅ 核心优势

| 优势 | 网空价值 |
|------|----------|
| 极快 | 实时检测毫秒级响应 |
| 无需大量数据 | 小样本也能工作 |
| 概率输出 | 提供可信度而非简单结论 |
| 高维友好 | 可处理数千维特征 |
| 增量学习 | 支持在线更新模型 |

</div>

<div style="background:rgba(38,139,210,0.06);padding:10px 14px;border-radius:6px;border:1px solid #e74c3c;">
⚠ 固有局限

| 局限 | 网空应对 |
|------|----------|
| 特征独立性假设 | 实际特征多相关 → 可做特征选择/降维 |
| 对输入分布敏感 | 需根据数据分布选择合适的变体 |
| 不能自动学习特征组合 | 可结合人工特征工程 |

</div>

</div>

<div style="margin-top:6px;padding:6px 12px;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.5em;text-align:center;">
💡 朴素贝叶斯 "朴素" 在假设独立,但它的速度和概率输出在网空场景中价值巨大
</div>

---

<!-- slide -->

## 朴素贝叶斯在网空领域的典型应用

| 场景 | 贝叶斯做什么 | 为什么选它 |
|------|-------------|-----------|
| 📧 **钓鱼邮件/URL 识别** | 计算恶意概率 | 概率输出便于分级处置 |
| 🚨 **告警可信度评分** | 评估告警的真实性 | 帮助分析师优先处理高风险告警 |
| 🌐 **DNS 隧道检测** | 域名请求异常概率 | 小样本也能快速适配新威胁 |
| 📊 **流量分类** | 判断流量类型概率 | 实时处理,毫秒级响应 |
| 🧠 **攻击阶段推断** | 计算当前处于攻击链哪一步 | 不确定性量化辅助决策 |

---

<!-- slide -->

## 随堂思考题

某部内网部署了钓鱼邮件检测系统。

**方案 A:** 决策树模型(准确率 88%,输出:是/否)

**方案 B:** 朴素贝叶斯模型(准确率 86%,输出:85% 可能是钓鱼)

问题: 如果你是安全负责人,你会选择哪个方案?为什么?

---

<!-- slide -->

## 如何选择? —— 方案对比

**取决于使用场景:**

<div style="display:grid;grid-template-columns:1fr 1fr;gap:8px;font-size:0.45em;">

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #268bd2;">
<div style="font-weight:700;color:#268bd2;">🤖 自动拦截</div>
<div style="font-size:0.85em;color:var(--solarized-base00);">误拦成本低</div>
→ **决策树(A)**
需要明确规则,高准确率直接拦截
</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #f39c12;">
<div style="font-weight:700;color:#f39c12;">🧠 辅助研判</div>
<div style="font-size:0.85em;color:var(--solarized-base00);">误拦成本高</div>
→ **朴素贝叶斯(B)**
输出概率,分析师可结合上下文综合判断
</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #27ae60;">
<div style="font-weight:700;color:#27ae60;">⚡ 资源受限</div>
<div style="font-size:0.85em;color:var(--solarized-base00);">边缘/端侧部署</div>
→ **朴素贝叶斯(B)**
更轻量,训练和推理更快,无需 GPU
</div>

<div style="background:rgba(38,139,210,0.06);padding:6px 10px;border-radius:6px;border:1px solid #e74c3c;">
<div style="font-weight:700;color:#e74c3c;">📋 需要审计</div>
<div style="font-size:0.85em;color:var(--solarized-base00);">合规/溯源要求</div>
→ **决策树(A)**
规则透明,每条判据可追溯
</div>

</div>

<div style="display:flex;align-items:center;justify-content:center;gap:12px;margin-top:6px;padding:6px 16px;background:rgba(38,139,210,0.06);border-radius:6px;border:1px solid rgba(38,139,210,0.1);font-size:0.4em;">
<div style="font-weight:700;color:#268bd2;">📊 朴素贝叶斯</div>
<div style="color:var(--solarized-base00);">→ 初筛(可疑度评分)</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">↓</div>
<div style="font-weight:700;color:#e74c3c;">🌳 决策树</div>
<div style="color:var(--solarized-base00);">→ 明确拦截规则</div>
<div style="color:var(--solarized-base00);font-size:1.2em;">↓</div>
<div style="font-weight:700;color:#27ae60;">👤 分析师</div>
<div style="color:var(--solarized-base00);">→ 人工确认</div>
</div>

<div style="margin-top:4px;padding:4px 10px;background:rgba(231,76,60,0.06);border-left:4px solid #268bd2;border-radius:4px;font-size:0.35em;text-align:center;">
🎯 **网空核心命题:** 我们需要的不是 "哪个更好",而是 **"哪个在什么情况下更适用"**。
</div>

---

<!-- slide -->

## 本部分总结 · 朴素贝叶斯

<div style="display:grid;grid-template-columns:1fr 1fr;gap:8px;font-size:0.6em;">

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #268bd2;">
💡 核心思想
根据证据不断修正认知 —— 先验 → 似然 → 后验
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #f39c12;">
🔑 关键区别
概率输出 — 不仅告诉结论,还告诉可信度
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #27ae60;">
⚡ 核心优势
极快、小样本、高维友好、概率输出
</div>

<div style="background:rgba(38,139,210,0.06);padding:8px 12px;border-radius:6px;border:1px solid #e74c3c;">
🎯 网空定位
从 "确定性规则" 到 "概率性研判" 的认知跃迁
</div>

</div>

<div style="margin-top:8px;padding:8px 14px;background:rgba(38,139,210,0.08);border-radius:6px;text-align:center;font-size:0.7em;border:1px solid rgba(38,139,210,0.15);">
贝叶斯不做 "是/否" 判断,而是告诉你 "有多大把握" —— 概率让决策更有依据。
</div>

---

<!-- slide -->

## 下一部分预告

<div style="text-align:center;">
🌲 孤立森林 · 异常的隔离
当恶意样本极度稀少,连 "钓鱼" 的规律都难以总结
—— 异常本身就是信号
</div>

---
