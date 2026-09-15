#include<stdio.h>

int com(int *a,int *b,int *c);

int main(void)
{
	int a[10]={3,6,7,18,23,33,35,43,48,78},b[10]={2,7,13,21,33,37,48,50,58,67},c[30]={0};
	int i,count;

	for(i=0;i<10;i++)
		scanf("%d",&a[i]);

	for(i=0;i<10;i++)
		scanf("%d",&b[i]);

	count=com(a,b,c);
	for(i=0;c[i]&&i<20;i++)
		printf("%d ",c[i]);
	printf("\ncount=%d\n",count);
	return 0;
}

int com(int *a,int *b,int *c)
{
	int i=0,j=0,count=0,k=0;
	while(i<10&&j<10)
		if(a[i]<b[j]) c[k++]=a[i++];
		else if(a[i]==b[j]) count++,i++,j++;
		else c[k++]=b[j++];
	while(i<10) c[k++]=a[i++];
	while(j<10) c[k++]=b[j++];
	return count;
}
