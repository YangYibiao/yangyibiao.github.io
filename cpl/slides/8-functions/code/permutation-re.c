/* 排列组合计算器: 用函数 */
#include <stdio.h>

long factorial(int n)      /* 写一次 */
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

  printf("输入 m n (m>=n): ");
  scanf("%ld%ld", &m, &n);

  /* 处处用: 需要阶乘就调用 */
  printf("P(%ld,%ld) = %ld\n", m, n,
         factorial(m) / factorial(m - n));
  printf("C(%ld,%ld) = %ld\n", m, n,
         factorial(m) / (factorial(n) * factorial(m - n)));
  return 0;
}
