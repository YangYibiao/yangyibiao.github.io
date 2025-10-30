#include <stdio.h>

#define LEN 500

int A[LEN][LEN] = {0};

int EX[LEN * LEN / 2] = {0};
int X1[LEN * LEN / 2] = {0};
int Y1[LEN * LEN / 2] = {0};
int X2[LEN * LEN / 2] = {0};
int Y2[LEN * LEN / 2] = {0};


int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k = A[i][j];
      if (EX[k] == 0) {
        X1[k] = i;
        Y1[k] = j;
        EX[k]++;
      } else {
        X2[k] = i;
        Y2[k] = j;
        EX[k]++;
      }
    }
  }

  for (int k = 1; k <= m * n / 2; k++) {
    // 找到值为k的两个位置
    int x1, y1, x2, y2;
    x1 = X1[k], y1 = Y1[k], x2 = X2[k], y2 = Y2[k];

//    printf("%d: (%d, %d) ~ (%d, %d)\n", k, x1, y1, x2, y2);

    int side1, side2;
    int flag = 0;
    // 确定是否可消除
    // 1. 上方是否都为空
    side1 = side2 = 1;
    for (int i = 0; i < x1; i++) {
      if (A[i][y1] > 0) {
        side1 = 0;
        break;
      }
    }
    for (int i = 0; i < x2; i++) {
      if (A[i][y2] > 0) {
        side2 = 0;
        break;
      }
    }
    if (side1 && side2) {
//      printf("up can remove\n");
      flag = 1;
    }

    // 2. 左边是否都为空
    side1 = side2 = 1;
    for (int i = 0; i < y1; i++) {
      if (A[x1][i] > 0) {
        side1 = 0;
        break;
      }
    }
    for (int i = 0; i < y2; i++) {
      if (A[x2][i] > 0) {
        side2 = 0;
        break;
      }
    }
    if (side1 && side2) {
//      printf("left can remove\n");
      flag = 1;
    }

    // 3. 右边是否都为空
    side1 = side2 = 1;
    for (int i = y1 + 1; i < m; i++) {
      if (A[x1][i] > 0) {
        side1 = 0;
        break;
      }
    }
    for (int i = y2 + 1; i < m; i++) {
      if (A[x2][i] > 0) {
        side2 = 0;
        break;
      }
    }
    if (side1 && side2) {
//      printf("right can remove\n");
      flag = 1;
    }

    // 4. 下边是否都为空
    side1 = side2 = 1;
    for (int i = x1 + 1; i < n; i++) {
      if (A[i][y1] > 0) {
        side1 = 0;
        break;
      }
    }
    for (int i = x2 + 1; i < n; i++) {
      if (A[i][y2] > 0) {
        side2 = 0;
        break;
      }
    }
    if (side1 && side2) {
//      printf("down can remove\n");
      flag = 1;
    }

    // 最后看是否可以消除
    if (flag) {
      printf("%d ", k);
      A[x1][y1] = A[x2][y2] = 0;
    }
  }

  return 0;
}