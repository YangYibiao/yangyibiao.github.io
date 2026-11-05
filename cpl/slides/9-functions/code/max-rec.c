/* max-rec.c: 递归求数组最大值 —— 先想递归三问, 再写函数体
   提示: max_rec(a, n) = max( a[n-1], max_rec(a, n-1) )
         基准情形: n == 1 时, 最大值就是 a[0] */
#include <stdio.h>

int max_rec(int a[], int n)
{
  /* TODO: 基准情形 + 递归情形 */
  if (n == 1) {
    return a[0];
  }
  int max = max_rec(a, n - 1);
  return a[n - 1] > max ? a[n - 1] : max;
}

int main(void)
{
  int a[] = {3, 9, 1, 7, 5};

  printf("%d\n", max_rec(a, 5));   /* 期望输出: 9 */
  return 0;
}
