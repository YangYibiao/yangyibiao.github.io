/* bin-rec.c: 递归二分查找 —— 只写函数体
   提示: 每次砍一半; 基准情形: low > high (没找到)
   a 是升序数组, 找到返回下标, 找不到返回 -1 */
#include <stdio.h>

int bin_search(int a[], int low, int high, int key)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  int a[] = {2, 5, 8, 12, 19};

  printf("%d\n", bin_search(a, 0, 4, 8));    /* 期望输出: 2 */
  printf("%d\n", bin_search(a, 0, 4, 7));    /* 期望输出: -1 */
  return 0;
}
