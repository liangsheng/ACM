#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, n, sx = 0, sy = 0, ex = 0, ey = 0, x, y, z;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    vector<vector<int>> g(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'S') sx = i, sy = j;
            else if (s[i][j] == 'T') ex = i, ey = j;
            else if (s[i][j] == '#') g[i][j] = -1;
        }
    }

    cin >> n;
    while (n--) {
        cin >> x >> y >> z;
        g[x - 1][y - 1] = z;
    }

    if (g[sx][sy] <= 0) {
        cout << "No" << '\n';
        return 0;
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> d(h, vector<int>(w, -1));
    priority_queue<tuple<int, int, int>> q;
    q.push({d[sx][sy] = g[sx][sy], sx, sy});
    while (!q.empty()) {
        auto [z, x, y] = q.top();
        q.pop();
        if (z < d[x][y] || z == 0) continue;
        // cout << "x= " << x << ", y= " << y << ", z= " << z << '\n';
        for (int k = 0; k < 4; k++) {
            int u = x + dx[k], v = y + dy[k];
            if (u < 0 || u >= h || v < 0 || v >= w || s[u][v] == '#') continue;
            int tmp = max(g[u][v], z - 1);
            if (tmp > d[u][v]) q.push({d[u][v] = tmp, u, v});
        }
    }
    cout << (d[ex][ey] >= 0 ? "Yes" : "No") << '\n';
    return 0;
}