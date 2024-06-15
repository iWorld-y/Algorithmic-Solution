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

// @lc app=leetcode.cn id=94 lang=cpp

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

// @lc code=start
class Solution {
   public:
    bool isPrefix(string sentence, string searchWord, int start, int end) {
        for (int i = 0; i < searchWord.size(); i++) {
            if (start + i >= end || sentence[start + i] != searchWord[i]) {
                return false;
            }
        }
        return true;
    }

    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1, start = 0, end = 0, n = sentence.size();
        while (start < n) {
            while (end < n && sentence[end] != ' ') {
                end++;
            }
            if (isPrefix(sentence, searchWord, start, end)) return index;
            index++;
            end++;
            start = end;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char* argv[]) {
    string str[] = {"i love eating burger",
                    "burg",
                    "this problem is an easy problem",
                    "pro",
                    "i am tired",
                    "you"};
    Solution s;
    for (int i = 0; i < str->size(); i += 2) {
        cout << s.isPrefixOfWord(str[i], str[i + 1]) << endl;
    }
    return 0;
}