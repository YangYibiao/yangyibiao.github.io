/* 求 b 的元素之和: 非函数版 */
#include <stdio.h>

int sum_array(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

int main(void)
{
  int b[10] = {3, 7, 1, 9, 4, 6, 7, 8, 9};
  int sum = sum_array(b, 10);
  printf("sum = %d\n", sum);
  return 0;
}



