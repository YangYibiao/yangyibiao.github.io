/* skeleton.c: 从这行开始写你的代码 */
#include <stdio.h>

int sum(int n) {
  /* TODO: 递归求和 1 + 2 + ... + n */
}

int power(int x, int n) {
  /* TODO: 递归求 x 的 n 次方 */
}

void print(int n) {
  /* TODO: 递归按位打印整数 */
}

int main() {
  printf("%d\n", sum(10));    /* 期望输出: 55 */
  printf("%d\n", power(5, 3)); /* 期望输出: 125 */
  print(1234);                /* 期望输出: 1 2 3 4 */
  return 0;
}
