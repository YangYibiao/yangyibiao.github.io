#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c;
  a = 1.1f;
  b = 2.2f;
  c = a + b;
  printf("%.10f\n", c);
  printf("%.10f\n", 3.3f);
  if (c == 3.3f) {
    // if(fabs(c - 3.3f)<1e-5){//no guarantee
    //c == m, |c-m|<eplison
    printf("yes!\n");
  } else {
    printf("no!\n");
  }
  return 0;
}