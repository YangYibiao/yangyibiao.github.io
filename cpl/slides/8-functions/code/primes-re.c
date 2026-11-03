/* 原版: 判断逻辑埋在 main 里 */
#include <stdio.h>

int is_prime(int n);
int count_primes(int n);

int main() {
  int max;
  scanf("%d", &max);
  printf("\n素数个数: %d", count_primes(max));
  return 0;
}

int is_prime(int n) {
  int d;
  if (n <= 1) return 0;
  for (d = 2; d <= n / d; d++)
    if (n % d == 0) return 0;
  return 1;
}

int count_primes(int n) {
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if( is_prime(i) ) count++;
  }
  return count;
}
