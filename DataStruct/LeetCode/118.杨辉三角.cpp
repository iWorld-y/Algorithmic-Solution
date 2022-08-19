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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};
        ans.push_back({1});
        ans.push_back({1, 1});
        for (int i = 1; i < numRows - 1; i++) {
            vector<int> temp;
            temp.push_back(1);
            for (int j = 1; j < ans[i].size(); j++) {
                temp.push_back(ans[i][j - 1] + ans[i][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, char* argv[]) { return 0; }