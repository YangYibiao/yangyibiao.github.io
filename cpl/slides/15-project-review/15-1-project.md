---
password: "cpl2026"
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

## 期末项目指导与答辩

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 项目要求回顾 (代码 + 答辩 + 技术文档)

- 选题示例与分组、进度里程碑与提交

- AI 使用规范

- 答辩流程与评分标准

- 常见问题与准备建议

---


<!-- slide data-notes="" -->


##### 项目要求回顾

---

==期末项目== (占总评 20%): 跨学科智能应用开发

三项交付物:

1. ==代码==: 可编译运行, 结构清晰, 有注释

2. ==答辩==: 现场演示 + 讲解设计思路

3. ==技术文档==: 需求分析、模块设计、测试与运行说明

<div class="fullborder">

| 评分维度 | 权重参考 |
| :-- | :-- |
| 功能完成度 (能跑、符合需求) | 40% |
| 代码质量 (结构、注释、规范) | 30% |
| 答辩表现 (讲清思路、答问) | 20% |
| 技术文档 | 10% |

</div>

---


<!-- slide data-notes="" -->
##### 选题示例与分组

---

==选题原则==: 小而完整——2-3 人一组, 几周内能做出一个能演示的"小系统"

<div style="display:flex;align-items:flex-start;gap:28px;font-size:0.85em;line-height:1.55;">

<div style="flex:1;">

==示例题目==

- 学生成绩管理 (结构体数组 + 文件读写 + 排序统计)

- 图书借阅登记 (链表 + 文件持久化)

- 词频统计与检索 (字符串 + 排序 + 二分查找)

- 简易计算器/表达式求值 (栈 + 函数指针)

- 小游戏 (生命游戏/猜数字, 二维数组 + 函数化)

</div>

<div style="flex:1;">

==分组与分工==

- 2-3 人一组, 自选组长

- 分工建议: 核心算法 · 输入输出与界面 · 测试与文档

- 每人必须能讲清==整体结构==, 不只认自己那块

- 答辩按组进行, 提问可==指定任何成员==回答

</div>

</div>

---


<!-- slide data-notes="" -->


##### 进度里程碑与提交

---

<div class="fullborder">

| 时间 | 里程碑 | 交付物 |
| :-- | :-- | :-- |
| 本周内 | 选题与分组 | 题目 + 成员与分工 (发给老师确认) |
| 两周后 | 原型可运行 | 最小可运行版本 (能演示核心功能) |
| 三周后 | 功能完成 | 代码冻结, 开始写技术文档 |
| 考试周 | 答辩 | 代码 + 技术文档 + 现场演示 |

</div>

==提交内容==: 全部源文件与头文件、Makefile/编译说明、技术文档 (需求/设计/测试/运行说明)、演示用样例数据

<span class="blue">:fa-lightbulb-o:</span> 每完成一个里程碑就==把能跑的版本存一份==——答辩时"最小可运行版本"就是保底

---


<!-- slide data-notes="" -->


##### 答辩流程

---

每组的答辩 (10-15 分钟):

1. ==演示== (3-5 分钟): 现场运行程序, 展示核心功能

2. ==讲解== (3-5 分钟): 讲清三个问题——
   - 解决什么问题? 给谁用?
   - 整体结构: 分成哪些模块/函数? 数据怎么组织?
   - 最难的一点是什么? 怎么解决的?

3. ==提问== (3-5 分钟): 老师提问 (可能涉及: 为什么这样设计、某个函数的作用、换一种输入会怎样)

<span class="blue">:fa-lightbulb-o:</span> 演示前==先自己多跑几遍==: 换几组输入、试边界情况 (空输入、超大数据)

---


<!-- slide data-notes="" -->


##### 常见问题与准备建议

---

==常见失分点==:

- 演示时程序崩溃 (边界输入没试过)

- 讲不清代码结构 ("这段是别人给我的" / "AI 生成的, 我没细看")

- 答辩答不上"为什么" (如: 为什么用结构体不用数组?)

==准备建议==:

- 组内==互相讲一遍==, 确保每个人都能讲清整体结构

- 准备==最小可运行版本==: 即使高级功能没完成, 核心功能必须能演示

- AI 用过的部分, ==自己必须读懂每一行==——老师会问

---


<!-- slide data-notes="" -->


##### AI 使用规范 (务必遵守)

---

<div style="font-size:0.9em;line-height:1.6;">

==允许==: 用 AI 解释报错、生成测试数据、对比不同写法、帮你检查边界情况

==不允许==: 整段生成后不理解就提交; 让 AI 替你想设计、替你答辩

==三条要求==:

1. 用 AI 生成或修改过的==每一行==, 自己必须读懂、能解释

2. 技术文档中==注明 AI 参与的部分== (做了什么、你怎么验证的)

3. 答辩时老师会==指定片段==要求现场解释——看不懂的代码不要留

<span class="blue">:fa-lightbulb-o:</span> 课程名字里有"智能": ==会用好 AI 是能力, 判断与理解必须是你自己的==

</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 最后一课: 总复习

---


