#include <stdio.h>

// 示例 2：二级指针指向一级指针
int main() {
  int value = 100;
  int *p = &value;
  int **pp = &p;

  printf("value = %d\n", value);
  printf("*p = %d\n", *p);
  printf("**pp = %d\n", **pp);

  return 0;
}
