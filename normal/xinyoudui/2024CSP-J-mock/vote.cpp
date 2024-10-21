// https://contest.xinyoudui.com/contest/280/problem/1439
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<i64, int>;
const i64 INF = numeric_limits<i64>::max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("vote.in", "r", stdin);
    freopen("vote.out", "w", stdout);

    int n, p, x;
    cin >> n;
    vector<bool> a(n + 1);
    vector<i64> b(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p >> x >> b[i];
        a[i] = x;
        g[p].push_back(i);
    }

    // f[c][i]: 通过贿赂使得 i 节点返回 c 的最小代价
    vector<vector<i64>> f(2, vector<i64>(n + 1, INF));

    // dp[i]: 使得 i 节点的直接儿子节点的 0 和 1 的个数相同的最小代价
    vector<i64> dp(n + 1);
    function<void(int)> dfs = [&](int u) {
        i64 tmp = 0;
        vector<int> c(2, 0);
        vector<priority_queue<pii>> d(2);
        for (int v : g[u]) {
            dfs(v);
            int id = (f[0][v] <= f[1][v] ? 0 : 1);
            c[id]++, tmp += f[id][v];
            d[id].push({f[id][v] - f[id ^ 1][v], v});
        }
        int x = -1;
        if (d[0].size() < d[1].size()) x = 1;
        if (d[0].size() > d[1].size()) x = 0;
        if (x != -1) {
            int cnt = (d[x].size() - d[x ^ 1].size()) / 2;
            for (int _k = 1; _k <= cnt; _k++) {
                auto [w, v] = d[x].top(); d[x].pop();
                // w 是负数
                tmp -= w;
            }
        }
        dp[u] = tmp;
        f[a[u]][u] = min(f[a[u]][u], dp[u]);
        f[a[u] ^ 1][u] = min(f[a[u] ^ 1][u], dp[u] + b[u]);
        if (x != -1) {
            f[x][u] = 0;
            f[x ^ 1][u] = min(f[x ^ 1][u], dp[u] - d[x].top().first);
        } else if (!g[u].empty()){
            f[0][u] = min(f[0][u], -d[1].top().first);
            f[1][u] = min(f[1][u], -d[0].top().first);
        }
        // cout << "u= " << u << ", f0= " << f[0][u] << ", f1= " << f[1][u] << ", dp= " << dp[u] << '\n';
    };
    dfs(1);

    // vector<i64> ans(n + 1);
    // auto gao = [&](int u, i64 fa) {
        
    // };
    // ans[1] = dp[1];
    // for (int v : g[1]) gao(v, u);
    for (int i = 1; i <= n; i++) cout << dp[i] << '\n';
    return 0;
}