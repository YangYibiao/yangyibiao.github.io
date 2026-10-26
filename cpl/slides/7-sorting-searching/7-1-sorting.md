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

## 排序

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

<div style="font-size:1.3em;text-align:left;margin-left:2rem;">

- 为什么排序

- 三种排序: 选择、冒泡、插入 (原理与图示 → 代码)

- 二分查找: 排好序, 每次砍掉一半

- 课堂编码

- 课堂小测
</div>

---


<!-- slide data-notes="" -->


##### 为什么排序

---

==排序==: 把一组数据按某种规则整理成有序 —— 数值可以从大到小(降序)或从小到大(升序), 字符串可以按字典序

<div style="font-size:0.7em;color:var(--solarized-base00);margin-top:4px;">
字典序 = 像查字典那样逐字符比较: 先比第一个字符, 相同再比下一个 —— 如 "apple" 排在 "banana" 前, "zhang" 排在 "zhao" 前
</div>

成绩排名、字典、电话簿……==有序==的数据才好用

- 排名: 全班机试成绩乱序, 谁第 1、前 10 是谁? —— 排了才知道

- 查找: 排好序才能用二分查找, 100 万个数据从约 50 万次比较降到约 20 次

- 地基: 去重、统计、合并都建立在有序之上

<span class="blue">:fa-lightbulb-o:</span> 第 6 周把数据装进数组, 今天给它们排队; 第 1 周 "程序能做什么" 里的排序, 今天实现出来

---


<!-- slide data-notes="" -->


##### 选择排序

---

<div style="display:grid;grid-template-columns:1fr 1fr;gap:16px;align-items:center;">

<div>

每一轮从剩余元素中==选出最小==的, 放到前面

- 第 1 轮: 在 a[0..n-1] 里找最小, 换到 a[0]

- 第 2 轮: 在 a[1..n-1] 里找最小, 换到 a[1]

- 依此类推, 共 n-1 轮; 第 i 轮结束时 a[0..i] 已经有序

<div style="font-size:0.7em;color:var(--solarized-base00);margin-top:6px;">
每一轮: 在未排序部分挑出最小的, 与未排序部分的第一个交换
</div>

</div>

<div style="text-align:center;">
  <img src="figs/selection-sort.png" height=530px>
</div>

</div>

---


<!-- slide data-notes="" -->


##### 选择排序 · 代码

---

<div style="display:grid;grid-template-columns:1.5fr 1fr;gap:14px;align-items:center;">

<div>

```C
/* 选择排序 (约定: a[0..n-1] 已读入 n 个元素) */
for (int i = 0; i < n - 1; i++) {
  int min = i;                       /* 先假设 a[i] 最小 */
  for (int j = i + 1; j < n; j++)    /* 往后找更小的 */
    if (a[j] < a[min]) {
      min = j;
    }
  int t = a[i]; a[i] = a[min]; a[min] = t;  /* 交换 */
}
```

- 一共 n-1 轮, 第 i 轮结束后 a[0..i] 已经有序

</div>

<div style="text-align:center;">
  <img src="figs/selection-sort-anim.gif" width=400px>
</div>

</div>

<span class="blue">:fa-lightbulb-o:</span> 后面学了函数, 就能把这整段封装成 `sort(a, n)` 随时调用

---


<!-- slide data-notes="" -->


##### 冒泡排序

---

相邻元素两两比较, 顺序不对就交换 —— 一轮结束最大的元素"沉"到最后, 每轮少比一个, 共 n-1 轮

<div style="text-align:center;">

<svg viewBox="0 0 840 330" style="max-width:100%;height:auto;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="60" y="30" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="115" y="65">5</text>
<rect x="190" y="30" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#cb4b16" stroke-width="3"/>
<text x="245" y="65">8</text>
<rect x="320" y="30" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="375" y="65">3</text>
<rect x="450" y="30" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="505" y="65">1</text>
<rect x="580" y="30" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="635" y="65">2</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="60" y="96" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="115" y="131">5</text>
<rect x="190" y="96" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="245" y="131">3</text>
<rect x="320" y="96" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#cb4b16" stroke-width="3"/>
<text x="375" y="131">8</text>
<rect x="450" y="96" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="505" y="131">1</text>
<rect x="580" y="96" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="635" y="131">2</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="60" y="162" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="115" y="197">5</text>
<rect x="190" y="162" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="245" y="197">3</text>
<rect x="320" y="162" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="375" y="197">1</text>
<rect x="450" y="162" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#cb4b16" stroke-width="3"/>
<text x="505" y="197">8</text>
<rect x="580" y="162" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="635" y="197">2</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="60" y="228" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="115" y="263">5</text>
<rect x="190" y="228" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="245" y="263">3</text>
<rect x="320" y="228" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="375" y="263">1</text>
<rect x="450" y="228" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2"/>
<text x="505" y="263">2</text>
<rect x="580" y="228" width="110" height="54" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="635" y="263">8</text>
<text x="700" y="263" font-size="18" fill="#859900" text-anchor="start">沉底 ✓</text>
</g>
<g stroke="#586e75" stroke-width="2" fill="none">
<path d="M 255 84 Q 340 90 365 96" marker-end="url(#arr)"/>
<path d="M 385 150 Q 470 156 495 162" marker-end="url(#arr)"/>
<path d="M 515 216 Q 600 222 625 228" marker-end="url(#arr)"/>
</g>
<defs>
<marker id="arr" markerWidth="8" markerHeight="8" refX="7" refY="4" orient="auto">
<path d="M 0 0 L 8 4 L 0 8 z" fill="#586e75"/>
</marker>
</defs>
<g font-size="18" fill="#586e75" text-anchor="middle">
<text x="330" y="80">8 &gt; 3, 交换</text>
<text x="460" y="146">8 &gt; 1, 交换</text>
<text x="590" y="212">8 &gt; 2, 交换</text>
</g>
</g>
</svg>

</div><div style="text-align:center;font-size:0.7em;color:var(--solarized-base00);margin-top:2px;">
第 1 轮: 相邻比较, 8 一路"沉"到最后; 后面每轮少比一个
</div>

---


<!-- slide data-notes="" -->


##### 冒泡排序 · 代码

---

<div style="display:grid;grid-template-columns:1.5fr 1fr;gap:14px;align-items:center;">

<div>

```C
/* 冒泡排序: 把 a[0..n-1] 从小到大排好 */
for (int i = 0; i < n - 1; i++) {         /* 共 n-1 轮 */
  for (int j = 0; j < n - 1 - i; j++) {   /* 每轮少比一个 */
    if (a[j] > a[j + 1]) {
      int t = a[j];
      a[j] = a[j + 1];
      a[j + 1] = t;
    }
  }
}
```

- 每一轮结束, 本轮==未排序部分的最大元素"沉"到最后==

- 三种排序里过程最形象的一种——相邻比较、逐轮沉底

</div>

<div style="text-align:center;">
  <img src="figs/bubble-sort.gif" width=420px>
</div>

</div>

---


<!-- slide data-notes="" -->


##### 插入排序

---

像打牌理手牌: 每次拿起一张, 插到已排序部分的正确位置 —— 比 key 大的往后挪一格, 找到位置把 key 放进去

<div style="text-align:center;">

<svg viewBox="0 0 900 370" style="max-width:100%;height:auto;">
<g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif" font-weight="700">
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="40" y="20" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="95" y="55">5</text>
<rect x="170" y="20" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#cb4b16" stroke-width="3" stroke-dasharray="7 4"/>
<text x="225" y="55">2</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="40" y="92" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#93a1a1" stroke-width="2" stroke-dasharray="7 4"/>
<rect x="170" y="92" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="225" y="127">5</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="40" y="164" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="95" y="199">2</text>
<rect x="170" y="164" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="225" y="199">5</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="40" y="236" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="95" y="271">2</text>
<rect x="170" y="236" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="225" y="271">5</text>
<rect x="300" y="236" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#cb4b16" stroke-width="3" stroke-dasharray="7 4"/>
<text x="355" y="271">4</text>
</g>
<g font-size="26" text-anchor="middle" fill="#073642">
<rect x="40" y="308" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="95" y="343">2</text>
<rect x="170" y="308" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="225" y="343">4</text>
<rect x="300" y="308" width="110" height="52" rx="8" fill="#fdf6e3" stroke="#859900" stroke-width="3"/>
<text x="355" y="343">5</text>
</g>
<g font-size="20" fill="#586e75" text-anchor="start">
<text x="470" y="54">① 拿起 key = 2</text>
<text x="470" y="126">② 2 &lt; 5, 5 右移一格</text>
<text x="470" y="198">③ 2 放进去</text>
<text x="470" y="270">④ 拿起 key = 4</text>
<text x="470" y="342">⑤ 4 放进去 (5 再右移)</text>
</g>
<g stroke="#586e75" stroke-width="2" fill="none">
<path d="M 225 72 L 225 92" marker-end="url(#arr2)"/>
<path d="M 225 216 L 225 236" marker-end="url(#arr2)"/>
</g>
<defs>
<marker id="arr2" markerWidth="8" markerHeight="8" refX="7" refY="4" orient="auto">
<path d="M 0 0 L 8 4 L 0 8 z" fill="#586e75"/>
</marker>
</defs>
</g>
</svg>

</div>

<div style="text-align:center;font-size:0.7em;color:var(--solarized-base00);margin-top:2px;">
绿框 = 已排序的"左手牌"; 橙虚框 = 新拿起的 key; 比 key 大的依次右移, 再把 key 放进去
</div>

---


<!-- slide data-notes="" -->


##### 插入排序 · 代码

---

<div style="display:grid;grid-template-columns:1.5fr 1fr;gap:14px;align-items:center;">

<div>

```C
/* 插入排序: 把 a[0..n-1] 从小到大排好 */
for (int i = 1; i < n; i++) {
  int key = a[i];                          /* 拿起的"牌" */
  int j = i - 1;
  while (j >= 0 && a[j] > key) {           /* 比 key 大的往后挪 */
    a[j + 1] = a[j];
    j--;
  }
  a[j + 1] = key;                          /* 放进去 */
}
```

- 三种排序都是 ==O(n²)==——数据量不大时完全够用

</div>

<div style="text-align:center;">
  <img src="figs/insertion-sort.gif" width=420px>
</div>

</div>

---


<!-- slide data-notes="" -->


##### 排序与查找

---

==排序==: 把数据按大小整理好 —— 今天前半段已经做完

==查找==: 在数据里找到目标 —— 今天后半段

- 排好序, 查找才能 "快" 起来:

- 无序只能一个个比: 顺序查找, 平均比较 n/2 次

- 有序可以每次砍掉一半: 二分查找, 约 log2(n) 次

<span class="blue">:fa-lightbulb-o:</span> 接下来就用排序的成果, 学二分查找

---


<!-- slide data-notes="" -->


##### 二分查找

---

数据==排好序==后, 可以每次砍掉一半: 和中间元素比较, 决定去左半边还是右半边

<div style="text-align:center;">
  <img src="figs/binary-search-mario.png" width=560px>
</div>

<div style="text-align:center;font-size:0.7em;color:var(--solarized-base00);margin-top:2px;">
每次和中间元素比较, 砍掉不可能的一半
</div>

---


<!-- slide data-notes="" -->


##### 二分查找 · 代码

---

```C
/* 二分查找: a 必须已从小到大排好序 */
int low = 0, high = n - 1;
while (low <= high) {
  int mid = (low + high) / 2;
  if (a[mid] == key) {
    printf("找到, 下标 %d\n", mid);
    break;
  }
  if (a[mid] < key) {
    low = mid + 1;
  } else {
    high = mid - 1;
  }
}
if (low > high) {
  printf("没找到\n");
}
```

- n 个元素最多比较 log2(n)+1 次——100 万个数也只要约 20 次!

- 如果数据没排序, 只能顺序查找: 从头到尾逐个比, 平均比较 n/2 次

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

1. 输入 10 个数, 用冒泡排序从小到大输出

2. 变体: 把冒泡排序改成==从大到小==, 并输出==每一轮结束后==的数组 (观察"沉底"过程)

3. 排好序后, 输入一个数, 用二分查找输出它的下标; 找不到输出 `not found`

---

<!-- slide data-notes="" -->


##### 课堂小测

---

1. 选择排序每一轮做什么？总共需要几轮？

2. 冒泡排序一轮结束后，什么元素"就位"了？

3. 代码阅读: 冒泡排序内层循环写成 `for (j = 0; j < n - 1; j++)` (漏了 `- i`)，会发生什么？

4. 纠错: 交换写成了 `int t = a[i]; a[i] = a[min]; a[min] = a[i];`——交换为什么没生效？

5. 二分查找的前提条件是什么？

6. 纠错: 二分查找里写 `int mid = low + high / 2;` 有什么问题？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


