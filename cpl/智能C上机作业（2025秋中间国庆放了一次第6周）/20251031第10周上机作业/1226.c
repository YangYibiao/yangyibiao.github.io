#include<stdio.h>
#include<math.h>
int main(void){
	double x,a,s;
	int n=1;
	scanf("%lf",&x);
	a=x;
	s=a;
	while(fabs(a)>=1e-8){
		a=-a*x*x/(n+1)/(n+2);
		s=s+a;
		n+=2;
	}
	printf("%.1lf",s);
	return 0;
}
