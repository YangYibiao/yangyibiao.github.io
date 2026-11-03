<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 链表 (II) · 插入、搜索与删除

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 提纲

---

- 链表的开头插入一个结点

- 搜索链表

- 从链表中删除结点

- 有序链表

- 课堂编码与小测

---


<!-- slide data-notes="" -->


##### 链表的开头插入一个结点

---

<div style="display:flex;align-items:flex-start;gap:24px;">



<div style="flex:1;font-size:0.6em;">

链表的优点之一是可以在链表中的任何位置添加结点. 

但是, 链表的开头是最容易插入结点的地方. 

假设new_node指向要插入的结点, first指向链表中的第一个结点.


将结点插入链表需要两个语句. 

第一步是修改新结点的成员next, 使其指向之前在链表开头的结点: 

`new_node->next = first;`

第二步是使first指向新结点: 

`first = new_node;`

即使链表为空, 这些语句也有效.


让我们跟踪将两个结点插入一个空链表的过程. 

首先插入一个包含数字10的结点, 然后插入一个包含20的结点.

</div>

</div>

<!-- slide data-notes="" -->


##### 搜索链表

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
for (p = first; p != NULL; p = p->next)
  …
```

```C
struct node *search_list(struct node *list, int n)
{
 struct node *p;

 for (p = list; p != NULL; p = p->next)
   if (p->value == n)
     return p;
 return NULL;
}
```

```C
struct node *search_list(struct node *list, int n)
{
 for (; list != NULL; list = list->next)
   if (list->value == n)
     return list;
 return NULL; 
}
```

</div>

<div style="flex:1;font-size:0.6em;">

虽然while循环也可以搜索链表, 但for语句通常是首选. 

访问链表中结点的循环, 使用指针变量p来跟踪"当前"结点:

这种形式的循环可用于在链表中搜索整数n的函数.


如果找到n, 该函数将返回一个指向包含n的结点的指针; 否则, 它将返回一个空指针. 

该函数的初始版本:

还有很多其他的方法来编写search_list. 

一种替代方法是消除变量p, 用list本身来跟踪当前结点:

由于list是原始链表指针的副本, 因此在函数中更改它没有损害.

</div>

</div>

<!-- slide data-notes="" -->


##### 从链表中删除结点

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.3;font-size:0.6em;">

```C
for (cur = list, prev = NULL;
    cur != NULL && cur->value != n;
    prev = cur, cur = cur->next)
  ;
```

</div>

<div style="flex:1;font-size:0.6em;">

链表的一大优势: 删除结点很方便。

删除结点分三步:

- 找到要删除的结点.
- 更改前一个结点, 使其"绕过"已删除的结点.
- 调用 free 回收被删除结点占用的空间.

第 1 步比看起来更难, 因为第 2 步需要更改前一个结点.

这个问题有多种解决方案.

"追踪指针"技术涉及保持指向前一个结点(prev)的指针以及指向当前结点(cur)的指针.

假设 list 指向要搜索的链表, n 是要删除的整数.

实现第 1 步的循环:

当循环终止时, cur 指向要删除的结点, prev 指向前一个结点.

</div>

</div>

<!-- slide data-notes="" -->

##### 从链表中删除结点 (续)

---

第 2、3 步的代码:

```C
if (prev == NULL)          /* 删的是头结点 */
  list = cur->next;
else
  prev->next = cur->next;  /* 绕过 cur */
free(cur);                 /* 回收内存 */
```

- 删除头结点要==更新头指针==; free 之后 cur 不能再解引用
- 删除操作只改变==指针==, 不移动结点; 查找是 O(n), 删除本身 O(1)

<!-- slide data-notes="" -->

##### 从链表中删除结点 (续 2)

---

假设链表如下并且 n 为 20:

<div class="top-2">
  <img src="figs/16-11-1.png" width=500px>
</div>

执行完 `cur = list, prev = NULL` 后:

<div class="top-2">
  <img src="figs/16-11-2.png" width=500px>
</div>

<!-- slide data-notes="" -->


##### 有序链表

---

当链表的结点是有序的——按结点中的数据排序——我们称该链表是**有序链表**. 

向有序链表中插入结点更加困难, 因为结点并不总是放在链表的开头. 

但是搜索会更快: 在到达期望结点应该出现的位置后, 就可以停止查找.

<svg viewBox="0 0 400 175" style="max-width:100%;height:175px;" role="img" aria-label="有序链表插入 25">
  <defs>
    <marker id="ll-order-arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="5" markerHeight="5" orient="auto">
      <path d="M0,0 L10,5 L0,10 Z" fill="#268bd2"/>
    </marker>
  </defs>
  <g font-family="LXGWWenKai, 'Noto Sans SC', sans-serif">
    <text x="8" y="18" font-size="11" fill="#586e75">有序链表: 找到第一个比 25 大的结点</text>
    <text x="8" y="48" font-size="9" fill="#859900">list</text>
    <line x1="34" y1="44" x2="48" y2="44" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-order-arrow)"/>

    <rect x="50" y="42" width="64" height="32" rx="4" fill="#fdf6e3" stroke="#93a1a1" stroke-width="1.5"/>
    <text x="82" y="63" font-size="13" fill="#073642" text-anchor="middle">10</text>
    <rect x="150" y="42" width="64" height="32" rx="4" fill="#fdf6e3" stroke="#268bd2" stroke-width="2"/>
    <text x="182" y="63" font-size="13" fill="#073642" text-anchor="middle">20</text>
    <rect x="270" y="42" width="64" height="32" rx="4" fill="#fdf6e3" stroke="#dc322f" stroke-width="2"/>
    <text x="302" y="63" font-size="13" fill="#073642" text-anchor="middle">30</text>

    <line x1="114" y1="58" x2="148" y2="58" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-order-arrow)"/>
    <line x1="214" y1="58" x2="268" y2="58" stroke="#93a1a1" stroke-width="1.3" stroke-dasharray="4 3"/>
    <text x="240" y="63" font-size="12" fill="#dc322f" text-anchor="middle">×</text>
    <line x1="334" y1="58" x2="350" y2="58" stroke="#93a1a1" stroke-width="1.4" marker-end="url(#ll-order-arrow)"/>
    <text x="354" y="62" font-size="9" fill="#93a1a1">NULL</text>

    <text x="182" y="34" font-size="8.5" fill="#268bd2" text-anchor="middle">prev</text>
    <text x="302" y="34" font-size="8.5" fill="#dc322f" text-anchor="middle">cur</text>

    <rect x="190" y="108" width="64" height="32" rx="4" fill="#dceaf5" stroke="#268bd2" stroke-width="2"/>
    <text x="222" y="129" font-size="13" fill="#073642" text-anchor="middle">25</text>
    <text x="222" y="154" font-size="8.5" fill="#268bd2" text-anchor="middle">new_node</text>

    <line x1="200" y1="74" x2="212" y2="106" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-order-arrow)"/>
    <line x1="254" y1="124" x2="282" y2="76" stroke="#268bd2" stroke-width="1.6" marker-end="url(#ll-order-arrow)"/>

    <text x="8" y="170" font-size="9" fill="#586e75">prev-&gt;next = new; new-&gt;next = cur</text>
  </g>
</svg>

---


<!-- slide data-notes="" -->

##### 课堂编码

---

==现场演示==

1. 写 `void print_list(struct node *list)`: 从头到尾打印每个结点的 value

2. 写 `struct node *append(struct node *list, int n)`: 把新结点接到==末尾== (注意: 空链表时直接返回新结点)

3. 删除链表中==所有==值为 n 的结点 (删除头结点要更新头指针!)

<span class="blue">:fa-lightbulb-o:</span> 提示: 先想清楚 ==prev 和 cur 两个指针==怎么配合, 再动手

<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/13-struct-linked-list/code/skeleton.c" style="display:inline-block;margin-top:8px;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 skeleton.c</a>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 概念: 在链表头部插入结点, 两条语句的顺序能交换吗？为什么？

2. 概念: 删除一个结点分哪三步？

3. 阅读: `search_list` 在==空链表==上调用会返回什么？

4. 纠错: `free(cur)` 之后, 又访问 `cur->next` 会怎样？

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---

