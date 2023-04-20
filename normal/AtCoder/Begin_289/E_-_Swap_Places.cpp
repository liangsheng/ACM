#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, x, y;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<vector<bool>> f(n + 1, vector<bool>(n + 1, false));
        dp[1][n] = 0, f[1][n] = 1;
        queue<pair<int, int>> q;
        q.push({1, n});
        while (!q.empty()) {
            auto [u, v] = q.front();
            // cout << "u= " << u << ", v= " << v << " " << dp[u][v] << '\n';
            q.pop(), f[u][v] = 0;
            for (int x : g[u]) for (int y : g[v]) {
                if (a[x] == a[y]) continue;
                if (dp[x][y] == -1 || dp[x][y] > dp[u][v] + 1) {
                    dp[x][y] = dp[u][v] + 1;
                    if (!f[x][y]) f[x][y] = 1, q.push({x, y});
                }
            }
        }
        cout << dp[n][1] << '\n';
    }
    return 0;
}