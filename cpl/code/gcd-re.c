#include <stdio.h>

int gcd(int a, int b);

int main(void)
{
    for (int i = 0; i < 4; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        printf("The greatest common divisor for %d and %d is %d", a, b, gcd(a, b));
    }

    return 0;
}

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else if (b % a == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}