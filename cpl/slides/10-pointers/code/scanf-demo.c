/* scanf-demo.c: scanf 与传址的完整示例
   演示两种正确写法:
     1) scanf("%d", &i);  // 传 i 的地址
     2) scanf("%d", p);   // p 已经保存了 &i
   样例运行:
     输入一个整数: 42
     i = 42, *p = 42
     再输入一个整数: 7
     i = 7, *p = 7
   注意: scanf("%d", &p) 是错误写法, &p 的类型是 int **. */
#include <stdio.h>

int main(void)
{
    int i = 0;
    int *p = &i;

    printf("输入一个整数: ");
    scanf("%d", &i);          /* 方式 1: 传 i 的地址 */
    printf("i = %d, *p = %d\n", i, *p);

    printf("再输入一个整数: ");
    scanf("%d", p);           /* 方式 2: p 里已经是 &i */
    printf("i = %d, *p = %d\n", i, *p);

    /* scanf("%d", &p);  // 错误: &p 是 int ** */
    return 0;
}
