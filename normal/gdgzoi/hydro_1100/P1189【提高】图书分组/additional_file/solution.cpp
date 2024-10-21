#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const i64 INF = numeric_limits<i64>::max() / 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("book.in", "r", stdin);
    // freopen("book.out", "w", stdout);

    int n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<int> w(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];

    vector<i64> dp(n + 1, INF), h1(m + 1, INF), h2(m + 1, INF);
    dp[0] = 0;
    h1[w[1]] = dp[0] + 1 - 1 * 1 + w[1];
    h2[w[1]] = dp[0] + 1 - 1 * 1 - w[1];
    for (i64 i = 1; i <= n; i++) {
        i64 tmp = INF;
        for (int j = w[i]; j <= m; j++) tmp = min(tmp, h1[j]);
        dp[i] = min(dp[i], tmp - w[i]);

        tmp = INF;
        for (int j = 1; j < w[i]; j++) tmp = min(tmp, h2[j]);
        dp[i] = min(dp[i], tmp + w[i]);

        dp[i] += k + i + i * i;
        h1[w[i + 1]] = min(h1[w[i + 1]], dp[i] + (i + 1) - (i + 1) * (i + 1) + w[i + 1]);
        h2[w[i + 1]] = min(h2[w[i + 1]], dp[i] + (i + 1) - (i + 1) * (i + 1) - w[i + 1]);

        // for (i64 j = i; j >= 1; j--) {
        //     tmp = min(tmp, dp[j - 1] + j - j * j + abs(w[i] - w[j]));
        //     // dp[i] = min(dp[i], k + dp[j - 1] + cal(j, i));
        // }
        // dp[i] = k + i + i * i + tmp;
        // cout << "i= " << i << ", dp[i]= " << dp[i] << '\n';
    }
    cout << dp[n] << '\n';

    return 0;
}