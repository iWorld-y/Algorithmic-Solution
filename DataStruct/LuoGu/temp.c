#include <stdio.h>
#include <stdlib.h>
long long cmp(const void *a, const void *b) {
    return *(long long *)b - *(long long *)a;
}
void printArr(int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d\t", nums[i]);
    }
    printf("\n");
}
long long maxKelements(int *nums, int numsSize, int k) {
    long long ans = 0;
    int p = 0;
    qsort(nums, numsSize, sizeof(long long), cmp);
    while (k--) {
        printArr(nums, numsSize);
        if (p + 1 < numsSize && nums[p] >= nums[p + 1]) {
            ans += nums[p];
            nums[p] = (nums[p] + 2) / 3;
        } else {
            ans += nums[++p];
            nums[p] = (nums[p] + 2) / 3;
        }
    }
    return ans;
}

int main() {
    int nums[] = {10, 10, 10, 10, 10};
    printf("%ld\n", maxKelements(nums, 5, 5));
    // int nums_1[] = {1, 10, 3, 3, 3};
    // printf("%ld\n", maxKelements(nums_1, 5, 3));
    return 0;
}