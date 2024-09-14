#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 30;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    // f[i] 表示二进制的第 i 位是 1 的最长子序列长度
    vector<int> a(n), dp(n, 1), f(31, 0);
    for (int i = 0; i < n ; i++) {
        cin >> a[i];
        // for (int j = 0; j < i; j++) {
        //     if (a[i] & a[j]) dp[i] = max(dp[i], dp[j] + 1);
        // }
        for (int j = 0; j < 30; j++) if (a[i] >> j & 1) dp[i] = max(dp[i], f[j] + 1);
        for (int j = 0; j < 30; j++) if (a[i] >> j & 1) f[j] = max(f[j], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}