/* task-reverse-array.c: 动态数组练习
   任务: 读入 n, 用 malloc 建 n 个 int 的数组, 填入 1..n,
         逆序输出, 最后 free.
   样例输入: 5
   样例输出: 5 4 3 2 1
   提示: 参照 dynamic-array.c, 把输出循环改成从 n-1 到 0.
   在 TODO 处补完代码. */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("内存不足\n");
        return 1;
    }

    /* TODO: 填入 1..n */
    /* TODO: 逆序输出 */
    printf("\n");

    free(a);
    a = NULL;
    return 0;
}
