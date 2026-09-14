#include <stdio.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  int P1[100][100] = {0};
  int P2[100][100] = {0};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &P1[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &P2[i][j]);
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (P1[i][j] == P2[i][j]) {
        sum++;
      }
    }
  }
  printf("%.2lf", sum *100.0 / (n * m));
  return 0;
}
