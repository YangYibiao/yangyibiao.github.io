/* multidim-col.c: 现场演示 —— 处理二维数组的列
   用行指针 p 依次访问每一行的第 i 列. */
#include <stdio.h>

#define ROWS 3
#define COLS 4

int main(void)
{
    int a[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int (*p)[COLS];
    int i = 2;

    printf("第 %d 列: ", i);
    for (p = &a[0]; p < &a[ROWS]; p++)
        printf("%d ", (*p)[2]);
    printf("\n");

    /* 把第 i 列清零 */
    for (p = &a[0]; p < &a[ROWS]; p++)
        (*p)[i] = 0;

    printf("清零后第 %d 列: ", i);
    for (p = &a[0]; p < &a[ROWS]; p++)
        printf("%d ", (*p)[i]);
    printf("\n");
    return 0;
}
