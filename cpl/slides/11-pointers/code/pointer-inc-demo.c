/* pointer-inc-demo.c: 现场演示 —— * 和 ++ 的四种组合 */
#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    int v;

    // v = *p++;
    // // v = *p; 
    // // p = p + 1;
    // printf("*p++   = %d, p -> a[%d]\n", v, (int)(p - a));
    // printf("*p     = %d\n", *p);

    // p = a; // p = &a[0];
    // v = (*p)++; 
    // // v = *p; *p = *p + 1;
    // printf("(*p)++ = %d, a[0] = %d, p -> a[%d]\n", v, a[0], (int)(p - a));
    // printf("a[0]   = %d\n", a[0]);

    // p = a; // p = &a[0]
    // v = *++p; // v = *(++p);
    // // p = p + 1; v = *p;
    // printf("*++p   = %d, p -> a[%d]\n", v, (int)(p - a));

    p = a;
    v = ++*p; // ++(*p);
    // *p = *p + 1;
    // v = *p;
    printf("++*p   = %d, a[0] = %d, p -> a[%d]\n", v, a[0], (int)(p - a));
    return 0;
}
