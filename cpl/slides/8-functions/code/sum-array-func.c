/* 数组求和: 函数版 */
#include <stdio.h>

int sum_array(int a[], int n)
{
  int i, sum = 0;

  for (i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum;
}

int main(void)
{
  int b[5] = {3, 7, 1, 9, 4};

  printf("sum = %d\n", sum_array(b, 5));
  return 0;
}
