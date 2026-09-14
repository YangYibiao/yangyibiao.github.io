#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    char sch[16];
    scanf("%s", sch);
    int len = strlen(sch);

    char tch[22] = {0};
    int v = 1;
    int s = 0;
    int p = 1;
    int r = 0;
    for (int j = len - 1; j >= 0; j--) {
      if (sch[j] <= '9' && sch[j] >= '0') {
        s += (sch[j] - '0') * p;
      } else if (sch[j] == '-' && j == 0) {
        r = 1;
      } else {
        v = 0;
        break;
      }
      p *= 10;
    }

    if (v == 1) {
//      printf("Decimal number: %d\n", s);
      int ind = 0;
      do {
        tch[ind++] = s % 3 + '0';
        s /= 3;
      } while (s != 0);
      tch[ind] = '\0';

      int u;
      do {
        u = 0;
        int tlen = strlen(tch);
//        printf("ternary number(before): %s\n", tch);
        for (int j = 0; j < tlen; j++) {
          if (tch[j] == '2') {
            tch[j] = 'Z';
            if (tch[j + 1] == '\0') {
              tch[j + 1] = '1';
              tch[j + 2] = '\0';
            } else {
              tch[j + 1] += 1;
            }
            u = 1;
            break;
          } else if (tch[j] == '3') {
            tch[j] = '0';
            if (tch[j + 1] == '\0') {
              tch[j + 1] = '1';
              tch[j + 2] = '\0';
            } else {
              tch[j + 1] += 1;
            }
            u = 1;
            break;
          }
        }
//        printf("after: %s\n", tch);
      } while (u == 1);

      if (r == 1) {
        int tlen = strlen(tch);
        for (int j = tlen - 1; j >= 0; j--) {
          if (tch[j] == 'Z') {
            tch[j] = '1';
          } else if (tch[j] == '1') {
            tch[j] = 'Z';
          }
        }
      }

      int tlen = strlen(tch);
      for (int j = tlen - 1; j >= 0; j--) {
        printf("%c", tch[j]);
      }
      printf("\n");
    } else {
      printf("Radix Error\n");
    }
  }

  return 0;
}
