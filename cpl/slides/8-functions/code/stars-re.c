/* Star tower: no functions */
#include <stdio.h>

void print_stars(int n) {
  for (int j = 0; j < n; j++) {
    printf("*");
  }
}

void print_space(int n) {
  for (int j = 0; j < n; j++) {
    printf(" ");
  }
}

int main(void)
{
  int lines, i, j;

  printf("Enter lines: ");
  scanf("%d", &lines);

  for (i = 0; i < lines; i++) {
    print_space(lines - 1 - i);
    print_stars(2 * i + 1);
    printf("\n");
  }
  return 0;
}
