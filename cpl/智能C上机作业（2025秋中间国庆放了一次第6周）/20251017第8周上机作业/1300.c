#include<stdio.h> 
int main(void)
{
	int t1,t2,s;
//	printf("输入时间点t1、t2（t1、t2在7:30到8:00之间且t1<t2，格式如7:30 7:40，\":\"前后都是整数，表示从7点30到7点40）");
	scanf("%*c%*c%d %*c%*c%d",&t1,&t2);
	if(t2==0) t2=60;
	if(t2<=40)
		s=(t2-t1)*100;
	else if(t2<=50){
		if (t1<=40)
			s=(40-t1)*100+(t2-40)*150;
		else
			s=(t2-t1)*150;
	}
	else if(t2<=60){
		if (t1<=40)
			s=(40-t1)*100+1500+(t2-50)*50;
		else if(t1<=50)
			s=(50-t1)*150+(t2-50)*50;
		else
			s=(t2-t1)*50;
	}
	printf("%d米",s);
}

