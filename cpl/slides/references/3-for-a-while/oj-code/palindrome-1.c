#include <stdio.h>

char s[2001];

int main() {
  int n;
  scanf("%d", &n);

  char ch;
  scanf("%c", &ch);
  for (int i = 0; i < n; i++) {
    scanf("%c", &s[i]);
  }

  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] == '?') {
      s[i] = s[j];
    }
    if (s[j] == '?') {
      s[j] = s[i];
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%c", s[i]);
  }

  return 0;
}
