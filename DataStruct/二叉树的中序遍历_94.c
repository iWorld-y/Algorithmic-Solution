#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 0xffff
#define INF 0x7fffffff

typedef long long ll;
typedef double lf;

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
// int*ans(struct TreeNode*root, int )
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL)
        return NULL;
    inorderTraversal(root, returnSize);
    // printf("%d")
}

int main(int argc, char* argv[]) {
    return 0;
}