#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;

int n, m, e;
LL k, now, ans;
vector<vector<LL>> g;
vector<int> f;
vector<int> s;

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void dfs(int i) {
    // cout << "i= " << i << ", e= " << e << ", now= " << now << '\n';
    if (i == m) {
        f = vector<int>(n + 1, -1);
        for (int j = 1; j <= n; j++) f[j] = j;
        bool ok = 1;
        for (int j = 0; j < e; j++) {
            int u = g[s[j]][0], v = g[s[j]][1];
            int fu = find(u), fv = find(v);
            if (fu == fv) {
                ok = 0;
                break;
            }
            // cout << "fu= " << fu << " " << fv << '\n';
            f[fu] = fv;
        }
        if (ok) ans = min(ans, now);
        return ;
    }
    if (e + m - i - 1 >= n - 1) dfs(i + 1);
    if (e < n - 1) {
        s[e++] = i, now = (now + g[i][2]) % k;
        dfs(i + 1);
        e--, now = ((now - g[i][2]) % k + k) % k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, v, w;
    while (cin >> n >> m >> k) {
        g = vector<vector<LL>>(m, vector<LL>(3));
        for (int i = 0; i < m; i++) {
            cin >> g[i][0] >> g[i][1] >> g[i][2];
        }
        ans = k - 1, now = 0, e = 0;
        s = vector<int>(m);
        dfs(0);
        cout << ans << '\n';
    }
    return 0;
}