#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = ~0ULL >> 2;

int n;
vector<LL> a, b;
vector<LL> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        a = vector<LL>(n + 1, 0), b = a;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
        dp = vector<LL>(n + 1, 0);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int j = 1; j < i; j++) {
                if (j >= i - 2) dp[i] = max(dp[i], dp[j]);
                else {
                    int id = (i + j) / 2 + 1;
                    int m = i - id;
                    int l = id - j, r = i - j - 1;
                    // cout << "i= " << i << ", j = " << j << ", l= " << l << ", r= " << r << " " << dp[j] - (b[r] - b[l - 1]) + b[m] << '\n'; 
                    dp[i] = max(dp[i], dp[j] - (b[r] - b[l - 1]) + b[m]);
                }
            }
            for (int j = 1; j < i; j++) dp[j] += a[i - j];
            // cout << "i= " << i << '\n';
            // for (int j = 1; j <= i; j++) cout << dp[j] << ' ';
            // cout << '\n';
        }
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= n - 1) ans = max(ans, dp[i]);
            else {
                int id = (i + n + 1) / 2 + 1;
                int m = n + 1 - id;
                int l = id - i, r = n + 1 - i - 1;
                ans = max(ans, dp[i] - (b[r] - b[l - 1]) + b[m]);                
            }
        }
        cout << ans << '\n';
    }
    return 0;
}