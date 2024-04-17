#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 85;

int n;
int p[N][N], r[N][N], d[N][N];
LL dp[N][N], f[N][N][N][N];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> p[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) cin >> r[i][j];
        r[i][n] = -1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) cin >> d[i][j];
    }
    for (int j = 1; j <= n; j++) d[n][j] = -1;

    for (int i = n; i >= 1; i--) for (int j = n; j >= 1; j--) {
        f[i][j][i][i] = 0;
        for (int u = i + 1; u <= n; u++) {
            f[i][j][u][j] = f[i][j][u - 1][j] + d[u - 1][j];
        }
        for (int v = j + 1; v <= n; v++) {
            f[i][j][i][v] = f[i][j][i][v - 1] + r[i][v - 1];
        }
        for (int u = i + 1; u <= n; u++) for (int v = j + 1; v <= n; v++) {
            f[i][j][u][v] = min(f[i][j][u - 1][v] + d[u - 1][v], f[i][j][u][v - 1] + r[u][v - 1]);
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = -1;
    dp[n][n] = 0;
    // cout << "ove" << '\n';
    for (int i = n; i >= 1; i--) for (int j = n; j >= 1; j--) {
        if (dp[i][j] != -1) continue;
        dp[i][j] = (f[i][j][n][n] + p[i][j] - 1) / p[i][j] + n - i + n - j;
        for (int u = i; u <= n; u++) for (int v = j; v <= n; v++) {
            if (i == u && j == v) continue;
            if (p[u][v] <= p[i][j]) continue;
            LL tmp = (f[i][j][u][v] + p[i][j] - 1) / p[i][j] + u - i + v - j + dp[u][v];
            dp[i][j] = min(dp[i][j], tmp);
        }
    }
    cout << dp[1][1] << '\n';
    return 0;
}