#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k, u, v;
    cin >> n >> k;
    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        cin >> u >> v;
        s.insert({u, v});
    }

    int ans = 0;
    map<tuple<int, int, int>, int> m;

    function<int(int, int, int)> gao = [&](int u, int v, int c) {
        if (m.count({u, v, c})) return m[{u, v, c}];
        if (c < 0) return 0;
        int tmp = gao(u + 1, v, c - !s.count({u + 1, v})) + 1;
        tmp = max(tmp, gao(u, v + 1, c - !s.count({u, v + 1})) + 1);
        if (c == k) ans = max(ans, tmp);
        // cout << "u= " << u << ", v= " << v << ", c= " << c << ", tmp= " << tmp << '\n';
        return m[{u, v, c}] = tmp;
    };
    for (auto it : s) gao(it.first, it.second, k);
    
    cout << ans << '\n';
    return 0;
}