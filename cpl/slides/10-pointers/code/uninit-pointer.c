/* uninit-pointer.c: 未初始化指针的反例
   运行结果可能因机器/运行而异; 本机示例:
     p  = 0x1f1b34100
     *p = -239910720
     Bus error (core dumped)
   注意: 这个程序运行会崩溃, 这是为了演示未定义行为. */
#include <stdio.h>

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* 让崩溃前的输出先显示 */
    int *p;                          /* 未初始化: p 里是垃圾值 */
    printf("p  = %p\n", (void *)p);  /* 看看 p 里到底是什么 */
    printf("*p = %d\n", *p);         /* 未定义行为 */
    *p = 1;                          /* 更危险: 可能改写未知内存 */
    printf("done\n");
    return 0;
}
