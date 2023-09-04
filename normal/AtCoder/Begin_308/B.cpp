// 最优路线1
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int CH = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    string s;
    while (cin >> n >> m) {
        cin >> s;

        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[y].push_back(x);
            cnt[x]++;
        }

        vector<vector<int>> dp(n + 1, vector<int>(CH, 0));
        for (int i = 1; i <= n; i++) dp[i][s[i - 1] - 'a'] = 1;

        queue<int> q;
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);
        vector<int> a;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            // cout << "u= " << u << '\n';
            a.push_back(u);
            for (int v : g[u]) {
                if (--cnt[v] == 0) q.push(v);
                for (int i = 0; i < CH; i++) {
                    // if (u == 3) cout << "v= " << v << ", i= " << i << ' ' << dp[v][i] << ' ' << dp[u][i] << '\n';
                    dp[v][i] = max(dp[v][i], dp[u][i] + (s[v - 1] - 'a' == i));
                    // if (u == 3) cout << "V= " << v << ", i= " << i << ' ' << dp[v][i] << ' ' << dp[u][i] << '\n';
                }
            }
        }
        vector<int> ans(n + 1, -1);
        for (int u : a) for (int i = 0; i < CH; i++) ans[u] = max(ans[u], dp[u][i]);
        for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    }
    return 0;
}