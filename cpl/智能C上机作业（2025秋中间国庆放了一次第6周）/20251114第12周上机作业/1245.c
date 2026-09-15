#include<stdio.h>
int inverse(int n)
{
	int m=0;
	while(n!=0){
		m=m*10+n%10;
		n=n/10;
	}
	return m;
}
int main(void)
{
	int x,i;
	scanf("%d",&x);
	for(i=1;i<=10000&&x!=inverse(x);i++){
		x=x+inverse(x);
	}
	if(i>10000)
		printf("error:变换超过10000次啦！");
	else
		printf("%d,%d",x,i-1);
}
