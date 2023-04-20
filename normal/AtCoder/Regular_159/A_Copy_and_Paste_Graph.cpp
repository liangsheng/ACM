#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q, d, ans;
    LL u, v;
    while (cin >> n >> k) {
        vector<vector<int>> g(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            cin >> d;
            if (d == 1) g[i][j] = 1;
        }
        // for (int i = 0; i < n; i++) g[i][i] = 1;
        for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (k != i && k != j && i != j) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) cout << g[i][j] << ' ';
        //     cout << '\n'; 
        // }
        cin >> q;
        while (q--) {
            cin >> u >> v;
            u--, v--;
            if (u / n == v / n) {
                // cout << u % n << ' ' << v % n << '\n';
                ans = g[u % n][v % n];
            } else {
                u = u % n, v = v % n;
                if (g[u][v] == 1) ans = 1;
                else {
                    ans = INF;
                    for (int j = 0; j < n; j++) if (g[u][j] == 1) ans = min(ans, 1 + g[j][v]);
                }
            }
            if (ans == INF) ans = -1;
            cout << ans << '\n';
        }
    }
    return 0;
}