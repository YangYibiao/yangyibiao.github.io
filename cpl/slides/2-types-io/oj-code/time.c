#include <stdio.h>

int main() {
  char month[20];
  char weekday[20];
  int day, year;
  int hour, minute, second;

  scanf("%s %d%d %s %d %d %d", month, &day, &year, weekday, &hour, &minute, &second);
  printf("%.3s %.3s %.2d %.2d:%.2d:%.2d %.4d", weekday, month, day, hour, minute, second, year);
  return 0;
}
