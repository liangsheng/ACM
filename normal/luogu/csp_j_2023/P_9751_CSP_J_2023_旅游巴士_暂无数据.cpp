#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, x, y, z;
    while (cin >> n >> m >> k) {
        vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>());
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> z;
            g[x].push_back({y, z});
        }
        vector<vector<int>> d(n + 1, vector<int>(k, INF));
        priority_queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < 1; i++) d[1][i] = i, q.push({-i, {1, i}});
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int w = -it.first, u = it.second.first, c = it.second.second;
            if (d[u][c] != w) continue;
            // cout << "u= " << u << ", c= " << c << ", w= " << w << '\n';
            for (auto j : g[u]) {
                int v = j.first, t = j.second, tmp = 0;
                if (w < t) tmp = w + ((t - w) / k + ((t - w) % k > 0)) * k + 1;
                else tmp = w + 1;
                z = tmp % k;
                if (tmp < d[v][z]) {
                    d[v][z] = tmp;
                    q.push({-d[v][z], {v, z}});
                }
            }
        }
        if (d[n][0] == INF) cout << -1 << '\n';
        else cout << d[n][0] << '\n';
    }
    return 0;
}