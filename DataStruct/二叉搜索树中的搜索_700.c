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
/*
 * 二叉搜索树满足如下性质：
    - 左子树所有节点的元素值均小于根的元素值；
    - 右子树所有节点的元素值均大于根的元素值。
*/
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL)
        return NULL;
    if (root->val == val) {
        return root;
    }
    return searchBST(root->val > val ? root->left : root->right, val);
}

int main(int argc, char* argv[]) {
    return 0;
}