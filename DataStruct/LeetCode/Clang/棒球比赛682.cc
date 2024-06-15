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
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i][0] == 'C') {
                v.pop_back();
            } else if (ops[i][0] == 'D') {
                v.push_back(v[v.size() - 1] * 2);
            } else if (ops[i][0] == '+') {
                v.push_back(v[v.size() - 1] + v[v.size() - 2]);
            } else {
                v.push_back(stoi(ops[i]));
            }
        }
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    // vector<string> str = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    vector<string> str = {"1", "C", "-62", "-45", "-68"};
    Solution s;
    cout << s.calPoints(str);
    return 0;
}