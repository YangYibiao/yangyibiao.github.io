#include <stdio.h>

int a[1000001];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  int p = a[k - 1];
  int l = 0, r = n - 1;
  while (1) {
    while (1) {
      if (l == r || a[l] >= p) { break; } // 找到第一个大于pivot的l
      l++;
    }

    while (1) {
      if (r == l || a[r] < p) { break; } // 找到第一小于pivot的r
      r--;
    }

    if (l == r) { break; } // 仅在l与r相遇时退出外层循环

//    printf("swap for l: %d (%d), r: %d (%d)\n", l, a[l], r, a[r]);

    // 交换两个元素
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
  }

//  printf("l: %d (%d), r: %d (%d)\n", l, a[l], r, a[r]);

  if (a[l] > p && l < k - 1) {
//    printf("(l: %d, r: %d) last swap l: %d (%d), p: %d (%d)\n", l, r, l, a[l], k - 1, a[k - 1]);
    int temp = a[l];
    a[l] = a[k - 1];
    a[k - 1] = temp;
  } else if (a[r] < p && r > k - 1) {
//    printf("(l: %d, r: %d) last swap r: %d (%d), p: %d (%d)\n", l, r, r, a[r], k - 1, a[k - 1]);
    int temp = a[r];
    a[r] = a[k - 1];
    a[k - 1] = temp;
  }

  int last_index;
  for (int i = 0; i < n; i++) {
    if (a[i] == p) {
      last_index = i;
    }
    printf("%d", a[i]);
    if (i != n - 1) {
      printf(" ");
    }
  }
  printf("\npivot index: %d\n", last_index);

  return 0;
}
