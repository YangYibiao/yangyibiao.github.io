#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int d1 = n / 100, d2 = n / 10 % 10, d3 = n % 10;
    if (d1 == d2 && d2 == d3) return 0;

    printf("%d", n);          /* 先输出原始数 */

    for (;;) {
        int d[3] = { d1, d2, d3 };
        /* 降序排序 */
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2 - i; ++j)
                if (d[j] < d[j + 1]) { int t = d[j]; d[j] = d[j + 1]; d[j + 1] = t; }

        int max = d[0] * 100 + d[1] * 10 + d[2];
        int min = d[2] * 100 + d[1] * 10 + d[0];
        n = max - min;

        printf("-%d", n);     /* 输出“-新数” */
        if (n == 495) break;  /* 到达黑洞，立即退出 */

        d1 = n / 100;
        d2 = n / 10 % 10;
        d3 = n % 10;
    }
    return 0;
}
