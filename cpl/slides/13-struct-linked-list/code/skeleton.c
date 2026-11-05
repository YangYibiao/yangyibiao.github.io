/* skeleton.c: 从这行开始写你的代码
 * 链表 (I)(II)(III) 三份课件的课堂编码共用本文件, 按注释分组;
 * 只写函数体, main 已经给出测试数据. */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

/* ===== 链表 (I): 头插与尾插 ===== */

/* 头插: 新建 value 为 n 的结点, 插到 list 开头, 返回新的头指针 */
struct node *insert_front(struct node *list, int n) {
  /* TODO */
}

/* 尾插: 新建 value 为 n 的结点, 接到 list 末尾, 返回头指针 */
struct node *append(struct node *list, int n) {
  /* TODO */
}

/* ===== 链表 (II): 打印与删除 ===== */

/* 从头到尾打印每个结点的 value */
void print_list(struct node *list) {
  /* TODO */
}

/* 删除链表中所有值为 n 的结点, 返回新的头指针 */
struct node *remove_all(struct node *list, int n) {
  /* TODO */
}

/* ===== 链表 (III): 反转与合并 ===== */

/* 反转链表, 返回新的头指针 */
struct node *reverse(struct node *list) {
  /* TODO */
}

/* 合并两个有序链表 (只改指针, 不新建结点), 返回合并后的头指针 */
struct node *merge_sorted(struct node *a, struct node *b) {
  /* TODO */
}

int main(void) {
  struct node *list = NULL;

  /* (I) 头插 10、20, 再尾插 30; 期望输出: 20 10 30 */
  list = insert_front(list, 10);
  list = insert_front(list, 20);
  list = append(list, 30);
  print_list(list);

  /* (II) 删除所有 10; 期望输出: 20 30 */
  list = remove_all(list, 10);
  print_list(list);

  /* (III) 反转; 期望输出: 30 20 */
  list = reverse(list);
  print_list(list);

  return 0;
}
