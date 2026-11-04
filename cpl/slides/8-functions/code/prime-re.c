#include <stdio.h>

int main(void) {
  int n, prime = 1;

  scanf("%d", &n);
  for (int d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      prime = 0;
      break;
    }
  }
  if (prime == 1) {
    printf("是素数\n");
  } else {
    printf("不是素数\n");
  }
  return 0;
}
