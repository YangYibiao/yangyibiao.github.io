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
void guest(int n)    //思考：为何函数无返回值？
{
	int i;
	for(i=3;i<=n/2;i+=2){
		if(prime(i)&&prime(n-i))
			printf("%d=%d+%d ",n,i,n-i);
	}
	putchar('\n');
}
int main(void)
{
	int m=6,n=50,i,t=0;
	for(i=m;i<=n;i+=2){
		guest(i);
	}
	return 0;
}

