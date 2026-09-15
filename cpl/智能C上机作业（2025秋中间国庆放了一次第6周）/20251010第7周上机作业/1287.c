#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("sin(x):%.6f\n", sin(x));
    printf("cos(x):%.6f\n", cos(x));
    printf("|x|:%.6f\n", fabs(x));
    printf("e?x??:%.6f\n", exp(x));
    printf("x?y??:%.6f\n", pow(x, y));
    
    return 0;
}