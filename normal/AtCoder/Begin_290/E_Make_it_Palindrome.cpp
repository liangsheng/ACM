#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n + 2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        // for (int i = 1; i <= n; i++) a[i] = i;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        vector<LL> x(n + 1, 0);
        vector<LL> y(n + 1, 0);
        // map<int, LL> x, y;
        for (int i = 1; i <= n; i++) x[a[i]]++;
        LL ans = 0, p = n;
        for (int i = 1; i <= n; i++) {
            if (i * 2 <= n) {
                int j = n - i + 1;
                x[a[i]]--, x[a[j]]--;
                ans += i * (n - 2 * i - x[a[i]]);
                // cout << "iii= " << i << ", ans= " << ans << '\n';

                p = j;
                y[a[p]] += n - p + 1;
                ans += (1LL + i) * i / 2 - y[a[i]];
                // cout << "ii= " << i << ", ans= " << ans << '\n';
            } else {
                while (p <= i) y[a[p]] -= n - p + 1, p++;
                if (p <= n) ans += (1LL + n - p + 1) * (n - p + 1) / 2 - y[a[i]];
            }
            // cout << "i= " << i << ", ans= " << ans << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}