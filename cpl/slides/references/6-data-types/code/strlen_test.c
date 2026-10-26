#include <stdio.h>
#include <string.h>

int main() {
  char name1[] = "NJ";
  char name2[] = "NJU";
  printf("%lu\n", strlen(name1) - strlen(name2));
  //  if (strlen(name1) < strlen(name2)) {
  if (strlen(name1) - strlen(name2) < 0) {
    printf("true");
  } else {
    printf("false");
  }

  return 0;
}