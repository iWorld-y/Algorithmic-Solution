#include <stdio.h>

#define maxLen  10007
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void reverse(int* nums, int len) {
    for (int i = 0; i < len / 2; i++) {
        swap(&nums[i], &nums[len - i - 1]);
    }
}

void printNums(int* nums, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, numsSize);
    reverse(nums, k);
    reverse(nums + k, numsSize - k);
}

int main() {
    int arr[] = { 1,2,3,4,5,6,7 };
    int k = 3, len = sizeof(arr) / sizeof(arr[0]);
    rotate(&arr, len, k);
    for (int i = 0; i < len; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}