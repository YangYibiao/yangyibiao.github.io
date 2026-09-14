#include <stdio.h>
#include <limits.h>

#define LEN 1000

int main(void) {
    int nums[LEN] = {0};
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int min = nums[0];
    for (int i = 0; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }


    printf("min of array is %d\n", min);
    return 0;
}
