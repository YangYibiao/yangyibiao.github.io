/* swap-ptr.c: swap 的传址版
   运行结果: x = 5, y = 3
   说明: 形参用指针, 调用时传 &x、&y, 函数里通过 *a、*b 改 main 的变量. */
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void)
{
    int x = 3, y = 5;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);  /* x = 5, y = 3 */
    return 0;
}
