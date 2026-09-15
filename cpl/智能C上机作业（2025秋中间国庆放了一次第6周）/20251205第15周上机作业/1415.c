#include<stdio.h>
void sort(int a[5][5])
{
	int i,j,t;
	for(i=0;i<4;i++){
		for(j=i+1;j<5;j++){
			if(a[i][4-i]>a[j][4-j]){
				t=a[i][4-i];
				a[i][4-i]=a[j][4-j];
				a[j][4-j]=t;
			}
		}
	}
}
int main(void)
{
	int a[5][5]={{0,3,-1,9,3},{8,2,3,7,-5},{4,2,9,8,0},{2,3,-8,6,7},{2,3,7,4,-5}},i,j,sum;

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);


	for(i=0;i<5;i++){
		sum=0;
		for(j=0;j<5;j++){
			sum+=a[i][j];
			a[i][j]=0;
		}
		a[i][4-i]=sum;
	}
	sort(a);
	for(i=0;i<5;i++){
		for(j=0;j<5;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;	
}
