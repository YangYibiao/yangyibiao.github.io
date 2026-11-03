/* 求 m 的元素之和: 非函数版 */
#include <stdio.h>
#define COLS 4
int sum_array(int arr[][COLS], int rows, int cols) {
  int sum = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < COLS; j++) {
      sum += arr[i][j];
    }
  }
  return sum;
}

int main(void)
{
  int m[3][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int sum = sum_array(m, 3, 4);
  printf("sum = %d\n", sum);
  return 0;
}
