#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func1(char **p, int len) {
  for (int i = 0; i < len; i++) {
    // 或者传递过来的直接是一个char**
    printf("%p: %s\n", *p, *p);
    p++;
  }
}

void func2(void *p, int len) {
  // 传递过来的是一个void*时
  // 需要转成正确的类型
  // ptr++才能正确指向下一个字符串
  char **ptr = (char**)p;
  for (int i = 0; i < len; i++) {
    printf("*ptr: %p\n", *ptr);
    printf("%s\n", *ptr);
    ptr++;
  }
}

int main(){
  char *sa[3];

  char str[10] = "hello";
  printf("%s\n", str);
  printf("%c\n", *str);

  // strcpy之前先malloc分配存储空间
  sa[0] = (char*)malloc(10);
  sa[1] = (char*)malloc(10);
  sa[2] = (char*)malloc(10);

  strcpy(sa[0], "hello");
  strcpy(sa[1], "world");
  strcpy(sa[2], "nju");

  printf("sa[0]: %p\n", sa[0]);
  printf("sa[1]: %p\n", sa[1]);
  printf("sa[2]: %p\n", sa[2]);

  func1(sa, 3);
  func2(sa, 3);

  free(sa[0]);
  free(sa[1]);
  free(sa[2]);
  return 0;
}