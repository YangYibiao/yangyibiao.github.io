#include <stdio.h>

struct {
  int number;    // 商品编号
  char name[25]; // 商品名称
  int on_hand;   // 商品库存
//  char description[20]; // 商品描述
} item;

int main() {
  printf("sizeof struct: %d\n", sizeof(item));
  printf("address of struct: %p\n", &item);
  printf("address of number: %p\n", &item.number);
  printf("address of name: %p\n", &item.name);
  printf("address of on_hand: %p\n", &item.on_hand);
//  printf("address of address: %p\n", &item.description);
}
