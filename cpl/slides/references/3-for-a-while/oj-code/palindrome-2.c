#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  char ch;
  scanf("%c", &ch);

  char s[100001];
  for (int i = 0; i < n; i++) {
    scanf("%c", &s[i]);
  }

  int r = 0;
  for (int i = 0, j = n - 1; i <= j; i++, j--) {
    if (s[i] == '?' && s[j] != '?') {
      s[i] = s[j];
    }
    if (s[i] != '?' && s[j] == '?') {
      s[j] = s[i];
    }
  }

  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      printf("%c", s[i]);
    } else {
      if (i < n / 2) { // 若在前面
        printf("%c%c", r / 10 + '0', r % 10 + '0');
        r++;
      } else {
        r--;
        printf("%c%c", r % 10 + '0', r / 10 + '0');
      }
    }
  }
  return 0;
}
