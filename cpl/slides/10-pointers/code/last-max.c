/* last-max.c: 任务 6 参考 —— 返回指向最后一个最大元素的指针
   测试数组: 3 8 1 9 2 7 4 6 9 0
   期望输出: 最后一个最大值: 9 (下标 8) */
#include <stdio.h>

#define N 10

int *last_max(int *a, int n)
{
    int *best = a;
    for (int *p = a + 1; p < a + n; p++) {
        if (*p >= *best)
            best = p;
    }
    return best;
}

int main(void)
{
    int a[N] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
    int *p = last_max(a, N);

    printf("最后一个最大值: %d (下标 %d)\n", *p, (int)(p - a));
    return 0;
}
