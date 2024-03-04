#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, s;
    cin >> n >> V;
    vector<int> dp(V + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vector<int> v(s), w(s);
        for (int j = 0; j < s; j++) cin >> v[j] >> w[j];
        // 从大到小枚举体积 j 时，依次用组里每个物品去更新 dp[j]
        for (int j = V; j >= 0; j--) {
            for (int k = 0; k < s; k++) {
                if (j >= v[k]) dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
            }
        }
    }
    cout << dp[V] << '\n';
    return 0;
}