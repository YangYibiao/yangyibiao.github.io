#include <stdio.h>

int main() {
  int s[9][9] = {0};

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &s[i][j]);
    }
  }

  for (int i = 0; i < 9; i++) {
    int H[9] = {0}, L[9] = {0};
    for (int j = 0; j < 9; j++) {
      int h = s[i][j];
      int l = s[j][i];

      if (h > 9 || h < 1 || l > 9 || l < 1) {
        printf("NO");
        return 0;
      }

      H[h - 1]++;
      L[l - 1]++;
    }

    for (int j = 0; j < 9; j++) {
      if (H[j] != 1 || L[j] != 1) {
        printf("NO");
        return 0;
      }
    }
  }

  for (int m = 0; m < 3; m++) {
    for (int n = 0; n < 3; n++) {
      int O[9] = {0};
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int v = s[3 * m + i][3 * n + j];
          if (v > 9 || v < 1) {
            printf("NO");
            return 0;
          }
          O[v - 1]++;
        }
      }
      for (int i = 0; i < 9; i++) {
        if (O[i] != 1) {
          printf("NO");
          return 0;
        }
      }
    }
  }

  printf("YES");
  return 0;
}