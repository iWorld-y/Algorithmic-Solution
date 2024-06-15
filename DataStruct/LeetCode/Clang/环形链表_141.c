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
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        if (fast == slow)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

/**
 * 采用了低效的搜索算法
 */
// bool hasCycle(struct ListNode* head) {
//     // struct ListNode* arr[MAXN] = NULL;
//     int arr[MAXN] = {0};
//     for (int i = 0; head; i++) {
//         arr[i] = head;
//         for (int j = 0; j < i; j++) {
//             if (arr[i] == arr[j])
//                 return true;
//         }
//         head = head->next;
//     }
//     return false;
// }

int main(int argc, char *argv[]) {
    return 0;
}