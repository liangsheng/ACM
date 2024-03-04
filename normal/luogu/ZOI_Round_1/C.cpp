#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int D = 30, INF = ~0U >> 2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    vector<pii> a, b;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (s[i][j] == 'A') a.push_back({i, j});
        else if (s[i][j] == 'B') b.push_back({i, j});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto [sx, sy] = a[0];
    auto [ex, ey] = b[0];
    priority_queue<pii> q;
    vector<int> dis(n * m, INF);
    dis[sx * m + sy] = 0, q.push({0, sx * m + sy});
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto [w, id] = q.top();
        q.pop();
        w = -w;
        if (dis[id] != w) continue;
        int x = id / m, y = id % m;
        // printf("x= %d, y= %d, d= %d\n", x, y, dis[x * m + y]);
        for (int k = 0; k < 4; k++) {
            int u = x + dx[k], v = y + dy[k];
            bool ok = true;
            for (auto [c, d] : a) {
                c = u - sx + c, d = v - sy + d;
                if (c < 0 || c >= n || d < 0 || d >= m || s[c][d] == '#') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                int p = u * m + v;
                if (dis[p] > w + 1) {
                    dis[p] = w + 1;
                    q.push({-dis[p], p});
                }
            }
        }
    }
    if (dis[ex * m + ey] == INF) {
        cout << "No" << '\n';
        cout << -1 << '\n';
    } else {
        cout << "Yes" << '\n';
        cout << dis[ex * m + ey] << '\n';        
    }
    return 0;
}