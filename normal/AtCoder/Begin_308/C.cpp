// 最优路线2
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, g, r;
    while (cin >> n >> m) {
        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cin >> g >> r;

        vector<vector<LL>> dp(m, vector<LL>(g + 1, -1));
        dp[0][g] = 0;
        queue<pair<LL, pii>> q;
        q.push({-dp[0][g], {0, g}});
        while (!q.empty()) {
            auto [w, it] = q.front();
            q.pop();
            w = -w;
            int p = it.first, d = it.second;
            if (dp[p][d] != w) continue;
            // cout << "p= " << p << ", d= " << d << ' ' << dp[p][d] << '\n';
            for (int u = p - 1; u <= p + 1; u += 2) {
                if (u < 0 || u >= m) continue;
                int t = d - abs(a[u] - a[p]);
                if (t < 0) continue;
                LL tmp = w + abs(a[u] - a[p]);
                int k = t;
                if (k == 0) tmp += r, k = g;
                if (dp[u][k] == -1 || tmp < dp[u][k]) {
                    dp[u][k] = tmp;
                    q.push({-dp[u][k], {u, k}});
                }
            }
        }
        LL ans = -1;
        for (int i = 1; i <= g; i++) {
            if (dp[m - 1][i] == -1) continue;
            LL tmp = dp[m - 1][i];
            if (i == g) tmp -= r;
            if (ans == -1 || tmp < ans) ans = tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}