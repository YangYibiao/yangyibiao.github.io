#include <stdio.h>
#include <string.h>

#define LEN 10005

int main() {
  char ach[LEN] = {0};
  char bch[LEN] = {0};
  char rch[LEN] = {0};
  char c1, c2, op;

  int T;
  scanf("%d", &T);

  for (int m = 0; m < T; m++) {
    scanf("%s %c %s", ach, &op, bch);
    printf("\na: %s\nb: %s, op: %c\n", ach, bch, op);

    int alen = strlen(ach);
    int blen = strlen(bch);

    if (op == '+') { // 加法
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
          rch[k] = s + '0';
          carr = 0;
        } else {
          rch[k] = s - 10 + '0';
          carr = 1;
        }
      }

      if (carr == 1) {
        rch[k] = '1';
      }

      for (int i = strlen(rch) - 1; i >= 0; i--) {
        printf("%c", rch[i]);
      }
      printf("\n");
    } else if (op == '-') {
      int borr = 0, k = 0;
      for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; i--, j--, k++) {
        int d;

        if (j < 0) {
          d = (ach[i] - '0') - borr;
        } else {
          d = (ach[i] - '0') - (bch[j] - '0') - borr;
        }

        if (d >= 0) {
          rch[k] = d + '0';
          borr = 0;
        } else {
          rch[k] = d + 10 + '0';
          borr = 1;
        }
      }
      int start = 0;
      for (int i = strlen(rch) - 1; i >= 0; i--) {
        if (rch[i] == '0' && start == 0) {
          continue;
        } else {
          start = 1;
          printf("%c", rch[i]);
        }
      }
      printf("\n");

      for (int i = 0; i < LEN; i++) {
        ach[i] = bch[i] = rch[i] = 0;
      }
    } else if (op == '*') {

    } else if (op == '/') {

    }


  }
  return 0;
}

