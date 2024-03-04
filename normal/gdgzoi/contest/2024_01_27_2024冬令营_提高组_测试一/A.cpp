#include <bits/stdc++.h>
using namespace std;

const int N = 1005, MOD = 2012;

int n, k;
int dp[N][N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    for (int i = 1; i <= 1000; i++) {
        dp[i][0] = 1, dp[i][i - 1] = 1;
        for (int j = 1; j <= i - 2; j++) {
            dp[i][j] = (dp[i - 1][j - 1] * (i - j) + dp[i - 1][j] * (j + 1)) % MOD;
        }
    }
    while (cin >> n >> k) cout << dp[n][k] << '\n';
    return 0;
}
