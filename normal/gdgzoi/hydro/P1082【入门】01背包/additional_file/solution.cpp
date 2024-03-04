#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    vector<int> dp(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[m] << '\n';
    return 0;
}