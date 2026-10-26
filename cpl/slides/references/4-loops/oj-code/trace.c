#include <stdio.h>

char matrix[50 + 2][50 + 2] = {0};
int is_visited[50 + 2][50 + 2] = {0};
int trace[2500][2] = {0};

int main() {
  int n, m, x0, y0;
  scanf("%d%d%d%d", &n, &m, &x0, &y0);

  for (int i = 0; i < 52; i++) {
    for (int j = 0; j < 52; j++) {
      matrix[i][j] = '_';
      is_visited[i][j] = 0;
    }
  }

  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%c", &matrix[i][j]);
    }
    getchar();
  }

  int x = x0, y = y0;
  trace[0][0] = x, trace[0][1] = y;
  is_visited[x][y] = 1;
  int len = 1;
  while (1) {
    int flag = 0;
    int nx, ny;
    if (matrix[x][y - 1] == '#' && is_visited[x][y - 1] == 0) {
      flag = 1;
      nx = x, ny = y - 1;
    } else if (matrix[x][y + 1] == '#' && is_visited[x][y + 1] == 0) {
      flag = 1;
      nx = x, ny = y + 1;
    } else if (matrix[x - 1][y] == '#' && is_visited[x - 1][y] == 0) {
      flag = 1;
      nx = x - 1, ny = y;
    } else if (matrix[x + 1][y] == '#' && is_visited[x + 1][y] == 0) {
      flag = 1;
      nx = x + 1, ny = y;
    }

    if (flag) {
      trace[len][0] = nx;
      trace[len][1] = ny;
      is_visited[nx][ny] = 1;
      len++;
      x = nx;
      y = ny;
    } else {
      break;
    }
  }

  printf("%d\n", len);
  for (int i = 0; i < len; i++) {
    printf("%d %d\n", trace[i][0], trace[i][1]);
  }
  return 0;
}
