#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        LL x = 0, y = 1 << 20;
        vector<vector<LL>> a(n, vector<LL>(m, 0));
        a[0][0] = x, a[0][1] = x + 1;
        for (int j = 2; j < m; j++) a[0][j] = a[0][j - 2] + 4;
        a[1][0] = y, a[1][1] = y + 1;
        for (int j = 2; j < m; j++) a[1][j] = a[1][j - 2] + 4;
        LL d = 1 << 10;
        for (int i = 2; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = a[i - 1][j] + d;
        cout << n * m << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) cout << a[i][j] << ' ';
            cout << a[i][m - 1] << '\n';
        }
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = 0; j < m - 1; j++) {
        //         LL c = a[i][j] ^ a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1];
        //         cout << c << '\n';
        //     }
        // }
    }
    return 0;
}