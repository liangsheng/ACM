#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y;
    while (cin >> n >> m) {
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            cnt[y]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);
        vector<int> ans;
        vector<int> f(n + 1, 0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            f[u] = 1;
            for (int v : g[u]) {
                if (--cnt[v] == 0) q.push(v);
            }
        }
        if (ans.size() == n) {
            cout << 1 << '\n';
            for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
            cout << ans[n - 1] << '\n';
        } else {
            cout << 2 << '\n';
            int sz = ans.size();
            for (int i = 1; i <= n; i++) if (!f[i]) ans.push_back(i);
            for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
            cout << ans[n - 1] << '\n';
            reverse(ans.begin() + sz, ans.end());
            for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
            cout << ans[n - 1] << '\n';
        }
    }
    return 0;
}