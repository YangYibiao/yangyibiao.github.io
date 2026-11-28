/* task-last-max.c: 任务 5 —— 返回指向最后一个最大元素的指针
   任务: 完成 int *last_max(int *a, int n),
         返回指向最后一个最大元素的指针.
   测试数组: 3 8 1 9 2 7 4 6 9 0
   期望输出: 最后一个最大值: 9
   提示: 用下标遍历; 遇到 >= 当前最大值就更新下标, 这样保留最后一个.
   在 TODO 处补完函数体. */
#include <stdio.h>

#define N 10

int *last_max(int *a, int n, int *best)
{
  /* TODO: 返回指向最后一个最大元素的指针 */
  *best = 0;
  for (int i = 0; i < n; i++) {
    if (*(a + *best) <= *(a + i)) {
      *best = i;
    }
  }
  return &a[*best];
}

int main(void)
{
  int a[N] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
  int index;
  int *p = last_max(a, N, &index);

  printf("最后一个最大值(index:%d): %d\n", index, *p);
  return 0;
}
