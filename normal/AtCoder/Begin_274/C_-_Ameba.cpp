#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n + 1);
        vector<int> dp(2 * n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp[1] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i * 2] = dp[a[i]] + 1;
            dp[i * 2 + 1] = dp[a[i]] + 1;
        }
        for (int i = 1; i <= 2 * n + 1; i++) cout << dp[i] - 1 << '\n';
    }
    return 0;
}