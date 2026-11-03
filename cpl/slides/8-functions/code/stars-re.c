#include <stdio.h>

void print_nchars(int n, char c) {
  for (int j = 0; j < n; j++) {
    printf("%c", c);
  }
}

int main() {
  int lines = 0;
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++) {
    print_nchars(lines - 1 - i, ' ');
    print_nchars(2 * i + 1, '#');
    if (i != lines - 1) {
      printf("\n");
    }
  }

  return 0;
}
