/* climb-rec.c: 递归求爬楼梯方法数 —— 只写函数体
   提示: 每次走 1 或 2 级; 走到第 n 级 = 走到 n-1 级 + 走到 n-2 级 (Fibonacci 的亲戚)
   基准情形: n <= 1 → 1 */
#include <stdio.h>

int climb(int n)
{
  /* TODO: 基准情形 + 递归情形 */
  if (n <= 1) {
    return 1;
  }
  return climb(n - 1) + climb(n - 2);
}

int main(void)
{
  printf("%d\n", climb(4));    /* 期望输出: 5 */
  printf("%d\n", climb(10));   /* 期望输出: 89 */
  return 0;
}
