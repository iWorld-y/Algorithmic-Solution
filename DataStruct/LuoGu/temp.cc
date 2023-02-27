#include <iostream>
#include <cstring>

using namespace std;

int n, k, a[110000], b[110000];

bool ok(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += (a[i] / x)*(b[i] / x);
        if (cnt >= k)
            return true;
    }

    return false;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    int l = 0;
    int r = 100000;

    while (l <= r) {   // 此处一定要有等号

        int m = (l + r) / 2;
        if (ok(m))
            l = m + 1;
        else
            r = m - 1;
    }
    cout << l - 1 << endl;
    return 0;
}