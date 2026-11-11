/* task-split-time.c: 任务 1 —— 拆分时间
   任务: 读入一个总秒数, 编写 split_time, 把总秒数拆成时、分、秒,
         通过指针参数带回.
   样例输入: 3661
   样例输出: 1 1 1
   提示: 1 小时 = 3600 秒; 用 / 和 %; 通过 *h、*m、*s 写回.
   在 TODO 处补完函数体. */
#include <stdio.h>

void split_time(int total, int *h, int *m, int *s)
{
    /* TODO: 计算时、分、秒, 分别写入 *h、*m、*s */
}

int main(void)
{
    int total, h, m, s;

    scanf("%d", &total);
    split_time(total, &h, &m, &s);
    printf("%d %d %d\n", h, m, s);

    return 0;
}
