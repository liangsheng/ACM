#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;

const LL N = 1000005, p = 998244353;

//1、线性求逆元
LL inv[N]; 

//线性求到a的逆元 
void INV(int a, int p) {
    inv[1] = 1;
    for (int i = 2; i <= a; ++i) {
        inv[i] = (-(p / i)) * inv[p % i] % p;
        inv[i] = (inv[i] % p + p) % p;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b;

        INV(n, MOD);
        m = 0;
        for (int i = 0; i < n; i++) m += (a[i] != b[i]);
        vector<LL> df(n + 1);
        df[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            df[i] = (n + df[i + 1] * (n - i) % MOD) * inv[i] % MOD;
            // cout << "i= " << i << ", df= " << df[i] << '\n';
        }
        vector<LL> f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= m; i++) f[i] = (f[i - 1] + df[i]) % MOD;
        cout << f[m] << '\n';
    }
    return 0;
}

// f[i]: i diffierent
// f[0] = 0
// n * f[i] = (n - i) * (f[i + 1] + 1) + i * (f[i - 1] + 1)
// (n - i) * (f[i + 1] - f[i]) = i * (f[i] - f[i - 1]) - n
// f[i] - f[i - 1] = (n + (n - i) * (f[i + 1] - f[i])) / i
// f[n] = 1 + f[n - 1]  => f[n] - f[n - 1] = 1
// f[0] = 0