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

class MyQueue {
   private:
    stack<int> in;
    stack<int> out;
    int front;

   public:
    MyQueue() {}

    void push(int x) {
        if (this->in.empty())
            this->front = x;
        this->in.push(x);
    }

    int pop() {
        if (this->out.empty()) {
            while (this->in.size() != 0) {
                this->out.push(this->in.top());
                this->in.pop();
            }
        }
        int ans = this->out.top();
        this->out.pop();
        return ans;
    }

    int peek() {
        if (this->out.size() != 0)
            return this->out.top();
        return this->front;
    }

    bool empty() { return this->in.empty() && this->out.empty(); }
};

int main(int argc, char* argv[]) {
    return 0;
}