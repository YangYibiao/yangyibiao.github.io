#include <stdio.h>
#include <string.h>

int main() {
  char msg1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char msg2[] = "Hello";
  char msg3[4] = {'H', 'e', 'l', 'l'};
  char c = '\0';
  printf("msg3: %p\n", msg3);
  printf("msg2: %p\n", msg2);
  printf("c: %p\n", &c);
  char msg4[10] = "Hello";
  char msg5[10] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char msg6[10] = {'H', 'e', 'l', 'l', 'o', '\0', 'W', 'O', 'R', '\0'};
  printf("msg3: %d\n", strlen(msg3));
  printf("msg1: %d\n", sizeof (msg1) / sizeof(msg1[0]));
  printf("msg2: %d\n", sizeof (msg2) / sizeof(msg2[0]));
  printf("msg3: %d\n", sizeof (msg3) / sizeof(msg3[0]));
  printf("msg4: %d\n", sizeof (msg3) / sizeof(msg4[0]));
  printf("msg5: %d\n", sizeof (msg3) / sizeof(msg5[0]));
  printf("msg6: %d\n", sizeof (msg6) / sizeof(msg6[0]));

  char strArr[][5] = {
      {'H', 'e', 'l', 'l', 'o'},
      {'n', 'j', 'u', '!', '\0'},
      {'y', 'y', 'y', 'y', 'y'}
  };

  printf("str[0]: %s\n", strArr[0]);
  printf("str[1]: %s\n", strArr[1]);
  printf("str[2]: %s\n", strArr[2]);
}