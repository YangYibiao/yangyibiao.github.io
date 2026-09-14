#include <stdio.h>
#include <string.h>

#define LEN 1005

int main() {
  char ach[LEN] = {0};
  char bch[LEN] = {0};
  char sch[LEN] = {0};
  while (scanf("%s %s", ach, bch) != EOF) {
//    printf("\na: %s\nb: %s\n", ach, bch);
    int alen = strlen(ach);
    int blen = strlen(bch);
    int carr = 0, k = 0;
    for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; i--, j--, k++) {
      int s;
      if (i < 0) {
        s = bch[j] - '0' + carr;
      } else if (j < 0) {
        s = ach[i] - '0' + carr;
      } else {
        s = ach[i] - '0' + bch[j] - '0' + carr;
      }

      if (s < 10) {
        sch[k] = s + '0';
        carr = 0;
      } else {
        sch[k] = s % 10 + '0';
        carr = 1;
      }
    }

    if (carr == 1) {
      sch[k] = '1';
    }

    for (int i = strlen(sch) - 1; i >= 0; i--) {
      printf("%c", sch[i]);
    }
    printf("\n");

    for (int i = 0; i < LEN; i++) {
      ach[i] = bch[i] = sch[i] = 0;
    }
  }
  return 0;
}
