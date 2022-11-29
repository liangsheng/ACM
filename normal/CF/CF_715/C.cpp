#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2005;

int n;
LL a[N], b[N];
LL dp[N][N];

LL gao() {
    sort(a + 1, a + n + 1);
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // puts("");
    // b[1] = a[3], b[2] = a[4];
    // b[3] = a[2], b[4] = a[5];
    // b[5] = a[1], b[6] = a[6];
    // LL ans = 0, mini = 1000000000, maxi = -1;
    // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    // puts("");
    // for (int i = 1; i <= n; i++) {
    //     mini = min(mini, b[i]);
    //     maxi = max(maxi, b[i]);
    //     ans += maxi - mini;
    // }
    // cout << ans << '\n';
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int k = 2; k <= n; k++) {
        for (int l = 1, r = l + k - 1; r <= n; l++, r++) {
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + a[r] - a[l];
        }
    }
    return dp[1][n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << gao() << '\n';
    }
    return 0;
}