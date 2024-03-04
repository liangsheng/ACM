#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005, M = 200005, INF = ~0U >> 2;

int n, m, e;
int head[N], pnt[M], nxt[M];
int f[N];

void init() {
    e = 0;
    fill(head + 1, head + n + 1, -1);
    for (int i = 1; i <= n; i++) f[i] = i;
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    init();
    vector<pair<int, int>> g(m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[i] = {u, v};
        if (a[u] == a[v]) f[find(u)] = find(v);
    }
    for (int i = 1; i <= n; i++) find(i);

    int s = f[1], t = f[n];
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < m; i++) {
        auto [u, v] = g[i];
        u = f[u], v = f[v];
        if (u == v) continue;
        if (a[u] > a[v]) swap(u, v);
        if (v != s) add_edge(u, v), cnt[v]++;
    }
    
    vector<int> dp(n + 1, -INF);
    dp[s] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) q.push(i);
    while (!q.empty()) {
        u = q.front(), q.pop();
        for (int i = head[u]; i != -1; i = nxt[i]) {
            v = pnt[i];
            dp[v] = max(dp[v], dp[u] + 1);
            if (--cnt[v] == 0) q.push(v);
        }
    }
    cout << max(0, dp[t]) << '\n';
    return 0;
}