/* array-swap.c: 任务 2 参考 —— 交换数组首尾元素
   读入 5 个整数, 交换 a[0] 与 a[4], 输出交换后的数组. */
#include <stdio.h>

#define N 5

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int a[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    swap(&a[0], &a[N - 1]);

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
