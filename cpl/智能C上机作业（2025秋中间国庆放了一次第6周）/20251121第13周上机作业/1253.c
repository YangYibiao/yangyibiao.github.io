#include<stdio.h>
int *count(char *ch_p)
{
	static int i=0;
	if(*ch_p>='A'&&*ch_p<='Z')
		*ch_p=*ch_p+32;
	if(*ch_p=='a'||*ch_p=='e'||*ch_p=='i'||*ch_p=='o'||*ch_p=='u')
		i++;
	return &i;
}
int main(void)
{
    char str[1000]; // 定义字符数组
    int *p;
    gets(str); // 用gets输入字符串
    // 处理每个字符并输出变换后的序列
    for(int i = 0; str[i] != '\0'; i++)
    {
        p = count(&str[i]);
        printf("%c", str[i]);
    }
    printf(",%d", *p); // 输出总数
    return 0;
}
