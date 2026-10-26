#include <stdio.h>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

  int k = 0;
  n = n == 1 ? 6 : n - 2;

  for (int i = 0; i < n; i++) {
    printf("    ");
    k++;
  }
  for (int i = 1; i <= m; i++) {
    printf("%2d", i);
    if (i == m) {
      break;
    }
    k++;
    if (k % 7 == 0) {
      printf("\n");
    } else {
      printf("  ");
    }
  }
  return 0;
}
