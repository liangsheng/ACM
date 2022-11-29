#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1), dp(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<vector<int>> d(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) if (i + a[i] <= n) d[i + a[i]].push_back(i);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            if (i - a[i] >= 1 && dp[i - a[i] - 1]) dp[i] = 1;
            else {
                for (int x : d[i]) if (dp[x - 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}