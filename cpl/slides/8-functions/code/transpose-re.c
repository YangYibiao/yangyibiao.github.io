/* Matrix transpose: with functions */
#include <stdio.h>

void transpose(int a[][4], int b[][3], int rows)
{
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < 4; j++) {
      b[j][i] = a[i][j];
    }
  }
}

int main(void)
{
  int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int b[4][3];
  int i, j;

  transpose(a, b, 3);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      printf("%3d", b[i][j]);
    }
    printf("\n");
  }
  return 0;
}
