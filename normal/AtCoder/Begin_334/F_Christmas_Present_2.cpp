#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, k;
    while (~scanf("%d %d", &n, &k)) {
        vector<pair<LL, LL>> a(n + 1);
        for (int i = 0; i <= n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);

        auto dis = [&](int i, int j) {
            LL x = a[i].first - a[j].first;
            LL y = a[i].second - a[j].second;
            return sqrt(x * x + y * y);
        };
        vector<double> L(n + 1, 0);
        for (int i = 2; i <= n; i++) L[i] = L[i - 1] + dis(i - 1, i);

        vector<double> dp(n + 1), f(n + 1);
        dp[1] = dis(0, 1), f[1] = dp[1];
        int l = 0, r = 0;
        vector<int> q(n + 1);
        q[r++] = 1;
        // cout << "i= " << 1 << ", dp[i]= " << dp[1] << ", f[i]= " << f[1] << '\n';
        for (int i = 2; i <= n; i++) {
            f[i] = dp[i - 1] + dis(i - 1, 0) + dis(0, i);
            dp[i] = f[i];
            while (l != r && q[l] < i - k + 1) l++;
            if (l != r) dp[i] = min(dp[i], f[q[l]] + L[i] - L[q[l]]);
            while (l != r && f[q[r - 1]] - L[q[r - 1]] >= f[i] - L[i]) r--;
            q[r++] = i;
            // cout << "i= " << i << ", dp[i]= " << dp[i] << ", f[i]= " << f[i] << '\n';
        }
        printf("%.9f\n", dp[n] + dis(n, 0));
    }
    return 0;
}