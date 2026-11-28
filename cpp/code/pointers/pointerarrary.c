// Date: 2021/7/3
// label: 指针与数组

#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int *p, sum = 0;
    for (p = &a[0]; p < &a[N]; p++)
        sum += *p;

    printf("%d", sum);
    return 0;
}