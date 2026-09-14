#include <stdio.h>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d%d%d", &a, &b, &c);
    int min = 0;
    if (a < b) {
        if (a < c) {
            min = a;
        } else {
            min = c;
        }
    } else {
        if (b < c) {
            min = b;
        } else {
            min = c;
        }
    }
    printf("min(%d, %d, %d) = %d", a, b, c, min);
    return 0;
}
