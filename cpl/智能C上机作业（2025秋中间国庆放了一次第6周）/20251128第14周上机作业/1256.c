#include<stdio.h>

int main()
{
	int a[10]={1,4,2,3,4,1,2,5,5,9};
	int i,j,k;

	for(i=0;i<10;i++)
		scanf("%d",&a[i]);

	for(i=j=0;i<10;i++){
		for(k=0;k<j;k++)
			if(a[k]==a[i])
				break;
		if(k>=j)
			a[j++]=a[i];
	}

	for(k=0;k<j;k++)
		printf("%d ",a[k]);
	printf("\n");

	return 0;
}
