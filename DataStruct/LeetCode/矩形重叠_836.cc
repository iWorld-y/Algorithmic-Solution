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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] ||
            rec2[1] == rec2[3]) {
            return false;
        }
        return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] ||
                 rec1[1] >= rec2[3] || rec1[3] <= rec2[1]);
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> r1 = {0, 0, 2, 2}, r2 = {1, 1, 3, 3};
    cout << s.isRectangleOverlap(r1, r2);
    return 0;
}