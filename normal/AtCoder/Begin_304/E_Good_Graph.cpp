#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q, u, v;
    while (cin >> n >> m) {
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) if (!f[i]) {
            f[i] = i;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                u = q.front(), q.pop();
                for (int v : g[u]) if (!f[v]) f[v] = i, q.push(v);
            }
        }
        for (int i = 1; i <= n; i++) if (f[i] == 0) f[i] = i;
        
        bool ok = 1;
        cin >> k;
        set<pii> s;
        for (int i = 0; i < k; i++) {
            cin >> u >> v;
            u = f[u], v = f[v];
            if (u == v) ok = 0;
            if (u > v) swap(u, v);
            s.insert({u, v});
        }

        cin >> q;
        for (int j = 0; j < q; j++) {
            cin >> u >> v;
            if (!ok) {
                cout << "No" << '\n';
                continue;
            }
            u = f[u], v = f[v];
            if (u > v) swap(u, v);
            if (s.count({u, v})) cout << "No" << '\n';
            else cout << "Yes" << '\n';
        }
    }
    return 0;
}