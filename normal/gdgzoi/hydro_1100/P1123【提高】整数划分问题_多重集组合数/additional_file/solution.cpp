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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // dp[i][j] 表示从前 i 种物品里取出 $j$ 个的方案数
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = 1;  // 注意初始值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            if (j - 1 - a[i] >= 0) {
                // 在结果可能为负的情况下要 + MOD
                dp[i][j] = (dp[i][j] - dp[i - 1][j - 1 - a[i]] + MOD) % MOD;
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
