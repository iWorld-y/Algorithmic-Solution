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
    // vector<int> getRow(int rowIndex) {
    //     vector<int> ans = {1};
    //     if (rowIndex == 0)
    //         return ans;
    //     for (int i = 0; i < rowIndex; i++) {
    //         vector<int> temp = {1};
    //         int j = 0;
    //         while (j + 1 < ans.size()) {
    //             temp.push_back(ans[j] + ans[j + 1]);
    //             j++;
    //         }
    //         temp.push_back(1);
    //         ans.clear();
    //         ans.insert(ans.end(), temp.begin(), temp.end());
    //     }
    //     return ans;
    // }
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        if (rowIndex == 0)
            return ans;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                ans[j] += ans[j - 1];
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}