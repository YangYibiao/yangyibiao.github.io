#include <stdio.h>

int jojo[501] = {0};
int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  int curr = 0;
  int left = n;
  while (1) {
    if (left == 1) {
      break;
    }
    int indx = 0;
    while (1) {
      if (jojo[curr] == 0) {
        if (indx == 0) {
          indx = 1;
        } else {
          indx++;
        }
      }
      if (indx == k) {
        break;
      } else {
        curr = (curr + 1) % n;
      }
    }

//    printf("Kill: %d\n", curr);
    jojo[curr] = 1;
    left--;
  }

  for (int i = 0; i < n; i++) {
    if (jojo[i] == 0) {
      printf("%d", i + 1);
    }
  }
  return 0;
}