#include <bits/stdc++.h>
using namespace std;

int T, n, m, x, y;
vector<vector<bool>> g;
int kx[2] = {1, 0};
int ky[2] = {0, 1};

vector<vector<bool>> gao(int x, int y, int d) {
    // cout << "x= " << x << ", y= " << y << '\n';
    vector<vector<bool>> a(n, vector<bool>(3, 0));
    queue<pair<int, int>> q;
    q.push({x, y}), a[x][y] = 1;
    while (!q.empty()) {
        auto [u, v] = q.front();
        // cout << "u= " << u << ", v= " << v << '\n';
        q.pop();
        for (int k = 0; k < 2; k++) {
            x = u + d * kx[k], y = v + d * ky[k];
            if (x < 0 || x >= n || y < 0 || y >= 3) continue;
            // cout << "xx= " << x << ", yy= " << y << ' ' << g[x][y] << ' ' << a[x][y] << '\n';
            if (g[x][y] || a[x][y]) continue;
            a[x][y] = 1;
            q.push({x, y});
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        g = vector<vector<bool>>(n, vector<bool>(3, 0));
        while (m--) {
            cin >> x >> y;
            g[x - 1][y - 1] = 1 - g[x - 1][y - 1];
        }
        vector<vector<bool>> b = gao(n - 1, 2, -1);
        vector<vector<bool>> a = gao(0, 0, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) ans += (a[i][j] & b[i][j]);
        ans -= (a[0][0] & b[0][0]);
        cout << ans << '\n';
    }
    return 0;
}