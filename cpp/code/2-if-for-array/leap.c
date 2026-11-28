#include <stdio.h>

int main(void) {
  int year = 0;
  scanf("%d", &year);
  
  int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  if (leap == 0) {
    printf("%d is a leap year.", year);
  } else {
    printf("%d is not a leap year.", year);
  }
  return 0;
}