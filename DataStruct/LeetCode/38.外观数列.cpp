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
    string solve(string str) {
        if (str.length() == 0) {
            return "";
        }
        if (str.length() == 1) {
            return "1" + str;
        }
        string ans = "";
        char pre = str[0];
        int cnt = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str[i] == pre) {
                cnt++;
            } else if (str[i] != pre) {
                ans += to_string(cnt) + pre;
                pre = str[i];
                cnt = 1;
            }
            pre = str[i];
        }
        if (cnt)
            ans += to_string(cnt) + str[str.length() - 1];
        return ans;
    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string ans = "1";
        for (int i = 1; i < n; i++) {
            ans = solve(ans);
        }
        return ans;
    }
};

// @lc code=end
int main(int argc, char* argv[]) {
    Solution s;
    s.countAndSay(5);
    return 0;
}