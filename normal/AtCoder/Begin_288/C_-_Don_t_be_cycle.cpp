#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n, m, x, y;
    while (cin >> n >> m) {
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans = 0;
        vector<bool> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (f[i]) continue;
            ans++, f[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : g[u]) {
                    if (f[v]) continue;
                    f[v] = 1;
                    q.push(v);
                }
            }
        }
        cout << m - (n - ans) << '\n';
    }
    return 0;
}