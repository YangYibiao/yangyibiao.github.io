/* split-time.c: 任务 1 参考 —— 拆分时间
   样例:
     输入: 3661
     输出: 1 1 1 */
#include <stdio.h>

void split_time(int total, int *h, int *m, int *s)
{
    *h = total / 3600;
    *m = total % 3600 / 60;
    *s = total % 60;
}

int main(void)
{
    int total, h, m, s;

    scanf("%d", &total);
    split_time(total, &h, &m, &s);
    printf("%d %d %d\n", h, m, s);

    return 0;
}
