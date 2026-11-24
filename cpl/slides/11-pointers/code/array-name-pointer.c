/* array-name-pointer.c: 现场演示 —— 数组名作为指针
   观察 a[i] 与 *(a + i)、a 与 &a[0] 的关系. */
#include <stdio.h>

#define N 10

int main(void)
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *p;
    int sum = 0;

    *a = 7;          /* a[0] = 7 */
    *(a + 1) = 12;   /* a[1] = 12 */
    printf("a[0] = %d, a[1] = %d\n", a[0], a[1]);

    /* 原始写法: 从 &a[0] 走到 &a[N] */
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;
    printf("sum (p = &a[0]) = %d\n", sum);

    /* 简化写法: 数组名 a 就是首地址 */
    sum = 0;
    for (p = a; p < a + N; p++)
        sum += *p;
    printf("sum (p = a)      = %d\n", sum);

    /* a 是数组名, 不能自增; a++ 非法 (编译错误) */
    /* a++; */

    /* 指针变量可以移动: 走到值为 0 的元素 */
    p = a;
    while (*p != 0)
        p++;
    printf("第一个 0 在 a[%d]\n", (int)(p - a));

    return 0;
}
