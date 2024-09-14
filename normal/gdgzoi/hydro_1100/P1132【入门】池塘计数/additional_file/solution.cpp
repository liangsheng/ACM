#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    int dx[8] = {-1, -1, 0, 1, 1,  1, 0,  -1};
    int dy[8] = {0,   1, 1, 1, 0, -1, -1, -1};

    int cnt = 0;
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (g[i][j] == '.' || f[i][j] != 0) continue;

        // 找到一个还没访问的有水的地方
        queue<pair<int, int>> q;
        f[i][j] = ++cnt;
        // q.push({i, j});
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 8; k++) {
                int u = x + dx[k], v = y + dy[k];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;
                if (g[u][v] == '.' || f[u][v] > 0) continue;
                f[u][v] = cnt, q.push({u, v});
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}
