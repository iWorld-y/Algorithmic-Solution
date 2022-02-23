//#define _CRT_SECURE_NO_DEPRECATE
//#include <ctype.h>
//#include <limits.h>
//#include <math.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXN 0xffff
//#define INF 0x7fffffff
//
//typedef long long ll;
//typedef double fl;
//
//#define mem(arr, num) memset(arr, num, sizeof(arr))
//#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
//#define newStruct(structName) \
//    (struct structName*)malloc(sizeof(struct structName))
//#define elif else if
//#define bool int
//#define false 0
//#define true 1
//
//struct TreeNode {
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//bool buddyStrings(char* s, char* goal) {
//    if (strlen(s) != strlen(goal))
//        return false;
//    if (strcmp(s) == strcmp(goal)) {
//        int cnt[26] = {0};
//        for (int i = 0; i < strlen(s); i++) {
//            cnt[s[i] - 'a']++;
//            if (cnt[s[i] - 'a'] > 1)
//                return true;
//        }
//        return false;
//    } else {
//    }
//}
//
//int main(int argc, char* argv[]) {
//    char* str1 = "aa";
//    char* str2 = "aa";
//    printf("%s", buddyStrings(str1, str2) ? "true" : "false");
//    return 0;
//}

#include <stdio.h>
int main() {
    int i = 3, x;
    int a[4];
    srand(123);
    //scanf_s("%d", &x);  //输入1257
    for (int check = 0; check < 1001; check++) {
        x = random(10, 100);
        while (i != -1) {
            a[i] = x % 10;
            x = x / 10;
            i--;
        }  //得到含有1257四个元素数组

        for (i = 0; i < 4; i++) {
            a[i] = (a[i] + 8) % 10;
        }

        // swap
        int p, q;
        p = a[0];
        a[0] = a[2];
        a[2] = p;

        q = a[1];
        a[1] = a[3];
        a[3] = q;

        for (i = 0; i < 4; i++) {
            printf("%d", a[i]);
        }printf("\n");
    }
    return 0;
}