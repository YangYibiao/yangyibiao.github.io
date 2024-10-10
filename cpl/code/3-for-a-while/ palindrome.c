#include <stdio.h>
#include <string.h>

#define LEN 21
char string[LEN] = "";

int main() {
  printf("Iuput a string containing at most 20 characters: ");
  scanf("%20s", string);

  int len = strlen(string);
  // int len = 0;
  // while (string[len] != '\0') {
  //   len++;
  // }

  int is_palindrome = 1;
  for (int i = 0, j = len - 1; i < j; i++, j--) {
    if (string[i] != string[j]) {
      is_palindrome = 0;
      break;
    }
  }

  // int i = 0;
  // int j = len - 1;
  // while (i < j) {
  //   if (string[i] != string[j]) {
  //     is_palindrome = 0;
  //     break;
  //   }
  //   i++;
  //   j--;
  // }

  if (is_palindrome) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}