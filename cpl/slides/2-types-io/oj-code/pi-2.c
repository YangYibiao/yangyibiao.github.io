#include <stdio.h>
#include <math.h>

int main() {
  double pi = log(pow(5280, 3.0) *
                  pow(236674 + 30303 * sqrt(61), 3.0) + 744) / sqrt(427);
  double pi_4 = (6 * atan(1.0/8) + 2 * atan(1.0/57) + atan(1.0/239)) * 4.0;
  printf("%.15f\n%.15lf", pi, pi_4);
  return 0;
}
