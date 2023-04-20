#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, d;
    cin >> T;
    while (T--) {
        cin >> n >> m >> d;
        vector<int> a(n + 2, 0);
        vector<int> f(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[a[i]] = i;
        }
        f[0] = 0, f[n + 1] = n + 1;
        vector<int> b(m + 2, 0);
        for (int i = 1; i <= m; i++) cin >> b[i];
        b[m + 1] = n + 1;
        bool flag = 1;
        int ans = n;
        for (int i = 1; i < m; i++) {
            if (f[b[i]] > f[b[i + 1]] || f[b[i + 1]] > f[b[i]] + d) {
                // cout << f[b[i]] << ' ' << f[b[i + 1]] << '\n';
                flag = 0;
                break;
            } else {
                ans = min(ans, f[b[i + 1]] - f[b[i]]);
            }
        }
        // cout << "ans= " << ans << ", flag= " << flag << '\n';
        if (!flag) {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i < m; i++) if (f[b[i + 2]] - 1 - (f[b[i - 1]] + 1) > d) {
            ans = min(ans, d + 1 - (f[b[i + 1]] - f[b[i]]));
        }
        cout << ans << '\n';
    }
    return 0;
}