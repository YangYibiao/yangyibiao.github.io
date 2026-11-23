/* minmax-avg.c: 任务 4 参考 —— 一次带回最大、最小和平均值
   测试输入: 3 8 1 9 2 7 4 6 5 0
   期望输出:
     最大: 9
     最小: 0
     平均: 4.50 */
#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min, double *avg)
{
    int sum = a[0];
    *max = *min = a[0];
    for (int i = 1; i < n; i++) {
        sum += a[i];
        if (a[i] > *max) *max = a[i];
        if (a[i] < *min) *min = a[i];
    }
    *avg = (double)sum / n;
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
    printf("平均: %.2f\n", avg);    /* 期望 4.50 */
    return 0;
}
