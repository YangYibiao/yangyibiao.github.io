/* string-array-vs-pointer.c: 现场演示 —— 字符数组 vs 字符指针 */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "abc";
    char *p = "abc";

    printf("s = %s, sizeof(s) = %zu, strlen(s) = %zu\n", s, sizeof(s), strlen(s));
    printf("p = %s, sizeof(p) = %zu, strlen(p) = %zu\n", p, sizeof(p), strlen(p));

    s[0] = 'A';                 /* 可以: s 是自己的数组 */
    printf("s[0] = 'A' 后: %s\n", s);

    /* p[0] = 'A';  错误: p 指向只读的字符串字面量 */

    printf("s 的地址 = %p\n", (void *)s);
    printf("p 的值   = %p\n", (void *)p);
    return 0;
}
