#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void *a, const void *b) {
  // a 和 b 是 char* 的地址 → type: char**
  return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
  const char *words[] = {"banana", "apple", "orange", "kiwi"};
  int n = sizeof(words)/sizeof(words[0]);

  qsort(words, n, sizeof(char*), cmp_str);

  for (int i = 0; i < n; i++) {
    printf("%s\n", words[i]);
  }
}
