#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int> f, sz;
vector<vector<int>> g;

void dfs(int u, int fa) {
    f[u] = fa;
    for (int v : g[u]) if (v != fa) gao(v, u);
} 

void gao(int u, int fa) {
    sz[u] = 1;
    for (int v : g[u]) if (v != fa) {
        gao(v, u);
        sz[u] += sz[v];
    }
    int p = -1;
    for (int v : g[u]) if (sz[v] * 2 > sz[u]) {
        p = v;
        break;
    }
    if (p != -1) {
        f[u] = f[fa]
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        g = vector<vector<int>>(n + 1, vector<int>());
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        f = vector<int>(n + 1, -1);
        dfs(1, -1);

        sz = vector<int>(n + 1, 0);
        gao(1, -1);
    }
    return 0;
}