#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = f[i][j - 1] + (g[i - 1][j - 1] == '*');
    
    vector<vector<int>> dl(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) dl[n - 1][j] = (g[n - 1][j] == '*');
    for (int i = n - 2; i >= 0; i--) {
        dl[i][0] = (g[i][0] == '*');
        for (int j = 1; j < m; j++) {
            dl[i][j] = (g[i][j] == '*') * (dl[i + 1][j - 1] + 1);
        }
    }

    vector<vector<int>> dr(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++) dr[n - 1][j] = (g[n - 1][j] == '*');
    for (int i = n - 2; i >= 0; i--) {
        dr[i][m - 1] = (g[i][m - 1] == '*');
        for (int j = 0; j < m - 1; j++) {
            dr[i][j] = (g[i][j] == '*') * (dr[i + 1][j + 1] + 1);
        }
    }

    for (int k = 1; 2 * k + 1 <= m && k + 1 <= n; k++) {
        int x = k + 1, y = 2 * k + 1;
        for (int i = 0; i + x <= n; i++) for (int j = 0; j + y <= m; j++) {
            bool ok = (f[i + x][j + y] - f[i + x][j] == y);
            ok &= (g[i][j + k] == '*');
            ok &= (dl[i][j + k] >= k && dr[i][j + k] >= k);
            ans += ok;
        } 
    }
    cout << ans << '\n';
    return 0;
}