/* malloc-exhaust.c: 演示不 free 导致内存持续增长
   为安全, 设 128MB 演示上限; 真实程序会继续到 malloc 失败/OOM. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#define BLOCK_MB 1
#define LIMIT_MB 128

static long rss_mb(void)
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
#ifdef __APPLE__
    return ru.ru_maxrss / (1024 * 1024);
#else
    return ru.ru_maxrss / 1024;
#endif
}

int main(void)
{
    int used = 0;
    for (;;) {
        if (used >= LIMIT_MB) {
            printf("已分配 %d MB, 达到演示上限 %d MB\n", used, LIMIT_MB);
            printf("真实程序会继续增长, 最终 malloc 返回 NULL 或被 OOM 杀死.\n");
            break;
        }
        unsigned char *p = malloc(BLOCK_MB * 1024 * 1024);
        if (p == NULL) {
            printf("malloc failed after %d MB\n", used);
            break;
        }
        memset(p, 0, BLOCK_MB * 1024 * 1024);   /* 真正触碰每一页 */
        used += BLOCK_MB;
        if (used % 16 == 0)
            printf("allocated %3d MB, RSS ~ %ld MB\n", used, rss_mb());
    }
    return 0;
}
