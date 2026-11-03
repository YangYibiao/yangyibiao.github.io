/* 成绩统计: 函数版 (二维数组进, 一维数组出) */
#include <stdio.h>

void row_sums(int scores[][3], int n, int sums[])
{
  for (int i = 0; i < n; i++) {
    sums[i] = 0;
    for (int j = 0; j < 3; j++) {
      sums[i] += scores[i][j];
    }
  }
}

int main(void)
{
  int scores[5][3] = {{80, 85, 90}, {70, 75, 80}, {90, 92, 88},
                      {60, 65, 70}, {85, 80, 90}};
  int totals[5];

  row_sums(scores, 5, totals);
  for (int i = 0; i < 5; i++) {
    printf("student %d total: %d\n", i + 1, totals[i]);
  }
  return 0;
}
