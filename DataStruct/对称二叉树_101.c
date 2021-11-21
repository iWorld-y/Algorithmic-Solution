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

bool check(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    else if (p == NULL || q == NULL)
        return false;
    return p->val == q->val && check(p->left, q->right) &&
           check(p->right, q->left);
}

// bool check(struct TreeNode* p, struct TreeNode* q) {
//     if (p == NULL && q == NULL) {
//         return true;
//     }
//     if (p == NULL || q == NULL) {
//         return false;
//     }
//     return p->val == q->val && check(p->left, q->right) &&
//            check(p->right, q->left);
// }

bool isSymmetric(struct TreeNode* root) {
    check(root, root);
}

int main(int argc, char* argv[]) {
    return 0;
}