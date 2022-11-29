#include <bits/stdc++.h>
using namespace std;

const int N = 405;

int n, m;

vector<vector<int>> gao() {
    int e;
    vector<int> dx, dy;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) if (i * i + j * j == m) {
        dx.push_back(i), dy.push_back(j);
        dx.push_back(i), dy.push_back(-j);
        dx.push_back(-i), dy.push_back(j);
        dx.push_back(-i), dy.push_back(-j);
    }
    e = dx.size();
    vector<vector<int>> ans(n, vector<int>(n, -1));
    vector<vector<int>> f(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    ans[0][0] = 0, f[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop(), f[x][y] = 0;
        for (int k = 0; k < e; k++) {
            int u = x + dx[k], v = y + dy[k];
            if (u < 0 || u >= n || v < 0 || v >= n) continue;
            if (ans[u][v] == -1 || ans[u][v] > ans[x][y] + 1) {
                ans[u][v] = ans[x][y] + 1;
                if (!f[u][v]) f[u][v] = 1, q.push({u, v});
            }
        }
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> m) {
        vector<vector<int>> ans = gao();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) cout << ans[i][j] << ' ';
            cout << ans[i][n - 1] << '\n';
        }
    }
    return 0;
}