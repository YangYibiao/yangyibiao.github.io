/* 求两组数据的和: 非函数版 */
#include <stdio.h>

int main(void)
{
  int b[5] = {3, 7, 1, 9, 4};
  int c[3] = {10, 20, 30};
  int sum = 0;

  for (int i = 0; i < 5; i++) {    /* 第一组 */
    sum += b[i];
  }
  printf("sum = %d\n", sum);

  sum = 0;
  for (int i = 0; i < 3; i++) {    /* 第二组: 又抄了一遍 */
    sum += c[i];
  }
  printf("sum = %d\n", sum);
  return 0;
}
