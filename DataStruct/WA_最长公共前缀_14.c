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

char* longestCommonPrefix(char** strs, int strsSize) {
    int minLen = INT_MAX;
    for (int i = 0; i < strsSize; i++) {
        minLen = minLen > strlen(strs[i]) ? strlen(strs[i]) : minLen;
    }

    char* ans = (char*)malloc(minLen * (sizeof(char)));
    mem(ans, 0);
    for (int col = 0, up = 0; col < minLen; col++) {
        for (int down = 0; down < strsSize; down++) {
            if (strs[up][col] != strs[down][col]) {
                return ans;
            }
        }
        ans[col] = strs[up][col];
    }
    return ans;
}

int main(int argc, char* argv[]) {
    // char* s[20] = {"flower", "flow", "flight"};
    char* s[20] = {"reflower", "flow", "flight"};
    // char* s[20] = {"dog", "racecar", "car"};
    int strSize = 3;
    printf("%s", longestCommonPrefix(s, strSize));
    return 0;
}