#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int n = p.size(), INF = numeric_limits<int>::max() / 2;
    // dp[i][0]: 已买第 1 张股票
    // dp[i][1]: 已卖第 1 张股票
    // dp[i][2]: 已买第 2 张股票
    // dp[i][3]: 已卖第 2 张股票
    vector<vector<int>> dp(n, vector<int>(4, -INF));
    dp[0][0] = -p[0];
    
    // 此题用二维数组会比二维 vector 快一些
    // int dp[100005][4];
    // for (int i = 0; i < n; i++) for (int j = 0; j < 4; j++) dp[i][j] = -INF;
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], -p[i]);
        dp[i][1] = max(dp[i - 1][1], p[i] + dp[i - 1][0]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - p[i]);
        dp[i][3] = max(dp[i - 1][3], p[i] + dp[i - 1][2]);
    }
    int ans = 0;
    ans = max(ans, dp[n - 1][1]);
    ans = max(ans, dp[n - 1][3]);
    return ans;
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