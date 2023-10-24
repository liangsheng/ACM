#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = ~0ULL >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, p;
    while (cin >> n >> k >> p) {
        vector<int> c(n);
        vector<vector<int>> a(n, vector<int>(k, 0));
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            for (int j = 0; j < k; j++) cin >> a[i][j];
        }
        vector<int> h(k, 1);
        int t = p;
        for (int i = 1; i < k; i++) {
            h[i] = h[i - 1] * (p + 1);
            t += h[i] * p;
        }
        vector<vector<LL>> dp(n + 1, vector<LL>(t + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j <= t; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            vector<int> b(k, 0);
            int s = 0;
            for (int l = 0; l < k; l++) {
                b[l] = min(j / h[l] % (p + 1) + a[i][l], p);
                s += h[l] * b[l];
            }
            dp[i + 1][s] = min(dp[i + 1][s], dp[i][j] + c[i]);
        }
        // for (int i = 0; i <= n; i++) for (int j = 0; j <= t; j++) if (dp[i][j] != INF) {
        //     cout << "i= " << i << ", j= " << j << " " << dp[i][j];
        //     for (int l = 0; l < k; l++) cout << ' ' << j / h[l] % (p + 1);
        //     cout << '\n';
        // }
        cout << (dp[n][t] == INF ? -1 : dp[n][t]) << '\n'; 
    }
    return 0;
}