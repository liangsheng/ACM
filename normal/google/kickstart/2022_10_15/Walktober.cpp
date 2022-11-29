#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, p;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> m >> n >> p;
        vector<vector<int>> a(m, vector<int>(n, 0));
        vector<int> b(n, 0);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j] = max(b[j], a[i][j]);
        }
        int ans = 0;
        for (int j = 0; j < n; j++) ans += b[j] - a[p - 1][j];
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}