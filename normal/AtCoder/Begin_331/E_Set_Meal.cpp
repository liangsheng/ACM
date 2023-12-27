#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q, x, y;
    while (cin >> n >> m >> q) {
        vector<int> a(n, 0), b(m, 0), d(m, 0);
        vector<vector<int>> c(n, vector<int>());
        vector<bool> f(m, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        for (int i = 0; i < m; i++) d[i] = i;
        sort(d.begin(), d.end(), [&](const int& i, const int& j) {
            return b[i] < b[j];
        });
        while (q--) {
            cin >> x >> y;
            c[x - 1].push_back(y - 1);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j : c[i]) f[j] = 1;
            for (int j = m - 1; j >= 0; j--) if (!f[d[j]]) {
                ans = max(ans, a[i] + b[d[j]]);
                break;
            }
            for (int j : c[i]) f[j] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}