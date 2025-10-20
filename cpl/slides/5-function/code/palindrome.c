#include <stdio.h>

#define LEN 21
char str[21] = "";
int main() {
  scanf("%20s", str);

  int len = 0;
  for (int i = 0; i < 21; i++) {
    if (str[i] == '\0') {
      break;
    }
    len++;
  }
  printf("len of the string: %d\n", len);

  int flag = 1;
  for (int l = 0, r = len - 1; l <= r; l++, r--) {
    if (str[l] != str[r]) {
      flag = 0;
      break;
    }
  }

  if (flag == 1) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }
  return 0;
}
