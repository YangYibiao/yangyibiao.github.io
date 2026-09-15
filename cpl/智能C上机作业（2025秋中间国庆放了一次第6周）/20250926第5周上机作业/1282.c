#include<stdio.h>
int main(void)
{
	int m,y,d,m1;
	printf("请输入一个分钟数：");
	scanf("%d",&m);
	y=m/60/24/365;
	d=(m-y*365*24*60)/60/24;
	m1=m-y*365*24*60-d*60*24;
	if(m1>0) d++;
	printf("\n%ld分钟是%ld年%ld天\n",m,y,d);
} 
