/* multidim-type-size.c: 用 sizeof 观察二维数组的表达式类型 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

int find_largest(int a[], int n)
{
    int max = a[0];
    printf("sizeof(a): %zu\n", sizeof(a));
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main(void)
{
    int b[10] = {0};
    printf("sizeof(b): %zu\n", sizeof(b));
    find_largest(b, 10);

    int a[ROWS][COLS] = {0}; /* 3 * 4 */
    int (*rowp)[COLS] = a + 0;   /* a + 0 变成行指针 */

    printf("sizeof(int)      = %zu\n", sizeof(int));
    printf("sizeof(a)        = %zu  (整个二维数组)\n", sizeof(a));
    printf("sizeof(a[1])     = %zu  (一行)\n", sizeof(a[1]));
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

    rowp = a + 0;
    return 0;
}
