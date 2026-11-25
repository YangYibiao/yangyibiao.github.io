/* string-literal.c: 现场演示 —— 字符串字面量的存储与转义 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *p = "abc";
    char ch = "abc"[1];

    printf("p = %s, p[1] = %c\n", p, p[1]);
    printf("ch = %c\n", ch);
    printf("sizeof(\"abc\") = %zu\n", sizeof("abc"));   /* 4: 含 '\0' */
    printf("strlen(\"abc\") = %zu\n", strlen("abc"));   /* 3: 不含 '\0' */
    printf("one\ntwo\n");
    return 0;
}
