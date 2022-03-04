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
    int removeElement(vector<int>& nums, int val) {
        int right = nums.size(), left = 0;
        for (; left < right;) {
            if (nums[left] == val) {
                swap(nums[left], nums[--right]);
                // printNums(nums);
            } else {
                left++;
            }
        }
        return left;
    }
    void printNums(vector<int>& nums) {
        for (auto num : nums) {
            printf("%d ", num);
        }
        printf("\n");
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums = {1};
    cout << s.removeElement(nums, 1);
    printf("\n***************\n");
    s.printNums(nums);
    return 0;
}
