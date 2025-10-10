#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    scanf("%d%d", &a, &b);
    int min = 0;
    if (a < b) {
        min = a;
    } else {
        min = b;
    }
    printf("min(%d, %d) = %d", a, b, min);
}