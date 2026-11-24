/* multidim-row.c: 现场演示 —— 处理二维数组的行
   演示 p = a[i] / p = &a[i][0], 以及把 a[i] 传给一维数组函数. */
#include <stdio.h>

#define ROWS 3
#define COLS 4

int find_largest(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main(void)
{
    int a[ROWS][COLS] = {
        {3, 8, 1, 9},
        {2, 7, 4, 6},
        {5, 0, 9, 9}
    };
    int *p;

    printf("第 1 行: ");
    for (p = a[1]; p < a[1] + COLS; p++)
        printf("%d ", *p);
    printf("\n");

    /* 把第 1 行清零 */
    for (p = a[1]; p < a[1] + COLS; p++)
        *p = 0;

    printf("清零后第 1 行: ");
    for (p = &a[1][0]; p < &a[1][0] + COLS; p++)
        printf("%d ", *p);
    printf("\n");

    printf("第 2 行最大值: %d\n", find_largest(a[2], COLS));
    return 0;
}
