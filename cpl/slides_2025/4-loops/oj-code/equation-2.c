#include <stdio.h>

#define N 3

double cal_delta(double orig[][4], double mat[][3], int k) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      mat[i][j] = orig[i][j];
    }
  }

  if (k > 0) {
    mat[0][k - 1] = orig[0][3];
    mat[1][k - 1] = orig[1][3];
    mat[2][k - 1] = orig[2][3];
  }

//  for (int i = 0; i < N; i++) {
//    for (int j = 0; j < N; j++) {
//      printf("%lf ", mat[i][j]);
//    }
//    printf("\n");
//  }

  return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
         mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) +
         mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
}

int main() {
  double equation_matrix[N][N + 1] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N + 1; j++) {
      scanf("%lf", &equation_matrix[i][j]);
    }
  }

  double determinant_mat[N][N] = {0};

  double deltao = cal_delta(equation_matrix, determinant_mat, 0);
  double deltax = cal_delta(equation_matrix, determinant_mat, 1);
  double deltay = cal_delta(equation_matrix, determinant_mat, 2);
  double deltaz = cal_delta(equation_matrix, determinant_mat, 3);

  double x = deltax / deltao;
  double y = deltay / deltao;
  double z = deltaz / deltao;

//  printf("%lf %lf %lf %lf\n", deltao, deltax, deltay, deltaz);

  printf("%.2lf %.2lf %.2lf\n", x, y, z);

  return 0;
}
