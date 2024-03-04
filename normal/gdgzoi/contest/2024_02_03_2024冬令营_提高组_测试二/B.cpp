#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;
typedef long long LL;

const int N = 100005, M = N * 2;

int n, m, e;
int head[N], pnt[M], nxt[M], wv[M];
int d[N], vis[N];

void init(int n) {
    e = 0;
    fill(head, head + n + 1, -1);
    fill(d, d + n + 1, 0);
    fill(vis, vis + n + 1, -2);
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void solve() {
    // 没有边
    if (m == 0) {
        cout << 3 << ' ' << (LL) n * (n - 1) * (n - 2) / 6 << '\n';
        return ;
    }
    vector<int> c(3, 0);
    for (int i = 1; i <= n; i++) c[min(d[i], 2)]++;
    // 没有度超过 1 的点
    if (c[2] == 0) {
        cout << 2 << ' ' << (LL) m * (n - 2) << '\n';
        return ;
    }

    LL ok = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] != -2) continue;
        c[vis[i] = 0] = 1, c[1] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            // cout << "u= " << u << '\n';
            repe (j, u) {
                int v = pnt[j];
                if (vis[v] == -2) c[vis[v] = 1 - vis[u]]++, q.push(v);
                else if (vis[v] == vis[u]) {
                    ok = 1;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok) break;
        if (c[0] >= 2) cnt += (LL) c[0] * (c[0] - 1) / 2;
        if (c[1] >= 2) cnt += (LL) c[1] * (c[1] - 1) / 2;
    }
    if (ok) cout << 0 << ' ' << 1 << '\n';
    else cout << 1 << ' ' << cnt << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int x, y;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        d[x]++, d[y]++;
        add_edge(x, y), add_edge(y, x);
    }
    solve();
    return 0;
}

