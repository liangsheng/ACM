#include <bits/stdc++.h>
using namespace std;

const int M = 11000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T, n, m;
    cin >> T >> n >> m;
    vector<vector<int>> p(T, vector<int>(n, 0));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n; j++) cin >> p[i][j];
    }

    vector<int> dp(M + 1, 0);
    for (int t = 0; t < T - 1; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = p[t][i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - p[t][i]] + p[t + 1][i] - p[t][i]);
            }
        }
        m = *max_element(dp.begin(), dp.begin() + m + 1) + m;
        fill(dp.begin(), dp.begin() + m + 1, 0);
    }
    cout << m << '\n';

    return 0;
}