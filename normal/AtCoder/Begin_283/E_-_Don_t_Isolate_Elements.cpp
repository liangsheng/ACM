#include <bits/stdc++.h>
using namespace std;

const int INF = ~0U >> 2;

int h, w;
vector<vector<bool>> g;

bool ok(int i, int x, int y, int z) {
    vector<bool> a(w, 0), b(w, 0), c(w, 0);
    if (i - 1 >= 0) {
        for (int j = 0; j < w; j++) a[j] = g[i - 1][j];
        if (x) for (int j = 0; j < w; j++) a[j] = 1 - a[j];
    }
    for (int j = 0; j < w; j++) b[j] = g[i][j];
    if (y) for (int j = 0; j < w; j++) b[j] = 1 - b[j];
    if (i + 1 < h) {
        for (int j = 0; j < w; j++) c[j] = g[i + 1][j];
        if (z) for (int j = 0; j < w; j++) c[j] = 1 - c[j];
    }
    for (int j = 0; j < w; j++) {
        if (j - 1 >= 0 && b[j - 1] == b[j]) continue;
        if (j + 1 < h && b[j + 1] == b[j]) continue;
        if (i - 1 >= 0 && a[j] == b[j]) continue;
        if (i + 1 < h && c[j] == b[j]) continue;
        return 0;
    }
    return 1;
}

void get_min(int &x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> h >> w) {
        g = vector<vector<bool>>(h, vector<bool>(w, 0));
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            int x;
            cin >> x, g[i][j] = x;
        }
        vector<vector<vector<int>>> dp(h, vector<vector<int>>(2, vector<int>(2, INF)));
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            dp[1][i][j] = i + j;
            if (!ok(0, 0, i, j)) dp[1][i][j] = INF;
            // cout << "i= " << i << ", j= " << j << " " << dp[1][i][j] << '\n';
        }
        for (int i = 1; i < h - 1; i++) for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) {
            if (dp[i][x][y] == INF) continue;
            if (ok(i, x, y, 0)) get_min(dp[i + 1][y][0], dp[i][x][y]);
            if (ok(i, x, y, 1)) get_min(dp[i + 1][y][1], dp[i][x][y] + 1);
        }
        int ans = INF;
        for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) {
            if (dp[h - 1][x][y] == INF) continue;
            if (ok(h - 1, y, 0, 0)) ans = min(ans, dp[h - 1][x][y]);
            else if (ok(h - 1, y, 1, 0)) ans = min(ans, dp[h - 1][x][y] + 1);
        }
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}