#include <stdio.h>

int main() {
  int i = 0, j = 1;
  int *p; // 声明一个指向整数类型的指针变量p
  p = &i; // 取变量i的地址, 赋值给指针变量p
  printf("%p\n", p);
  printf("sizeof(p): %d\n", sizeof(p));

  p = &j; // 变量j的地址, 赋值给指针变量p
  printf("%p\n", p);

  *p = 8; // 等同于 i = 8, 对*p的操作等同于对i的操作
  printf("i = %d, j = %d", i, j);
  return 0;
}
