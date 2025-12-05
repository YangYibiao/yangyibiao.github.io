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
    // 或者传递过来的直接是一个char**
    printf("%p: %s\n", *p, *p);
    p++;
  }
}

int main(){
  char *str_arr[3];

  // strcpy之前先malloc分配存储空间
  str_arr[0] = (char*)malloc(10*sizeof(char));
  str_arr[1] = (char*)malloc(10*sizeof(char));
  str_arr[2] = (char*)malloc(10*sizeof(char));

  strcpy(str_arr[0], "hello");
  strcpy(str_arr[1], "world");
  strcpy(str_arr[2], "nju");

  for (int i = 0; i < 3; i++) {
    printf("%p\n", str_arr[i]);
  }

  func1(str_arr, 3);
  func2(str_arr, 3);

  free(str_arr[0]);
  free(str_arr[1]);
  free(str_arr[2]);
  return 0;
}