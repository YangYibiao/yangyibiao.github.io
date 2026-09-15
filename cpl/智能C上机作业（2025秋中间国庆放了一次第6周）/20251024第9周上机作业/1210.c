#include <stdio.h>
int main()
{
	int i=1,x,min=100,max=0,s=0;
	//printf("please input ten numbers(1-100):");
	while(i<=10){
		scanf("%d",&x);
		min=x<min?x:min;
		max=x>max?x:max;
		s=s+x;
		i++;
	}
	printf("%.2lf",(s-min-max)/8.0);
}

