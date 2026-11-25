/* task-reverse-array.c: 动态数组练习
   任务: 读入 n, 用 malloc 建 n 个 int 的数组, 填入 1..n,
         逆序输出, 最后 free.
   样例输入: 5
   样例输出: 5 4 3 2 1
   提示: 先用 malloc 申请 n 个 int 并检查 NULL; 输出循环从 n-1 到 0; 最后 free.
   在 TODO 处补完代码. */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int *a = NULL;

    /* TODO: 用 malloc 申请 n 个 int, 并检查 NULL */

    /* TODO: 填入 1..n */
    /* TODO: 逆序输出 */
    printf("\n");

    /* TODO: free(a); a = NULL; */
    return 0;
}
