#include<stdio.h>
int main()
{
	char a1,a2;
	double b1,c1,d1,b2,c2,d2;
//	printf("请分别输入一名学生的姓名、数学成绩、物理成绩和化学成绩：\n");
	scanf("%c%lf%lf%lf",&a1,&b1,&c1,&d1);//这里姓名只能是一个字符 
//	printf("请分别输入另一名学生的姓名、数学成绩、物理成绩和化学成绩：\n");
	scanf(" %c%lf%lf%lf",&a2,&b2,&c2,&d2);//注意：%c前面有一个空格
	printf("*********************************************************\n");
	printf("    NAME    MATH    PHYSICS    CHEMSTRY    SUM    AVERAGE\n");
	printf("%8c%8.1lf%11.1lf%12.1lf%7.1lf%11.1lf\n",a1,b1,c1,d1,b1+c1+d1,(b1+c1+d1)/3); 
	printf("%8c%8.1lf%11.1lf%12.1lf%7.1lf%11.1lf\n",a2,b2,c2,d2,b2+c2+d2,(b2+c2+d2)/3);  
	printf("*********************************************************\n");
}


