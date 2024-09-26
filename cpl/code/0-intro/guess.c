#include <stdio.h>

int main() {
    int number = 5;
    int guess;

    printf("Guess a number: ");
    scanf("%d", &guess);

    if (guess == number) {
        printf("You guessed it!\n");
    } else {
        printf("You didn't guess it.\n");
    }

    return 0;
}