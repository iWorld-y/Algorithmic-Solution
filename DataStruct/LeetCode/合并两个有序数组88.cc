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
    //原地修改
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i != 0 && j != 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i];
                nums1[--i] = INT_MIN;
            } else if (nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j--];
            }
        }
        if (j != 0) {
            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    }
    //新建数组
    void merge_2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if (i == m && j != n) {
            for (; j < n; j++) {
                ans.push_back(nums2[j]);
            }
        } else if (i != m && j == n) {
            for (; i < m; i++) {
                ans.push_back(nums1[i]);
            }
        }
        // nums1.clear();
        // nums1.assign(ans.begin(), ans.end());
        for (int i = 0; i < m + n; i++) {
            nums1[i] = ans[i];
        }
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
    // vector<int> nums1 = {1}, nums2 = {};
    // s.merge(nums1, 1, nums2, 0);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}