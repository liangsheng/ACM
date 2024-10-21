#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m = *max_element(a.begin(), a.end());
    vector<int> dp(n + 1, 0), p(n + 1, 0), q(m + 1, 0);
    vector<int> max1(n + 1, 0), v1(n + 1, 0), max2(n + 1, 0), v2(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        p[i] = q[a[i]] - 1;
        q[a[i]] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] < 0) dp[i] = 0;
        else {
            if (v1[p[i]] != a[i]) dp[i] = max1[p[i]] + 2;
            else dp[i] = max2[p[i]] + 2;
        }
        if (dp[i] > max1[i - 1]) {
            max1[i] = dp[i], v1[i] = a[i];
            if (v1[i - 1] != a[i]) max2[i] = max1[i - 1], v2[i] = v1[i - 1];
            else max2[i] = max2[i - 1], v2[i] = v2[i - 1];
        } else if (dp[i] > max2[i - 1]) {
            max1[i] = max1[i - 1], v1[i] = v1[i - 1];
            if (v1[i - 1] != a[i]) max2[i] = dp[i], v2[i] = a[i];
            else max2[i] = max2[i - 1], v2[i] = v2[i - 1];            
        } else {
            max1[i] = max1[i - 1], v1[i] = v1[i - 1];
            max2[i] = max2[i - 1], v2[i] = v2[i - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}