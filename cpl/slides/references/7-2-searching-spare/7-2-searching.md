---
presentation:
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

## 查找与课堂编码

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

<div style="font-size:1.3em;text-align:left;margin-left:2rem;">

- 顺序查找

- 课堂编码 (排序/二分复习 + 挑战)

- 课堂小测
</div>

---


<!-- slide data-notes="" -->


##### 顺序查找

---

从第一个元素开始==逐个比较==, 找到即停

```C
/* 顺序查找: 在 a[0..n-1] 中找 key (约定: 数组已读入 n 个元素) */
int i;
for (i = 0; i < n; i++) {
  if (a[i] == key) {
    break;                    /* 找到, 提前退出 */
  }
}
if (i < n) {
  printf("找到, 下标 %d\n", i);
} else {
  printf("没找到\n");
}
```

- `i < n` 说明是==提前退出==(找到); `i == n` 说明是==正常结束==(没找到)——第 5 周素数判断用过同样的写法

- 适合无序数据; 平均比较 n/2 次, 最坏 n 次

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

1. 复习: 输入 10 个数, 用选择排序从小到大排好并输出

2. 复习: 在有序数组上, 输入一个数, 用二分查找输出下标; 找不到输出 `not found` (周二讲过)

3. 挑战: 统计该数在有序数组中出现了几次

<span class="blue">:fa-lightbulb-o:</span> 今天的代码都写在 main 里——后面学了函数把它们函数化

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 顺序查找最坏情况下要比较多少次？平均呢？

2. 100 万个有序元素里二分查找最多比较约几次？

3. 纠错: 二分查找里写 `int mid = low + high / 2;` 有什么问题？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 下周见!

<hr class="width50 center">

## 未完待续

---


