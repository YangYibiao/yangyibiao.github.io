---
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../css/theme/solarized.css"
@import "../css/logo.css"
@import "../css/font.css"
@import "../css/color.css"
@import "../css/margin.css"
@import "../css/table.css"
@import "../css/main.css"
@import "../plugin/zoom/zoom.js"
@import "../plugin/customcontrols/plugin.js"
@import "../plugin/customcontrols/style.css"
@import "../plugin/chalkboard/plugin.js"
@import "../plugin/chalkboard/style.css"
@import "../plugin/menu/menu.js"
@import "../js/anychart/anychart-core.min.js"
@import "../js/anychart/anychart-venn.min.js"
@import "../js/anychart/pastel.min.js"
@import "../js/anychart/venn-ml.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## Loops编程实践


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- Selection Sort

- Bubble Sort

- Merge Sort

- Binary Search

- Conway's Game of Life


<!-- slide data-notes="" -->



##### Selection Sort

---

<div class="top-2">
  <img src="../img/selectionsort.png" width=400px>
</div>



<!-- slide vertical=true data-notes="" -->

##### Bubble Sort

---

<div class="top-2">
  <img src="../img/bubblesort.png" height=500px>
</div>


<!-- slide vertical=true data-notes="" -->

##### Merge Sort

---

<div class="top-2">
  <img src="../img/mergeSort.png" height=500px>
</div>

<!-- slide vertical=true data-notes="" -->



##### Convey's Game of Life

---

At each step in time, the following transitions occur:

- Any live cell with fewer than two live neighbours dies, as if by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


<!-- slide vertical=true data-notes="" -->



##### Convey's Game of Life

---

设定细胞处于ON（活）或OFF（死）状态，然后为每个细胞分配一个初始状态，由数学规则决定其状态如何随时间而改变

Conway「生命游戏」的4个规则：

- 如果一个细胞为ON，邻居中少于两个为ON，它变为OFF。（模拟生命数量过少）
- 如果一个细胞为ON，邻居中有两个或3个为ON，它保持为ON。
- 如果一个细胞为ON，邻居中超过3个为ON，它变为OFF。（模拟生命数量过多）
- 如果一个细胞为OFF，邻居中恰好有3个为ON，它变为ON。（模拟繁殖）