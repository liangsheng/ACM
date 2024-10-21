#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int m = *max_element(a.begin(), a.end());
    vector<int> dp(n + 1, 0), p(n + 1, 0), q(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        p[i] = q[a[i]] - 1;
        q[a[i]] = i;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = p[i]; j >= 0; j--) {
            if (a[j] != a[i]) dp[i] = max(dp[i], dp[j] + 2);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    cout << res << '\n';
    return 0;
}