#include <stdio.h>

int main() {
  char rtype[20];
  int n;
  int cube[600][100];
  scanf("%s%d", rtype, &n);
  for (int i = 0; i < 6 * n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &cube[i][j]);
    }
  }

  if (rtype[0] == 'r') {
    int side;
    scanf("%d", &side);
    int rot_mat[100][100];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        rot_mat[i][j] = cube[n - 1 - j + n * side][i];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cube[n * side + i][j] = rot_mat[i][j];
      }
    }

    for (int i = 0; i < 6 * n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", cube[i][j]);
      }
      printf("\n");
    }
  } else {
    int mat[4][2];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        scanf("%d", &mat[i][j]);
      }
    }

    int rot_mat[4][100];
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < n; j++) {
        int k = n * mat[i][0] + mat[i][1];
        rot_mat[(i + 1) % 4][j] = cube[k][j];
      }
    }

//    for (int i = 0; i < 4; i++) {
//      for (int j = 0; j < n; j++) {
//        printf("%d ", rot_mat[i][j]);
//      }
//      printf("\n");
//    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < n; j++) {
        int k = n * mat[i][0] + mat[i][1];
        cube[k][j] = rot_mat[i][j];
      }
    }

    for (int i = 0; i < 6 * n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", cube[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
