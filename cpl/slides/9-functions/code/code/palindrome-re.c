#include <stdio.h>

#define LEN 21

// get length of a string
int get_strlen(char cstr[]) {
  int len = -1;
  while (cstr[++len] != '\0');
  return len;
}

int main() {
  char str[21] = "";
  scanf("%s", str);

  int len = get_strlen(str);
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
