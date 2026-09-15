#include<stdio.h>

void  line_sort(int a[ ][4],int b[ ],int n);

int main(void)
{
	int a[5][4]={1,4,5,7,3,5,7,8,9,10,2,3,1,3,4,2,1,2,1,1},b[5]={0},i,j;

	for(i=0;i<5;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);

	line_sort(a,b,5);
	for(i=0;i<5;i++){
		for(j=0;j<4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("sum\n");
	for(i=0;i<5;i++) printf("%d ",b[i]);
	return 0;
}

void  line_sort(int a[ ][4],int b[ ],int n)
{
	int i,j,min,t;
	for(i=0;i<n;i++)
		for(j=0;j<4;j++)
			b[i]+=a[i][j];
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++)
			if(b[j]<b[min]) min=j;
		if(min!=i){       
			t=b[min];b[min]=b[i];b[i]=t;
			for(j=0;j<4;j++){	
				t=a[min][j];a[min][j]=a[i][j];a[i][j]=t;}
		}
	}

}
