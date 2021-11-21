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

int myAtoi(char* s) {
    int ans = 0;
    int len = strlen(s);
    int i = 0;
    bool isNegativeNum = false;

    for (; i < len; i++) {
        if (s[i] != ' ')
            break;
    }
    if (i == len)
        return 0;
    elif (s[i] == '-') {
        isNegativeNum = true;
        i++;
    }
    elif (s[i] == '+') i++;

    if (!('0' <= s[i] && s[i] <= '9')) {
        return 0;
    }

    for (; i < len; i++) {
        if (!('0' <= s[i] && s[i] <= '9'))
            break;

        if (ans > INT_MAX / 10 ||
            ans == INT_MAX / 10 && (s[i] - '0' > 7)) {  //即将溢出
            return isNegativeNum ? INT_MIN : INT_MAX;
        }
        ans *= 10;
        ans += s[i] - '0';

        // elif(INT_MIN / 10 <= -ans &&
        //     ans <= INT_MAX / 10) {
        //     ans *= 10;
        //     ans += s[i] - '0';
        // }
        // elif (!isNegativeNum && ans > (INT_MAX - (s[i] - '0')) / 10) {
        //     return INT_MAX;
        // }
        // elif (isNegativeNum && -ans < (INT_MIN + (s[i] - '0')) / 10) {
        //     return INT_MIN;
        // }
    }
    return isNegativeNum ? -ans : ans;
}

int main(int argc, char* argv[]) {
    char s[][20] = {
        "42",           "   -42",      "4193 with words", "words and 987",
        "-91283472332", "21474836460", "  -0012a42",      "-2147483648"};
    for (int i = 0; i < 8; i++) {
        printf("\n\n");
        printf("%d\t", myAtoi(s[i]));
        printf("%s\n", s[i]);
        printf("------------\n");
    }
    return 0;
}