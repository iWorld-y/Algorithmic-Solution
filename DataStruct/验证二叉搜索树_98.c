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
#define newStruct(structName, size) \
    (struct structName*)malloc(size * sizeof(struct structName))
#define elif else if
#define bool int
#define false 0
#define true 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool ansFun(struct TreeNode* root, ll lower, ll upper) {
    if (root == NULL) {
        return true;
    }
    if (root->val <= lower || root->val >= upper) {
        return false;
    }
    return ansFun(root->left, lower, root->val) &&
           ansFun(root->right, root->val, upper);
}

bool isValidBST(struct TreeNode* root) {
    return ansFun(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char* argv[]) {
    return 0;
}