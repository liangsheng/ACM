#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n, m, e, cas = 0, INF = ~0U >> 2;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> A(n), a;
        for (int i = 0; i < n; i++) cin >> A[i];
        a.push_back(A[0]);
        for (int i = 1; i < n; i++) if (A[i] != A[i - 1]) a.push_back(A[i]);
        n = a.size();
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        e = *max_element(b.begin(), b.end());
        vector<vector<int>> q(e + 1);
        for (int i = 0; i < m; i++) q[b[i]].push_back(i);
        vector<vector<int>> dp(n, vector<int>(m, INF));
        for (int i : q[a[0]]) dp[0][i] = 0;
        for (int i = 0; i < n - 1; i++) for (int j : q[a[i]]) {
            if (dp[i][j] == INF) continue;
            for (int k : q[a[i + 1]]) dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(j - k));
        }
        int ans = INF;
        for (int i : q[a[n - 1]]) ans = min(ans, dp[n - 1][i]);
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}