<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 链表 (III) · 综合案例

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 案例: 约瑟夫问题 (问题 → 思路 → 代码)

- 案例: 零件数据库 (改进版)

- 课堂编码与小测

---


<!-- slide data-notes="" -->

##### 案例: 约瑟夫问题

---

n 个人围成一圈 (编号 1~n), 从 1 号开始报数, 报到 m 的人==出列==; 下一个人继续从 1 报起, 直到只剩一人

样例: 输入 `7 3` → 出列顺序 `3 6 2 7 5 1 4`, 幸存者 `4`

==现场演示==: 用链表把这个问题写出来

<span class="blue">:fa-lightbulb-o:</span> 提示: 围成一圈 = 尾结点的 next 指向头结点 (==循环链表==); 出列 = 删除结点

---


<!-- slide data-notes="" -->

##### 约瑟夫问题 · 思路

---

1. ==建环==: 建 n 个结点 (编号 1~n), 首尾相接成循环链表

2. ==报数==: 用 prev 跟踪 "报到 m 的人的前一个"——每轮走 ==m-1 步==, prev->next 就是出列者

3. ==出列==: 输出编号 → `prev->next = prev->next->next` 绕过 → `free` 回收

4. ==循环==: prev 不动 (它就是下一个报数者的前一个), 直到 `prev->next == prev` (只剩一人)

---

<!-- slide data-notes="" -->

##### 约瑟夫问题 · 参考代码

---

<div style="font-size:0.6em;">

```C{.line-numbers}
/* 约瑟夫问题: n 个人围圈, 报到 m 出列 */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int no;              /* 编号 */
  struct node *next;
};

int main(void)
{
  int n, m, i;
  struct node *head, *p, *prev;

  scanf("%d %d", &n, &m);

  for (i = n; i >= 1; i--) {          /* 头插法建 1..n */
    p = malloc(sizeof(struct node));
    p->no = i;
    p->next = head;
    head = p;
  }

  prev = head;                        /* 找尾结点, 连成环 */
  while (prev->next != NULL) {
    prev = prev->next;
  }
  prev->next = head;

  while (prev->next != prev) {        /* 只剩一人时停止 */
    for (i = 1; i < m; i++) {         /* 报数 m-1 步 */
      prev = prev->next;
    }
    p = prev->next;                   /* 报到 m 的人 */
    printf("%d ", p->no);
    prev->next = p->next;             /* 绕过 p */
    free(p);                          /* 回收 */
  }
  printf("\n幸存者: %d\n", prev->no);
  return 0;
}
```

</div>

- 建环用==头插法== (倒着插, 正着报); 尾结点怎么找? 从 head 走到 `next == NULL`

- 出列后 prev ==不要动==——它正好是下一个报数者的前一个

---


<!-- slide data-notes="" -->


##### 程序: 维护零件数据库(改进版)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.5;font-size:0.7em;">

```C{.line-numbers}
struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};
```

</div>

<div style="flex:1;font-size:0.6em;">

`inventory2.c` 是对上一节 13-1 零件数据库程序的改进, 这次数据库存储在一个链表中. 

使用链表的优点: 

- 无需限制数据库的大小. 

- 数据库可以很容易地按零件编号排序. 

在原始程序中, 数据库没有排序.


part 结构体多加一个成员: 指向下一个结点的指针:

inventory将指向链表首结点: 

`struct part *inventory = NULL;`


新程序中的大多数函数与原始程序中的版本非常相似. 

find_part和insert会更复杂, 因为将按零件编号对链表inventory中的结点进行排序.

</div>

</div>

<!-- slide data-notes="" -->

##### 课堂编码

---

==现场演示==

1. 链表反转: `1 → 2 → 3` 变成 `3 → 2 → 1` (三指针: prev、cur、next)

2. 挑战: 合并两个==有序==链表, 结果仍然有序 (只改指针, 不新建结点)

<span class="blue">:fa-lightbulb-o:</span> 提示: 反转时先把 next 存下来, 再改方向——顺序错了链表就断了

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 概念: 约瑟夫问题为什么用==循环链表==？普通链表 (尾接 NULL) 行不行？

2. 概念: 报数循环里, prev 每一轮走几步？为什么是 m-1 而不是 m？

3. 阅读: 链表只剩一个结点时, `prev->next != prev` 是什么值？循环还会继续吗？

4. 纠错: 出列时只写了 `prev->next = p->next`, 忘了 `free(p)` 会怎样？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---

