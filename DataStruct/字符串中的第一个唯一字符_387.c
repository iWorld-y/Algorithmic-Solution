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

int firstUniqChar(char* s) {
    int arr[26], len = strlen(s);
    mem(arr, 0);
    for (int i = 0; i < len; i++) {
        arr[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (arr[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    printf("%d", firstUniqChar("jtayytj"));
    return 0;
}