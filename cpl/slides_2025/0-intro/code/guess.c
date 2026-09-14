#include <stdio.h> // 标准输入输出库文件/库函数
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));// 设置随机种子
    int rand_number = rand();
    printf("rand_number: %d\n", rand_number);
    int target = rand_number % 100 + 1; // 保证要猜的数一定在1 到 100之间。

    int i = 1;
    while (i <= 5) {
        int guess;
        printf("(The %dth try)Please guess a number between 1 to 100:", i);

        scanf("%d", &guess);
        if (guess == target) {
            printf("You win!\n");
            return 0;
        }

        if (guess > target) {
            printf("target is smaller than %d\n", guess);
        } else {
            printf("target is greater than %d\n", guess);
        }
        i = i + 1;
    }
    printf("You lose!");

    return 0;
}