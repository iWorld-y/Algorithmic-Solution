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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* left = head;
    struct ListNode* right = head;
    // for (int i = 0; i <= n; i++) {
    for (int i = 0; i < n; ++i) {
        right = right->next;
    }

    /* n 等于链表长度 */
    if (right == NULL) {
        return head->next;
    }

    while (right->next != NULL) {
        printf("left.val: %d\tright.val: %d\n", left->val, right->val);
        right = right->next;
        left = left->next;
    }
    left->next = left->next->next;
    return head;
}

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    // int arr[] = {1, 2};
    // int arr[] = {1};
    int len = sizeof(arr) / sizeof(int);
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = node;
    for (int i = 0; i < len; i++) {
        node->val = arr[i];
        struct ListNode* nextNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = nextNode;
        nextNode->next = NULL;
        node = nextNode;
    }
    head = removeNthFromEnd(head->next, 2);
    do {
        printf("%d\t", head->val);
        head = head->next;
    } while (head->next);
    return 0;
}