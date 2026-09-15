#include <stdio.h>
#include <math.h>
int main(void)
{	 
	int x,i;
	int x1,x2,x3;
	for(x=100;x<=999;x++){
		for(i=2;i<=sqrt(x);i++){
			if(x%i==0) break;
		}
		if(i>sqrt(x)&&(x%10+x/10%10)%10==x/100)
			printf("%d\n",x);
	}	
}
