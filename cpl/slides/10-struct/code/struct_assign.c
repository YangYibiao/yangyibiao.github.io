#include <stdio.h>

#define NAME_LEN 30

int main() {
  struct {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
  } item1 = {528, "Disk drive"}, item2;

  scanf("%d", &item2.number);
  scanf("%s", item2.name);
  scanf("%d", &item2.on_hand);
  printf("(item1)number: %d, name: %s, on_hand: %d\n", item1.number, item1.name, item1.on_hand);
  printf("(item2)number: %d, name: %s, on_hand: %d\n", item2.number, item2.name, item2.on_hand);

  item2 = item1;
  printf("(item2)number: %d, name: %s, on_hand: %d\n", item2.number, item2.name, item2.on_hand);

  struct { int a[10]; } a1 = {.a = {1, 2, 3}}, a2;
  a2 = a1;

  for (int i = 0; i < 10; i++) {
    printf("%d ", a2.a[i]);
  }
  return 0;
}