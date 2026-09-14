#include <stdio.h>

// 按地址传递或按引用传递
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 10, y = 20;
  swap(&x, &y);
  printf("x=%d, y=%d", x, y); // 输出：x=10, y=20，没有改变！
}