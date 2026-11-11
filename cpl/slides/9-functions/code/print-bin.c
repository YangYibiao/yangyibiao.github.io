/* print-bin.c: 课堂编码 4 参考 —— 递归打印二进制
   运行结果:
     print_bin(10) → 1010
     print_bin(0)  → 0
     print_bin(13) → 1101 */
#include <stdio.h>

void print_bin(int n)
{
    if (n < 2) {
        printf("%d", n);
        return;
    }
    print_bin(n / 2);
    printf("%d", n % 2);
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
