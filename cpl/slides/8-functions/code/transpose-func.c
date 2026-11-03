/* 矩阵转置: 函数版 (a: 3x4, b: 4x3) */
#include <stdio.h>

void transpose(int a[][4], int b[][3], int rows)
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      b[j][i] = a[i][j];
    }
  }
}

int main(void)
{
  int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int b[4][3];

  transpose(a, b, 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3d", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}
