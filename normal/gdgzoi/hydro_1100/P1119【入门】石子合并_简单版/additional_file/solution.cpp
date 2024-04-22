#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> f[i], f[i] += f[i - 1];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int d = 2; d <= n; d++) {
        for (int i = 1; i + d - 1 <= n; i++) {
            int j = i + d - 1;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + f[j] - f[i - 1]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}