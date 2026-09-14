#include <stdio.h>

#define LEN 110

int main() {
  int n;
  scanf("%d", &n);

  char cmap[LEN][LEN];
  char nmap[LEN][LEN];
  int imap[LEN][LEN] = {0};

  // 初始化（外围一圈）
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      cmap[i][j] = 'o';
    }
  }

  // 读取用户输入，处理换行
  for (int i = 1; i <= n; i++) {
    getchar();
    for (int j = 1; j <= n; j++) {
      scanf("%c", &cmap[i][j]);
    }
  }

//  for (int i = 1; i <= n; i++) {
//    for (int j = 1; j <= n; j++) {
//      printf("%c", cmap[i][j]);
//    }
//    printf("\n");
//  }

  // map to imap
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      if (cmap[i][j] == '*') {
        imap[i][j] = 1;
      } else {
        imap[i][j] = 0;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cmap[i][j] == '*') {
        nmap[i][j] = '*';
      } else {
        for (int m = i - 1; m <= i + 1; m++) {
          for (int l = j - 1; l <= j + 1; l++) {
            if (m == i && l == j) continue;
            nmap[i][j] += imap[m][l];
          }
        }
        nmap[i][j] += '0';
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%c", nmap[i][j]);
    }
    printf("\n");
  }
  return 0;
}
