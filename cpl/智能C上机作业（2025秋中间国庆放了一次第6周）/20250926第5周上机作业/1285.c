#include <stdio.h>

int main() {
    double weight;

    scanf("%lf", &weight);
    int max_cans = (int)(weight * 1000 * 5 / (35 * 350 * 0.001));
    printf("%d\n", max_cans);
    
    return 0;
}
