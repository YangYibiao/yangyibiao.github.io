/* 求 b 的元素之和: 非函数版 */
#include <stdio.h>

int main(void)
{
  int b[5] = {3, 7, 1, 9, 4};
  int sum = 0, i;

  for (i = 0; i < 5; i++) {
    sum += b[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
