#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> c(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
            c[x]++, c[y]++;
        }
        if (n != m + 1) {
            cout << "No" << '\n';
            continue;
        }
        int a1 = 0, a2 = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i]== 1) a1++;
            else if (c[i] == 2) a2++;
        }
        if (!(a1 + a2 == n && a1 == 2 && a2 == n - 2)) {
            cout << "No" << '\n';
            continue;
        }
        queue<int> q;
        vector<int> f(n + 1, 0);
        f[1] = 1, q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (f[v]) continue;
                f[v] = 1;
                q.push(v);
            }
        }
        int s = accumulate(f.begin(), f.end(), 0);
        cout << (s == n ? "Yes" : "No") << '\n';
    }
    return 0;
}