#include<stdio.h>
#include<string.h>
#include<ctype.h>

int FindNoVowel(char *str[],int num,char res[][20]);
int Novowel(char *s);
void sort(char s[][20],int n);

int main(void)
{
	char dest[10][20],str[10][20]={"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"};
	char *s[10];
	int i=0,n;

	for(i=0;i<10;i++){
		scanf("%s",str[i]);
		s[i]=str[i];
	}
	n=FindNoVowel(s,10,dest);
	for(i=0;i<n;i++) printf("%s ",dest[i]);
	return 0;
}

int FindNoVowel(char *str[],int num,char res[][20])
{
	int i,k=0;
	for(i=0;i<num;i++)
		if(Novowel(str[i])) strcpy(res[k++],str[i]);
	sort(res,k);
	return k;
}
int Novowel(char *s)
{
	int i;
	char ch;

	for(i=0;s[i];i++){
		ch=tolower(s[i]);
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return 0;
	}
	return 1;
} 
void sort(char s[][20],int n)
{	
	char temp[20];
	int i,chg; 
	 
	do { 	
		chg=0;
		for(i=0;i<n-1;i++)
			if(strcmp(s[i],s[i+1])>0)	{ 	
				strcpy(temp,s[i]);strcpy(s[i],s[i+1]);strcpy(s[i+1],temp);
         			chg=1; 
			}
	}while(chg);
}
