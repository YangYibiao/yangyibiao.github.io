#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= k; i++) {
      printf("%dx%d=%d ", i, k, i*k);
    }
    printf("\n");
  }
  return 0;
}
