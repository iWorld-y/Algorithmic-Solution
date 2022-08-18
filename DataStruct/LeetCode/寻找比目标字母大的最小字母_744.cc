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

// class Solution {
//    public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         int len = letters.size() - 1;
//         if (target >= letters[len]) {
//             return letters[0];
//         }
//         int low = 0, high = len;
//         while (low < high) {
//             int mid = (high - low) / 2 + low;
//             if (letters[mid] > target) {
//                 high = mid;
//             } else {
//                 low = mid + 1;
//             }
//         }
//         return letters[low];
//     }
// };

class Solution {
   public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        if (target == 'z')
            return letters[0];
        while (l <= r) {
            int m = (l + r) / 2;
            if (letters[m] > target)
                r = m - 1;
            if (letters[m] <= target)
                l = m + 1;
        }

        return letters[l % letters.size()];
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';
    cout << s.nextGreatestLetter(letters, target);
    return 0;
}