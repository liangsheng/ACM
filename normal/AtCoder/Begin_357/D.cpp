#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

const LL INF = numeric_limits<LL>::max(), MOD = 998244353;

LL power(LL x, LL y) {
    LL ans = 1;
    while (y > 0) {
        if (y & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n, m, d = 0;
    cin >> n;
    m = n;
    while (m > 0) d++, m /= 10;
    cout << "d= " << d << ", " << n * d << '\n';
    LL ans = n % MOD * power(10, n * d) % MOD - n % MOD;
    ans = (ans % MOD + MOD) % MOD;
    cout << "ans= " << ans << '\n';
    LL p = 1;
    for (int i = 1; i <= d; i++) p = p * 10;
    p -= 1;
    p = power(p, MOD - 2);
    ans = ans * p % MOD;
    cout << ans << '\n';
    return 0;
}