#include<stdio.h> 
int main(void)
{
	int a,b,c,t;
	printf("请分别三个整数a,b,c（以空格分隔）:");
	scanf("%d%d%d",&a,&b,&c);
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	if(a>b){	
		t=a;
		a=b;
		b=t;
	}
	printf("%d<%d<%d",a,b,c);
}

