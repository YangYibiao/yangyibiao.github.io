#include <stdio.h>

int is_leap_year(int n) {
  int leap = 0;
  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    leap = 1;
  }
  return leap;
}

int main(void) {
  int year = 0;
  scanf("%d", &year);

  if (is_leap_year(year)) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is a common year\n", year);
  }

  return 0;
}




