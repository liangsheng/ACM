#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m) {
        if (n == 2) cout << (LL) m * (m - 1) % MOD << '\n';
        else if (n == 3) cout << (LL) m * (m - 1) % MOD * (m - 2) % MOD << '\n';
        else {
            vector<vector<int>> dp(n + 1, vector<int>(2, 0));
            dp[2][1] = (LL) m * (m - 1) % MOD;
            for (int i = 3; i <= n - 1; i++) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = ((LL) dp[i - 1][0] * (m - 1) % MOD + (LL) dp[i - 1][1] * (m - 2) % MOD) % MOD;
            }
            int ans = ((LL) dp[n - 1][0] * (m - 1) % MOD + (LL) dp[n - 1][1] * (m - 2) % MOD) % MOD;
            cout << ans << '\n';
        }
    }
    return 0;
}