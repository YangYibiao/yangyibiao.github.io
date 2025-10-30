#include <stdio.h>

int main() {
  long long n;
  scanf("%lld", &n);

  int sum = 1;
  for (long long i = 3; i <= n; i = i + 2) {
    if (i > 10 && (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0)) {
      continue;
    }
    int prime = 1;
    for (long long j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      sum++;
    }
  }
  printf("%d", sum);
  return 0;
}
