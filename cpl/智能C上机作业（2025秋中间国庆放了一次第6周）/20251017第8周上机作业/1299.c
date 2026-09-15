#include <stdio.h>

int main(void)
{
    char c1, c2;

    /* 读第一个字符，跳过空白 */
    if (scanf(" %c", &c1) != 1) return 0;

    /* 统一转大写 */
    if (c1 >= 'a' && c1 <= 'z') c1 -= 32;

    switch (c1)
    {
        case 'M': puts("Monday");    break;
        case 'T':                   /* Tuesday vs Thursday */
            if (scanf(" %c", &c2) != 1) return 0;
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;   /* 转大写 */
            if (c2 == 'U')      puts("Tuesday");
            else if (c2 == 'H') puts("Thursday");
            else                { puts("Illegal input!"); return 0; }
            break;
        case 'W': puts("Wednesday"); break;
        case 'F': puts("Friday");    break;
        case 'S':                   /* Saturday vs Sunday */
            if (scanf(" %c", &c2) != 1) return 0;
            if (c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if (c2 == 'A')      puts("Saturday");
            else if (c2 == 'U') puts("Sunday");
            else                { puts("Illegal input!"); return 0; }
            break;
        default:
            puts("Illegal input!");
            return 0;
    }
    return 0;
}
