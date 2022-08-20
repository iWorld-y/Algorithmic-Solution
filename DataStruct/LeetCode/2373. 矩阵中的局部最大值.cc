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

// class Solution {
//    public:
//     vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         vector<vector<int>> ret;
//         ret.resize(n - 2);
//         for (auto r : ret) r.resize(n - 2);
//         for (int i = 0; i < n - 2; i++) {
//             for (int j = 0; j < n - 2; j++) {
//                 int x = i + 1, y = j + 1;
//                 int mx = INT_MIN;
//                 for (int k = -1; k <= 1; k++) {
//                     for (int l = -1; l <= 1; l++) {
//                         mx = max(mx, grid[x + k][y + l]);
//                     }
//                 }
//                 ret[i][j] = mx;
//             }
//         }
//         return ret;
//     }
// };

int main(int argc, char* argv[]) {
    vector<vector<int>> arr = {
        {9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    Solution s;
    vector<vector<int>> ret = s.largestLocal(arr);
    for (auto re : ret) {
        for (auto r : re) cout << r << "\t";
        cout << endl;
    }
    return 0;
}