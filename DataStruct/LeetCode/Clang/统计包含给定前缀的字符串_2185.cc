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
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, len = pref.size();
        for (auto str : words) {
            if (str.substr(0, len) == pref) {
                ans++;
            }
            // bool illegal = true;
            // for (int i = 0; i < pref.size(); i++) {
            //     if (str[i] != pref[i]) {
            //         illegal = false;
            //         break;
            //     }
            // }
            // if (illegal)
            //     ans++;
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<string> words = {"pay", "attention", "practice", "attend"};
    cout << s.prefixCount(words, "at") << endl;
    words = {"leetcode", "win", "loops", "success"};
    cout << s.prefixCount(words, "code");
    return 0;
}