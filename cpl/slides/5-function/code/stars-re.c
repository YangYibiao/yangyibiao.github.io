#include <stdio.h>

void print_line(int i, int lines) {
  for (int j = 0; j < lines - 1 - i; j++) {
    printf(" ");
  }
  // 2 * i + 1 '*'
  for (int j = 0; j < 2 * i + 1; j++) {
    printf("*");
  }
  if (i != lines - 1) {
    printf("\n");
  }
}

int main() {
  int lines = 0;
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++) {
    // NUm ' '
    print_line(i, lines);
  }

  return 0;
}