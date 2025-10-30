#include <stdio.h>

int main() {
  int m, n, p;
  scanf("%d%d%d", &m, &n, &p);

  int A[100][100] = {0};
  int B[100][100] = {0};
  int C[100][100] = {0};

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      int cij = 0;
      for (int k = 0; k < n; k++) {
        cij += A[i][k] * B[k][j];
      }
      C[i][j] = cij;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  return 0;
}
