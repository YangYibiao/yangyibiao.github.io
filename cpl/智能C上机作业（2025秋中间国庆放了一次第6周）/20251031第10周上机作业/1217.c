#include<stdio.h>
int main(void){
	int i,max=-1,count=1;
	while(i!=-1){
		scanf("%d",&i);
		if(max<i){
			max=i;
			count=1;
		}			
		else if(max==i)
			count=count+1;
	}
	printf("max=%d count=%d",max,count);
	return 0;
}
