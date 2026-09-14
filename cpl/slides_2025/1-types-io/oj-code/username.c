#include <stdio.h>
#include <string.h>

int main() {
  char str[101];
  scanf("%[^\n]", str);
  printf("%d\n", strlen(str));
  printf("\"%.20s\"", str);
  return 0;
}
