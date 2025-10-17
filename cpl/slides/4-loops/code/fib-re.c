#include <stdio.h>

int fib(int n);

int main(void)
{
    for (int i = 0; i < 20; i++) {
        int r = fib(i);
        printf("%d's fibonacci sequence is %d\n", i, r);
    }

    return 0;
}

int fib(int n)
{
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}