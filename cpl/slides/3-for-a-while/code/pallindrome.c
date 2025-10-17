#include <stdio.h>

#define LEN 21
char str[21] = "";
int main() {
  scanf("%20s", str);

  int len = 0;
  for (int i = 0; i < 21; i++) {
    if (str[i] == '\0') {
      len = i;
      break;
    }
  }
  printf("%d\n", len);
  int flag = 1;
  for (int i = 0, j = len - 1; i <= j; i++, j--) {
    if (str[i] != str[j]) {
      flag = 0;
      break;
    }
  }
  if (flag == 1) {
    printf("%s is a pallindrome\n", str);
  } else {
    printf("%s is not\n", str);
  }
  return 0;
}
