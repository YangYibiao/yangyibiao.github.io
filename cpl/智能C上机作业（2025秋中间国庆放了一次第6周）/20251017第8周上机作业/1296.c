#include<stdio.h> 
int main(void)
{
	double g,h,t,s;
	//printf("please input ¦¤H,T,¦¤S:");
	scanf("%lf%lf%lf",&h,&t,&s);
	g=h-t*s;
	printf("%.2f\n",g);
	if(g<0) printf("Yes\n");
	
}

