#include<stdio.h>
int main(void){
	int x0=2,x1=3,i,x;
	printf("%d %d ",x0,x1);
	for(i=3;i<=20;i++){
		if(i%2!=0)
			x=x0+x1;
		else
			x=x0-x1;	
		printf("%d ",x);
		x0=x1;
		x1=x;
	}
	return 0;
}
