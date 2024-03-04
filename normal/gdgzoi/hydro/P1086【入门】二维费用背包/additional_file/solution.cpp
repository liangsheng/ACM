#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面两句是为了让 cin 更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, V, M, v, m, w;
    cin >> n >> V >> M;
    vector<vector<int>> dp(V + 1, vector<int>(M + 1, 0));
    for (int i = 0; i < n; i++) {
        cin >> v >> m >> w;
        for (int j = V; j >= v; j--) for (int k = M; k >= m; k--) {
            dp[j][k] = max(dp[j][k], dp[j - v][k - m] + w);
        }
    }
    cout << dp[V][M] << '\n';
    return 0;
}