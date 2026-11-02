/* Factorial: no functions */
#include <stdio.h>

int main(void)
{
  int n, i;
  long f = 1;

  printf("Enter n: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    f = f * i;
  }
  printf("%d! = %ld\n", n, f);
  return 0;
}
