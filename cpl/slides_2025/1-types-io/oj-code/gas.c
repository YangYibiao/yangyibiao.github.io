#include <stdio.h>
#include <math.h>

int main() {
  double P, L, T;
  scanf("%lf%lf%lf", &P, &L, &T);

  const double R = 8.314;
  double V = pow(L, 3);

  printf("%1.4e", P * V / (R * T));
  return 0;
}