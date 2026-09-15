#include<stdio.h>
#include<math.h>
double f(double x)
{
	return (2*x+1);
}

double integral(double a,double b,long n,double (*p)(double))
{
	double s,h;
	int i;
	h=(b-a)/n;
	s=((*p)(a)+(*p)(b))/2;
	for(i=1;i<n;i++){
		s+=(*p)(a+i*h);
	}
	return (s*h);
}

int main(void)
{
	double a,b;
	long n;
	scanf("a=%lf,b=%lf,n=%ld",&a,&b,&n);
	printf("integral cos:%lf\n",integral(a,b,n,cos));
	printf("integral sin:%lf\n",integral(a,b,n,sin));
	printf("integral 2x+1:%lf\n",integral(a,b,n,f));
	return 0;
}
