#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,k;
	for(i=100000;i<=999999;i++){
		j=i;
		k=0;
		while(j!=0){
			k=k*10+j%10;
			j=j/10;
		}
		if(i==k&&(int)sqrt(i)==sqrt(i))
			printf("%d\n",i);
	}
}
