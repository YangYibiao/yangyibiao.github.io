#include<stdio.h>

int main(void)
{
    unsigned int num,kilobit,cenbit,tenbit,indivbit,revnum;
    scanf("%u",&num);
    kilobit=num/1000;
    cenbit=num/100%10;
    tenbit=num/10%10;
    indivbit=num%10;
    revnum=indivbit*1000+tenbit*100+cenbit*10+kilobit;
    printf("%d\n",revnum);

    return 0;
}
