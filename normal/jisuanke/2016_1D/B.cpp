#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 105

using namespace std;

typedef long long LL;

const LL MOD = (1LL << 32);

int n;
LL m;
LL dp[N][N];

void add(LL &x, LL y) {
    x = ((x + y) % MOD + MOD) % MOD;
}

//void gao(int id, int t, int p) {
//    int i, r = (p - 1) / 2;
//    for (i = 0; i <= r; i++) {
//        if (dp[p][i] == 0) continue;
//        if (i + 1 <= t) {
//            add(dp[id][i + 1], dp[p][i]);
//        }
//        if (i == 0) {
//            add(dp[id][0], (m - 1) * dp[p][i] % MOD);
//            //add(dp[id][1], dp[p][i]);
//        } else {
//            gao(id, t, i);
//        }
//    }
//}

int main() {
    int i, j, t;
    LL ans, tmp;
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[1][0] = m, dp[2][0] = m * (m - 1) % MOD;
    for (i = 3; i <= n; i++) {
        t = (i - 1) / 2;
        //gao(i, t, i - 1);
        tmp = 0;
        for (j = 0; j < t; j++) {
            if (dp[i - 1][j] == 0) continue;
            add(dp[i][j + 1], dp[i - 1][j]);
            add(tmp, m * dp[i - 1][j]);
        }
        if (dp[i - 1][t] != 0) add(tmp, (m - 1) * dp[i - 1][t]);
        for (j = 1; j <= t; j++) add(tmp, -dp[i][j]);
        dp[i][0] = tmp;
    }
    ans = 0;
    for (i = 1; i <= n; i++) {
        t = (i - 1) / 2;
        for (j = 0; j <= t; j++) {
            add(ans, dp[i][j]);
            if (dp[i][j] != 0) cout << "i= " << i << " " << j << " " << dp[i][j], system("pause");
        }
    }
    cout << ans << '\n';
    return 0;
}
