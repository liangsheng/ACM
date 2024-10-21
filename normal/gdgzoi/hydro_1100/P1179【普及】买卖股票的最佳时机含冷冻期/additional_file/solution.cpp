#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int n = p.size(), INF = numeric_limits<int>::max() / 2;
    // dp[i][0]: 手上没股票, 第 i 天没卖股票
    // dp[i][1]: 手上没股票, 第 i 天卖了股票
    // dp[i][2]: 手上有股票
    vector<vector<int>> dp(n, vector<int>(3, -INF));
    dp[0][0] = 0, dp[0][2] = -p[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][2] + p[i];
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - p[i]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << maxProfit(p) << '\n';

    return 0;
}