#include<stdio.h>
#include<string.h>
int Strlen(const char *str);

size_t StrLenStd(const char *s);

int main(){
    char msg[20] = "Hello world";
    char* msg2 = "Hello world";
    //strlen();
    printf("%s: %d\n", msg, Strlen(msg));
    printf("%s: %d\n", msg, StrLenStd(msg));
    printf("%s: %d\n", msg2, Strlen(msg2));
    printf("%s: %d\n", msg2, StrLenStd(msg2));

    msg[0] = 'N';
    printf("%s: %d\n", msg, Strlen(msg));
    *msg2 = 'N';
    printf("%s: %d\n", msg2, Strlen(msg2));

    return 0;
}
int Strlen(const char *str){
    int cnt = 0;
    while (*str++!='\0')//str[cnt]
    {
        cnt ++;
    }
    return cnt;
}
size_t StrLenStd(const char *s){
    const char *sc;
    for(sc = s; *sc!='\0'; sc++);

    return (sc - s);
}