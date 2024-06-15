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
private:
    unordered_map<char, int> operatorPrecedence;
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<int> oporStack;

        this->operatorPrecedence.insert(pair<char, int>('+', 0));
        this->operatorPrecedence.insert(pair<char, int>('-', 0));
        this->operatorPrecedence.insert(pair<char, int>('*', 1));
        this->operatorPrecedence.insert(pair<char, int>('/', 1));

        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                //过滤掉空格
                while (i < s.size() && s[i] == ' ') {
                    ++i;
                }
            } else if (isdigit(s[i])) {
                //取数字
                int d = 0;
                for (; i < s.size() && isdigit(s[i]); ++i) {
                    d = 10 * d + (s[i] - '0');
                }
                numStack.push(d);
            } else {
                //取运算符
                while (oporStack.size() && !priority(s[i], oporStack.top())) {
                    calc(numStack, oporStack);
                }
                oporStack.push(s[i]);
                ++i;
            }
        }
        while (oporStack.size()) {
            calc(numStack, oporStack);
        }
        return numStack.top();
    }

    void calc(stack<int> &numStack, stack<int> &oporStack) {//计算
        int rightNum = numStack.top();
        numStack.pop();//右操作数
        int leftNum = numStack.top();
        numStack.pop();//左操作数
        int op = oporStack.top();
        oporStack.pop();//运算符
        int ans;
        switch (op) {
            case '+':
                ans = leftNum + rightNum;
                break;
            case '-':
                ans = leftNum - rightNum;
                break;
            case '*':
                ans = leftNum * rightNum;
                break;
            case '/':
                ans = leftNum / rightNum;
                break;
        }
        numStack.push(ans);
    }

    //a 的优先级是否高于 b
    bool priority(char a, char b) {
        return this->operatorPrecedence[a] <= this->operatorPrecedence[b];
    }
};

int main(int argc, char *argv[]) {
    printf("%d\t%d\t%d\t%d\n", '+', '-', '*', '/');
    return 0;
}