/* qsort-rec.c: 递归快速排序 —— 从这行开始写你的代码
   提示: ① split(a, low, high): 以 a[low] 为基准 (空位法), 小的放左、大的放右, 返回基准的最终下标
         ② quicksort(a, low, high): 基准情形 low >= high; 否则 split 后对左右两段各自递归
   两个函数都写在 main 上面 */
#include <stdio.h>

int main(void)
{
  int a[] = {5, 2, 9, 1, 8, 3};
  int i;

  quicksort(a, 0, 5);
  for (i = 0; i < 6; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");          /* 期望输出: 1 2 3 5 8 9 */
  return 0;
}
