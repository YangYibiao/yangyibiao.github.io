/* task-minmax-avg.c: 任务 4 —— 一次带回最大、最小和平均值
   任务: 完成 max_min, 通过指针带回 *max、*min、*avg.
   测试输入: 3 8 1 9 2 7 4 6 5 0
   期望输出:
     最大: 9
     最小: 0
     平均: 4.90
   提示: 先假设 a[0] 既是最大也是最小, 遍历更新 *max、*min;
         同时累加求和, 最后 *avg = (double)sum / n.
   在 TODO 处补完函数体. */
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min, double *avg)
{
  /* TODO: 求最大、最小、平均值, 分别写入 *max、*min、*avg */
}

int main(void)
{
  int b[N], big, small;
  double avg;

  printf("输入 %d 个数: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }
  max_min(b, N, &big, &small, &avg);
  printf("最大: %d\n", big);      /* 期望 9 */
  printf("最小: %d\n", small);    /* 期望 0 */
  printf("平均: %.2f\n", avg);    /* 期望 4.90 */
  return 0;
}
