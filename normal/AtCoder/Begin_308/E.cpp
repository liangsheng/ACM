// and问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 57;

int n, k;
vector<LL> a, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k) {
        a = vector<LL>(n + 1, 0);
        p = vector<LL>(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];

        vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][1] = p[i];
            for (int j = 2; j <= i && j <= k; j++) {
                for (int h = 1; h <= i - (j - 1); h++) {
                    dp[i][j] = max(dp[i][j], dp[i - h][j - 1] & (p[i] - p[i - h]));
                }
            }
        }
        cout << dp[n][k] << '\n';
    }
    return 0;
}