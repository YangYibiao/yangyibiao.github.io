#include <stdio.h>
#include <string.h>

int main() {
    char *splitch = "#*";
    char str[] = "1234#891624*212734#123*1244";

    //char * p = "jakfg";
    char *p = str;
    char *token;
    //token = strtok(str, splitch);
    //printf("%s\n", token);
    for (token = strtok(str, splitch); token != NULL; token = strtok(NULL, splitch))
        printf("%s\n", token);

    printf("%s", str);
    return 0;
}