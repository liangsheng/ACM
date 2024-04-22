#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    // dp[i][j] 表示将 i 划分成不超过 j 组的划分数
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++) dp[0][j] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;  // 划分成 1 组, 只有 1 种方法
        for (int j = 2; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) dp[i][j] += dp[i - j][j];  // 划分成恰好 j 组
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
