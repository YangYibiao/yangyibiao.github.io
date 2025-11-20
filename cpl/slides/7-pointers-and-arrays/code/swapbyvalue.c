#include <stdio.h>

// 值传递示例
void swap_by_value(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 10, y = 20;
  swap_by_value(x, y);
  printf("x=%d, y=%d", x, y); // 输出：x=10, y=20，没有改变！
}