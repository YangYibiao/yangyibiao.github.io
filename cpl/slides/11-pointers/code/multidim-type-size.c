/* multidim-type-size.c: 用 sizeof 观察二维数组的表达式类型 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void)
{
    int a[ROWS][COLS] = {0};
    int (*rowp)[COLS] = a + 0;   /* a + 0 退化成行指针 */

    printf("sizeof(int)      = %zu\n", sizeof(int));
    printf("sizeof(a)        = %zu  (整个二维数组)\n", sizeof(a));
    printf("sizeof(a[0])     = %zu  (一行)\n", sizeof(a[0]));
    printf("sizeof(a[0][0])  = %zu  (一个 int)\n", sizeof(a[0][0]));
    printf("sizeof(*a)       = %zu  (一行, 不是 int)\n", sizeof(*a));
    printf("sizeof(rowp)     = %zu  (a + 0 退化成的行指针)\n", sizeof(rowp));
    printf("sizeof(&a[0][0]) = %zu  (int *)\n", sizeof(&a[0][0]));

    printf("&a        = %p\n", (void *)&a);
    printf("a         = %p\n", (void *)a);
    printf("&a[0]     = %p\n", (void *)&a[0]);
    printf("a[0]      = %p\n", (void *)a[0]);
    printf("&a[0][0]  = %p\n", (void *)&a[0][0]);

    printf("a + 1        = %p\n", (void *)(a + 1));
    printf("&a[0][0] + 1 = %p\n", (void *)(&a[0][0] + 1));
    printf("(a + 1) - a  = %td 行\n", (a + 1) - a);
    return 0;
}
