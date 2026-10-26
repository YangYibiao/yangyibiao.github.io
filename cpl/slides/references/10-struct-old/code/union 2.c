#include <stdio.h>

#define NAME_LEN 30

union U {
  char carr[4];
  int i;
};
int main() {
  union U u;
  u.carr[0] = 1, u.carr[1] = 1, u.carr[2] = 0, u.carr[3] = 0;
  printf("%d\n", u.i);

  u.i = 65793;

  printf("%d %d %d %d\n", u.carr[0], u.carr[1], u.carr[2], u.carr[3]);
  return 0;
}
