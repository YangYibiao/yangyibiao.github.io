/* reverse-pointer.c: 参考实现 —— 数列反向(指针版) */
#include <stdio.h>

#define N 10

int main(void)
{
    int a[N], *p;
    printf("输入 %d 个数: ", N);
    for (p = a; p < a + N; p++)
        scanf("%d", p);
    printf("逆序输出:");
    for (p = a + N; p != a; )
        printf(" %d", *--p);
    printf("\n");
    return 0;
}
