#include<stdio.h>
double x,y;
void fun(char op,double a,double b,double c,double d)
{
	switch(op){
		case '+':x=a+c,y=b+d;break;
		case '-':x=a-c,y=b-d;break;
		case '*':x=a*c-b*d,y=b*c+a*d;
	}
} 
int main(void)
{
	char op;
	double a,b,c,d;
	scanf("(%lf+%lfi)%c(%lf+%lfi)",&a,&b,&op,&c,&d);
	fun(op,a,b,c,d);
	printf("(%lf+%lfi)%c(%lf+%lfi)=(%lf)+(%lf)i\n",a,b,op,c,d,x,y);
	return 0;
}
