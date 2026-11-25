/* string-init-demo.c: 现场演示 —— date3[7] 没有 '\0', 不是字符串 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char date1[8] = "June 14";   /* 恰好: 7 个字符 + '\0' */
    char date3[7] = "June 14";   /* 没有空间存 '\0' */

    printf("date1: sizeof = %zu, strlen = %zu, s = %s\n",
           sizeof(date1), strlen(date1), date1);

    printf("date3: sizeof = %zu\n", sizeof(date3));
    printf("date3 的 7 个字节: ");
    for (int i = 0; i < 7; i++)
        printf("%c", date3[i]);
    printf("\n");

    /* 下面两个操作都要求 date3 以 '\0' 结尾; 否则是未定义行为 */
    printf("strlen(date3) = %zu\n", strlen(date3));
    printf("date3 as string: %s\n", date3);

    return 0;
}
