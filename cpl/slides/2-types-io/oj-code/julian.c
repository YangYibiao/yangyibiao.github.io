#include <stdio.h>

int main() {
  int year, month, day;

  scanf("%d%d%d", &year, &month, &day);

  int a = (14 - month) / 12;
  int y = year + 4800 - a;
  int m = month + 12 * a - 3;

  int JDN = day + (153 * m  + 2) / 5 +
            365 * y + y / 4 - y/100 + y /400 - 32045;

  printf("%d", JDN);
  return 0;
}
