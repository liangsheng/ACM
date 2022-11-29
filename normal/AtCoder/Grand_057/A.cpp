#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    LL T, L, R;
    cin >> T;
    while (T--) {
        cin >> L >> R;
        if (R < 10) {
            cout << R - L + 1 << '\n';
            continue;
        }
        LL ans = 0;
        vector<LL> a = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
        vector<LL> b = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999LL};
        for (LL i = 0; i < 10; i++) {
            LL l = max(L, a[i]), r = min(R, b[i]), d = r - l + 1;
            ans = max(ans, d);
            if (R < b[i]) {
                if (L >= b[i]) break;
                LL l = max(L, a[i - 1]), r = b[i - 1], mid;
                if (a[i] + r <= R || r * 10 <= R) break;
                // cout << "l= " << l << " r= " << r << '\n';
                int cnt = 0;
                while (l < r) {
                    // cout << "l= " << l << " r= " << r << '\n';
                    mid = (l + r) / 2;
                    if (a[i] + mid <= R || mid * 10 <= R) l = mid + 1;
                    else r = mid;
                }
                // cout << "l= " << l << '\n';
                ans = max(ans, R - l + 1);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}