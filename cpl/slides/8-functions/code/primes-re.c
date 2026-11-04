/* 原版: 判断逻辑埋在 main 里 */
#include <stdio.h>

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    // 判断 i 是否素数
    int prime = 1;
    for (int j = 2; j <= i / j; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
      count++;
    }
  }
  printf("\n素数个数: %d", count);
  return 0;
}
