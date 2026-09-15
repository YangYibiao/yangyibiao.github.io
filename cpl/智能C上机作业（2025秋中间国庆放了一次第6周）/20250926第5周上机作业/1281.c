#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int units = num % 10;
    int tens = (num / 10) % 10;
    int hundreds = (num / 100) % 10;
    int thousands = num / 1000;
    int sum = units + tens + hundreds + thousands;
    
    printf("%d\n", sum);
    
    return 0;
}
