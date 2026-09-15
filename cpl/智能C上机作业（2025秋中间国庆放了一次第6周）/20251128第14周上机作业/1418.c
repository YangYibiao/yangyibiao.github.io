#include<stdio.h>

int mpsort(int x[]);
int prime(int n);

int main(void)
{
	int x[10],i,count;
	for(i=0;i<10;i++)
		scanf("%d",&x[i]);
  	count=mpsort(x);
	for(i=0;i<10;i++)
		printf("%d ",x[i]);
	printf("\nt=%d\n",count);
	return 0;
}

int mpsort(int x[])
{
	int i,j,n,head=0,tail=-1,min,t;
	for(i=1;i<10;i++)
		if(x[i]%2==0&&x[i]>x[head]) head=i;
	for(i=9;i>=0;i--)
		if(prime(x[i])){
			tail=i;
			break;
		}
	n=tail-head+1;
	if(head>=tail) return -1;
	for(i=head;i<tail;i++){
		min=i;
		for(j=i+1;j<=tail;j++)
			if(x[j]<x[min]) min=j;
		if(min!=i){ t=x[min];x[min]=x[i];x[i]=t;}
	}
	return n;
}
int prime(int n)
{
	int i;
	for(i=2;i<n;i++)
		if(n%i==0) return 0;
	return 1;
}
