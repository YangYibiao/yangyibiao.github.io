#include <stdio.h>

int a[50005];
int main() {
  int T;
  scanf("%d", &T);

  for (int l = 1; l <= T; l++) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }

//    for (int i = 0; i < n; i++) {
//      for (int j = 0; j < n - i - 2; j++) { // not j < n - i - 1
//        if (a[j] > a[j + 1]) {
//          int tmp = a[j];
//          a[j] = a[j + 1];
//          a[j + 1] = tmp;
//        }
//      }
//    }

    int correct = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[n-1]) { // 只要最后一个数不是最大的，就不会正确的排序
        correct = 0;
        break;
      }
    }

//    for (int i = 0; i < n - 1; i++) {
//      if (a[i] > a[i+1]) {
//        correct = 0;
//        break;
//      }
//    }

    if (correct) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }

  return 0;
}
