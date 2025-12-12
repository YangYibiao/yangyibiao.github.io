#include <stdio.h>

#define NAME_LEN 30

struct Point {
  int x;
  int y;
}; // 分号必须跟在右大括号后面

int main() {
  // 标记可用于声明变量:
  struct Point p1, p2; // struct关键字不能省略
  //Point part3, part4;   // WRONG！！！因为part不是类型名
  p1.x = 1, p1.y = 2;
  printf("Point(%d, %d)\n", p1.x, p2.y);
  return 0;
}
