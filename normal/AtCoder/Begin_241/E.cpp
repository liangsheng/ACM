#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    LL n, m, k, d;
    while (cin >> n >> k) {
        vector<LL> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        LL now = 0;
        vector<LL> f(n, -1);
        vector<LL> b;
        for (int i = 0; i < n + 5; i++) {
            LL id = now % n;
            if (f[id] != -1) {
                d = f[id];
                break;
            }
            now += a[id];
            f[id] = i;
            b.push_back(a[id]);
        }
        m = b.size();
        if (k <= m) cout << accumulate(b.begin(), b.begin() + k, 0LL) << '\n';
        else {
            LL ans = accumulate(b.begin(), b.begin() + d, 0LL);
            LL tmp = accumulate(b.begin() + d, b.end(), 0LL), sz = m - d;
            k -= d;
            ans += k / sz * tmp;
            for (int i = 0; i < k % sz; i++) ans += b[d + i];
            cout << ans << '\n';
        }
    }
    return 0;
}