#include<stdio.h>
int huiwen(long n)
{
	long a=n,m=0;
	while(n!=0){
		m=m*10+n%10;
		n=n/10;
	}
	if(m==a)
		return 1;
	else
		return 0;    //注意：用于判断的函数，是返回1，不是也必须返回0，否则如果不是也没有给定返回值，系统会随即返回一个值，该值很可能是非0，导致判断结果的错误
}
int main(void)
{
	long i;
	for(i=1;i<=300;i++){
		if(huiwen(i)&&huiwen(i*i))
			printf("%ld\n",i);
	}
	return 0;
}
