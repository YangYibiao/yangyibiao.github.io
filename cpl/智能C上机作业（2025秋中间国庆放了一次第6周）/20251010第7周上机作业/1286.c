#include<stdio.h>
#include<math.h>

int main(void)
{
    double a;
    char c='+';
    scanf("%lf",&a);
    if(a<0)
        c='-';
    printf("sign:%c\nintegral part:%d\ndecimal fraction part:%lf",
           c, abs((int)a), fabs(a)-abs((int)a));
    return 0;
}