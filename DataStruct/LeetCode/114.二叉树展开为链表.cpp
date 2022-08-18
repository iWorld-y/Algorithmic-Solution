#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc app=leetcode.cn id=94 lang=cpp

const int MAXN = 0xffff;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    /*
     * 用类似线索二叉树的思路找前驱结点
     */
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* prev = curr->left;
                TreeNode* next = prev;
                while (prev->right != nullptr) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }

    /*
     * 用队列储存二叉树的先序遍历, 再重建二叉树.
     */
    // void flatten(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     solve(root, q);
    //     int len = q.size();
    //     TreeNode* pre = q.front();
    //     q.pop();
    //     for (int i = 0; i < len - 1; i++) {
    //         TreeNode* curr = q.front();
    //         q.pop();
    //         pre->left = NULL;
    //         pre->right = curr;
    //         pre = curr;
    //     }
    // }
    // void solve(TreeNode* root, queue<TreeNode*>& q) {
    //     if (root) {
    //         q.push(root);
    //         solve(root->left, q);
    //         solve(root->right, q);
    //     }
    // }
};
// @lc code=end

int main(int argc, char* argv[]) {
    return 0;
}