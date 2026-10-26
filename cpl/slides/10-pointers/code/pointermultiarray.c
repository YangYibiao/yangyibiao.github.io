#include <stdio.h>

int main(void) {
  int matrix[4][10] = {0};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      printf("a[%d][%d]: %p, ", i, j, &matrix[i][j]);
    }
    printf("\n");
  }

  printf("a: %p\n", matrix);
  printf("a + 1: %p\n", matrix + 1);
  for (int i = 0; i < 5; i++) {
    printf("a[%d]: %p\n", i, matrix[i]);
  }

  printf("%p\n", *(matrix + 1) + 2);
  return 0;
}