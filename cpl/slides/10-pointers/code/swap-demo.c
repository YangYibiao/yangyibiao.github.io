/* swap-demo.c: 传址调用 swap 的两种等价写法
   运行结果:
     swap(&x,&y): x=2, y=1
     swap(p,q):   x=2, y=1 */
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 1, y = 2;
    int *p = &x, *q = &y;

    swap(&x, &y);          /* 直接传变量的地址 */
    printf("swap(&x,&y): x=%d, y=%d\n", x, y);

    x = 1; y = 2;          /* 重置, 方便演示第二种写法 */
    swap(p, q);            /* p、q 里存的就是 &x、&y */
    printf("swap(p,q):   x=%d, y=%d\n", x, y);

    return 0;
}
