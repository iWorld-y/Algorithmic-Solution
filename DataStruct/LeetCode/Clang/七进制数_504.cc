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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
            : val(x), left(left), right(right) {}
};

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        string ans;
        int temp = abs(num);
        while (temp) {
            ans += temp % 7 + '0';
            temp /= 7;
        }
        reverse(ans.begin(), ans.end());
        if (num < 0) {
            ans = "-" + ans;
        }
        return ans;
    }
};
// class Solution {
// public:
// 	string convertToBase7(int num) {
//         if (num == 0) {
// 			return "0";
// 		}
// 		string ans;
// 		int temp = abs(num);
// 		while (temp > 0) {
// 			string sTemp;
// 			sTemp.push_back(temp % 7 + '0');
// 			ans = sTemp + ans;
// 			if (temp < 7) {
// 				temp /= 7;
// 				if (temp == 0) {
// 					break;
// 				}
// 				sTemp.clear();
// 				sTemp.push_back(temp + '0');
// 				ans = sTemp + ans;
// 				break;
// 			}
// 			temp /= 7;
// 			//cout << sTemp << endl << endl;
// 		}
// 		if (num < 0) {
// 			ans = "-" + ans;
// 		}
// 		return ans;
// 	}
// };

int main(int argc, char *argv[]) {
    Solution s;
    // cout << s.convertToBase7(-7) << endl;
    cout << s.convertToBase7(100) << endl;
    return 0;
}