#include <stdio.h>

int main(void) {
    int year = 0;
    scanf("%d", &year);

    int leap = 0; // boolean; indicator; flag
    // 级联的if else语句
//    if (year % 4 != 0) {
//        leap = 0;
//    } else if (year % 100 != 0) {
//        leap = 1; // year % 4 == 0 and year % 100 != 0
//    } else if (year % 400 != 0) {
//        leap = 0;
//    } else {
//        leap = 1; // year % 4 == 0 and year % 100 == 0 and year % 400 == 0
//    }

    // &&: and (&)
    // ||: or (|)
    // !: not
    // if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    //     leap = 1;
    // } else {
    //     leap = 0;
    // }

    // if (leap == 0) {
    //     printf("%d is a common year\n", year);
    // } else {
    //     printf("%d is a leap year\n", year);
    // }

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    if (leap) {
        printf("%d is a leap year\n", year);
    } else {
        printf("%d is a common year\n", year);
    }
    return 0;
}

