/* Factorial: no functions */
#include <stdio.h>

long long fact(int n) {
  long long f = 1;
  for (int i = 1; i <= n; i++) {
    f = f * i;
  }
  return f;
}

int main(void)
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  printf("%d! = %lld\n", n, fact(n));
  return 0;
}
