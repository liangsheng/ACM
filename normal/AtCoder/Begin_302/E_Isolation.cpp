#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, ans, cmd, u, v;
    while (cin >> n >> q) {
        ans = n;
        vector<set<int>> g(n);
        while (q--) {
            cin >> cmd;
            // cout << "q= " << q << '\n';
            if (cmd == 1) {
                cin >> u >> v;
                u--, v--;
                ans -= (g[u].size() == 0);
                ans -= (g[v].size() == 0);
                g[u].insert(v), g[v].insert(u);
            } else {
                cin >> u;
                u--;
                ans += (g[u].size() > 0);
                for (int v : g[u]) {
                    if (g[v].size() == 1) ans++;
                    g[v].erase(u);
                }
                g[u].clear();
            }
            cout << ans << '\n';
        }
    }
    return 0;
}