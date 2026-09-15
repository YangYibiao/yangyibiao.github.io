#include<stdio.h>
int main(void)
{
    long a;
    scanf("%ld",&a);
    while(a>0){
        printf("%d\n",a%1000);
        a/=1000;
    }
}
