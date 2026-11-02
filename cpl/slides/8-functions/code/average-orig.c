/* Three averages: no functions */
#include <stdio.h>

int main(void)
{
  double x = 3.5, y = 9.6, z = 10.2;

  printf("Average of %g and %g: %g\n", x, y, (x + y) / 2);
  printf("Average of %g and %g: %g\n", y, z, (y + z) / 2);
  printf("Average of %g and %g: %g\n", x, z, (x + z) / 2);
  return 0;
}
