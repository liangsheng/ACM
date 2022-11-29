#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 65;

int n;
string a[N];
LL dp[N][2];

void gao() {
    if (a[1] == "AND") dp[1][1] = 1, dp[1][0] = 3;
    else dp[1][1] = 3, dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == "AND") {
            dp[i][1] = dp[i - 1][1];
            dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1];
        } else {
            dp[i][1] = dp[i - 1][1] * 2 + dp[i - 1][0];
            dp[i][0] = dp[i - 1][0];
        }
        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    cout << dp[n][1] << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        gao();
    }
    return 0;
}