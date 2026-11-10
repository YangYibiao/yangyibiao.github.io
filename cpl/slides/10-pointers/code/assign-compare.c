/* assign-compare.c: q = p 与 *q = *p 的区别
   运行结果:
     q = p 后:   i=3 j=2 *p=3 *q=3
     *q = *p 后: i=1 j=1 *p=1 *q=1 */
#include <stdio.h>

int main(void)
{
    int i = 1, j = 2;
    int *p = &i, *q = &j;

    /* ① q = p: 复制地址 */
    q = p;          /* q 改指向 i, 不再指向 j */
    *q = 3;         /* 改的是 i */
    printf("q = p 后:   i=%d j=%d *p=%d *q=%d\n", i, j, *p, *q);

    /* ② *q = *p: 复制值 */
    p = &i; q = &j; i = 1; j = 2;   /* 重置 */
    *q = *p;        /* 把 i 的值复制给 j */
    printf("*q = *p 后: i=%d j=%d *p=%d *q=%d\n", i, j, *p, *q);

    return 0;
}
