/* deref.c: 间接寻址运算符 * 的完整示例
   演示:
     - p = &i 后, p 指向 i
     - 读 *p 得到 i 的值
     - 写 *p = 2 就把 i 改成 2
   运行结果:
     i = 1, *p = 1
     i = 2, *p = 2 */
#include <stdio.h>

int main(void)
{
    int i = 1;
    int *p = &i;                         /* p 指向 i */

    printf("i = %d, *p = %d\n", i, *p);  /* 1 1 */
    *p = 2;                              /* 通过 p 改 i */
    printf("i = %d, *p = %d\n", i, *p);  /* 2 2 */
    return 0;
}
