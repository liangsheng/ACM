#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int N = 200005, INF = ~0U >> 2;

int n, m, k, x, y, z;
int a[N], h[N];
vector<pii> g[N];
int d[N][2], f[N][2];

void spfa() {
    for (int i = 1; i <= n; i++) for (int j = 0; j < 2; j++) {
        d[i][j] = INF;
        f[i][j] = 0;
    }
    queue<pii> q;
    d[1][0] = 0, f[1][0] = 1;
    q.push({1, 0});
    while (!q.empty()) {
        auto [u, s] = q.front();
        int w = d[u][s] + 1;
        // cout << "u= " << u << ", s= " << s << " " << d[u][s] << '\n';
        q.pop();
        f[u][s] = 0;
        for (auto it : g[u]) if (it.Y ^ s) {
            int v = it.X;
            if (d[v][s] > w) {
                d[v][s] = w;
                if (!f[v][s]) f[v][s] = 1, q.push({v, s});
            }
        }
        if (h[u]) {
            s ^= 1;
            // cout << "uuuu= " << u << ", s= " << s << '\n';
            for (auto it : g[u]) if (it.Y ^ s) {
                int v = it.X;
                // cout << "v= " << v << " " << d[v][s] << ;
                if (d[v][s] > w) {
                    d[v][s] = w;
                    if (!f[v][s]) f[v][s] = 1, q.push({v, s});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k) {
        for (int i = 1; i <= n; i++) g[i].clear(), h[i] = 0;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> z;
            g[x].push_back({y, z});
            g[y].push_back({x, z});
        }
        for (int i = 1; i <= k; i++) {
            cin >> x;
            h[x] = 1;
        }
        spfa();
        int ans = min(d[n][0], d[n][1]);
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}