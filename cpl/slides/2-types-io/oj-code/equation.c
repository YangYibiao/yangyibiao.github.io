#include <stdio.h>
#include <math.h>

int main() {
  int p,q;
  scanf("%d %d",&p,&q);
  double delta=pow(q/2.0,2)+pow(p/3.0,3);
  double x1,a;
  a=sqrt(delta);
  double A=cbrt(-q/2.0+a);
  double B=cbrt(-q/2.0-a);
  x1=A+B;
  printf("%.3f",x1);
  return 0;
}