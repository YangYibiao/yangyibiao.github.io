/* skeleton.c: 指针与函数课堂编码 —— 只写函数体
   任务 1: swap(a, b) 交换两个整数; main 验证交换前 x=1, y=2, 调用后 x=2, y=1
   任务 2: max_min(a, n, &max, &min, &avg) 一次带回最大、最小和平均值
           在参考代码基础上增加 avg 指针参数
   任务 3 (挑战): last_max(a, n) 返回指向最后一个最大元素的指针
   提示: 先想清楚"函数要改谁的什么", 再决定传什么地址 */
#include <stdio.h>

#define N 10

void swap(int *a, int *b)
{
  /* TODO: 借助临时变量交换 *a 与 *b */
}

void max_min(int a[], int n, int *max, int *min, double *avg)
{
  /* TODO: 先假设 a[0] 既是最大也是最小, 遍历更新 *max、*min;
           同时累加求和, 最后把总和除以 n 写入 *avg (注意浮点除法) */
}

int *last_max(int *a, int n)
{
  /* TODO: 用指针遍历, 遇到大于或等于当前最大值的元素就更新;
           遍历结束返回指向最后一个最大元素的指针 */
}

int main(void)
{
  int x = 1, y = 2;
  int a[] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
  int big, small;
  double avg;
  int *p;

  swap(&x, &y);
  printf("交换后: x=%d, y=%d\n", x, y);    /* 期望输出: x=2, y=1 */

  max_min(a, N, &big, &small, &avg);
  printf("最大: %d\n", big);      /* 期望输出: 9 */
  printf("最小: %d\n", small);    /* 期望输出: 0 */
  printf("平均: %.2f\n", avg);     /* 期望输出: 4.90 */

  p = last_max(a, N);
  printf("最后一个最大值: %d (下标 %d)\n", *p, (int)(p - a));  /* 期望输出: 9 (下标 8) */
  return 0;
}
