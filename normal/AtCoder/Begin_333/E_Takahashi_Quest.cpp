#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<int> t(n), x(n);
        vector<vector<int>> a(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> t[i] >> x[i];
            if (t[i] == 1) a[x[i]].push_back(i);
        }
        vector<int> p(n + 1, 0), f(n + 1, 0);
        for (int i = 1; i <= n; i++) p[i] = a[i].size() - 1;
        int ok = 1;
        for (int i = n - 1; i >= 0; i--) if (t[i] == 2) {
            int d = x[i];
            while (p[d] >= 0 && a[d][p[d]] > i) p[d]--;
            if (p[d] < 0) {
                ok = 0;
                break;
            }
            f[a[d][p[d]--]] = 1;
        }
        if (!ok) cout << -1 << '\n';
        else {
            int now = 0, ans = 0;
            for (int i = 0; i < n; i++) {
                if (t[i] == 1) now += f[i], ans = max(ans, now);
                else now--;
            }
            cout << ans << '\n';
            for (int i = 0; i < n; i++) if (t[i] == 1) cout << f[i] << ' ';
        }
    }
    return 0;
}
