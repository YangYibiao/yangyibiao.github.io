#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * next;
};

// 初始化一个结点
struct node *initNode(int data)
{
  struct node *p = (struct node*)malloc(sizeof(struct node));
  p->data = data;
  p->next = NULL;
  return p;
}

// 插入至链表的末尾
struct node *insertAtTail(struct node *list, struct node *newnode)
{
  if (list == NULL) { // 当前链表为空
    list = newnode;
  } else {
    struct node *p = list;
    while (p->next != NULL) {
      p = p->next;
    }
    p->next = newnode;
  }
  return list;
}

// 插入至链表的开头
struct node * insertAtHead(struct node *list, struct node *newnode) {
  if (list == NULL) { // 当前链表为空
    list = newnode;
  } else {
    newnode->next = list;
    list = newnode;
  }
  return list;
}

// 按升序插入至链表
struct node * insertSortedAscending(struct node *list, struct node *newnode)
{
  if (list == NULL) { // 链表为空
    list = newnode;
    return list;
  }

  struct node *prev, *curr;
  // 找到第一个大于当前newnode的结点
  for (prev = NULL, curr=list; curr!=NULL && curr->data <= newnode->data; prev = curr, curr = curr->next);

  if (prev == NULL) { // insert at the first node
    newnode->next = list;
    list = newnode;
  } else {
    prev->next = newnode;
    newnode->next = curr;
  }
  return list;
}

// 按降序插入至链表
struct node * insertSortedDescending(struct node *list, struct node *newnode)
{
  if (list == NULL) { // 链表为空
    list = newnode;
    return list;
  }

  struct node *prev, *curr;
  // 找到第一个小于当前newnode的结点
  for (prev = NULL, curr=list; curr!=NULL && curr->data >= newnode->data; prev = curr, curr = curr->next);

  if (prev == NULL) { // 插入至第一个结点
    newnode->next = list;
    list = newnode;
  } else {
    prev->next = newnode;
    newnode->next = curr;
  }
  return list;
}

struct node * delete(struct node *list, int value) {
  struct node *prev = NULL, *curr = list;
  for (; curr != NULL && curr->data != value;) {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL) { // value was not found in the list
    return list;
  }

  if (prev == NULL) {
    list = list->next; // n is in the first node
  } else {
    prev->next = curr->next;
  }
  free(curr);
  return list;
}

void display(struct node *list)
{
  struct node *p = list;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main()
{
  struct node *list = NULL;

  struct node *anode = initNode(4);
  list = insertSortedAscending(list, anode);

  display(list);
  for (int i = 0; i < 10; i++) {
    struct node *newnode = initNode(i);
    list = insertSortedDescending(list, newnode);
    display(list);
  }

  delete(list, 2);
  display(list);
}