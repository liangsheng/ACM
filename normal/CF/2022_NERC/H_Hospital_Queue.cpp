#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    while (cin >> n >> m) {
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> p[i];
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) a[i] = i;
        sort(a.begin() + 1, a.end(), [&](const int &i, const int &j) {
            return p[i] < p[j];
        });

        vector<int> cnt(n + 1, 0);
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            cnt[y]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);
        vector<set<int>> h(n + 1, set<int>());
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                h[v].insert(u);
                for (int p : h[u]) h[v].insert(p);
                if (--cnt[v] == 0) q.push(v);
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << "i= " << i << '\n';
        //     for (int v : h[i]) cout << v << ' ';
        //     cout << '\n';
        // }
        vector<int> ans(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            int d = h[i].size();
            
        }
    }
    return 0;
}