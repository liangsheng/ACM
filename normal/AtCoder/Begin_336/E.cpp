#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
typedef long long LL;

const LL N = 14, MM = 14 * 9, INF = 100000000000000LL;

// 15 * 127 * 127 * 127
LL dp[2][MM + 1][MM + 1][MM + 1];

LL gao(LL n) {
    LL x = n, ans = 0;
    if (n == INF) ans = 1, x--;
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    reverse(a.begin(), a.end());
    int m = a.size(), M = 9 * m, now = 0, pre = 1;
    rep (i, M + 1) FOR(j, 1, M) FOR (k, 0, j - 1) {
        dp[now][i][j][k] = 0;
    }
    for (int i = 0; i < a[0]; i++) for (int j = 1; j <= M; j++) {
        dp[now][i][j][i % j] = 1;
    }
    LL s = a[0], d = a[0];
    for (int i = 1; i < m; i++) {
        swap(now, pre);
        rep (u, M + 1) FOR (v, 1, M) FOR (w, 0, v - 1) dp[now][u][v][w] = 0;
        rep (u, M + 1) FOR (v, 1, M) FOR (w, 0, v - 1) if (dp[pre][u][v][w] > 0) {
            for (int j = 0; j < 10; j++) {
                dp[now][u + j][v][(w * 10 + j) % v] += dp[pre][u][v][w];
            }
        }
        for (int k = 1; k <= M; k++) for (int j = 0; j < a[i]; j++) {
            dp[now][s + j][k][(d * 10 + j) % k]++;
        }
        s += a[i];
        d = d * 10 + a[i];
    }
    ans += (d % s == 0);
    for (int k = 1; k <= M; k++) {
        ans += dp[now][k][k][0];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL n;
    cin >> n;
    cout << gao(n) << '\n';
    return 0;
}