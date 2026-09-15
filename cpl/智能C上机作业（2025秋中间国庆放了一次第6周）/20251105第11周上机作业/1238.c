#include<stdio.h>
int gcd(int a, int b);    //函数引用性声明
int main(void)
{
	int n,i,t=0;
	scanf("%d",&n);
	for(i=1;i<n;i++){
		if(gcd(i,n)==1) t++;
	}
	printf("%d",t);
	return 0;
}
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
