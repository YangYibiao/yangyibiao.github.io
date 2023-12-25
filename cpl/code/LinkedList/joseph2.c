#include <stdlib.h>
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

struct LinkedList {
  struct node *head;
  struct node *tail;
};

void initLinkedList(struct LinkedList *ll)
{
  ll->head = NULL;
  ll->tail = NULL;
}

struct node * initNode(int i)
{
  struct node * nn = malloc(sizeof(struct node));
  nn->data = i;
  nn->next = NULL;
  return nn;
}

void initListWithN(struct LinkedList *ll, int n)
{
  for (int i = 1; i <= n; i++) {
    struct node *nn = initNode(i);
//    printf("malloc: %p\n", nn);
    if (ll->head != NULL && ll->tail != NULL) { // 当前链表标为空链表
      ll->tail->next = nn; // 尾部结点的next指针指向nn
      ll->tail = nn; // nn为新的尾部
      nn->next = ll->head; // 新结点的next指针修改为头结点的指针
    } else { // 当前链表为空链表
      ll->head = nn;
      ll->tail = nn;
      nn->next = ll->head; // nn->next = nn;
    }
  }
}

void display(struct LinkedList *ll)
{
  struct node *p = ll->head;
  while (p->next != ll->head) { // 直到当前的指针指向最后一个结点
    printf("%d ", p->data);
    p = p->next;
  }
  printf("%d ", p->data); // 打印最后一个结点的数据
  printf("\n");
}

void killUntilOne(struct LinkedList *ll, int kill)
{
  struct node *prev = NULL;
  struct node *curr = ll->head;

  while (curr->next != curr) { // 只剩下一个结点，退出循环
    int cnt = 1;
    do {
      cnt++;
      prev = curr;
      curr = curr->next;
    } while (cnt < kill);
    printf("node with %d will be removed. \n", curr->data);
    prev->next = curr->next;
    free(curr);
    curr = prev->next; // curr = curr->next; // curr已经free掉了，结点不存在了
  }
  ll->head = curr;
  ll->tail = curr;
}

int main()
{
  struct LinkedList ll;
  initLinkedList(&ll);
  initListWithN(&ll, 4);
  display(&ll);
  killUntilOne(&ll, 5);
  display(&ll);
}