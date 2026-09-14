#include <stdio.h>

// 示例 3：二维数组的指针运算
int main() {
  int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

  printf("matrix[1][2] = %d\n", matrix[1][2]);
  printf("*(*(matrix + 1) + 2) = %d\n", *(*(matrix + 1) + 2));

  return 0;
}