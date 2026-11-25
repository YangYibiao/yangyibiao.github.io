/* digit-to-hex.c: 现场演示 —— 用字符串字面量做查表 */
#include <stdio.h>

char digit_to_hex_char(int digit)
{
    return "0123456789ABCDEF"[digit];
}

int main(void)
{
    for (int i = 0; i < 16; i++)
        printf("%2d -> %c\n", i, digit_to_hex_char(i));
    return 0;
}
