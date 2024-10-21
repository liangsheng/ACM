#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    // 记得测试下, 2 维 vector 是不是会很慢
    // dp[i][j]: 从 j 点出发, 还可以添加 i 个点, 最长路径
    vector<vector<int>> dp(m + 1, vector<int>(n, 1));  // 414ms

    // int dp[105][505];  // 393ms, 和 2 维 vector 区别不大
    // for (int j = 0; j <= m; j++) for (int i = 0; i < n; i++) dp[j][i] = 1;

    for (int j = 0; j <= m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (j > 0) dp[j][i] = dp[j - 1][i] + 1;  // 至少可以多加 1 个点
            for (int k = n - 1; k > i; k--) {
                // 点 k 在点 i 的右上角
                if (p[k].first >= p[i].first && p[k].second >= p[i].second) {
                    int d = p[k].first - p[i].first + p[k].second - p[i].second - 1;
                    if (d <= j) {
                        dp[j][i] = max(dp[j][i], dp[j - d][k] + d + 1);
                    }
                }
            }
            // cout << "j= " << j << ", i= " << i << ", dp= " << dp[j][i] << '\n';
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[m][i]);
    cout << ans << '\n';
    // cout << *max_element(dp[m].begin(), dp[m].end()) << '\n';
    return 0;
}