#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int i,r;

	if(n<=1)
		return 0;

	r=sqrt(n);
	for(i=2;i<=r;i++)
		if(n%i==0)
			return 0;

	return 1;
}

int main()
{
	int a[10]={108, 4, 19, 7, 23, 66, 49, 13, 33, 35},i,j,t;

	for(i=0;i<10;i++)
		scanf("%d",&a[i]);

	i=0;j=9;
	while(i<j){
		while(i<10&&!prime(a[i])) i++;
		while(j>=0&&!prime(a[j])) j--;
		if(i<j){
			t=a[i]; a[i]=a[j]; a[j]=t;	i++; j--;	
		}
	}

	for(i=0;i<10;i++)
		printf("%d ",a[i]);

	return 0;
}