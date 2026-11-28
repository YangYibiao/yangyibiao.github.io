/* matrix-param.c: 现场演示 —— 把二维数组传给函数 */
#include <stdio.h>

#define ROWS 3
#define COLS 4

void print_matrix(int (*a)[COLS], int rows)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%3d", *((*(a + i)) + j));
        printf("\n");
        // *(a + i): a[i]
        // a[i][j]
    }
}

int main(void)
{
    int m[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    print_matrix(m, ROWS);
    return 0;
}
