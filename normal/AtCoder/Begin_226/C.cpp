#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, x;
    while (cin >> n) {
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> cnt(n + 1, 0);
        vector<LL> dp(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            cin >> dp[i] >> cnt[i];
            for (int j = 1; j <= cnt[i]; j++) {
                cin >> x;
                g[i].push_back(x);
            }
        }
        queue<int> q;
        vector<bool> ans(n + 1, 0);
        q.push(n);
        while (!q.empty()) {
            int u  = q.front();
            q.pop();
            ans[u] = 1;
            for (int v : g[u]) if (!ans[v]) q.push(v);
        }
        LL ret = 0;
        for (int i = 1; i <= n; i++) ret += ans[i] * dp[i];
        cout << ret << '\n';
    }
    return 0;
}