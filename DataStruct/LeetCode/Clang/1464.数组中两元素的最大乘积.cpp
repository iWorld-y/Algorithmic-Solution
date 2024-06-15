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
    /*
     * O(n)
     */
    int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1];
        int len = nums.size();
        if (a < b) swap(a, b);
        for (int i = 2; i < len; i++) {
            if (a < nums[i]) {
                swap(a, b);
                a = nums[i];
            } else if (b < nums[i])
                b = nums[i];
        }
        return (a - 1) * (b - 1);
    }
    /*
     * O(nlog(n))
     */
    // int maxProduct(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return (nums[0] - 1) * (nums[1] - 1);
    // }
    /*
     * O(n^2)
     */
    // int maxProduct(vector<int>& nums) {
    //     int ans = INT16_MIN;
    //     int len = nums.size();
    //     for (int i = 0; i < len; i++) {
    //         for (int j = i + 1; j < len; j++) {
    //             ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end

int main(int argc, char* argv[]) { return 0; }