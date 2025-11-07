#include <stdio.h>

int is_leap_year(year) {
    int leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        leap = 1;
    }
    return leap;
}

int main(void) {
    int year = 0;
    scanf("%d", &year);

    int leap = is_leap_year(year);
    if (leap == 0) {
        printf("%d is a common year\n", year);
    } else {
        printf("%d is a leap year\n", year);
    }

    return 0;
}

