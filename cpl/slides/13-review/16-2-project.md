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

## 期末项目答辩

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 项目要求回顾 (代码 + 答辩 + 技术文档)

- 答辩流程与评分标准

- 常见问题与准备建议

- 课程总结

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


##### 一学期的旅程

---

从第一个 Hello World 到今天的项目:

```text
第1周  Hello World / 猜数字        →  让程序跑起来
第2周  变量、类型、输入输出        →  数据进得来、出得去
第3周  表达式与运算                →  算得对
第4-5周 判断与循环                 →  程序会"思考"和"重复"
第6-7周 函数与递归                 →  会分解、会复用
第8-9周 数组与矩阵                 →  处理批量数据
第10-11周 指针与字符串             →  触及内存
第12-13周 结构体与链表             →  组织复杂数据
第14周 文件与多文件                →  数据能保存、代码能分工
第15周 AI 实践                     →  把一切拼起来做一个"聪明"的程序
```

<span class="blue">:fa-lightbulb-o:</span> 这门课学的不是"背语法", 而是==用计算思维解决问题==的能力——它会陪你走很远

---


<!-- slide data-notes="" -->


##### 课程结语

---

==做中学==

- 每一个知识点都走过: 为什么需要 → 是什么 → 怎么用

- OJ 上的每一道题、项目里的每一行代码, 都是你自己的积累

==接着走==

- 想深入 C: 读 K.N. King《C程序设计语言: 现代方法》, 或做更复杂的系统编程

- 想转向应用: Python / C++ / Rust——你在 C 里学的内存、指针、数据结构, 全都用得上

- 想继续 AI: 你会发现框架的每一层都还能看到这两周写过的影子

<span class="blue">:fa-lightbulb-o:</span> 感谢一学期的陪伴, 祝大家在后面的学习和项目里一切顺利!

---


<!-- slide data-notes="" -->

#####

---

<div class="top-2">
  <img src="../figs/see-you.png" width=500px>
</div>

---


