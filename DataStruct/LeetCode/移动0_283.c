#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize) {
    for (int left = 0, right = 0; right < numsSize; right++) {
        if (nums[right] != 0) {
            swap(nums + left, nums + right);
            left++;
        }
    }
}

//void moveZeroes(int* nums, int numsSize) {
//    int stop = 0;
//    for (int i = 0; i < numsSize - 1; i++) {
//        if (nums[i] == 0 && stop != 1) {
//            for (int j = i + 1; j < numsSize; j++) {
//                if (nums[j] != 0) {
//                    swap(&nums[i], &nums[j]);
//                    if (j == numsSize - 1) {
//                        stop = 1;
//                    }
//                    break;
//                }
//            }
//
//            for (int i = 0; i < 5; i++) printf("%d ", nums[i]); printf("\n\n");
//        }
//    }
//}

int main() {
    int nums[] = { 0,1,0,3,12 };
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}