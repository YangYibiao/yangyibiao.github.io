#include<stdio.h> 
int main(void)
{
	double i,x;
	//printf("请输入本月的利润（万元）：");
	scanf("%lf",&i);
	switch((int)i/10){	//注意：这里的类型转换，switch的表达式要求是整数类型
		case 0:x=i*0.1;break;
		case 1:x=1.0+(i-10)*0.075;break;
		case 2:
		case 3:x=1.75+(i-20)*0.05;break;
		case 4:
		case 5:x=2.75+(i-40)*0.03;break;
		case 6:
		case 7:
		case 8:
		case 9:x=3.35+(i-60)*0.015;break;
		default:x=3.95+(i-100)*0.01;		
	}
	printf("%.2lf",x);
}

