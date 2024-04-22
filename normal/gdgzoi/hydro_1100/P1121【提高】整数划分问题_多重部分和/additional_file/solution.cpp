#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), m(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> m[i];

    // dp[i][j] 表示前 i 个数表示 j 时, 第 i 个数最多能剩下多少个; 如果不能表示, dp[i][j] 为 -1
    // vector<vector<int> > dp(n + 1, vector<int>(k + 1, -1));
    // dp[0][0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     dp[i][0] = m[i];
    //     for (int j = 1; j <= k; j++) {
    //         if (dp[i - 1][j] >= 0) dp[i][j] = m[i];  // 只用前 i - 1 个数就行
    //         else {
    //             if (j < a[i] || dp[i][j - a[i]] <= 0) dp[i][j] = -1;
    //             else dp[i][j] = dp[i][j - a[i]] - 1;
    //         }
    //     }
    // }
    // int cnt = 0;
    // for (int i = 1; i <= k; i++) cnt += (dp[i] >= 0);
    // cout << cnt << '\n';

    // 进一步将 dp 缩小成 1 维
    vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[j] >= 0) dp[j] = m[i];  // 只用前 i - 1 个数就行
            else {
                if (j < a[i] || dp[j - a[i]] <= 0) dp[j] = -1;
                else dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= k; i++) cnt += (dp[i] >= 0);
    cout << cnt << '\n';
    return 0;
}
