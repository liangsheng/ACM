#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, x;
vector<vector<int>> g;
vector<int> a, d;

void gao(int u, int fa, int w) {
    d[u] = w;
    for (int v : g[u]) {
        if (v == fa) continue;
        gao(v, u, w + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        g = vector<vector<int>>(n, vector<int>());
        a = vector<int>(n);
        for (int i = 1; i < n; i++) {
            cin >> x;
            g[x - 1].push_back(i);
            g[i].push_back(x - 1);
        }
        for (int i = 0; i < n; i++) cin >> a[i];
        d = vector<int>(n);
        gao(0, -1, 1);
        LL ans = 0;
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        for (int i = 0; i < n; i++) ans += (LL) a[i] * d[i];
        cout << ans << '\n';
    }
    return 0;
}