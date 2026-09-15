#include<stdio.h>
#include<math.h>
double f(double x){
	return (exp(x)+x);
}
int main(void){
	double a=-1,b=1,c,x,eps;
	scanf("%lf",&eps);
	if(fabs(f(a))<eps)
		x=a;
	else if(fabs(f(b))<eps)
		x=b;
	else{
		do{
			c=(a+b)/2;
			if(f(a)*f(c)<0)
				b=c;
			else
				a=c;
		}while(fabs(f(c))>eps&&fabs(b-a)>eps);
		x=c;
	}
	printf("x=%lf",x);
	return 0;
}
