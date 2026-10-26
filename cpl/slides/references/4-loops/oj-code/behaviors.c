#include <stdio.h>


int main() {
  int n;
  scanf("%d", &n);

  int ANS[19] = {-1, 0, 0, 3, 0, 5, // 5 unclear
                 0, 0, 0, 0, 0, 0,
                 0, 0, 14, 15, 16, 0, 18};

  int r_wa, r_wo, r_wx;
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);

    if (i == 1) {
      r_wa = r_wo = r_wx = ANS[t];
    } else {
      r_wa &= ANS[t];
      r_wo |= ANS[t];
      r_wx ^= ANS[t];
    }
  }

  printf("%d %d %d", r_wa, r_wo, r_wx);
  return 0;
}
