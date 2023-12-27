#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int N = 3000, MOD = 998244353;

LL mypow(LL x, LL y, LL mod = MOD){
    LL res = 1;
    while (y) {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> d(N + 1), sum_d(N + 1), inv_sum_d(N + 1);
    d[0] = 1, sum_d[0] = 1, inv_sum_d[0] = 1;
    for (int i = 1; i <= N; i++) {
        d[i] = (LL) d[i - 1] * 2 % MOD;
        sum_d[i] = ((LL) sum_d[i - 1] + d[i]) % MOD;
        inv_sum_d[i] = mypow(sum_d[i], MOD - 2);
    }
    int G = mypow(2, MOD - 2);

    // f[n][1] = 1 / 2 * f[n][n]
    // f[n][i]= 1 / 2 * (f[n][i - 1] + f[n - 1][i - 1]);
    // 
    // f[n][1] = 1 / (2 ^ n - 1) * (2^0 * f[n - 1][1] + 2^1 * f[n - 1][2] + ... + 2^(n-2) * f[n - 1][n - 1]) 
    vector<vector<int>> f(N + 1, vector<int>(N + 1, 1));
    f[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        int t = 0;
        for (int j = 1; j <= i - 1; j++) t = (t + (LL) d[j - 1] * f[i - 1][j] % MOD) % MOD;
        t = (LL) t * inv_sum_d[i - 1] % MOD;
        f[i][1] = t;
        for (int j = 2; j <= i; j++) {
            f[i][j] = (f[i][j - 1] + f[i - 1][j - 1]) % MOD;
            f[i][j] = (LL) G * f[i][j] % MOD;
        }
    }
    
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) cout << f[n][i] << " \n"[i == n];
    }
    return 0;
}


