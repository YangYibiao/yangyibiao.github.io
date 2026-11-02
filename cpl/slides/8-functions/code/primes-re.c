/* Count primes up to max: with functions */
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

int main() {
  int max;
  scanf("%d", &max);
  int count = 0;
  for (int i = 2; i <= max; i++) {
    if (is_prime(i) == 1) {
      count++;
    }
  }
  printf("count: %d\n", count);
  return 0;
}
