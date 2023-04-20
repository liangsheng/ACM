#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

//2、单独求某个值的逆元
int inv(int a) {
     if (a == 1) return 1;
     return (((-(MOD / a) * inv(MOD % a)) % MOD) + MOD) % MOD;
}

template <typename T>
T extend_gcd(T a, T b, T &x, T&y) {
    T t, ret;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b, a % b, x, y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // LL m = inv(100);
    // cout << m << '\n';
    int x, y;
    extend_gcd(100, MOD, x, y);
    LL m = ((LL) x + MOD) % MOD;
    // cout << x << '\n';
    // cout << m * 281LL % MOD << '\n';
    int n, p;
    while (cin >> n >> p) {
        vector<LL> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            LL a = (dp[i - 2] + 1) * p % MOD * m % MOD;
            LL b = (dp[i - 1] + 1) * (100 - p) % MOD * m % MOD;
            dp[i] = (a + b) % MOD;
        }
        cout << dp[n] << '\n';
    }
    return 0;
}