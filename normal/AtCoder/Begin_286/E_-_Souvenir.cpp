#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, LL> pii;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    while (cin >> n) {
        vector<int> a(n + 1, 0);
        vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
        vector<vector<LL>> f(n + 1, vector<LL>(n + 1, -1));
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= n; j++) if (s[j - 1] == 'Y') {
                d[i][j] = 1;
                f[i][j] = a[i] + a[j];
            }
        }
        for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            if (i == k || i == j || j == k) continue;
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        
        for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            if (i == k || i == j || j == k) continue;
            if (d[i][k] + d[k][j] == d[i][j]) f[i][j] = max(f[i][j], f[i][k] + f[k][j] - a[k]);
        }

        cin >> m;
        while (m--) {
            cin >> x >> y;
            if (d[x][y] >= INF) cout << "Impossible" << '\n';
            else cout << d[x][y] << ' ' << f[x][y] << '\n';
        }
    }
    return 0;
}