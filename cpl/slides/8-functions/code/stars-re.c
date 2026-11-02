/* Star tower: with functions (one thing per function) */
#include <stdio.h>

void print_spaces(int n)
{
  int j;

  for (j = 0; j < n; j++) {
    printf(" ");
  }
}

void print_stars(int n)
{
  int j;

  for (j = 0; j < n; j++) {
    printf("*");
  }
}

int main(void)
{
  int lines, i;

  printf("Enter lines: ");
  scanf("%d", &lines);

  for (i = 0; i < lines; i++) {
    print_spaces(lines - 1 - i);
    print_stars(2 * i + 1);
    printf("\n");
  }
  return 0;
}
