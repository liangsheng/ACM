#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    string s, t;
    cin >> n >> s;
    cin >> m >> t;
    
    // dp[i][j] 表示 s[1..i] 和 t[1..j] 的最短编辑距离
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, n + m));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
    }
    cout << dp[n][m] << '\n';
    return 0;
}