#include<stdio.h>
#include<math.h>
int prime(int x)
{
	static int k=2;	//静态变量
	if(k>(int)sqrt((double)x)){	//改换条件判断位置，2可不必单独判断
		k=2;	//若有多个素数需要判断时，返回结果前，将静态变量值初始化
		return 1;
	}
	else if(x%k==0){
		k=2;	
		return 0;
	}
	else{
		k++;
		return prime(x);
	}
}
int main(void)
{
	int x;
	scanf("%d",&x);
	printf("%d",prime(x));
	return 0;
}
