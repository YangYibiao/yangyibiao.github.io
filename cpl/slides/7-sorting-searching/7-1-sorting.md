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
<style>.reveal pre code{max-height:none!important}</style>

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

- 什么是排序、为什么需要排序

- 三种排序: 选择、冒泡、插入 + 对比小结 (原理与图示 → 代码)

- 顺序查找: 逐个比; 二分查找: 排好序, 每次砍掉一半

- 案例: 众数统计 (排序 + 扫描)

- 课堂小测
</div>

---


<!-- slide data-notes="" -->


##### 什么是排序 · 为什么需要排序

---

<div style="display:grid;grid-template-columns:1fr 1.15fr;gap:18px;align-items:start;">

<div>

==排序==: 把一组数据按某种规则整理成有序

- 数值: 从小到大(升序)或从大到小(降序)

- 字符串: 按字典序

- 例: [8,3,5] 升序 → [3,5,8]; 降序 → [8,5,3]

<div style="font-size:0.7em;color:var(--solarized-base00);margin-top:4px;">
字典序 = 像查字典那样逐字符比较: 先比第一个字符, 相同再比下一个 —— 如 "apple" 排在 "banana" 前, "zhang" 排在 "zhao" 前
</div>

</div>

<div>

成绩排名、字典、电话簿……==有序==的数据才好用

- 排名: 全班机试成绩乱序, 谁第 1、前 10 是谁? —— 排序后才有答案

- 查找: 排好序才能用二分查找, 100 万个数据从约 50 万次比较降到约 20 次

- 地基: 去重、统计、合并都建立在有序之上

</div>

</div>

<span class="blue">:fa-lightbulb-o:</span> 之前把数据装进数组, 今天给它们排队; 开学时说的排序, 今天实现

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
  for (int j = i + 1; j < n; j++) {  /* 往后找更小的 */
    if (a[j] < a[min]) {
      min = j;
    }
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

<div style="display:grid;grid-template-columns:1fr 1.3fr;gap:16px;align-items:center;">

<div>

相邻元素两两比较, 顺序不对就交换

- 第 1 轮: 从头比到尾, 最大的元素一路"沉"到 a[n-1]

- 第 2 轮: 再比一遍, 次大的沉到 a[n-2] (末尾已就位, 少比一个)

- 共 n-1 轮; 每一轮结束, 本轮最大的元素"沉底"

<div style="font-size:0.7em;color:var(--solarized-base00);margin-top:6px;">
相邻比较、逐个交换, 最大的逐步"沉"到末尾
</div>

</div>

<div style="text-align:center;">
  <img src="figs/bubble-sort-steps.png" style="max-width:100%;">
</div>

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

<div style="display:grid;grid-template-columns:1fr 1.3fr;gap:16px;align-items:center;">

<div>

像打牌理手牌: 每次拿起一张, 插到已排序部分的正确位置

- 左手: 已排序的牌, 起初只有 a[0]

- 右手: 每次拿起下一张 key = a[i]

- 从右往左比: 比 key 大的往后挪一格, 找到位置把 key 放进去

<div style="font-size:0.7em;color:var(--solarized-base00);margin-top:6px;">
已排序部分逐步变长, 每个 key 与前面的元素比较、右移, 再插到正确位置
</div>

</div>

<div style="text-align:center;">
  <img src="figs/insertion-sort-steps.png" style="max-width:100%;">
</div>

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
  int j;                                   /* 循环后还要用 j */
  for (j = i - 1; j >= 0 && a[j] > key; j--) {  /* 比 key 大的往后挪 */
    a[j + 1] = a[j];
  }
  a[j + 1] = key;                          /* 放进去 */
}
```

- 三种排序都是 ==O(n²)==——数据量不大时完全够用

<div style="margin-top:6px;font-size:0.7em;background:rgba(38,139,210,0.06);border-left:4px solid #268bd2;border-radius:4px;padding:4px 10px;line-height:1.6;">
内层 for 退出时: j 停在第一个 ==≤ key== 的元素 (或 -1), 位置 a[j+1] 已空出, key 正好放进去。<br>
例: [2, 5] 插 key=4 —— j 从 1 开始: a[1]=5 &gt; 4 → 右移, j 变 0; a[0]=2 ≤ 4 → 停, 退出时 j = 0, 放入 a[1] → [2, 4, 5]
</div>

</div>

<div style="text-align:center;">
  <img src="figs/insertion-sort.gif" width=420px>
</div>

</div>

---


<!-- slide data-notes="" -->##### 三种排序 · 对比小结

---

<div class="fullborder" style="font-size:0.62em;">

| 算法 | 平均/最坏时间 | 最好情况 | 空间 | 稳定性 | 特点 |
| :-- | :-- | :-- | :-- | :-- | :-- |
| 选择排序 | O(n²) / O(n²) | O(n²) | O(1) | ==不稳定== | 每轮只==交换一次==, 交换次数最少 |
| 冒泡排序 | O(n²) / O(n²) | O(n) (已有序) | O(1) | ==稳定== | 相邻比较, 大数像气泡上浮 |
| 插入排序 | O(n²) / O(n²) | O(n) (接近有序) | O(1) | ==稳定== | 像整理手牌, ==基本有序时最快== |

</div>

- ==稳定性==: 相等元素排序后保持原有先后——按"班级+成绩"排序时会用到

- ==怎么选==: 数据量小或接近有序 → 插入排序; 只关心交换代价 → 选择排序; 教学演示 → 冒泡排序

- 三者都是 O(n²); 想更快, 要靠后面分治思想引出的快速排序 (递归部分细讲)

<!-- slide data-notes="" -->


##### 顺序查找

---

<div style="font-size:0.8em;color:var(--solarized-base00);margin:0 2rem 2px;text-align:left;">排序之后进入==查找==: 在数据里找到目标。无序只能逐个比 (平均 n/2 次); 有序才能每次砍掉一半 (约 log2(n) 次, 下页) —— 先看顺序查找</div>

从第一个元素开始==逐个比较==, 找到即停

<div style="display:grid;grid-template-columns:1.5fr 1fr;gap:14px;align-items:center;">

<div>

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

</div>

<div>

<div style="text-align:center;">
<svg viewBox="0 0 400 170" style="max-width:100%;height:165px;">
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="200" y="18" font-size="11.5" fill="#586e75" text-anchor="middle">100 万个数据中查找一个数 (平均比较次数)</text>

    <text x="14" y="61" font-size="12.5" fill="#073642">顺序查找</text>
    <rect x="100" y="42" width="272" height="28" rx="3" fill="#dc322f"/>
    <text x="366" y="61" font-size="11.5" fill="#fdf6e3" text-anchor="end">≈ 500,000 次</text>

    <text x="14" y="110" font-size="12.5" fill="#073642">二分查找</text>
    <rect x="100" y="92" width="8" height="28" rx="2" fill="#859900"/>
    <line x1="110" y1="106" x2="128" y2="106" stroke="#859900" stroke-width="1.5"/>
    <text x="134" y="110" font-size="12.5" fill="#859900">≈ 20 次</text>

    <text x="200" y="140" font-size="11" fill="#586e75" text-anchor="middle">每次砍掉一半:1,000,000 → 500,000 → … → 1</text>
    <text x="200" y="160" font-size="11.5" fill="#268bd2" text-anchor="middle">有序,才敢这么砍——这就是排序的价值</text>
  </g>
</svg>
</div>

- `i < n` 说明是==提前退出==(找到); `i == n` 说明是==正常结束==(没找到)——之前素数判断用过同样的写法

- 适合无序数据; 平均比较 n/2 次, 最坏 n 次

</div>

</div>

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

<div style="display:grid;grid-template-columns:1.5fr 1fr;gap:14px;align-items:center;">

<div>

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

</div>

<div style="text-align:center;">
  <img src="figs/binary-search-steps.png" style="max-width:100%;">
</div>

</div>

---


<!-- slide data-notes="" -->


##### 众数统计 · 问题与现场编码

---

<div style="display:grid;grid-template-columns:1.15fr 1fr;gap:22px;align-items:start;">

<div>

输入 n 个==无序==的数 (1 ≤ n ≤ 100), 输出出现次数最多的数(众数)及其出现次数; 若多个数并列, 输出==最小==的那个

<div style="margin-top:8px;font-size:0.8em;line-height:1.8;">

样例输入: `7` 与 `1 2 2 3 2 5 7`

样例输出: `2 3`

</div>

<span class="blue">:fa-lightbulb-o:</span> 提示: 先==排序==, 再观察有序数组里 "相同的数" 有什么特点

</div>

<div>

==现场演示==

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/7-sorting-searching/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 打开 skeleton.c (骨架)</a>

1. 思路: 先排序 (任选一种, 正好复习) → 相同的数相邻 → 一遍扫描统计每段长度 → 找最长段

2. 学生先写 10 分钟, 再一起看参考代码

3. 引导提问: 最后一段什么时候 "结算"? 并列时怎么保证输出最小的?

</div>

</div>

---


<!-- slide data-notes="" -->


##### 众数统计 · 代码

---

```C
/* 众数统计 (约定: a[0..n-1] 已读入 n 个数, 且已从小到大排好序) */
int best = a[0], best_cnt = 1;    /* 众数与出现次数 */
int cur = a[0], cur_cnt = 1;      /* 当前这一段 */
for (int i = 1; i <= n; i++) {
  if (i < n && a[i] == cur) {
    cur_cnt++;
  } else {                        /* 这一段结束了 */
    if (cur_cnt > best_cnt) {     /* 只更新更大的, 并列保留最小的 */
      best = cur;
      best_cnt = cur_cnt;
    }
    if (i < n) {
      cur = a[i];
      cur_cnt = 1;
    }
  }
}
printf("%d %d\n", best, best_cnt);
```

- 循环条件 `i <= n`: `i == n` 时也要==结算最后一段==; 用 `>` 而非 `>=`: 升序扫描, 并列时自然保留==最小==

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

<hr class="width50 center">

## 未完待续

---


