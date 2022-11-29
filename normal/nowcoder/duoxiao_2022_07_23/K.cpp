#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 205, MOD = 1000000007;

int T, n, m;
int dp[2][N][N];
string s;

void add(int& x, int y) {
    x = ((LL) x + y) % MOD;
}

int gao() {
    int now = 0, pre = 1;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[now][i][j] = 0;
    dp[now][0][0] = 1;
    for (int k = 1; k <= m; k++) {
        swap(now, pre);
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[now][i][j] = 0;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
            if (dp[pre][i][j] == 0) continue;
            // printf("k= %d, i= %d, j= %d, %d\n", k - 1, i, j, dp[pre][i][j]);
            if (j + 1 <= m) {
                if (i + 1 <= n && s[i + 1 - 1] == '(') add(dp[now][i + 1][j + 1], dp[pre][i][j]);
                else add(dp[now][i][j + 1], dp[pre][i][j]);
            }
            if (j - 1 >= 0) {
                if (i + 1 <= n && s[i + 1 - 1] == ')') add(dp[now][i + 1][j - 1], dp[pre][i][j]);
                else add(dp[now][i][j - 1], dp[pre][i][j]);
            }
        }
    }
    // for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) if (dp[now][i][j] != 0) printf("k= %d, i= %d, j= %d, %d\n", m, i, j, dp[now][i][j]);
    return dp[now][n][0];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin >> s;
        cout << gao() << '\n';
    }
    return 0;
}