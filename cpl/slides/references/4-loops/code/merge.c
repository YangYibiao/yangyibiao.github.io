#include <stdio.h>

#define LEN_L 5
#define LEN_R 6
int L[LEN_L] = {1, 2, 5, 7, 9};
int R[LEN_R] = {0, 2, 4, 6, 8, 10};
int N[LEN_L + LEN_R];

int main(void) {
  // TODO: merge L and R into a sorted array
  int l = 0, r = 0, k = 0;
  while (l < LEN_L && r < LEN_R) {
    if (L[l] <= R[r]) {
      N[k++] = L[l++]; // N[k] = L[l]; k++, l++;
    } else {
      N[k++] = R[r++];
    }
  }

  while (r < LEN_R) {
    N[k++] = R[r++];
  }
  while (l < LEN_L) {
    N[k++] = L[l++];
  }

  for (int i = 0; i < LEN_L + LEN_R; i++) {
    printf("%d ", N[i]);
  }
  return 0;
}