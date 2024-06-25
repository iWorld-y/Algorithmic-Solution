#include <algorithm>
#include <iostream>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int nums[m], targets;
    for (int i = 0; i < m; i++) {
        scanf("%d ", &nums[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &targets);
        printf("%d\n", (nums, targets, m));
    }
    return 0;
}