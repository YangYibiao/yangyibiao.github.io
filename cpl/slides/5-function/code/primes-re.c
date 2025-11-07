#include <stdio.h>

int is_prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
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
    // determine if i is a prime
    if (is_prime(i)) {
      count++;
    }
  }
  printf("\ntotal count: %d", count);
  return 0;
}