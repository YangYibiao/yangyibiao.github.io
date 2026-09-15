#include<stdio.h>
#include<string.h>
#include<ctype.h>

void FindLWord(char *a,char *b);

int main(void)
{
	char s[100],str_long[20]="";
	
	gets(s);
	FindLWord(s,str_long);
	puts(str_long);
	return 0;
}

void FindLWord(char *a,char *b)
{
	char temp[20];
	int word=0,k=0,i,j;

	for(i=0;i<=strlen(a);i++)
		if(isalpha(a[i])){
			if(word==0) k=0;
			temp[k++]=a[i];
			word=1;
		}else if(word==1){
			temp[k]='\0';
			word=0;
			if(strlen(temp)>strlen(b)) strcpy(b,temp);
		}
}
