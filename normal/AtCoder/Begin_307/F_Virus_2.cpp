#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pii;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, K, D, u, v, w;
    while (cin >> n >> m) {
        vector<vector<pii>> g(n + 1, vector<pii>());
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<int> ans(n + 1, INF);
        vector<LL> d(n + 1, INF);
        priority_queue<pair<pair<int, LL>, int>> q;
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> u;
            ans[u] = 0, d[u] = 0;
            q.push({{-ans[u], -d[u]}, u});
        }
        cin >> D;
        vector<int> p(D + 1, -1);
        for (int i = 1; i <= D; i++) cin >> p[i];
        
        while (!q.empty()) {
            auto [it, u] = q.top();
            auto [f, w] = it;
            q.pop();
            f = -f, w = -w;
            if (f != ans[u] || w != d[u]) continue;
            cout << "u= " << u << ", ans[u]= " << ans[u] << ", d[u]= " << d[u] << '\n';
            for (auto o : g[u]) {
                auto [v, t] = o;
                LL tmp = d[u] + t;
                if (tmp <= p[f]) {
                    if (f < ans[v] || (f == ans[v] && tmp < d[v])) {
                        ans[v] = f, d[v] = tmp;
                        q.push({{-ans[v], -d[v]}, v});
                    }
                } else if (f != D && t <= p[f + 1]) {
                    if (f + 1 < ans[v] || (f + 1 == ans[v] && t < d[v])) {
                        ans[v] = f + 1, d[v] = t;
                        q.push({{-ans[v], -d[v]}, v});
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ans[i] == INF) ans[i] = -1;
            cout << ans[i] << '\n';
        }
    }
    return 0;
}