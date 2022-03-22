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

class Solution {
   public:
    string longestWord(vector<string>& words) {
        ll maxIndx = 0, maxL = 0;

        for (int i = 0; i < words.size(); i++) {
            if (max(maxL, words[i].size()) > maxL) {
                maxIndx = i;
                maxL = words[i].size();
            }
        }
        return words[maxIndx];
    }
};

int main(int argc, char* argv[]) {
    return 0;
}