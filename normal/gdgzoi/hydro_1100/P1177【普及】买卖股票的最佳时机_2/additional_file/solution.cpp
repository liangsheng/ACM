#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0, dp[0][1] = -p[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + p[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - p[i]);
    }
    return dp[n - 1][0];
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