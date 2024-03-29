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
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 1) cnt++;
            if (i == 0) cnt--;
            if (cnt > 0)
                for (int j = 0; j < n; j++)
                    if (mat[i][j] == 1) mat[0][j] += cnt;
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (mat[0][i] == 1) sum++;
        return sum;
    }
};
// @lc code=end

int main(int argc, char* argv[]) { return 0; }