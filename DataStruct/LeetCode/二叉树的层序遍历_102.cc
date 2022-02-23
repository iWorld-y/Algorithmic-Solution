#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
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
#include <vector>

using namespace std;

const int MAXN = 0xffff;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ans.push_back(vector<int>());
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                ans.back().push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};

// class Solution {
//    public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (root == nullptr)
//             return ans;
//         queue<TreeNode*> tree;
//         tree.push(root);
//         while (!tree.empty()) {
//             int size = tree.size();
//             ans.push_back(vector<int>());
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = tree.front();
//                 tree.pop();
//                 ans.back().push_back(node->val);
//                 if (node->left != nullptr) {
//                     tree.push(node->left);
//                 }
//                 if (node->right != nullptr) {
//                     tree.push(node->right);
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main(int argc, char* argv[]) {
    return 0;
}