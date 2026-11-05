/* comb-rec.c: 递归求组合数 C(m,n) —— 只写函数体
   提示: C(m,n) = C(m-1,n-1) + C(m-1,n)  (选中/不选第 m 个)
   基准情形: n == 0 或 n == m → 1 */
#include <stdio.h>

long comb(int m, int n)
{
  /* TODO: 基准情形 + 递归情形 */
  if (n == 0 || n == m) {
    return 1;
  }
  return comb(m - 1, n - 1) + comb(m - 1, n);
}

int main(void)
{
  printf("%ld\n", comb(5, 2));    /* 期望输出: 10 */
  printf("%ld\n", comb(10, 3));   /* 期望输出: 120 */
  return 0;
}
