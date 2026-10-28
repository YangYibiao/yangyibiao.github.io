/* Permutation & combination calculator: no functions */
#include <stdio.h>

int main(void)
{
  long m, n, i;
  long fact_m = 1, fact_n = 1, fact_mn = 1;

  printf("Enter m n (m>=n): ");
  scanf("%ld%ld", &m, &n);

  for (i = 1; i <= m; i++)      /* part 1: compute m! */
    fact_m = fact_m * i;

  for (i = 1; i <= n; i++)      /* part 2: compute n! */
    fact_n = fact_n * i;

  for (i = 1; i <= m - n; i++)  /* part 3: compute (m-n)! */
    fact_mn = fact_mn * i;

  printf("P(%ld,%ld) = %ld\n", m, n, fact_m / fact_mn);
  printf("C(%ld,%ld) = %ld\n", m, n,
         fact_m / (fact_n * fact_mn));
  return 0;
}
