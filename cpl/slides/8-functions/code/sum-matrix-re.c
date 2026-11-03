/* Matrix sum: no functions */
#include <stdio.h>

int sum_tarray(int m[][4], int rows) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      sum += m[i][j];
    }
  }
  return sum;
}
int main(void)
{
  int m[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  printf("sum = %d\n", sum_tarray(m, 3));
  return 0;
}
