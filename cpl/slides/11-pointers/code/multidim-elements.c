/* multidim-elements.c: 现场演示 —— 处理二维数组的元素
   演示嵌套循环与按行优先顺序的指针遍历. */
#include <stdio.h>

#define ROWS 3
#define COLS 4

void print_tarray(int a[][COLS], int rows) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", a[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    int a[ROWS][COLS];

    /* 方法1: 嵌套循环 */
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            a[r][c] = r * COLS + c + 1;
        }
    }
    print_tarray(a, ROWS);

    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r < ROWS; r++) {
            a[r][c] = r * COLS + c + 1;
        }
    }
    print_tarray(a, ROWS);

    printf("方法1 (嵌套循环):\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            printf("%3d", a[r][c]);
        printf("\n");
    }

    /* 方法2: 按行优先顺序用指针遍历 */
    // for (int *p = &a[0][0]; p <= &a[ROWS - 1][COLS - 1]; p++)
    //     *p = 0;

    printf("方法2 (指针遍历后):\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++)
            printf("%3d", a[r][c]);
        printf("\n");
    }

    /* 地址连续: 相邻元素相差 sizeof(int) 3 rows 4 cols */
    printf("&a[0][0] = %p\n", (void *)&a[0][0]);
    printf("&a[0][1] = %p\n", (void *)&a[0][1]);
    printf("&a[1][0] = %p\n", (void *)&a[1][0]);

    int *p;
    p = a[2];          /* p 指向第 1 行第 0 个元素 */
    for (int i = 0; i < COLS; i++) {
        printf("%d ", p[i]);
    }
    
    return 0;
}
