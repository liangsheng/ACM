#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int T, n, x, y;
int a[N], dp[N], b[N];
vector<int> g[N];

void dfs(int u, int fa) {
    dp[u] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        if (a[v] < a[u]) dp[u] += dp[v];
    }
}

void gao(int u, int fa) {
    if (a[u] > a[fa]) b[u] = dp[u] + b[fa];
    else b[u] = dp[u];
    for (int v : g[u]) {
        if (v == fa) continue;
        gao(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> n;
        for (int i = 1; i <= n; i++) g[i].clear(), cin >> a[i];
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        dfs(1, -1);
        b[1] = dp[1];
        for (int v : g[1]) gao(v, 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, b[i]);
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}