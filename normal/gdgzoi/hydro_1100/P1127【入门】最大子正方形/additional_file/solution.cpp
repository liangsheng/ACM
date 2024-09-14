#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];

    // L[i][j] 表示从 (i, j) 开始往左数有多少个连续的 1
    vector<vector<int>> L(n + 1, vector<int>(m + 1, 0));

    // U[i][j] 表示从 (i, j) 开始往上数有多少个连续的 1
    vector<vector<int>> U(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            U[i][j] = (g[i - 1][j - 1] == '1' ? U[i - 1][j] + 1 : 0);
            L[i][j] = (g[i - 1][j - 1] == '1' ? L[i][j - 1] + 1 : 0);
        }
    }
    
    // dp[i][j] 表示以 (i, j) 位右下角的最大正方形的边长
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (g[i - 1][j - 1] == '1') {
            dp[i][j] = min(L[i][j - 1], U[i - 1][j]) + 1;
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            ans = max(ans, dp[i][j] * dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}