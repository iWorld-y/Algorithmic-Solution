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
    bool ansFun(TreeNode* root, ll lower, ll upper) {
        if (root == nullptr)
            return true;
        else if (root->val <= lower || root->val >= upper)
            return false;
        return ansFun(root->left, lower, root->val) &&
               ansFun(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) { return ansFun(root, LONG_MIN, LONG_MAX); }
};

int main(int argc, char* argv[]) {
    return 0;
}