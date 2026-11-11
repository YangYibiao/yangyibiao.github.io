/* swap-rotate.c: 任务 1 参考 —— 用 swap 轮换三个数
   样例:
     输入: 1 2 3
     输出: 2 3 1 */
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    swap(&x, &y);   /* 1 2 3 -> 2 1 3 */
    swap(&y, &z);   /* 2 1 3 -> 2 3 1 */

    printf("%d %d %d\n", x, y, z);
    return 0;
}
