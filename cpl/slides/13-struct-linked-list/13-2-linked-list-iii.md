---
password: "cpl2026"
---

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

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/13-struct-linked-list/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>

---


<!-- slide data-notes="" -->

##### 约瑟夫问题 · 思路

---

1. ==建环==: 建 n 个结点 (编号 1~n), 首尾相接成循环链表

2. ==报数==: 用 prev 跟踪 "报到 m 的人的前一个"——每轮走 ==m-1 步==, prev->next 就是出列者

3. ==出列==: 输出编号 → `prev->next = prev->next->next` 绕过 → `free` 回收

4. ==循环==: prev 不动 (它就是下一个报数者的前一个), 直到 `prev->next == prev` (只剩一人)

<svg viewBox="0 0 400 200" style="max-width:100%;height:200px;" role="img" aria-label="约瑟夫问题循环链表">
  <defs>
    <marker id="joseph-arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="4.5" markerHeight="4.5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#93a1a1"/>
    </marker>
    <marker id="joseph-red" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="4.5" markerHeight="4.5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#dc322f"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <line x1="155" y1="43" x2="175" y2="53" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>
    <line x1="194" y1="77" x2="198" y2="97" stroke="#dc322f" stroke-width="2" marker-end="url(#joseph-red)"/>
    <line x1="192" y1="127" x2="178" y2="145" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>
    <line x1="151" y1="158" x2="129" y2="158" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>
    <line x1="102" y1="145" x2="88" y2="127" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>
    <line x1="82" y1="97" x2="86" y2="77" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>
    <line x1="105" y1="53" x2="125" y2="43" stroke="#93a1a1" stroke-width="1.5" marker-end="url(#joseph-arrow)"/>

    <circle cx="140" cy="36" r="15" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="140" y="41" font-size="12" fill="#073642" text-anchor="middle">1</text>
    <circle cx="190" cy="60" r="15" fill="#fdf6e3" stroke="#268bd2" stroke-width="2.5"/>
    <text x="190" y="65" font-size="12" fill="#268bd2" text-anchor="middle">2</text>
    <circle cx="202" cy="114" r="15" fill="#fdf6e3" stroke="#dc322f" stroke-width="2.5"/>
    <text x="202" y="119" font-size="12" fill="#dc322f" text-anchor="middle">3</text>
    <circle cx="168" cy="158" r="15" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="168" y="163" font-size="12" fill="#073642" text-anchor="middle">4</text>
    <circle cx="112" cy="158" r="15" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="112" y="163" font-size="12" fill="#073642" text-anchor="middle">5</text>
    <circle cx="78" cy="114" r="15" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="78" y="119" font-size="12" fill="#073642" text-anchor="middle">6</text>
    <circle cx="90" cy="60" r="15" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="90" y="65" font-size="12" fill="#073642" text-anchor="middle">7</text>

    <text x="232" y="38" font-size="11.5" font-weight="700" fill="#268bd2">一轮操作 (m = 3)</text>
    <text x="232" y="60" font-size="9.2" fill="#073642">① prev 从 1 走 2 步</text>
    <text x="232" y="78" font-size="9.2" fill="#073642">② p = prev-&gt;next (3)</text>
    <text x="232" y="96" font-size="9.2" fill="#073642">③ 输出 3, 绕过 p</text>
    <text x="232" y="114" font-size="9.2" fill="#073642">④ free(p), prev 不动</text>
    <text x="232" y="132" font-size="9.2" fill="#073642">⑤ 直到 prev-&gt;next == prev</text>

    <circle cx="236" cy="152" r="4" fill="#fdf6e3" stroke="#268bd2" stroke-width="2"/>
    <text x="246" y="155" font-size="8.5" fill="#268bd2">prev</text>
    <circle cx="296" cy="152" r="4" fill="#fdf6e3" stroke="#dc322f" stroke-width="2"/>
    <text x="306" y="155" font-size="8.5" fill="#dc322f">p (出列)</text>

    <text x="8" y="190" font-size="9.5" fill="#586e75">7 人、m=3: 出列 3 6 2 7 5 1 4, 幸存 4</text>
  </g>
</svg>

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

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/13-struct-linked-list/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>

<svg viewBox="0 0 400 180" style="max-width:100%;height:180px;" role="img" aria-label="链表反转前后指针变化">
  <defs>
    <marker id="ll-rev-arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#268bd2"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="8" y="20" font-size="11" font-weight="700" fill="#586e75">反转前</text>
    <text x="20" y="49" font-size="9" fill="#859900">first</text>
    <line x1="62" y1="45" x2="98" y2="45" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>

    <rect x="100" y="30" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="128" y="50" font-size="13" fill="#073642" text-anchor="middle">1</text>
    <rect x="180" y="30" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="208" y="50" font-size="13" fill="#073642" text-anchor="middle">2</text>
    <rect x="260" y="30" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="288" y="50" font-size="13" fill="#073642" text-anchor="middle">3</text>

    <line x1="156" y1="45" x2="178" y2="45" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>
    <line x1="236" y1="45" x2="258" y2="45" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>
    <line x1="316" y1="45" x2="334" y2="45" stroke="#93a1a1" stroke-width="1.4" marker-end="url(#ll-rev-arrow)"/>
    <text x="340" y="49" font-size="9" fill="#93a1a1">NULL</text>

    <text x="128" y="74" font-size="8.5" fill="#268bd2" text-anchor="middle">prev</text>
    <text x="208" y="74" font-size="8.5" fill="#859900" text-anchor="middle">cur</text>
    <text x="288" y="74" font-size="8.5" fill="#b58900" text-anchor="middle">next</text>

    <text x="8" y="98" font-size="11" font-weight="700" fill="#586e75">反转后</text>
    <text x="352" y="127" font-size="9" fill="#859900">first</text>
    <line x1="345" y1="123" x2="318" y2="123" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>

    <rect x="100" y="108" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="128" y="128" font-size="13" fill="#073642" text-anchor="middle">1</text>
    <rect x="180" y="108" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="208" y="128" font-size="13" fill="#073642" text-anchor="middle">2</text>
    <rect x="260" y="108" width="56" height="30" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="288" y="128" font-size="13" fill="#073642" text-anchor="middle">3</text>

    <line x1="260" y1="123" x2="238" y2="123" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>
    <line x1="180" y1="123" x2="158" y2="123" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-rev-arrow)"/>
    <line x1="100" y1="123" x2="82" y2="123" stroke="#93a1a1" stroke-width="1.4" marker-end="url(#ll-rev-arrow)"/>
    <text x="46" y="127" font-size="9" fill="#93a1a1">NULL</text>

    <text x="8" y="166" font-size="9.5" fill="#dc322f">先把 next 存下来, 再改箭头——顺序反了会丢结点</text>
  </g>
</svg>

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

