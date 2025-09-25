#include <stdio.h>

int main(int argc, char ** argv){
    printf("%d\n", argc);
    int i = 1;
    while (i!=argc)
    {
        //*(argv[i]) = 'm';
        printf("%s %c\n", argv[i], *(argv[i] + 1));
        i++;
    }
}