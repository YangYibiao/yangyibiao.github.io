/* 排列组合计算器: 不用函数 */
#include <stdio.h>

int main(void)
{
  long m, n, i;
  long fact_m = 1, fact_n = 1, fact_mn = 1;

  printf("输入 m n (m>=n): ");
  scanf("%ld%ld", &m, &n);

  for (i = 1; i <= m; i++)      /* 第一段: 计算 m! */
    fact_m = fact_m * i;

  for (i = 1; i <= n; i++)      /* 第二段: 计算 n! */
    fact_n = fact_n * i;

  for (i = 1; i <= m - n; i++)  /* 第三段: 计算 (m-n)! */
    fact_mn = fact_mn * i;

  printf("P(%ld,%ld) = %ld\n", m, n, fact_m / fact_mn);
  printf("C(%ld,%ld) = %ld\n", m, n,
         fact_m / (fact_n * fact_mn));
  return 0;
}
