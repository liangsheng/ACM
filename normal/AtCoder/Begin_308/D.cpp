// and问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 57;

int n, k;
vector<LL> a, p;

bool ok(LL tmp) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
    dp[0][0] = 1;
    // cout << "tmp= " << tmp << '\n';
    for (int i = 1; i <= n; i++) {
        // cout << "i= " << i << '\n';
        dp[i][1] = ((p[i] & tmp) == tmp);
        for (int j = 2; j <= k && j <= i; j++) {
            for (int h = i; h >= j; h--) {
                LL t = p[i] - p[h - 1];
                if (dp[h - 1][j - 1] && ((t & tmp) == tmp)) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
        // cout << "iii= " << i << '\n';
        // for (int j = 1; j <= k; j++) cout << "i= " << i << ", j= " << j << " " << dp[i][j] << '\n';
    }
    // cout << "tmp= " << tmp << " " << dp[n][k] << '\n';
    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k) {
        a = vector<LL>(n + 1, 0);
        p = vector<LL>(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
        LL ans = 0;
        for (int i = D; i >= 0; i--) {
            LL tmp = ans | (1LL << i);
            if (ok(tmp)) ans = tmp;
        } 
        cout << ans << '\n';
    }
    return 0;
}