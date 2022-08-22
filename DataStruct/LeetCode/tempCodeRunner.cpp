#include <iostream>
#include <queue>
#include "tree.h"

using namespace std;
const int maxSize = 100;

int Btdepth(TreeNode *root) {
    if (!root)
        return 0;
    TreeNode *q[maxSize];
    int front = 0, rear = 0, level = 0;
    q[rear++] = root;
    while (front < rear) {
        // 存储当前层次的区间
        int size = rear - front;
        // 若当前层次没有遍历完全则继续
        while (size > 0) {
            TreeNode *node = q[front++];
            if (node->left)
                q[rear++] = node->left;
            if (node->right)
                q[rear++] = node->right;
            size--;
        }
        level++;
    }
    return level;
}
//int Btdepth(TreeNode *root) {
//    if (root == nullptr) return 0;
//    queue<TreeNode *> Q;
//    Q.push(root);
//    int ans = 0;
//    while (!Q.empty()) {
//        int sz = Q.size();
//        while (sz > 0) {
//            TreeNode *node = Q.front();
//            Q.pop();
//            if (node->left) Q.push(node->left);
//            if (node->right) Q.push(node->right);
//            sz -= 1;
//        }
//        ans += 1;
//    }
//    return ans;
//}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    cout << Btdepth(root);
    return 0;
}