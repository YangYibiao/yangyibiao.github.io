/* 原版: 判断逻辑在 main 里 */
#include <stdio.h>
int main(void) {
  int year = 0;
  scanf("%d", &year);
  int leap = 0;
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    leap = 1;
  }
  if (leap == 0) {
    printf("%d 是平年\n", year);
  } else {
    printf("%d 是闰年\n", year);
  }
  return 0;
}
