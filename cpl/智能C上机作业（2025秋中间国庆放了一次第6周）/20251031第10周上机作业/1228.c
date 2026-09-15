#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1.0, fx, df, dx;

    do {
        fx = cos(x) - x;          /* f(x)  */
        df = -sin(x) - 1.0;       /* f'(x) */
        dx = fx / df;
        x -= dx;
    } while (fabs(dx) >= 1e-6);

    printf("x=%.6lf\n", x);
    printf("f(x)=%.6lf\n", fabs(cos(x) - x));
    return 0;
}
