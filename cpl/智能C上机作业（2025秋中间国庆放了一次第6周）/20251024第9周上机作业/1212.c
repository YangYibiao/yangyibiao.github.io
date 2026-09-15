#include <stdio.h>
int main()
{
	int x,i=2;
	scanf("%d",&x);
	printf("%d=",x);
	while(x!=i){
		if(x%i==0){
			printf("%d*",i);
			x=x/i;
		}
		else
			i++;
	}
	printf("%d",i);
}
