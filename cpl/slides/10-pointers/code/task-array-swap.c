/* task-array-swap.c: 任务 2 —— 交换数组首尾元素
   任务: 读入 5 个整数存入 a[5], 交换 a[0] 与 a[4],
         输出交换后的数组.
   样例输入: 1 2 3 4 5
   样例输出: 5 2 3 4 1
   提示: 数组元素也是变量, 传地址用 &a[i];
         交换首尾: swap(&a[0], &a[4]).
   在 TODO 处补完代码. */
#include <stdio.h>

#define N 5

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int a[N];

    /* TODO: 读入 N 个数 */
    /* TODO: 交换 a[0] 与 a[N-1] */
    /* TODO: 输出数组 */

    return 0;
}
