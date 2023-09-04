#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<LL> a(n + 2, 0), b(n + 2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        
        int p = -1;
        vector<LL> dp(n + 2, 0), L(n + 2, 0);
        for (int i = 1; i <= n; i++) if (b[i] == 1) {
            p = i;
            break;
        }
        if (p == -1) {
            cout << 0 << '\n';
            continue;
        }
        dp[p] = a[p];
        dp[p - 1] = a[p - 1];
        dp[p + 1] = a[p + 1];
        for (int i = 1; i <= p + 1; i++) L[i] = max(dp[i], L[i - 1]);
        
            // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
            // cout << '\n';
            // for (int i = 1; i <= n; i++) cout << L[i] << ' ';
            // cout << '\n';
        for (int i = p + 1; i <= n; i++) {
            if (b[i] == 1) {
                dp[i - 1] = max(dp[i - 1], L[i - 2] + a[i - 1]);
                dp[i] = max(dp[i], L[i - 1] + a[i]);
                dp[i + 1] = max(dp[i + 1], L[i] + a[i + 1]);
            }
            L[i + 1] = max(L[i], dp[i + 1]);
            L[i] = max(L[i - 1], dp[i]);
            L[i - 1] = max(L[i - 2], dp[i - 1]);
            L[i] = max(L[i], L[i - 1]);
            L[i + 1] = max(L[i + 1], L[i]);
            // cout << "i= " << i << '\n';
            // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
            // cout << '\n';
            // for (int i = 1; i <= n; i++) cout << L[i] << ' ';
            // cout << '\n';
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}