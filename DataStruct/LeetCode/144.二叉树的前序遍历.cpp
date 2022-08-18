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
class Solution {
   public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root) {
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        // if (!root)
        //     return {};
        // vector<int> ans;
        // queue<TreeNode *> q;
        // q.push(root);
        // while (!q.empty()) {
        //     TreeNode *node = q.front();
        //     q.pop();
        //     ans.push_back(node->val);
        //     if (node->left != NULL) {
        //         q.push(node->left);
        //     }
        //     if (node->right != NULL) {
        //         q.push(node->right);
        //     }
        // }
        // return ans;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    TreeNode* node = new TreeNode;
    TreeNode* root = node;
    node->val = 1;

    node->left = new TreeNode;
    node->left->val = 4;

    node->right = new TreeNode;
    node->right->val = 3;

    node->left = new TreeNode;
    node = node->left;
    node->val = 2;

    Solution s;
    vector<int> arr = s.preorderTraversal(root);
    for (auto num : arr) {
        cout << num;
    }
    return 0;
}
