#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 14, M = 100, MOD = 1000000007;

void add(int &x, int y) {
    x = x + y;
    if (x >= MOD) x -= MOD;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, x;
    while (cin >> n >> m) {
        vector<vector<int>> a(m, vector<int>());
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            cin >> x;
            if (x) a[j].push_back(i);
        }
        if (n > m) {
            cout << 0 << '\n';
            continue;
        }
        
        vector<int> dp(1 << n, 0);
        dp[0] = 1;
        for (int j = 0; j < m; j++) {
            for (int s = (1 << n) - 1; s >= 0; s--) {
                if (dp[s] == 0) continue;
                for (int i : a[j]) {
                    if (s >> i & 1) continue;
                    add(dp[s | 1 << i], dp[s]);
                }
            }
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
    return 0;
}