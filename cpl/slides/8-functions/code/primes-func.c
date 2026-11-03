/* primes.c: 函数版 (is_prime + count_primes 两层调用链) */
#include <stdio.h>

int is_prime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int j = 2; j <= n / j; j++) {
    if (n % j == 0) {
      return 0;
    }
  }
  return 1;
}

int count_primes(int max) {
  int count = 0, i;
  for (i = 2; i <= max; i++) {
    if (is_prime(i) == 1) {
      count++;
    }
  }
  return count;
}

int main(void) {
  int max;
  scanf("%d", &max);
  printf("素数个数: %d\n", count_primes(max));
  return 0;
}
