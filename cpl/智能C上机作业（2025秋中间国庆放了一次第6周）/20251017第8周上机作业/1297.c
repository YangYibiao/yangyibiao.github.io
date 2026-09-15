#include<stdio.h> 
int main(void)
{
	double n1,n2,n3,n4,n5;
	printf("please input five float numbers:");
	scanf("%lf,%lf,%lf,%lf,%lf",&n1,&n2,&n3,&n4,&n5);
	if(n1<=n2&&n2<=n3&&n3<=n4&&n4<=n5)
		printf("YES.\n");
	else
		printf("NO.\n");
}

