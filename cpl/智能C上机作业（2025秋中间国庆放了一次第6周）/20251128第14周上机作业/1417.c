#include<stdio.h>
int main(void)
{
	int a[10]={5,23,28,34,43,45,56,60,67,90},f,k=0;
	int l=0,r=10,m;
	scanf("%d",&f);
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==f){
			k=1;
			break;
		}
		else if(a[m]>f)
			r=m-1;
		else
			l=m+1;		
	}
	if(k)
		printf("%d",m);
	else
		printf("not found");
}
