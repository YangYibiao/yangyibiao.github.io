#include <stdio.h>
#include <stdlib.h>

/* void *malloc(size_t _Size); */
/* void free(void *ptr); */

/*
int *array = (int *) malloc(len*sizeof(int))
int *array = malloc(len*sizeof(int))
int *array = malloc(len*sizeof(*array))
*/
int main()
{
  int size = 5;
  // int size = 2000000000000000;
  int *p = (int *)malloc(sizeof(int) * size); // 分配失败返回NULL
  if (!p) {
    printf("Allocation failed.\n");
    exit(1);
  }
  for (int i = 0; i < size; i++) {
    p[i] = i; // *(p + i) = i;
  }
  printf("Before free: %p\n", p);
  free(p);
  printf("After free: %p\n", p);
  printf("%d\n", *(p + 10000));
  p++;
  printf("After: %p\n", p);
  return 0;
}
