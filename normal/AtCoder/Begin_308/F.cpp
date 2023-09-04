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

        auto ok = [&](LL tmp) {
            vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));
            dp[0][0] = 1;
            for (int i = 1; i <= n; i++) {
                dp[i][1] = ((p[i] & tmp) == tmp);
                for (int j = 2; j <= k && j <= i; j++) {
                    for (int h = 1; h <= i - (j - 1); h++) {
                        LL t = p[i] - p[i - h];
                        if (dp[i - h][j - 1] && ((t & tmp) == tmp)) {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
            return dp[n][k];
        };
        LL l = 0, r = 1LL << D, mid;
        while (l != r) {
            mid = (l + r) / 2 + 1;
            if (ok(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << '\n';
    }
    return 0;
}