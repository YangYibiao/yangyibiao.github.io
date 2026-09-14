#include <stdio.h>

int main() {
  int W;
  scanf("%d", &W);

  getchar();
  char str_a[51] = {0}, str_b[51] = {0}, str_c[51]= {0};
  scanf("%[^,],%[^,],%[^\n]", str_a, str_b, str_c);

  printf("| %-8s | %-*.*s |\n", "ID", W, W, str_a);
  printf("| %-8s | %-*.*s |\n", "Username", W, W, str_b);
  printf("| %-8s | %-*.*s |\n", "Email", W, W, str_c);
  return 0;
}
