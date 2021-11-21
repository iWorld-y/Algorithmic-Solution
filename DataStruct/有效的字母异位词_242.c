#define _CRT_SECURE_NO_DEPRECATE
#include <limits.h>
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

bool isAnagram(char* s, char* t) {
    int arrS[26], arrT[26];
    int len = strlen(s), tlen = strlen(t);
    mem(arrS, 26);
    mem(arrT, 26);
    if (len != tlen) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        arrS[s[i] - 'a']++;
        arrT[t[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (arrS[s[i] - 'a'] != arrT[s[i] - 'a']) {
            return false;
        }
    }
    return true;
}
int main(int argc, char* argv[]) {
    printf("%d", isAnagram("rat", "car"));
    return 0;
}