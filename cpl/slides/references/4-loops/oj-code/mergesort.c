#include <stdio.h>

// 归并排序的合并操作
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    int L[n1], R[n2];

    // 将数据复制到临时数组 L[] 和 R[] 中
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 归并临时数组到 arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序的非递归版本
void mergeSort(int arr[], int size) {
    int curr_size;  // 当前子数组的大小
    int left_start; // 子数组的起始索引

    // 从小到大合并子数组
    for (curr_size = 1; curr_size <= size - 1; curr_size = 2 * curr_size) {
        // 合并 arr[left_start...left_start+curr_size-1] 和 arr[left_start+curr_size...left_start+2*curr_size-1]
        for (left_start = 0; left_start < size - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = left_start + 2 * curr_size - 1;

            // 防止越界
            if (right_end > size - 1) {
                right_end = size - 1;
            }

            // 合并子数组
            merge(arr, left_start, mid, right_end);
        }
    }
}

// 打印数组
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 测试
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("排序后的数组：\n");
    printArray(arr, size);

    return 0;
}