#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const i64 INF = numeric_limits<i64>::max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    // dp[j][i]: 完成第 j 列, 并最终停在 (i, j) 的最大和
    int now = 0, pre = 1;
    vector<vector<i64>> dp(2, vector<i64>(n, -INF));
    dp[now][0] = a[now][0];
    for (int i = 1; i < n; i++) dp[now][i] = dp[now][i - 1] + a[i][0];

    for (int j = 1; j < m; j++) {
        swap(now, pre);
        fill(dp[now].begin(), dp[now].end(), -INF);

        // 从上到下
        dp[now][0] = dp[pre][0] + a[0][j];
        for (int i = 1; i < n; i++) {
            dp[now][i] = max(dp[pre][i], dp[now][i - 1]) + a[i][j];
        }

        // 从下到上
        dp[now][n - 1] = max(dp[now][n - 1], dp[pre][n - 1] + a[n - 1][j]);
        vector<i64> f(n, -INF);
        f[n - 1] = dp[pre][n - 1] + a[n - 1][j];
        for (int i = n - 2; i >= 0; i--) {
            // 注意这里不能直接用 dp[now]
            f[i] = max(dp[pre][i], f[i + 1]) + a[i][j];
            dp[now][i] = max(dp[now][i], f[i]);
        }
    }
    cout << dp[now][n - 1] << '\n';
    return 0;
}