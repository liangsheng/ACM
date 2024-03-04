#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, V, W, C;
    while (cin >> n >> m) {
        vector<int> v, w;
        for (int i = 1; i <= n; i++) {
            cin >> V >> W >> C;
            // 把物品数量按二进制拆分
            int d = 1;
            while (d <= C) {
                v.push_back(d * V), w.push_back(d * W);
                C -= d, d *= 2;
            }
            if (C > 0) v.push_back(C * V), w.push_back(C * W);
        }
 
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < (int) w.size(); i++) for (int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
        cout << dp[m] << '\n';
    }
    return 0;
}