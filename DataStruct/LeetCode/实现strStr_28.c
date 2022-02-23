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

int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);
    if (nLen == 0) {
        return 0;
    }
    elif (hLen < nLen) return -1;
    for (int i = 0; i <= hLen - nLen; i++) {
        if (haystack[i] == needle[0]) {
            int j = 0;
            for (; j < nLen; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == nLen) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    printf("%d", strStr("", ""));
    return 0;
}