#include<stdio.h> 
#include<math.h>
int main(void)
{
	int a,b,c;
	double p,x1,x2;
	printf("请分别输入二元一次方程的三个参数a,b,c（以逗号分隔）:");
	scanf("%d%d%d",&a,&b,&c);
	p=1.0*b*b-4.0*a*c;
	if(p>=0){
		x1=(-b+sqrt(p))/2/a;
		x2=(-b-sqrt(p))/2/a;
		printf("方程的实根为%.2lf %.2lf",x1,x2);
	}
	else
		printf("方程没有实根！");
}

