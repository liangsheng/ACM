#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, sum, m;
vector<LL> a, dp, cnt;
vector<vector<int>> g;

struct Node {
    int u, v;
    LL w;
    Node() {}
    Node(int U, int V, LL W): u(U), v(V), w(W) {}
};
vector<Node> ans;

void dfs(int u, int fa) {
    dp[u] = a[u], cnt[u] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] += dp[v], cnt[u] += cnt[v];
    }
}

void gao(int u, int v) {
    int cv = cnt[v], cu = n - cv;
    LL dv = dp[v], du = sum - dv;
    LL ov = cv * m, ou = cu * m;
    if (du > ou) ans.push_back(Node(u, v, du - ou));
    else if (dv > ov) ans.push_back(Node(v, u, dv - ov));
    for (int t : g[v]) if (t != u) gao(v, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    while (cin >> n) {
        a = vector<LL>(n + 1, 0);
        dp = vector<LL>(n + 1, 0);
        cnt = vector<LL>(n + 1, 0);
        g = vector<vector<int>>(n + 1, vector<int>());
        sum = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        m = sum / n;
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        ans.clear();
        dfs(1, -1);
        for (int v : g[1]) gao(1, v);

        for (int i = 1; i <= n; i++) g[i].clear();
        vector<bool> ok(ans.size(), 0);
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < ans.size(); i++) {
            g[ans[i].u].push_back(i);
            q.push({a[ans[i].u] - ans[i].w, i});
        }
        cout << ans.size() << '\n';
        while (!q.empty()) {
            auto [_w, id] = q.top();
            q.pop();
            if (ok[id]) continue;
            int u = ans[id].u, v = ans[id].v;
            LL w = ans[id].w;
            if (a[u] < w) continue;
            ok[id] = 1;
            a[u] -= w, a[v] += w;
            cout << u << ' ' << v << ' ' << w << '\n';
            for (int j: g[u]) {
                if (ok[j]) continue;
                q.push({a[ans[j].u] - ans[j].w, j});
            }
            for (int j: g[v]) {
                if (ok[j]) continue;
                q.push({a[ans[j].u] - ans[j].w, j});
            }
        }
    }
    return 0;
}