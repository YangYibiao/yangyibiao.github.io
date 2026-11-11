/* task-print-bin.c: 课堂编码 4 —— 递归打印二进制
   任务: 用递归按二进制逐位打印 n (先递归, 后输出).
   样例:
     print_bin(10) → 1010
     print_bin(0)  → 0
     print_bin(13) → 1101
   提示: 基准 n < 2 直接打印; 先 print_bin(n/2), 回来打印 n%2.
   在 TODO 处补完函数体. */
#include <stdio.h>

void print_bin(int n)
{
    /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
    print_bin(10);
    printf("\n");
    print_bin(0);
    printf("\n");
    print_bin(13);
    printf("\n");
    return 0;
}
