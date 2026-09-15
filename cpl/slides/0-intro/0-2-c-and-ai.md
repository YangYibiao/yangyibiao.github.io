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

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)






<!-- slide data-notes="" -->

##### 提纲

---

本次课(周三)分两部分:

- ==0-2== (本课件): C 简史与人工智能

- ==0-3==: 变量与基本数据类型、代码展示、开发环境与 AI 工具

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

- 缺点: 程序容易隐藏错误、可能难以理解、可能难以维护

- 应对:
  - 深入理解以避免 C 语言的陷阱
  - 避免过于复杂的代码
  - 使用软件工具 (lint、调试器) 使程序更可靠
  - 采用一套合理的编码规范
  - 紧贴标准

---





<!-- slide data-notes="" -->

##### 什么是人工智能

---

人工智能 (Artificial Intelligence): 研究如何用计算机去==模拟、延伸和扩展==人的智能

- 图灵测试: 让机器表现得像人一样思考、学习、做决策

- 身边的 AI: 
  - <span class="blue">:fa-camera:</span> 人脸识别
  - <span class="blue">:fa-language:</span> 机器翻译
  - <span class="blue">:fa-car:</span> 自动驾驶
  - <span class="blue">:fa-microphone:</span> 语音助手 (Siri/小爱同学)
  - <span class="blue">:fa-comments:</span> 大语言模型 (GPT、DeepSeek 等)

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

当我们用 Python 调用 AI 框架时，发生了什么？

<div style="display:flex;align-items:center;justify-content:center;gap:10px;font-size:0.85em;text-align:center;">
  <div style="border:2px solid var(--solarized-blue);border-radius:8px;padding:8px 16px;">Python<br>发出指令</div>
  <span class="blue" style="font-size:1.5em;">→</span>
  <div style="border:2px solid var(--solarized-red);border-radius:8px;padding:8px 16px;"><mark>C/C++ 高性能引擎</mark><br>完成繁重的数学计算</div>
  <span class="blue" style="font-size:1.5em;">→</span>
  <div style="border:2px solid var(--solarized-green);border-radius:8px;padding:8px 16px;">结果返回<br>Python</div>
</div>

- TensorFlow / PyTorch 核心: C++ 实现

- BLAS / LAPACK: 数值计算的==接口标准== (经典实现用 Fortran); OpenBLAS 等高性能实现用 C/汇编

- CUDA: 以 C 语言为基础扩展而来，驱动 GPU

- TinyML (如 TensorFlow Lite for Microcontrollers): 用 C/C++ 编写、无动态内存，跑在单片机上

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

接下来打开 ==0-3== 课件:

- 变量与基本数据类型 (正式知识点)

- 代码展示: 年龄 / 温度转换 / 成绩 / 石头剪刀布

- 开发环境与 AI 工具

---
