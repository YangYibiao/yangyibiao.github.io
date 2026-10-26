#include <stdio.h>
#include <math.h>

// 提醒：这道题给的点都是坐标，而不是数组下标

int main() {
  int xa, ya, xb, yb, xc, yc;
  scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);

  int y_step = yb > ya ? yb - ya : ya - yb;
  int x_step = xb > xa ? xb - xa : xa - xb;
  char y_side = yb > ya ? 'U' : 'D';
  char x_side = xb > xa ? 'R' : 'L';

  if (xa == xb && xc == xa) { // AB一条竖线
    if ((yc > ya && yc < yb) || (yc < ya && yc > yb)) { // C在AB之间
      printf("%d", y_step + 2);
      printf("L");
      for (int i = 0; i < y_step; i++) {
        printf("%c", y_side);
      }
      printf("R");
    } else {
      printf("%d", y_step);
      for (int i = 0; i < y_step; i++) {
        printf("%c", y_side);
      }
    }
  } else if (ya == yb && yc == ya) { // AB一条直线
    if ((xc > xa && xc < xb && xa < xb) || (xc > xb && xc < xa && xa > xb)) { // C在AB之间
      printf("%d\n", x_step + 2);
      printf("U");
      for (int i = 0; i < x_step; i++) {
        printf("%c", x_side);
      }
      printf("D");
    } else {
      printf("%d\n", x_step);
      for (int i = 0; i < x_step; i++) {
        printf("%c", x_side);
      }
    }
  } else if (xc == xa || yc == yb) { // 与a点在相同横线上或者与b点相同竖线上
    printf("%d\n", x_step + y_step);
    for (int i = 0; i < x_step; i++) { // 先左右
      printf("%c", x_side);
    }
    for (int i = 0; i < y_step; i++) { // 再上下
      printf("%c", y_side);
    }
  } else { // if (xc == xb || yc == ya) { // 与b点在相同横线上或者与a点相同竖线上
    printf("%d\n", x_step + y_step);
    for (int i = 0; i < y_step; i++) { // 先上下
      printf("%c", y_side);
    }
    for (int i = 0; i < x_step; i++) { // 再左右
      printf("%c", x_side);
    }
  }

  return 0;
}
