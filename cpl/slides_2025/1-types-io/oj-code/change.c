#include <stdio.h>

int main() {
  int change;
  scanf("%d", &change);

  int c_50 = change / 50;
  change = change - c_50 * 50;
  int c_20 = change / 20;
  change = change - c_20 * 20;
  int c_10 = change / 10;
  change = change - c_10 * 10;
  int c_5 = change / 5;
  int c_1 = change - c_5 * 5;
  printf("%d\n%d\n%d\n%d\n%d", c_50, c_20, c_10, c_5, c_1);
  return 0;
}
