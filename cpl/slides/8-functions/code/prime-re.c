/* Prime check: no functions */
#include <stdio.h>

int main(void)
{
  int n, d, prime = 1;

  scanf("%d", &n);
  for (d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      prime = 0;
      break;
    }
  }
  if (prime == 1) {
    printf("prime\n");
  } else {
    printf("not prime\n");
  }
  return 0;
}
