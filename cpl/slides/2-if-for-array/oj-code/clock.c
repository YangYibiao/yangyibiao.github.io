#include <stdio.h>

int main() {
  int h, m;
  scanf("%d:%d", &h, &m);

  int h_n;
  if (h < 13) {
    h_n = h;
  } else {
    h_n = h % 12;
  }

  printf("%.2d:%.2d", h_n, m);
  if (h >= 12) {
    printf(" p.m.");
  } else {
    printf(" a.m.");
  }
  return 0;
}
