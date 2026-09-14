/* 
* 计算班级平均数
* 输入：学生数n和n个学生的成绩
* 输出：平均分
*/
#include <stdio.h>

int main() {
  int n, i;
  float score, sum = 0.0, average;

  printf("Enter number of students: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    printf("Enter score for student %d: ", i);
    scanf("%f", &score);
    sum += score;
  }

  average = sum / n;
  printf("The average score is: %.2f\n", average);
  return 0;
}