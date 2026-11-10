/* assign-multi.c: 多个指针指向同一块内存
   运行结果: i=2, *p=2, *q=2 */
#include <stdio.h>

int main(void)
{
    int i = 1, *p, *q;

    p = &i;        /* p 指向 i */
    q = p;         /* q 也指向 i: 复制地址 */
    *p = 1;        /* i = 1 */
    *q = 2;        /* i = 2 */
    printf("i=%d, *p=%d, *q=%d\n", i, *p, *q);  /* 2 2 2 */
    return 0;
}
