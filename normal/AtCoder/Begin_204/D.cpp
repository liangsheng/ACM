#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 100005;

int n, m;
int t[N], dp[2][M];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int now, pre, ans;
    while (cin >> n) {
        m = 0;
        for (int i = 0; i < n; i++) cin >> t[i], m += t[i];
        now = 0, pre = 1;
        memset(dp[now], 0, sizeof(dp[now]));
        dp[now][0] = 1;
        for (int i = 0; i < n; i++) {
            swap(now, pre);
            memset(dp[now], 0, sizeof(dp[now]));
            for (int j = 0; j <= m / 2; j++) dp[now][j] = dp[pre][j];
            for (int j = 0; j <= m / 2; j++) {
                if (!dp[pre][j]) continue;
                // cout << "i= " << i << ' ' << j << ' ' << max(j, m - j) << '\n';
                int d = j + t[i];
                if (d <= m / 2) dp[now][d] = 1;
            }
        }
        ans = m;
        for (int j = 1; j <= m / 2; j++) if (dp[now][j]) {
            // cout << "j= " << j << '\n';
            ans = min(ans, max(j, m - j));
        }
        cout << ans << '\n';
    }
    return 0;
}