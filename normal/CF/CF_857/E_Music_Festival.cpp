#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, x;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> x;
                a[i].push_back(x);
            }
        }
        vector<vector<int>> f = a;
        for (int i = 0; i < n; i++) {
            f[i][0] = 1;
            int now = a[i][0];
            for (int j = 1; j < a[i].size(); j++) {
                f[i][j] = f[i][j - 1];
                if (a[i][j] > now) {
                    f[i][j]++;
                    now = a[i][j];
                }
            }
        }
        vector<vector<int>> h = a;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < a[i].size(); j++) h[i][j] = max(h[i][j - 1], a[i][j]);
        }

        vector<int> c(n);
        for (int i = 0; i < n; i++) c[i] = i;
        sort(c.begin(), c.end(), [&](const int &x, const int &y) {
            int sx = a[x].size(), sy = a[y].size();
            int ans = f[x][sx - 1];
            int id = upper_bound(h[y].begin(), h[y].end(), h[x][sx - 1]) - h[y].end();
            if (id != h[y].size()) {
                ans += f[y][sy - 1];
                if (id != 0) ans -= f[y][id - 1];
            }

            int res = f[y][sy - 1];
            id = upper_bound(h[x].begin(), h[x].end(), h[y][sy - 1]) - h[x].end();
            if (id != h[x].size()) {
                res += f[x][sx - 1];
                if (id != 0) res -= f[x][id - 1];
            }
            return ans > res;
        });
        for (int i = 0; i < n; i++) cout << c[i] << ' ';
        cout << '\n';
        vector<int> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < a[c[i]].size(); j++) q.push_back(a[c[i]][j]);
        int ans = 1, now = q[0];
        for (int i = 1; i < q.size(); i++) if (q[i] > now) {
            ans++;
            now = q[i];
        }
        cout << ans << '\n';
    }
    return 0;
}