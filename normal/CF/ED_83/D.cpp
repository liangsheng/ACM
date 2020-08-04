#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200000, MOD = 998244353;

int inv[N + 5], finv[N + 5], f[N + 5];

void init() {
    inv[1] = 1, finv[1] = 1, f[1] = 1;
    for (int i = 2; i <= N; ++i) {
        f[i] = (LL) f[i - 1] * i % MOD;
        inv[i] = ((LL) inv[MOD % i] * (-(MOD / i)) % MOD + MOD) % MOD;
        finv[i] = (LL) finv[i - 1] * inv[i] % MOD;
    }
}

int cal(int x, int y) {
    return (LL) f[x] * finv[y] % MOD * finv[x - y] % MOD;
}

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (LL) ans * x % MOD;
        x = (LL) x * x % MOD;
        y >>= 1;
    }
    return ans;
}

int n, m;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int ans;
    init();
    while (~scanf("%d %d", &n, &m)) {
        if (n == 2) {
            puts("0");
            continue;
        }
        if (n == 3) ans= (LL) cal(m, n - 1);
        else ans = (LL) cal(m, n - 1) * power(2, n - 3) % MOD * (n - 2) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}