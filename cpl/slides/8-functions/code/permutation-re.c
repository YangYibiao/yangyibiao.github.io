/* Permutation & combination calculator: with functions */
#include <stdio.h>

long factorial(int n)      /* write once */
{
  long f = 1;
  int i;

  for (i = 1; i <= n; i++)
    f = f * i;
  return f;
}

int main(void)
{
  long m, n;

  printf("Enter m n (m>=n): ");
  scanf("%ld%ld", &m, &n);

  /* use everywhere: call factorial whenever needed */
  printf("P(%ld,%ld) = %ld\n", m, n,
         factorial(m) / factorial(m - n));
  printf("C(%ld,%ld) = %ld\n", m, n,
         factorial(m) / (factorial(n) * factorial(m - n)));
  return 0;
}
