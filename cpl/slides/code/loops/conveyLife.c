#include <stdio.h>

void printArr(int arr[][10], int len);

int iter(int arr[][10], int len);

int main() {
    int arr[100][10] = {0};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < 10; j++) {
            if (getchar() == '*') {
                arr[i][j] = 1;
            }
        }
    }

    printf("Before:\n");
    printArr(arr, n);

    iter(arr, n);

    printf("After:\n");
    printArr(arr, n);
    return 0;
}

int iter(int arr[][10], int len) {
    // TODO
    int flag = 0;
    int new[100][10] = {0};
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            int sum = 0;
            if (i - 1 >= 0) {
                if (j - 1 >= 0) {
                    sum += arr[i - 1][j - 1];
                }
                sum += arr[i - 1][j];
                if (j + 1 < 10) {
                    sum += arr[i - 1][j + 1];
                }
            }

            if (j - 1 >= 0) {
                sum += arr[i][j - 1];
            }
            if (j + 1 < 10) {
                sum += arr[i][j + 1];
            }

            if (i + 1 < 10) {
                if (j - 1 >= 0) {
                    sum += arr[i + 1][j - 1];
                }
                sum += arr[i + 1][j];
                if (j + 1 < 10) {
                    sum += arr[i + 1][j + 1];
                }
            }

            if (arr[i][j]) {
                if (sum < 2 || sum > 3) {
                    new[i][j] = 0;
                    flag = 1;
                } else {
                    new[i][j] = 1;
                }
            } else {
                if (sum == 3) {
                    new[i][j] = 1;
                    flag = 1;
                } else {
                    new[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = new[i][j];
        }
    }

    return flag;
}

void printArr(int arr[][10], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}