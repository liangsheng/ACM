#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

void work() {
    for (int m = 9; m <= 9; m++) {
        int n = (1 << m);
        vector<int> a(n + 1, -1);
        for (int i = 1; i <= n; i *= 2) a[i] = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                a[i] = 0;
                for (int j = 0; j < m; j++) if ((i >> j) & 1) {
                    int d = i ^ (1 << j);
                    a[i] += a[d] + 1;
                }
            }
            // cout << "i= " << i << ", a[i]= " << a[i] << '\n';
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += a[i];
        cout << "m= " << m << ", n= " << n << ", ans= " << ans << '\n';
        for (int i = 1; i <= n; i++) cout << "i= " << i << ", a[i]= " << a[i] << '\n';
    }
}

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

void solve() {
    int n = 10000000;
    vector<int> fac(n + 1, 1), inv(n + 1, 1);
    fac[1] = 1;
    for (int i = 2; i <= n; i++) fac[i] = (LL) fac[i - 1] * i % MOD;
    inv[n] = mypow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--) {
        inv[i] = (LL) inv[i + 1] * (i + 1) % MOD;
    }
    vector<int> f(n + 1, 0);
    for (int i = 2; i <= n; i++) f[i] = (LL) i * (f[i - 1] + 1) % MOD;
    int T, m;
    cin >> T;
    while (T--) {
        cin >> m;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int tmp = (LL) f[i] * fac[m] % MOD * inv[i] % MOD * inv[m - i] % MOD;
            ans = ((LL) ans + tmp) % MOD;
        }
        cout << ans << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // work();
    solve();
	return 0;
}