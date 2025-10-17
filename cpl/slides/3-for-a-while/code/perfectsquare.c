#include <stdio.h>

int main() {
  int max = 0;
  scanf("%d", &max);

  int sum = 0;
  int root = 1;
  for (int i = 1; i <= max; i++) {
    for (; root * root < i; root++);
//    printf("root is %d\n", root);
    if (root * root == i) {
//      printf("%d is a perfect square\n", i);
      continue;
    }

    sum += i;
  }
  printf("sum of non-perfect square is %d\n", sum);

}
