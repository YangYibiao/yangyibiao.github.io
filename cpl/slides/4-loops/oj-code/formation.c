#include <stdio.h>

#define LEN 2000

// 多维数组不要定义在栈上，定义为全局变量
int matrix[LEN][LEN + 2] = {0};

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

  char str[LEN + 1];
  scanf("%s", str);

  for (int j = 1; j <= n; j++) {
    matrix[0][j] = str[j - 1] - '0';
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      int k = matrix[i - 1][j - 1] * 4 + matrix[i - 1][j] * 2 + matrix[i - 1][j + 1];
      if (k == 7 || k == 4 || k == 0) {
        matrix[i][j] = 0;
      } else {
        matrix[i][j] = 1;
      }
    }
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
