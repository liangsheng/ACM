#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

void add(int &x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[1][0] = 1, dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] != a[i - 1]) add(dp[i][0], dp[i - 1][0]);
            if (a[i] != b[i - 1]) add(dp[i][0], dp[i - 1][1]);
            if (b[i] != a[i - 1]) add(dp[i][1], dp[i - 1][0]);
            if (b[i] != b[i - 1]) add(dp[i][1], dp[i - 1][1]);
        }
        int ans = ((LL) dp[n][0] + dp[n][1]) % MOD;
        cout << ans << '\n';
    }
    return 0;
}