#include<stdio.h>
int a,b,c;    //注意：全局变量的正确使用
int f(int n)
{
	if(n>999){
		a=n/1000;
		b=(n-a*1000)/100;
		c=n%100;
	}
	else{
		a=n/100;
		b=(n-a*100)/10;
		c=n%10;
	}
	if(a*a+b*b==c*c&&a!=0&&b!=0&&c!=0)
		return 1;
	else
		return 0;
}
int main(void)
{
	int m,n,i,t=0;
	do{
		scanf("%d %d",&m,&n);
	}while(!(100<m&&m<10000&&100<n&&n<10000&&m<n));
	for(i=m;i<=n;i++){
		if(f(i))
			printf("%d:%d*%d+%d*%d=%d*%d\n",i,a,a,b,b,c,c);
	}
	return 0;
}

