#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, v, w, s;
    while (cin >> n >> m) {
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> v >> w >> s;
            if (s == -1) {        // 只能用 1 次, 01背包
                for (int j = m; j >= v; j--) {
                    dp[j] = max(dp[j], dp[j - v] + w);
                }
            } else if (s == 0) {  // 可以用无限次, 完全背包
                for (int j = v; j <= m; j++) {
                    dp[j] = max(dp[j], dp[j - v] + w);
                }
            } else {              // 可以用有限次, 多重背包, 二进制拆分
                for (int d = 1; s > 0; d *= 2) {
                    int c = min(d, s), nv = c * v, nw = c * w;
                    for (int j = m; j >= nv; j--) {
                        dp[j] = max(dp[j], dp[j - nv] + nw);
                    }
                    s -= c;
                }
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}