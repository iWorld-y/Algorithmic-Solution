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

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countSegments(string s) {
        if (s.length() == 0)
            return 0;
        int ans = 0;
        bool isNotSpace = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ' && isNotSpace) {
                ans++;
                isNotSpace = false;
            } else if (s[i] == ' ')
                isNotSpace = true;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<string> s = {"a", "       ", "", "Hello, my name is John"};
    Solution S;
    for (int i = 0; i < s.size(); i++)
        cout << S.countSegments(s[i]) << endl;

    return 0;
}