#include <stdio.h>
#include <limits.h>
int reverse(int x) {
    int ans = 0, temp = 0;

    while (x != 0) {
        if (ans< INT_MIN / 10 || ans > INT_MAX / 10) {
            return 0;
        }
        temp = x % 10;
        ans = ans * 10 + temp;
        x /= 10;
    }

    return ans;
}
int main() {
    printf("%d", reverse(-123));
    return 0;
}
