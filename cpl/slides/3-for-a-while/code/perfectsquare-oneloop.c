#include <stdio.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  int sum = 0;
  int base_current = 1;
  for (int i = 1; i <= max; i++) {
    if (i == base_current * base_current) {
      base_current++;
      printf("%d is a perfect square\n", i);
      continue;
    }

    sum += i;
  }
  printf("sum of non-perfect square is %d\n", sum);
  return 0;
}
