#define _CRT_SECURE_NO_DEPRECATE
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXN 200007
#define INF 0x3f3f3f3f

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define bool int
#define false 0
#define true 1
bool isLegal(char ch) {
    if (isalnum(ch) || isalpha(ch))
        return true;
    return false;
}
bool isPalindrome(char* s) {
    int len = strlen(s);
    int left = 0, right = len - 1;

    for (; left < right;) {
        if (isLegal(s[left])&&isLegal(s[right])) {
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++, right--;
        }elif(!isLegal(s[left]) && isLegal(s[right])) {
            left++;
        }elif(isLegal(s[left]) && !isLegal(s[right])) {
            right--;
        }elif(!isLegal(s[left]) && !isLegal(s[right])) {
            left++, right--;
        }
    }
    return true;
}

/**
 * 此为 筛选 + 判断法, 空间效率较为低下
 *
 */

// bool isPalindrome(char* s) {
//     int len = strlen(s), newLen = 0;
//     char str[MAXN];
//     mem(str, '\0');
//     for (int i = 0; i < len; i++) {
//         if (('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
//             str[newLen++] = s[i];
//         }
//         elif('A' <= s[i] && s[i] <= 'Z') { str[newLen++] = s[i] - 'A' + 'a';
//         }
//     }
//     for (int i = 0, j = newLen - 1; i < newLen / 2; i++, j--) {
//         if (str[i] != str[j]) {
//             return false;
//         }
//     }
//     return true;
// }

int main(int argc, char* argv[]) {
    char* ch = "0P";
    printf("%d", isPalindrome(ch));
    return 0;
}