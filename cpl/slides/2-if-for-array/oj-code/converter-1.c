#include <stdio.h>

static char *ones [] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens [] = {
    "0", "1", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
  int i;
  scanf("%d", &i);

  int b = i / 100;       // 百位
  int s = i % 100 / 10;  // 十位
  int g = i % 10;        // 个位

  if (i == 0) {
    printf("zero");
    return 0;
  }
  if (b >= 1) {
    printf("%s hundred", ones[b]);
    if (s > 0 || g > 0) {
      printf(" and ");
    }
  }

  if (s >= 2) {
    printf("%s", tens[s]);
    if (g > 0) {
      printf("-%s", ones[g]);
    }
  } else {
    if (s > 0 || g > 0) {
      printf("%s", ones[i - b * 100]);
    }
  }
  return 0;
}
