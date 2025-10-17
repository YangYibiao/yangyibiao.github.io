#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int j;
    for (j = 1; j * j < i; j++);
    if (j * j == i) {
      continue;
    }
    sum += i;
  }
  printf("sum of non-perfect square is %d\n", sum);

}
