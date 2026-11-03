/* 原版: 判断逻辑在 main 里 */
#include <stdio.h>

int is_leap_year(int year);

int main(void) {
  int year = 0;
  scanf("%d", &year);
  
  if (is_leap_year(year)) {
    printf("%d 是闰年\n", year);
  } else {
    printf("%d 是平年\n", year);
  }
  return 0;
}

int is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
