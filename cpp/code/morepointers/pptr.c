#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1(void *p, int len) {
  // 传递过来的是一个void*时，需要转成正确的类型，ptr++才能正确指向下一个字符串
  char **ptr = (char**)p;
  for (int i = 0; i < len; i++) {
    printf("%s\n", *ptr);
    ptr++;
  }
}

void func2(char **p, int len) {
  for (int i = 0; i < len; i++) {
    printf("%s\n", *p);
    // 或者传递过来的直接是一个char**
    p++;
  }
}

int main(){
  char *mstr[4];

  // strcpy之前先malloc分配存储空间
  mstr[0] = malloc(sizeof(10));
  mstr[1] = malloc(sizeof(10));
  mstr[2] = malloc(sizeof(10));
  mstr[3] = malloc(sizeof(10));

  strcpy(mstr[0], "hello");
  strcpy(mstr[1], "world");
  strcpy(mstr[2], "nju");
  strcpy(mstr[3], "nihao");

  func1(mstr, 4);
  func2(mstr, 4);
  return 0;
}