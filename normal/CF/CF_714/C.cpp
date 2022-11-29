#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200015, MOD = 1000000007;

int T, n, m;
int dp[2][10];
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int now = 0, pre = 1;
    memset(dp[now], 0, sizeof(dp[now]));
    dp[now][0] = 1, f[0] = 1;
    for (int i = 1; i <= 200010; i++) {
        int sum = 0;
        swap(now, pre);
        memset(dp[now], 0, sizeof(dp[now]));
        for (int j = 1; j < 10; j++) {
            dp[now][j] = dp[pre][j - 1];
        }
        dp[now][0] = ((LL) dp[now][0] + dp[pre][9]) % MOD;
        dp[now][1] = ((LL) dp[now][1] + dp[pre][9]) % MOD;
        for (int j = 0; j < 10; j++) sum = ((LL) sum + dp[now][j]) % MOD;
        f[i] = sum;
    }
    // for (int i = 0; i <= 100; i++) cout << i << ' ' << f[i] << '\n';
    cin >> T;
    while (T--) {
        cin >> n >> m;
        
        int ans = 0;
        while (n != 0) {
            int d = n % 10;
            n /= 10;
            ans = ((LL) ans + f[d + m]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}