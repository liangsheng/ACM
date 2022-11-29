#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005, MOD = 998244353;

int n, m, x, y, e;
vector<int> g[N];
int f[N];

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

void dfs(int u, int fa, int t) {
    // cout << "u= " << u << ' ' << fa << ' ' << t << '\n';
    f[u] = t;
    for (int v : g[u]) {
        if (v == fa || f[v] != -1) continue;
        dfs(v, u, t);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        e = 0;
        memset(f, -1, sizeof(f));
        for (int i = 1; i <= n; i++) {
            if (f[i] != -1) continue;
            dfs(i, -1, e++);
        }
        // cout << "e= " << e << '\n';
        vector<vector<int>> d(n, vector<int>());
        for (int i = 1; i <= n; i++) d[f[i]].push_back(i);
        int ans = 0, flag = 1;
        for (int t = 0; t < e; t++) {
            int cnt = 0;
            for (int u : d[t]) cnt += g[u].size();
            if (cnt != 2 * d[t].size()) {
                flag = 0;
                break;
            }
        }
        if (flag) ans = power(2, e);
        cout << ans << '\n';
    }
    return 0;
}