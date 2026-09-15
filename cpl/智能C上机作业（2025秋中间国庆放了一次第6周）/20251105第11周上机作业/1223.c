#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int i;
	for(i=2;i<=sqrt((double)n);i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(void)
{
	int m,n,i,t=0;
	scanf("%d %d",&m,&n);
	int start = (m > 2) ? m : 2; 
	for(i=start;i<=n-2;i++){
		if(prime(i)&&prime(i+2)){
			printf("(%d,%d)\n",i,i+2);
			t++;	
		}
	}
	if(t==0)
		printf("该区间内无孪生素数");
	else 
		printf("t=%d",t);
	return 0;
}
