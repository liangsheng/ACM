#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

void add(int &x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    while (cin >> n >> m >> k) {
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> b(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> b[i][j];

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0))); 
        dp[1][1][0] = 1;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int h = 1; h <= k; h++) {
            int now = h;
            for (int p = i - 1; p >= 1; p--) {
                now -= a[p][j];
                if (now < 0) break;
                add(dp[i][j][h], dp[p][j][now]);
            }
            now = h;
            for (int p = j - 1; p >= 1; p--) {
                now -= b[i][p];
                if (now < 0) break;
                add(dp[i][j][h], dp[i][p][now]);
            }
            cout << "i= " << i << ' ' << j << ' ' << h << ' ' << dp[i][j][h] << '\n';
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) cout << dp[i][j][k] << ' ';
            cout << dp[i][m][k] << '\n';
        }
    }
    return 0;
}