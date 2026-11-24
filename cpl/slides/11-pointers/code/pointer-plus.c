/* pointer-plus.c: 现场演示 —— 指针 + 整数
   观察 p、q 指向的元素, 以及 p += 6 后 p 的变化. */
#include <stdio.h>

#define N 10

int main(void)
{
    int a[N];
    for (int i = 0; i < N; i++)
        a[i] = i;          /* 让 a[i] 的值等于下标, 便于观察 */

    int *p = &a[2];
    int *q = p + 3;

    printf("p = %p, *p = %d (a[2])\n", (void *)p, *p);
    printf("q = %p, *q = %d (a[5])\n", (void *)q, *q);

    p += 6;
    printf("p += 6 后: p = %p, *p = %d (a[8])\n", (void *)p, *p);

    return 0;
}
