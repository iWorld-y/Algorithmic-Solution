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

class Solution {
   public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> m;
        vector<int> arr2(arr);
        sort(arr2.begin(), arr2.end());
        int cnt = 1;
        for (int i = 0; i < arr2.size()  ; i++) {
            if (i!=0 && arr2[i] == arr2[i - 1])
                continue;
            m.insert(pair<int, int>(arr2[i], cnt));
            cnt++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    vector<int> arr = { 37,12,28,9,100,56,80,5,12 };
    vector<int> ans = s.arrayRankTransform(arr);
    for (auto num : ans) {
        cout << num << "\t";
    }
    return 0;
}