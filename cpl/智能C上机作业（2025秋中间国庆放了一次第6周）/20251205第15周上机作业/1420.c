#include<stdio.h>	 
int  findsub(int a[],int n,int b[]);
int main(void)
{
	int i,t,num[10]={7,2,6,9,8,3,4,5,2,1},b[10];

	for(i=0;i<10;i++)
		scanf("%d",&num[i]);

	t=findsub(num,10,b);
	
	for(i=0;i<10;i++) printf("%d ",num[i]);
	printf("\n");
	for(i=0;i<t-1;i++) printf("%d ",b[i]);
	printf("\n%d\n",t);
	return 0;
}
int  findsub(int a[],int n,int b[])
{
	int i=1,j=0,count=1,flag;
	if(a[0]<a[1])
		flag=1;
	else
		flag=0;
	while(i<n-1){
		if(flag){
			while(i<n-1&&a[i]<a[i+1]) i++;
			flag=0;
		}
		else{
			while(i<n-1&&a[i]>a[i+1]) i++;
			flag=1;
		}
		if(i<n-1){
			b[j++]=i;
			count++;
		}
	}
	return count;
}
