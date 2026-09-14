#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
  long int min = 0, max = UINT_MAX;
  long int med;
  char str[10];
  while (1) {
    med = (min + max) / 2;
    printf("%u\n", med);
    fflush(stdout);
    scanf("%s", str);
    if (str[0] == 'G') {
      max = med - 1;
    } else if (str[0] == 'L') {
      min = med + 1;
    } else if (str[0] == 'E'){
      return 0;
    } else {
      return 0;
    }
  }
  return 0;
}