#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* void *malloc(size_t _Size); */
/* void free(void *ptr); */

/*
int *array = (int *) malloc(len*sizeof(int))
int *array = malloc(len*sizeof(int))
int *array = malloc(len*sizeof(*array))
*/

// 演示memory leak也就是分配但是未free
void malloc_memory_leak() {
  void *p = NULL;
  int cnt = 0;
  while ((p = malloc(100 * 1024 * 1024))) {
    cnt++;

    // 关键：实际使用分配的内存
    memset(p, 0, 100 * 1024 * 1024); // 写入数据，强制分配物理内存
    printf("Allocated %d00MB memory\n", cnt);
    sleep(1);
//    free(p);
  }
  printf("Can allocate at most %d00MB space.\n", cnt);
  sleep(20);
}

void malloc_use_after_free() {
  char *p = malloc(1024 * 1024 * sizeof(char));
  *p = 'a';
  memset(p, 'a', 1024 * 1024 * 1024);
  free(p);
//  p = NULL; // 如果未置为空，可能会不小心再次使用p来进行内存访问
  printf("use_after_free: %c", *p);
}

void malloc_out_of_index() {
  char *p = malloc(20 * sizeof(char));
  printf("out of index: %d\n", *(p + 30));
  free(p);
}

void malloc_free_p_plus_plus() {
  char *p = malloc(20 * sizeof(char));
  p++;
  printf("free after p++\n");
  free(p);
}

void malloc_free_array(char *p, int len) {
//  char p[200] = {0};
  memset(p, 'a', len);
  free(p);
}

void malloc_double_free() {
  char *p = malloc(1024 * 1024 * sizeof(char));
  *p = 'a';
  memset(p, 'a', 1024 * 1024 * 1024);
  free(p);
  free(p);
//  p = NULL; // 如果未置为空，可能会不小心再次使用p来进行内存访问
  printf("use_after_free: %c", *p);
}

int main() {
//  malloc_memory_leak();
//  malloc_use_after_free();
//  malloc_out_of_index();
//  malloc_double_free();
//  char p[2000] = {0};
//  malloc_free_array(p, 2000);
//  malloc_free_p_plus_plus();
  return 0;
}
