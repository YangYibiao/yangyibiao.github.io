#include <stdio.h>
#include <math.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  double x_vector[100];
  double t_vector[100];
  double y_vector[100];

  for (int i = 0; i < n; i++) {
    scanf("%lf", &x_vector[i]);
  }

  for (int i = 0; i < k; i++) {
    scanf("%lf", &t_vector[i]);
  }

  for (int j = 0; j < k; j++) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
      sum += exp(x_vector[i] / t_vector[j]);
    }

    for (int i = 0; i < n; i++) {
      y_vector[i] = exp(x_vector[i] / t_vector[j]) / sum;
      printf("%.3lf ", y_vector[i]);
    }

    double e_y = 0.0;
    for (int i = 0; i < n; i++) {
      e_y += y_vector[i];
    }
    e_y /= n;

    double v_y = 0.0;
    for (int i = 0; i < n; i++) {
      v_y += (y_vector[i] - e_y) * (y_vector[i] - e_y);
    }
    v_y /= n;
    printf("%.3lf ", v_y);
    printf("\n");
  }
  return 0;
}
