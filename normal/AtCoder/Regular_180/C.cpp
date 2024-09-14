#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1000000007, D = 1000;

void add(int& x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int now = 0, pre = 1;
    vector<vector<int>> dp(2, vector<int>(2 * D + 1, 0));
    set<int> s;
    if (a[1] != 0) s.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        if (a[i] == 0) continue;
        swap(now, pre);
        dp[now] = dp[pre];
        for (auto it : s) dp[now][it + a[i] + D]++;

        // cout << "iii= " << i << '\n';
        // for (int j = 0; j <= 2 * D; j++) {
        //     if (dp[now][j] == 0) continue;
        //     cout << "j= " << j - D << ' ' << dp[now][j] << '\n';
        // }

        for (int j = 0; j <= 2 * D; j++) {
            if (dp[pre][j] == 0) continue;
            int t = j + a[i];
            if (t >= 0 && t <= 2 * D) {
                add(dp[now][t], dp[pre][j]);
            }
        }
        s.insert(a[i]);
        cout << "i= " << i << '\n';
        for (int j = 0; j <= 2 * D; j++) {
            if (dp[now][j] == 0) continue;
            cout << "j= " << j - D << ' ' << dp[now][j] << '\n';
        }
    }
    int ans = 1;
    for (int j = 0; j <= 2 * D; j++) add(ans, dp[now][j]);
    cout << ans << '\n';
    return 0;
}
