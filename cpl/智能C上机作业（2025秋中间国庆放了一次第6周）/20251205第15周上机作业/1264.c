#include<stdio.h>
#include<ctype.h>

int fun(char a[]);

int main(void)
{
	char s[100],ch;
	int n;

	gets(s);
	n=fun(s);
	printf("%d:",n);
	puts(s);
	return 0;
}

int fun(char a[])
{	
	int i,j=0,count=0;
	for(i=0;a[i];i++)
		if(!isdigit(a[i]))
			a[j++]=a[i];
		else count++;
	a[j]='\0';
	return count;	
}

