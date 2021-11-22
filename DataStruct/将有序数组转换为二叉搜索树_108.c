#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 0xffff
#define INF 0x7fffffff

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr))
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define newStruct(structName) \
    (struct structName*)malloc(sizeof(struct structName))
#define elif else if
#define bool int
#define false 0
#define true 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0)
        return NULL;

    struct TreeNode* root = newStruct(TreeNode);
    root->val = nums[numsSize / 2];
    root->left = sortedArrayToBST(nums, numsSize / 2);
    root->right = sortedArrayToBST(nums + numsSize / 2 + 1,
                                   numsSize / 2 - !(numsSize % 2));
    return root;
}

int main(int argc, char* argv[]) {
    return 0;
}