#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int MAXN = 1e5 + 7;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define bool int
#define false 0
#define true 1

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *left, *middle, *right;
    if (head == NULL)
        return head;
    elif (head->next == NULL) return head;
    elif (head->next->next == NULL) {
        left = head;
        middle = head->next;
        left->next = NULL;
        middle->next = left;
        return middle;
    }
    left = NULL;
    middle = head;
    while (middle) {
        right = middle->next;
        middle->next = left;
        left = middle;
        middle = right;
    }
    return left;
}

struct ListNode* findTheMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(struct ListNode* head) {
    struct ListNode* tail = reverseList(findTheMiddle(head));
    while (head != NULL && tail != NULL) {
        if (head->val != tail->val) {
            return false;
        }
        head = head->next;
        tail = tail->next;
    }
    return true;
}

int main(int argc, char* argv[]) {
    return 0;
}