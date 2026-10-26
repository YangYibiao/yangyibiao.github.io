#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);

  int sum = 0;
  int root = 1;
  for (int i = 1; i <= n; i++) {
    if (i == root * root) {
      root++;
      continue;
    }
    sum += i;
  }
  printf("sum of non-perfect square is %d\n", sum);
  return 0;
}
