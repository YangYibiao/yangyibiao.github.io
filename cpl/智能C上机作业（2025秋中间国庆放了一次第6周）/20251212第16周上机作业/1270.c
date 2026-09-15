#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define N 2

void count(char a[], char w[][10], int n,int b[]);

int main(void)
{
	char s[100]="this is a book, that is an apple",str[N][10]={0};
	int i=0,frequency[N]={0};

	gets(s);
	count(s,str,N,frequency);
	for(i=0;i<N;i++) printf("%s:%d ",str[i],frequency[i]);
	return 0;
}

void count(char a[], char w[][10], int n,int b[])
{
	char temp[10];
	int word=0,k=0,i,j,ct=0;

	for(i=0;i<=strlen(a);i++)
		if(isalpha(a[i])){
			if(word==0) k=0;
			temp[k++]=a[i];
			word=1;
		}
		else if(word==1){
			temp[k]='\0';
			word=0;
			if(ct<n){
				strcpy(w[ct],temp);
				b[ct++]=1;
			}
			else
				for(j=0;j<n;j++)
					if(strcmp(temp,w[j])==0) b[j]++;

		}

}
