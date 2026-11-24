/* pointer-inc-demo.c: 现场演示 —— * 和 ++ 的四种组合 */
#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    int v;

    v = *p++;
    printf("*p++   = %d, p -> a[%d]\n", v, (int)(p - a));
    printf("*p     = %d\n", *p);

    p = a;
    v = (*p)++;
    printf("(*p)++ = %d, a[0] = %d, p -> a[%d]\n", v, a[0], (int)(p - a));
    printf("a[0]   = %d\n", a[0]);

    p = a;
    v = *++p;
    printf("*++p   = %d, p -> a[%d]\n", v, (int)(p - a));

    p = a;
    v = ++*p;
    printf("++*p   = %d, a[0] = %d\n", v, a[0]);
    return 0;
}
