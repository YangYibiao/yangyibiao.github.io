#include <stdio.h>

int main() {
    // 1. set the limit as 100, the number to guess, and the number of tries

    int limit = 100;
    int number_of_tries = 5;

    // 2. set a random number between 1 and limit

    srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();

    int reward = random_variable % limit + 1;

    printf("The number to guess is: %d\n", reward);

    int is_win = 0;
    // 5. loop through the number of tries
    while (number_of_tries > 0 && is_win == 0) {
        // 3. set the guess variable and take the input from the user

        printf("Guess a number: ");

        int guess;
        scanf("%d", &guess);

        printf("The number you guessed is: %d\n", guess);

        // 4. check if the guess is equal to the number

        if (guess == reward) {
            printf("You guessed it!\n");
            is_win = 1;
        } else if (guess > reward) {
            printf("You guessed > reward!\n");
        } else {
            printf("You guessed < reward!\n");
        }

        number_of_tries = number_of_tries - 1;
    }

    if (is_win == 0) {
        printf("You LOSE!\n");
    }

    return 0;
}