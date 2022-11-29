#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int maxi = *max_element(a.begin(), a.end());
        vector<int> dp(m + 15);
        for (int i = 0; i < n; i++) dp[a[i]]++;
        for (int i = 1; i <= maxi; i++) {
            if (dp[i] == 0) continue;
            dp[i + 1] += dp[i] / (i + 1);
            dp[i] = dp[i] % (i + 1);
        }
        bool flag = 1;
        for (int i = 1; i < m; i++) if (dp[i] != 0) {
            flag = 0;
            break;
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
    return 0;
}