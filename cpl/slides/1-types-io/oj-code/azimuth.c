#include <stdio.h>
#include <math.h>

int main() {
  int xa, ya, xb, yb;
  scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

  double dx = xb - xa;
  double dy = yb - ya;
  double distance = hypot(dx, dy); // 距离

  double PI = acos(-1);
  double angle = fmod(atan2(dx, dy + !distance) * 180 / PI + 360, 360); // 角度
  printf("%.4lf %.4lf", distance, angle);
  return 0;
}