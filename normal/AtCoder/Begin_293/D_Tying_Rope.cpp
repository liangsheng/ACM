#include <bits/stdc++.h>
using namespace std;

struct UnioSet {
    int n;
    vector<int> f, sz;

    void init(int n) {
        f = vector<int>(n + 1, -1);
        for (int i = 1; i <= n; i++) f[i] = i;
        sz = vector<int>(n + 1, 1);
    }

    int find(int x) {
        if (f[x] == x) return f[x];
        f[x] = find(f[x]);
        return f[x];
    }

    void unio(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy) return ;
        if (sz[fx] >= sz[fy]) {
            f[fy] = fx;
            sz[fx] += sz[fy];
        } else {
            f[fx] = fy;
            sz[fy] += sz[fx];
        }
    }
} S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    char ch;
    while (cin >> n >> m) {
        S.init(n);
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].first >> ch >> a[i].second >> ch;
            S.unio(a[i].first, a[i].second);
        }
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int fx = S.find(a[i].first), fy = S.find(a[i].second);
            if (fx == fy) cnt[fx]++;
        }
        int ans = 0, res = 0;
        vector<bool> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int fx = S.find(i);
            if (f[fx]) continue;
            if (S.sz[fx] == cnt[fx]) ans++;
            else res++;
            f[fx] = 1;
        }
        cout << ans << ' ' << res << '\n';
    }
    return 0;
}