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

## C语言历史与人工智能

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)






<!-- slide data-notes="" -->

##### 提纲

---

本次课(周三)分两部分:

- ==0-3== (本课件): C 简史与人工智能

- ==0-4==: 变量与基本数据类型、代码展示、开发环境与 AI 工具

---





<!-- slide data-notes="" -->

##### 回顾周二

---

周二我们知道了:

- 程序是计算机的==灵魂==, 程序 = ==算法 + 数据==

- 计算机工作的流程: ==输入 → 处理 → 存储 → 输出==

- 写程序 = ==结构==(顺序、判断、循环) + ==数据== + ==分解==

- 还动手写了自己的第一个程序 Hello World

今天: C 从哪里来、AI 为什么用 C, 然后开始写==真正的程序==!

---





<!-- slide data-notes="" -->

##### C语言的起源

---

- C 是 ==UNIX== 的副产品: Thompson 先设计了小型语言 ==B== (源自 ==BCPL==)

- 1971 年 Ritchie 扩展 B, 初名 ==NB==("New B"), 分歧渐大后改名 ==C==

- ==1973== 年: UNIX 已可以用 C 重写, 语言足够稳定

- 1978: Kernighan 和 Ritchie 合著《C程序设计语言》，成为事实标准

- 1989: 正式标准化为 ANSI C (C89/C90)，后续 C99、C11

- 影响力: 高效、灵活，广泛应用于系统编程、嵌入式系统

---





<!-- slide data-notes="" -->

##### 基于C的语言

---

- C++: 包括 C 的所有特性, 添加了类以支持面向对象编程

- Java: 基于 C++, 继承了许多 C 特性

- C#: 从 C++ 和 Java 派生

- Python: 解释器与核心计算库大量用 C 实现 (为 ==C语言与人工智能== 埋下伏笔)

---





<!-- slide data-notes="" -->

##### C的特点与优点

---

- ==低层语言==: 提供对机器级概念的访问 (字节和地址)

- ==小型语言==: 有限的特性集合, 很大程度依赖标准函数库

- ==宽松包容==: 高自由度, 不强制详细的错误检查

- 优点: ==效率高==、==可移植==、==灵活==、功能强大、标准库、与 Linux 集成

---





<!-- slide data-notes="" -->
##### C的缺点与应对

---

<div style="font-size:1.25em;line-height:1.7;">
<ul>
<li>==缺点==: 程序容易隐藏错误、可能难以理解、可能难以维护</li>
<li>==应对==:
<div style="font-size:0.8em;line-height:1.7;">
<ul>
<li>深入理解, 避开 C 语言的陷阱</li>
<li>避免过于复杂的代码</li>
<li>使用软件工具 (lint、调试器) 让程序更可靠</li>
<li>采用一套合理的编码规范</li>
<li>紧贴标准</li>
</ul>
</div>
</li>
</ul>
</div>

---

<!-- slide data-notes="" -->
##### 什么是人工智能

---

<p style="font-size:1.1em;">==人工智能 (AI)==: 研究如何让计算机去==模拟、延伸和扩展==人的智能</p>

<div style="font-size:1.25em;line-height:1.65;">
<ul>
<li>==图灵测试==: 机器能否像人一样思考? —— 用一场"模仿游戏"来判断</li>
<li>==身边的 AI==: 人脸识别 · 机器翻译 · 自动驾驶 · 语音助手 (Siri/小爱同学) · 大语言模型 (GPT、DeepSeek)</li>
</ul>
</div>

<div style="font-size:1.05em;line-height:1.65;border-left:4px solid #268bd2;padding-left:14px;margin-top:12px;">
==图灵测试 (1950)==: 裁判在看不到对方的情况下, 通过文字对话分辨哪边是人、哪边是机器; ==分不出来, 就认为机器表现出了智能==。它把"机器能否思考"变成了==可操作的行为判断==——但==会模仿 &ne; 真正理解==, 这也是今天评价大模型时的常用视角。
</div>

---

<!-- slide data-notes="" -->

##### 人工智能简史

---

<span class="blue">:fa-lightbulb-o:</span> 你们觉得 Siri 会'听懂人话'吗？背后其实是 ==语音识别 + 大语言模型==

- 1950: 图灵提出"机器能思考吗？"，图灵测试

- 1956: 达特茅斯会议，"人工智能"正式诞生

- 1980s: 专家系统

- 2006~: 深度学习兴起

- 2017~: Transformer 架构 → 大语言模型 (GPT、DeepSeek 等)

---





<!-- slide data-notes="" -->
##### AI 的底层: C 与 C++

---

当我们用 Python 调用 AI 框架时, 发生了什么?

<div style="display:flex;align-items:stretch;justify-content:center;gap:8px;font-size:0.78em;text-align:center;flex-wrap:wrap;margin:8px 0;">
  <div style="border:2px solid var(--solarized-blue);border-radius:8px;padding:10px 14px;">Python 前端<br>调用框架 API</div>
  <span class="blue" style="font-size:1.6em;align-self:center;">→</span>
  <div style="border:2px solid var(--solarized-red);border-radius:8px;padding:10px 14px;"><mark>C/C++ 引擎</mark><br>算子调度 · 张量运算</div>
  <span class="blue" style="font-size:1.6em;align-self:center;">→</span>
  <div style="border:2px solid var(--solarized-yellow);border-radius:8px;padding:10px 14px;">数值内核<br>CPU: BLAS/OpenBLAS<br>GPU: CUDA 内核</div>
  <span class="blue" style="font-size:1.6em;align-self:center;">→</span>
  <div style="border:2px solid var(--solarized-green);border-radius:8px;padding:10px 14px;">结果返回<br>Python</div>
</div>

- TensorFlow / PyTorch 的核心引擎: ==C++ 实现==; Python 层只负责"发号施令"

- 数值计算最终落在: CPU 的 ==BLAS/LAPACK== 内核 (经典实现为 Fortran, OpenBLAS 等用 C/汇编) 或 GPU 的 ==CUDA 内核== (以 C 语言为基础扩展)

- TinyML (如 TensorFlow Lite for Microcontrollers): 用 C/C++ 编写、无动态内存, 跑在单片机上

---

<!-- slide data-notes="" -->

##### AI 的底层是 C

---

==C 语言是 AI 底层生态的通用接口==

- 学 C 能理解张量 (Tensor): 连续内存 + 指针

- 学 C 能理解矩阵运算: 二维数组 + 循环 + Cache 优化

- 学 C 能理解内存管理: malloc / free

- 学 C 才能看懂 PyTorch / TensorFlow 的"引擎"

---


<!-- slide data-notes="" -->

##### 上半场结束

---

接下来打开 ==0-4== 课件:

- 变量与基本数据类型 (正式知识点)

- 代码展示: 年龄 / 温度转换 / 找零计算

- 开发环境与 AI 工具

---
