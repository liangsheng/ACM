#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int id[N];
vector<int> g[N], f[N];

bool gao() {
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) f[i].clear();
    for (int i = 1; i <= m; i++) f[g[i][0]].push_back(i);
    for (int i = 1; i <= n; i++) if (f[i].size() == 2) q.push(i);
    // for (int i = 1; i <= n; i++) {
    //     cout << "i= " << i << ' ' << f[i].size() << '\n';
    //     for (auto& x : f[i]) cout << x << ' ';
    //     cout << '\n';
    // }
    while (!q.empty()) {
        int x = f[q.front()][0], y = f[q.front()][1];
        ans++, q.pop();
        if (++id[x] < g[x].size()) {
            int u = g[x][id[x]];
            f[u].push_back(x);
            if (f[u].size() == 2) q.push(u);
        }
        if (++id[y] < g[y].size()) {
            int v = g[y][id[y]];
            f[v].push_back(y);
            if (f[v].size() == 2) q.push(v);
        }
    }
    return ans == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, x;
    while (cin >> n >> m) {
    // while (~scanf("%d %d", &n, &m)) {
        for (int i = 1; i <= m; i++) {
            id[i] = 0, g[i].clear();
            cin >> c;
            // scanf("%d", &c);
            while (c--) {
                cin >> x;
                // scanf("%d", &x);
                g[i].push_back(x);
            }
        }
        cout << (gao() ? "Yes" : "No") << '\n';
    }
    return 0;
}