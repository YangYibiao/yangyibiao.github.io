#include<stdio.h>
#include<math.h>
int main(void)
{
    int a,b,c;
    double s,s1;
    scanf("%d%d%d",&a,&b,&c);
    s=(a+b+c)/2.0;
    s1=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%lf",s1);
}

