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
#include <vector>

using namespace std;

const int MAXN = 0xffff;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

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
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0, idx = 0;
        if (nums[0] == target)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            cout << (nums[i] < target) ? "true\n" : "false\n";
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target) {
                pos = i + 1;
            }
        }
        return pos;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1, 3, 5, 6};
    // cout << s.searchInsert(nums, 5) << endl;
    cout << s.searchInsert(nums, 2) << endl;
    // cout << s.searchInsert(nums, 7) << endl;
    return 0;
}