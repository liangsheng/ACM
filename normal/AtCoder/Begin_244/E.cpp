#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2005, MOD = 998244353;

int n, m, k, s, t, x;
vector<int> g[N];
int dp[N][N][2];
bool f[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v;
    while (cin >> n >> m >> k >> s >> t >> x) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i <= k; i++) for (int j = 1; j <= n; j++) {
            dp[i][j][0] = 0, dp[i][j][1] = 0;
            f[i][j][0] = 0, f[i][j][1] = 0;
        }
        dp[0][s][0] = 1, f[0][s][0] = 1;
        queue<tuple<int, int, int>> q;
        q.push({0, s, 0});
        while (!q.empty()) {
            auto [l, u, c] = q.front();
            q.pop();
            f[l][u][c] = 0;
            if (l >= k) continue;
            for (int v : g[u]) {
                int d = (v == x);
                dp[l + 1][v][c ^ d] = ((LL) dp[l + 1][v][c ^ d] + dp[l][u][c]) % MOD;
                if (!f[l + 1][v][c ^ d]) {
                    f[l + 1][v][c ^ d] = 1;
                    q.push({l + 1, v, c ^ d});
                }
            }
        }
        cout << dp[k][t][0] << '\n';
    }
    return 0;
}