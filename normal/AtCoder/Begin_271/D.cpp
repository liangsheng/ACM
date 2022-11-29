#include <bits/stdc++.h>
using namespace std;

int dp[101][10001];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, s;
    while (cin >> n >> s) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        for (int i = 0; i < n; i++) for (int j = 1; j <= s; j++) dp[i][j] = -1;
        dp[0][a[0]] = 0, dp[0][b[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= s; j++) if (dp[i - 1][j] != -1) {
                if (j + a[i] <= s) dp[i][j + a[i]] = 0;
                if (j + b[i] <= s) dp[i][j + b[i]] = 1;
            }
        }
        if (dp[n - 1][s] == -1) cout << "No" << '\n';
        else {
            string ans;
            int p = n - 1, now = s;
            while (p >= 0) {
                // printf("p= %d, now= %d, dp[p][now]= %d\n", p, now, dp[p][now]);
                if (dp[p][now] == 0) ans.push_back('H'), now -= a[p];
                else ans.push_back('T'), now -= b[p];
                p--;
            }
            reverse(ans.begin(), ans.end());
            cout << "Yes" << '\n' << ans << '\n';
        }
    }
    return 0;
}