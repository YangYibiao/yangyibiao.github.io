#include <stdio.h>

int main() {
  int lower[26] = {0};
  int upper[26] = {0};

  int n;
  scanf("%d", &n);

  getchar();
  for (int i = 0; i < n; i++) {
    char ch;
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
      lower[ch - 'a']++;
    }
    if (ch >= 'A' && ch <= 'Z') {
      upper[ch - 'A']++;
    }
  }

  int max = -1;
  for (int i = 0; i < 26; i++) {
    if (lower[i] > max) {
      max = lower[i];
    }
    if (upper[i] > max) {
      max = upper[i];
    }
  }

  for (int j = max; j >= 1; j--) {
    int begin = 0;
    for (int i = 0; i < 26; i++) {
      if (lower[i] > 0 || upper[i] > 0) {
        if (begin) {
          printf(" ");
        }
        begin = 1;
      }
      if (lower[i] >= j) {
        printf("=");
      } else {
        if (lower[i] > 0) {
          printf(" ");
        }
      }
      if (upper[i] >= j) {
        printf("=");
      } else {
        if (upper[i] > 0) {
          printf(" ");
        }
      }
    }
    printf("\n");
  }

  int begin = 0;
  for (int i = 0; i < 26; i++) {
    if (lower[i] > 0 || upper[i] > 0) {
      if (begin == 1) {
        printf("-");
      }
      begin = 1;
    }
    if (lower[i] > 0) {
      printf("-");
    }
    if (upper[i] > 0) {
      printf("-");
    }
  }
  printf("\n");

  begin = 0;
  for (int i = 0; i < 26; i++) {
    if (lower[i] > 0 || upper[i] > 0) {
      if (begin) {
        printf(" ");
      }
      begin = 1;
    }
    if (lower[i] > 0) {
      printf("%c", i + 'a');
    }
    if (upper[i] > 0) {
      printf("%c", i + 'A');
    }

  }
  return 0;
}
