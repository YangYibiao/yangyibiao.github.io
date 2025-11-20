#include <stdio.h>

int main() {
  int i = 1;
  int *p = &i;

  printf("%d\n", i); /* 打印 2 */
  printf("%d\n", *p); /* 打印 2 */

  *p = 2;

  printf("%d\n", i); /* 打印 2 */
  printf("%d\n", *p); /* 打印 2 */
  return 0;
}
