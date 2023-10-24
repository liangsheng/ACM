#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, e;
string s;
vector<LL> dp, sum;
vector<vector<int>> g;
vector<int> f;
vector<int> st;

void dfs(int u, int fa) {
    f[u] = fa;
    if (s[u] == '(') {
        dp[u] = 0;
        sum[u] = sum[fa];
        st[e++] = u;
        for (int v : g[u]) if (v != fa) dfs(v, u);
        e--;
    } else {
        int p = -1;
        if (e != 0) p = st[--e];
        if (p != -1) {
            dp[u] = dp[f[p]] + 1;
            sum[u] = sum[f[u]] + dp[u];
        } else {
            dp[u] = 0;
            sum[u] = sum[f[u]];
        }
        for (int v : g[u]) if (v != fa) dfs(v, u);
        if (p != -1) st[e++] = p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    while (cin >> n) {
        cin >> s;
        s += '#';
        for (int i = n; i >= 1; i--) s[i] = s[i - 1];
        s[0] = '#';
        g = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) {
            cin >> x;
            g[i].push_back(x);
            g[x].push_back(i);
        }
    
        f = vector<int>(n + 1, 0);
        dp = vector<LL>(n + 1, 0);
        sum = vector<LL>(n + 1, 0);
        st = vector<int>(n + 1, 0);
        e = 0;
        dfs(1, 0);

        LL ans = 0;
        // for (int i = 1; i <= n; i++) cout << sum[i] << ' ';
        // cout << '\n';
        for (int i = 1; i <= n; i++) ans ^= (LL) i * sum[i];
        cout << ans << '\n';
    }
    return 0;
}