#include <stdio.h>

#define LEN (500 + 1)

// 存放矩阵（第0行和第0列为空
int A[LEN][LEN] = {0};
// 记录数值为k的两个点在矩阵中的位置(x1, y1) (x2, y2)
int X1[LEN * LEN / 2] = {0}; // 存储k的第一个点的行号
int Y1[LEN * LEN / 2] = {0}; // 存储k的第一个点的列号
int X2[LEN * LEN / 2] = {0}; // 存储k的第二个点的行号
int Y2[LEN * LEN / 2] = {0}; // 存储k的第二个点的列号

void initialize_Pos(int n, int m);
int is_Left_Empty(int x, int y, int n, int m);
int is_Right_Empty(int x, int y, int n, int m);
int is_Up_Empty(int x, int y, int n, int m);
int is_Down_Empty(int x, int y, int n, int m);

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  initialize_Pos(n, m);

  for (int k = 1; k <= m * n / 2; k++) {
    // 找到值为k的两个位置
    int x1 = X1[k], y1 = Y1[k];
    int x2 = X2[k], y2 = Y2[k];

    printf("Line: 80 %d: (%d, %d), (%d, %d)\n", k, x1, y1, x2, y2);

    if (is_Left_Empty(x1, y1, n, m) && is_Left_Empty(x2, y2, n, m)) {
      printf("%d ", k);
      A[x1][y1] = A[x2][y2] = 0;
      continue;
    }

    if (is_Right_Empty(x1, y1, n, m) && is_Right_Empty(x2, y2, n, m)) {
      printf("%d ", k);
      A[x1][y1] = A[x2][y2] = 0;
      continue;
    }

    if (is_Up_Empty(x1, y1, n, m) && is_Up_Empty(x2, y2, n, m)) {
      printf("%d ", k);
      A[x1][y1] = A[x2][y2] = 0;
      continue;
    }

    if (is_Down_Empty(x1, y1, n, m) && is_Down_Empty(x2, y2, n, m)) {
      printf("%d ", k);
      A[x1][y1] = A[x2][y2] = 0;
      continue;
    }
  }

  return 0;
}

int is_Left_Empty(int x, int y, int n, int m) {
  for (int i = 1; i < y; i++) {
    if (A[x][i] > 0)
      return 0;
  }
  return 1;
}

int is_Right_Empty(int x, int y, int n, int m) {
  for (int i = y + 1; i <= m; i++) {
    if (A[x][i] > 0) {
      return 0;
    }
  }
  return 1;
}

int is_Up_Empty(int x, int y, int n, int m) {
  for (int i = 1; i < x; i++) {
    if (A[i][y] > 0) {
      return 0;
    }
  }
  return 1;
}

int is_Down_Empty(int x, int y, int n, int m) {
  for (int i = x + 1; i <= n; i++) {
    if (A[i][y] > 0) {
      return 0;
    }
  }
  return 1;
}

void initialize_Pos(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int k = A[i][j]; // 当前的数值为k
      if (X1[k] == 0) {
        // 数值为k的第一个点横纵坐标存放在(k, 0, 0) (k, 0, 1)
        X1[k] = i;
        Y1[k] = j; // Assume buggy code: Pos[k][0][0] = i;
      } else {
        // 数值为k的第二个点横纵坐标存放在(k, 1, 0) (k, 1, 1)
        X2[k] = i;
        Y2[k] = j;
      }
    }
  }
}

