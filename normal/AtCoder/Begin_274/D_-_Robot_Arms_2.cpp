#include <bits/stdc++.h>
using namespace std;

bool gao(vector<int> &a, int x) {
    int n = a.size(), m = accumulate(a.begin(), a.end(), 0);
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n' << x << ' ' << m << '\n';
    if (n == 0) return x == 0;
    if (x < -m || x > m) return 0;
    int now = 0, pre = 1;
    vector<vector<bool>> dp(2, vector<bool>(2 * m + 1, 0));
    dp[now][a[0] + m] = 1, dp[now][-a[0] + m] = 1;
    for (int i = 1; i < n; i++) {
        swap(now, pre);
        fill(dp[now].begin(), dp[now].end(), 0);
        for (int j = 0; j <= 2 * m; j++) {
            if (dp[pre][j] == 0) continue;
            if (j + a[i] <= 2 * m) dp[now][j + a[i]] = 1;
            if (j - a[i] >= 0) dp[now][j - a[i]] = 1;
        }
    }
    // cout << x + m << ' ' << -a[0] + m << ' ' << dp[now][x + m] << '\n';
    return dp[now][x + m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y, t;
    while (cin >> n >> x >> y) {
        vector<vector<int>> a(2, vector<int>());
        cin >> t;
        x -= t;
        for (int i = 2; i <= n; i++) cin >> t, a[i % 2].push_back(t);
        if (gao(a[0], y) && gao(a[1], x)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}