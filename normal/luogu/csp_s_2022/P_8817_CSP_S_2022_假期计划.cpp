#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, x, y;
    while (cin >> n >> m >> k) {
        k++;
        vector<int> a(n + 1, 0);
        vector<vector<int>> g(n + 1, vector<int>());
        for (int i = 2; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
        auto bfs = [&](int u) {
            queue<int> q;
            d[u][u] = 0, q.push(u);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int v : g[x]) if (d[u][v] == INF) {
                    d[u][v] = d[u][x] + 1;
                    q.push(v);
                }
            }
        };
        for (int i = 1; i <= n; i++) bfs(i);
        for (int i = 2; i <= n; i++) {
            int &v1 = g[i][0], &v2 = g[i][1], v3 = g[i][2];
            for (int j = 2; j <= n; j++) if (i != j && d[i][j] <= k && d[1][j] <= k) {
                if (a[j] > a[v1]) {
                    v3 = v2, v2 = v1, v1 = j;
                } else if (a[j] > a[v2]) {
                    v3 = v2, v2 = j;
                } else if (a[j] > a[v1]) {
                    v3 = j;
                }
            }
        }
        LL ans = 0;
        for (int i = 2; i <= n; i++) for (int j = i + 1; j <= n; j++) if (d[i][j] <= k) {
            for (int h = 0; h < 3; h++) for (int p = 0; p < 3; p++) {
                x = g[i][h], y = g[j][p];
                if (x <= 1 || y <= 1 || x == y || x == i || x == j || y == i || y == j) continue;
                // cout << "x= " << x << ", i= " << i << ", j= " << j << ", y= " << y << '\n';
                ans = max(ans, (LL) a[i] + a[j] + a[x] + a[y]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}