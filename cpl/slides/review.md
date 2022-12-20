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
@import "https://cdn.bootcdn.net/ajax/libs/jquery/3.5.0/jquery.js"



<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 复习


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_



<!-- slide vertical=true data-notes="" -->

##### 提纲

---

- 复杂声明解析

- 结构体

- 二分查找

- 链表



<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // ???
}
```

<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // + 4 // sizeof(int) == 4
}
```

<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **p = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // ???
}
```

<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int **p = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // + 8  // sizeof(int*) == 8
}
```

<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int (*p)[10] = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // ???
}
```

<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
  int (*p)[10] = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // + 4 * 10 // sizeof(int[10]) == 40
}
```


<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
 int *(*p)[2] = malloc(100);
  printf("%p\n", p); // assume 1000
  p++;
  printf("%p\n", p); // ???
}
```


<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
 int *(*p)[2] = malloc(100);
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // + 2 * 8 // sizeof(int*[2]) == 16
}
```


<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值

---

```C

int (*ff(int))(int *, int); 

// 根据优先律，等价于
int (*(ff(int))(int *, int));
```



<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值

---

```C

int (*ff(int))(int *, int); 

// PF是一个函数指针，指向一个返回值为int的函数
int (*PF)(int *, int); 

// PF是函数指针，作为类型来声明ff(int)
// ff(int)的返回值就是函数指针，即返回值为指向另一个函数的指针
PF ff(int); 
```


<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值

---

```C
int (*ff(int))(int *, int); 

// 作用同上，PF是一个指针，指向一个函数，有返回值，返回值类型即int
typedef int (*PF)(int *,int); 
// PF是函数指针，作为类型来声明ff(int)
// 那么ff(int)的返回值就是函数指针，即返回值为指向另一个函数的指针
PF ff(int);

```



<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值

```C
void (*fone(int s, void (*ftwo)(int))) (int);
```

fone和ftwo类型如何解读?


<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值

```C
void (*fone(int s, void (*ftwo)(int))) (int);
```

ftwo: 函数==指针==, 函数类型: 形式参数int, 返回void类型

fone: ==函数==，参数(int s, ftwo函数指针), 返回函数指针(类型: int参数, 返回void)



<!-- slide vertical=true data-notes="" -->

##### 复杂声明解析:函数指针作为函数的返回值(示例)


```C{.line-numbers}
#include <stdio.h>

double GetMin(double *arr, int size);
double GetMax(double *arr1, int size);
double GetAvg(double *arr3, int size);
double UnKnown(double *arr2, int size);

typedef double (*PF)(double *arr, int size); // 定义函数指针类型
PF GetOperation(char c) { // 根据字符得到操作类型，返回函数指针
  switch (c) {
    case 'd': return GetMax;
    case 'x': return GetMin;
    case 'p': return GetAvg;
    default: return UnKnown;
  }
}

int main(void) {
  double arr[] = {3.14, 1.41, -0.5, 99, -31, 35};
  int size = sizeof(arr) / sizeof(double);
  printf("Please input the Operation :\n");
  char c = getchar();
  PF fp = GetOperation(c);
  printf("Result is %lf\n", fp(arr, size));   // 通过函数指针调用函数
}

double GetMin(double *arr, int size) { // 求最小值
  double min = arr[0];
  for (int i=1; i<size; i++){
    if (min>arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

double GetMax(double *arr, int size) { // 求最大值
  double max = arr[0];
  for (int i=1; i<size; i++){
    if (max<arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

double GetAvg(double *arr, int size) { // 求平均值
  double sum = arr[0];
  for (int i=1; i<size; i++){
    sum += arr[i];
  }
  return sum / size;
}

double UnKnown(double *arr, int size) { // 未知算法
  return 0;
}
```



<!-- slide vertical=true data-notes="" -->

##### 二分查找

---

二分查找算法(英语: binary search algorithm), 也称折半搜索算法(英语: half-interval search algorithm)和对数搜索算法(英语: logarithmic search algorithm), 是一种在 ==有序数组== 中查找某一特定元素的搜索算法. 


搜索过程: 

- 从数组的中间元素开始, 如果中间元素正好是要查找的元素, 则搜索过程结束;

- 如果某一特定元素大于或者小于中间元素, 则在数组大于或小于中间元素的那一半中查找, 而且跟开始一样从中间元素开始比较. 

- 如果在某一步骤数组为空, 则代表找不到. 

我的启示 二分查找算法每一次比较都使搜索范围缩小一半. 

<!-- 二分查找算法核心思想: 不断缩小搜索区域, 降低查找目标元素的难度. 

以在升序序列中查找目标元素为例, 二分查找算法的实现思路是:

- 初始状态下, 将整个序列作为搜索区域(假设为[B, E])

- 找到搜索区域内的中间元素(假设所在位置为M), 和目标元素进行比对. 

  - 若相等, 则搜索成功;
  - 若大于目标元素, 表明目标元素位于 ==中间元素的左侧==, 将[B, M-1]作为新的搜素区域;
  - 若小于目标元素, 表明目标元素位于 ==中间元素的右侧==, 将[M+1, E]作为新的搜素区域;

- 重复执行第二步, 直至找到目标元素. 如果搜索区域无法再缩小, 且区域内不包含任何元素, 表明整个序列中没有目标元素, 查找失败.  -->



<!-- slide vertical=true data-notes="" -->

##### 二分查找

---

<div class="top-2">
  <img src="../img/review/Binary_search_into_array.png">
</div>


<!-- slide vertical=true data-notes="" -->

##### 二分查找

---

二分查找算法的具体实现(伪代码):

```C{.line-numbers}
输入 arr[]                            // 输入有序序列
binary_search(arr, begin, end, ele): // [begin,end] 指定搜索区域，ele 为要搜索的目标元素
  if begin > end:                    // [begin,end] 不存在时，返回一个错误值（比如 -1）
    return -1
  mid <- ⌊ begin+(end-begin)/2 ⌋     // 找到 [begin,end] 区域内中间元素所在位置的下标
  if ele == arr[mid]:                // 递归的出口，即 ele 和中间元素的值相等
    return mid
  if ele ＜ arr[mid]:                // 比较 ele 和中间元素的值，进一步缩小搜索区域
    return binary_search(arr, begin, mid-1, ele)
  else:
    return binary_search(arr, mid+1, end, ele)
```



<!-- slide vertical=true data-notes="" -->

##### 二分查找(循环)

---

```C{.line-numbers}
#include <stdio.h>

int binary_search(const int arr[], int start, int end, int key) {
  int ret = -1; // 未搜索到数据返回-1下标

  int mid;
  while (start <= end) {
    mid = start + (end - start) / 2;
    if (arr[mid] < key) { // 小于
      start = mid + 1;
    } else if (arr[mid] > key) { // 大于
      end = mid - 1;
    } else if (arr[mid] == key) { // 相等
      ret = mid;
      break;
    }
  }
  
  return ret; // 单一出口
}

int main()
{
  int arr[10] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
  // 输出二叉查找元素31所在位置的下标
  printf("%d", binary_search(arr, 0, 9, 31));
  return 0;
}
```



<!-- slide vertical=true data-notes="" -->

##### 二分查找(递归)

---

```C{.line-numbers}
#include <stdio.h>

int binary_search(const int arr[], int start, int end, int key) {
  if (start > end)
    return -1;

  int mid = start + (end - start) / 2; // 直接平均可能会溢出
  if (arr[mid] > key) {
    return binary_search(arr, start, mid - 1, key);
  } else if (arr[mid] < key) {
    return binary_search(arr, mid + 1, end, key);
  } else if (arr[mid] == key) {
    return mid; // 最后检测相等最後檢測相等是因為多數搜尋狀況不是大於要不就小於
  }
}

int main()
{
  int arr[10] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
  // 输出二叉查找元素31所在位置的下标
  printf("%d", binary_search(arr, 0, 9, 31));
  return 0;
}
```


<!-- slide vertical=true data-notes="" -->

##### 二分查找(基于函数指针的通用实现)

---

```C{.line-numbers}
#include <stdio.h>
#include <string.h>

typedef int (*CompareFunc)(const void *a, const void *b);

int compare_double(const void *a, const void *b) {
  const double *da = (const double *) a;
  const double *db = (const double *) b;
  return *da - *db;
}

int compare_int(const void *a, const void *b) {
  const int *ia = (const int *) a;
  const int *ib = (const int *) b;
  return *ia - *ib;
}

int compare_str(void *a, const void *b) {
  const char *stra = (const char *) a;
  const char *strb = (const char *) b;
  return strcmp(stra, strb);
}

void *binary_search(const void *base, const void *key, int nelem, int size, CompareFunc cmp) {
  const char *p = (const char *) base;
  int n = nelem;
  for (; n > 0;) {
    int mid = n >> 1;
    const char *q = p + size * mid;
    const int val = cmp(key, q);
    if (val < 0) { // key小于当前q指向的元素
      n = mid; // 前面还剩余mid个元素, 下标标号为[0, 1, 2, ..., mid - 1]
    } else if (val > 0) { // key大于当前q指向的元素
      p = q + size; // 从q的下一个元素开始寻找
      n -= (mid + 1); // 后面还剩余n - (mid + 1)个元素, 下标标号为 [mid + 1, mid + 2, ... n - 1]
    } else if (val == 0) { // key与q相等, 直接返回当前指针q
      return q;
    }
  }

  return NULL;
}

int main() {
  int arr_int[10] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
  char arr_str[8][6] = {"abc", "def", "hij", "lmn", "opq", "rst", "uvw", "xyz"};

  int key_int = 44; // 查找int
  int *ki = binary_search(arr_int, &key_int, 10, 4, compare_int);
  if (ki) {
    printf("%d\n", *ki);
  }

  char key_str[6] = "abc"; // 查找字符串
  char *ks = binary_search(arr_str, key_str, 8, 6, compare_str);
  if (ks) {
    printf("%s\n", ks);
  }

  return 0;
}
```


<!-- slide vertical=true data-notes="" -->

##### 链表结点类型

---

方法1:
```C{.line-numbers}
// 链表中节点的结构
typedef struct Node {
  int elem; //代表数据域
  struct Node * next; //代表指针域，指向直接后继元素
} List;
```

方法2:
```C{.line-numbers}
struct Node {
  int elem;
  struct Node * next;
};

typedef struct Node List; // typedef struct Node * List;
```


<!-- slide vertical=true data-notes="" -->

##### 链表结点类型

---

问题:
```C{.line-numbers}
// 是否合法
typedef struct node {
  int node;
} node;
```

解答: 合法, node单独使用是typedef定义的结构体类型, 与struct一起使用是结构体标记，int node是结构体的数据成员, 作用域是结构体内部可见



<!-- slide vertical=true data-notes="" -->

##### 链表(创建)

---

<div class="top-2">
  <img src="../img/review/linklist.gif">
</div>

创建头结点, 依次尾部添加结点, 链表中存储 {1, 2, 3, 4}:

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int elem;
  struct Node * next;
};

typedef struct Node* List;

List initList() {
  // 1、创建头指针和尾指针
  List head = NULL;
  List tail = NULL;
  for (int i = 1; i < 5; i++) {
    // 2、每创建一个结点，都令tail的next指针指向它
    List temp = (List)malloc(sizeof(struct Node));
    temp->elem = i;
    temp->next = NULL;
    if (head == NULL) {
      head = tail = temp; // 初始化头结点和尾结点
    } else {
      // tail的next指针指向temp结点
      tail->next = temp;
      // 更新tail指向新建结点
      tail = temp; // 或者 tail = tail->next; 
    }
  }
  return head;
}

void printList(List p) {
  //只要p指向结点的next值不是NULL，就执行输出语句。
  while (p) {
    printf("%d ", p->elem);
    p = p->next;
  }
  printf("\n");
}

void freeList(List p) {
  while (p) {
    List t = p;
    p = p->next;
    free(t);
  }
}

int main() {
  //创建链表{1,2,3,4}
  List p = initList();
  //输出链表中的数据
  printf("初始化链表为：\n");
  printList(p);
  freeList(p);
  return 0;
}
```