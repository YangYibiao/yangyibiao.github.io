#include <stdio.h>
#include <string.h>

void print(char num[], char res[]) {
  for (int i = 0; i < strlen(num); i++) {
    res[i] = num[i];
  }
}

int main() {
  int times;
  scanf("%d", &times);
  for (int i = 0; i < times; i++) {
    char num[20];
    scanf("%15s", num);
    int len = strlen(num);
    char res[20];
    print(num, res);
    printf("%s\n", res);
  }
  return 0;
}