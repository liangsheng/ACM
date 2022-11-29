#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
const LL INF = ~0ULL >> 2;

int n, m;
vector<tuple<int, int, int> > g[N];

LL spfa() {
    priority_queue<pair<LL, int>> q;
    vector<LL> dis(n + 1, INF);
    auto push = [&](int u, LL d) {
        if (d < dis[u]) {
            dis[u] = d;
            q.emplace(-d, u);
        }
    };
    push(1, 0);
    while (!q.empty()) {
        auto [t, x] = q.top(); q.pop();
        t = -t;
        if (t != dis[x]) continue;
        for (auto [y, c, d]: g[x]) {
            LL sq = sqrt(d), tmp;
            if (dis[x] <= sq) {
                tmp = c + min(sq + d / (sq + 1), sq + 1 + d / (sq + 2));
            } else {
                tmp = c + t + d / (t + 1);
            }
            push(y, tmp);
        }
    }
    return dis[n];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x, y, c, d;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> c >> d;
            g[x].emplace_back(y, c, d);
            g[y].emplace_back(x, c, d);
        }
        LL ans = spfa();
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}