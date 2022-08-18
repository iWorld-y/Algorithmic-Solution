#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 0xffff;
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef double fl;

#define mem(arr, num) memset(arr, num, sizeof(arr));
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
#define elif else if
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main(int argc, char* argv[]) {
    string msg;
    int cnt = 0, ans = 0;
    while (getline(cin, msg)) {
        if (msg[0] == '+')
            cnt++;
        else if (msg[0] == '-')
            cnt--;
        else {
            int temp = msg.find(':');
            ans += cnt * (msg.size() - 1 - temp);
        }
    }
    cout << ans;
    return 0;
}