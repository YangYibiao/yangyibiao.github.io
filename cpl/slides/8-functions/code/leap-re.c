/* Leap year check: no functions */
#include <stdio.h>

int is_leap(int n);

int main(void) {
  int year = 0;
  scanf("%d", &year);
  
  if (is_leap(year)) {
    printf("leap year\n");
  } else {
    printf("common year\n");
  }
  return 0;
}

int is_leap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
