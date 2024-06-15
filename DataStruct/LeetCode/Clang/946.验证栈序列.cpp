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
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int pushLen = pushed.size(), popLen = popped.size();
        if (pushLen != popLen) {
            return false;
        }
        stack<int> s;
        int popN = 0, pushN = 0;
        while (popN < popLen && pushN < pushLen) {
            if (!s.empty() && s.top() == popped[popN]) {
                s.pop();
                popN++;
            } else if (pushed[pushN] == popped[popN]) {
                pushN++;
                popN++;
                continue;
            } else if (pushed[pushN] != popped[popN]) {
                s.push(pushed[pushN]);
                pushN++;
            }
        }
        while (popN < popLen && s.top() == popped[popN]) {
            s.pop();
            popN++;
        }
        return s.empty();
    }
};
// @lc code=end

int main(int argc, char *argv[]) {
    // vector<int> pushed = {1, 2, 3, 4, 5};
    // vector<int> popped = {4, 5, 3, 2, 1};
    vector<int> pushed = {2, 1, 0};
    vector<int> popped = {1, 2, 0};
    Solution s;
    cout << s.validateStackSequences(pushed, popped);
    return 0;
}