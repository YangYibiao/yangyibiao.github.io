/* 矩阵求和: 函数版 (列数 4 不能省) */
#include <stdio.h>

int sum_matrix(int a[][4], int rows)
{
  int sum = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      sum += a[i][j];
    }
  }
  return sum;
}

int main(void)
{
  int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  printf("sum = %d\n", sum_matrix(m, 3));
  return 0;
}
