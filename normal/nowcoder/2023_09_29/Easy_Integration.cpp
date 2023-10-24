#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2000001, MOD = 998244353;

LL mypow(LL x, LL y) {
    LL res = 1;
    while (y){
        if (y & 1) {
            res = res * x % MOD;
        }
        y >>= 1;
        x = x * x % MOD;
    }
    return res;
}

vector<LL> fac, inv;

void init() {
    fac = vector<LL>(N + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    inv = vector<LL>(N + 1, 0);
    inv[N] = mypow(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n;
    while (cin >> n) cout << fac[n] * fac[n] % MOD * inv[2 * n + 1] % MOD << '\n';
    return 0;
}