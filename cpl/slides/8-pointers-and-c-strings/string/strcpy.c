#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void StrCpy(char *dest, const char *src);
void StrCpy1(char *dest, const char *src);
void StrCpy2(char *dest, const char *src);
void StrCpy3(char *dest, const char *src);
void StrCpy4(char *dest, const char *src);
void StrCpy5(char *dest, const char *src);
char *StrCpyStd(char *dest, const char *src);

int main(){
    const char *src = "Hello world";
    char dest[strlen(src) + 1];
    //char *dest = malloc(sizeof(*src))
    StrCpy(dest, src);
    printf("%s\n", dest);

    printf("%s\n", StrCpyStd(dest, src));
    return 0;
}

void StrCpy(char *dest, const char *src){
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void StrCpy1(char *dest, const char *src){
    int i = 0;
    while ((dest[i] = src[i])!= '\0')
    {
        i++;
    }
}

void StrCpy2(char *dest, const char *src){
    int i = 0;
    while ((*(dest + i) = *(src + i)) != '\0')
    {
        i++;
    }       
}

void StrCpy3(char *dest, const char *src){
    while ((*(dest++) = *(src++))!='\0');
}

void StrCpy4(char *dest, const char *src){
    while ((*dest++ = *src++)!='\0');
}

void StrCpy5(char *dest, const char *src){
    while ((*dest++ = *src++));
}

char *StrCpyStd(char *dest, const char *src){
    char *s = dest;
    for(s = dest; (*s++ = *src++)!='\0'; );
    
    return dest;
}