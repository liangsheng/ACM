#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, sz, u, v;
    while (cin >> n >> m) {
        vector<vector<pii>> g(m + n + 1, vector<pii>());
        for (int i = 1; i <= n; i++) {
            u = i + m;
            cin >> sz;
            for (int j = 0; j < sz; j++) {
                cin >> v;
                g[u].push_back({v, 0});
                g[v].push_back({u, 1});
            }
        }
        vector<int> d(n + m + 1, -1), f(n + m + 1, 0);
        priority_queue<pii> q;
        d[1] = 0, f[1] = 1;
        q.push({-d[1], 1});
        while (!q.empty()) {
            auto [t, u] = q.top();
            q.pop();
            t = -t;
            if (d[u] != t) continue;
            // cout << "u= " << u << " " << d[u] << '\n';
            for (pii it : g[u]) {
                int v = it.first;
                int w = t + it.second;
                if (d[v] == -1 || w < d[v]) {
                    d[v] = w;
                    if (!f[v]) f[v] = 1, q.push({-d[v], v});
                }
            }
        }
        if (d[m] == -1) cout << -1 << '\n';
        else cout << d[m] - 1 << '\n';
    }
    return 0;
}