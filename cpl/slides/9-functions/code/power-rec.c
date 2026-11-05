/* power-rec.c: 递归求幂 —— 只写函数体
   问题: 计算 x 的 n 次方 (x^n)
   提示: x^n = x × x^(n-1); 基准情形: n == 0 → 1
   思考: 参数里哪些量在变、哪些不变? */
#include <stdio.h>

int power(int x, int n)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  printf("%d\n", power(5, 3));    /* 期望输出: 125 */
  printf("%d\n", power(2, 10));   /* 期望输出: 1024 */
  return 0;
}
