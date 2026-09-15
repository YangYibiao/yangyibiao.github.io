#include<stdio.h>
#include<string.h>

int replace_str(char *s,char *t,char *g);
int findsub(char *a,char *b);

int main(void)
{
	char s[300],t[100],g[100];
	int count;
	
	scanf("%s%s%s",s,t,g);
	count=replace_str(s,t,g);
	printf("%s\ncount=%d",s,count);
	return 0;
}
int replace_str(char *s,char *t,char *g)
{
	char tempstr[300];
	int position,k,tail;

	if(strlen(s)==0) return 0;
	position=findsub(s,t);
	if(position==-1) return 0;
	k=strlen(t);
	strcpy(tempstr,s+position+k);
	s[position]='\0';
	strcat(s,g);
	tail=strlen(s);
	strcat(s,tempstr);
	return 1+replace_str(s+tail,t,g);
}

int findsub(char *a,char *b)
{
	int i,j,k;
    
	for(i=0;a[i]!='\0';i++){  
		for(j=i,k=0; a[j]==b[k]&&k<strlen(b);j++,k++); 
       		if(b[k]=='\0') return i;
    }
    return -1;
}
