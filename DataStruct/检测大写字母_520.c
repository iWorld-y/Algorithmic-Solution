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

#define mem(arr, num) memset(arr, num, sizeof(arr))
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define bool int
#define false 0
#define true 1

bool detectCapitalUse(char* word) {
    int len = strlen(word);

    if (len == 1) {
        return true;
    }

    elif ('A' <= word[0] && word[0] <= 'Z') {
        if ('A' <= word[1] && word[1] <= 'Z') {
            for (int i = 1; i < len; i++) {
                if ('a' <= word[i] && word[i] <= 'z')
                    return false;
            }
            return true;
        }
        elif ('a' <= word[1] && word[1] <= 'z') {
            for (int i = 1; i < len; i++) {
                if ('A' <= word[i] && word[i] <= 'Z')
                    return false;
            }
            return true;
        }
    }
    else {
        for (int i = 1; i < len; i++) {
            if ('A' <= word[i] && word[i] <= 'Z')
                return false;
        }
        return true;
    }
}

int main(int argc, char* argv[]) {
    char* s[10] = {"aPP", "USA", "FlaG", "Google"};
    for (int i = 0; i < 4; i++) {
        printf("%s\t%d\n", s[i], detectCapitalUse(s[i]));
    }
    return 0;
}