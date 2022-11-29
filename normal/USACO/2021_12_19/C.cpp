#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 50, M = 4;

int T, n, m;
string g[N];
LL dp[N][N][2][M];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

LL gao(int x, int y, int f, int d) {
    if (dp[x][y][f][d] != -1) return dp[x][y][f][d];
    if (x == n - 1 && y == n - 1) return dp[x][y][f][d] = 1;
    int u = x + dx[f], v = y + dy[f];
    LL tmp = 0;
    if (u >= 0 && u < n && v >= 0 && v < n && g[u][v] == '.') {
        tmp += gao(u, v, f, d);
    }
    u = x + dx[1 - f], v = y + dy[1 - f];
    if (d + 1 <= m && u >= 0 && u < n && v >= 0 && v < n && g[u][v] == '.') {
        tmp += gao(u, v, 1 - f, d + 1);
    }
    // cout << "x= " << x << ' ' << y << ' ' << f << ' ' << d << ' ' << tmp << '\n';
    return dp[x][y][f][d] = tmp;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> g[i];
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k <= m; k++) {
            dp[i][j][0][k] = -1;
            dp[i][j][1][k] = -1;
        }
        LL ans = 0;
        if (g[0][1] == '.') ans += gao(0, 1, 0, 0);
        if (g[1][0] == '.') ans += gao(1, 0, 1, 0);
        cout << ans << '\n';
    }
    return 0;
}