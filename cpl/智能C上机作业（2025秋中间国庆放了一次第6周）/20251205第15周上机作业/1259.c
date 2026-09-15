#include<stdio.h>
#include<math.h>

int prime(int n);
int suc_prime(int n);

int main(void)
{
	int a[4][4]={3,6,4,17,8,5,9,10,9,19,7,20,4,14,21,23},i,j,count=0;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<4;i++)
		for(j=0;j<=i;j++)
			if(prime(a[i][j])) a[i][j]=suc_prime(a[i][j]),count++;
			else a[i][j]=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("count=%d\n",count);
	return 0;
}

int prime(int n)
{
	int i,r;

	if(n<=1)
		return 0;

	r=sqrt(n);
	for(i=2;i<=r;i++)
		if(n%i==0) return 0;
	return 1;
}
int suc_prime(int n)
{
	int i;
	for(i=n+1;;i++)
		if(prime(i)) return i;
}
