#include <stdio.h>

int is_prime(int n) {
  int prime = 1;
  for (int j = 2; j * j <= n; j++) {
    if (i % j == 0) {
      prime = 0;
      break;
    }
  }
  return prime;
}

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i <= max; i++) {
    // determine if i is a prime
    int prime = is_prime(i);
    if (prime == 1) {
      count++;
    }
  }
  printf("\ntotal count: %d", count);
  return 0;
}
