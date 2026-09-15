#include <stdio.h>
#include <math.h>
int main(void)
{	 
	int m,p=2,i=1,j,t;
	while(i<=5){
		m=pow(2,p)-1;
		for(t=1,j=2;j<=sqrt(m);j++) 
			if(m%j==0) break;
		if(j>sqrt(m)){
			printf("%d\n",m);
			i++;
		}
		t=0;
		while(t==0){
			p++;
			for(t=1,j=2;t&&j<=sqrt(p);j++) 
				if(p%j==0) t=0;
		}
	}
}

