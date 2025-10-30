#include <stdio.h>

int main() {
  int m;
  scanf("%d", &m);

  double matrix[100][2] = {0};
  for (int i = 0; i < m; i++) {
    scanf("%lf%lf", &matrix[i][0], &matrix[i][1]);
  }

  double theta0 = 1.000, theta1 = 1.000, alpha = 0.01;
  int T = 2000;
  for (int i = 0; i < T; i++) {
    double J_theta0 = 0.0, J_theta1 = 0.0;
    for (int j = 0; j < m; j++) {
      double med = (theta0 + theta1 * matrix[j][0]) - matrix[j][1];
      J_theta0 += med;
      J_theta1 += med * matrix[j][0];
    }
    J_theta0 /= m;
    J_theta1 /= m;

    theta0 = theta0 - alpha * J_theta0;
    theta1 = theta1 - alpha * J_theta1;
//    printf("Loop %d: %lf %lf\n", i, theta0, theta1);
  }

  printf("y = %.3lf + %.3lfx", theta0, theta1);
  return 0;
}
