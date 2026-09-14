#include <stdio.h>

void printByPointer(int (*p)[4], int rows) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < 4; j++) {
      // 错误写法：*((*p + i) + j)
      printf("%d ", *(*(p + i) + j));  // p[i] == *(p+i)
    }
    printf("\n");
  }
}

int main() {
  int matrix[2][4] = {
      {7, 8, 9, 10},
      {11, 12, 13, 14}
  };

  printByPointer(matrix, 2); // matrix 自动转换为 int (*)[4]
  return 0;
}
