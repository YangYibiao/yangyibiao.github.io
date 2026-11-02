/* Star tower: no functions */
#include <stdio.h>

int main(void)
{
  int lines, i, j;

  printf("Enter lines: ");
  scanf("%d", &lines);

  for (i = 0; i < lines; i++) {
    for (j = 0; j < lines - 1 - i; j++) {
      printf(" ");
    }
    for (j = 0; j < 2 * i + 1; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
