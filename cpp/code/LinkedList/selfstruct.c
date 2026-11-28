#include <stdio.h>

//struct SELF {
//  int a;
//  struct SELF b;
//  float c;
//};

// struct SELF {
//   int a;
//   struct SELF b; // error: field ‘b’ recursively requires itself to be defined
//   float c;
// };

struct SELF {
 int a;
 struct SELF * b;
 float c;
};

// typedef struct {
//  int a;
//  SELF * b; // error: SELF undeclared (first use in this function)
//  float c;
// } SELF;

typedef struct SELF_TAG {
 int a;
 struct SELF_TAG *b;
 float c;
} SELF;

int main() {
  SELF s;
  s.a = 10;
  s.b = NULL;
  s.c = 3.14;
  printf("s.a = %d\n", s.a);
  printf("s.b = %p\n", s.b);
  printf("s.c = %f\n", s.c);
  return 0;
}