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

int n = 0, ans = 0;
short arr[8][8];

bool queenNumber(short** arr) {
    int white = 0, black = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 6) {
                white++;
            }
            if (arr[i][j] == 9) {
                black++;
            }
        }
    }
    return white == n && black == n;
}

void putQueen(short** arr, short row) {
    if (row == n) {
        if (queenNumber(arr))
            ans++;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[row][j] != 0)
                arr[row][j] = 1;
        }
    }
}

int main(int argc, char* argv[]) {
    cin >> n;
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    return 0;
}