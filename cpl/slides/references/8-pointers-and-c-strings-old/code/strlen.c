#include <stdio.h>
#include <string.h>

int strlen(const char *str);
size_t strLenStd(const char *s);

int main(){
    char msg[20] = "Hello world";
    char* msg2 = "Hello world";
    printf("%s: %d\n", msg, strlen(msg));
    printf("%s: %d\n", msg, strLenStd(msg));
    printf("%s: %d\n", msg2, strlen(msg2));
    printf("%s: %d\n", msg2, strLenStd(msg2));

    msg[0] = 'N';
    printf("%s: %d\n", msg, strlen(msg));
    *msg2 = 'N';
    printf("%s: %d\n", msg2, strlen(msg2));

    return 0;
}

int strlen(const char *str){
    int cnt = 0;
    while (*str++!='\0')//str[cnt]
    {
        cnt ++;
    }
    return cnt;
}

size_t strLen(char *ptr) {
    char *nptr = ptr;
    while (*nptr) { nptr++; }
    return nptr - ptr;
}

size_t strLenStd(const char *s){
    const char *sc;
    for(sc = s; *sc!='\0'; sc++);

    return (sc - s);
}