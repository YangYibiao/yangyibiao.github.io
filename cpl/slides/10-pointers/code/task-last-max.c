/* task-last-max.c: 任务 6 —— 返回指向最后一个最大元素的指针
   任务: 完成 int *last_max(int *a, int n),
         返回指向最后一个最大元素的指针.
   测试数组: 3 8 1 9 2 7 4 6 9 0
   期望输出: 最后一个最大值: 9 (下标 8)
   提示: 用指针遍历; 遇到 >= 当前最大值就更新, 这样保留最后一个.
   在 TODO 处补完函数体. */
#include <stdio.h>

#define N 10

int *last_max(int *a, int n)
{
  /* TODO: 返回指向最后一个最大元素的指针 */
  return a;
}

int main(void)
{
  int a[N] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
  int *p = last_max(a, N);

  printf("最后一个最大值: %d (下标 %d)\n", *p, (int)(p - a));
  return 0;
}
