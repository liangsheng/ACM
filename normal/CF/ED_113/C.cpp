#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200000, MOD = 998244353;

int T, n;
int a[N + 5];

int f[N + 5], inv[N + 5], finv[N + 5];

void init() {
    f[0] = 1, f[1] = 1, inv[1] = 1, finv[1] = 1, finv[0] = 1;
    for (int i = 2; i <= N; i++) {
        f[i] = (LL) f[i - 1] * i % MOD;
        inv[i] = ((-(MOD / i)) * (LL) inv[MOD % i] % MOD + MOD) % MOD;
        finv[i] = (LL) finv[i - 1] * inv[i] % MOD;
    }

}

int cal(int n, int m) {
    // cout << f[n] << ' ' << finv[m] << ' ' << finv[n - m] << '\n';
    return (LL) f[n] * finv[m] % MOD * finv[n - m] % MOD;
}

int gao() {
    int x = a[0], y = a[1];
    if (x < y) swap(x, y);
    for (int i = 2; i < n; i++) {
        if (a[i] > x) y = x, x = a[i];
        else if (a[i] == x) y = x;
        else if (a[i] > y) y = a[i];
    }
    if (x >= y + 2) return 0;
    if (x == y) return f[n];
    int c = 0, ans = 0;
    for (int i = 0; i < n; i++) c += (a[i] == y);
    // cout << "x= " << x << ' ' << y << ' ' << c << '\n';
    for (int i = n; i >= c + 1; i--) {
        int tmp = (LL) cal(i - 1, c) * f[c] % MOD * f[n - c - 1] % MOD;
        // cout << "i= " << i << ' ' << tmp << ' ' << cal(i - 1, c) << ' ' << f[c] << ' ' << f[n - c - 1] << '\n';
        ans = ((LL) ans + tmp) % MOD;
    }
    return ((f[n] - ans) % MOD + MOD) % MOD;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    init();
    // cout << inv[2] << ' ' << inv[3] << ' ' << finv[3] << '\n';
    // cout << cal(5, 3) << '\n';
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << gao() << '\n';
    }
    return 0;
}