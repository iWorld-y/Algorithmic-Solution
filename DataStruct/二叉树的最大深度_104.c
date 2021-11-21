#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 0xffff
#define INF 0x3f3f3f3f

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr))
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define newStruct(structName, size) \
    (structName*)malloc(size * sizeof(structName))
#define elif else if
#define bool int
#define false 0
#define true 1

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(struct TreeNode* root) {
    // return root == NULL ? 0
    //                     : fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
    if (root == NULL)
        return 0;
    return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main(int argc, char* argv[]) {
    return 0;
}