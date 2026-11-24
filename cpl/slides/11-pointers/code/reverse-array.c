/* reverse-array.c: 动手参考 —— 动态数组逆序
   读入 n, 申请 n 个 int, 填入 1..n, 逆序输出, 最后 free. */
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

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    a = NULL;
    return 0;
}
