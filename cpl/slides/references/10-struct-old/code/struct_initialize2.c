#include <stdio.h>

#define NAME_LEN 30

struct {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} item1;

int main() {
  struct {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
  } item2;
  printf("(item1)number: %d, name: %s, on_hand: %d\n", item1.number, item1.name, item1.on_hand);
  printf("(item2)number: %d, name: %s, on_hand: %d\n", item2.number, item2.name, item2.on_hand);
  return 0;
}
