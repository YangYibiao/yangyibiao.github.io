#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
  int data;
  struct node *next;
};

struct linkedlist
{
  struct node *head;
  struct node *tail;
};

void initList(struct linkedlist *ll)
{
  ll->head = NULL;
  ll->tail = NULL;
}

void append(struct linkedlist *ll, struct node *newnode)
{
  if (!ll->head && !ll->tail)
  {
    ll->head = newnode;
    ll->tail = newnode;
    newnode->next = ll->head;
  } else {
    ll->tail->next = newnode;
    ll->tail = newnode;
    newnode->next = ll->head;
  }
}

struct node *initLNode(int value)
{
  struct node *p = malloc(sizeof(*p));
  p->next = NULL;
  p->data = value;
  return p;
}

void display(struct linkedlist *ll)
{
  struct node *p = ll->head;
  while (p->next != ll->head)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("%d ", p->data);
  printf("\n");
}

void sitCricle(struct linkedlist *ll, int num)
{
  for (int i = 1; i <= num; i++)
  {
    append(ll, initLNode(i));
  }
  // display(ll);
}

void killUntilOne(struct linkedlist *ll, int kill)
{
  struct node *pnode = ll->head;
  struct node *p_prev;
  assert(ll->tail->next == ll->head);
  while (pnode->next != pnode) // buggy
  {
    int cnt = 1;
    do
    {
      cnt++;
      p_prev = pnode;
      pnode = pnode->next;
    } while (cnt < kill);
    p_prev->next = pnode->next;
    // printf("kill %d\n", pnode->data);
    free(pnode);
    pnode = p_prev->next;
  }
  ll->head = pnode;
  ll->tail = pnode;
  // printf("----\n");
}

int getSurvivor(struct linkedlist *list)
{
  return list->head->data;
}

void freeList(struct linkedlist *list)
{
  struct node *p = list->head;
  while (p != NULL)
  {
    // printf("free%d ", p->data);
    list->head = p->next;
    list->tail->next = list->head;
    if (p == list->tail)
      list->tail = NULL;
    free(p);
    p = list->head;
  }
  printf("\n");
}

int main()
{
  int all, kill;
  scanf("%d %d", &all, &kill);
  struct linkedlist list;
  initList(&list);
  sitCricle(&list, all);
  killUntilOne(&list, kill);
  printf("survivor: %d\n", getSurvivor(&list));
  free(list.head);
  // freeList(&list);
}