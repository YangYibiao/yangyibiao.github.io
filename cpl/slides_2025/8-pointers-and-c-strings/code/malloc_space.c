#include <stdio.h>
#include <stdlib.h>

/*
 * Example code for malloc out of memory
 * How many MB space can be allocated? 
*/
int main(void) {
  void *p = NULL;
  int cnt = 0;
  while ((p = malloc(100 * 1024 * 1024))) {
    cnt++;
  }
  printf("Can allocate at most %d00MB space.\n", cnt);

  // p = malloc(100*1024*1024);
  // p++;
  free(p);
  return 0;
}