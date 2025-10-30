#include <stdio.h>

int main() {
  int a, b;
  char op[3];
//  int res;
  double res;
  while (scanf("%d %s %d", &a, op, &b) != EOF) {
    if (op[0] == '+') {
      res = a + b;
    } else if (op[0] == '-') {
      res = a - b;
    } else if (op[0] == '*') {
      if (op[1] == '*') {
        res = 1;
        for (int i = 1; i <= b; i++) {
          res *= a;
        }
      } else {
        res = a * b;
      }
    } else if (op[0] == '/') {
      if (op[1] == '*') {
        res = a * 1.0 / b;
      } else {
        res = a / b;
      }
    } else if (op[0] == '%') {
      res = a % b;
    }
    if (op[0] == '/' && op[1] == '*') {
      printf("%.3lf\n", res);
    } else {
      printf("%d\n", (int)res);
    }
  }


  return 0;
}
