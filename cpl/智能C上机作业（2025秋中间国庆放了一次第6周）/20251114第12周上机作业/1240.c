#include <stdio.h>

void convert(int m, int n) {
    if (m == 0) {
        return; 
    }
    int remainder = m % n; 
    convert(m / n, n);    
    
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", 'A' + remainder - 10);
    }
}

int main() {
    int num, base;
    scanf("%d %d", &num, &base);
    if (num == 0) {
        printf("0");
    } else {
        convert(num, base);
    }
    printf("\n");
    return 0;
}