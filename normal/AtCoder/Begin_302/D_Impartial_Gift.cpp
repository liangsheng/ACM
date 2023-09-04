#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // vector<int> c = {1, 2, 3, 4};
    // cout << upper_bound(c.begin(), c.end(), 5) - c.begin() << '\n';
    LL n, m, d;
    while (cin >> n >> m >> d) {
        vector<LL> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        LL ans = -1;
        for (int i = 0; i < n; i++) {
            int j = upper_bound(b.begin(), b.end(), a[i] + d) - b.begin() - 1;
            if (abs(a[i] - b[j]) <= d) ans = max(ans, a[i] + b[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}