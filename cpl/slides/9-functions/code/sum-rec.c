/* sum-rec.c: 递归求和 —— 只写函数体
   问题: 计算 1 + 2 + ... + n
   提示: sum(n) = n + sum(n-1); 基准情形: n == 0 → 0 */
#include <stdio.h>

int sum(int n)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  printf("%d\n", sum(10));    /* 期望输出: 55 */
  printf("%d\n", sum(100));   /* 期望输出: 5050 */
  return 0;
}
