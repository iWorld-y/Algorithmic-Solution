#include <math.h>
#include <stdio.h>
int main() {
    int k;
    scanf("%d", &k);
    long long ans = 0;
    int sum = (sqrt(8 * k + 1) - 1) / 2;
    for (int i = 1; i <= sum; i++) {
        ans += i * i;
    }
    int max_days = ((1 + sum) * sum) / 2;
    ans += (sum + 1) * (k - max_days);
    printf("%d\n", ans);
    return 0;
}