#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, id, n, m, f, c;
    cin >> T >> id;
    while (T--) {
        cin >> n >> m >> c >> f;
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];

        vector<vector<int>> R(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = m - 1; j >= 1; j--) if (g[i - 1][j - 1] == '0' && g[i - 1][j] == '0') R[i][j] = R[i][j + 1] + 1;
        }

        vector<vector<int>> D = R;
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= m; j++) if (g[i - 1][j - 1] == '0') D[i][j] += D[i + 1][j];
        }

        int ans = 0, res = 0;
        if (c > 0) {
            for (int i = 1; i <= n - 2; i++) for (int j = 1; j <= m - 1; j++) {
                if (g[i - 1][j - 1] == '0' && g[i][j - 1] == '0') ans = (ans + (LL) R[i][j] * D[i + 2][j] % MOD) % MOD;
            }
        }
        if (f > 0) {
            vector<vector<int>> U = R;
            for (int i = 2; i <= n; i++) for (int j = 1; j <= m; j++) if (g[i - 1][j - 1] == '0') U[i][j] += U[i - 1][j];
                       
            vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
            for (int j = 1; j <= m; j++) d[n][j] = (g[n - 1][j - 1] == '0');
            for (int i = n - 1; i >= 1; i--) for (int j = 1; j <= m; j++) if (g[i - 1][j - 1] == '0') d[i][j] = d[i + 1][j] + 1;

            // for (int i = 1; i <= n; i++) {
            //     for (int j = 1; j <= m; j++) cout << d[i][j] << ' ';
            //     cout << '\n';
            // } 

            for (int i = 3; i <= n - 1; i++) for (int j = 1; j <= m - 1; j++) {
                if (g[i - 1][j - 1] == '0' && g[i - 2][j - 1] == '0') res = (res + (LL) U[i - 2][j] * d[i + 1][j] % MOD * R[i][j] % MOD) % MOD;
            }
        }
        cout << ans << ' ' << res << '\n';
    }
    return 0;
}