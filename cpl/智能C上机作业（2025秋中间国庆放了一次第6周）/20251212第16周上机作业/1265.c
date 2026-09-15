#include<stdio.h>
#include<ctype.h>

void fun(char xx[]);

int main(void)
{
	char s[100];

	gets(s);
	fun(s);
	puts(s);
	return 0;
}

void fun(char xx[])
{
	int i,count=0;

	for(i=0;xx[i];i++)
		if(isdigit(xx[i])) count++;
	for(i=strlen(xx);i>=0;i--)	{
		xx[i+count]=xx[i];
		if(isdigit(xx[i])){
			xx[i+count-1]='$';
			count--;
		}
	}
}
