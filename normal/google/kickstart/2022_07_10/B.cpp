#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> gao(vector<int>& a, int n, int k) {
    vector<LL> f(n + 1, 0);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
    vector<LL> dp(k + 1, 0);
    for (int i = 0; i <= min(k, n); i++) for (int j = 0; j + i <= min(k, n); j++) {
        int d = i + j;
        LL x = 0, y = 0;
        if (i != 0) x = f[i];
        if (j != 0) y = f[n] - f[n - j];
        dp[d] = max(dp[d], x + y);
    }
    return dp;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, m, k, cas = 0;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        vector<int> b(m + 1, 0);
        for (int i = 1; i <= m; i++) cin >> b[i];
        cin >> k;
        vector<LL> x = gao(a, n, k);
        vector<LL> y = gao(b, m, k);
        LL ans = 0;
        // for (int i = 0; i <= k; i++) cout << x[i] << ' ';
        // cout << '\n';
        for (int i = 0; i <= k; i++) ans = max(ans, x[i] + y[k - i]);
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}