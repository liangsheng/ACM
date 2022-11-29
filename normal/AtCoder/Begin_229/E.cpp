#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m, x, y;
vector<int> g[N];
int ans[N], f[N];

void init() {
    for (int i = 1; i <= n; i++) f[i] = i;
}

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void gao() {
    int now = n;
    init();
    ans[n] = 0;
    for (int u = n - 1; u >= 1; u--) {
        ans[u] = ans[u + 1] + 1;
        for (int v : g[u + 1]) {
            int fu = find(u + 1), fv = find(v);
            // cout << "u= " << u << ' ' << fu << " v= " << v << ' ' << fv << '\n';
            if (fu != fv) f[fu] = fv, ans[u]--;
        }
    }
}

int main() {
    priority_queue<int> q;
    q.push(2);
    q.push(1);
    cout << q.top() << '\n';
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            if (x > y) swap(x, y);
            g[x].push_back(y);
        }
        gao();
        for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    }
    return 0;
}