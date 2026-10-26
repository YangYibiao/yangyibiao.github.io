#include <stdio.h>

char ca[10000002];

int main() {
  int n;
  scanf("%d", &n);

  char ch;
  scanf("%c", &ch);
  for (int i = 0; i < n; i++) {
    scanf("%c", &ca[i]);
  }

  int k;
  scanf("%d", &k);
  for (int i = k - 1; i >= 0; i--) {
    printf("%c", ca[i]);
  }

  for (int i = n - 1; i >= k; i--) {
    printf("%c", ca[i]);
  }

  return 0;
}
