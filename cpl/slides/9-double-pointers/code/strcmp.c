#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    s1++;
    s2++;
  }
  return *(unsigned char*)s1 - *(unsigned char*)s2;
}

int main() {
  char str1[20] = {'a', 'p', 'p', 'l', 'e', '\0', 'n', 'j', 'u', '\0'};
  char str2[20] = {'a', 'p', 'p', 'l', 'e', '\0'};

  printf("Compare(str1, str2) = %d\n", my_strcmp(str1, str2));

  printf("Compare(\"apple\", \"apple\") = %d\n", my_strcmp("apple", "apple"));
  printf("Compare(\"apple\", \"apples\") = %d\n", my_strcmp("apple", "apples"));
  printf("Compare(\"banana\", \"apple\") = %d\n", my_strcmp("banana", "apple"));
  return 0;
}
