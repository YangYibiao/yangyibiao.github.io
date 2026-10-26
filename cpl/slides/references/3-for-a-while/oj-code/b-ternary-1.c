#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    char zch[16];
    scanf("%s", zch);

    int len = strlen(zch);
    int s = 0;
    int v = 1;
    for (int j = 0; j < len; j++) {
      int cur = pow(3, len - 1 - j);
      if (zch[j] != '1' && zch[j] != 'Z' && zch[j] != '0') {
        v = 0;
        break;
      }
      if (zch[j] == '1') {
        s += cur;
      } else if (zch[j] == 'Z') {
        s -= cur;
      }
    }

    if (v == 1) {
      printf("%d\n", s);
    } else {
      printf("Radix Error\n");
    }
  }
  return 0;
}
