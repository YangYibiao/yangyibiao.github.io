/* array-pointer.c: 任务参考 —— 数组名与指针 */
#include <stdio.h>

#define N 6

int main(void)
{
    int a[N] = {2, 4, 6, 8, 10, 12};
    int sum = 0;

    for (int *p = a; p < a + N; p++)
        sum += *p;

    for (int i = 0; i < N; i++)
        printf("i=%d: a[%d]=%d, *(a+%d)=%d\n",
               i, i, a[i], i, *(a + i));

    printf("sum = %d\n", sum);
    printf("a = %p, &a[0] = %p\n",
           (void *)a, (void *)&a[0]);
    printf("a + 1 = %p, &a[1] = %p\n",
           (void *)(a + 1), (void *)&a[1]);
    return 0;
}
