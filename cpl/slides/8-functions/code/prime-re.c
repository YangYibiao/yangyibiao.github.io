#include <stdio.h>

int is_prime(int);

int main(void) {
  int n;
  scanf("%d", &n);
  if (is_prime(n)) printf("是素数\n");
  else printf("不是素数\n");
  return 0;
}

int is_prime(int n) {
  if (n <= 1) return 0;
  for (int d = 2; d <= n / d; d++) {
    if (n % d == 0) { return 0; }
  }
  return 1;
}