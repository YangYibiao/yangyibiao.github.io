#include <stdio.h>

int main(void) {
    int year = 0;
    scanf("%d", &year);

    // &&: and (&)
    // ||: or (|)
    // !: not
    int leap = 0; // boolean; indicator; flag
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // (year % 4 == 0 && year % 100 != 0)
//             || (year % 400 == 0);
         leap = 1; // printf("%d is a leap year\n", year);
    }

     if (leap == 0) {
         printf("%d is a common year\n", year);
     } else {
         printf("%d is a leap year\n", year);
     }

//    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

//    if (leap) {
//        printf("%d is a leap year\n", year);
//    } else {
//        printf("%d is a common year\n", year);
//    }
    return 0;
}

