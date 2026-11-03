/* Count primes up to max: no functions */
#include <stdio.h>

int count_primes(int);
int is_prime(int);

int main() {
  int max;
  scanf("%d", &max);

  printf("count: %d\n", count_primes(max));
  return 0;
}

int is_prime(int n) {
  if (n <= 1) return 0;
  for (int d = 2; d <= n / d; d++) {
    if (n % d == 0) {
      return 0;
    }
  }
  return 1;
}

int count_primes(int n) {
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (is_prime(i)) {
      count++;
    }
  }
  return count;
}


