#include <bits/stdc++.h>
using namespace std;

int T, n, m;
vector<vector<int>> g, f, R, D;

bool ok(int mid) {
    for (int j = 1; j <= m; j++) D[n][j] = (g[n][j] >= mid);
    for (int i = n - 1; i >= 1; i--) for (int j = 1; j <= m; j++) {
        if (g[i][j] < mid) D[i][j] = 0;
        else D[i][j] = D[i + 1][j] + 1; 
    }
    for (int i = 1; i <= n; i++) R[i][m] = (g[i][m] >= mid);
    for (int j = m - 1; j >= 1; j--) for (int i = 1; i <= n; i++) {
        if (g[i][j] < mid) R[i][j] = 0;
        else R[i][j] = R[i][j + 1] + 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << R[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << D[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i++) f[i][m] = (g[i][m] >= mid);
    for (int j = 1; j <= m; j++) f[n][j] = (g[n][j] >= mid);
    for (int i = n - 1; i >= 1; i--) for (int j = m - 1; j >= 1; j--) {
        if (g[i][j] < mid) f[i][j] = 0;
        else {
            int tmp = min(R[i][j], D[i][j]);
            f[i][j] = min(tmp, f[i + 1][j + 1] + 1);
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (f[i][j] >= mid) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        g = vector<vector<int>>(n + 1, vector<int>(m + 1, 0)); 
        f = g, R = g, D = g;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> g[i][j];

        int l = 1, r = n, mid;
        while (l != r) {
            mid = (l + r) / 2 + 1;
            bool flag = ok(mid);
            // cout << "mid= " << mid << " " << flag << '\n';
            if (flag) l = mid;
            else r = mid - 1;
        }
        cout << l << '\n';
    }
    return 0;
}