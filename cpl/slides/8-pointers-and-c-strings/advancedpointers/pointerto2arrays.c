#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 10

void print_array(int a[][NUM_COLS], int rows, int cols)
{
    int row, col;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
            printf("%d ", a[row][col]);
        printf("\n");
    }
}

void print_array2(int *p, int rows, int cols)
{
    int row, col;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
            printf("%d ", *(p + rows * NUM_COLS + cols));
        printf("\n");
    }
}

int main()
{
    int a[NUM_ROWS][NUM_COLS];

    /* 方法1: 使用嵌套的for循环来进行二维数组的初始化 */
    int row, col;
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            a[row][col] = 0;
        }
    }

    printf("方法1: a = \n");
    print_array(a, NUM_ROWS, NUM_COLS);

    printf("a[0] \t = %p\n", a[0]);
    printf("&a[0][0] = %p\n", &a[0][0]);
    printf("&a[0][1] = %p\n", &a[0][1]);

    printf("a[1] \t = %p\n", a[1]);
    printf("&a[1][0] = %p\n", &a[1][0]);
    printf("&a[1][1] = %p\n", &a[1][1]);

    /* 方法2: 将a视为一维的整型数组, 单个循环进行初始化 */
    int *p;
    for (p = &a[0][0]; p <= &a[NUM_ROWS - 1][NUM_COLS - 1]; p++) {
        *p = 1;
    }

    printf("方法2: a = \n");
    print_array(a, NUM_ROWS, NUM_COLS);

    /* 方法3: 使用指针数组来进行初始化 */
    int *p2[NUM_ROWS];
    for (row = 0; row < NUM_ROWS; row++) {
        p2[row] = &a[row][0];
    }

    printf("p2[0] = %p\n", p2[0]);
    printf("p2[1] = %p\n", p2[1]);
    printf("p2[2] = %p\n", p2[2]);

    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            p2[row][col] = 2;
        }
    }

    printf("方法3: a = \n");
    print_array(a, NUM_ROWS, NUM_COLS);

    /* 方法4: 使用指向指针的指针来进行初始化 (错误版本) */
    /*
    int ** p3;
    p3 = &a[0];
    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            p3[row][col] = 3;
        }
    }

    printf("方法4: a = \n");
    print_array(a, NUM_ROWS, NUM_COLS);
    */

    return 0;
}
