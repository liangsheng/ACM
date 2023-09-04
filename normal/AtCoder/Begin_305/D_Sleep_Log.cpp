#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l, r;
    while (cin >> n) {
        vector<int> a(n + 2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> b(n + 2, 0);
        for (int i = 3; i <= n; i++) {
            b[i] = b[i - 1];
            if (i & 1) b[i] += a[i] - a[i - 1];
            // cout << "i= " << i << ' ' << b[i] << '\n';
        }
        cin >> m;
        while (m--) {
            cin >> l >> r;
            if (r <= a[2]) {
                cout << 0 << '\n';
                continue;
            }
            int x = lower_bound(a.begin() + 1, a.begin() + n + 1, l) - a.begin();
            int y = upper_bound(a.begin() + 1, a.begin() + n + 1, r) - a.begin() - 1;
            if (r == a[n]) y = n;
            int ans = b[y] - b[x];
            // cout << "x= " << x << ", y= " << y << ", ans= " << ans << '\n';
            if (x >= 3 && x % 2) ans += a[x] - l;
            if (y >= 2 && y % 2 == 0) ans += r - a[y];
            cout << ans << '\n';
        }
    }
    return 0;
}