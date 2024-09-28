#include <stdio.h>

int i;

void print_one_row(void)
{
  for (i = 1; i <= 10; i++)
    printf("*");
}
 
void print_all_rows(void)
{
  for (i = 1; i <= 10; i++) {
    print_one_row();
    printf("\n");
  }
}

int main(void)
{
  print_all_rows();
  return 0;
}