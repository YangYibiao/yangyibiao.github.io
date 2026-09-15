#include<stdio.h>
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

int Del_findgcd(int a[],int n,int *f)
{
	int i,j;
	for(i=0;i<n/2;i++)
		a[i]=a[2*i];
	j=gcd(a[0],a[1]);
	for(i=2;i<n/2;i++)
		j=gcd(a[i],j);
	*f=j;
	return n/2;
}

int main()
{
	int a[10]={6,8,9,11,12,13,15,16,18,19},i,n,x;

	for(i=0;i<10;i++)
		scanf("%d",&a[i]);

	n=Del_findgcd(a,10,&x);
	for(i=0;i<n;i++)
		printf("%4d",a[i]);
	printf(", max common divisor is %d.",x);
	return 0;
}
