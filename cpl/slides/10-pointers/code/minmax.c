/* minmax.c: 输入 10 个数, 输出最大和最小值 —— 只写函数体
   任务: 用 max_min 一次带回最大和最小两个结果
   提示: return 只能带回一个值; 把 big、small 的地址传进去, 函数通过指针写回
   测试输入: 3 8 1 9 2 7 4 6 5 0 */
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min)
{
  /* TODO: 先假设 a[0] 既是最大也是最小, 再遍历更新 */
}

int main(void)
{
  int b[N], big, small;

  printf("输入 %d 个数: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }
  max_min(b, N, &big, &small);
  printf("最大: %d\n", big);    /* 期望输出: 9 */
  printf("最小: %d\n", small);  /* 期望输出: 0 */
  return 0;
}
