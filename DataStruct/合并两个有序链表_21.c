#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 10007
#define INF 0x3f3f3f3f

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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* preHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* prev = preHead;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            prev->next = l1;
            l1 = l1->next;
        }
        else {
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }
    prev->next = l1 == NULL ? l2 : l1;
    return preHead->next;
}

int main(int argc, char* argv[]) {
    int l1[] = {1, 2, 4};
    int l2[] = {1, 3, 4};
    int len1 = sizeof(l1) / sizeof(int);
    int len2 = sizeof(l2) / sizeof(int);
    struct ListNode* head1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));

    head1->next = node;
    for (int i = 0; i < len1; i++) {
        node->val = l1[i];
        struct ListNode* nextNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = nextNode;
        nextNode->next = NULL;
        node = nextNode;
    }

    head2->next = node;
    for (int i = 0; i < len2; i++) {
        node->val = l2[i];
        struct ListNode* nextNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        node->next = nextNode;
        nextNode->next = NULL;
        node = nextNode;
    }

    head1 = mergeTwoLists(head1->next, head2->next);

    do {
        printf("%d\t", head1->val);
        head1 = head1->next;
    } while (head1->next);
    return 0;
}