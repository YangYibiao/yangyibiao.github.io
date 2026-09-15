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

## 排序与查找

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 为什么排序与查找

- 三种排序: 选择、冒泡、插入

- 查找: 顺序查找与二分查找

- 递归排序预告: 快速排序

---


<!-- slide data-notes="" -->


##### 为什么排序与查找

---

成绩排名、字典、数据库……==排序==和==查找==是程序处理数据的基本功

- 排序: 把一组数据按大小整理好

- 查找: 在一组数据中找到目标

<span class="blue">:fa-lightbulb-o:</span> 第 1 周的冒泡排序预告, 今天正式实现!

---


<!-- slide data-notes="" -->


##### 选择排序

---

每一轮从剩余元素中==选出最小==的, 放到前面

<div class="top-2">
  <img src="../3-for-a-while/figs/selection-sort.png" width=420px>
</div>

```C
void selection_sort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[min])
        min = j;
    int t = a[i]; a[i] = a[min]; a[min] = t;
  }
}
```

---


<!-- slide data-notes="" -->


##### 冒泡排序

---

相邻元素两两比较, 顺序不对就交换, 一轮后最大的元素"沉"到最后

```C
void bubble_sort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)           /* 共 n-1 轮 */
    for (int j = 0; j < n - 1 - i; j++)     /* 每轮少比一个 */
      if (a[j] > a[j + 1]) {
        int t = a[j];
        a[j] = a[j + 1];
        a[j + 1] = t;
      }
}
```

---


<!-- slide data-notes="" -->


##### 插入排序

---

像打牌理手牌: 每次拿起一张, 插到已排序部分的正确位置

```C
void insertion_sort(int a[], int n)
{
  for (int i = 1; i < n; i++) {
    int key = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > key) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = key;
  }
}
```

---


<!-- slide data-notes="" -->


##### 顺序查找

---

从第一个元素开始==逐个比较==, 找到即停

```C
int linear_search(int a[], int n, int key)
{
  for (int i = 0; i < n; i++)
    if (a[i] == key)
      return i;      /* 找到, 返回下标 */
  return -1;          /* 没找到 */
}
```

- 适合无序数据; 平均比较 n/2 次, 最坏 n 次

---


<!-- slide data-notes="" -->


##### 二分查找

---

数据==排好序==后, 可以每次砍掉一半: 和中间元素比较, 决定去左半边还是右半边

<div class="top-2">
  <img src="../3-for-a-while/figs/binary-search-mario.png" width=420px>
</div>

```C
int binary_search(int a[], int n, int key)
{
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == key) return mid;
    if (a[mid] < key) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}
```

- n 个元素最多比较 log2(n)+1 次——100 万个数也只要约 20 次!

---


<!-- slide data-notes="" -->


##### 递归排序预告: 快速排序

---

用第 7 周的==递归==做排序: 选一个基准, 小的放左、大的放右, 再对左右递归

```C
void quicksort(int a[], int low, int high)
{
  if (low >= high) return;        /* 基准情形 */
  int p = partition(a, low, high); /* 划分 */
  quicksort(a, low, p - 1);
  quicksort(a, p + 1, high);
}
```

- 平均 O(n log n), 比冒泡/选择/插入的 O(n^2) 快得多

- 课后有兴趣可以看课件目录里的完整 quicksort 实现

---


<!-- slide data-notes="" -->


##### 课堂编码

---

==现场演示==

1. 输入 10 个数, 用冒泡排序从小到大输出

2. 输入一个数, 在有序数组中用二分查找找到它

---


<!-- slide data-notes="" -->


##### 课堂小测

---

1. 选择排序每一轮做什么？总共需要几轮？

2. 冒泡排序一轮结束后，什么元素"就位"了？

3. 二分查找的前提条件是什么？100 万个元素最多比较几次？

4. 快速排序和前面三种排序的本质区别是什么？

---


<!-- slide data-notes="" -->


#####

---

<div class="bottom20"></div>

# 周三见!

<hr class="width50 center">

## 未完待续

---


