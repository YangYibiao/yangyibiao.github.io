#include<stdio.h>
int main()
{
    int m,t1,t2;
    double q;
    scanf("%d %d %d",&m,&t1,&t2); 
    q=4184.0*m*(t2-t1);
    printf("%f\n",q);
    return 0;
} 
