#include <stdio.h>

int is_prime[50000000] = {0};

int main() {
  int n;
  scanf("%d", &n);

  is_prime[2] = 1;
  for (int i = 3; i <= n; i+=2) {
    is_prime[i] = 1;
  }

  // i * i <= n 说明 i <= sqrt(n)
  for (int i = 2; i * i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = 0;
      }
    }
  }

  int sum = 1;
  for (int i = 3; i <= n; i += 2) {
    if (is_prime[i]) sum++;
  }
  printf("%d", sum);
  return 0;
}
