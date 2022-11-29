#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
const LL INF = ~0ULL >> 2;

int T, n;
LL a[N];

LL gao() {
    LL ans = INF, tmp, c0 = 0, c1 = a[1], min0 = INF, min1 = a[1];
    for (int i = 2; i <= n; i++) {
        if (i % 2) {
            c1 += a[i];
            min1 = min(min1, a[i]);
        } else {
            c0 += a[i];
            min0 = min(min0, a[i]);
        }
        tmp = c0 + c1;
        if (i % 2) tmp += min1 * (n - i / 2 - 1) + min0 * (n - i / 2);
        else tmp += min1 * (n - i / 2) + min0 * (n - i / 2);
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << gao() << '\n';
    }
    return 0;
}