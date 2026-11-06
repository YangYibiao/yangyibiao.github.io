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

## 程序设计与C语言入门

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 什么是计算机

- 计算机与编程语言

- 什么是程序设计语言

- 算法: 计算机如何工作 (找最高分)

- 编程思维与==本课程地图==

- 为什么学习==C语言==

---


<!-- slide data-notes="" -->

##### 思考: 计算机和计算器有什么区别？

---

==问题1==：计算机和==计算器==有什么区别？

<div style="display:flex;gap:24px;margin-top:16px;">

<div style="flex:1;text-align:center;">
<svg viewBox="0 0 200 250" style="max-width:100%;height:240px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<rect x="40" y="10" width="120" height="225" rx="12" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2.5"/>
<rect x="55" y="26" width="90" height="38" rx="4" fill="#073642"/>
<text x="100" y="52" font-size="20" fill="#93a1a1" text-anchor="middle" font-family="Menlo,monospace">12 + 34</text>
<g font-size="14" fill="#073642" font-family="Menlo,monospace">
<rect x="55" y="78" width="18" height="22" rx="3" fill="#eee8d5"/><text x="64" y="94" text-anchor="middle">7</text>
<rect x="79" y="78" width="18" height="22" rx="3" fill="#eee8d5"/><text x="88" y="94" text-anchor="middle">8</text>
<rect x="103" y="78" width="18" height="22" rx="3" fill="#eee8d5"/><text x="112" y="94" text-anchor="middle">9</text>
<rect x="127" y="78" width="18" height="22" rx="3" fill="#b58900"/><text x="136" y="94" text-anchor="middle">+</text>
<rect x="55" y="104" width="18" height="22" rx="3" fill="#eee8d5"/><text x="64" y="120" text-anchor="middle">4</text>
<rect x="79" y="104" width="18" height="22" rx="3" fill="#eee8d5"/><text x="88" y="120" text-anchor="middle">5</text>
<rect x="103" y="104" width="18" height="22" rx="3" fill="#eee8d5"/><text x="112" y="120" text-anchor="middle">6</text>
<rect x="127" y="104" width="18" height="22" rx="3" fill="#b58900"/><text x="136" y="120" text-anchor="middle">-</text>
<rect x="55" y="130" width="18" height="22" rx="3" fill="#eee8d5"/><text x="64" y="146" text-anchor="middle">1</text>
<rect x="79" y="130" width="18" height="22" rx="3" fill="#eee8d5"/><text x="88" y="146" text-anchor="middle">2</text>
<rect x="103" y="130" width="18" height="22" rx="3" fill="#eee8d5"/><text x="112" y="146" text-anchor="middle">3</text>
<rect x="127" y="130" width="18" height="22" rx="3" fill="#b58900"/><text x="136" y="146" text-anchor="middle">×</text>
<rect x="55" y="156" width="42" height="22" rx="3" fill="#dceaf5"/><text x="76" y="172" text-anchor="middle">0</text>
<rect x="103" y="156" width="18" height="22" rx="3" fill="#eee8d5"/><text x="112" y="172" text-anchor="middle">.</text>
<rect x="127" y="156" width="18" height="22" rx="3" fill="#dc322f"/><text x="136" y="172" text-anchor="middle" fill="#fdf6e3">=</text>
</g>
</g>
</svg>
<div style="font-size:0.85em;color:#586e75;">计算器: 只能算数, 功能写死在硬件里</div>
</div>

<div style="flex:1;text-align:center;">
<svg viewBox="0 0 220 250" style="max-width:100%;height:240px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<rect x="15" y="10" width="190" height="140" rx="10" fill="#fdf6e3" stroke="#268bd2" stroke-width="3"/>
<rect x="28" y="24" width="164" height="112" rx="4" fill="#073642"/>
<rect x="40" y="36" width="70" height="50" rx="3" fill="#268bd2"/>
<rect x="120" y="36" width="60" height="38" rx="3" fill="#859900"/>
<rect x="40" y="96" width="90" height="12" rx="2" fill="#93a1a1"/>
<rect x="40" y="114" width="60" height="8" rx="2" fill="#586e75"/>
<text x="60" y="66" font-size="13" fill="#fdf6e3">程序 A</text>
<text x="140" y="59" font-size="13" fill="#fdf6e3">程序 B</text>
<rect x="95" y="150" width="30" height="14" fill="#93a1a1"/>
<rect x="62" y="164" width="96" height="12" rx="4" fill="#93a1a1"/>
</g>
</svg>
<div style="font-size:0.85em;color:#586e75;">计算机: 装什么程序, 就能做什么事</div>
</div>

</div>

---


<!-- slide data-notes="" -->

##### 问题1 的答案: 为什么计算机什么都能做？

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.9em;line-height:1.6;">

- 区别1: ==存储==——计算机有内存与外存, 可长期保存海量数据; 计算器只能暂存几个数

- 区别2: ==可编程==——计算器的功能固化在硬件里; 计算机装什么程序, 就能做什么事

- 区别3: ==处理的信息==——文本、图像、声音、视频; 计算器只会数值运算

- 点睛: 打开计算器 App, 计算机就能当计算器用, 计算器却永远变不成计算机

- 彩蛋: 计算器其实也是一种小计算机——区别不在"有没有芯片", 而在"程序能不能换"

==程序是计算机的灵魂==——我们要学的, 就是怎么给这台万能机器写指令

</div>

<div style="flex:1;display:flex;flex-direction:column;gap:14px;">

<div style="text-align:center;">
<svg viewBox="0 0 130 70" style="max-width:100%;height:72px;">
<g>
<ellipse cx="65" cy="14" rx="44" ry="10" fill="#b58900"/>
<path d="M21 14 v40 a44 10 0 0 0 88 0 v-40" fill="none" stroke="#b58900" stroke-width="3"/>
<path d="M21 34 a44 10 0 0 0 88 0" fill="none" stroke="#b58900" stroke-width="2"/>
</g>
</svg>
<div style="font-size:0.8em;color:#586e75;">存储: 海量数据长期保存</div>
</div>

<div style="text-align:center;">
<svg viewBox="0 0 130 70" style="max-width:100%;height:72px;">
<g>
<path d="M42 20 L22 35 L42 50" fill="none" stroke="#268bd2" stroke-width="5" stroke-linecap="round" stroke-linejoin="round"/>
<path d="M88 20 L108 35 L88 50" fill="none" stroke="#268bd2" stroke-width="5" stroke-linecap="round" stroke-linejoin="round"/>
<rect x="54" y="28" width="22" height="14" rx="3" fill="#268bd2"/>
</g>
</svg>
<div style="font-size:0.8em;color:#586e75;">可编程: 装什么程序, 就能做什么事</div>
</div>

<div style="text-align:center;">
<svg viewBox="0 0 160 70" style="max-width:100%;height:72px;">
<g>
<rect x="6" y="16" width="40" height="36" rx="3" fill="none" stroke="#dc322f" stroke-width="3"/>
<path d="M12 46 L22 32 L31 40 L37 30 L46 46 Z" fill="#dc322f"/>
<path d="M72 22 q9 -11 18 0 v20 q-9 -6 -18 0" fill="#859900"/>
<circle cx="90" cy="19" r="4" fill="#859900"/>
<rect x="112" y="19" width="34" height="32" rx="6" fill="#268bd2"/>
<path d="M123 28 L123 42 L138 35 Z" fill="#fdf6e3"/>
</g>
</svg>
<div style="font-size:0.8em;color:#586e75;">多媒体: 文本、图像、声音、视频</div>
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 什么是计算机: 硬件 + 软件

---

程序跑在哪？——计算机。先认识这台机器:

计算机: 由==硬件==和==软件==组成, 用于==接收、处理和存储数据==的电子设备

- 硬件：输入设备、输出设备、存储设备、CPU、内存、主板等物理组件

- 软件：操作系统、应用程序等，执行各种任务

---


<!-- slide data-notes="" -->

##### 计算机如何工作: 输入 → 处理 → 存储 → 输出

---

程序在这台机器上跑, 靠的是五个环节:

<div style="display:flex;align-items:center;gap:20px;">

<div style="flex:1.25;">

- ==输入==：键盘、鼠标、摄像头等接收数据和指令

- ==处理==：CPU 执行指令，进行数据处理和计算

- ==存储==：内存临时存储正在处理的数据；存储设备长期保存信息

- ==输出==：显示器、打印机、扬声器等呈现处理结果

- ==控制==：操作系统和应用程序管理硬件资源，协调各组件

==编程==: 使用特定的==编程语言==编写指令, 控制计算机执行上述任务

</div>

<div style="flex:1;">
  <img src="figs/howcomputerworks.png" style="max-width:100%;">
</div>

</div>

---


<!-- slide data-notes="" -->

##### 为什么需要高级语言

---

怎么指挥这台机器？它只懂 ==0 和 1== 组成的==机器指令==——语言是这样一步步进化来的:

<div class="fullborder">

| 语言 | 长这样 | 问题/特点 |
| :-- | :-- | :-- |
| 机器语言 | `10110000 00001100`<br>`00101100 00000101` | 难记、易错、依赖具体机器 |
| 汇编语言 | `MOV AL,12D`<br>`SUB AL,5D` | 助记符好记了, 但仍与机器绑定 |
| 高级语言 | `result = 12 - 5;` | 接近自然语言和数学==与机器无关== |

</div>

- 高级语言写的代码==需要翻译==才能执行——这个"翻译官"就是==编译器==

- 好处: 易学易用、易读易调试、==可移植==(换台机器不用重写)

- C 是高级语言中==离硬件最近==的一个: 既好用, 又高效

---
<!-- slide data-notes="" -->

##### 程序设计语言: 人与计算机沟通的工具

---

高级语言也是语言——先回到更基本的问题:

人类交流 → 机器交流

- 人类要交流需要语言（中文、英文）

- 人和计算机交流也需要"语言"——程序设计语言

对比：自然语言 vs 程序语言

- 自然语言灵活但有歧义
  - 如: ==南京市长江大桥==——是"南京市 · 长江大桥", 还是"南京市长 · 江大桥"?

- 程序语言严格、无歧义，让机器可以准确执行

==程序设计语言，就是人类和计算机沟通的工具==

---


<!-- slide data-notes="" -->

##### 程序能做什么: 排序、游戏、自动驾驶

---

==程序是计算机的灵魂==, 那程序能做什么?

1. 排序一组成绩/批改试卷/统计单词个数等

2. 游戏、微信、自动驾驶背后都是程序

---


<!-- slide data-notes="" -->

##### 思考: 如何让计算机找最高分？

---

程序这么能干, 是怎么"想"出来的？先看一个小问题:

==问题2==：给全班 100 个同学的成绩，怎么让计算机找出最高分？

<span class="blue">:fa-lightbulb-o:</span> 提示: 你不能让它"看一眼"，只能一步步指挥它

---


<!-- slide data-notes="" -->

##### 算法: 找最高分

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.2;font-size:0.9em;line-height:1.6;">

- ==问题2 的答案==: 人扫一眼就能找到最高分, 但计算机不能"看"

- 计算机的做法:
  1. ==假设==第一个成绩是最高分
  2. ==逐个比较==剩下的成绩
  3. 遇到更大的就==替换==
  4. 比较完, 剩下的一定是最高分

- 启示: 人觉得简单的事, 计算机需要一个==算法==

- 程序 = ==算法 + 数据==

</div>

<div style="flex:1;text-align:center;">
<svg viewBox="0 0 400 195" style="max-width:100%;height:300px;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<text x="20" y="18" font-size="14" fill="#586e75">逐个读入 (扫描方向 →)</text>
<text x="380" y="18" font-size="14" fill="#859900" text-anchor="end">遇到更大就替换</text>
<rect x="20" y="28" width="56" height="44" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="48" y="58" font-size="28" fill="#073642" text-anchor="middle">78</text>
<rect x="90" y="28" width="56" height="44" rx="6" fill="#dceaf5" stroke="#859900" stroke-width="3"/>
<text x="118" y="58" font-size="28" fill="#073642" text-anchor="middle">92</text>
<rect x="160" y="28" width="56" height="44" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="188" y="58" font-size="28" fill="#073642" text-anchor="middle">65</text>
<rect x="230" y="28" width="56" height="44" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="258" y="58" font-size="28" fill="#073642" text-anchor="middle">88</text>
<rect x="300" y="28" width="56" height="44" rx="6" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="328" y="58" font-size="28" fill="#073642" text-anchor="middle">71</text>
<line x1="48" y1="72" x2="48" y2="102" stroke="#93a1a1" stroke-width="1.2"/>
<line x1="118" y1="72" x2="118" y2="102" stroke="#859900" stroke-width="2"/>
<line x1="188" y1="72" x2="188" y2="102" stroke="#93a1a1" stroke-width="1.2"/>
<line x1="258" y1="72" x2="258" y2="102" stroke="#93a1a1" stroke-width="1.2"/>
<line x1="328" y1="72" x2="328" y2="102" stroke="#93a1a1" stroke-width="1.2"/>
<rect x="20" y="104" width="56" height="32" rx="5" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
<text x="48" y="126" font-size="20" fill="#586e75" text-anchor="middle">78</text>
<rect x="90" y="104" width="56" height="32" rx="5" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
<text x="118" y="126" font-size="20" fill="#859900" text-anchor="middle">92</text>
<rect x="160" y="104" width="56" height="32" rx="5" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
<text x="188" y="126" font-size="20" fill="#859900" text-anchor="middle">92</text>
<rect x="230" y="104" width="56" height="32" rx="5" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
<text x="258" y="126" font-size="20" fill="#859900" text-anchor="middle">92</text>
<rect x="300" y="104" width="56" height="32" rx="5" fill="#e8f0d8" stroke="#859900" stroke-width="2"/>
<text x="328" y="126" font-size="20" fill="#859900" text-anchor="middle">92</text>
<text x="20" y="160" font-size="14" fill="#586e75">上排是成绩, 下排是读到这里时手里的最高分</text>
<text x="20" y="181" font-size="14" fill="#859900">92 比 78 大 → 替换; 后面都比 92 小 → 不再换</text>
</g>
</svg>
</div>

</div>

---



<!-- slide data-notes="" -->

##### 计算机如何工作: 找最高分

---

把刚才的算法放回机器的工作流程, 每一步对应哪个环节?

1. ==输入==: 逐个读入成绩

2. ==处理==: 与当前最高分比较, 更大就替换

3. ==存储==: 记住当前最高分 (内存)

4. ==输出==: 比较完, 打印最高分

---


<!-- slide data-notes="" -->

##### 编程思维: 结构 + 数据 + 设计

---

回头看"找最高分"的步骤, 写程序需要的东西全在里面:

- ==结构==: 顺序 (一步步执行)、判断 (if: 更大就替换)、循环 (重复比较, 直到比完)

- ==数据==: 存储——记住当前最高分 (变量)

- ==设计==: 分解——大问题拆成小步骤

接下来要学的, 就是把这些要素用 ==C 语言== 写出来!

---


<!-- slide data-notes="" -->

##### 程序需要什么: 本课程地图

---

==编程思维==要落地, 还需要具体工具——从 ==输入 → 处理 → 存储 → 输出== 反推:

<div class="fullborder">

| 程序的需求 | 需要的元素 | 什么时候学 |
| :-- | :-- | :-- |
| 记住数据 | 变量、类型 | 第 1-2 周 |
| 计算 | 表达式、运算符 | 第 3 周 |
| 不同情况做不同事 | 判断 if / switch | 第 4 周 |
| 重复做 | 循环 while / for | 第 5 周 |
| 一批数据 | 数组、排序与查找 | 第 6-7 周 |
| 复用与分解 | 函数、递归 | 第 8-9 周 |
| 内存与地址 | 指针 | 第 10-11 周 |
| 字符串 | 字符串处理、函数指针 | 第 12 周 |
| 复杂的数据组织 | 结构体、链表 | 第 13 周 |
| 长期保存数据 | 文件、多文件 | 第 14 周 |
| 综合应用 | 期末项目、总复习 | 第 15 周 |

</div>

<span class="blue">:fa-lightbulb-o:</span> 每一项都是"==因为需要, 所以才有=="——这就是本学期的路线图; 接下来就动手写第一个 C 程序:

---
