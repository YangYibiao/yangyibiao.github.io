#include <stdio.h>
#include <string.h>

int main() {
  int len, N;
  scanf("%d%d", &len, &N);

  char ch_N[31];
  scanf("%s", ch_N);

  int s = 0;
  int p = 1;
  int v = 1;
  for (int i = len - 1; i >= 0; i--) {
    int k = -1;
    if (ch_N[i] >= '0' && ch_N[i] <= '9') {
      k = ch_N[i] - '0';
    } else if (ch_N[i] <= 'F' && ch_N[i] >= 'A') {
      k = ch_N[i] - 'A' + 10;
    } else {
      v = 0;
      break;
    }

    if (k >= N) {
      v = 0;
      break;
    }
    s += p * k;
    p *= N;
  }

  if (v == 1) {
    printf("%d", s);
  } else {
    printf("Error");
  }
  return 0;
}
