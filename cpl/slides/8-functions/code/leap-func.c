/* leap.c: 函数版 */
#include <stdio.h>
int is_leap_year(int);
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
int is_leap_year(int n) {
  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    return 1;
  }
  return 0;
}
