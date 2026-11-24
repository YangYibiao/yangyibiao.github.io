/* find-sum-max.c: 课堂编码参考 —— 用指针遍历数组
   任务: 用指针实现 find_sum 和 find_max, 不使用下标 a[i].
   测试数组: 34 82 49 102 7 94 23 11 50 31
   期望输出: sum = 483, max = 102 */
#include <stdio.h>

#define N 10

int find_sum(int *a, int n)
{
    int sum = 0;
    for (int *p = a; p < a + n; p++)
        sum += *p;
    return sum;
}

int find_max(int *a, int n)
{
    int max = *a;
    for (int *p = a + 1; p < a + n; p++)
        if (*p > max)
            max = *p;
    return max;
}

int main(void)
{
    int b[N] = {34, 82, 49, 102, 7, 94, 23, 11, 50, 31};

    printf("sum = %d\n", find_sum(b, N));   /* 483 */
    printf("max = %d\n", find_max(b, N));   /* 102 */
    return 0;
}
