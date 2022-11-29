#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, k;
    while (cin >> n >> m >> k) {
        vector<int> a(m), b(m), e(k);
        vector<LL> c(m);
        for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i];
        for (int i = 0; i < k; i++) cin >> e[i];
        
        vector<LL> dp(n + 1, -1);
        dp[1] = 0;
        for (int i = 0; i < k; i++) {
            int x = a[e[i] - 1], y = b[e[i] - 1];
            LL z = c[e[i] - 1];
            // cout << "x= " << x << ' ' << y << ' ' << z << '\n';
            if (dp[x] == -1) continue;
            LL tmp = dp[x] + z;
            if (dp[y] == -1 || dp[y] > tmp) dp[y] = tmp; //, cout << "i= " << i << " y= " << y << ' ' << tmp << '\n';
        }
        cout << dp[n] << '\n';
    }
    return 0;
}