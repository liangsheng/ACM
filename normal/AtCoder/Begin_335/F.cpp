#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353, D = 500;

int f[D + 1][D + 1];

void add(int& x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n + 1, 0);
    memset(f, 0, sizeof(f));
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1;
        if (a[i] >= D) {
            for (int j = i + a[i]; j < n; j += a[i]) add(dp[i], dp[j]);
        } else {
            add(dp[i], f[a[i]][i % a[i]]);
        }
        for (int j = 1; j < D; j++) add(f[j][i % j], dp[i]);
    }
    cout << dp[0] << '\n';
    return 0;
}