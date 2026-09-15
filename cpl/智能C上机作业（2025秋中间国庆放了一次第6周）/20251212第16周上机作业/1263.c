#include<stdio.h>
#include<ctype.h>

int main(void)
{
	char s[100],ch;
	int freq[26]={0},i=0;

	gets(s);
	for(i=0;s[i];i++)
		if(isalpha(s[i])){
			ch=(s[i]>='A'&&s[i]<='Z')?s[i]+32:s[i];
			freq[ch-'a']++;
		}
	for(i=0;i<26;i++)
		if(freq[i])	printf("%c:%d ",i+'a',freq[i]);
	return 0;
}
