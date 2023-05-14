#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

long long mypow(long long x, long long y, long long mod = MOD){
    long long res=1;
    while(y){
        if(y&1) {
            res = res * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}

LL n, m;
map<LL, LL> dp;

LL gao(LL u) {
    if (u == n) return 1;
    if (u > n) return 0;
    if (dp.count(u)) return dp[u];
    LL t = 0, d = min(6LL, n / u);
    for (LL i = 2; i <= d; i++) t += gao(i * u);
    dp[u] = t * m % MOD;
    // cout << u << ' ' << dp[u] << '\n';
    return dp[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    m = mypow(5, MOD - 2);
    while (cin >> n) cout << gao(1) << '\n';
    return 0;
}