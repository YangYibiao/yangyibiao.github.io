#include <stdio.h>
#include <string.h>

#define LEN 1000

char str_org[LEN + 6] = {0};
char str_new[LEN + 6] = {0};

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < LEN + 6; i++) {
    str_org[i] = str_new[i] = '.';
  }

  char str[1001];
  scanf("%s", str);

  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    str_org[3 + i] = str[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 3; j < len + 3; j++) {
      int neighbor_A = 0; // A的个数
      int neighbor_B = 0; // B的个数
      for (int k = j - 3; k <= j + 3; k++) {
        if (k == j) continue;
        if (str_org[k] == 'A') neighbor_A++;
        if (str_org[k] == 'B') neighbor_B++;
      }
      if (str_org[j] == '.') {
        if (neighbor_A >= 2 && neighbor_A <= 4 && neighbor_B == 0) {
          str_new[j] = 'A';
        }
        if (neighbor_B >= 2 && neighbor_B <= 4 && neighbor_A == 0) {
          str_new[j] = 'B';
        }
      } else {
        if (neighbor_A >= 1 && str_org[j] == 'B') {
          str_new[j] = '.';
        } else if (neighbor_B >= 1 && str_org[j] == 'A') {
          str_new[j] = '.';
        } else if ((neighbor_A >= 5 && str_org[j] == 'A')
            || (neighbor_B >= 5 && str_org[j] == 'B')
            || (neighbor_A <= 1 && str_org[j] == 'A')
            || (neighbor_B <= 1 && str_org[j] == 'B')) {
          str_new[j] = '.';
        } else {
          str_new[j] = str_org[j];
        }
      }
    }

    for (int j = 0; j < len; j++) {
      str_org[j + 3] = str_new[j + 3];
    }

//    printf("\nLoop: %d   ", i);
//    for (int j = 0; j < len; j++) {
//      printf("%c", str_org[j + 3]);
//    }
//    printf("\n");
  }

  for (int i = 0; i < len; i++) {
    printf("%c", str_org[i + 3]);
  }

  return 0;
}
