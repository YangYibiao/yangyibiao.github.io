/* malloc-leak.c: 演示不 free 的内存泄漏
   终端运行: leaks --atExit -- ./malloc-leak */
#include <stdio.h>
#include <stdlib.h>

#define N 100000

int main(void)
{
    for (int i = 0; i < 10; i++) {
        int *p = malloc(N * sizeof(int));
        if (p == NULL) {
            printf("malloc failed\n");
            return 1;
        }
        p[0] = i;   /* 使用一下, 避免被优化掉 */
        /* 忘记 free(p) */
    }
    printf("done (leaked 10 blocks)\n");
    return 0;
}
