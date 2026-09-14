#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main() {
  printf("sizeof(bool) = %lu\n\n", sizeof(bool));
  printf("sizeof(char) = %lu, max = %d, min = %d\n", sizeof(char), CHAR_MAX, CHAR_MIN);
  printf("sizeof(unsigned char) = %lu, max = %d\n\n", sizeof(unsigned char), UCHAR_MAX);

  printf("sizeof(short int) = %lu, max = %d, min = %d\n", sizeof(short int), SHRT_MAX, SHRT_MIN);
  printf("sizeof(unsigned short int) = %lu, max = %d\n\n", sizeof(short int), USHRT_MAX);

  printf("sizeof(int) = %lu, max = %d, min = %d\n", sizeof(int), INT_MAX, INT_MIN);
  printf("sizeof(unsigned int) = %lu, max = %u\n\n", sizeof(unsigned int), UINT_MAX);

  printf("sizeof(long) = %lu, max = %ld, min = %ld\n", sizeof(long), LONG_MAX, LONG_MIN);
  printf("sizeof(long long) = %lu, max = %lld, min = %lld\n\n", sizeof(long long), LLONG_MAX, LLONG_MIN);

  printf("sizeof(float) = %lu, max = %E, min = %E\n", sizeof(float), __FLT_MAX__, __FLT_MIN__);
  printf("sizeof(double) = %lu, max = %E, min = %E \n", sizeof(double), __DBL_MAX__, __DBL_MIN__);
  printf("sizeof(long double) = %lu, max = %LF, min = %LF\n", sizeof(long double), __LDBL_MAX__, __LDBL_MIN__);

  // sizeof 不实际执行表达式, 而只是分析类型, 因此无副作用
  int a = 0;
  printf("sizeof(a++) = %lu\n", sizeof(a++));
  printf("a = %d", a);
  return 0;
}