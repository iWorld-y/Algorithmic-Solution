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

class MyCircularDeque {
private:
    vector<int> data;
    int front, rear;
    int maxSize;
public:
    MyCircularDeque(int k) {
        k++;
        maxSize = k;
        data.resize(k);
        front = rear = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front + maxSize - 1) % maxSize;
        data[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        data[rear] = value;
        rear = (rear + 1) % maxSize;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % maxSize;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        rear = (rear + maxSize - 1) % maxSize;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return data[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return data[(rear + (maxSize - 1)) % maxSize];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(int argc, char *argv[]) {

    return 0;
}