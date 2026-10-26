#include <stdio.h>

int magic[1000][1000] = {0};

int main() {
  int n;
  scanf("%d", &n);

  int ipos = 0, jpos = (n + 1) / 2 - 1;
  magic[ipos][jpos] = 1;
  for (int i = 2; i <= n * n; i++) {
    int ipos_new = ipos - 1;
    int jpos_new = jpos + 1;

    if (ipos_new < 0) {
      ipos_new += n;
    }
    if (jpos_new >= n) { // 右上方格出界
      jpos_new -= n;
    }
    if (magic[ipos_new][jpos_new] != 0) {
      ipos_new = ipos + 1;
      jpos_new = jpos;
    }
//    printf("(%d, %d): %d\n", ipos_new, jpos_new, i);
    magic[ipos_new][jpos_new] = i;
    ipos = ipos_new;
    jpos = jpos_new;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", magic[i][j]);
    }
    printf("\n");
  }
  return 0;
}