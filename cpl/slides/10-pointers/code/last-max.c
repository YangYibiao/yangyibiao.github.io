/* last-max.c: 任务 5 参考 —— 返回指向最后一个最大元素的指针
   测试数组: 3 8 1 9 2 7 4 6 9 0
   期望输出: 最后一个最大值: 9 */
#include <stdio.h>

#define N 10

int *last_max(int *a, int n)
{
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[best])
            best = i;
    }
    return &a[best];
}

int main(void)
{
    int a[N] = {3, 8, 1, 9, 2, 7, 4, 6, 9, 0};
    int *p = last_max(a, N);

    printf("最后一个最大值: %d\n", *p);
    return 0;
}
