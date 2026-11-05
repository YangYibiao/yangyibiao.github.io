/* climb-rec.c: 递归求爬楼梯方法数 —— 只写函数体
   问题: n 级台阶, 每次走 1 或 2 级, 从第 0 级走到第 n 级共有多少种走法?
   提示: 最后一步从 n-1 (走 1 级) 或 n-2 (走 2 级) 上来
   基准情形: n <= 1 → 1 */
#include <stdio.h>

int climb(int n)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  printf("%d\n", climb(4));    /* 期望输出: 5 */
  printf("%d\n", climb(10));   /* 期望输出: 89 */
  return 0;
}
