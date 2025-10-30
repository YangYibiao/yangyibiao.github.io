#include <stdio.h>

int main() {
  char bit[2001];

  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    bit[i] = '0';
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      if (bit[j] == '1') {
        bit[j] = '0';
      } else {
        bit[j] = '1';
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (bit[i] == '1') {
      printf("%d ", i);
    }
  }

  return 0;
}