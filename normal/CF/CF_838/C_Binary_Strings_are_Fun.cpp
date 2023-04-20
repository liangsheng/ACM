#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int ans = 1, d = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) d = (LL) d * 2 % MOD;
            else d = 1;
            ans = ((LL) ans + d) % MOD;
        }
        cout << ans << '\n';

        // vector<vector<int>> dp(n + 1, vector<int>(2 * n - 1, 0));
        // dp[1][s[0] == '0'] = 1;
        // for (int i = 1; i <= n - 1; i++) for (int j = 0; j <= 2 * i - 1; j++) {
        //     if (dp[i][j] == 0) continue;
        //     int d = s[i] - '0', x = j, y = 2 * i - 1 - j;
        //     // if (d == 0) {
        //     //     if (x + 2 >= i + 1) dp[i + 1][j + 2] += dp[i][j];
        //     //     if (x + 1 >= i + 1) dp[i + 1][j + 1] += dp[i][j];
        //     // } else {
        //     //     if (y + 1 >= i + 1) dp[i + 1][j + 1] += dp[i][j];
        //     //     if (y + 2 >= i + 1) dp[i + 1][j] += dp[i][j];
        //     // }
        //     if (d == 0) {
        //         if (i - j <= 1) dp[i + 1][j + 2] += dp[i][j];
        //         if (i - j <= 0) dp[i + 1][j + 1] += dp[i][j];
        //     } else {
        //         if (i - j >= 1) dp[i + 1][j + 1] += dp[i][j];
        //         if (i - j >= 0) dp[i + 1][j] += dp[i][j];
        //     }
        // }
        // int ans = 0;
        // for (int i = 1; i <= n; i++) for (int j = 0; j <= 2 * i - 1; j++) ans += dp[i][j];
        // cout << ans << '\n';
    }
    return 0;
}