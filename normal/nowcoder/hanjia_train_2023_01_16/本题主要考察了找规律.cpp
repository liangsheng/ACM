#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (~scanf("%d %d", &n, &m)) {
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j <= m; j++) {
            if (dp[i][j] == -1) continue;
            // cout << "i= " << i << ", j= " << j << dp[i][j] << '\n';
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            for (int k = 1; k <= m - j; k++) {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + k * 1.0 / (m - j));
            }
        }
        double ans = 0.0;
        for (int j = 0; j <= m; j++) ans = max(ans, dp[n][j]);
        printf("%.9f\n", ans);
    }
    return 0;
}