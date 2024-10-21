#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 100005, M = 7;
const i64 INF = numeric_limits<i64>::max() / 2;

// array<array<i64, M>, N> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int C, T, m;
    cin >> C >> T;
    string s;
    vector<i64> v(10);
    vector<i64> t(M, 1);
    for (int i = 1; i < M; i++) t[i] = t[i - 1] * 10;
    while (T--) {
        cin >> s;
        for (int i = 1; i <= 9; i++) cin >> v[i];

        int n = s.size();
        // dp[j][i]: 表示在 s[i..(n - 1)] 中, 最后一步直接拿走了一个 j 位数的最小代价
        vector<vector<i64>> dp(M, vector<i64>(n + 1, INF));
        dp[0][n] = 0;
        for (int i = n - 1; i >= 0; i--) for (int j = 0; j < M; j++) {
            dp[j][i] = min(dp[j][i], dp[j][i + 1] + v[s[i] - '0']);
            if (j - 1 >= 0) {
                dp[j][i] = min(dp[j][i], dp[j - 1][i + 1] + (s[i] - '0') * t[j - 1]);
            }
            // cout << "i= " << i << ", j= " << j << ", dp= " << dp[j][i] << '\n';
        }
        i64 ans = dp[0][0];
        for (int j = 1; j < M; j++) ans = min(ans, dp[j][0]);
        cout << ans << '\n';
    }
    return 0;
}